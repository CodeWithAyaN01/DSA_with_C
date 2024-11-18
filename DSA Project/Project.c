#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void Add_Patient();
void Discharge_Patient();
void Display_List();
void Time(char* FormattedDate);
struct Patient
{
    char P_Name[30];
    int Patient_ID;
    char Patient_Address[30];
    char Patient_Problem[30];
    char Patient_Date[20];
}p;
int main()
{
    Add_Patient();
}
void Add_Patient()
{
    char Date_of_Admit[20];
    printf("\nEnter Name of the Patient: ");gets(p.P_Name);
    printf("\n Enter the Patinet ID: ");gets(p.Patient_ID);
    printf("\n Enter the Patient Address: ");gets(p.Patient_Address);
    Time(p.Patient_Date);

}
void Time(char* FormattedDate)
{
    time_t currentTime;
    struct tm *local_Time; 
    time(&currentTime);
    //local time representation
    local_Time = localtime(&currentTime);
    sprintf(FormattedDate,"%02d/%02d/%04d", local_Time->tm_mday , local_Time->tm_mon+1,local_Time->tm_year+1900);;
}
void Display_List()
{
    
}


