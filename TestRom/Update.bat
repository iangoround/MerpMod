mkdir %BUILDCONFIG%\%TARGETROM%\
cd 
for %%P in (*.patch) do del %%P
copy ..\%BUILDCONFIG%\MerpMod.mot partial-patch.mot
if exist "%TARGETROM%.bin" (copy /Y "%TARGETROM%.bin" patched.bin) else (Copy ..\..\..\SubaruRoms\OEM\%TARGETROM%.bin patched.bin)
..\..\SharpTune.exe rommod hewbuild partial-patch.mot patched.bin %BUILDCONFIG%
