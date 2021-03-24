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

class RearrangeList{
	public:
		static void rearrangeList(ListNode *head){
			if(head == nullptr || head -> next == nullptr){
				return;
			}

			ListNode *slow = head;
			ListNode *fast = head;

			while(fast != nullptr && fast->next	!= nullptr){
				slow = slow->next;
				fast = fast->next->next;
			}

			ListNode *headSecondHalf = reverse(slow);
			ListNode *headFirstHalf = head;
			
			while(headFirstHalf != nullptr && headSecondHalf != nullptr){
				ListNode *temp = headFirstHalf->next;
				headFirstHalf->next = headSecondHalf;
				headFirstHalf = temp;

				temp = headSecondHalf->next;
				headFirstHalf->next = headFirstHalf;
				headSecondHalf = temp;
			}

			if(headFirstHalf != nullptr){
				headFirstHalf->next = nullptr;
			}
		}

		static ListNode *reverse(ListNode *head){
			ListNode *p1 = nullptr;
			while(head != nullptr){
				ListNode *p3 = head->next;
				head->next = p1;
				p1 = head;
				head = p3;
			}

			return p1;
		}

		static void traverse(ListNode *head){
			while(head != nullptr){
				cout << head -> value << " ";
				head = head->next;
			}
		}
};

int main(){
	ListNode *head = new ListNode(2);
	head->next = new ListNode(4);
	head->next->next = new ListNode(6);
	head->next->next->next = new ListNode(8);
	head->next->next->next->next = new ListNode(10);
	head->next->next->next->next->next = new ListNode(12);

	RearrangeList::rearrangeList(head);
	RearrangeList::traverse(head);
	return 0;
}