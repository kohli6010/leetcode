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

class Reverse{
	public:
		static ListNode *reverseList(ListNode *head){
			ListNode *p1 = nullptr;
			ListNode *p2 = head;
			while(p2 != nullptr){
				ListNode *p3 = p2->next;
				p2->next = p1;
				p1 = p2;
				p2 = p3;
			}

			return p1;
		}

		static void traverse(ListNode *head){
			while(head != nullptr){
				cout << head->value << " ";
				head = head->next;
			}
		}
};

int main(){
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	ListNode *newHead = Reverse::reverseList(head);
	Reverse::traverse(newHead);
	return 0;
}