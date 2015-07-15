/* =========================================================================
   File: shareLauncher_x64
   Date: 15.07.2015
   Revision: 0.0.1
   Creator: DimiG
   Note: This code as example how to call Windows system command by C++ code
   ========================================================================= */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

using namespace std;

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
int main(void)
{
    WORD Attributes = 0;
    SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN );

    char shellcmd[BUFSIZ];

    /**
     * Build a buffer, and execute the commands within it
     */

    strcpy (shellcmd, "net use *");
    strcat (shellcmd, " \\\\computername@SSL@5006\\sharename\\foldername");

// NOTE(DimiG): Preprocessor commands for DEBUG purposes (True or DEBUG mode means 1)

#if 0
    printf ("Executing %s\n", shellcmd);
#endif

    printf ("\n");
    printf ("ShareLauncher 0.0.1 - Connect to Shared Resource (64bit only)\n");
    printf ("\nCopyright (C) DimiG, 2015\n\n");

    ResetConsoleColour(Attributes);

    system (shellcmd);

    system("pause");
    
    return 0;
}
