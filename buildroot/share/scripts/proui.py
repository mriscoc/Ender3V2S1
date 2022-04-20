import shutil

libpath = "Marlin/lib/proui/"

Import("env")

print("Processing Professional Firmware requirements")

def _GetMarlinEnv(marlinEnv, feature):
    if not marlinEnv: return None
    return 1 if feature in marlinEnv else None

# Get Marlin evironment vars
MarlinEnv = env['MARLIN_FEATURES']
marlin_manualmesh = _GetMarlinEnv(MarlinEnv, 'MESH_BED_LEVELING')
marlin_abl = _GetMarlinEnv(MarlinEnv, 'AUTO_BED_LEVELING_BILINEAR')
marlin_ubl = _GetMarlinEnv(MarlinEnv, 'AUTO_BED_LEVELING_UBL')

if (marlin_manualmesh):
   print("Manual Mesh Bed Leveling detected")
   shutil.copy(libpath+'libproui_mbl.a', libpath+'libproui.a')

if(marlin_abl):
   print("Auto Mesh Bed Leveling detected")
   shutil.copy(libpath+'libproui_abl.a', libpath+'libproui.a')

if(marlin_ubl):
   print("Unified Mesh Bed Leveling detected")
   shutil.copy(libpath+'libproui_ubl.a', libpath+'libproui.a')

