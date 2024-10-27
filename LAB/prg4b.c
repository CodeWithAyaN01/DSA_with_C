#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void towers(int, char, char, char);
int moves = 0;
int main()
{
    int num;
    printf("Enter the number of disks : ");
   scanf("%d", &num);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(num, 'A', 'C', 'B');
   getch();
   printf("no of moves are: ",moves);
    return 0;
}
void towers(int num, char source, char dest, char aux)
{
    if (num == 1)
    {
        printf("\n Move disk 1 from peg %c to peg %c", source,dest);moves++;
        return;
    }
    towers(num - 1, source, aux,dest);
    printf("\n Move disk %d from peg %c to peg %c", num, source, dest);moves++;
    towers(num - 1, aux, dest, source);
}