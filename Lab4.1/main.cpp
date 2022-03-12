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
		if(exc.n>=exc.N-1) break;
		exc.n+=1;
	}
	Schedule_Sort(&exc);
	Schedule_Insert(&exc);
	Date_Erase(&exc);
	Schedule_Sort(&exc);
	Date_Output(&exc);
}