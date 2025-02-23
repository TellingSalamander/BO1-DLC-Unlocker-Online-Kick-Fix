﻿// dllmain.cpp : Definiuje punkt wejścia dla aplikacji DLL.
#include "pch.h"
#include <Psapi.h>
#include <stdlib.h>
#include <cstdio>

HINSTANCE hOriginalBink = NULL;
FARPROC p[72] = { 0 };

void GetAddresses()
{
	hOriginalBink = LoadLibraryA("binkw32_o.dll");
	if (hOriginalBink)
	{
		p[0] = GetProcAddress(hOriginalBink, "_BinkBufferBlit@12");
		p[1] = GetProcAddress(hOriginalBink, "_BinkBufferCheckWinPos@12");
		p[2] = GetProcAddress(hOriginalBink, "_BinkBufferClear@8");
		p[3] = GetProcAddress(hOriginalBink, "_BinkBufferClose@4");
		p[4] = GetProcAddress(hOriginalBink, "_BinkBufferGetDescription@4");
		p[5] = GetProcAddress(hOriginalBink, "_BinkBufferGetError@0");
		p[6] = GetProcAddress(hOriginalBink, "_BinkBufferLock@4");
		p[7] = GetProcAddress(hOriginalBink, "_BinkBufferOpen@16");
		p[8] = GetProcAddress(hOriginalBink, "_BinkBufferSetDirectDraw@8");
		p[9] = GetProcAddress(hOriginalBink, "_BinkBufferSetHWND@8");
		p[10] = GetProcAddress(hOriginalBink, "_BinkBufferSetOffset@12");
		p[11] = GetProcAddress(hOriginalBink, "_BinkBufferSetResolution@12");
		p[12] = GetProcAddress(hOriginalBink, "_BinkBufferSetScale@12");
		p[13] = GetProcAddress(hOriginalBink, "_BinkBufferUnlock@4");
		p[14] = GetProcAddress(hOriginalBink, "_BinkCheckCursor@20");
		p[15] = GetProcAddress(hOriginalBink, "_BinkClose@4");
		p[16] = GetProcAddress(hOriginalBink, "_BinkCloseTrack@4");
		p[17] = GetProcAddress(hOriginalBink, "_BinkControlBackgroundIO@8");
		p[18] = GetProcAddress(hOriginalBink, "_BinkControlPlatformFeatures@8");
		p[19] = GetProcAddress(hOriginalBink, "_BinkCopyToBuffer@28");
		p[20] = GetProcAddress(hOriginalBink, "_BinkCopyToBufferRect@44");
		p[21] = GetProcAddress(hOriginalBink, "_BinkDDSurfaceType@4");
		p[22] = GetProcAddress(hOriginalBink, "_BinkDX8SurfaceType@4");
		p[23] = GetProcAddress(hOriginalBink, "_BinkDX9SurfaceType@4");
		p[24] = GetProcAddress(hOriginalBink, "_BinkDoFrame@4"); // doframeasync, doframeasyncwait, doframeplane
		p[25] = GetProcAddress(hOriginalBink, "_BinkGetError@0");
		p[26] = GetProcAddress(hOriginalBink, "_BinkGetFrameBuffersInfo@8");
		p[27] = GetProcAddress(hOriginalBink, "_BinkGetKeyFrame@12");
		p[28] = GetProcAddress(hOriginalBink, "_BinkGetPalette@4");
		p[29] = GetProcAddress(hOriginalBink, "_BinkGetRealtime@12");
		p[30] = GetProcAddress(hOriginalBink, "_BinkGetRects@8");
		p[31] = GetProcAddress(hOriginalBink, "_BinkGetSummary@8");
		p[32] = GetProcAddress(hOriginalBink, "_BinkGetTrackData@8");
		p[33] = GetProcAddress(hOriginalBink, "_BinkGetTrackID@8");
		p[34] = GetProcAddress(hOriginalBink, "_BinkGetTrackMaxSize@8");
		p[35] = GetProcAddress(hOriginalBink, "_BinkGetTrackType@8");
		p[36] = GetProcAddress(hOriginalBink, "_BinkGoto@12");
		p[37] = GetProcAddress(hOriginalBink, "_BinkIsSoftwareCursor@8");
		p[38] = GetProcAddress(hOriginalBink, "_BinkLogoAddress@0");
		p[39] = GetProcAddress(hOriginalBink, "_BinkNextFrame@4");
		p[40] = GetProcAddress(hOriginalBink, "_BinkOpen@8");
		p[41] = GetProcAddress(hOriginalBink, "_BinkOpenDirectSound@4");
		p[42] = GetProcAddress(hOriginalBink, "_BinkOpenMiles@4");
		p[43] = GetProcAddress(hOriginalBink, "_BinkOpenTrack@8");
		p[44] = GetProcAddress(hOriginalBink, "_BinkOpenWaveOut@4");
		p[45] = GetProcAddress(hOriginalBink, "_BinkPause@8");
		p[46] = GetProcAddress(hOriginalBink, "_BinkRegisterFrameBuffers@8"); // blinkrequeststopasyncthread
		p[47] = GetProcAddress(hOriginalBink, "_BinkRestoreCursor@4");
		p[48] = GetProcAddress(hOriginalBink, "_BinkService@4");
		p[49] = GetProcAddress(hOriginalBink, "_BinkSetError@4");
		p[50] = GetProcAddress(hOriginalBink, "_BinkSetFrameRate@8");
		p[51] = GetProcAddress(hOriginalBink, "_BinkSetIO@4");
		p[52] = GetProcAddress(hOriginalBink, "_BinkSetIOSize@4");
		p[53] = GetProcAddress(hOriginalBink, "_BinkSetMemory@8");
		p[54] = GetProcAddress(hOriginalBink, "_BinkSetMixBinVolumes@20");
		p[55] = GetProcAddress(hOriginalBink, "_BinkSetMixBins@16");
		p[56] = GetProcAddress(hOriginalBink, "_BinkSetPan@12");
		p[57] = GetProcAddress(hOriginalBink, "_BinkSetSimulate@4");
		p[58] = GetProcAddress(hOriginalBink, "_BinkSetSoundOnOff@8");
		p[59] = GetProcAddress(hOriginalBink, "_BinkSetSoundSystem@8");
		p[60] = GetProcAddress(hOriginalBink, "_BinkSetSoundTrack@8");
		p[61] = GetProcAddress(hOriginalBink, "_BinkSetVideoOnOff@8");
		p[62] = GetProcAddress(hOriginalBink, "_BinkSetVolume@12");
		p[63] = GetProcAddress(hOriginalBink, "_BinkShouldSkip@4"); // blinkstartasyncthread
		p[64] = GetProcAddress(hOriginalBink, "_BinkWait@4"); // blinkwaitstopasyncthread
		p[65] = GetProcAddress(hOriginalBink, "_RADTimerRead@0");
		p[66] = GetProcAddress(hOriginalBink, "_BinkDoFrameAsync@12");
		p[67] = GetProcAddress(hOriginalBink, "_BinkDoFrameAsyncWait@8");
		p[68] = GetProcAddress(hOriginalBink, "_BinkDoFramePlane@8");
		p[69] = GetProcAddress(hOriginalBink, "_BinkRequestStopAsyncThread@4");
		p[70] = GetProcAddress(hOriginalBink, "_BinkStartAsyncThread@8");
		p[71] = GetProcAddress(hOriginalBink, "_BinkWaitStopAsyncThread@4");

		for (int i = 0; i < 72; i++) {
			if (!p[i]) {
				MessageBoxA(NULL, "ERROR: Some export from binkw32.dll has not been found! (wrong file?)", "ERROR", MB_OK | MB_ICONERROR);
				exit(0);
			}
		}

	}
	else
	{
		MessageBoxA(NULL, "ERROR: Original binkw32.dll (binkw32_o.dll) file not found!", "ERROR", MB_OK | MB_ICONERROR);
		exit(0);
	}
}


