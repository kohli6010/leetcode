#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
	public:
		vector<vector<int>> merge(vector<vector<int>>& intervals) {
			if(intervals.size() < 2){
				return intervals;
			}
			vector<vector<int>> mergedInrervals;
			sort(intervals.begin(), intervals.end(), [](const vector<int> &x, const vector<int> &y) {
				return x[0] <= y[0];
			}); // O(nlogn) time-complexity

			auto it = intervals.begin();
			vector<int> interval = *it++;
			int start = interval[0];
			int end = interval[1];

			while(it != intervals.end()){
				vector<int> interval = *it++;
				if(interval[0] <= end){
					end = max(interval[1], end);
				}else{
					mergedInrervals.push_back({start, end});
					start = interval[0];
					end = interval[1];
				}
			}

			mergedInrervals.push_back({start, end});
			return mergedInrervals;
		}
};

int main(){
	// vector<vector<int>> inp = 	
	// Solution s;
	// vector<vector<int>> out = s.merge(inp);
	// for (int i = 0; i < out.size(); i++){
	// 	cout << "{" << out[i][0] << ", " << out[i][1] << "}";
	// }
	// return 0;
}