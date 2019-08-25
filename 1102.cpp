#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

struct node
{
	int left, right;
};

node nodes[11];
bool notRoot[11] = { false }; // 初始设置所有节点都为根节点

int findRoot(const int& n);
void postOrder(int root, int n);
void BFS(int root, int n);
void inOrder(int root, int n);

int num = 0;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		getchar(); // 吸收回车
		char lchild, rchild;
		scanf("%c %c", &lchild, &rchild);
		if (lchild == '-')
			nodes[i].left = -1;
		else
		{
			nodes[i].left = lchild - '0';
			notRoot[lchild - '0'] = true; // 根节点不是任何节点的子节点
		}
		if (rchild == '-')
			nodes[i].right = -1;
		else
		{
			nodes[i].right = rchild - '0';
			notRoot[rchild - '0'] = true;
		}
	}
	int root = findRoot(n);  // 获得根节点编号
	postOrder(root, n); // 后续遍历，反转二叉树
	BFS(root, n); // 层序遍历输出
	inOrder(root, n); // 中序遍历输出
	return 0;
}

int findRoot(const int& n)
{
	for (int i = 0; i < n; i++)
	{
		if (notRoot[i] == false)
			return i;  // 是根节点，返回标号
	}
}

void postOrder(int root, int n)
{
	if (root == -1) // 到叶子节点
		return;

	postOrder(nodes[root].left, n);
	postOrder(nodes[root].right, n);
	swap(nodes[root].left, nodes[root].right); // 交换左右孩子结点
}

void inOrder(int root, int n)
{
	if (root == -1) // 到叶子结点
		return; 

	inOrder(nodes[root].left, n);
	printf("%d", root);
	num++;
	if (num < n)
		printf(" ");
	else
		printf("\n");
	inOrder(nodes[root].right, n);
}
void BFS(int root, int n)
{
	queue<int> q; // 队列里存地址
	q.push(root);
	int num = 0;
	while (!q.empty())
	{
		int now = q.front();  // 取出队首元素
		q.pop();
		printf("%d",now);
		num++;
		if (num < n)
			printf(" ");
		else
			printf("\n");

		if (nodes[now].left != -1)
			q.push(nodes[now].left);
		if (nodes[now].right != -1)
			q.push(nodes[now].right);
	}

}