DWORD FindPattern(const char* pattern, const char* mask)
{

	HMODULE hModule = GetModuleHandle(NULL);

	MODULEINFO mInfo; GetModuleInformation(GetCurrentProcess(), hModule, &mInfo, sizeof(MODULEINFO));
	DWORD base = (DWORD)mInfo.lpBaseOfDll;
	DWORD size = (DWORD)mInfo.SizeOfImage;
	DWORD patternLength = (DWORD)strlen(mask);
	for (DWORD i = 0; i < size - patternLength; i++)
	{
		bool found = true;
		for (DWORD j = 0; j < patternLength; j++)
		{
			found &= mask[j] == '?' || pattern[j] == *(char*)(base + i + j);
		}
		if (found)
		{
			return base + i;
		}
	}
	return NULL;

}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    if(ul_reason_for_call == DLL_PROCESS_ATTACH) {
		GetAddresses();

		DWORD toPatch = FindPattern("\x75\x2F\x8B\x86\xB0\xEE\x03\x00\x3B", "xxxxxxxxx"); // 75 2F 8B 86 B0 EE 03 00 3B
		if (!toPatch) {
			MessageBoxA(NULL, "Error while searching for a thing to fix! (wrong game?)", "ERROR", MB_OK | MB_ICONERROR);
			exit(0);
		}
		DWORD prot;
		VirtualProtect((LPVOID)toPatch, 2, PAGE_EXECUTE_READWRITE, &prot);
		*(char*)toPatch     = 0x90; // NOP
		*(char*)(toPatch+1) = 0x90; // NOP
		VirtualProtect((LPVOID)toPatch, 2, prot, &prot);

		if (FILE* file = fopen("KickFixer.txt", "r")) {
			fclose(file);
		}
		else {
			MessageBoxA(NULL, "DLC Unlocker Host Kick Fix made by kuba6000!\r\nhttps://www.youtube.com/@Kuba6000\r\n\r\nHappy playing! This message will never show again!", "Kick Fixer", MB_OK | MB_ICONEXCLAMATION);
			file = fopen("KickFixer.txt", "w");
			const char* toWrite = "DLC Unlocker Host Kick Fix made by kuba6000!\r\nhttps://www.youtube.com/@Kuba6000\r\n\r\nHappy playing!";
			fwrite(toWrite, sizeof(char), strlen(toWrite) + 1, file);
			fclose(file);
		}


    }
    return TRUE;
}

