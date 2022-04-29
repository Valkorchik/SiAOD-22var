#include <iostream>
using namespace std;
void arrInput(int* arr,int n);
void insertionSort(int* arr, int n);
void arrRand(int* arr,int n);
void arrOutput(int* arr,int n);
int main() {
	int n,choice;
	cin>>n;
	int* arr=new int[n];
	cout<<"Method of containing: 1 (keyboard) , 2 (random): \n";
	cin>>choice;
	if(choice==1)
		arrInput(arr,n);
	else if(choice==2)
	{
		srand(time(NULL));
		arrRand(arr,n);
	}
	cout<<"\nSource array: \n";
	arrOutput(arr,n);
	insertionSort(arr,n);
	cout<<"Array after sort: \n";
	arrOutput(arr,n);
	delete[] arr;
	return 0;
}
void arrInput(int* arr,int n)
{
	for(int i=0;i<n;i++)
	{
		  cin>>arr[i];
	}
}
void arrRand(int* arr,int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void insertionSort(int* arr, int n)
{
	int temp,item;
	for (int counter = 1; counter < n; counter++)
	{
		temp = arr[counter];
		item = counter-1;
		while(item >= 0 && arr[item] > temp)
		{
			arr[item + 1] = arr[item];
			arr[item] = temp;
			item--;
		}
	}
}
void arrOutput(int* arr,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}