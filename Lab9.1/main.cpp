#include <iostream>
#include <string>
#include <cmath>
#include <chrono>
using namespace std;

struct Patient
{
	uint64_t cardId = 0;
	uint64_t diseaseId;
	string doctorSurname;
};

int bruteForce(Patient* table, int size, uint64_t key)
{
	for (int i = 0; i < size; i++)
		if (table[i].cardId == key)
			return i;
	return -1;
}

int barierSearch(Patient* table, int size, uint64_t key)
{
	Patient last = table[size - 1];
	table[size - 1].cardId = key;
	int i=0;
	for ( i; table[i].cardId != key; i++);
	table[size - 1] = last;
	if((i != size - 1)  || (last.cardId == key))
	{
		return i;
	}
	return -1;
}

struct Hash
{
	int max,size;
	Patient* hashTab;
	Hash();
	bool isFull();
	int hash(int64_t key);
	void insertHash(Patient* table);
	int hashSearch(int64_t key);
};

bool Hash::isFull()
{
	return (size == max);
}

int Hash::hash(int64_t key)
{
	return (key % max);
}

Hash::Hash()
{
	max = 100000;
	hashTab = new Patient[max];
	size = 0;
	for (int i = 0; i < max; i++)
		hashTab[i].cardId = -1;
}
void Hash::insertHash(Patient* table)
{
	if (isFull())
		return;
	int64_t index = hash(table->cardId);
	if (hashTab[index].cardId != -1)
	{
		int i = 1;
		while (1)
		{
			if (hashTab[index+1+i].cardId== -1)
			{
				hashTab[index+1+i].cardId = table->cardId;
				break;
			}
			i++;
		}
	}
	else
		hashTab[index] = *table;
	size++;
}
int Hash::hashSearch(int64_t key)
{
	int k = hash(key);
	int i = 0;
	while (hashTab[(k + i ) % max].cardId != key)
	{
		if (hashTab[(k+ i ) % max].cardId== -1)
		{
			cout << key << " not found" << endl;
			return -1;
		}
		i++;
	}
	return (k + i) % max;
}

void input(Patient* table, int size)
{
	for (int i = 0; i < size; i++)
	{
		cin>>table[i].cardId>>table[i].diseaseId>> table[i].doctorSurname;
	}
}

void randFill(Patient* table, int size)
{

	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			table[i].cardId += (rand() % 9 + 1) * pow(10, j);
		}
		table[i].diseaseId = rand() % 1000;

		table[i].doctorSurname ="Surname"+to_string(i+1);
	}
}

void printTab(Patient* table, int size)
{
	for (int i = 0; i < size; i++) {
		cout << table[i].cardId << '\t'<< table[i].diseaseId << '\t'<< table[i].doctorSurname << '\t'<<endl;
	}

}

void printCard(Patient* table, int i)
{
	cout << "\nCardId:\n";
	if(i!=-1)
	{
		cout << table[i].cardId << '\t'<< table[i].diseaseId << '\t'<< table[i].doctorSurname << '\t';
	}
	else cout << "not found ";
}

int main()
{
	int size;
	cin >> size;
	cout << "Table size: "<<endl<<size;
	uint64_t key = -1;
	Patient* table = new Patient[size];

	cout << "\nMenu: 1 - keyboard , 2 - random fill, 3 - worst fill\n";
	int choice;
	cin >> choice;

	if (choice == 1)
	{
		input(table, size);
		printTab(table, size);
		cin >> key;
	}
	else if (choice == 2)
	{
		randFill(table, size);
		printTab(table, size);
		cin >> key;
	}
	else if (choice == 3)
	{
		randFill(table, size);
		printTab(table, size);
		key = table[size - 1].cardId;
	}

	cout<<"\nAlgorithm: 1 - bruteForce, 2 - barier, 3 - hash:\n";
	cin>>choice;
	if (choice == 1)
	{

		int num = bruteForce(table, size, key);
		printCard(table, num);
	}
	else if (choice == 2)
	{

		int num = barierSearch(table, size, key);
		printCard(table, num);
	}
	else if (choice == 3)
	{

		Hash hash;
		for (int i = 0; i < size; i++)
		{

			hash.insertHash(&table[i]);
		}
		int num = hash.hashSearch(key);
		printCard(hash.hashTab, num);
	}
	delete[] table;
}