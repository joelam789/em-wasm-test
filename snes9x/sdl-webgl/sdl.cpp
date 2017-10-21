/***********************************************************************************
  Snes9x - Portable Super Nintendo Entertainment System (TM) emulator.

  (c) Copyright 1996 - 2002  Gary Henderson (gary.henderson@ntlworld.com),
                             Jerremy Koot (jkoot@snes9x.com)

  (c) Copyright 2002 - 2004  Matthew Kendora

  (c) Copyright 2002 - 2005  Peter Bortas (peter@bortas.org)

  (c) Copyright 2004 - 2005  Joel Yliluoma (http://iki.fi/bisqwit/)

  (c) Copyright 2001 - 2006  John Weidman (jweidman@slip.net)

  (c) Copyright 2002 - 2006  funkyass (funkyass@spam.shaw.ca),
                             Kris Bleakley (codeviolation@hotmail.com)

  (c) Copyright 2002 - 2010  Brad Jorsch (anomie@users.sourceforge.net),
                             Nach (n-a-c-h@users.sourceforge.net),

  (c) Copyright 2002 - 2011  zones (kasumitokoduck@yahoo.com)

  (c) Copyright 2006 - 2007  nitsuja

  (c) Copyright 2009 - 2016  BearOso,
                             OV2

  (c) Copyright 2011 - 2016  Hans-Kristian Arntzen,
                             Daniel De Matteis
                             (Under no circumstances will commercial rights be given)


  BS-X C emulator code
  (c) Copyright 2005 - 2006  Dreamer Nom,
                             zones

  C4 x86 assembler and some C emulation code
  (c) Copyright 2000 - 2003  _Demo_ (_demo_@zsnes.com),
                             Nach,
                             zsKnight (zsknight@zsnes.com)

  C4 C++ code
  (c) Copyright 2003 - 2006  Brad Jorsch,
                             Nach

  DSP-1 emulator code
  (c) Copyright 1998 - 2006  _Demo_,
                             Andreas Naive (andreasnaive@gmail.com),
                             Gary Henderson,
                             Ivar (ivar@snes9x.com),
                             John Weidman,
                             Kris Bleakley,
                             Matthew Kendora,
                             Nach,
                             neviksti (neviksti@hotmail.com)

  DSP-2 emulator code
  (c) Copyright 2003         John Weidman,
                             Kris Bleakley,
                             Lord Nightmare (lord_nightmare@users.sourceforge.net),
                             Matthew Kendora,
                             neviksti

  DSP-3 emulator code
  (c) Copyright 2003 - 2006  John Weidman,
                             Kris Bleakley,
                             Lancer,
                             z80 gaiden

  DSP-4 emulator code
  (c) Copyright 2004 - 2006  Dreamer Nom,
                             John Weidman,
                             Kris Bleakley,
                             Nach,
                             z80 gaiden

  OBC1 emulator code
  (c) Copyright 2001 - 2004  zsKnight,
                             pagefault (pagefault@zsnes.com),
                             Kris Bleakley
                             Ported from x86 assembler to C by sanmaiwashi

  SPC7110 and RTC C++ emulator code used in 1.39-1.51
  (c) Copyright 2002         Matthew Kendora with research by
                             zsKnight,
                             John Weidman,
                             Dark Force

  SPC7110 and RTC C++ emulator code used in 1.52+
  (c) Copyright 2009         byuu,
                             neviksti

  S-DD1 C emulator code
  (c) Copyright 2003         Brad Jorsch with research by
                             Andreas Naive,
                             John Weidman

  S-RTC C emulator code
  (c) Copyright 2001 - 2006  byuu,
                             John Weidman

  ST010 C++ emulator code
  (c) Copyright 2003         Feather,
                             John Weidman,
                             Kris Bleakley,
                             Matthew Kendora

  Super FX x86 assembler emulator code
  (c) Copyright 1998 - 2003  _Demo_,
                             pagefault,
                             zsKnight

  Super FX C emulator code
  (c) Copyright 1997 - 1999  Ivar,
                             Gary Henderson,
                             John Weidman

  Sound emulator code used in 1.5-1.51
  (c) Copyright 1998 - 2003  Brad Martin
  (c) Copyright 1998 - 2006  Charles Bilyue'

  Sound emulator code used in 1.52+
  (c) Copyright 2004 - 2007  Shay Green (gblargg@gmail.com)

  S-SMP emulator code used in 1.54+
  (c) Copyright 2016         byuu

  SH assembler code partly based on x86 assembler code
  (c) Copyright 2002 - 2004  Marcus Comstedt (marcus@mc.pp.se)

  2xSaI filter
  (c) Copyright 1999 - 2001  Derek Liauw Kie Fa

  HQ2x, HQ3x, HQ4x filters
  (c) Copyright 2003         Maxim Stepin (maxim@hiend3d.com)

  NTSC filter
  (c) Copyright 2006 - 2007  Shay Green

  GTK+ GUI code
  (c) Copyright 2004 - 2016  BearOso

  Win32 GUI code
  (c) Copyright 2003 - 2006  blip,
                             funkyass,
                             Matthew Kendora,
                             Nach,
                             nitsuja
  (c) Copyright 2009 - 2016  OV2

  Mac OS GUI code
  (c) Copyright 1998 - 2001  John Stiles
  (c) Copyright 2001 - 2011  zones

  Libretro port
  (c) Copyright 2011 - 2016  Hans-Kristian Arntzen,
                             Daniel De Matteis
                             (Under no circumstances will commercial rights be given)


  Specific ports contains the works of other authors. See headers in
  individual files.


  Snes9x homepage: http://www.snes9x.com/

  Permission to use, copy, modify and/or distribute Snes9x in both binary
  and source form, for non-commercial purposes, is hereby granted without
  fee, providing that this license information and copyright notice appear
  with all copies and any derived work.

  This software is provided 'as-is', without any express or implied
  warranty. In no event shall the authors be held liable for any damages
  arising from the use of this software or it's derivatives.

  Snes9x is freeware for PERSONAL USE only. Commercial users should
  seek permission of the copyright holders first. Commercial use includes,
  but is not limited to, charging money for Snes9x or software derived from
  Snes9x, including Snes9x or derivatives in commercial game bundles, and/or
  using Snes9x as a promotion for your commercial product.

  The copyright holders request that bug fixes and improvements to the code
  should be forwarded to them so everyone can benefit from the modifications
  in future versions.

  Super NES and Super Nintendo Entertainment System are trademarks of
  Nintendo Co., Limited and its subsidiary companies.
 ***********************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#ifdef HAVE_STRINGS_H
#include <strings.h>
#endif
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#ifdef HAVE_SYS_IOCTL_H
#include <sys/ioctl.h>
#endif
#include <chrono>
#include <thread>

#include "port.h"
#include "blit.h"
#include "snes9x.h"
#include "memmap.h"
#include "apu/apu.h"
#include "gfx.h"
#include "snapshot.h"
#include "controls.h"
#include "cheats.h"
#include "movie.h"
#include "logger.h"
#include "display.h"
#include "conffile.h"

#include <SDL/SDL.h>

#include <emscripten.h>

static uint16* snes_pixels = nullptr;
static uint32* pixel_buffer = nullptr;
static bool    is_external_screen_buffer = false;
static int     snes_pixel_count = 0;
static int     snes_img_w = 0;
static int     snes_img_h = 0;

static uint32  screen_update_times = 0;
static uint32  game_sound_buffer_size = 100;

static bool is_running = false;

SDL_AudioSpec *audiospec;

static const char	*s9x_base_dir  = NULL;
static char		default_dir[PATH_MAX + 1];

typedef	void (* Blitter) (uint8 *, int, uint8 *, int, int, int);

enum
{
	VIDEOMODE_BLOCKY = 1,
	VIDEOMODE_TV,
	VIDEOMODE_SMOOTH,
	VIDEOMODE_SUPEREAGLE,
	VIDEOMODE_2XSAI,
	VIDEOMODE_SUPER2XSAI,
	VIDEOMODE_EPX,
	VIDEOMODE_HQ2X
};

static const char	dirNames[13][32] =
{
	"",				// DEFAULT_DIR
	"",				// HOME_DIR
	"",				// ROMFILENAME_DIR
	"rom",			// ROM_DIR
	"sram",			// SRAM_DIR
	"savestate",	// SNAPSHOT_DIR
	"screenshot",	// SCREENSHOT_DIR
	"spc",			// SPC_DIR
	"cheat",		// CHEAT_DIR
	"patch",		// IPS_DIR
	"bios",			// BIOS_DIR
	"log",			// LOG_DIR
	""
};

static void NSRTControllerSetup (void);

static void FatalError (const char *str)
{
	fprintf(stderr, "%s\n", str);
	S9xExit();
}

void S9xInitDisplay (int argc, char **argv)
{
	EM_ASM( console.log("Going to create buffers... "); );
	
	snes_img_w = IMAGE_WIDTH;
	snes_img_h = IMAGE_HEIGHT;

	snes_pixel_count = snes_img_w * snes_img_h;

	EM_ASM_({
		window.set_game_screen_size($0, $1);
	}, snes_img_w, snes_img_h);

	// Allocate snes pixel buffer
	if (snes_pixels == nullptr)
	{
		EM_ASM( console.log("create display buffer... "); );
		snes_pixels = new (std::nothrow) uint16[snes_pixel_count];
	}
	if (snes_pixels == nullptr)
	{
		fprintf(stderr, "Could not allocate pixel buffer.\n");
		S9xExit();
	}
	
	EM_ASM( console.log("Going to init display... "); );

	// Set up Snes9x GFX
	GFX.Pitch = snes_img_w * 2;
	GFX.Screen = snes_pixels;

	S9xGraphicsInit();
}

void S9xDeinitDisplay (void)
{
	S9xGraphicsDeinit();

	if (snes_pixels != nullptr && !is_external_screen_buffer)
	{
		delete[] snes_pixels;
		snes_pixels = nullptr;
	}

	snes_pixel_count = 0;
	screen_update_times = 0;
}

void S9xPutImage (int width, int height)
{
	static int prevWidth = 0;
	static int prevHeight = 0;

	screen_update_times++;

	if ((width <= SNES_WIDTH) && ((prevWidth != width) || (prevHeight != height)))
	{
		//EM_ASM(console.log("clean up screen"););
		//S9xBlitClearDelta(); // if need this, you must run S9xBlitFilterInit() first
		//EM_ASM(window.clear_tex_buf(););
	}

	if (prevWidth != width)
		EM_ASM_({
			window.update_scene_width($1);
			console.log("width changed: " + $0 + " => " + $1);
		}, prevWidth, width);

	if (prevHeight != height)
		EM_ASM_({
			window.update_scene_height($1);
			console.log("height changed: " + $0 + " => " + $1);
		}, prevHeight, height);


	if (!is_external_screen_buffer && pixel_buffer)
	{
		uint16 color = 0;
		uint8 r,g,b;
	
		int linelen = snes_img_w;
		uint16* src = (uint16*) GFX.Screen;
		
		for (int y=0; y<height; y++)
		{
			for(int x=0; x<width; x++)
			{
				color = src[y * linelen + x];
				
				r = ((color>>11) & 0x1f) << 3;
				g = ((color>>5) & 0x3f) << 2;
				b = (color & 0x1f) << 3;

				pixel_buffer[y * linelen + x] = (255 << 24) | (b << 16) | (g << 8) | r;
				
			}
		}
	}
	
	EM_ASM( window.update_tex(); );

	prevWidth  = width;
	prevHeight = height;
}

void S9xToggleSoundChannel (int c)
{
	static uint8 sound_switch = 255;
	if (c == 8) sound_switch = 255;
	else sound_switch ^= 1 << c;
	S9xSetSoundControl(sound_switch);
}

static void sdl_audio_callback (void *userdata, Uint8 *stream, int len)
{   
    SDL_LockAudio ();
    S9xMixSamples (stream, len >> (Settings.SixteenBitSound ? 1 : 0));
    SDL_UnlockAudio ();
    return;
}

static void samples_available (void *data)
{   
    SDL_LockAudio ();
    S9xFinalizeSamples ();
    SDL_UnlockAudio ();
    return;
}

bool8 S9xOpenSoundDevice (void)
{
	//SDL_InitSubSystem (SDL_INIT_AUDIO);
	SDL_Init (SDL_INIT_AUDIO);

	audiospec = (SDL_AudioSpec *) malloc (sizeof (SDL_AudioSpec));
	
	audiospec->freq = Settings.SoundPlaybackRate;
	audiospec->channels = Settings.Stereo ? 2 : 1;
	audiospec->format = Settings.SixteenBitSound ? AUDIO_S16SYS : AUDIO_U8;

    audiospec->samples = 1024; // needs to be power-of-two

	audiospec->callback = sdl_audio_callback;
	
	printf ("SDL sound driver initializing...\n");
	printf (" => (Frequency: %dhz, Latency: %dms)...", audiospec->freq,
			(audiospec->samples * 1000 / audiospec->freq) << 1);
	
	if (SDL_OpenAudio (audiospec, NULL) < 0)
	{
		printf ("Failed\n");
		free (audiospec);
		audiospec = NULL;
		return FALSE;
	}
	
	printf ("OK\n");
	
	SDL_PauseAudio(0);
	
	S9xSetSamplesAvailableCallback (samples_available, NULL);
    return TRUE;

}

void S9xInitInputDevices (int r, int l, int d, int u, int st, int sl, int a, int b, int x, int y, int lb, int rb)
{
	S9xUnmapAllControls();

    S9xMapButton(r, S9xGetCommandT("Joypad1 Right"), false);
    S9xMapButton(l, S9xGetCommandT("Joypad1 Left"), false);
    S9xMapButton(d, S9xGetCommandT("Joypad1 Down"), false);
    S9xMapButton(u, S9xGetCommandT("Joypad1 Up"), false);
    S9xMapButton(st, S9xGetCommandT("Joypad1 Start"), false);
    S9xMapButton(sl,  S9xGetCommandT("Joypad1 Select"), false);
    S9xMapButton(a, S9xGetCommandT("Joypad1 A"), false);
    S9xMapButton(b, S9xGetCommandT("Joypad1 B"), false);
    S9xMapButton(x, S9xGetCommandT("Joypad1 X"), false);
    S9xMapButton(y, S9xGetCommandT("Joypad1 Y"), false);
    S9xMapButton(lb, S9xGetCommandT("Joypad1 L"), false);
    S9xMapButton(rb, S9xGetCommandT("Joypad1 R"), false);

}

void S9xSetTitle (const char *str)
{
	SDL_WM_SetCaption(str, str);
}

void S9xProcessEvents (bool8 block)
{
	SDL_Event event;
	bool8 quit_state = FALSE;

	while ((block) || (SDL_PollEvent (&event) != 0))
	{
		switch (event.type) {
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			// domaemon: not sure it's the best idea, but reserving the SDLK_q for quit.
			if (event.key.keysym.sym == SDLK_q)
			{
				quit_state = TRUE;
			}
			else
			{
				S9xReportButton(event.key.keysym.mod << 16 | // keyboard mod
						event.key.keysym.sym, // keyboard ksym
						event.type == SDL_KEYDOWN); // press or release
			}
			break;

		case SDL_QUIT:
			// domaemon: we come here when the window is getting closed.
			quit_state = TRUE;
			break;
		}
	}

	if (quit_state == TRUE)
	{
		printf ("Quit Event. Bye.\n");
		S9xExit();
	}
}

extern "C" int framesf()
{
	return screen_update_times;
}

extern "C" void showfpsf(int fps, int flags)
{
	static char txt[20];
	sprintf(txt, flags > 0 ? (flags == 1 ? "FPS=%d (WebGL)" : "FPS=%d (WebGL2)") : "FPS=%d (Canvas)", fps);
	S9xSetInfoString(txt);
}

extern "C" void savesramf()
{
	S9xAutoSaveSRAM();
}

extern "C" void setsrf(int inputRate, int outputRate)
{
	Settings.SoundPlaybackRate = outputRate;
	Settings.SoundInputRate = inputRate;
}

extern "C" void setscreenbuff(uint16* screenbuf)
{
	snes_pixels = screenbuf;
	is_external_screen_buffer = true;
	EM_ASM( console.log("set game display buffer! "); );
}

extern "C" void setpixelbuff(uint32* pixelbuf)
{
	pixel_buffer = pixelbuf;
	EM_ASM( console.log("set gui display buffer! "); );
}

extern "C" void rptbtnf(int key, int state)
{
	S9xReportButton(key, state > 0);
}

void mainloop()
{
	S9xProcessEvents(FALSE);
	S9xMainLoop();
}

void load(char *filename) 
{
	Settings.StopEmulation = TRUE;
	S9xSetSoundMute(TRUE);

	uint32 saved_flags = CPU.Flags;
	bool8 loaded = FALSE;

	loaded = Memory.LoadROM(filename);
	if (!loaded)
	{
		fprintf(stderr, "Error opening the ROM file. %s\n", filename);
		exit(1);
	}

	printf("Attempting to load SRAM %s.\n", S9xGetFilename(".srm", SRAM_DIR));
	bool8 sramloaded = Memory.LoadSRAM(S9xGetFilename(".srm", SRAM_DIR));
	if (sramloaded) printf("Load SRAM successful.\n");
	else printf("Failed to load SRAM.\n");

	CPU.Flags = saved_flags;
	Settings.StopEmulation = FALSE;

	sprintf(String, "\"%s\" %s: %s", Memory.ROMName, TITLE, VERSION);
	S9xSetTitle(String);

	S9xSetSoundMute(FALSE);

	printf("before start\n");
    printf("registers.pcw=%x\n", Registers.PCw);
}

extern "C" void run(char *filename) 
{
    load(filename);
	if (!is_running)
	{
		is_running = true;
		printf("start main loop\n");
		emscripten_set_main_loop(mainloop, 0, 0);
	}
	else S9xSoftReset();
}

extern "C" int mainf (int argc, char **argv)
{
	printf("\n\nSnes9x " VERSION " for HTML5 (with EM + SDL)\n");

	snprintf(default_dir, PATH_MAX + 1, "%s%s%s", getenv("HOME"), SLASH_STR, ".snes9x");
	s9x_base_dir = default_dir;

	EM_ASM(
		console.log('Syncing file system...');
		FS.mkdir('/home/web_user/.snes9x');
		FS.mkdir('/home/web_user/.snes9x/sram');
		FS.mount(IDBFS, {}, '/home/web_user/.snes9x/sram');
		FS.syncfs(true, function(err) {
			if (err) console.error(err);
			else {
				console.log('File system synced.');
				window.initSNES();
			}
		});
	);

	memset(&Settings, 0, sizeof(Settings));
	Settings.MouseMaster = TRUE;
	Settings.SuperScopeMaster = TRUE;
	Settings.JustifierMaster = TRUE;
	Settings.MultiPlayer5Master = FALSE;
	Settings.FrameTimePAL = 20000;
	Settings.FrameTimeNTSC = 16667;
	Settings.SixteenBitSound = TRUE;
	Settings.Stereo = TRUE;
	Settings.SupportHiRes = TRUE;
	Settings.Transparency = TRUE;
	Settings.AutoDisplayMessages = TRUE;
	Settings.InitialInfoStringTimeout = 120;
	Settings.HDMATimingHack = 100;
	Settings.BlockInvalidVRAMAccessMaster = FALSE;
	Settings.StopEmulation = TRUE;
	Settings.WrongMovieStateProtection = TRUE;
	Settings.DumpStreamsMaxFrames = -1;
	Settings.DisplayFrameRate = FALSE;
	Settings.StretchScreenshots = 1;
	Settings.SnapshotScreenshots = TRUE;
	Settings.SkipFrames = 0;
	Settings.TurboSkipFrames = 15;
	Settings.CartAName[0] = 0;
	Settings.CartBName[0] = 0;
	Settings.NoPatch= TRUE;
	Settings.SoundSync = FALSE;

	Settings.Mute = FALSE;
	Settings.SoundPlaybackRate = 22100;
	Settings.SoundInputRate = 22100;

	EM_ASM( window.update_sound_sample_rates(); );

	printf("SoundInputRate: %d, SoundPlaybackRate: %d, Channels: %d \n", 
			Settings.SoundInputRate, Settings.SoundPlaybackRate, Settings.Stereo ? 2 : 1);

	CPU.Flags = 0;
	if (!Memory.Init() || !S9xInitAPU())
	{
		fprintf(stderr, "Snes9x: Memory allocation failure.\nExiting...\n");
		Memory.Deinit();
		S9xDeinitAPU();
		exit(1);
	}

	S9xSetRenderPixelFormat(RGB565);
	S9xInitDisplay(NULL, NULL);

	S9xInitSound(game_sound_buffer_size, 0);
	S9xSetSoundMute(TRUE);

	NSRTControllerSetup();
	S9xReportControllers();
	S9xInitInputDevices(1103, 1104, 1105, 1106, 13, 32, 120, 122, 114, 97, 113, 119);

	//emscripten_exit_with_live_runtime();

	return 0;
}

static void NSRTControllerSetup (void)
{
	if (!strncmp((const char *) Memory.NSRTHeader + 24, "NSRT", 4))
	{
		// First plug in both, they'll change later as needed
		S9xSetController(0, CTL_JOYPAD, 0, 0, 0, 0);
		S9xSetController(1, CTL_JOYPAD, 1, 0, 0, 0);

		switch (Memory.NSRTHeader[29])
		{
			case 0x00:	// Everything goes
				break;

			case 0x10:	// Mouse in Port 0
				S9xSetController(0, CTL_MOUSE,      0, 0, 0, 0);
				break;

			case 0x01:	// Mouse in Port 1
				S9xSetController(1, CTL_MOUSE,      1, 0, 0, 0);
				break;

			case 0x03:	// Super Scope in Port 1
				S9xSetController(1, CTL_SUPERSCOPE, 0, 0, 0, 0);
				break;

			case 0x06:	// Multitap in Port 1
				S9xSetController(1, CTL_MP5,        1, 2, 3, 4);
				break;

			case 0x66:	// Multitap in Ports 0 and 1
				S9xSetController(0, CTL_MP5,        0, 1, 2, 3);
				S9xSetController(1, CTL_MP5,        4, 5, 6, 7);
				break;

			case 0x08:	// Multitap in Port 1, Mouse in new Port 1
				S9xSetController(1, CTL_MOUSE,      1, 0, 0, 0);
				// There should be a toggle here for putting in Multitap instead
				break;

			case 0x04:	// Pad or Super Scope in Port 1
				S9xSetController(1, CTL_SUPERSCOPE, 0, 0, 0, 0);
				// There should be a toggle here for putting in a pad instead
				break;

			case 0x05:	// Justifier - Must ask user...
				S9xSetController(1, CTL_JUSTIFIER,  1, 0, 0, 0);
				// There should be a toggle here for how many justifiers
				break;

			case 0x20:	// Pad or Mouse in Port 0
				S9xSetController(0, CTL_MOUSE,      0, 0, 0, 0);
				// There should be a toggle here for putting in a pad instead
				break;

			case 0x22:	// Pad or Mouse in Port 0 & 1
				S9xSetController(0, CTL_MOUSE,      0, 0, 0, 0);
				S9xSetController(1, CTL_MOUSE,      1, 0, 0, 0);
				// There should be a toggles here for putting in pads instead
				break;

			case 0x24:	// Pad or Mouse in Port 0, Pad or Super Scope in Port 1
				// There should be a toggles here for what to put in, I'm leaving it at gamepad for now
				break;

			case 0x27:	// Pad or Mouse in Port 0, Pad or Mouse or Super Scope in Port 1
				// There should be a toggles here for what to put in, I'm leaving it at gamepad for now
				break;

			// Not Supported yet
			case 0x99:	// Lasabirdie
				break;

			case 0x0A:	// Barcode Battler
				break;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
// Functions called by Snes9x below
///////////////////////////////////////////////////////////////////////////////

void _makepath (char *path, const char *, const char *dir, const char *fname, const char *ext)
{
	if (dir && *dir)
	{
		strcpy(path, dir);
		strcat(path, SLASH_STR);
	}
	else
		*path = 0;

	strcat(path, fname);

	if (ext && *ext)
	{
		strcat(path, ".");
		strcat(path, ext);
	}
}

void _splitpath (const char *path, char *drive, char *dir, char *fname, char *ext)
{
	*drive = 0;

	const char	*slash = strrchr(path, SLASH_CHAR),
				*dot   = strrchr(path, '.');

	if (dot && slash && dot < slash)
		dot = NULL;

	if (!slash)
	{
		*dir = 0;

		strcpy(fname, path);

		if (dot)
		{
			fname[dot - path] = 0;
			strcpy(ext, dot + 1);
		}
		else
			*ext = 0;
	}
	else
	{
		strcpy(dir, path);
		dir[slash - path] = 0;

		strcpy(fname, slash + 1);

		if (dot)
		{
			fname[dot - slash - 1] = 0;
			strcpy(ext, dot + 1);
		}
		else
			*ext = 0;
	}
}

/**
 * Display port-specific usage information
 */
