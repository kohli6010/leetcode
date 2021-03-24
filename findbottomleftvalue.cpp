// 513. Find Bottom Left Tree Value

// Given the root of a binary tree, return the leftmost value in the last row of the tree.

// Example 1:

// Input: root = [2,1,3]
// Output: 1

// Example 2:

// Input: root = [1,2,3,4,null,5,6,null,null,7]
// Output: 7
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -231 <= Node.val <= 231 - 1

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class TreeNode{
	public:
		int value;
		TreeNode *left;
		TreeNode *right;

		TreeNode(){
			this->left = NULL;
			this->value = 0;
			this->right = NULL;
		}

		TreeNode(int value){
			this->value = value;
			this->left = NULL;
			this->right = NULL;
		}
};

class Solution {
public:
   //  int findBottomLeftValue(TreeNode* root) {
   //      if(root == NULL){
	// 		  return -1;
	// 	  }

	// 	  if(root->left == NULL && root->right == NULL){
	// 		  return root->value;
	// 	  }

	// 	  int height = findHeight(root);

	// 	  queue<TreeNode *> q;
	// 	  q.push(root);
	// 	  q.push(NULL);
	// 	  int counter = 0;

	// 	  while(!q.empty()){
	// 		  TreeNode *temp = q.front();
	// 		  q.pop();
	// 		  if(temp == NULL){
	// 			  counter++;
	// 			  if(counter == height){
	// 				  return q.front()->value;
	// 			  }

	// 			  q.push(NULL);
	// 		  }else{
	// 			  if(temp->left){
	// 				  q.push(temp->left);
	// 			  }

	// 			  if(temp->right){
	// 				  q.push(temp->right);
	// 			  }
	// 		  }
	// 	  }

	// 	  return 0;
	//  }

	int findBottomLeftValue(TreeNode *root){
		if(root==NULL){
			return -1;
		}

		if(root->left == NULL && root->right == NULL){
			return root->value;
		}

		TreeNode *n = NULL;
		queue<TreeNode *> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty()){
			TreeNode *temp = q.front();
			q.pop();
			if(temp == NULL){
				if(q.empty()){
					return n->value;
				}
				q.push(NULL);
				n = q.front();
			}
			else{
				if(temp->left){
					q.push(temp->left);
				}
				if(temp->right){
					q.push(temp->right);
				}
			}
		}

		return n->value;
	}

	 int findHeight(TreeNode *root){
		 if(root == NULL){
			 return -1;
		 }

		 int leftHeight = findHeight(root->left);
		 int rightHeight = findHeight(root->right);

		 return max(leftHeight, rightHeight) + 1;
	 }
};

int main(){
	TreeNode *root = new TreeNode(2);
	root->left = new TreeNode(1);
	// root->left->left = new TreeNode(1);
	root->right = new TreeNode(3);
	// root->right->left = new TreeNode(5);
	// root->right->right = new TreeNode(6);
	// root->right->left->right = new TreeNode(7);

	Solution s;
	int bottomLeftElement = s.findBottomLeftValue(root);
	cout << bottomLeftElement;
	return 0;
}