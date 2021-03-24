#include<iostream>
#include<string>
using namespace std;

void removeDuplicates(string &, int, int);

int main(){
	string str = "";
	removeDuplicates(str, 0, str.length());
	cout << str;
	return 0;
}

void removeDuplicates(string &str, int index, int len){
	if(len == 0)
		return;
	
	if(index == len)
		return;	

	if(str[index] == str[index+1]){
		int i = index;
		while(i<len){
			str[i] = str[i + 1];
			i++;
		}

		removeDuplicates(str, index, len-1);
	}

	removeDuplicates(str, index + 1, len);
}