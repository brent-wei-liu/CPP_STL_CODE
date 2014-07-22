// unordered_set::begin/end example
#include <iostream>
#include <map>
#include <tr1/unordered_map> 
#include <string>
#include "time.h"



//you can typedef
tr1::unordered_map<int, int> Hash;
using namespace std;
int main ()
{
    {    
    time_t first_time = time(0); 
    tr1::unordered_map<int, int> test_hash;  
    for (int i = 0; i < 5000000; i++)  
    {  
        test_hash.insert(std::pair<int, int>(i, i));  
    }  
    cout << test_hash.size() << endl;  

   time_t second_time = time(0);  
  
    for (int i = 0; i< 5000001; ++i)  
    {  
        tr1::unordered_map<int, int>::iterator iter = test_hash.find(i);  
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
    map<int, int> test_hash;  
    for (int i = 0; i < 5000000; i++)  
    {  
        test_hash.insert(std::pair<int, int>(i, i));  
    }  
    cout << test_hash.size() << endl;  
  
    time_t second_time = time(0);  
  
    for (int i = 0; i< 5000001; ++i)  
    {  
        map<int, int>::iterator iter = test_hash.find(i);  
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

