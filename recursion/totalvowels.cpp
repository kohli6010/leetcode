#include <iostream>
#include <string>
using namespace std; 

int totalVowels(string text, int len, int index) 
{ 
  //Write your code here
  // Don't make changes to the input parameters

  if(len == 0){
	  return 0;
  }

  if(index == len){
	  return 0;
  }

  if(text[index] == 'a' || text[index] == 'e' || text[index] == 'i' || text[index] == 'o' || text[index] == 'u' || text[index] == 'A' || text[index] == 'E' || text[index] == 'I' || text[index] == 'O' || text[index] == 'U'){
	  return 1 + totalVowels(text, len, index + 1);
  }

  return totalVowels(text, len, index + 1);
} 


//Function to test your code
// Don't edit any code below this

int test(string text, int len, int index){

  return totalVowels(text,len,index);

}

int main(){
	string str = "";
	int len = str.length();
	int result = test(str, len, 0);
	cout << result;
	return 0;
}