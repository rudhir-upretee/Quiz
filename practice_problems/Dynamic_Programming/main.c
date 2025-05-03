/******************************************************************************
 Dynamic Programming 
 
 Technique of dividing a problem into smaller problems and solving
 those smaller problems to reach solution to bigger problems.
 
 1) Top Down (using recursion)
    Start with main problem and keep dividing into small sub-problems. Result
    will bubble up due to recursion. Use memoization for faster computation.
    
2) Bottom Up (using iteration)
    Start with smallest problem and keep adding results and increasing the 
    problem size till you reach main problem.
 

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
 Longest Increasing Subsequence (LIS) using recursion is complicated
*******************************************************************************/


/******************************************************************************
 Longest Increasing Subsequence (LIS) using iteration
*******************************************************************************/

#define MAX(a, b) ((a>b)?a:b)
int findMax(int a[], int size)
{
    int maxItem = 0;
    
    for(int i = 0; i < size; i++)
    {
        maxItem = MAX(a[i], maxItem);
    }
    return maxItem;
}

int LIS_with_iteration(int a[], int size)
{
    if(size <= 1)
    {
        return 1;
    }
    
    //create answer 
    int *ans = malloc(size * sizeof(int));
    for(int i = 0; i < size; i++) {ans[i] = 1;}
    
    int start, end;
    for(end = 1; end < size; end++)
    {
        for(start = 0; start < end; start++)
        {
            if(a[start] <= a[end])
            {
                ans[end] = MAX(ans[end], (1+ans[start]));
                
            }
        }
    }
    
    int maxItem = findMax(ans, size);
    printf("LIS size = %d\n", maxItem);
}

int main()
{
    int a[] = {2,4,1,5,6,2,8};
    LIS_with_iteration(a, 7);

    int b[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    LIS_with_iteration(b, 9);
    return 0;
}