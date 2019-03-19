#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct BookItem
{
	string ID;
	string title;
	string author;
	vector<string> keyWords;
	string publisher; 
	string pubYear;
};

bool sortByID(const BookItem& book1, const BookItem& book2)
{
	return book1.ID < book2.ID; // 升序排列
}

void search(char num, string item, vector<BookItem>& books)
{
	int size = books.size();
	bool found = false;

	cout << num << ": " << item << endl;
	switch (num)
	{
	case '1': //a book title
	{
		for (int i = 0; i < size; ++i)
		{
			if (books[i].title == item)
			{
				cout << books[i].ID << endl;
				found = true;
			}
		}
		break;
	}
	case '2': //name of an author
	{
		for (int i = 0; i < size; ++i)
		{
			if (books[i].author == item)
			{
				cout << books[i].ID << endl;
				found = true;
			}
		}
		break;
	}
	case '3': //a key word
	{
		for (int i = 0; i < size; ++i)
		{
			int size2 = books[i].keyWords.size();
			for (int j = 0; j < size2; ++j)
			{
				if (books[i].keyWords[j] == item)
				{
					cout << books[i].ID << endl;
					found = true;
				}
			}
		}
		break;
	}
	case '4': //name of a publisher
	{
		for (int i = 0; i < size; ++i)
		{
			if (books[i].publisher == item)
			{
				cout << books[i].ID << endl;
				found = true;
			}
		}
		break;
	}
	case '5': //a 4-digit number representing the year
	{
		for (int i = 0; i < size; ++i)
		{
			if (books[i].pubYear == item)
			{
				cout << books[i].ID << endl;
				found = true;
			}
		}
		break;
	}
	}

	if (found == false)
		cout << "Not Found" << endl;

	
}
int main()
{
	int N; // total number of books
	scanf("%d", &N);
	cin.get(); //scanf不会带走缓冲区的'\n'
	vector<BookItem> books;
	BookItem tempbook;
	string key;
	for (int i = 0; i < N; ++i)
	{
		getline(cin,tempbook.ID);
		getline(cin, tempbook.title);
		getline(cin, tempbook.author);
		do {
			cin >> key;
			tempbook.keyWords.push_back(key);
		} while (cin.get() != '\n');
		getline(cin, tempbook.publisher);
		getline(cin, tempbook.pubYear);
		books.push_back(tempbook);
		tempbook.keyWords.clear(); //注意一定要清空这个vector，否则每次都会在后面继续push_back(key)
	}
	sort(books.begin(), books.end(), sortByID);
	int M; // the number of user's queries
	scanf("%d", &M);
	cin.get(); //读取缓冲区回车，否则下一个scanf会读取这个'\n'
	vector<string> item(M);
	vector<char> num(M);
	for (int i = 0; i < M; ++i)
	{
		scanf("%c: ", &num[i]);
		getline(cin, item[i]);
	}


	for (int i = 0; i < M; ++i)
	{
		search(num[i], item[i], books);
	}

	return 0;
}
