#include<iostream>
#include<string>
#include<ctime>
#include<random>
#include<cstdlib>
#include<windows.h>
using namespace std;

void wait(unsigned long time) {
    clock_t s = clock();
    while((float)(clock() - s) / ((float)CLOCKS_PER_SEC / 1000) < (float)time);
}

void out_slow(ostream& out, string s, unsigned long delay) {
    for (size_t i = 0; i < s.length(); ++i) {
        out << s[i];
        wait(delay);
    }
}

void new_process(LPTSTR exepath) {
    STARTUPINFO si = { sizeof(STARTUPINFO) };
    PROCESS_INFORMATION pi = {};
    if (!CreateProcess(nullptr, exepath, nullptr, nullptr, false, 0, nullptr, nullptr, &si, &pi)) {
        fprintf(stderr, "process error");
    }
}

int main(int argc, char** argv) {
    string s;
    random_device rd;
    minstd_rand mr(rd());
    uniform_int_distribution<> dist(1200, 1700);
    out_slow(cout, "Enter Passward :\n", 20);
    cin >> s;
    out_slow(cout, "Cheking Passward...\n", 120);
    wait((unsigned long)dist(mr));
    if (s == "12345678") {
        out_slow(cout, "Passward is Accepted.\n\n", 80);
        wait(200);
        out_slow(cout, "Building Main Game.....\n\n", 80);
        wait(2000);
        LPTSTR proc = TEXT("calc.exe");
        new_process(proc);
    } else {
        out_slow(cout, "Passward is Incorrect.\n", 40);
    }
    return 0;
}