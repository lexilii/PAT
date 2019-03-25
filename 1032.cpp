#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Node
{
	int next;
	char data;
	int flage = 0;
};

Node nodes[100001]; // 太大了，如果开在main函数中会导致 堆栈 溢出
 
int main()
{
	int start1, start2;
	int N;
	scanf("%d %d %d", &start1, &start2, &N);

	int address, next;
	char data;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %c %d", &address, &data, &next);
		nodes[address].next = next;
		nodes[address].data = data;
	}
	while (start1 != -1)
	{
		nodes[start1].flage = 1;
		start1 = nodes[start1].next;
	}
	while (start2 != -1)
	{
		if (nodes[start2].flage == 1)
		{
			printf("%05d", start2);
			return 0;

		}
		start2 = nodes[start2].next;
	}
	printf("-1");

	return 0;
}
