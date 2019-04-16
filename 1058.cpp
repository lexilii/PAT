#include <cstdio>

struct Money {
	int galleon;
	int sickle;
	int knut;
};

int main()
{
	Money a, b;
	scanf("%d.%d.%d", &a.galleon, &a.sickle, &a.knut);
	scanf("%d.%d.%d", &b.galleon, &b.sickle, &b.knut);

	Money c;
	c.knut = (a.knut + b.knut) % 29;
	c.sickle = (a.sickle + b.sickle + (a.knut + b.knut) / 29) % 17;
	c.galleon = a.galleon + b.galleon + (a.sickle + b.sickle + (a.knut + b.knut) / 29) / 17;

	printf("%d.%d.%d", c.galleon, c.sickle, c.knut);
	return 0;
}
