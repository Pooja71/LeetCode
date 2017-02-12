/*Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

#include <iostream>
#include <vector>

using namespace std;

    void setZeroes(vector<vector<int>>& matrix) {
        int rowMax=0, colMax=0, r=-1, c=-1;
        rowMax=matrix.size();
        
        vector<int> vec=matrix[0];
        colMax=vec.size();
        for(int row=0; row<rowMax; row++)
        {
            for(int col=0;col<colMax;col++)
            {
                if(matrix[row][col]==0)
                {
                    if(-1==r && -1==c)
                    {
                        r=row; c=col;
                    }
                        matrix[r][col]=0;
                        matrix[row][c]=0;
                }   
            }
        }
        
        if(r!=-1 && c!=-1)
        {
        
        //setting the rows to zero except the one at r
        for(int i=r+1;i<rowMax;i++)
        {
            if(matrix[i][c]==0)
               for(int j=0;j<colMax;j++)
                    matrix[i][j]=0;
        }
        //setting columns to zero except col c
        for(int i=0;i<colMax;i++)
            if(i!=c and matrix[r][i]==0)
                for(int j=0;j<rowMax;j++)
                    matrix[j][i]=0;
        //Setting 'r'th row to zero
        for(int j=0;j<colMax;j++)
            matrix[r][j]=0;
        //Setting 'c'th column to zero
        for(int j=0;j<rowMax;j++)
            matrix[j][c]=0;
        }
    }

int main()
{
	vector< vector<int> > vec;
	/*Write code to fetch input*/
	setZeroes(*vec);
	return 0;
}
