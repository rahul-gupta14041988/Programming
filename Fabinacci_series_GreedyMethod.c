#include<stdio.h>

#define MAXFINDSIZE 20

unsigned memory[MAXFINDSIZE]={0};

unsigned int fabseries_element(unsigned int pos)
{
    memory[0]=0;
    memory[1]=1;

    if(pos <=1)
    {
        return pos;
    }
    else
    {
        for(int i=2;i<=pos;i++)
        {
            memory[i]=memory[i-2] + memory[i-1];
        }
    }

    return memory[pos];
}

int main()
{
    int position=0;
    while(position <= MAXFINDSIZE)
    {
        printf("\nEnter the position value to find element (greater than 0):");
        scanf("%d",&position);
        if(position < 0)
        {
            printf("Please enter value greater than 0\n");
        }
        else
        {
            printf("The element at Position %d is: %d\n",position,fabseries_element((unsigned int)position));
            for(int i=0; i<MAXFINDSIZE; i++)
            {
                printf(" %d",memory[i]);
            }
        }

    }

    printf("\nThe entered position is the max limit for the program to find");

    return 0;
}
