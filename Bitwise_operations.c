/* Bitwise operations
    1.  Clear all bits from LSB to ith bit
        Logic: To clear all bits from LSB to i-th bit, we have to AND x with mask having LSB to
        i-th bit 0. To obtain such mask, first left shift 1 i times. Now if we minus 1 from that,
        all the bits from 0 to i-1 become 1 and remaining bits become 0. Now we can simply take
        complement of mask to get all first i bits to 0 and remaining to 1.
    2.  Clearing all bits from MSB to i-th bit
        Logic: To clear all bits from MSB to i-th bit, we have to AND x with mask having MSB to i-th bit 0.
        To obtain such mask, first left shift 1 i times. Now if we minus 1 from that, all the bits from 0
        to i-1 become 1 and remaining bits become 0.
    3.  How to set a particular bit in C?
        Setting a Bits
        Bitwise OR operator (|) use to set a bit of integral data type.”OR” of two bits is always one if any
        one of them is one.
        An algorithm to set the bits
        Number  | =  (1<< nth Position)
    4.  How to clear a particular bit in C?
        Bitwise AND operator (&) use to clear a bit of integral data type. “AND” of two bits is always zero
        if any one of them is zero.
        An algorithm to clear the bits
        Number  &=  ~ (1<< nth Position)
        To clear the nth bit, first, you need to invert the string of bits then AND it with the number.
    5.  How to check if a particular bit is set in C?
        To check the nth bit, shift the ‘1’ nth position toward the left and then “AND” it with the number.
        An algorithm to check the bits
        Bit = Number & (1 << nth)
    6.  How to toggle a particular bit in C?
        Bitwise XOR (^) operator use to toggle the bit of an integral data type.
        To toggle the nth bit shift the ‘1’ nth position toward the left and “XOR” it.
        An algorithm to toggle the bits
        Number  ^=  (1<< nth Position)

 */
#include<stdio.h>

const int mask = 32;

void clearNbitfromLSB(int *number,int N)
{
    *number = *number & ~((1<<N+1) - 1);
}
void clearNbitsfromMSB(int *number,int N)
{
    *number = *number & ((1<<N)-1);
}

char *toLowerCase(char *c)
{
    int i=0;

    for(i=0;c[i]!='\0';i++)
    {
        c[i] = c[i] | mask;
    }
    return c;
}

char *toUppercase(char *c)
{
    int i=0;
    for(i=0;c[i]!='\0';i++)
    {
        c[i] = c[i] & ~mask;
    }
    return c;
}

int is_power_of_2(int x)
{
	// Check if the number has only one set bit
	if ((x & (x - 1)) != 0)
		return 0;
	return 1;
}

unsigned int countSetBits(unsigned int n)
{
    unsigned int count = 0;

    while(n)
    {
        count+=n&1;
        n>>=1;
    }

    return count;
}

int main()
{

    int number=29;
    printf("Number before masking: Decimal:%d Hexadecimal:%x\n",number,number);
    clearNbitfromLSB(&number,3);
    printf("Number After masking: Decimal:%d Hexadecimal:%x\n",number,number);

    number = 215;
    printf("Number before masking: Decimal:%d Hexadecimal:%x\n",number,number);
    clearNbitsfromMSB(&number,4);
    printf("Number After masking: Decimal:%d Hexadecimal:%x\n",number,number);


    char LowerString[] = "ABCDEFghijkLMN";
    char UpperString[] = "opqrSTUVWxyz";

    printf("Before change LowerString:%s\n",LowerString);
    printf("Changed to Uppercase: UpperCase:%s\n",toUppercase(LowerString));

    printf("Before change UpperString:%s\n",UpperString);
    printf("Changed to LowerCase: LowerCase:%s\n",toLowerCase(UpperString));

    int pow2 = 4;
    int npow2 = 10;

    printf("is power of 2 pow2:%d\n",is_power_of_2(pow2));
    printf("is power of 2 npow2:%d\n",is_power_of_2(npow2));

    printf("Bits Set in number 16 is:%d\n",countSetBits(16));
    printf("Bits Set in number 17 is:%d\n",countSetBits(17));
    printf("Bits Set in number 19 is:%d\n",countSetBits(19));

    return 0;
}
