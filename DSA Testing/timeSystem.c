#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include <stdio.h>

void Time(char* FormattedDate) {
    time_t currentTime;
    struct tm *local_Time; // defined structure in <time.h>
    // char FormattedDate[30];

    // Get the current system time
    time(&currentTime);

    //local time representation
    local_Time = localtime(&currentTime);

    // printf("Current date: %02d-%02d-%04d\n", 
    //        local_Time->tm_mday, 
    //        local_Time->tm_mon + 1,  // tm_mon is months since January (0-11), so add 1
    //        local_Time->tm_year + 1900); // tm_year is years since 1900, so add 1900

    sprintf(FormattedDate,"%02d/%02d/%04d", local_Time->tm_mday , local_Time->tm_mon+1,local_Time->tm_year+1900);

    // printf("The Date is %s\n ",FormattedDate);
}
int main()
{
    char Ptime[20];

    Time(Ptime);

    printf("Current time is : %s\n ",Ptime);

}
