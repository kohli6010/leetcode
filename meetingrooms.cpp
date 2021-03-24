using namespace std; 
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector> 
class Meeting { 
	public:  
		int start = 0;  
		int end = 0;   
		Meeting(int start, int end) {
			this->start = start;    this->end = end;  
		}
}; 

class MinimumMeetingRooms { 
	public:  
		static int findMinimumMeetingRooms(vector<Meeting> &meetings) {
			if(meetings.empty()){
				return 0;
			}

			sort()
			return -1;  
		}
}; 

int main(int argc, char *argv[]) {
	vector<Meeting> input = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};  
	int result = MinimumMeetingRooms::findMinimumMeetingRooms(input);  
	cout << "Minimum meeting rooms required: " << result << endl;   
	input = {{1, 4}, {2, 5}, {7, 9}};  
	result = MinimumMeetingRooms::findMinimumMeetingRooms(input);  
	cout << "Minimum meeting rooms required: " << result << endl;   
	input = {{6, 7}, {2, 4}, {8, 12}};  
	result = MinimumMeetingRooms::findMinimumMeetingRooms(input);  
	cout << "Minimum meeting rooms required: " << result << endl;   
	input = {{1, 4}, {2, 3}, {3, 6}};  
	result = MinimumMeetingRooms::findMinimumMeetingRooms(input);  
	cout << "Minimum meeting rooms required: " << result << endl;   
	input = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};  
	result = MinimumMeetingRooms::findMinimumMeetingRooms(input);  
	cout << "Minimum meeting rooms required: " << result << endl;

	return 0;
}