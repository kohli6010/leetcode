// Leetcode-57 Insert Interval

// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

// You may assume that the intervals were initially sorted according to their start times.

 

// Example 1:

// Input: intervals = {1,3},{6,9}, newInterval = {2,5}
// Output: {1,5},{6,9}
// Example 2:

// Input: intervals = {1,2},{3,5},{6,7},{8,10},{12,16}, newInterval = {4,8}
// Output: {1,2},{3,10},{12,16}
// Explanation: Because the new interval {4,8} overlaps with {3,5},{6,7},{8,10}.
// Example 3:

// Input: intervals = {}, newInterval = {5,7}
// Output: {5,7}
// Example 4:

// Input: intervals = {1,5}, newInterval = {2,3}
// Output: {1,5}
// Example 5:

// Input: intervals = {1,5}, newInterval = {2,7}
// Output: {1,7}

#include<iostream>
#include<vector>
#include<limits>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		 if(intervals.empty()){
			 intervals.push_back(newInterval);
			 return intervals;
		 }

		 vector<vector<int>> mergedIntervals;
		 int i = 0;

		 while(i < intervals.size() && intervals[i][1] < newInterval[0]){
			 mergedIntervals.push_back(intervals[i++]);
		 }

		 while(i<intervals.size() && intervals[i][0] <= newInterval[1]){
			 newInterval[0] = min(newInterval[0], intervals[i][0]);
			 newInterval[1] = max(newInterval[1], intervals[i][1]);
			 i++;
		 }

		 mergedIntervals.push_back(newInterval);

		 while(i<intervals.size()){
			 mergedIntervals.push_back(intervals[i]);
			 i++;
		 }

		 return mergedIntervals;
		}
};

int main(){
	Solution s;
	vector<vector<int>> inp = {{1,2},{3,5},{6,7},{8,10},{12,16}};
	vector<int> vec = {4,8};
	vector<vector<int>> out = s.insert(inp, vec);
	for (int i = 0; i < out.size(); i++){
		cout << out[i][0] << " " << out[i][1] << " ";
	}

	return 0;
}