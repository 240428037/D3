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
	//�ݹ�
	return isUnivalTree(root->left) && isUnivalTree(root->right);
}

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

//�������ڵ����
//���εݹ�
//�ݹ�-1.������ 2.��������
//1.������ root left right
//2.�������� ����
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




// ������Ҷ�ӽڵ����
//1.���� return 0
//2.Ҷ�� return 1
//3.��Ϊ�� ������Ҷ�ӽڵ����+������Ҷ�ӽڵ����

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL&&root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}



// ��������k��ڵ����
//��k�㣺������k-1��+������k-1��
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}



//���εݹ�
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