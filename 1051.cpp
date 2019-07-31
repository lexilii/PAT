#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int m, n, k;
	scanf("%d%d%d", &m, &n, &k);

	while (k--)
	{
		stack<int> st;
		// st 定义在循环里面，不需要执行如下清空操作
		//while (!st.empty())
		//{
		//	st.pop();
		//}

		vector<int> seque(n);

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &seque[i]);
		}
		bool flag = true;
		int curr = 0; // 指向出栈序列中的待出栈元素
		for (int i = 0; i < n; i++)
		{
			st.push(i + 1);
			if (st.size() > m)
			{
				flag = false;
				break;
			}
			// 栈顶元素与出栈序列当前位置的元素相同
			while (!st.empty() && st.top() == seque[curr])
			{
				st.pop();
				curr++;
			}

		}

		if (st.empty() && flag == true)  // 结束时栈要为空
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
