/*

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.


Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.


*/
#include<iostream>
#include<vector>
using namespace std ;
int buy_sell_stock( vector<int> arr )
{
    int max_profit =  0   ;
    for( int i = 0 ; i<= arr.size()-1 ; i++)
    {
        for( int j = i+1 ; j <= arr.size()-1 ; j++)
        {
            if( arr[j] > arr[i] ){

                int diff = (arr[j] - arr[i]) ;
                max_profit = max( diff , max_profit ) ;

            }


        }
    }
    return max_profit ;

}

int main()
{
    vector<int> vec ;
    cout<< "\nEnter the number of Elements " ;
    int num ;
    cin >> num ;
    cout<< "\nEnter the elements of Array" ;
    for( int i = 0 ; i <= num-1 ; i++ ){
        int element ;
        cin >> element ;
        vec.emplace_back( element )   ;
    }
    cout << buy_sell_stock( vec ) ;

}
