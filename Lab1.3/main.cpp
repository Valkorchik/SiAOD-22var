#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> VectorCreate(int);
vector<int>VectorRandomFiller(vector<int>);
void VectorShower(vector<int>);
int IndexSearcher(vector<int>&);
string ElementInsert(vector<int>&);
string ElementErase(vector<int>&);
int main()
{

    int n;
    cout<<"Enter array size: \n";
    cin>>n;
    vector<int> arr = VectorCreate(n);
    VectorShower(arr);
    cout<<"First ex (-1 code = index not found): \n";
    cout<<IndexSearcher(arr)<<endl;
    cout<<"Second ex: \n"<<ElementInsert(arr);
    VectorShower(arr);
    cout<<"Third ex: \n"<<ElementErase(arr);
    VectorShower(arr);

}
vector<int> VectorCreate(int n)
{
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    return arr;
}
vector<int>VectorRandomFiller(vector<int> arr)
{
    srand(time(NULL));
    for(int i=0;i<arr.size();i++)
    {
        arr[i]=rand()%100+1;
    }
    return arr;
}
void VectorShower(vector<int> arr)
{
    cout<<"Array: \n";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int IndexSearcher(vector<int>& arr)
{
    vector<int> local_arr=arr;
    int counter=0;
    int dcounter=0;
    for(int i=1;i<arr.size();i++)
    {
        while(local_arr[i])
        {
            int d=arr[i]%10;
            if(i%d==0)
            {
                counter+=1;
            }
            local_arr[i]=local_arr[i]/10;
            dcounter+=1;
        }
        if(counter==dcounter)
        {
            return i;
        }
        dcounter=0;
        counter=0;
    }
    return -1;
}
string ElementInsert(vector<int>& arr)
{
    int elem;
    cout<<"Enter element: \n";
    cin>>elem;
    vector<int> local_arr=arr;
    int counter=0;
    int dcounter=0;
    for(int i=0;i<arr.size();i++)
    {
        while (local_arr[i])
        {
            int d = arr[i] % 10;
            if (elem % d == 0)
            {
                counter += 1;
            }
            local_arr[i] = local_arr[i] / 10;
            dcounter += 1;
        }
        if (counter == dcounter) {
            arr.insert(arr.begin()+i+1,elem);
            return "Successfully inserted\n";
        }
        dcounter=0;
        counter = 0;
    }
    return "No index found\n";
}
string ElementErase(vector<int>& arr)
{
    for(int i=0;i<arr.size();++i)
    {
        if(arr[i]%3==0)
        {
            arr.erase(arr.begin()+i);
        }
    }
    return "Elements erased\n";
}
