/******************************************************************************

//Write program to return number of Subarrys which equals sum 'K'

*******************************************************************************/
#include <iostream>
#include <unordered_map>

using namespace std;

#define MAX_SIZE 10

int globalArr[MAX_SIZE] = {10, 20, 5, 15, 10, 45, 30, 25, 55, 5};
int outArr[MAX_SIZE];
unordered_multimap<int, int> sumMap;

int getSubArrSum(int subArrStart, int subArrEnd)
{
    if((subArrStart < 0) || (subArrEnd >= MAX_SIZE))
    {
        return -1;
    }
    
    //Logic to get subarry sum
    int outSum;
    if(subArrStart > 0)
    {
        outSum = (outArr[subArrEnd]) - (outArr[subArrStart-1]);
    }
    else
    {
        outSum = (outArr[subArrEnd]);
    }
    
    return outSum;
}

void getSubArrPrefixSum(void)
{
    int sum = 0;
    
    for(int i = 0; i < MAX_SIZE; i++)
    {
        sum += globalArr[i];
        outArr[i] = sum;
        
        //Add to multimap with key = sum, value = endIndex
        sumMap.insert({sum, i});
        cout << outArr[i] << endl;
    }

}

//This is O(n) because inner for loop most of the time is zero
int findSubArrSumK(int K)
{
    int rangeSum;
    int totalSubArrCnt = 0;
    for(int i = 0; i < MAX_SIZE; i++)
    {
        rangeSum = outArr[i] + K;
        
        //Find rangeSum in prefix multimap
        //Idea is - at any index i, when you add K to prefix sum array,
        //you will get new prefix sum forwards. Search for the new prefix sum
        //in prefix hashmap whether it exists.
        auto rangeItr = sumMap.equal_range(rangeSum);
        cout << "RangeSum = " << rangeSum << " i = " << i << " K = " << K << endl;
        for (auto it = rangeItr.first; it != rangeItr.second; ++it) 
        {
            cout << it->first << ": " << it->second << std::endl;
            
            //Make sure the prefix sum is ahead of of current index i.
            //This check is useful if there are negative numbers
            if(it->second >= i)
            {
                totalSubArrCnt++;
            }
        }
        
    }
    
    return totalSubArrCnt;
}

int main()
{
    //Pre-process
    getSubArrPrefixSum();
    
    cout << "subArrSum = " << getSubArrSum(0, 9) << endl;
    cout << "subArrSum = " << getSubArrSum(0, 1) << endl;
    cout << "subArrSum = " << getSubArrSum(2, 2) << endl;
    cout << "subArrSum = " << getSubArrSum(8, 9) << endl << endl;
    
    int cnt = findSubArrSumK(30);
    cout << "Sub Array cnt = " << cnt << endl;

    return 0;
}