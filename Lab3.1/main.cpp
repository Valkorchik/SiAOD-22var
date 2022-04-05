#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
void StringReader(char*, char*, int&);
int StringConverter(char*, string*, int&);
vector<int> LengthSearcher(string*, int);
void PrintWords(string*, vector<int>);
int main()
{
	char stroka[] = { 'C','A','R',' ',' ',',','S','A','R',',',',','D','O','O','R',' ','P','O','O','R' };
	char nstroka[100];
	string string_container[100];
	int index=0;
	StringReader(stroka, nstroka, index);
	PrintWords(string_container, LengthSearcher(string_container,StringConverter(nstroka,string_container, index)));
	return 0;
}
void StringReader(char* stroka, char* nstroka,int& index)
{
	for (int i = 0; i < strlen(stroka); i++)
	{
		if (stroka[i] != ' ' && stroka[i] != ',')
		{
			nstroka[index]=stroka[i];
			index+=1;
		}
		if ((stroka[i] == ' ' || stroka[i] == ',') && (stroka[i + 1] != ' ' && stroka[i + 1] != ','))
		{
			nstroka[index]='|';
			index+=1;
		}
	}
}
int StringConverter(char* nstroka, string* string_container, int& index)
{
	string filler;
	int container_index=0;
	for(int i=0;i<index;i++)
	{
		if(nstroka[i] != '|')
		{
			filler += nstroka[i];
		}
		if (nstroka[i] == '|' || nstroka[i+1]==nstroka[index-1])
		{
			string_container[container_index] = filler;
			filler = "";
			container_index += 1;
		}
	}
	for(int i=0;i<container_index;i++)
	{
		cout<<string_container[i]<<" ";
	}
	return index;
}
vector<int> LengthSearcher(string* string_container,int index)
{
	vector<int> length_container;
	int length=0,min_length=1;
	for(int i=0;i<index;i++)
	{
		for(int j=0;j<index;j++)
		{
			if(string_container[i]==string_container[j])
			{
				continue;
			}
			for(int z=0;z<string_container[i].size();z++)
			{
				if(string_container[i][z]!=string_container[j][z])
				{
					length+=1;
				}
				if(z==string_container[i].size()-1 && length<=min_length && length!=0)
				{
					min_length = length;
					length_container.push_back(length);
				}
				if(z==string_container[i].size()-1)
				{
					length=0;
				}
			}
		}
	}
	return length_container;
}
void PrintWords(string* string_container, vector<int> length_container)
{
	cout<<"Words: ";
	int min_elem=*min_element(length_container.begin(),length_container.end());
	if(count(length_container.begin(),length_container.end(),min_elem)>1 && min_elem>0)
	{
		for(int j=0;j<length_container.size();j++)
		{
			if(length_container[j]==min_elem)
			{
				cout<<string_container[j]<<" ";
			}
		}
	}
	if(count(length_container.begin(),length_container.end(),min_elem)==1 && min_elem>0)
	{
		vector<int>::iterator it=find(length_container.begin(), length_container.end(),min_elem);
		if (it!=length_container.end())
		{
			cout<<string_container[*it];
		}
	}
	if(min_elem==0)
	{
		cout<<"No words";
	}
}
