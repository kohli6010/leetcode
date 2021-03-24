#include<iostream>
using namespace std;

int noOfOccurences(int arr[], int size, int num){
	if(size < 0){
		return 0;
	}

	int found = 0;
	if(arr[size] == num){
		++found;
	}

	return (found + noOfOccurences(arr, size - 1, num));
}

int main(){
	int arr[] = {4, 5, 2, 1, 2, 2};
	int size = sizeof(arr) / sizeof(arr[0]);
	int result = noOfOccurences(arr, size, 2);
	cout << result;
	return 0;
}