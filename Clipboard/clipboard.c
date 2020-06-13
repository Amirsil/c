#include <windows.h>
#include <winuser.h>
#include <stdio.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
	int ok = 1;
	HANDLE clipboard;
	OpenClipboard(NULL);
	HANDLE prev = GetClipboardData(CF_TEXT);
	printf("%s\n", prev);
	CloseClipboard();

	while (1)
	{
		ok = 1;
		if (!OpenClipboard(NULL)) 
			ok = 0;
		if (ok)
		{
			clipboard = GetClipboardData(CF_TEXT);
			if (strcmp( ( char * )prev, ( char * )clipboard ) ) printf("%s\n", clipboard);
			prev = clipboard;
			CloseClipboard();
		}
		Sleep(10);
	}
	
}