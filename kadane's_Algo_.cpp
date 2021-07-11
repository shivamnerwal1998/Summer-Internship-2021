#include<iostream>
#include<vector>
using namespace std ;

int MaxSum( vector<int> vec )
{
   int meh =  0 ;
   int msf = INT_MIN ;
   for( int i = 0 ; i <= vec.size()-1 ; i++ )
   {
       meh += vec[i] ;
       if( meh < vec[i] ) meh = vec[i] ;
       if( msf < meh   ) msf = meh ;
   }
   return msf ;

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
    cout << MaxSum( vec ) ;

}
