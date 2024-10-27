#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int str[100] , pat[100] , rep[100] , ans[100];
void read()
{
    gets(str);
    gets(pat);
    gets(rep);
}
void pattern()
{
    int i,j,m,k,c;
    int f = 0;
    i=j=m=c = 0;
    while (str[c] != '\0')
    {
        if (str[m] == pat[i])
        {
            i++;m++;
            if (pat[i] == '\0')
            {
                printf("Pat founf at pos %d",c);
                for (k = 0; rep[k] != '\0' ; k++,j++)
                {
                    ans[j] = rep[k];
                }
                f = 1;
                i = 0;
                c = m;
            }
        }
        else
        {
            ans[j++] = str[c++];
            i = 0;
            m = c;
        }
    }
    ans[j] = '\0';
    if (f == 0)
    {
        printf("Patt not foud : ");
    }else
    {
        printf("pattern found at : %s",ans);
    }
}
void main()
{
    read();
    pattern();
    // getch();
}
