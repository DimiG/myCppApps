/* ========================================================================
   File: moncontroller_x64
   Date: 14.07.2015
   Revision: 0.0.1
   Creator: DimiG
   ======================================================================== */

#include <stdlib.h> 
#include <stdio.h> 
#include <windows.h>

#include <iostream>
#include <string>

using namespace std;

static void show_usage(string name)
{
    // Help Message
    cerr << "\nUsage: " << name << " < OPTIONS >\n"
         << "\nOptions:\n"
         << "\t-h, --help\tShow this help message\n"
         << "\t-s, --sleep\tSleep the current monitor\n"
         << endl;
}


// Color attributes setup
void SetConsoleColour(WORD* Attributes, DWORD Color)
{
    CONSOLE_SCREEN_BUFFER_INFO Info;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &Info);
    *Attributes = Info.wAttributes;
    SetConsoleTextAttribute(hStdout, Color);
}

void ResetConsoleColour(WORD Attributes)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Attributes);
}

// Main Code is here
int main(int argc, char* argv[])
{
    WORD Attributes = 0;
    SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN );
    string arg;

// NOTE(DimiG): Preprocessor commands for DEBUG purposes (True or DEBUG mode means 1)
#if 0

    printf ("Executing the program in DEBUG mode...\n");
        
    for (int i = 1; i < argc; ++i) {
        printf ("Arguments are: %s\n", argv[i]);

    }

#endif
    
    if (argc < 2) {
        show_usage(argv[0]);

        printf ("\n");
        printf ("Monitor Controller 0.0.1 - Control the monitor power (64bit only)\n");
        printf ("\nCopyright (C) DimiG, 2015\n\n");

        ResetConsoleColour(Attributes);

        system("pause");
        return 1;
    } else {

        arg = argv[1];

    }

    if ((arg == "-h") || (arg == "--help")) {
        
        show_usage(argv[0]);
        system("pause");
        
    }

    if ((arg == "-s") || (arg == "--sleep")) {
        printf("Execute the sleep command...");
        // Low power monitor
        Sleep(500); // Eliminate user's interaction for 500 ms
        SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2);
    }  

    ResetConsoleColour(Attributes);
    // system("pause");
    
    return 0;
}
