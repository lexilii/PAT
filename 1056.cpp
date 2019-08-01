#include <cstdio>
#include <queue>

using namespace std;

struct mice
{
	int weight;
	int ranks;
};

int main()
{

	int np, ng;
	scanf("%d%d", &np, &ng);

	int w;
	vector<mice> mouse(np);

	for (int i = 0; i < np; i++)
	{
		scanf("%d", &w);
		mouse[i].weight = w;
	}

	queue<int> q;
	int order;
	for (int i = 0; i < np; i++)
	{
		scanf("%d", &order);
		q.push(order);
	}

	int tempN = np; // 记录当前参赛的老鼠数
	int group; // 记录当前的组数
	while (tempN != 1) // 
	{
		// 计算当前分为几组进行比赛
		if (tempN%ng == 0)
			group = tempN / ng;
		else
			group = tempN / ng + 1;

		// 枚举每一组，选出该组中老鼠质量最大的
		for (int i = 0; i < group; i++)
		{
			int k = q.front(); // 存放组中质量最大的老鼠的 标号
			for (int j = 0; j < ng; j++)
			{
				// 在 最后一组老鼠数不足ng时 起作用，保证索引不越界
				if (i*ng + j >= tempN)
					break;
				int front = q.front();
				// 如果当前mice质量大于 k的质量，则更新max
				if (mouse[front].weight > mouse[k].weight)
					k = q.front();  // 不包含指针的结构体可以直接赋值

				mouse[front].ranks = group + 1; // 更新当前的排名情况
				q.pop(); // 出队这只老鼠
			}

			q.push(k); // 把胜利的老鼠入队
		}
		tempN = group; // group 只老鼠晋级，因此下一轮老鼠总数为 group
	}
	mouse[q.front()].ranks = 1; // 当队列中只有一只老鼠时，更新其排名为1

	printf("%d", mouse[0].ranks);
	for (int i = 1; i < np; i++)
	{
		printf(" %d", mouse[i].ranks);
	}
	return 0;
}
