// Palindrome LinkedList (medium) #
// Given the head of a Singly LinkedList, write a method to check if the LinkedList is a palindrome or not.

// Your algorithm should use constant space and the input LinkedList should be in the original form once the algorithm is finished. The algorithm should have O(N)O(N) time complexity where ‘N’ is the number of nodes in the LinkedList.

// Example 1:

// Input: 2 -> 4 -> 6 -> 4 -> 2 -> null
// Output: true
// Example 2:

// Input: 2 -> 4 -> 6 -> 4 -> 2 -> 2 -> null
// Output: false

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

class PalindromicLinkedList{
	public:
		static bool isPalindrome(ListNode *head){
			if(head == nullptr || head->next == nullptr){
				return true;
			}

			ListNode *slow = head;
			ListNode *fast = head;

			while(fast != nullptr && fast->next != nullptr){
				slow = slow->next;
				fast = fast->next->next;
			}

			ListNode *headSecondList = reverse(slow);
			ListNode *copyHeadSecondList = headSecondList;

			while(head != nullptr && headSecondList != nullptr){
				if(head->value != headSecondList->value){
					break;
				}

				head = head->next;
				headSecondList = headSecondList->next;
			}

			reverse(copyHeadSecondList);
			if(head == nullptr || headSecondList == nullptr){
				return true;
			}

			return false;
		}

		static ListNode *reverse(ListNode *head){
			ListNode *p1 = nullptr;
			while(head !=nullptr){
				ListNode *p3 = head->next;
				head->next = p1;
				p1 = head;
				head = p3;
			}

			return p1;
		}

		static void traverse(ListNode *head){
			ListNode *temp = head;
			while(temp != nullptr){
				cout << temp->value << " ";
				temp = temp->next;
			}

			cout << endl;
		}
};

int main(){
	ListNode *head = new ListNode(2);
	head->next = new ListNode(4);
	head->next->next = new ListNode(6);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(2);

	cout << std::boolalpha <<PalindromicLinkedList::isPalindrome(head);
	
	head->next->next->next->next->next = new ListNode(2);

	cout << std::boolalpha << PalindromicLinkedList::isPalindrome(head);

	return 0;
}