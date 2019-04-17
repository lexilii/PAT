#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool mysort(const string& s1, const string& s2)
{
	return s1.length() < s2.length();
}

int main()
{
	int n;
	scanf("%d", &n);
	cin.get();
	vector<string> data(n);
	for (int i = 0; i < n; i++)
	{
		getline(cin, data[i]);
	}
	sort(data.begin(), data.end(), mysort);

	int len0 = data[0].length();

	bool stop = false;
	int start = -1;
	for (int l = 0; l < len0; l++)
	{
		for (int i = 1; i < n; i++)
		{
			int leni = data[i].length();

			if (data[i][leni - l - 1] != data[0][len0 - l - 1])
			{
				stop = true;
				break;
			}
		}
		if (stop == false)
		{
			start = len0 - l - 1;
		}
		else
			break;
	}

	if (start < 0)
		printf("nai");
	else
	{
		for (int i = start; i < len0; i++)
			printf("%c", data[0][i]);
	}
}
