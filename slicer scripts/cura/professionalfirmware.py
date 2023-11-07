#------------------------------------------------------------------------------
# Cura Professional firmware post processing script
# Miguel A. Risco-Castillo
# version: 2.1
# date: 2023-09-17
#
# Contains thumbnail code from:
# https://github.com/Ultimaker/Cura/blob/master/plugins/PostProcessingPlugin/scripts/CreateThumbnail.py
#------------------------------------------------------------------------------

import re
import base64
import json
from typing import Callable, TypeVar, Optional
from enum import Enum, auto

from UM.Logger import Logger
from cura.Snapshot import Snapshot
from cura.CuraApplication import CuraApplication
from cura.CuraVersion import CuraVersion

from ..Script import Script

T = TypeVar("T")

class Ordering(Enum):
    LESS = auto()
    EQUAL = auto()
    GREATER = auto()

def binary_search(list: list[T], compare: Callable[[T], Ordering]) -> Optional[T]:
    left: int = 0
    right: int = len(list) - 1
    while left <= right:
        middle: int = (left + right) // 2

        comparison = compare(list[middle])
        if comparison == Ordering.LESS:
            left = middle + 1
        elif comparison == Ordering.GREATER:
            right = middle - 1
        else:
            return middle
    return None

class QualityFinder:
    compute_image_size: Callable[[int], int]
    # Keep track of which quality value produced the closest match to the target_size
    closest_match: Optional[tuple[int, float]]
    # The size that the image should have
    target_size: int
    # A lower bound for the acceptable image size in percent
    # For example when the acceptable_bound is 0.9 and a value produces an image that
    # has a size of target_size * 94%, then the value is accepted, because 0.94 >= 0.9
    acceptable_bound: float

    def __init__(self, compute_image_size: Callable[[int], int], target_size: int, acceptable_bound: float = 0.9) -> None:
        self.compute_image_size = compute_image_size
        self.closest_match = None
        self.target_size = target_size
        self.acceptable_bound = acceptable_bound

    def __get_ratio(self, quality: int) -> float:
        # calculate the size of the image with the specified quality:
        current_size: int = self.compute_image_size(quality)

        # check if the new image size is closer to 100% than the previous one (but ideally less than 1.0)
        ratio = float(current_size) / float(self.target_size)
        if self.closest_match is None:
            self.closest_match = (quality, ratio)
        else:
            (_, best_ratio) = self.closest_match
            if best_ratio > 1.0 and ratio <= 1.0:
                self.closest_match = (quality, ratio)
            elif ratio >= self.acceptable_bound and abs(1.0 - ratio) < abs(1.0 - best_ratio):
                self.closest_match = (quality, ratio)

        return ratio

    def compare_quality(self, value: int) -> Ordering:
        Logger.log("d", f"Trying a quality of {value}%")
        ratio = self.__get_ratio(value)
        Logger.log("d", f"Image size is {ratio * 100.0:.2f}% of {self.target_size}")

        # check if the image is too large
        if ratio > 1.0:
            return Ordering.GREATER

        if ratio >= self.acceptable_bound:
            # check if the next quality would produce an even better result
            next_ratio: float = self.__get_ratio(value + 1)
            if next_ratio <= 1.0 and next_ratio > ratio:
                return Ordering.LESS

            return Ordering.EQUAL
        else:
            return Ordering.LESS

