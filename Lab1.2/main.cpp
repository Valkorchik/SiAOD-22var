#include <iostream>
#include <string>
using namespace std;
int* ArrayCreate(int*,const int&);
int* ArrayRandomFiller(int*, const int&);
void ArrayShower( const int& , const int*);
int IndexSearcher(const int*, const int&);
string ElementInsert(int*, int&);
string ElementErase(int*, int&);
int main()
{

    int n;
    cout<<"Enter array size: \n";
    cin>>n;
    int* arr=new int[n];
    ArrayShower(n,ArrayCreate(arr,n));
    cout<<"First ex (-1 code = index not found): \n";
    cout<<IndexSearcher(arr,n)<<endl;
    cout<<"Second ex: \n"<<ElementInsert(arr,n);
    ArrayShower(n,arr);
    cout<<"Third ex: \n"<<ElementErase(arr,n);
    ArrayShower(n,arr);
}
int* ArrayCreate(int* arr,const int& size)
{
    int arr_value;
    for(int i=0;i<size;i++)
    {
        cin>>arr_value;
        arr[i]=arr_value;
    }
    return *&arr;
}
int* ArrayRandomFiller(int* arr,const int& size)
{
    srand(time(NULL));
    for(int i=0;i<size;i++)
    {
        arr[i]=rand()%100+1;
    }
    return *&arr;
}
void ArrayShower(const int& size,const int* arr)
{
    cout<<"Array: \n";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int IndexSearcher(const int* arr, const int& size)
{
    int* local_arr=new int[size];
    for(int copy=0;copy<size;copy++)
    {
        local_arr[copy]=arr[copy];
    }
    int counter=0;
    int dcounter=0;
    for(int i=1;i<size;i++)
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
string ElementInsert(int* arr, int& size)
{
    int elem;
    cout<<"Enter element: \n";
    cin>>elem;
    int* local_arr=new int[size];
    for(int copy=0;copy<size;copy++)
    {
        local_arr[copy]=arr[copy];
    }
    int counter=0;
    int dcounter=0;
    for(int i=0;i<size;i++) {
        while (local_arr[i]) {
            int d = arr[i] % 10;
            if (elem % d == 0) {
                counter += 1;
            }
            local_arr[i] = local_arr[i] / 10;
            dcounter += 1;
        }
        if (counter == dcounter) {
            local_arr[i+1]=arr[i+1];
            arr[i+1]=elem;
            for(int j=i+1;j<size+1;j++)
            {
                local_arr[j+1]=arr[j+1];
                arr[j+1]= local_arr[j];
            }
            size=size+1;
            return "Successfully inserted\n";
        }
        dcounter=0;
        counter = 0;
    }
    return "No index found\n";
}
string ElementErase(int* arr, int& size)
{
    for(int i=0;i<size;++i)
    {
        if(arr[i]%3==0)
        {
            for(int j=i;j<size;j++)
            {
                arr[j]=arr[j+1];
            }
            i-=1;
            size=size-1;
        }
    }
    return "Elements erased\n";
}