void S9xExtraUsage()
{
}

/**
 * Parse port-specific arguments
 */
void S9xParseArg(char** argv, int& i, int argc)
{
}

/**
 * Parse port-specific config
 */
void S9xParsePortConfig(ConfigFile &conf, int pass)
{
}

/**
 * Called when Snes9x wants to know the directory dirtype.
 */
const char * S9xGetDirectory (enum s9x_getdirtype dirtype)
{
	static char	s[PATH_MAX + 1];

	if (dirNames[dirtype][0])
		snprintf(s, PATH_MAX + 1, "%s%s%s", s9x_base_dir, SLASH_STR, dirNames[dirtype]);
	else
	{
		switch (dirtype)
		{
			case DEFAULT_DIR:
				strncpy(s, s9x_base_dir, PATH_MAX + 1);
				s[PATH_MAX] = 0;
				break;

			case HOME_DIR:
				strncpy(s, getenv("HOME"), PATH_MAX + 1);
				s[PATH_MAX] = 0;
				break;

			case ROMFILENAME_DIR:
				strncpy(s, Memory.ROMFilename, PATH_MAX + 1);
				s[PATH_MAX] = 0;

				for (int i = strlen(s); i >= 0; i--)
				{
					if (s[i] == SLASH_CHAR)
					{
						s[i] = 0;
						break;
					}
				}

				break;

			default:
				s[0] = 0;
				break;
		}
	}

	return (s);
}