class professionalfirmware(Script):
    def __init__(self):
        super().__init__()

    def _createSnapshot(self, width, height):
        Logger.log("d", "Creating thumbnail image...")
        try:
            return Snapshot.snapshot(width, height)
        except Exception:
            Logger.logException("w", "Failed to create snapshot image")

    def _encodeSnapshot(self, snapshot, quality=-1):

        Major=0
        Minor=0
        try:
          Major = int(CuraVersion.split(".")[0])
          Minor = int(CuraVersion.split(".")[1])
        except:
          pass

        if Major < 5 :
          from PyQt5.QtCore import QByteArray, QIODevice, QBuffer
        else :
          from PyQt6.QtCore import QByteArray, QIODevice, QBuffer

        Logger.log("d", "Encoding thumbnail image...")
        try:
            thumbnail_buffer = QBuffer()
            if Major < 5 :
              thumbnail_buffer.open(QBuffer.ReadWrite)
            else:
              thumbnail_buffer.open(QBuffer.OpenModeFlag.ReadWrite)
            thumbnail_image = snapshot
            thumbnail_image.save(thumbnail_buffer, "JPG", quality=quality)
            base64_bytes = base64.b64encode(thumbnail_buffer.data())
            base64_message = base64_bytes.decode('ascii')
            thumbnail_buffer.close()
            return base64_message
        except Exception:
            Logger.logException("w", "Failed to encode snapshot image")

    def _convertSnapshotToGcode(self, encoded_snapshot, width, height, chunk_size=78):
        gcode = []

        encoded_snapshot_length = len(encoded_snapshot)
        gcode.append(";")
        gcode.append("; thumbnail begin {}x{} {}".format(
            width, height, encoded_snapshot_length))

        chunks = ["; {}".format(encoded_snapshot[i:i+chunk_size])
                  for i in range(0, len(encoded_snapshot), chunk_size)]
        gcode.extend(chunks)

        gcode.append("; thumbnail end")
        gcode.append(";")
        gcode.append("")

        return gcode

    def getSettingDataString(self):
        return json.dumps({
            "name": "Professional Firmware support",
            "key": "professionalfirmware",
            "metadata": {},
            "version": 2,
            "settings":
            {
                "thumbnail_width":
                {
                    "label": "Thumbnail width",
                    "description": "Width of the generated thumbnail",
                    "unit": "px",
                    "type": "int",
                    "default_value": 180,
                    "minimum_value": "20",
                    "minimum_value_warning": "100",
                    "maximum_value": "200"
                },
                "thumbnail_height":
                {
                    "label": "Thumbnail height",
                    "description": "Height of the generated thumbnail",
                    "unit": "px",
                    "type": "int",
                    "default_value": 180,
                    "minimum_value": "20",
                    "minimum_value_warning": "100",
                    "maximum_value": "230"
                },
                "thumbnail_max_size":
                {
                    "label": "Maximum thumbnail size",
                    "description": "The maximum size of the thumbnail in bytes. Thumbnails must be smaller than 20 kbytes for TJC displays. If the thumbnail size should not be changed, write -1.",
                    "unit": "byte",
                    "type": "int",
                    "default_value": 15000,
                    "minimum_value": "-1"
                }
            }
        }, indent=4)

    def execute(self, data):
        header_string = ';Generated for MRiscoC Professional Firmware\n'
        header_string = header_string + ';https://github.com/mriscoc/Ender3V2S1\n'
        header_string = header_string + ';===========================================================\n'
        layer = data[0]
        layer_index = data.index(layer)
        lines = layer.split("\n")
        lines.insert(0, header_string)
        final_lines = "\n".join(lines)
        data[layer_index] = final_lines
               
        width = self.getSettingValueByKey("thumbnail_width")
        height = self.getSettingValueByKey("thumbnail_height")
        max_size = self.getSettingValueByKey("thumbnail_max_size")

        Logger.log("d", f"Options: width={width}, height={height}, max_size={max_size}")

        snapshot = self._createSnapshot(width, height)
        if snapshot:
            encoded_snapshot = self._encodeSnapshot(snapshot)
            # reduce the quality of the image until the size is below max_size
            # this option is necessary for some displays like TJC where the image must be smaller than 20kb
            if max_size != -1:
                if len(encoded_snapshot) > max_size:
                    Logger.log("d", f"Image size of {len(encoded_snapshot)} is larger than {max_size}")
                    finder = QualityFinder(lambda quality: len(self._encodeSnapshot(snapshot, quality=quality)), target_size=max_size)
                    # quality ranges from 95 (best) to 1 (worst)
                    qualities = list(range(1, 95 + 1))
                    index = binary_search(qualities, finder.compare_quality)
                    quality = finder.closest_match[0]
                    if index is not None:
                        quality = qualities[index]
                    else:
                        Logger.log("e", f"Failed to reduce image size to at most {max_size} bytes")
                    
                    Logger.log("d", f"Image encoded at quality of {quality}%")
                    encoded_snapshot = self._encodeSnapshot(snapshot, quality=quality)

            snapshot_gcode = self._convertSnapshotToGcode(
                encoded_snapshot, width, height)

            for layer in data:
                layer_index = data.index(layer)
                lines = data[layer_index].split("\n")
                for line in lines:
                    if line.startswith(";Generated with Cura"):
                        line_index = lines.index(line)
                        insert_index = line_index + 1
                        lines[insert_index:insert_index] = snapshot_gcode
                        break

                final_lines = "\n".join(lines)
                data[layer_index] = final_lines

        return data
