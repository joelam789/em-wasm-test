
set INCLUDES=-I. -I.. -I../apu/ -I../apu/bapu/ -I../filter/
set OBJECTS=../apu/apu.cpp ../apu/bapu/dsp/sdsp.cpp ../apu/bapu/dsp/SPC_DSP.cpp ../apu/bapu/smp/smp.cpp ../apu/bapu/smp/smp_state.cpp ^
../bsx.cpp ../c4.cpp ../c4emu.cpp ../cheats.cpp ../cheats2.cpp ../clip.cpp ../conffile.cpp ../controls.cpp ^
../cpu.cpp ../cpuexec.cpp ../cpuops.cpp ../crosshairs.cpp ../dma.cpp ../dsp.cpp ../dsp1.cpp ../dsp2.cpp ../dsp3.cpp ../dsp4.cpp ^
../fxinst.cpp ../fxemu.cpp ../gfx.cpp ../globals.cpp ../logger.cpp ../memmap.cpp ../msu1.cpp ../movie.cpp ../obc1.cpp ^
../ppu.cpp ../stream.cpp ../sa1.cpp ../sa1cpu.cpp ../screenshot.cpp ../sdd1.cpp ../sdd1emu.cpp ^
../seta.cpp ../seta010.cpp ../seta011.cpp ../seta018.cpp ../snapshot.cpp ../snes9x.cpp ../spc7110.cpp ../srtc.cpp ../tile.cpp ^
../filter/2xsai.cpp ../filter/blit.cpp ../filter/epx.cpp ../filter/hq2x.cpp ../filter/snes_ntsc.c ../statemanager.cpp ^
em.cpp

set CCFLAGS=-DLSB_FIRST -fomit-frame-pointer -fno-exceptions -fno-rtti -pedantic -Wall -W -Wno-unused-parameter  -Wno-c++11-extensions ^
-D_GNU_SOURCE=1 -D_REENTRANT -DHAVE_MKSTEMP -DHAVE_STRINGS_H -DHAVE_SYS_IOCTL_H -DHAVE_STDINT_H  -DRIGHTSHIFT_IS_SAR

REM emcc -O3 -lm -s WASM=1 ^
emcc -O3 -lm ^
 -s EXPORTED_FUNCTIONS="['_mainf', '_framesf', '_showfpsf', '_setsrf', '_setscreenbuff', '_setpixelbuff']" ^
 -s FORCE_FILESYSTEM=1 ^
 -s TOTAL_MEMORY=50331648 ^
 --preload-file test.smc ^
 -o snes9x.js ^
 %INCLUDES% %CCFLAGS% %OBJECTS% 