/**
 * When Snes9x needs to know the name of the cheat/IPS file and so on, this function is called.
 * Check extension and dirtype, and return the appropriate filename.
 * The current ports return the ROM file path with the given extension.
 */
const char * S9xGetFilename (const char *ex, enum s9x_getdirtype dirtype)
{
	static char	s[PATH_MAX + 1];
	char		drive[_MAX_DRIVE + 1], dir[_MAX_DIR + 1], fname[_MAX_FNAME + 1], ext[_MAX_EXT + 1];

	_splitpath(Memory.ROMFilename, drive, dir, fname, ext);
	snprintf(s, PATH_MAX + 1, "%s%s%s%s", S9xGetDirectory(dirtype), SLASH_STR, fname, ex);

	return (s);
}

/**
 * Almost the same as S9xGetFilename function, but used for saving SPC files etc.
 * So you have to take care not to delete the previously saved file, by increasing
 * the number of the filename; romname.000.spc, romname.001.spc, ...
 */
const char * S9xGetFilenameInc (const char *ex, enum s9x_getdirtype dirtype)
{
	static char	s[PATH_MAX + 1];
	char		drive[_MAX_DRIVE + 1], dir[_MAX_DIR + 1], fname[_MAX_FNAME + 1], ext[_MAX_EXT + 1];

	unsigned int	i = 0;
	const char		*d;
	struct stat		buf;

	_splitpath(Memory.ROMFilename, drive, dir, fname, ext);
	d = S9xGetDirectory(dirtype);

	do
		snprintf(s, PATH_MAX + 1, "%s%s%s.%03d%s", d, SLASH_STR, fname, i++, ex);
	while (stat(s, &buf) == 0 && i < 1000);

	return (s);
}

