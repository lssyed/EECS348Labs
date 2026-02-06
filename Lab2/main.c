#include <stdio.h>
#include "isEven.h"
#include "isOdd.h" //Added this
int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    isEven(num);
    isOdd(num);
    return 0;
}
