#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string &s1, string &s2)
{
	return s1 + s2 < s2 + s1;
}

int main()
{
	int n;
	scanf("%d", &n);
	vector<string> strs;
	for (int i = 0; i < n; i++)
	{
		char s[9];
		scanf("%s", s);
		string str = s;
		strs.push_back(str);
	}

	sort(strs.begin(), strs.end(), cmp);

	string ans;

	for (int i = 0; i < n; i++)
	{
		ans += strs[i];
	}

	// 如果结果不为空 且第一个为 0
	while (ans.size() != 0 && ans[0] == '0')
	{
		ans.erase(ans.begin());
	}

	if (ans.size() != 0)
		printf("%s", ans.c_str());
	else
		printf("0");

	return 0;
}