/**
 * Called when Snes9x wants to know the name of the ROM image.
 * Typically, extract the filename from path and return it.
 */
const char * S9xBasename (const char *f)
{
	const char	*p;

	if ((p = strrchr(f, '/')) != NULL || (p = strrchr(f, '\\')) != NULL)
		return (p + 1);

	return (f);
}

const char * S9xSelectFilename (const char *def, const char *dir1, const char *ext1, const char *title)
{
	static char	s[PATH_MAX + 1];
	char		buffer[PATH_MAX + 1];

	printf("\n%s (default: %s): ", title, def);
	fflush(stdout);

	if (fgets(buffer, PATH_MAX + 1, stdin))
	{
		char	drive[_MAX_DRIVE + 1], dir[_MAX_DIR + 1], fname[_MAX_FNAME + 1], ext[_MAX_EXT + 1];

		char	*p = buffer;
		while (isspace(*p))
			p++;
		if (!*p)
		{
			strncpy(buffer, def, PATH_MAX + 1);
			buffer[PATH_MAX] = 0;
			p = buffer;
		}

		char	*q = strrchr(p, '\n');
		if (q)
			*q = 0;

		_splitpath(p, drive, dir, fname, ext);
		_makepath(s, drive, *dir ? dir : dir1, fname, *ext ? ext : ext1);

		return (s);
	}

	return (NULL);
}

