#include "head.h"
int main()
{
	int choice;
	while(true)
	{
		cout<<"Enter discipline id(0:4) or enter -1 to stop input \n";
		cin>>choice;
		if(choice==-1) break;
		exc.data[exc.n].discipline_id=choice;
		Date_Input(&exc,exc.n);
		exc.n+=1;
		resize(&exc);
	}
	Schedule_Sort(&exc);
	Schedule_Insert(&exc);
	Date_Erase(&exc);
	Schedule_Sort(&exc);
	Date_Output(&exc);
	delete[] exc.data;
}