#include<stdio.h>
#define MAXFINDSIZE 20

unsigned int memory[MAXFINDSIZE] = {0};

unsigned int fabseries_element(unsigned int position)
{
    if(position < 2)
    {
        memory[position]=position;
        return position;
    }
    else if(memory[position] !=0)
    {
        return memory[position];
    }
    else
    {
        memory[position] = fabseries_element(position - 2) + fabseries_element(position - 1);
        return memory[position];
    }

}

int main()
{
  int pos = 0;
  while(pos <= MAXFINDSIZE)
  {
    printf("\nEnter the position value to find element (greater than 0):");
    scanf("%d",&pos);
    if(pos < 0)
    {
      printf("Please enter value greater than 0\n");
    }
    else
    {
        printf("The element at Position %d is: %d\n",pos,fabseries_element((unsigned int)pos));
        for(int i=0; i<MAXFINDSIZE; i++)
        {
            printf(" %d",memory[i]);
        }
    }
  }//End of while loop
 printf("\nThe entered position is the max limit for the program to find");
 return 0;
}