/**
 * If your port can match Snes9x's built-in LoadFreezeFile/SaveFreezeFile command
 * (see controls.cpp), you may choose to use this function. Otherwise return NULL.
 */
const char * S9xChooseFilename (bool8 read_only)
{
	char	s[PATH_MAX + 1];
	char	drive[_MAX_DRIVE + 1], dir[_MAX_DIR + 1], fname[_MAX_FNAME + 1], ext[_MAX_EXT + 1];

	const char	*filename;
	char		title[64];

	_splitpath(Memory.ROMFilename, drive, dir, fname, ext);
	snprintf(s, PATH_MAX + 1, "%s.frz", fname);
	sprintf(title, "%s snapshot filename", read_only ? "Select load" : "Choose save");

	S9xSetSoundMute(TRUE);
	filename = S9xSelectFilename(s, S9xGetDirectory(SNAPSHOT_DIR), "frz", title);

	S9xSetSoundMute(FALSE);

	return (filename);
}

/**
 * If your port can match Snes9x's built-in BeginRecordingMovie/LoadMovie command
 * (see controls.cpp), you may choose to use this function. Otherwise return NULL.
 */
const char* S9xChooseMovieFilename(bool8 read_only)
{
	printf("S9xChooseMovieFilename\n");
	return nullptr;
}

