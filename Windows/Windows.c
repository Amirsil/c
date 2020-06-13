#include <windows.h>
#include <stdio.h>
#include <winuser.h>

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
	LPTSTR buf = (LPTSTR)lParam;
	GetWindowTextA(hwnd, buf, 256);
	printf("%s\n", buf);
	return TRUE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
	LPTSTR buf;
    EnumWindows(&EnumWindowsProc, (LPARAM)buf);
}

