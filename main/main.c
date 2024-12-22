#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char *day;
    int date;
    char *activity;
}calendar;

calendar *create()
{
    calendar *week;
    week = (calendar*)calloc(7,sizeof(calendar));
    return week;
}

void read(calendar *week)
{
    char day[200],activity[33];
    printf("Enter week details (week_day,date,activity)\n\n");
    for (int i = 0 ; i<7 ; i++)
    {
        printf("For Day %d",i+1);
        scanf("%s%d%s",day,&week[i].date,activity);
        week[i].day = strdup(day);
        week[i].activity = strdup(activity);
    }
}

void display(calendar *week)
{
    printf("week Activity \nDay\nDate\nActivity");
    ;for (int i = 0 ; i< 7;i++)
    {
        printf("%s\t%d\t%s\t\n",week[i].day,week[i].date,week[i].activity);
    }
}
int main()
{
    int choice;
    calendar *week;
    while (1)
    {
        printf("Enter 1.Create \n 2.read \n 3.display \n4.exit");
        printf("Enter you choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: week = create();
                if(week != NULL)
                {
                    printf("created sucessfully");
                }
                break;
            
            case 2: read(week);
            break;

            case 3: display(week);
            break;
            case 4: return 0;
        }
    }
}