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

class Solution{
	public:
		ListNode *oddEvenList(ListNode *head){
			if(head == NULL || head->next ==NULL || head->next->next == NULL){
				return head;
			}
			int i = 3;	
			ListNode *traverse = head->next->next;
			ListNode *oddListStart = head;
			ListNode *evenListStart = head->next;
			ListNode *evenListEnd = evenListStart;
			while (traverse != NULL){
				if(i % 2 == 0){
					evenListEnd->next = traverse;
					evenListEnd = evenListEnd->next;
				}else{
					oddListStart->next = traverse;
					oddListStart = oddListStart->next;
				}

				++i;
				traverse = traverse->next;
			}

			evenListEnd->next = NULL;
			oddListStart->next = evenListStart;
			return head;
		}
};

int main(){
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	Solution s;
	ListNode *newHead = s.oddEvenList(head);
	while(newHead){
		cout << newHead->value << "->";
		newHead = newHead->next;
	}

	return 0;
}