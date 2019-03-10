#include<stdio.h>
// Logic: if number is OR with the bitmask 0x30 or 0b00110000

int main(void)
{
    char number = 2;
    printf("Equivalent char of number:%d is Without-conversion-Character:%c",number,number);
    printf("Equivalent char of number:%d is Character:%c",number,(number | 0x30));
    return 0;
}
