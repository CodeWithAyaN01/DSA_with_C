#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
void StringCon(char str1[20] , char str2[20])
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    // int j = 0;
    for (int i = 0 ; i<=len2 ; i++)
    {
        str1[len1] = str2[i];
        len1++;
    }
    str1[len1] = '\0';
    printf("%s",str1);
}
void StringComp(char str1[20] , char str2[20])
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int Result;
    if (len1 != len2)
    {
        printf("Different: ");
        return;
    }
    else
    {
        int i=0;
        while(str1[i] != '\0')
        {
            if (str1[i] == str2[i])
            {
                Result = 1;
            }
            else
            {
                Result = 0;
                return;
            }
            i++;
        }
    }
    if (Result)
    {
        printf("The String Are same");
    }else {
        printf("String are not same");
    }
}
int main()
{
    char s1[10] , s2[10];
    printf("Enter string 1: ");
    gets(s1);
    printf("Enter string 2: ");
    gets(s2);
    // StringCon(s1,s2);
    StringComp(s1,s2);
}