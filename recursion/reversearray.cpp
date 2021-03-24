#include<iostream>
using namespace std;

void reverseArray(int arr[], int startIndex, int endIndex){
	if(endIndex == 0){
		return;
	}

	if(startIndex >= endIndex){
		return;
	}

	char ch = arr[startIndex];
	arr[startIndex] = arr[endIndex];
	arr[endIndex] = ch;

	return reverseArray(arr, startIndex + 1, endIndex - 1);
}

int main(){
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int size = sizeof(arr) / sizeof(arr[0]);
	reverseArray(arr, 0, size-1);
	for (int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
		return 0;
}	