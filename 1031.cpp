#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int N = s.size();
	int n1, n2, n3;
	int k = 0;

	for (n2 = 3; n2 <= N; n2++)
	{
		int temp = N + 2 - n2;
		if (temp % 2 == 0 && temp / 2 <= n2)
		{
			if (temp / 2 > k)
				k = temp / 2;
		}
	}
	n1 = n3 = k;
	n2 = N + 2 - 2 * k;
	//cout << "n1 = " << n1 << "   n2 = " << n2 << endl;
	for (int i = 0; i < n1 - 1; i++)
	{
		printf("%c", s[i]);
		for (int j = 0; j < n2 - 2; j++)
			printf(" ");
		printf("%c\n", s[N - 1 - i]);
	}
	for (int i = n1 - 1; i < n1 + n2 - 1; i++)
		printf("%c", s[i]);

	return 0;
}
