#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
    #include <windows.h>

    void create_process() {
        STARTUPINFO si;
        PROCESS_INFORMATION pi;

        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);
        ZeroMemory(&pi, sizeof(pi));
        if (!CreateProcess(NULL, "program.exe", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
            exit(1);
        }


        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
#else
    #include <unistd.h>

    void create_process() {
        pid_t pid = fork();  // Create a new process

        if (pid < 0) {
            exit(1);
        } else if (pid == 0) {
            printf("Child process created with PID: %d\n", getpid());
            exit(0);
        } else {
        }
    }
#endif

int main() {
    while (1) {
        create_process();
    }

    return 0;
}
