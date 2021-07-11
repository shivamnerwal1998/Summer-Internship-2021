
class Solution {
public:
    int maxProfit(vector<int>& arr) 
    {
        int max_Profit = 0 ; 
        int minElem  = INT_MAX ; 
        for( int i = 0 ; i <= arr.size()-1 ; i++ )
        {
            minElem = min( minElem , arr[i] ) ;
            max_Profit = max ( arr[i]- minElem , max_Profit); 
        }
        return max_Profit ; 
    }
};
