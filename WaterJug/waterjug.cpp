
/*
You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly z litres using these two jugs.
If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.
Operations allowed:
Fill any of the jugs completely with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
Example 1: (From the famous "Die Hard" example)
Input: x = 3, y = 5, z = 4
Output: True


Example 2:
Input: x = 2, y = 6, z = 5
Output: False
*/

#include <iostream>

using namespace std;

bool canMeasureWater(int x, int y, int z) {
if(0==z)
    return true;
if(0==x && 0==y)
    return false;
if(x==0 || y==0)
{
    if(x+y==z)
        return true;
    else
        return false;
}
if(z>x+y)
    return false;
   while(x!=y)
   {
       if(x<y)
            y-=x;
        else
            x-=y;
   }
   if(z%x==0)
        return true;
    else
        return false;
}

int main()
{
	int x,y,z;
	//Add code to take inputs
	cout<<canMeasureWater(x,y,z)<<endl;
	return 0;
}