// Proxy to all the shit from the original dll

// _BinkBufferBlit@12
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferBlit(int a1, int a2, int a3)
{
	__asm
	{
		jmp p[0 * 4];
	}
}

// _BinkBufferCheckWinPos@12
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferCheckWinPos(int a1, int a2, int a3)
{
	__asm
	{
		jmp p[1 * 4];
	}
}

// _BinkBufferClear@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferClear(int a1, int a2)
{
	__asm
	{
		jmp p[2 * 4];
	}
}

// _BinkBufferClose@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferClose(int a1)
{
	__asm
	{
		jmp p[3 * 4];
	}
}

// _BinkBufferGetDescription@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferGetDescription(int a1)
{
	__asm
	{
		jmp p[4 * 4];
	}
}

// _BinkBufferGetError@0
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferGetError()
{
	__asm
	{
		jmp p[5 * 4];
	}
}

// _BinkBufferLock@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferLock(int a1)
{
	__asm
	{
		jmp p[6 * 4];
	}
}

// _BinkBufferOpen@16
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferOpen(int a1, int a2, int a3, int a4)
{
	__asm
	{
		jmp p[7 * 4];
	}
}

// _BinkBufferSetDirectDraw@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferSetDirectDraw(int a1, int a2)
{
	__asm
	{
		jmp p[8 * 4];
	}
}

// _BinkBufferSetHWND@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferSetHWND(int a1, int a2)
{
	__asm
	{
		jmp p[9 * 4];
	}
}

// _BinkBufferSetOffset@12
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferSetOffset(int a1, int a2, int a3)
{
	__asm
	{
		jmp p[10 * 4];
	}
}

// _BinkBufferSetResolution@12
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferSetResolution(int a1, int a2, int a3)
{
	__asm
	{
		jmp p[11 * 4];
	}
}

// _BinkBufferSetScale@12
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferSetScale(int a1, int a2, int a3)
{
	__asm
	{
		jmp p[12 * 4];
	}
}

// _BinkBufferUnlock@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferUnlock(int a1)
{
	__asm
	{
		jmp p[13 * 4];
	}
}

