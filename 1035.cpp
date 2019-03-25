#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

struct Account
{
	string name;
	string password;
};
int main()
{
	int N;
	scanf("%d", &N);
	vector<Account> accounts(N);
	char name[11];
	char password[11];
	for (int i = 0; i < N; i++)
	{
		scanf("%s %s", name, password);
		accounts[i].name = name;
		accounts[i].password = password;
	}

	bool flag = false;
	vector<Account> result;
	for (int i = 0; i < N; i++)
	{
		int size = accounts[i].password.size();
		flag = false;
		for (int j = 0; j < size; j++)
		{
			switch (accounts[i].password[j])
			{
			case '1':
				accounts[i].password[j] = '@';
				flag = true;
				break;

			case '0':
				accounts[i].password[j] = '%';
				flag = true;
				break;

			case 'l':
				accounts[i].password[j] = 'L';
				flag = true;
				break;

			case 'O':
				accounts[i].password[j] = 'o';
				flag = true;
				break;
			}
		}
		
		if (flag == true)
			result.push_back(accounts[i]);
	}
	if (result.size()==0)
	{
		if (N == 1)
			printf("There is 1 account and no account is modified");
		else
			printf("There are %d accounts and no account is modified",N);
	}
	else
	{
		printf("%d\n", result.size());
		for (int i = 0; i < result.size(); i++)
			printf("%s %s\n", result[i].name.c_str(), result[i].password.c_str());
	}
	return 0;
}
