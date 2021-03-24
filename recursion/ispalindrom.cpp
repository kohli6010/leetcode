#include <iostream>
#include <string>
using namespace std;

int isPalindrome(string text, int front, int back)
{  
    //Write your code here
    //Donot change the declaration of the function

	if(back == 0){
		return 0;
	}

	if(text[front] != text[back]){
		return 0;
	}

	if(front >= back){
		return 1;
	}

	return isPalindrome(text, front + 1, back - 1);
}

// Function to test your code
// Don't change any code below this
int test(string text) {
  
  int answer= isPalindrome(text,0,text.length()-1);
  if (answer){
	  cout<< "Yes" <<endl;
  }
  else{
	  cout<< "No" <<endl;
	}
  return answer;
}

int main(){
	string str = "OOPS";
	test(str);
	return 0;
}