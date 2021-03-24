//Leetcode 61(medium) - Given the head of a linked list, rotate the list to the right by k places.
 
// Example-1
// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]

// Example-2
// Input: head = [0,1,2], k = 4
// Output: [2,0,1]

#include<iostream>
using namespace std;

class ListNode{
	public:
		int value;
		ListNode *next;

		ListNode(int value){
			this->next =nullptr;
			this->value = value;
		}
};

class Solution{
	private:
		static int getLengthAndTail(ListNode *head, ListNode * &tail){
			int count = 0;
			while(head){
				if(head -> next == NULL){
					tail = head;	
				}
				head = head->next;
				count++;
			}

			return count;
		}

	public:
		static ListNode *rotateRight(ListNode *head , int k){
			if(head == NULL){
				return head;
			}
			ListNode *tail = NULL;
			int lenOfList = getLengthAndTail(head, tail);
			if(k == lenOfList || lenOfList == 1 || k%lenOfList == 0){
				return head;	
			}

			if(k > lenOfList){
				k = k - lenOfList;
			}
			
			int lastNodeIndex = (lenOfList - k) - 1;
			ListNode *curr = head;
			while(lastNodeIndex--){
				curr = curr -> next;
			}

			tail->next = head;
			head = curr->next;
			curr->next = NULL;

			return head;
		}	
};

int main(){
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	// head->next->next = new ListNode(3);
	// head->next->next->next = new ListNode(4);
	// head->next->next->next->next = new ListNode(5);

	ListNode *newHead = Solution::rotateRight(head, 5);
	while(newHead != nullptr){
		cout << newHead->value << " ";
		newHead = newHead->next;
	}

	return 0;
}