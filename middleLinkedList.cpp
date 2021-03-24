#include<iostream>
using namespace std;

class ListNode{
	public: 
		int value;
		ListNode *next;

		ListNode(int value){
			this->value = value;
			this->next = NULL;
		}
};

class FindMiddleNode{
	public:
		static ListNode *findMiddle(ListNode *head){
			ListNode *slow = head;
			ListNode *fast = head;
			while(fast != NULL && fast->next != NULL){
				slow = slow->next;
				fast = fast->next->next;
			}

			return slow;
		}
};

int main(){
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);

	ListNode *toFind = FindMiddleNode::findMiddle(head);
	cout << toFind->value;
}