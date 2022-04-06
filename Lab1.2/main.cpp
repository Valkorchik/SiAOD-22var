#include <iostream>
using namespace std;
int* ArrayCreate(int*, const int&);
void ArrayShower(const int&, const int*);
int IndexSearcher(const int*, const int&);
string ElementInsert(int*&, int&);
string ElementErase(int*&, int&);
int main()
{
	int n;
	cout << "Enter array size: \n";
	cin >> n;
	if (n < 0)
	{
		cout << "Wrong size" << endl;
		return 0;
	}
	int* arr = new int[n];
	ArrayShower(n, ArrayCreate(arr, n));
	cout << "First ex (-1 code = index not found): \n";
	cout << IndexSearcher(arr, n) << endl;
	cout << "Second ex: \n" << ElementInsert(arr, ++n);
	ArrayShower(n, arr);
	cout << "Third ex: \n" << ElementErase(arr, n);
	ArrayShower(n, arr);
	delete[] arr;
}
int* ArrayCreate(int* arr, const int& size)
{
	int arr_value;
	for (int i = 0; i < size; i++)
	{
		cin >> arr_value;
		arr[i] = arr_value;
	}
	return *&arr;
}
void ArrayShower(const int& size, const int* arr)
{
	cout << "Array: \n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int IndexSearcher(const int* arr, const int& size)
{
	int local;
	int counter = 0;
	int dcounter = 0;
	for (int i = 1; i < size; i++)
	{
		local = arr[i];
		while (local)
		{
			int d = arr[i] % 10;
			if (i % d == 0)
			{
				counter += 1;
			}
			local = local / 10;
			dcounter += 1;
		}
		if (counter == dcounter)
		{
			return i;
		}
		dcounter = 0;
		counter = 0;
	}
	return -1;
}
string ElementInsert(int*& arr, int& size)
{
	int elem;
	cout << "Enter element: \n";
	cin >> elem;
	int* local_arr = new int[size];
	bool insert_check = true;
	for (int i = 0, j = 0; i < size; i++, j++)
	{
		if (insert_check == true)
		{
			bool check = true;
			int temp = arr[i];
			while (temp)
			{
				if (temp % 10 == elem)
				{
					temp =  temp / 10;
				}
				else
				{
					check = false;
					break;
				}
			}
			if (check == true)
			{
				local_arr[j++] = arr[i++];
				local_arr[j] = elem;
				i--;
				insert_check = false;
				continue;
			}
		}
		local_arr[j] = arr[i];
	}
	delete[] arr;
	arr = local_arr;
	return "Successfully inserted\n";
}
string ElementErase(int*& arr, int& size)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 3 == 0)
		{
			counter++;
		}
	}
	int* local_arr = new int[size -= counter];
	for (int i = 0, j = 0; i < size; i++, j++)
	{
		if (arr[j] % 3 == 0)
		{
			i--;
		}
		else
			local_arr[i] = arr[j];
	}
	delete[] arr;
	arr = local_arr;
	return "Elements erased\n";
}
