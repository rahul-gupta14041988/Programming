#include<stdio.h>

#define MAXITEMSIZE 7

int findMaxValIndex(int *arr)
{
    int i=0;
    float max=0;
    int index=0;
    for(i=0;i<MAXITEMSIZE;i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
            index=i;
        }
    }

    return index;
}

float KnapsackSolution(int *weightA,int *profitA,int totalCapacity)
{
    int i=0,processedWeight=0;
    float profit = 0;
    float PvsWratio[MAXITEMSIZE]={0};
    int selectedIndex[MAXITEMSIZE]={0};
    printf("\nprofitVsWeight Ratio array:");
    for(i=0;i<MAXITEMSIZE;i++)
    {
        PvsWratio[i] = (float)profitA[i]/weightA[i];
        printf("%.2f ",PvsWratio[i]);
    }
    //also while(1) can also be used for infinite loop
    for(;;)
    {
        int index = findMaxValIndex(PvsWratio);
        printf("\nThe max value is at index %d is :%.2f",index,PvsWratio[index]);
        if(totalCapacity > weightA[index])
        {
            profit = profit + PvsWratio[index] * weightA[index];
            totalCapacity-=weightA[index];
            PvsWratio[index] = 0.0;
        }
        else
        {
            profit = profit + PvsWratio[index]*totalCapacity;
            break;
        }

    }


    return profit;
}

int main()
{
    //These weights are static can be taken as user input as number of items and their weights\
      corresponding profits

    int weight[MAXITEMSIZE]={2,3,5,7,1,4,1};
    int profit[MAXITEMSIZE]={10,5,15,7,6,18,3};
    int totalWeight=15; //Weight of Bag to be filled to find the max profit

    printf("\nThe Profit for BagSize 15 is:%.2f",KnapsackSolution(weight,profit,totalWeight));
    printf("\nThe Profit for BagSize 14 is:%.2f",KnapsackSolution(weight,profit,14));
    printf("\nThe Profit for BagSize 5 is:%.2f",KnapsackSolution(weight,profit,5));
    printf("\nThe Profit for BagSize 10 is:%.2f",KnapsackSolution(weight,profit,10));

    return 0;
}
