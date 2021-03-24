#include<iostream>
using namespace std;

class HappyNumber{
	public:
		static bool findHappy(int num){
			int slow = num;
			int fast = num;
			do{
				slow = findSquareNum(slow);
				fast = findSquareNum(findSquareNum(fast));
			} while (slow != fast);
			return slow == 1;
		}

	private:
		static int findSquareNum(int num){
			int sum = 0;
			int digit;
			while(num > 0){
				digit = num % 10;
				sum += digit * digit;
				num /= 10;
			}
			return sum;
		}	
};

int main(int argc, char* argv[]){
	cout << HappyNumber::findHappy(12) << endl;
	cout << HappyNumber::findHappy(23) << endl;
	return 0;
}