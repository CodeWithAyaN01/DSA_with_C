// #include<stdio.h>
// #include<stdlib.h>

// void EnterDetails(char CarVerson[20] , int CarAge , int CarPrice);
// int main()
// {
//     typedef struct 
//     {
//         char CarVerson[50];
//         int CarAge;
//         int CarPrice;
//     }car;

//     car skoda,aulto; // user defined function;
    
//     car *pointer; // defining 
    
//     pointer = &skoda; // structure variable

//     strcpy(pointer->CarVerson,"new");
//     printf("Car is %s",pointer->CarVerson);
//     printf("\n\n");
//     EnterDetails(aulto.CarVerson , aulto.CarAge , aulto.CarPrice);

// }
// void EnterDetails(char CarVerson[20] , int CarAge , int CarPrice)
// {
//     printf("enter the car name: ");scanf("%s",CarVerson);
//     printf("\nEnter the car Age : ");scanf("%d",&CarAge);
//     printf("\nEnter the car price: ");scanf("%d",&CarPrice);
//     system("cls");
//     printf("Car is %s its age is %d and its price is %d",CarVerson,CarAge,CarPrice);
// }


#include <stdio.h>

// Define the Address structure
struct Address {
    char city[50];
    int pin;
};

// Define the Student structure with an Address as a nested structure
struct Student {
    char name[50];
    int roll;
    struct Address address;  // Nested structure
};

int main() {
    // Declare a Student structure variable
    struct Student s1;

    // Input student details
    printf("Enter name: ");
    scanf("%s", s1.name); // Accessing name directly
    printf("Enter roll number: ");
    scanf("%d", &s1.roll); // Accessing roll directly

    // Input address details
    printf("Enter city: ");
    scanf("%s", s1.address.city);  // Accessing the nested structure's city
    printf("Enter pin code: ");
    scanf("%d", &s1.address.pin);  // Accessing the nested structure's pin

    // Display student details
    printf("\nStudent Details:\n");
    printf("Name: %s\n", s1.name);
    printf("Roll Number: %d\n", s1.roll);
    printf("City: %s\n", s1.address.city);  // Accessing the city from nested structure
    printf("Pin Code: %d\n", s1.address.pin);  // Accessing the pin from nested structure

    return 0;
}