/**
 * This function opens a freeze-game file. STREAM is defined as a gzFile if ZLIB is
 * defined else it's defined as FILE *. The read_only parameter is set to true when
 * reading a freeze-game file and false when writing a freeze-game file.
 * Open the file filepath and return its pointer file.
 */
bool8 S9xOpenSnapshotFile (const char *filename, bool8 read_only, STREAM *file)
{
	printf("open snapshotfile\n");
	return FALSE;
}

/**
 * This function closes the freeze-game file opened by S9xOpenSnapshotFile function.
 */
void S9xCloseSnapshotFile(STREAM file)
{
	printf("close snapshotfile\n");
	//CLOSE_STREAM(file);
}

/**
 * Called just before Snes9x begins to render an SNES screen.
 * Use this function if you should prepare before drawing, otherwise let it empty.
 */
bool8 S9xInitUpdate()
{
	return TRUE;
}

/**
 * Called at the end of screen refresh if GFX.DoInterlace && GFX.InterlaceFrame == 0 is true (?).
 */
bool8 S9xContinueUpdate(int width, int height)
{
	EM_ASM(console.log("S9xContinueUpdate()"););
	return TRUE;
}

/**
 * Called once a complete SNES screen has been rendered into the GFX.Screen memory buffer,
 * now is your chance to copy the SNES rendered screen to the host computer's screen memory.
 * The problem is that you have to cope with different sized SNES rendered screens:
 * 256*224, 256*239, 512*224, 512*239, 512*448 and 512*478.
 */
