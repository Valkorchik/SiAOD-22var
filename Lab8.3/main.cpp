#include <iostream>
#include <chrono>
using namespace std;
void arrInput(int* arr,int n);
void arrRand(int* arr,int n);
void arrOutput(int* arr,int n);
void swap(int& first, int& second);
void stoogeSort(int* arr,int l, int h);
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
	//arrOutput(arr,n);
	auto begin = std::chrono::high_resolution_clock::now();
	stoogeSort(arr,0, n-1);
	auto end = std::chrono::high_resolution_clock::now();
	cout<<"Array after sort: \n";
	//arrOutput(arr,n);
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
void arrOutput(int* arr,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}
void swap(int& first, int& second)
{
	int buff;
	buff = first;
	first= second;
	second = buff;
}
void stoogeSort(int* arr,int l, int h)
{
    if (l >= h)
      return;
    if (arr[l] > arr[h])
       swap(arr[l], arr[h]);
    if(h-l+1>2)
    {
        int t = (h-l+1)/3;
        stoogeSort(arr, l, h-t);
        stoogeSort(arr, l+t, h);
        stoogeSort(arr, l, h-t);
    }
}
