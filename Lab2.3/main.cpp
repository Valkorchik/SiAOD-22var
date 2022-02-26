#include <iostream>
#include <vector>
using namespace std;
void VectorCreate(vector<vector<int>>& arr)
{
	cout<<"Enter numbers to contain vector;\n";
	arr.resize(15);
	for(int i=0;i<arr.size();i++)
	{
		arr[i].resize(2);
		for (int j = 0; j < 2; j++)
		{
			cin >> arr[i][j];
		}
	}
}
void RandomVectorCreate(vector<vector<int>>& arr)
{
	srand(time(NULL));
	arr.resize(15);
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i].resize(2);
		for (int j = 0; j < 2; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}
}
void VectorShower(vector<vector<int>> arr)
{
	cout<<"=== Vector ===\n";
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
int MakeLine(int x1,int y1,int x2,int y2,int x, int y)
{
	int A = y1-y2;
	int B = x2-x1;
	int C = (x1-x2)*y1 + (y2-y1)*x1;
	return A*x+B*y+C;
}
void PointCheck(vector<vector<int>>& arr,int&  zero_counter, int& mz_counter, int& bzero_counter)
{
	for(int i=0;i<arr.size();i++)
	{
		for(int j=arr.size()-1;j>0;j--)
		{
			if(j==i) continue;
			for(int z=0;z<arr.size();z++)
			{
				if(z==i || z==j) continue;
				int number=MakeLine(arr[i][0],arr[i][1],arr[j][0],arr[j][1],arr[z][0],arr[z][1]); //2548 meets
				if(number==0) zero_counter+=1;
				if(number<0) mz_counter+=1;
				if(number>0) bzero_counter+=1;
			}
		}
	}
}
int main()
{
	int choice,zero_counter=0, mz_counter=0, bzero_counter=0;
	vector<vector<int>> arr(15);
	cout<<"Choose method of containing: 1 - from keyboard, 2 - random numbers."<<endl;
	cin>>choice;
	if(choice==1) {VectorCreate(arr);}
	if(choice==2){ RandomVectorCreate(arr);}
	PointCheck(arr,  zero_counter,  mz_counter,  bzero_counter);
	if(zero_counter<=14 || bzero_counter<=14 || mz_counter<=14) cout<<"Incorrect because not all points lie on the same side of the line.\n";
	else cout<<"Correct all points lie on the same side of the line.\n";
	cout<<"Size of memory equals: "<<sizeof(arr)<<endl;
	VectorShower(arr);
	return 0;
}





