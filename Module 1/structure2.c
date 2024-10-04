#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    struct Cars
    {
        char name[20];
        int price;

    }c1,c2;

    struct Cars *ptr;

    ptr = &c1;

    ptr->price = 34234;

    strcpy(c1.name,"Ayna");
    
    c2.price = 52343;
    // struct Cars car1 = {.name = "ayan" , .price = 43534};

    printf("%s\t %d",c1.name,c1.price);
    
}