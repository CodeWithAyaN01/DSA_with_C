#include<stdio.h>
#include<stdlib.h>

void EnterDetails(char CarVerson[20] , int CarAge , int CarPrice);
int main()
{
    typedef struct 
    {
        char CarVerson[50];
        int CarAge;
        int CarPrice;
    }car;

    car skoda,aulto; // user defined function;
    
    car *pointer; // defining 
    
    pointer = &skoda; // structure variable

    strcpy(pointer->CarVerson,"new");
    printf("Car is %s",pointer->CarVerson);
    printf("\n\n");
    EnterDetails(aulto.CarVerson , aulto.CarAge , aulto.CarPrice);

}
void EnterDetails(char CarVerson[20] , int CarAge , int CarPrice)
{
    printf("enter the car name: ");scanf("%s",CarVerson);
    printf("\nEnter the car Age : ");scanf("%d",&CarAge);
    printf("\nEnter the car price: ");scanf("%d",&CarPrice);
    system("cls");
    printf("Car is %s its age is %d and its price is %d",CarVerson,CarAge,CarPrice);
}