#include<stdio.h>

//Masking is the process or operation to set bit on to off or off to on in a byte,nibble or word.[/box]\
Mask means to block.\
Masking is the process by which ,only required data is retained and the rest is masked (blocked)

//Masking is the act of applying a mask to a value. This is accomplished by doing:

//Bitwise ANDing in order to extract a subset of the bits in the value\
  Bitwise ORing in order to set a subset of the bits in the value\
  Bitwise XORing in order to toggle a subset of the bits in the value

  //void more_stuff(uint32_t value) {             // Example value: 0x01020304
  //  uint32_t byte1 = (value >> 24);           // 0x01020304 >> 24 is 0x01 so
                                              // no masking is necessary
  //  uint32_t byte2 = (value >> 16) & 0xff;    // 0x01020304 >> 16 is 0x0102 so
                                              // we must mask to get 0x02
   // uint32_t byte3 = (value >> 8)  & 0xff;    // 0x01020304 >> 8 is 0x010203 so
                                              // we must mask to get 0x03
   // uint32_t byte4 = value & 0xff;            // here we only mask, no shifting
                                              // is necessary
   // ...
//}

//Conclusion of Masking :\
Portion to be retained is ANDed with 1\
Portion to be Masked is ANDed with 0


/*below program to extract each byte from a 32 bit hexadecimal number*/

int main()
{
    unsigned int i=0xAABBCCDD;
    unsigned int byte_1 = i >> 24;
    printf("Byte_1:%x\n",byte_1);
    unsigned int byte_2 = (i >> 16) & 0xff;
    printf("Byte_2:%x\n",byte_2);
    unsigned int byte_3 = (i >> 8) & 0xff;
    printf("Byte_3:%x\n",byte_3);
    unsigned int byte_4 = i & 0xff;
    printf("Byte_4:%x\n",byte_4);
    return 0;
}
