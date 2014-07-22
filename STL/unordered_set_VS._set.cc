#include <iostream>
#include <set>
#include <tr1/unordered_set> 
#include <string>
#include "time.h"
using namespace std;

typedef tr1::unordered_set<int> HashSet;
typedef set<int> Set;

int main ()
{
    {
    time_t first_time = time(0); 
    HashSet test_hash; 
    //50M integer, really fast
    for (int i = 0; i < 5000000; i++)  
    {  
        test_hash.insert( i );  
    }  
    cout << test_hash.size() << endl;  

   time_t second_time = time(0);  
  
    for (int i = 0; i< 5000001; ++i)  
    {  
        HashSet::iterator iter = test_hash.find(i);  
        if (iter == test_hash.end())  
        {  
            cout << "false" << endl;  
        }  
    }  
    time_t third_time = time(0);  
    cout << "second - first " << second_time - first_time << endl;  
    cout << "third - second " << third_time - second_time << endl; 
    }
    
    {  
    time_t first_time = time(0);  
    Set test_hash;  
    for (int i = 0; i < 5000000; i++)  
    {  
        test_hash.insert( i );  
    }  
    cout << test_hash.size() << endl;  
  
    time_t second_time = time(0);  
  
    for (int i = 0; i< 5000001; ++i)  
    {  
        Set::iterator iter = test_hash.find(i);  
        if (iter == test_hash.end())  
        {  
            cout << "false" << endl;  
        }  
    }  
    time_t third_time = time(0);  
    cout << "second - first " << second_time - first_time << endl;  
    cout << "third - second " << third_time - second_time << endl;  
    }  

    return 0;
}

