/*You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise). You have to do it in-place.
Solution:
Consider each concentric square at a time and rotate all elements in that square ring before going deeper. When you displace one element to put in its right place, you consecutively displace all the other along the four sides.
*/
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    if(matrix.size()==1)
        return;
        int n=matrix.size();
    int limit=(n%2==0)?(n/2)-1:((n-1)/2)-1;
    std::cout<<"limit: "<<limit;
    for(int i=0; i<=limit; i++){
        for(int j=i;j<=n-i-2;j++){
            int temp=matrix.at(i).at(j);
            std::cout<<"temp: "<<temp<<endl;
            matrix[i][j]=matrix.at(n-1-j).at(i);
            matrix.at(n-1-j).at(i)=matrix.at(n-1-i).at(n-1-j);
            matrix.at(n-1-i).at(n-1-j)=matrix.at(j).at(n-1-i);
            matrix.at(j).at(n-1-i)=temp;
        }
    }
     
}
}

int main()
{	
	vector< vector<int> > matrix;
	/* Write code to give the input to the function */
	rotate(*matrix);
	return 0;
}
