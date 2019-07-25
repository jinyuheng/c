 #define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void print_table(int line)

{
	int i = 0;
	int j = 0;
	for(i=1; i<=line; i++)
	{
		for(j=1; j<=i; j++)

		{

			printf("%d*%d=%d ", i, j, i*j);

		}

		printf("\n");
	}
}

int main()
{
	int line = 0;
	scanf("%d", &line);
	print_table(line);
	return 0;
}




void Init(int arr[], int sz)

{
	int i = 0;
	for(i=0; i<sz; i++)
	{
		arr[i] = i;
	}
}

void Empty(int arr[], int sz)
{
	int i = 0;
	for(i=0; i<sz; i++)
	{
		arr[i] = 0;
	}
}

void Reverse(int arr[], int sz)
{
	int left = 0;
	int right = sz-1;
	 
	while(left<right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}

void Print(int arr[], int sz)
{
	int i = 0;
	for(i=0; i<sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() 
{
	int arr[10] = {0};
	int sz = sizeof(arr)/sizeof(arr[0]);
	Init(arr, sz);
	Print(arr, sz);
	Reverse(arr, sz);
	Print(arr, sz);

	return 0;

}



