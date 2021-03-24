#include<iostream>
#include<vector>
using namespace std;

class ListNode {
		public:
			int val;
			ListNode *next;
			ListNode() : val(0), next(nullptr) {}
			ListNode(int x) : val(x), next(nullptr) {}
			ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len;
        len = Length(root);
        int r = len%k;
        ListNode *temp = root;
        vector<ListNode*>res;
        
        while(temp != NULL) {
            res.push_back(temp);
            int i = 0, x;
            if(r > 0) 
                x = len/k + 1;
            else
                x = len/k;
            while(i < x-1) {
                temp= temp->next;
                i++;
            }
            ListNode *Next = temp->next;
            temp->next = NULL;
            temp = Next;
            r--;
        }
        while(res.size() != k)
            res.push_back(NULL);
        
        return res;
    }
    int Length(ListNode *head) {
        int len = 0;
        ListNode *temp = head;
        
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }
};

int main(){
	Solution s;
	ListNode *head = new ListNode(1);
	head -> next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);
	head->next->next->next->next->next->next = new ListNode(7);
	head->next->next->next->next->next->next->next = new ListNode(8);
	head->next->next->next->next->next->next->next->next = new ListNode(9);
	head->next->next->next->next->next->next->next->next->next = new ListNode(10);
	vector<ListNode *> res = s.splitListToParts(head, 3);
	for (int i = 0; i < res.size(); i++){
		cout << res[i]->val << " ";
	}
		return 0;
}