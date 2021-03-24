#include<iostream>
using namespace std;

void sortArray(int arr[], int startIndex, int size){
	int min = startIndex;
	for (int i = startIndex + 1; i < size; i++){
		if(arr[min] > arr[i]){
			min = i;
		}
	}

	int swap = arr[startIndex];
	arr[startIndex] = arr[min];
	arr[min] = swap;

	if(startIndex + 1 < size){
		return sortArray(arr, startIndex + 1, size);
	}
}

int main(){
	int arr[] = {5, 3, 4, 10, 12};
	int size = sizeof(arr) / sizeof(arr[0]);
	sortArray(arr, 0, size);
	for (int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}

	return 0;
}