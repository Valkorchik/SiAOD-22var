#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#pragma warning(disable: 4996)
using namespace std;
int StringConverter(char* nstroka, char** string_container);
vector<int> LengthSearcher(char**, int);
void PrintWords(char**, vector<int>);
int main()
{
	char stroka[255] = "CAR SAR, DOOR,  POOR";
	char* string_container[255];
	int index = StringConverter(stroka, string_container);
	PrintWords(string_container, LengthSearcher(string_container, index));
	return 0;
}
int StringConverter(char* nstroka, char** string_container)
{
	int i=0;
	string_container[0]=strtok(nstroka, ", ");
	while(string_container[i])
		string_container[++i]=strtok(NULL, ", ");
	return i;
}
vector<int> LengthSearcher(char** string_container, int index)
{
	vector<int> length_container;
	int length = 0, min_length = 1;
	for (int i = 0; i < index; i++)
	{
		for (int j = 0; j < index; j++)
		{
			if (string_container[i] == string_container[j])
			{
				continue;
			}
			for (int z = 0; z < strlen(string_container[i]); z++)
			{
				if (string_container[i][z] != string_container[j][z])
				{
					length += 1;
				}
				if (z == strlen(string_container[i]) - 1 && length <= min_length && length != 0)
				{
					min_length = length;
					length_container.push_back(length);
				}
				if (z == strlen(string_container[i]) - 1)
				{
					length = 0;
				}
			}
		}
	}
	return length_container;
}
void PrintWords(char** string_container, vector<int> length_container)
{
	cout << "Words: ";
	int min_elem = *min_element(length_container.begin(), length_container.end());
	if (count(length_container.begin(), length_container.end(), min_elem) > 1 && min_elem > 0)
	{
		for (int j = 0; j < length_container.size(); j++)
		{
			if (length_container[j] == min_elem)
			{
				cout << string_container[j] << " ";
			}
		}
	}
	if (count(length_container.begin(), length_container.end(), min_elem) == 1 && min_elem > 0)
	{
		vector<int>::iterator it = find(length_container.begin(), length_container.end(), min_elem);
		if (it != length_container.end())
		{
			cout << string_container[*it];
		}
	}
	if (min_elem == 0)
	{
		cout << "No words";
	}
}