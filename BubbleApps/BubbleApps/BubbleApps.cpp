// BubbleApps.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <string>

using namespace System::Runtime::InteropServices;

int main()
{

	STARTUPINFO si;
	PROCESS_INFORMATION pi;


	HWND taskBar = FindWindow(
		L"Shell_TrayWnd", 
		0
	);

	BOOL hide = ShowWindow(taskBar, SW_HIDE);

	//Fails - possibly not allowed to destroy shell traywind
	BOOL destruction =  DestroyWindow(
		taskBar
	);

	short releaseESC = 1;

	while (1) {
		if ((GetKeyState(VK_ESCAPE) & 0x8000)) {
			if (releaseESC != GetKeyState(VK_ESCAPE)) {
				// if previous toggle state was 0 and current state is 1 OR previous toggle state was 1 and current state is 0
				releaseESC = (GetKeyState(VK_ESCAPE) << 7) >> 7;
				
				//fails, probably need to restart task in taskscheduler
				CreateProcess(L"C:\\Windows\\explorer.exe",
					NULL,
					NULL,
					NULL,
					FALSE,
					0,
					NULL,
					NULL,
					&si,
					&pi
				);
				return 0;
			}
		}
	}
    return 0;
}

