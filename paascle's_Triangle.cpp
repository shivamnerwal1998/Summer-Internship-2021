/*
118. Pascal's Triangle
Easy

3017

143

Add to List

Share
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>>arr ; 
        for( int i = 0 ; i < numRows ; i++ ){
             vector<int> data; 
            for( int j = 0 ; j <= i ; j++ )
            {
                
                if( j == 0  )
                    data.emplace_back(1) ;
                else if( j == i )
                    data.emplace_back(1) ;
                else
                {
            
                    int temp = ( arr[i-1][j-1] + arr[i-1][j] ) ;
                    data.emplace_back(temp) ;
                
                    
                }
                
            }
            arr.emplace_back( data ) ; 
        }
        return arr ;
        
    }
};
