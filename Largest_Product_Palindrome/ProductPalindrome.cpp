/***************************************************

Find the largest palindrome made from the product of two n-digit numbers.
Since the result could be very large, you should return the largest palindrome mod 1337.
Example:
Input: 2
Output: 987
Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
Note:
The range of n is [1,8].

***********************************************************/

#include <math.h>
#include <iostream>

using namespace std;

class Solution {
public:
       unsigned long int Reverse(unsigned long int num)
    {
        unsigned int reverse=0;
        while(num>0)
        {
            reverse=reverse*10+(num%10);
            num/=10;
        }
        return reverse;
    }
    

    int largestPalindrome(int n) {
        unsigned long int mod, highest, product=0, reverse,max_product=0, num=0;
        if(n==1)
            return 9;
        highest=pow(10,n)-1;
        mod=pow(10,n);
        max_product=highest*highest;
        if(max_product==Reverse(max_product))
            return max_product%1337;
        else
        {
            unsigned int left=max_product/mod;
            unsigned int right=max_product%mod;
            if(left>right)
                left--;
            max_product=left*mod+Reverse(left);
            while(left!=mod/10)
            {
                for(int i=highest;i>max_product/i;i--)
                    if(max_product%i==0)
                        return (max_product%1337);
                left--;
                max_product=left*mod+Reverse(left);
            }
        }
        return max_product%1337;
    }
};

int main()
{
    Solution sol;
    int n=0;
    cout<<"Enter n: ";
    cin>>n;
    int largest_pal=sol.largestPalindrome(n);
    cout<<"Answer: "<<largest_pal<<endl;
    return 0;
}
