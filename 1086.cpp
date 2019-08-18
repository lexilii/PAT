#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

const int maxn = 35;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

int pre[maxn], in[maxn], post[maxn]; // 先序，中序，后续

Node* creat(int prel, int prer, int inl, int inr);
void postOut(Node* root, int n, int &num);

int main()
{
	int n;
	scanf("%d", &n);
	string str;
	int x;
	int pre_idx = 0; // 先序
	int in_idx = 0; // 中序
	stack<int> st;
	for (int i = 0; i < 2 * n; i++) // n个结点，出栈入栈共2*n次
	{
		cin >> str;
		if (str == "Push") // 入栈
		{
			cin >> x;
			pre[pre_idx] = x;
			pre_idx++;
			st.push(x); 
		}
		else
		{
			in[in_idx] = st.top();
			in_idx++;
			st.pop();
		}
	}

	Node* root = creat(0, n - 1, 0, n - 1); // 建树
	int num = 0;
	postOut(root, n, num); // 后续遍历输出

	return 0;
}

// 当前二叉树 先序序列区间为 [prel,prer]，中序序列区间为 [inl,inr], 返回构建的二叉树根节点
Node* creat(int prel, int prer, int inl, int inr)
{
	if (prel > prer)
		return NULL; 
	Node* root = new Node; // 创建一个新结点，用来存放当前二叉树根节点
	root->data = pre[prel]; // 根节点的数据是 先序遍历的第一个
	int k;
	for (k = inl; k <= inr; k++)
	{
		if (in[k] == pre[prel])
			break; // 如果在中序序列中找到 pre中的根节点，则返回
	}
	int num_left = k - inl; // 左子树结点个数,根节点在中序遍历中划分左右子树
	root->left = creat(prel + 1, prel + num_left, inl, k - 1);
	root->right = creat(prel + num_left + 1, prer, k + 1, inr);

	return root;
}

// 后续遍历输出
void postOut(Node* root, int n, int &num)
{
	if (root == NULL)
		return;
	postOut(root->left, n, num);
	postOut(root->right, n, num);
	printf("%d", root->data);
	num++;
	if (num < n)
		printf(" ");
}
