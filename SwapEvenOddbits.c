#include<stdio.h>

int main()
{
    int number = 23;

    printf("Number before swap is:%d\n",number);

    int y= (((number & 0xAAAAAAAA)>>1) | ((number & 0x55555555)<<1));

    printf("\nNumber After swap is:%d",y);

    return 0;
}
