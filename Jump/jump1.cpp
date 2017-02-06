/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.
*/
#include <iostream>
#include <vector>

using namespace std;

    bool canJump(vector<int>& nums) {
        //int n=nums.size();
        int maxReachable=0;
        bool retFlag=false;
        if(nums.size()==0)
            return false;
        else if(nums.size()==1)
            return true;
        for(int i=0;i<nums.size()-1; i++)
        {
            if(i+nums.at(i)>maxReachable)
                maxReachable=i+nums.at(i);
            if(i>=maxReachable)
            {
                 retFlag= false;
                 break;
            }
            if(maxReachable>=nums.size()-1)
            {
                retFlag= true;
                break;
            }
        }
        return retFlag;
    }

int main()
{	vector<int> nums;
	//Add the code to add the array in nums
	cout<<canJump(*nums)<<endl;
	return 0;
}
