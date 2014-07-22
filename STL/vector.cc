#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Point
{
public:
    Point(double a, double b):x(a),y(b){}
    double x,y;
};

bool comp(const Point &a, const Point &b)
{
    if(a.x == b.x)  return a.y < b.y;
    return a.x < b.x;
}
vector<Point> v;


int
main()
{
    v.push_back(Point(1.0,2.0));
    v.push_back(Point(1.0,2.1));
    v.push_back(Point(1.0,2.2));
    v.push_back(Point(1.2,2.4));
    v.push_back(Point(3.2,2.0));
    v.push_back(Point(5.0,3.0));
    v.push_back(Point(5.0,4.0));
    v.push_back(Point(2.0,5.0));

    for(int i=0; i<v.size(); i++){
        cout<<"<"<<v[i].x<<", "<<v[i].y<<"> ";
    }
    cout<<endl;
        
    sort(v.begin(), v.end(),comp);
    for(int i=0; i<v.size(); i++){
        cout<<"<"<<v[i].x<<", "<<v[i].y<<"> ";
    }
    cout<<endl;
   
    make_heap(v.begin(), v.end(),comp);
    cout<<"heap:"<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<"<"<<v[i].x<<", "<<v[i].y<<"> ";
    }
    cout<<endl;


    return 0;
}
