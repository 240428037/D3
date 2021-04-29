/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
bool isUnivalTree(struct TreeNode* root){
	if (root == NULL)
		return true;
	if (root->left&&root->val != root->left->val)
		return false;
	if (root->right&&root->val != root->right->val)
		return false;
	//递归
	return isUnivalTree(root->left) && isUnivalTree(root->right);
}

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

//二叉树节点个数
//分治递归
//递归-1.子问题 2.返回条件
//1.子问题 root left right
//2.返回条件 空树
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}




// 二叉树叶子节点个数
//1.空树 return 0
//2.叶子 return 1
//3.不为空 左子树叶子节点个数+右子树叶子节点个数

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL&&root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}



// 二叉树第k层节点个数
//第k层：左子树k-1层+右子树k-1层
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}



//分治递归
//A B C
//N L R
//DepthA=Max(B,C)+1
int maxDepth(struct TreeNode* root){
	if (root == NULL)
		return 0;
	int leftdepth = maxDepth(root->left);
	int rightdepth = maxDepth(root->right);
	return leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;
}



#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int w, h, count = 0;
	cin >> w >> h;
	vector<vector<int>> a;
	a.resize(w);
	for (auto&e : a)
		e.resize(h, 1);
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; i < h; j++)
		{
			if (a[i][j] == 1)
			{
				count++;
				if ((i + 2) < w)
					a[i + 2][j] = 0;
				if ((j + 2) < h)
					a[i][j + 2] = 0;
			}
		}
	}
	cout << count;
	return 0;
}