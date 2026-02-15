#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<pair<int,int>>st;
    int n;
    scanf("%d",&n);
    while(n--){
    int new_elem;
    scanf("%d",&new_elem);

    int new_min = st.empty()?new_elem:min(new_elem,st.top().second);
    st.push({new_elem,new_min});
    }
    // while(!(st.empty())){
    //     printf("%d ",st.top().first,st.top().second);
    //     st.pop();
    // }
    printf("\n");
    //Removing an element
    int removed_elem = st.top().first;
    st.pop();
    int minimum = st.top().second;
    printf("%d\n",removed_elem);
    printf("%d\n",minimum);
    while(!(st.empty())){
        printf("%d %d",st.top().first,st.top().second);
        printf("\n");
        st.pop();
    }
    deque<int>q;
    int n;
    scanf("%d",&n);
    while(n--){
    int new_elem;
    scanf("%d",&new_elem);
    while(!q.empty()&&q.back()>new_elem){
        q.pop_back();
     }
    q.push_back(new_elem);
    }
    int min = q.front();
    int remove_element;
    scanf("%d",&remove_element);
    if(!q.empty()&&q.front == remove_element){
        q.pop(front());
    }


    return 0;
}

