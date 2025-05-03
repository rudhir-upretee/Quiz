/******************************************************************************


*******************************************************************************/
#include <stdio.h>

void findElementRange(int a[], int size, int elemInd)
{
    int elem = a[elemInd];
    int left, right;
    
    //Find left edge
    left = elemInd-1;
    while(left >= 0)
    {
        if(a[left] == elem)
        {
            left--;
        }
        else
        {
            break;
        }
    }
    left++;//adjust
    
    //Find right edge
    right = elemInd+1;
    while(right < size)
    {
        if(a[right] == elem)
        {
            right++;
        }
        else
        {
            break;
        }
    }
    right--;//adjust
    
    printf("Left=%d Right=%d\n", left, right);
}

void findElementWithRepeats(int a[], int size, int elem)
{
    int left, right, mid;
    
    left = 0;
    right = size-1;
    while(left <= right)
    {
        mid = (left + (right-left)/2);
        if(elem == a[mid])
        {
            findElementRange(a, size, mid);   
            return;
        }
        else if(elem < a[mid])
        {
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }
    
    return;
}

int main()
{
    int a[10] = {1,2,3,3,3,4,5,6,7,8};
    findElementWithRepeats(a, 10, 3);
    
    int b[10] = {1,1,1,2,3,4,5,6,7,8};
    findElementWithRepeats(b, 10, 3);
    
    int c[10] = {1,1,1,2,3,4,5,6,7,8};
    findElementWithRepeats(c, 10, 1);
    
    int d[10] = {1};
    findElementWithRepeats(d, 1, 1);
    
    int e[10] = {1,2,3,3,3,4,5,6,6,6};
    findElementWithRepeats(e, 10, 6);
    
    return 0;
}