/*===================================================
         * 
        * * 
       * * * 
      * * * * 
     * * * * * 
    * * * * * * 
   * * * * * * * 
  * * * * * * * * 
 * * * * * * * * * 
=====================================================*/
#include <iostream>
using namespace std;
int main()
{
    int n=10;
	for(int i=0; i<n; i++)
    {
        for(int j=0;j<n-i;j++)
        {
            cout<<" ";
        }
        for(int s=n-1;s>=n-i;s--)
        {
            cout<<"* ";
        }
        cout<<endl;
    }

	return 0;
}
