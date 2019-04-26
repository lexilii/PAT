#include <cstdio>

int main()
{
	int HashTable[128] = { 0 };  //0~9 a~z A~Z

	char c;
	while (scanf("%c", &c) && c != '\n')
	{
		HashTable[c]++;
	}

	while (scanf("%c", &c) && c != '\n')
	{
		HashTable[c]--;
	}

	bool flag = true;
	int missing = 0;
	int extra = 0;
	for (int i = 0; i < 128; i++)
	{
		// 说明该种类型珠子数量不够
		if (HashTable[i] < 0)
		{
			flag = false; 
			missing -= HashTable[i];
		}
		else if (HashTable[i] > 0)
		{
			extra += HashTable[i];
		}
	}

	// 输出
	if (flag == true)
	{
		printf("Yes %d\n", extra);
	}
	else
	{
		printf("No %d\n", missing);
	}

	return 0;
}
