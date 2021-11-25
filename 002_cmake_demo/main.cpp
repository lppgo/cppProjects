#include <stdio.h>
#include "hello.h"

int main() {
    int a = 0;
    int b = 0;
    int c = 0;

    printf("please input two numbers:");
    scanf("%d", &a);
    scanf("%d", &b);

    c = Calculate_sum(a, b);
    printf("the sum is:%d\n", c);
    return 0;
}