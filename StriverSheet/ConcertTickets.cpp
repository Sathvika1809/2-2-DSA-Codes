#include <set>
#include <iostream>

using namespace std;
int main(){
    long long n,m;
    multiset<long long> s;
    cin>>n>>m;
    for(long long i =0;i<n;i++){
        long long price;
        cin>>price;
        s.insert(price);
    }
    for(long long i=0;i<m;i++){
        long long maxPrice;
        cin>>maxPrice;
        auto it = s.upper_bound(maxPrice);
        if(it == s.begin()){
            cout<<"-1"<<endl;
        }else{
            --it;
            cout<<*it<<endl;
            s.erase(it);
        }
        
    }
    return 0;
}