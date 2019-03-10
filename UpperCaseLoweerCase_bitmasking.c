#include<stdio.h>
// Logic : For all upper case character the 3rd bit is set to 0, and for all lower case character 3rd bit is set to 1
// so & operation bit the bitmask 0b00100000 or 0x20 is 0 for uppercase and non zero for lower case.
//Usecase: using XOR we can convert upper case to lower and lower to uppercase character.

int main()
{
    char c = 'A';

    if((c & 0b00100000) == 0)
    {
        // character is upper case
        printf("Char %c is uppercase",c);
    }
    if((c & 0b001000000) == 0b00100000)
    {
        //character is lower case
        printf("Char %c is lowercase",c);
    }
    return 0;
}
