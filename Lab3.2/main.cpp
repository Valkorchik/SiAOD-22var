#include <iostream>
#include <string>
#include <vector>
using namespace std;
void StringReader(string&, string&);
int StringConverter(string&, string*);
vector<int> LengthSearcher(string*, int);
void PrintWords(string*, vector<int>);
int main()
{
	string stroka="CAR  ,SAR,,DOOR POOR"; //Проблемы реализации cin ввода: Вывод в PrintWords идет по порядку, значения теряются=>наименьшее число сходств должно быть в первых двух словах
	string string_container[100];
	string nstroka;
	StringReader(stroka, nstroka);
	PrintWords(string_container, LengthSearcher(string_container,StringConverter(nstroka,string_container)));
	return 0;
}
void StringReader(string& stroka, string& nstroka)
{
	for (int i = 0; i < stroka.length(); i++)
	{
		if (stroka[i] != ' ' && stroka[i] != ',')
		{
			nstroka.push_back(stroka[i]);
		}
		if ((stroka[i] == ' ' || stroka[i] == ',') && (stroka[i + 1] != ' ' && stroka[i + 1] != ','))
		{
			nstroka.push_back('|');
		}
	}
}
int StringConverter(string& nstroka, string* string_container)
{
	string filler;
	int index = 0;
	for(int i=0;i<nstroka.size();i++)
	{
		if(nstroka[i] != '|')
		{
			filler += nstroka[i];
		}
		if (nstroka[i] == '|' || nstroka[i+1]==nstroka[nstroka.size()])
		{
			string_container[index] = filler;
			filler = "";
			index += 1;
		}
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