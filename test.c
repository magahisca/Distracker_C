#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
//initialize time
void getStartTime(time_t *startTime){
     *startTime = time(NULL);
}
void getEndTime(time_t *endTime){
    *endTime = time(NULL);
}


int main()
{
char WindowTitle[256];
char LastWindowTitle[256] = "";
time_t startTime, endTime;
getStartTime(&startTime);
//get readable time
char *readableTime = ctime(&startTime);
printf("%s", readableTime);
//get local time


struct tm *curr_Time = localtime(&startTime);
struct tm *startLocalTime = localtime(&startTime); 
int sec = curr_Time->tm_sec;
int min = curr_Time->tm_min;
int hour = curr_Time->tm_hour;
int mday = curr_Time->tm_mday;
int mon = curr_Time->tm_mon +1;
int year = curr_Time->tm_year + 1900;
printf("Program start: %02d/%02d/%d %02d:%02d:%02d\n", mon, mday, year, hour, min, sec);

while (1){
    HWND hwnd = GetForegroundWindow();
    if (hwnd){
        GetWindowText(hwnd, WindowTitle, sizeof(WindowTitle));
        
        if (strcmp(WindowTitle, LastWindowTitle) != 0){
            getEndTime(&endTime);
            char *endTimeReadable = ctime(&endTime);
            struct tm *endLocalTime = localtime(&endTime);
            if (strlen(LastWindowTitle)>0){
                double duration = difftime(endTime, startTime);
                printf("You spent %.2f seconds on %s \n", duration, LastWindowTitle);
            }
            printf("End time for %s: %s",LastWindowTitle, endTimeReadable);

            printf("Active Window: %s\n", WindowTitle);
            
            strcpy(LastWindowTitle, WindowTitle);
            getStartTime(&startTime);    
            char *startTimeReadable = ctime(&startTime);
            struct tm *startLocalTime = localtime(&startTime);
            printf("%s", startTimeReadable);
        }
    }

Sleep(500); 
}


return 0;


}