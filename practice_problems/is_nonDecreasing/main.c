
#include <stdio.h>
int isNonDecreasing(int arr[], int size, int max_change_allow)
{
	int change_cnt = 0;

	if(size <= 2)
	{
		return 1;
	}

	//Check three items i-1, i, i+1 before making any decision
	for(int i = 0; (i+1) < size; i++)
	{
		if(arr[i] > arr[i+1])
		{
			if(change_cnt == max_change_allow)
			{
				return 0;
			}

			if((i == 0) || (arr[i-1] < arr[i+1]))
			{
				arr[i] = arr[i+1];
			}
			else
			{
				arr[i+1] = arr[i];
			}

			change_cnt++;
		}

	}

	return 1;

}

void printarr(int arr[], int size)
{
	for(int i = 0; i < size; i++)
		printf("%d ", arr[i]);

	printf("\n");
}

int main()
{

	int arr[5] = {1, 4, 7, 5, 6};
	printarr(&arr[0], 5);
	printf("arr  isNonDecreasing = %d\n", isNonDecreasing(&arr[0], 5, 1));


    int a[5] = {1, 4, 7, 3, 6};
    printarr(&a[0], 5);
    printf("arr  isNonDecreasing = %d\n", isNonDecreasing(&a[0], 5, 1));
    
    
    int b[5] = {1, 3, 7, 2, 8};
    printarr(&b[0], 5);
    printf("arr  isNonDecreasing = %d\n", isNonDecreasing(&b[0], 5, 1));
    
    
    int c[5] = {1, 3, 7, 5, 8};
    printarr(&c[0], 5);
    printf("arr  isNonDecreasing = %d\n", isNonDecreasing(&c[0], 5, 1));

	return 0;
}
