#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
	public:
		int value;
		Node *left;
		Node *right;

		Node(){
			this->value = 0;
			this->left = NULL;
			this->right = NULL;
		}

		Node(int value){
			this->value = value;
			this->right = NULL;
			this->left = NULL;
		}
};

class BST{
	public:
		static Node* insert(Node *root, int value){
			if(root == NULL){
				return new Node(value);
			}

			else if(root->value > value){
				root->left = insert(root->left, value);
			}

			else{
				root->right = insert(root->right, value);
			}

			return root;
		}

		static void traverse(Node *root){
			if(root == NULL){
				return;
			}

			traverse(root->left);
			cout << root->value << " ";
			traverse(root->right);
		}

		static void leftView(Node *root){
			if(root == NULL){					
				return;
			}
			queue<Node *> Q;
			Q.push(root);
			Q.push(NULL);
			cout << root->value << " ";
			while(!Q.empty()){
				Node *temp = Q.front();
				Q.pop();
				if(temp == NULL){
					if(Q.empty()){
						return;
					}
					cout << Q.front()->value << " ";
					Q.push(NULL);
				}else{
					if(temp->left){
						Q.push(temp->left);
					}

					if(temp->right){
						Q.push(temp->right);
					}
				}
			}
		}

		static void rightView(Node *root){
			if(root == NULL){					
				return;
			}
			queue<Node *> Q;
			Q.push(root);
			Q.push(NULL);
			cout << root->value << " ";
			while(!Q.empty()){
				Node *temp = Q.front();
				Q.pop();
				if(temp == NULL){
					if(Q.empty()){
						return;
					}
					cout << Q.front()->value << " ";
					Q.push(NULL);
				}else{
					if(temp->right){
						Q.push(temp->right);
					}

					if(temp->left){
						Q.push(temp->left);
					}
				}
			}
		}
};

int main(){
	Node *root = new Node(5);
	vector<int> vec = {2, 6, 3, 4, 7, 8, 1};
	for (int i = 0; i < vec.size(); i++){
		BST::insert(root, vec[i]);
	}

	// BST::traverse(root);
	BST::rightView(root);
	return 0;
}