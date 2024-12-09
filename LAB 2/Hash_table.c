/*Given a File of N employee records with a set K of Keys (4-digit) which uniquely
determine the records in file F. Assume that file F is maintained in memory by a
Hash Table (HT) of m memory locations with L as the set of memory addresses
(2-digit) of locations in HT. Let the keys in K and addresses in L are Integers.
Develop a Program in C that uses Hash function H: K ?L as H(K)=K mod m
(remainder method), and implement hashing technique to map a given key K to
the address space L. Resolve the collision (if any) using linear probing.*/
#include<stdio.h>
#include<stdlib.h>
int L[100],max=10;
// float A = 0.1352;
void display()
{
    int i;
    printf("\n Hash table contents are ");
    printf("\n Index\tdata\n");
    for(i=0;i<max;i++)
        printf("\n%d\t%d\n",i,L[i]);
}
void linear_probe(int addr,int num)
{
    int i;
    if(L[addr]==-1)
        L[addr]=num;
    else
    {
        printf("\n Collision detected");

        i=(addr+1)%max;
        while(i!=addr)
        {
            if(L[i]==-1)
            {
                L[i]=num;
                printf("\n Collision resolved through linear probe");
                return;
            }
            else
            i=(i+1)%max;
        }
        printf("\n Hash table is full");
        display();
    }
}
int main()
{
    int i,num,addr,input;
    for(i=0;i<max;i++)
        L[i]=-1;
    do
    {
        printf("\n Enter the number");
        scanf("%d",&num);
        addr=num%max;
        //key = max * (num*A - (int)(num*A));
        printf("%d, %d",num, addr);
        linear_probe(addr,num);
        display();
        
        printf("\n Enter 1 to continue");
        scanf("%d",&input);
    }while(input==1);
    return 0;
}