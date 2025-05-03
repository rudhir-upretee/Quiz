
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

//Write program to return Subarry sum give start index and size of sub array
//It can be easily done with a loop. But try to write optimum logic to reduce
//runtime if there are 'n' sub arrays
int globalArr[MAX_SIZE] = {10, 20, 5, 15, 10, 45, 30, 25, 55, 5};
int *outArr;

int getSubArrSum(int subArrStart, int subArrSize)
{
    if(subArrSize <= 1)
    {
        return globalArr[subArrStart];
    }
    
    //Display subarray
    printf("Input array : ");
    for(int i = subArrStart; i < (subArrStart+subArrSize); i++)
    {
        printf("%d ", globalArr[i]);
    }
    printf("\n");
    
    //Logic to get subarry sum
    int outSum;
    if(subArrStart > 0)
    {
        outSum = (outArr[subArrStart + (subArrSize-1)]) - (outArr[subArrStart-1]);
    }
    else
    {
        outSum = (outArr[subArrStart + (subArrSize-1)]);
    }
    
    return outSum;
}

void getSubArrPrefixSum(void)
{
    int sum = 0;
    outArr = malloc(MAX_SIZE * sizeof(int));
    for(int i = 0; i < MAX_SIZE; i++)
    {
        sum += globalArr[i];
        outArr[i] = sum;
        printf("%d ", outArr[i]);
    }
    printf("\n");
}

int main()
{
    //Pre-process
    getSubArrPrefixSum();
    
    printf("subArrSum = %d\n", getSubArrSum(0, 10));
    printf("subArrSum = %d\n", getSubArrSum(0, 2));
    printf("subArrSum = %d\n", getSubArrSum(2, 2));
    printf("subArrSum = %d\n", getSubArrSum(8, 2));

    return 0;
}
