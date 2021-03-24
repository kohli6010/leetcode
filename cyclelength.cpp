#include<iostream>
using namespace std;

class ListNode{
	public:
		int value = 0;
		ListNode *next;

		ListNode(int value){
			this->value = value;
			this->next = nullptr;
		}
};

class LinkedListCycle{
	public:
		static int hasCycle(ListNode *head){
			ListNode *slow = head;
			ListNode *fast = head;
			while(fast != nullptr && fast->next != nullptr){
				fast = fast->next->next;
				slow = slow->next;
				if(slow == fast){
					return calculateLength(slow);
				}
			}
			return 0;
		}

	private:
		static int calculateLength(ListNode *slow){
			ListNode *current = slow;
			int cycleLength = 0;
			do{
				current = current->next;
				cycleLength++;
			} while (current != slow);
			return cycleLength;
		}
};

int main(){
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);
	head->next->next->next->next->next->next = head->next->next;

	cout << LinkedListCycle::hasCycle(head);
}