// _BinkCheckCursor@20
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkCheckCursor(int a1, int a2, int a3, int a4, int a5)
{
	__asm
	{
		jmp p[14 * 4];
	}
}

// _BinkClose@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkClose(int a1)
{
	__asm
	{
		jmp p[15 * 4];
	}
}

// _BinkCloseTrack@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkCloseTrack(int a1)
{
	__asm
	{
		jmp p[16 * 4];
	}
}

// _BinkControlBackgroundIO@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkControlBackgroundIO(int a1, int a2)
{
	__asm
	{
		jmp p[17 * 4];
	}
}

// _BinkControlPlatformFeatures@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkControlPlatformFeatures(int a1, int a2)
{
	__asm
	{
		jmp p[18 * 4];
	}
}

// _BinkCopyToBuffer@28
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkCopyToBuffer(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
	__asm
	{
		jmp p[19 * 4];
	}
}

// _BinkCopyToBufferRect@44
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkCopyToBufferRect(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
	__asm
	{
		jmp p[20 * 4];
	}
}

// _BinkDDSurfaceType@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkDDSurfaceType(int a1)
{
	__asm
	{
		jmp p[21 * 4];
	}
}

// _BinkDX8SurfaceType@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkDX8SurfaceType(int a1)
{
	__asm
	{
		jmp p[22 * 4];
	}
}

// _BinkDX9SurfaceType@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkDX9SurfaceType(int a1)
{
	__asm
	{
		jmp p[23 * 4];
	}
}

// _BinkDoFrame@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkDoFrame(int a1)
{
	__asm
	{
		jmp p[24 * 4];
	}
}

// _BinkDoFrameAsync@12
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkDoFrameAsync(int a1, int a2, int a3)
{
	__asm
	{
		jmp p[66 * 4];
	}
}

// _BinkDoFrameAsyncWait@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkDoFrameAsyncWait(int a1, int a2)
{
	__asm
	{
		jmp p[67 * 4];
	}
}

// _BinkDoFramePlane@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkDoFramePlane(int a1, int a2)
{
	__asm
	{
		jmp p[68 * 4];
	}
}


// _BinkGetError@0
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGetError()
{
	__asm
	{
		jmp p[25 * 4];
	}
}

// _BinkGetFrameBuffersInfo@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGetFrameBuffersInfo(int a1, int a2)
{
	__asm
	{
		jmp p[26 * 4];
	}
}

// _BinkGetKeyFrame@12
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGetKeyFrame(int a1, int a2, int a3)
{
	__asm
	{
		jmp p[27 * 4];
	}
}

// _BinkGetPalette@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGetPalette(int a1)
{
	__asm
	{
		jmp p[28 * 4];
	}
}

// _BinkGetRealtime@12
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGetRealtime(int a1, int a2, int a3)
{
	__asm
	{
		jmp p[29 * 4];
	}
}

// _BinkGetRects@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGetRects(int a1, int a2)
{
	__asm
	{
		jmp p[30 * 4];
	}
}

// _BinkGetSummary@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGetSummary(int a1, int a2)
{
	__asm
	{
		jmp p[31 * 4];
	}
}

// _BinkGetTrackData@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGetTrackData(int a1, int a2)
{
	__asm
	{
		jmp p[32 * 4];
	}
}

// _BinkGetTrackID@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGetTrackID(int a1, int a2)
{
	__asm
	{
		jmp p[33 * 4];
	}
}

// _BinkGetTrackMaxSize@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGetTrackMaxSize(int a1, int a2)
{
	__asm
	{
		jmp p[34 * 4];
	}
}

// _BinkGetTrackType@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGetTrackType(int a1, int a2)
{
	__asm
	{
		jmp p[35 * 4];
	}
}

// _BinkGoto@12
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGoto(int a1, int a2, int a3)
{
	__asm
	{
		jmp p[36 * 4];
	}
}

// _BinkIsSoftwareCursor@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkIsSoftwareCursor(int a1, int a2)
{
	__asm
	{
		jmp p[37 * 4];
	}
}

// _BinkLogoAddress@0
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkLogoAddress()
{
	__asm
	{
		jmp p[38 * 4];
	}
}

// _BinkNextFrame@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkNextFrame(int a1)
{
	__asm
	{
		jmp p[39 * 4];
	}
}

