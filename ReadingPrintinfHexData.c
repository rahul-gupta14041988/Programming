#include<stdio.h>
//In C programming language, a Hexadecimal number is represented by preceding with "0x" or "0X",\
 thus the value in Hexadecimal can be written as "0x64" (which is equivalent to 100 in Decimal).\
 There is no special type of data type to store Hexadecimal values in C programming, \
 Hexadecimal number is an integer value and you can store it in the integral type of data types \
 (char, short or int).\
 "%x" prints the value in Hexadecimal format with alphabets in lowercase (a-f).\
 "%X" prints the value in Hexadecimal format with alphabets in uppercase (A-F).

int main()
{
 unsigned char a=0x64;
 int b=0xFAFA;

 int arr[] = {0x64,0xFAFA,0xABCD,0xBBA};
 int i = 0;

 printf("Decimal a:%d Hexadecimal a:[%x]\n",a,a);
 printf("Decimal b:%d Hexadecimal b:[%x]\n",b,b);

 printf("Decimal a:%d Hexadecimal a:[%X]\n",a,a);
 printf("Decimal b:%d Hexadecimal b:[%X]\n\n",b,b);

 for(i=0;i<4;i++)
 {
     printf("Loop Decimal:%d Hexadecimal:[%x]\n",arr[i],arr[i]);
     printf("Loop Decimal:%d Hexadecimal:[%X]\n",arr[i],arr[i]);
 }

 return 0;
}
