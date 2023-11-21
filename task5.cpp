#include <iostream>
#include <ctime>
#include <string>
using namespace std;


int counter = 0;
struct HeshTable
{
	string word = "#";
	int indexOfNext;
};

string new_word(int n)
{
	string res, q;
	for (int i = 0; i < n; i++)
	{
		q = 97 + (rand() % 26);
		res += q;
	}
	return res;
}

void hesh_linear_add(HeshTable* table, string word, int n)
{
	int index = 0, next = table->indexOfNext;
	for (int i = 0; i < n; i++) 
		index += word[i] < 100 ? word[i] % 10 : word[i] % 100;
	if (table[index].word == "#") 
		table[index].word = word;
	else {
		while (table[index].word != "#")
		{
			if (index + 1 >= 299) 
				index = 0;
			counter++;
			index++;
		}
		table[index].word = word;
	}
}

void hesh_random_add(HeshTable* table, string word, int n)
{
	int index = 0, next = table->indexOfNext, newIndex = 0;
	for (int i = 0; i < n; i++) 
		index += word[i] < 100 ? word[i] % 10 : word[i] % 100;
	if (table[index].word == "#") 
		table[index].word = word;
	else {
		while (table[index].word != "#")
		{
			newIndex = rand() % 300;
			table[index].indexOfNext = newIndex;
			index = newIndex;
			counter++;
		}
		table[index].word = word;
	}
}

void empty_table(HeshTable* table) {
	for (int i = 0; i < 300; i++) table[i].word = "#";
}

void main()
{
	srand(time(0));
	setlocale(LC_ALL, "RU");
	int n, i = 0, j = 0;
	double mean = 0;
	string word;
	HeshTable* table_linear = new HeshTable[300];
	HeshTable* table_random = new HeshTable[300];

	cout << "Cреднее линейное значение коллизий: " << endl;
	for (int k = 10; k < 300; k += 10)
	{
		for (int j = 1; j <= 1000; j++) 
		{
			for (int i = 0; i < k; i++)
			{
				n = rand() % 14 + 2;
				word = new_word(n);
				hesh_linear_add(table_linear, word, n);
			}
			counter = 0;
			n = rand() % 14 + 2;
			word = new_word(n);
			hesh_linear_add(table_linear, word, n);
			mean += counter;
			empty_table(table_linear);
		}
		cout << k << " : " << mean / 1000 << endl;
		mean = 0;
	}

	cout << "Cреднее случайное значение коллизий: " << endl;
	for (int k = 10; k < 300; k += 10)
	{
		for (int j = 1; j <= 1000; j++) {
			for (int i = 0; i < k; i++)
			{
				n = rand() % 14 + 2;
				word = new_word(n);
				hesh_random_add(table_random, word, n);
			}
			counter = 0;
			n = rand() % 14 + 2;
			word = new_word(n);
			hesh_random_add(table_random, word, n);
			mean += counter;
			empty_table(table_random);
		}
		cout << k << " : " << mean / 1000 << endl;
		mean = 0;
	}
	system("pause>nul");
}
