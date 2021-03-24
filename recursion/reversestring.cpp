#include<iostream>
#include<string>
using namespace std;

void reverseString(string &, int);

int main(){
	string str = "Hello World";
	reverseString(str, 0);
	cout << str;
	return 0;
}

void reverseString(string &str, int index){
	int n = str.length();
	if(index == n/2){
		return;
	}

	char swap = str[index];
	str[index] = str[n-index-1];
	str[n - index - 1] = swap;

	reverseString(str, index + 1);
}