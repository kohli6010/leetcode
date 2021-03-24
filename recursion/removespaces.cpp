#include<iostream>
#include<string>
using namespace std;

void removeSpaces(string &, int, int);

int main(){
	string str = "Good Morning to ya ladies";
	removeSpaces(str, 0, str.length());
	cout << str;
	return 0;
}

void removeSpaces(string &str, int index, int len){
	if(len == 0)
		return;
	
	if(index == len)
		return;

	if(str[index] == ' '){
		int i = index;
		while(i < len){
			str[i] = str[i+1];
			i++;
		}

		removeSpaces(str, index, len - 1);
	}

	removeSpaces(str, index + 1, len);
}