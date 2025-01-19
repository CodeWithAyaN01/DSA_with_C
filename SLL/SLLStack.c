#include<stdio.h>
#define MAX 5
typedef struct{
    int key;
}Element;

typedef struct
{
    Element data;
    stackPointer link;
}stack;

typedef struct stack *stackPointer;

stackPointer top[MAX];