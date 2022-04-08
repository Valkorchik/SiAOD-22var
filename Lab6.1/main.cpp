#include <iostream>
int C(int n, int m);
int main()
{
	int n,m;
	std::cout<<"Enter values for n and m:\n";
	std::cin>>n>>m;
	std::cout<<C(n,m);
}
int C(int n, int m)
{
	if ((m==0)&&(n>0) || (m==n)&&(n>0))
		return 1;
	else
		if ((m>n)&&(n>=0))
			return 0;
		else
			return C(n-1,m-1) + C(n-1,m);
}