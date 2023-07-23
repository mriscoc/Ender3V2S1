#------------------------------------------------------------------------------
# Cura JPEG Thumbnail creator
# Professional firmware for Ender3v2
# Miguel A. Risco-Castillo
# version: 1.6
# date: 2023-07-23
#
# Contains code from:
# https://github.com/Ultimaker/Cura/blob/master/plugins/PostProcessingPlugin/scripts/CreateThumbnail.py
#------------------------------------------------------------------------------

import base64

from UM.Logger import Logger
from cura.Snapshot import Snapshot
from cura.CuraVersion import CuraVersion

from ..Script import Script


class CreateJPEGThumbnail(Script):
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
        return """{
            "name": "Create JPEG Thumbnail",
            "key": "CreateJPEGThumbnail",
            "metadata": {},
            "version": 2,
            "settings":
            {
                "width":
                {
                    "label": "Width",
                    "description": "Width of the generated thumbnail",
                    "unit": "px",
                    "type": "int",
                    "default_value": 200,
                    "minimum_value": "0",
                    "minimum_value_warning": "12",
                    "maximum_value_warning": "800"
                },
                "height":
                {
                    "label": "Height",
                    "description": "Height of the generated thumbnail",
                    "unit": "px",
                    "type": "int",
                    "default_value": 200,
                    "minimum_value": "0",
                    "minimum_value_warning": "12",
                    "maximum_value_warning": "600"
                },
                "change_size":
                {
                    "label": "Show extra options?",
                    "description": "Enables extra options to change the quality of the produced image",
                    "type": "bool",
                    "default_value": false
                },
                "max_size":
                {
                    "label": "Max Size",
                    "description": "The maximum size of the thumbnail in bytes. This is useful for displays like TJC where thumbnails must be smaller than 20kbytes in size.",
                    "unit": "byte",
                    "type": "int",
                    "default_value": 15000,
                    "minimum_value": "100",
                    "minimum_value_warning": "1000",
                    "enabled": "change_size"
                }
            }
        }"""

    def execute(self, data):
        width = self.getSettingValueByKey("width")
        height = self.getSettingValueByKey("height")
        should_change_size = self.getSettingValueByKey("change_size")
        max_size = -1
        if should_change_size:
           max_size = self.getSettingValueByKey("max_size")

        Logger.log("d", f"Options: width={width}, height={height}, should_change_size={should_change_size}, max_size={max_size}")

        snapshot = self._createSnapshot(width, height)
        if snapshot:
            encoded_snapshot = self._encodeSnapshot(snapshot)
            # reduce the quality of the image until the size is below max_size
            # this option is necessary for some displays like TJC where the image must be smaller than 20kb
            if should_change_size:
                # quality ranges from 95 (best) to 1 (worst)
                quality = 95
                while len(encoded_snapshot) >= max_size:
                    if quality == 0:
                        Logger.log("e", f"Failed to reduce image size to at most {max_size} bytes")
                        break
                    encoded_snapshot = self._encodeSnapshot(snapshot, quality=quality)
                    quality -= 1
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
