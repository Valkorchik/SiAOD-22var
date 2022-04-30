#include <iostream>
#include <chrono>
using namespace std;
void arrInput(int* arr,int n);
void swap(int *arr, int index);
void arrRand(int* arr,int n);
void arrOutput(int* arr,int n);
void shakerSort(int *arr, int n);
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
	auto begin = std::chrono::high_resolution_clock::now();
	shakerSort(arr, n);
	auto end = std::chrono::high_resolution_clock::now();
	cout<<"Array after sort: \n";
	arrOutput(arr,n);
	std::chrono::duration<float> duration =   end - begin;
	std::cout << "\nSorting time: " << duration.count() << "ms\n";
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
void swap(int *arr, int index)
{
	int buff;
	buff = arr[index];
	arr[index] = arr[index - 1];
	arr[index - 1] = buff;
}
void shakerSort(int *arr, int n)
{
	bool ivers;
	int leftMark = 1;
	int rightMark = n - 1;
	while (leftMark <= rightMark)
	{
		ivers=false;
		for (int i = rightMark; i >= leftMark; i--)
		{
			if (arr[i - 1] < arr[i])
			{
				swap(arr, i);
				ivers=true;
			}
		}
		leftMark++;
		for (int i = leftMark; i <= rightMark; i++)
		{
			if (arr[i - 1] < arr[i])
			{
				swap (arr, i);
				ivers=true;
			}
		}
		if(ivers==false)
		{
			return;
		}
		rightMark--;
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