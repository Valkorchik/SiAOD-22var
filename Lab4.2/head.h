#ifndef HEAD_H
#define HEAD_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct schedule
{
	int group_id;
	int discipline_id;
	string day_of_week;
	int lecture_id;
	int class_id;
};
struct lessons
{
	int n = 0;
	schedule* data=new schedule[n];
};

lessons exc;
string discipline[5]
		{
				"Math",
				"Economy",
				"Science",
				"Language",
				"History"
		};
bool Auditory_Check(lessons* exc, int& choice)
{
	for(int i=0;i<exc->n;i++)
	{
		if(exc->data[i].day_of_week==exc->data[exc->n].day_of_week && exc->data[i].lecture_id==exc->data[exc->n].lecture_id && exc->data[i].class_id==exc->data[exc->n].class_id)
		{
			cout<<"Enter correct number of auditory\n";
			return true;
		}
		return false;
	}
}
void Date_Input(lessons* exc, int& index)
{
	int choice;
	string day;
	cout<<"Enter group number\n";
	cin>>choice;
	exc->data[index].group_id=choice;
	cout<<"Enter day of week \n";
	cin>>day;
	exc->data[index].day_of_week= day;
	cout<<"Enter number of lesson\n";
	cin>>choice;
	exc->data[index].lecture_id=choice;
	cout<<"Enter auditory number\n";
	cin>>choice;
	while(Auditory_Check(exc,choice))
	{
		cin>>choice;
	}
	exc->data[index].class_id=choice;
}
void Schedule_Sort(lessons* exc)
{
	for(int i=0;i<exc->n;i++)
	{
		for(int j=i+1;j<exc->n;j++)
		{
			if(i==j) continue;
			if(exc->data[i].day_of_week==exc->data[j].day_of_week)
			{
				exc->data[exc->n+1]=exc->data[i+1];
				exc->data[i+1]=exc->data[j];
				exc->data[j]=exc->data[exc->n+1];
			}
		}
	}
}
void Schedule_Insert(lessons* exc)
{
	for(int i=exc->n;i>0;i--)
	{
		exc->data[i]=exc->data[i-1];
	}
	exc->n+=1;
	int ind=0, choice;
	cout<<"Enter new note in schedule\n";
	cout<<"Enter discipline id(0:4) \n";
	cin>>choice;
	exc->data[ind].discipline_id=choice;
	Date_Input(exc,ind);
}
void Date_Erase(lessons* exc)
{
	int id, counter=0;
	cout<<"Enter discipline id to erase notes\n";
	cin>>id;
	for(int i=0;i<exc->n;i++)
	{
		if(id==exc->data[i].discipline_id)
		{
			counter+=1;
			for(int j=i;j<exc->n-counter;j++)
			{
				exc->data[j]=exc->data[j+1];
			}
		}
	}
	exc->n=exc->n-counter;
}
void Date_Output(lessons* exc)
{
	cout<<"Schedule of University: \n";
	for(int i=0;i<exc->n;i++)
	{
		cout<<"Day: "<<left<<setw(7)<<exc->data[i].day_of_week<<endl;
		cout<<"Group: "<<left<<setw(7)<<exc->data[i].group_id<<endl;
		cout<<left<<setw(3)<<exc->data[i].lecture_id<<left<<setw(9)<<discipline[exc->data[i].discipline_id]<<" ID:";
		cout<<left<<setw(3)<<exc->data[i].discipline_id<<left<<setw(4)<<"Class: "<<exc->data[i].lecture_id<<endl<<endl;
	}
}
void resize(lessons* exc)
{
	schedule* tempArray = new schedule[exc->n + 1];
	for (int i = 0; i < exc->n; i++)
	{
		tempArray[i] = exc->data[i];
	}
	delete[] exc->data;
	exc->data = tempArray;
}
#endif