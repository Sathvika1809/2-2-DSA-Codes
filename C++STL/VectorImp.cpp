//std::vector
/*
1.std::vector is a sequence container and also known as Dynamic Array or ArrayList
2.Its size can grow or shrink dynamically and no need to provide size at compile time
Element Access
at(),[],front(),back(),data()
MODIFIERS:
insert(),emplace(),push_back(),emplace_back(),pop_back(),resize(),swap(),erase(),clear()
*/
/*
all containers support insert and emplace operation to store data
2.Emplace is used to construct object in-place and avoids unnecessary copy of objects
3.Insert and Emplace is equal for primitive data types but when we deal with heavy objects
//we should use emplace if we can for efficiency 
*/
#include <iostream>
#include <vector>
using namespace std;

class A{
    public:
    int x;
    A(int x=0): x{x} {cout<<"Construct"<<endl; };
    A(const A&rhs){ x = rhs.x;cout<<"Copy"<<endl;}
};
bool operator < (const A& lhs,const A& rhs){return lhs.x < rhs.x;}

int main(){
    //Declarations
    vector<int>arr1;
    vector<int>arr2(5,20)//size 5 initially and all initialised to 0
    vector<int>arr3={1,2,3,4,5};//initialiser List
    vector<int>arr4{1,2,3,4,5};
    //Accessing Elements
    arr2[3]=10;//But this gives a garbage value(Not Exception Safe)
    arr2.at(3)=10;//Exception of out of bound case
    arr2.front()// ->first element of array
    arr2.back()//->last element of array
    arr2.data()//ptr of array inside vector class
    vector<int>vec;
    //push_back implementation
    //vec.reserve(1000)//Capacity will be 1000
    //vec.resize()
    for(int i=0;i<32;i++){
        vec.push_back(i);
        cout<<"Size:"<<vec.size()<<"Capacity:"<<vec.capacity()<<endl;
    }
    //insert and emplace
    set<A>Set;
    Set.insert(A(1));
    Set.emplace(2);
    return 0;
}
