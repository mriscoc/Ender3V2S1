cls
Write-Output 'Clean Up' 
if (Test-Path -Path '.\.pio\build') { Rename-Item -Path '.\.pio\build' -NewName 'build-' -Force }
if (Test-Path -Path '.\.pio\build-') { Remove-Item '.\.pio\build-' -Recurse }
. $env:USERPROFILE\.platformio\penv\Scripts\platformio.exe run --target clean -e STM32F103RET6_creality
Write-Output ' '
Write-Output ' '
#-------------------------------
Write-Output 'Compiling...'
. $env:USERPROFILE\.platformio\penv\Scripts\platformio.exe run -e STM32F103RET6_creality
Move-Item -Path '.pio\build\STM32F103RET6_creality\*.bin' -Destination '..\Releases'
Write-Output ' '