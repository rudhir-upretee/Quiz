
#include <stdio.h>
#include <string.h>

typedef struct longSub_t
{
    int start;
    int len;
    
}longSub_t;

void insert2(int a[], int size, int item, int* lastIdx)
{
    if(*lastIdx >= (size-1))
    {
        return;
    }
    
    int idx = *lastIdx;
    while((idx >= 0) && (item < a[idx]))
    {
        a[idx+1] = a[idx];
        idx--;
    }
    
    a[idx+1] = item;
    (*lastIdx) += 1;
}

void delete2(int a[], int size, int item, int* lastIdx)
{
    if(*lastIdx == -1)
    {
        return;
    }
    
    int itemIdx;
    for(int i = 0; i <= *lastIdx; i++)
    {
        if(item == a[i])
        {
            itemIdx = i;
        }
    }
    
    while((itemIdx + 1) <= (*lastIdx))
    {
        a[itemIdx] = a[itemIdx+1];
        itemIdx++;
    }
    
    (*lastIdx) -= 1;
}

void findLongestSub(int* arr, int size, longSub_t* out_p)
{
    int maxlen = 0, currlen = 0;
    
    if(size == 0)
    {
        out_p->start = 0;
        out_p->len = 0;
        
        return;
    }
    
    maxlen = 0;
    currlen = 1;
    out_p->start = 0;
    out_p->len = 1;
    //Search backwards
    for(int i = size-1; i-1 >= 0; i--)
    {
        if(arr[i-1] == (arr[i]-1))
        {
            currlen++;
        }
        else
        {
            if(currlen > maxlen)
            {
                out_p->start = i;
                out_p->len = currlen;
                maxlen = currlen;
                currlen = 1;
            }
        }
        
    }
    
    return;
}

void findLongestSub2(int a[], int size, longSub_t* ret)
{
    int start, currLen, lastVal;
    ret->start = 0;
    ret->len = 0;
    
    if(size == 0)
    {
        ret->start = -1;
        ret->len = -1;
        return;
    }
    
    lastVal = a[0];
    currLen = 1;
    start = 0;
    
    for(int i = 1; i < size; i++)
    {
        if(a[i] == (lastVal+1))
        {
            currLen++;
        }
        else
        {
            if(currLen > ret->len)
            {
                ret->len = currLen;
                ret->start = start;
            }
            
            currLen = 1;
            start = i;
        }
        
        lastVal = a[i];
    }
    
    if(currLen > ret->len)
    {
        ret->len = currLen;
        ret->start = start;
    }
            
    return;
}

int main()
{
    {
        int arr[10] = {2, 3, 4, 6, 7, 8, 9, 11, 12, 13};
        
        longSub_t ret;
        findLongestSub2(&arr[0], sizeof(arr)/sizeof(arr[0]), &ret);
        printf("start=%d len=%d\n", ret.start, ret.len);
        
        for(int i = 0; i < ret.len; i++)
        {
            printf("%d ", arr[ret.start+i]);
        }
        printf("\n");
    }
    
    {
        int arr[1] = {2};
        
        longSub_t ret;
        findLongestSub(&arr[0], sizeof(arr)/sizeof(arr[0]), &ret);
        printf("start=%d len=%d\n", ret.start, ret.len);
        
        for(int i = 0; i < ret.len; i++)
        {
            printf("%d ", arr[ret.start+i]);
        }
        printf("\n");
    }
    
    {
        int arr[5];
        memset(arr, 0, 5*sizeof(int));
        int last = -1;
        
        insert2(&arr[0], sizeof(arr)/sizeof(arr[0]), 4, &last);
        insert2(&arr[0], sizeof(arr)/sizeof(arr[0]), 2, &last);
        insert2(&arr[0], sizeof(arr)/sizeof(arr[0]), 3, &last);
        insert2(&arr[0], sizeof(arr)/sizeof(arr[0]), 1, &last);
        insert2(&arr[0], sizeof(arr)/sizeof(arr[0]), 5, &last);
        insert2(&arr[0], sizeof(arr)/sizeof(arr[0]), 7, &last);
        
        for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        
        delete2(&arr[0], sizeof(arr)/sizeof(arr[0]), 3, &last);
        delete2(&arr[0], sizeof(arr)/sizeof(arr[0]), 5, &last);
        for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    
    return 0;
}