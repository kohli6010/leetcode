#include<iostream>
using namespace std;

class Node{
	public:
		int value;
		Node *next;

		Node(int value){
			this->value = value;
			this->next = NULL;
		}
};

int linkedListSum(Node *head){
	if(head == NULL){

		return 0;
	}
	else{
		return head->value + linkedListSum(head->next);
	}
}

int main(){
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);

	int result = linkedListSum(head);
	cout << result;
	return 0;
}