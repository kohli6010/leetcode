#include<iostream>
using namespace std;

bool checkPrime(int, int);

int main(){
	int num = 13;
	bool result = checkPrime(12, num/2);
	cout << std::boolalpha << result;
	return 0;
}

bool checkPrime(int num, int i){
	if(num<2){
		return 0;
	}

	if(i == 1){
		return 1;
	}

	if(num % i == 0){
		return 0;
	}else{	
		checkPrime(num, i - 1);
	}

}