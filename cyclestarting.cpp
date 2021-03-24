#include<iostream>
using namespace std;

class ListNode{
	public:
		int value;
		ListNode *next;

		ListNode(int value){
			this->value = value;
			this->next = nullptr;
		}
};

class LinkedListCycleStart{
	public:
		static ListNode *findCycleStart(ListNode *head){
			ListNode *fast = head;
			ListNode *slow = head;
			int cycleLength = 0;
			while(fast != nullptr && fast->next != nullptr){
				fast = fast->next->next;
				slow = slow->next;
				if(slow == fast){
					cycleLength = calculateLength(slow);
					break;
				}
			}

			return findStart(head, cycleLength);
		}

	private:
		static int calculateLength(ListNode *head){
			ListNode *current = head;
			int cycleLength = 0;
			do{
				current = current->next;
				cycleLength++;
			}while(current != head);

			return cycleLength;
		}

		static ListNode *findStart(ListNode *head, int cycleLength){
			ListNode *firstPtr = head;
			ListNode *secondPtr = head;
			while(cycleLength > 0){
				firstPtr = firstPtr->next;
				cycleLength--;
			}

			while(firstPtr != secondPtr){
				firstPtr = firstPtr->next;
				secondPtr = secondPtr->next;
			}

			return secondPtr;
		}
};

int main(){
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);
	head->next->next->next->next->next->next = head->next->next->next;

	cout << LinkedListCycleStart::findCycleStart(head)->value;
	return 0;
}