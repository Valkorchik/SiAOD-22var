#include <iostream>
#include <vector>
using namespace std;
vector<int> VectorCreate(int);
void VectorShower(vector<int>);
int IndexSearcher(vector<int>&);
string ElementInsert(vector<int>&);
string ElementErase(vector<int>&);
int main()
{

    int n;
    cout<<"Enter array size: \n";
    cin>>n;
    if(n<0)
    {
        cout<<"Wrong size"<<endl;
        return 0;
    }
    vector<int> arr = VectorCreate(n);
    VectorShower(arr);
    cout<<"First ex (-1 code = index not found): \n";
    cout<<IndexSearcher(arr)<<endl;
    cout<<"Second ex: \n"<<ElementInsert(arr);
    VectorShower(arr);
    cout<<"Third ex: \n"<<ElementErase(arr);
    VectorShower(arr);

}
vector<int> VectorCreate(int n) //Создание вектора
{
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    return arr;
}
void VectorShower(vector<int> arr) //Вывод элементов вектора
{
    cout<<"Array: \n";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int IndexSearcher(vector<int>& arr) //Нахождение индекса по условию
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
string ElementInsert(vector<int>& arr) //Вставка элемента
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
string ElementErase(vector<int>& arr) //Удаление элементов из вектора
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
