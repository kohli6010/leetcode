#include<iostream>
using namespace std;

void replaceNegativeValues(int arr[], int size, int currentIndex){
	if(size == 0){
		return;
	}

	else if(size == currentIndex){
		return;
	}

	else if(arr[currentIndex] < 0){
		arr[currentIndex] = 0;
	}

	return replaceNegativeValues(arr, size, currentIndex + 1);
}

int main(){
	int arr[] = {-3, -4, 5, 3, -6};
	int size = sizeof(arr) / sizeof(arr[0]);
	replaceNegativeValues(arr, size, 0);
	for (int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	return 0;
}