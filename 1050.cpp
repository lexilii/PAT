#include <cstdio>
#include <iostream>

using namespace std;

int HashTable[128] = { 0 };
char a[10001]; // 记录顺序

int main()
{
	int i = 0;
	while (scanf("%c", &a[i]) && a[i] != '\n')
	{
		HashTable[a[i]]++;
		i++;
	}
	i--;
	
	char c;
	while (scanf("%c", &c) && c != '\n')
	{
		HashTable[c] = 0;
	}

	for (int k = 0; k <= i; k++)
	{
		if (HashTable[a[k]] != 0)
		{
			printf("%c", a[k]);
		}
	}
	return 0;
}
