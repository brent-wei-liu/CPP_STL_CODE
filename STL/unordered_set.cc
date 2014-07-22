#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <tr1/unordered_set>
#include <queue> 
using namespace std;
struct Vector3D{
  uint32_t x;
  uint32_t y;
  uint32_t z;
 
  Vector3D(const uint32_t x,const uint32_t y,const uint32_t z):
  x(x),y(y),z(z)
  {}
 
  Vector3D():
  x(0),y(0),z(0)
  {}
};
 
typedef struct{
  inline size_t operator() (const Vector3D& v) const {
    return (v.x*73856093)^(v.y*19349663)^(v.z*83492791);
  }
} Vector3DHash;
 
typedef struct{
  inline bool operator() (const Vector3D& lhs, const Vector3D &rhs) const { 
    return (lhs.x==rhs.x)&&(lhs.y==rhs.y)&&(lhs.z==rhs.z);
  }
} Vector3DEq;
 
typedef tr1::unordered_set<Vector3D,
                            Vector3DHash,
                            Vector3DEq> vector_map_t;
 /*
struct Vector3D{
  uint32_t x;
  uint32_t y;
  uint32_t z;
 
  Vector3D(const uint32_t x,const uint32_t y,const uint32_t z):
  x(x),y(y),z(z) {}

  Vector3D():x(0),y(0),z(0){}

  size_t operator() (const Vector3D& v) const {
    return (v.x*73856093)^(v.y*19349663)^(v.z*83492791);
  }
 
  bool operator() (const Vector3D& lhs, const Vector3D &rhs) const { 
    return (lhs.x==rhs.x)&&(lhs.y==rhs.y)&&(lhs.z==rhs.z);
  }
 

};
 
 typedef tr1::unordered_set<Vector3D,
                            Vector3D,
                            Vector3D> vector_map_t;
*/ 
int main(int argc, char** argv) {
  const uint32_t MAX_DISTANCE = 1000;
  const size_t LOOP_COUNT = 100000;
  vector_map_t vectors;
  
  // This assumes a vector with x:0 y:0 z:0 will never exist
  // If this is not true use tr1/unordered_map !!!
  //vectors.set_empty_key(Vector3D());
  
  // Fill with some random vectors and keys
  for(size_t i=0;i<LOOP_COUNT;i++){
    Vector3D v( rand()%MAX_DISTANCE+1,
                rand()%MAX_DISTANCE+1,
                rand()%MAX_DISTANCE+1);
    vectors.insert(v);
  }
  
  // Display whole map
  vector_map_t::const_iterator it,ite;
  for( it=vectors.begin(),ite=vectors.end();it!=ite;++it){
    cout << "Vector with x: " << it->x <<" y: "<<it->y << " z: " << it->z << endl;
  }
  
  // Do some random lookups
  for(size_t i=0;i<LOOP_COUNT;i++){
    Vector3D v(  rand()%MAX_DISTANCE+1,
                 rand()%MAX_DISTANCE+1,
                 rand()%MAX_DISTANCE+1);
    vector_map_t::const_iterator it=vectors.find(v);
    if (it!=vectors.end()){
        printf("Found vector with x:%u y:%u z:%u\n",it->x , it->y , it->z);
    }
  }
    priority_queue<int> queue;
    unsigned nbuckets = vectors.bucket_count();
    for (unsigned i=0; i<nbuckets; ++i) {
        queue.push(vectors.bucket_size(i));
    }

    for( int i=0; i<20; i++){
        printf("top %d bucket size : %d\n",i,queue.top() );
        queue.pop();
    }

    cout << "size = " << vectors.size() << endl;
    cout << "bucket_count = " << vectors.bucket_count() << endl;
    cout << "load_factor = " << vectors.load_factor() << endl;
    cout << "max_load_factor = " << vectors.max_load_factor() << endl;
  return 0;
}



