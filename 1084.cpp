#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Hash
{
	char c;
	int count = 0;
	int order = 0;
};

bool cmp(const Hash& h1, const Hash& h2)
{
	return h1.order < h2.order;
}

int main()
{
	vector<Hash> hashTable(128); // ASCLL 码共128个 编号为0~127

	char c;
	int order = 0;
    
	while (scanf("%c", &c) && c != '\n')
	{
		// 大小写都归为大写
		if (c >= 'a'&&c <= 'z')
		{
			c = c + 'A' - 'a';
		}
		// 第一次读到这个 字符
		if (hashTable[c].count == 0)
		{
			order++;
			hashTable[c].c = c;
			hashTable[c].order = order;
			hashTable[c].count++;
		}
		else
		{
			hashTable[c].count++;
		}
	}

	while (scanf("%c", &c) && c != '\n')
	{
		// 大小写都归为大写
		if (c >= 'a'&&c <= 'z')
		{
			c = c + 'A' - 'a';
		}

		hashTable[c].count--;
	}

	// 按照读入先后顺序排序
	sort(hashTable.begin(), hashTable.end(), cmp);

	for (int i = 0; i < 128; i++)
	{
		if (hashTable[i].count != 0)
		{
			printf("%c", hashTable[i].c);
		}
	}
	printf("\n");
	return 0;
}
