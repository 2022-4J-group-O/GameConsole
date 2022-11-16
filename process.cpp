#include<windows.h>
#include<stdio.h>
int main(int argc, char** argv) {
    LPTSTR command = TEXT("./Encoder.exe");
    STARTUPINFO si = { sizeof(STARTUPINFO) };
    PROCESS_INFORMATION pi = {};
    if(!CreateProcess(nullptr, command, nullptr, nullptr, false, 0, nullptr, nullptr, &si, &pi)) {
        fprintf(stderr, "error");
    }
}