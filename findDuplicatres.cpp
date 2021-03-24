#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
	public:
		int findDuplicate(vector<int> &nums){
			sort(nums.begin(), nums.end());
			for (int i = 0; i <nums.size()-1; i++){
				if(nums[i] == nums[i+1]){
					return nums[i];
				}
			}

			return 0;
		}
};

int main(){
	vector<int> nums = {1,3,4,2,2};
	Solution s;
	cout << s.findDuplicate(nums);
	return 0;
}