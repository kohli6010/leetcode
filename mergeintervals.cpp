#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Interval{
	public:
		int start = 0;
		int end = 0;

		Interval(int start, int end){
			this->start = start;
			this->end = end;
		}
};

class MergerIntervals{
	public:
		static vector<Interval> merge(vector<Interval> &intervals){
			if(intervals.size() < 2){
				return intervals;
			}

			sort(intervals.begin(), intervals.end(), [](const Interval &x, const Interval &y) { return x.start <= y.start; });

			vector<Interval> mergedIntervals;
			auto it = intervals.begin();

			Interval interval = *it++;
			int start = interval.start;
			int end = interval.end;

			while(it != intervals.end()){
				interval = *it++;
				if(interval.start <= end){
					end = max(interval.end, end);
				}else{
					mergedIntervals.push_back({start, end});
					start = interval.start;
					end = interval.end;
				}
			}

			mergedIntervals.push_back({start, end});
			return mergedIntervals;
		}
};

int main(){
	vector<Interval> vec = {{1, 3}, {2, 5}, {7, 9}};
	vector<Interval> res = MergerIntervals::merge(vec);

	for (auto it = res.begin(); it != res.end(); it++){
		cout << "[" << it->start << ", " << it->end << "] ";
	}
		return 0;
}