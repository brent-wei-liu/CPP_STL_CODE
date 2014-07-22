#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
 
using namespace std;
class Node{
public:
    int x, y;
    Node( int a= 0, int b= 0 ):x(a),y(b) {}
    bool operator<(Node m)const{
        if( x == m.x)
            return y < m.y;
        return x<m.x;
    }
    void print()
    {
        cout<<"("<<x<<" ,"<<y<<")"<<endl;
    }
};

class Heap{
private:
    vector<Node> heap;
public:
    void Push( Node val) {
        heap.push_back(val);
        push_heap(heap.begin(), heap.end());
    }
    Node Pop() {
        Node val = heap.front();
         
        //This operation will move the smallest element to the end of the vector
        pop_heap(heap.begin(), heap.end());
     
        //Remove the last element from vector, which is the smallest element
        heap.pop_back();  
        return val;
    }
    void print()
    {
        vector<Node>::iterator it = heap.begin();
        for(; it!=heap.end(); it++){
            it->print();
        }
    }
};
int main() {
    Heap h;
    h.Push( Node(1,2));
    h.Push( Node(2,2));
    h.Push( Node(4,3));
    h.Push( Node(2,3));
    h.Push( Node(1,3));
    h.Push( Node(2,7));
    h.Push( Node(1,4));
    h.Push( Node(2,1));
    h.print(); 
    return 0;
}

