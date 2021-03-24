// Given an array of intervals representing ‘N’ appointments, find out if a person can attend all the appointments.

// Example 1:

// Appointments: [[1,4], [2,5], [7,9]]
// Output: false
// Explanation: Since [1,4] and [2,5] overlap, a person cannot attend both of these appointments.

// Example 2:

// Appointments: [[6,7], [2,4], [8,12]]
// Output: true
// Explanation: None of the appointments overlap, therefore a person can attend all of them.

// Example 3:

// Appointments: [[4,5], [2,3], [3,6]]
// Output: false
// Explanation: Since [4,5] and [3,6] overlap, a person cannot attend both of these appointments.
 

using namespace std;

#include<iostream>
#include<algorithm>
#include<vector>

class Interval{
	public:
		int start;
		int end;

		Interval(int start, int end){
			this->start = start;
			this->end = end;
		}
};

class ConflictingAppointments{
	public:
		static bool canAttendAllAppointments(vector<Interval> &intervals){
			sort(intervals.begin(), intervals.end(), [](const Interval &x, const Interval &y) { return x.start < y.start; });

			for (int i = 0; i < intervals.size() - 1; i++){
				if(intervals[i].start <= intervals[i+1].start && intervals[i].end >intervals[i+1].start){
					return false;
				}
			}
				return true;
		}
};

int main(){
		vector<Interval> intervals = {{1, 4}, {2, 5}, {7, 9}};  
		bool result = ConflictingAppointments::canAttendAllAppointments(intervals);  
		cout << "Can attend all appointments: "  <<result << endl;   
		intervals = {{6, 7}, {2, 4}, {8, 12}};  
		result = ConflictingAppointments::canAttendAllAppointments(intervals);  
		cout << "Can attend all appointments: " << result << endl;   
		intervals = {{4, 5}, {2, 3}, {3, 6}};  
		result = ConflictingAppointments::canAttendAllAppointments(intervals);  
		cout << "Can attend all appointments: " << result << endl;
		return 0;
}