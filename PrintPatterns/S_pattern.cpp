
/*==================================================

print the bellow pattern

****
*   
*   
****
   *
   *
****


Hintb = use bellow conditions to print the specific line of star 
                i==0
              **********
       j==0   *        *  i==4
              *        *
              **********
                 j==4
========================================================*/

#include <iostream>
using namespace std;
int main()
{
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			if(i==0 || j==0|| i==3)
			{
				cout<<"*";

			}
			else cout<<" ";

		}
		cout<<endl;
	}
	for(int i=1; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			if(i==3 || j== 3)
			{
				cout<<"*";

			}
			else cout<<" ";

		}
		cout<<endl;
	}
	return 0;
}
