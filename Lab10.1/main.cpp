#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define alpha 10
void rabinKarp(char pattern[], char text[], int q)
{
	int counter=0;
	int patSize = strlen(pattern);
	int txtSize = strlen(text);

	int patHash = 0;
	int txtHash = 0;
	int hash = 1;

	int i, j;
	for (i = 0; i < patSize - 1; i++)
		hash = (hash * alpha) % q;


	for (i = 0; i < patSize; i++)
	{
		patHash = (alpha * patHash + pattern[i]) % q;
		txtHash = (alpha * txtHash + text[i]) % q;
	}


	for (i = 0; i <= txtSize - patSize; i++)
	{
		if (patHash == txtHash)
		{
			for (j = 0; j < patSize; j++)
			{
				if (text[i + j] != pattern[j])
					break;
			}

			if (j == patSize)
				counter++;
		}

		if (i < txtSize - patSize)
		{
			txtHash = (alpha * (txtHash - text[i] * hash) + text[i + patSize]) % q;

			if (txtHash < 0)
				txtHash = (txtHash + q);
		}
	}
	cout<<pattern<<" --- "<<counter<<endl;
}

int main()
{
	ifstream t;
	t.open("C:\\text.txt");
	string s, text;
	while(t)
	{
		getline(t,s);
		text+=s;
	}
	char txt[1000];
	strcpy(txt, text.c_str());
	char favWords[][11]={"metres","hours"," mountain ","Kilian"," his ", "life", "only", " at ", " age ","times", "year"};
	for(int i=0;i<10;i++)
	{
		rabinKarp(favWords[i],txt,13);
	}
	return 0;
}