// _BinkOpen@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkOpen(int a1, int a2)
{
	__asm
	{
		jmp p[40 * 4];
	}
}

// _BinkOpenDirectSound@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkOpenDirectSound(int a1)
{
	__asm
	{
		jmp p[41 * 4];
	}
}

// _BinkOpenMiles@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkOpenMiles(int a1)
{
	__asm
	{
		jmp p[42 * 4];
	}
}

// _BinkOpenTrack@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkOpenTrack(int a1, int a2)
{
	__asm
	{
		jmp p[43 * 4];
	}
}

// _BinkOpenWaveOut@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkOpenWaveOut(int a1)
{
	__asm
	{
		jmp p[44 * 4];
	}
}

// _BinkPause@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkPause(int a1, int a2)
{
	__asm
	{
		jmp p[45 * 4];
	}
}

// _BinkRegisterFrameBuffers@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkRegisterFrameBuffers(int a1, int a2)
{
	__asm
	{
		jmp p[46 * 4];
	}
}

// _BinkRequestStopAsyncThread@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkRequestStopAsyncThread(int a1)
{
	__asm
	{
		jmp p[69 * 4];
	}
}

// _BinkRestoreCursor@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkRestoreCursor(int a1)
{
	__asm
	{
		jmp p[47 * 4];
	}
}

// _BinkService@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkService(int a1)
{
	__asm
	{
		jmp p[48 * 4];
	}
}

// _BinkSetError@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetError(int a1)
{
	__asm
	{
		jmp p[49 * 4];
	}
}

// _BinkSetFrameRate@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetFrameRate(int a1, int a2)
{
	__asm
	{
		jmp p[50 * 4];
	}
}

// _BinkSetIO@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetIO(int a1)
{
	__asm
	{
		jmp p[51 * 4];
	}
}

// _BinkSetIOSize@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetIOSize(int a1)
{
	__asm
	{
		jmp p[52 * 4];
	}
}

// _BinkSetMemory@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetMemory(int a1, int a2)
{
	__asm
	{
		jmp p[53 * 4];
	}
}

// _BinkSetMixBinVolumes@20
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetMixBinVolumes(int a1, int a2, int a3, int a4, int a5)
{
	__asm
	{
		jmp p[54 * 4];
	}
}

// _BinkSetMixBins@16
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetMixBins(int a1, int a2, int a3, int a4)
{
	__asm
	{
		jmp p[55 * 4];
	}
}

// _BinkSetPan@12
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetPan(int a1, int a2, int a3)
{
	__asm
	{
		jmp p[56 * 4];
	}
}

// _BinkSetSimulate@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetSimulate(int a1)
{
	__asm
	{
		jmp p[57 * 4];
	}
}

// _BinkSetSoundOnOff@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetSoundOnOff(int a1, int a2)
{
	__asm
	{
		jmp p[58 * 4];
	}
}

// _BinkSetSoundSystem@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetSoundSystem(int a1, int a2)
{
	__asm
	{
		jmp p[59 * 4];
	}
}

// _BinkSetSoundTrack@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetSoundTrack(int a1, int a2)
{
	__asm
	{
		jmp p[60 * 4];
	}
}

// _BinkSetVideoOnOff@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetVideoOnOff(int a1, int a2)
{
	__asm
	{
		jmp p[61 * 4];
	}
}

// _BinkSetVolume@12
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetVolume(int a1, int a2, int a3)
{
	__asm
	{
		jmp p[62 * 4];
	}
}

// _BinkShouldSkip@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkShouldSkip(int a1)
{
	__asm
	{
		jmp p[63 * 4];
	}
}

// _BinkStartAsyncThread@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkStartAsyncThread(int a1, int a2)
{
	__asm
	{
		jmp p[70 * 4];
	}
}

// _BinkWait@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkWait(int a1)
{
	__asm
	{
		jmp p[64 * 4];
	}
}

// _BinkWaitStopAsyncThread@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkWaitStopAsyncThread(int a1)
{
	__asm
	{
		jmp p[71 * 4];
	}
}


// _RADTimerRead@0
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall RADTimerRead()
{
	__asm
	{
		jmp p[65 * 4];
	}
}