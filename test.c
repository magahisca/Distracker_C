#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>


int main()
{
char WindowTitle[256];
char LastWindowTitle[256];
time_t now = time(NULL); //initialize time

//get time

//get local time
struct tm *curr_Time = localtime(&now);
int sec = curr_Time->tm_sec;
int min = curr_Time->tm_min;
int hour = curr_Time->tm_hour;
int mday = curr_Time->tm_mday;
int mon = curr_Time->tm_mon;
int year = curr_Time->tm_year;
printf("%d", sec);
printf("%d", min);
printf("%d", hour);
printf("%d", mday);
printf("%d", mon);
printf("%d", year);
printf("\n");


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