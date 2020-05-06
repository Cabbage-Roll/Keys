#define WINVER 0x0500
#include <windows.h>

int main()
{
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    ip.ki.wVk = VK_LEFT;
    short j=0x4A;
    while(1){
        if(GetAsyncKeyState(j)){
        ip.ki.dwFlags = 0;
        SendInput(1, &ip, sizeof(INPUT));
        while(GetAsyncKeyState(j))
        Sleep(10);
        ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
        }
    }
    return 0;
}
