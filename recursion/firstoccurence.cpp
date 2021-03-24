#include<iostream>
using namespace std;

int firstOccurence(int arr[], int size, int x, int currentIndex){
	if(size == 0){
		return -1;
	}

	if(currentIndex == size){
		return -1;
	}

	if(arr[currentIndex] == x){
		return currentIndex;
	}

	return firstOccurence(arr, size, x, currentIndex+1);
}

int main(){
	int arr[] = {32, 43, 11, 2, 44};
	int size = sizeof(arr) / sizeof(arr[0]);
	int result = firstOccurence(arr, 5, 2, 0);
	cout << result;
	return 0;
}