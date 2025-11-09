#define UNICODE
#define _UNICODE
#include <windows.h>

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "advapi32.lib")

void __stdcall mainCRTStartup(void) {
    // WinPE”»’è
    HKEY hKey;
    LONG r = RegOpenKeyExW(
        HKEY_LOCAL_MACHINE,
        L"SYSTEM\\CurrentControlSet\\Control\\MiniNT",
        0,
        KEY_READ,
        &hKey
    );

    if (r != ERROR_SUCCESS) {
        ExitProcess(0);    // ’ÊíWindows‚È‚ç‘¦I—¹
    }
    RegCloseKey(hKey);

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    const wchar_t msg[] = L"Hello, Windows PE!\r\n";
    DWORD written;
    WriteConsoleW(h, msg, sizeof(msg) / sizeof(msg[0]) - 1, &written, NULL);

    ExitProcess(0);
}
