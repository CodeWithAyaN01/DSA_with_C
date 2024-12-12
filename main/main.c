#include <stdio.h>
// Function declaration
int addNumbers(int a, int b);
int subNumbers(int a, int b)
{
    return a-b;
}
int main() {
    int num1 = 5, num2 = 10, sum;
    int sub;

    // Function call
    sum = addNumbers(num1, num2);
    sub = subNumbers(num1, num2);

    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    printf("sub is : %d",sub);

    return 0;
}

// Function definition
int addNumbers(int a, int b) {
    return a + b;
}
