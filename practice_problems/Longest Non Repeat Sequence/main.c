/* Longest Non Repeating char sequence */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b)  ((a>b)?a:b)


unsigned int letMap = 0;
void letterMapInit()
{
	letMap = 0;
}
 
void letterMapAdd(unsigned char c)
{
	letMap |= (1 << (c - 'a'));
}

void letterMapRemove(unsigned char c)
{
	letMap &= ~(1 << (c - 'a'));
}

int letterFound(unsigned char c)
{
	return (letMap & (1 << (c - 'a'))) != 0;
}

int longestNonRepeat(char s[])
{
	int left, right;
	int currLen, maxLen;

	maxLen = 0;

	if((s[0] == 0) || (s[1] == 0))
	{
		return 1;
	}

	currLen = 1;
	letterMapInit();
	letterMapAdd(s[0]);
	for(left = 0, right = 0; ; )
	{
		//Add non repeats
		while((s[right]!=0) && (!letterFound(s[right])))
		{
			letterMapAdd(s[right]);
			currLen++;
			right++;
		}

		//Update maxLen
		maxLen = MAX(maxLen, currLen);
		
		if(s[right] == 0)
		{
		    return maxLen;
		}

		//Find repeat char from left
		while(s[left] != s[right])
		{
			letterMapRemove(s[left]);
			currLen--;
			left++;
		}
		
		//Remove repeat char
		while((left < right) && (s[left] == s[right]))
		{
			letterMapRemove(s[left]);
			currLen--;
			left++;
		}

	}

	return maxLen;
}


int main()
{
    
    char f[] = "abcdabc";
	printf("str=%s longest=%d\n", f, longestNonRepeat(f));
	
    char g[] = "abcdcefg";
	printf("str=%s longest=%d\n", g, longestNonRepeat(g));
	
    char h[] = "abcdcccefg";
	printf("str=%s longest=%d\n", h, longestNonRepeat(h));
	
    char i[] = "aaaaaa";
	printf("str=%s longest=%d\n", i, longestNonRepeat(i));

    return 0;
}
