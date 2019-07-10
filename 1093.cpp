#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 100000 + 5;
char s[maxn];
int leftP[maxn] = { 0 };

int main()
{
	scanf("%s", s);

	int len = strlen(s);

	if (s[0] == 'P')
		leftP[0] = 1;
	for (int i = 1; i < len; i++)
	{
		if (s[i] == 'P')
			leftP[i] = leftP[i - 1] + 1;
		else
			leftP[i] = leftP[i - 1];
	}
	int rightT = 0;
	int ans = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if (s[i] == 'T')
			rightT++;
		else if (s[i] == 'A')
			ans = (ans + leftP[i] * rightT) % 1000000007;
	}

	printf("%d", ans);
}
