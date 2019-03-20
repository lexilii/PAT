#include <iostream>
#include <string>

using namespace std;

char table[13] = { '0','1','2','3','4','5','6','7','8','9','A','B','C' };
int main()
{
	int dRGB[3];
	cin >> dRGB[0] >> dRGB[1] >> dRGB[2];

	string result;
	for (int i = 0; i < 3; i++)
	{
		int a, b;
		a = dRGB[i] % 13;
		b = dRGB[i] / 13;
		result = result + table[b] + table[a];
	}
	cout << "#" << result;
	return 0;
}
