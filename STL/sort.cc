#include <iostream>  
#include <stdio.h>  
#include <queue>  
#include <stdlib.h>  
#include <functional>  
#include <algorithm>  
using namespace std;  
class Node{  
public:       
    int x, y;  
    Node( int a= 0, int b= 0 ):x(a),y(b) {}  
    bool operator<(Node m)const{  
        return x<m.x;  
    }  
};  
   
/* 
重载可以放在外面，不用const修饰  
bool operator<( Node a, Node b ){ 
    if( a.x== b.x ) return a.y> b.y; 
    return a.x> b.x;  
} 
*/ 
   
int main()  
{  
    vector<Node> qq;  
       
       
    for( int i= 0; i< 10; ++i ){  
        qq.push_back( Node( rand(),rand() ) );  
    }  
    sort(qq.begin(),qq.end());  
    printf("The result of qq is :\n");  
    for(int i=0;i<qq.size();i++){  
        printf("%d %d\n",qq[i].x,qq[i].y);  
    }     
    return 0;  
}
