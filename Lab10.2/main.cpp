#include <iostream>
#include <regex>
#include <string>
using namespace std;
void regexMatch(string& var)
{
	regex r("([a-zA-z]=[0-9]?\\*?[a-zA-Z\\d](?:\\+|\\-|/|%|\\*)[0-9]?\\*?[a-zA-Z\\d])");
	smatch sm;

	if (regex_search(var, sm, r))
	{
		cout <<"Match found\n";
	}
	for (int i=1; i<sm.size(); i++)
	{
		cout << sm[i]<<" ";
	}
}
int main()
{
	string var;
	cin>>var;
	regexMatch(var);
	return 0;
}
