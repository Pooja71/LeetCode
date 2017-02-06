/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int trap(vector<int>& height) {
    int i=0, maxLeft=0, maxRight=0, water=0;
    vector<int> leftHeight;
    for(i=0;i<height.size();i++)
    {
        leftHeight.push_back(maxLeft);
        if(maxLeft<height.at(i))
            maxLeft=height.at(i);
    }
    for(i=height.size()-1;i>=0;i--)
    {
        int min=(leftHeight.at(i)<=maxRight)?leftHeight.at(i):maxRight;
        water+=(min-height.at(i)<0)?0:min-height.at(i);
        if(maxRight<height.at(i))
            maxRight=height.at(i);
    }
    return water;
     
}

int main()
{
	vector<int> height;
	/*
	Add the logic to accept
	*/
	trap(*height);
	return 0;
}