bool8 S9xDeinitUpdate(int width, int height)
{
	S9xPutImage(width, height);
	return TRUE;
}

/**
 * If your port can match Snes9x's built-in SoundChannelXXX command (see controls.cpp),
 * you may choose to use this function. Otherwise return NULL.
 * Basically, turn on/off the sound channel c (0-7), and turn on all channels if c is 8.
 */
//void S9xToggleSoundChannel(int c)
//{
//}

/**
 * If Settings.AutoSaveDelay is not zero, Snes9x calls this function when the contents of
 * the S-RAM has been changed. Typically, call Memory.SaveSRAM function from this function.
 */
void S9xAutoSaveSRAM()
{
	Memory.SaveSRAM(S9xGetFilename(".srm", SRAM_DIR));
}

/**
 * Called at the end of S9xMainLoop function, when emulating one frame has been done.
 * You should adjust the frame rate in this function
 */
void S9xSyncSpeed()
{
	IPPU.RenderThisFrame = (++IPPU.SkippedFrames >= Settings.SkipFrames) ? TRUE : FALSE;
	if (IPPU.RenderThisFrame) IPPU.SkippedFrames = 0;
}

/**
 * Called by Snes9x to poll for buttons that should be polled.
 */
bool S9xPollButton(uint32 id, bool* pressed)
{
	return false;
}

