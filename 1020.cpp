
/*
1020. Tree Traversals (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.
Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:
4 1 6 3 5 7 2
*/



//第一种方案
#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	Node(int d = -1, Node *l = NULL, Node *r = NULL):data(d),left(l),right(r){}
};

Node* Build_In_Post(vector<int>::const_iterator postorder, vector<int>::const_iterator inorder, int size)
{
	if (size == 0)
		return NULL;
	else
	{
		int data = *(postorder + size - 1); // 后序遍历的最后一个一定是根节点，以此类推，后序遍历的左右子树的最后一个元素一定是子树所在的根节点（如果存在的话），也就是第二层的根节点，以此类推
		Node* root = new Node(data); 

		int index;
		for (index = 0; index < size && *(inorder + index) != data; ++index); // 在中序遍历结果中查找根节点所在位置

		root->left = Build_In_Post(postorder, inorder, index);
		root->right = Build_In_Post(postorder + index, inorder + index + 1, size - index - 1);

		return root;
	}
}

void level_order(deque<Node*> &nodes, int N)
{
	Node* temp;
	int count = 0;
	while (nodes.size() > 0 && count < N - 1)
	{
		temp = nodes.front();
		printf("%d ", temp->data);
		++count;
		nodes.pop_front();
		if (temp->left != NULL)
			nodes.push_back(temp->left);
		if (temp->right != NULL)
			nodes.push_back(temp->right);
	}
	printf("%d", nodes.front()->data);
}


int main()
{
	int N;
	scanf("%d", &N);

	vector<int> postorder(N);
	vector<int> inorder(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &postorder[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &inorder[i]);
	Node* root = Build_In_Post(postorder.begin(), inorder.begin(), N);
	deque<Node*> nodes;
	if (root != NULL)
		nodes.push_back(root);
	level_order(nodes, N);

	return 0;
}



//第二种方案
