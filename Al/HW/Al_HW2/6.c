// sort-all.c

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 100000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int sorted[MAX_SIZE];   // Additional memoryh for merge sort

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;  			// 왼쪽 배열의 시작 인덱스
	j = mid + 1;  		// 오른쪽 배열의 시작 인덱스
	k = left;			// sorted array의 시작 인덱스

	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	if (i > mid)	// 오른쪽 배열에 아직 남아 있는 원소가 있는 경우
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];

	else if (j > right)  // 왼쪽 배열에 아직 원소가 남아 있는 경우
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];

	for (l = left; l <= right; l++)
		list[l] = sorted[l];

	return;
}

void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}


int partition(int arr[], int low, int high) {
	int i, pivot, pIndex, temp;

	pivot = arr[high];       // pivot 값을 배열 마지막 값으로 할당
	pIndex = low;

	for (i = low; i < high; i++) {    // pivot 보다 작은 값들을 scan
		if (arr[i] < pivot) {
			SWAP(arr[i], arr[pIndex], temp);
			pIndex++;
		}
	}
	SWAP(arr[pIndex], arr[high], temp);   // pivot 값을 pIndex 위치로 이동

	return pIndex;
}

void quicksort(int arr[], int low, int high) {
	int pIndex;

	if (low < high) {
		pIndex = partition(arr, low, high);
		quicksort(arr, low, pIndex - 1);
		quicksort(arr, pIndex + 1, high);
	}
	return;
}

void bubble_sort(int list[], int n)
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++)
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], temp);
	}

	return;
}

void selection_sort(int list[], int n)
{
	int i, j, minIndex, temp;
	for (i = 0; i < n - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[minIndex])
				minIndex = j;
		SWAP(list[i], list[minIndex], temp);
	}
	return;
}

void insertion_sort(int list[], int n)
{
	int i, j, key;

	for (i = 1; i < n; i++) {
		key = list[i];
		j = i - 1;
		while (j >= 0 && list[j] > key) {
			list[j + 1] = list[j];   //move the key value into right position
			j = j - 1;
		}
		list[j + 1] = key;
	}

	return;
}

// Shellsort 
void inc_insertion_sort(int list[], int first, int last, int gap)
{
	int i, j, key;

	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}

	return;
}

void shell_sort(int list[], int n)   // n: size
{
	int i, gap;

	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0)
			gap++;
		for (i = 0; i < gap; i++)
			inc_insertion_sort(list, i, n - 1, gap);
	}
	return;
}

int main(void)
{
	int i;
	srand(time(NULL));

	clock_t start1, start2, start3, start4, start5, start6;
	clock_t end1, end2, end3, end4, end5, end6;

	float result1, result2, result3, result4, result5, result6;


	for (i = 0; i < MAX_SIZE; i++)
		list[i] = rand() % 1;

	// Bubble sort
	start1 = clock();
	printf("Bubble sort:: \n");
	for (i = 0; i < MAX_SIZE; i++)
		printf("%d ", list[i]);
	printf("\n");
	bubble_sort(list, MAX_SIZE);
	for (i = 0; i < MAX_SIZE; i++)
		printf("%d ", list[i]);
	printf("\n\n");
	end1 = clock();
	result1 = (float)(end1 - start1) / CLOCKS_PER_SEC;

	for (i = 0; i < MAX_SIZE; i++)
		list[i] = rand() % 1;

	// Selection sort
	start2 = clock();
	printf("Selection sort:: \n");
	for (i = 0; i < MAX_SIZE; i++)
		printf("%d ", list[i]);
	printf("\n");
	selection_sort(list, MAX_SIZE);
	for (i = 0; i < MAX_SIZE; i++)
		printf("%d ", list[i]);
	printf("\n\n");
	end2 = clock();
	result2 = (float)(end2 - start2) / CLOCKS_PER_SEC;

	for (i = 0; i < MAX_SIZE; i++)
		list[i] = rand() % 1;

	printf("\n");
	// Insertion sort
	start3 = clock();
	printf("Insertion sort:: \n");
	for (i = 0; i < MAX_SIZE; i++)
		printf("%d ", list[i]);
	insertion_sort(list, MAX_SIZE);
	for (i = 0; i < MAX_SIZE; i++)
		printf("%d ", list[i]);
	printf("\n\n");
	end3 = clock();
	result3 = (float)(end3 - start3) / CLOCKS_PER_SEC;

	for (i = 0; i < MAX_SIZE; i++)
		list[i] = rand() % 1;
	
	// Shell sort
	start4 = clock();
	printf("Shell sort:: \n");
	for (i = 0; i < MAX_SIZE; i++)
		printf("%d ", list[i]);
	printf("\n");
	shell_sort(list, MAX_SIZE);
	for (i = 0; i < MAX_SIZE; i++)
		printf("%d ", list[i]);
	printf("\n\n");
	end4 = clock();
	result4 = (float)(end4 - start4) / CLOCKS_PER_SEC;

	for (i = 0; i < MAX_SIZE; i++)
		list[i] = rand() % 1;

	// Merge sort
	start5 = clock();
	printf("Merge sort:: \n");
	for (i = 0; i < MAX_SIZE; i++)
		printf("%d ", list[i]);
	printf("\n");
	merge_sort(list, 0, MAX_SIZE - 1);
	for (i = 0; i < MAX_SIZE; i++)
		printf("%d ", list[i]);
	printf("\n\n");
	end5 = clock();
	result5 = (float)(end5 - start5) / CLOCKS_PER_SEC;

	for (i = 0; i < MAX_SIZE; i++)
		list[i] = rand() % 1;

	// Quicksort
	start6 = clock();
	printf("Quicksort:: \n");
	for (i = 0; i < MAX_SIZE; i++)
		printf("%d ", list[i]);
	printf("\n");
	quicksort(list, 0, MAX_SIZE - 1);
	for (i = 0; i < MAX_SIZE; i++)
		printf("%d ", list[i]);
	printf("\n\n");
	end6 = clock();
	result6 = (float)(end6 - start6) / CLOCKS_PER_SEC;

	printf("\n");
	printf("%.3f, %.3f, %.3f, %.3f, %.3f, %.3f", result1, result2, result3, result4, result5, result6);
	
	return 0;
}