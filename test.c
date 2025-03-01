#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>


int main()
{
char WindowTitle[256];
char LastWindowTitle[256];

while (1){
    HWND hwnd = GetForegroundWindow();
    if (hwnd){
        GetWindowText(hwnd, WindowTitle, sizeof(WindowTitle));

        if (strcmp(WindowTitle, LastWindowTitle) != 0){
            printf("Active Window: %s\n", WindowTitle);
            strcpy(LastWindowTitle, WindowTitle);

        }


    }



}


return 0;


}