/**
 * Called by Snes9x to poll for axises that should be polled.
 */
bool S9xPollAxis(uint32 id, int16* value)
{
	return false;
}

/**
 * Called by Snes9x to poll for poiters that should be polled.
 */
bool S9xPollPointer(uint32 id, int16* x, int16* y)
{
	return false;
}

/**
 * Handle port-specific commands (?).
 */
void S9xHandlePortCommand(s9xcommand_t cmd, int16 data1, int16 data2)
{
}

/**
 * S9xInitSound function calls this function to actually open the host sound device.
 */
//bool8 S9xOpenSoundDevice(void)
//{
//}

/**
 * Called when some fatal error situation arises or when the “q” debugger command is used.
 */
void S9xExit()
{
	S9xSetSoundMute(TRUE);
	Settings.StopEmulation = TRUE;

#ifdef NETPLAY_SUPPORT
	if (Settings.NetPlay) S9xNPDisconnect();
#endif

	Memory.SaveSRAM(S9xGetFilename(".srm", SRAM_DIR));

#ifdef FANCY
	S9xSaveCheatFile(S9xGetFilename(".cht", CHEAT_DIR));
	S9xResetSaveTimer(FALSE);
#endif

	S9xUnmapAllControls();
	S9xDeinitDisplay();
	Memory.Deinit();
	S9xDeinitAPU();

	exit(0);
}

/**
 * When Snes9x wants to display an error, information or warning message, it calls this function.
 * Check in messages.h for the types and individual message numbers that Snes9x currently passes as parameters.
 * The idea is display the message string so the user can see it, but you choose not to display anything at all,
 * or change the message based on the message number or message type.
 * Eventually all debug output will also go via this function, trace information already does.
 */
void S9xMessage(int type, int number, const char* message)
{
	printf("S9xMessage - type: %d number: %d message: %s\n", type, number, message);
}

/**
 * Used by Snes9x to ask the user for input.
 */
const char* S9xStringInput(const char *message)
{
	static char  buffer[256];

	printf("%s: ", message);
	fflush(stdout);

	if (fgets(buffer, sizeof(buffer) - 2, stdin))
	{
		return buffer;
	}

	return nullptr;
}

/**
 * Called when the SNES color palette has changed.
 * Use this function if your system should change its color palette to match the SNES's.
 * Otherwise let it empty.
 */
void S9xSetPalette()
{
}
