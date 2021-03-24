#include<iostream>
#include<vector>
using namespace std;

class CircularArrayLoop{
	public:
		static bool loopExists(const vector<int> &arr){
			for (int i = 0; i < arr.size(); i++){
				bool isForward = arr[i] >= 0;
				int slow = i;
				int fast = i;
				do{
					slow = findNextIndex(arr, isForward, slow);
					fast = findNextIndex(arr, isForward, fast);
					if(fast != -1){
						fast = findNextIndex(arr, isForward, fast);
					}
				} while (slow!=-1 && fast!=-1&&slow!=fast);
			
				if(slow != -1 && slow == fast){
					return true;
				}
			}

			return false;
		}

		static int findNextIndex(const vector<int> &arr, bool isForward, int currentIndex){
			bool direction = arr[currentIndex] >= 0;
			if(isForward != direction){
				return -1;
			}

			int nextIndex = (currentIndex + arr[currentIndex] + arr.size()) % arr.size();

			if(nextIndex == currentIndex){
				return -1;
			}

			return nextIndex;
		}

};
int main(){
	cout << std::boolalpha << CircularArrayLoop::loopExists(vector<int> {1,2,-1,2,2}) << endl;
}