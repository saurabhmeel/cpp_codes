#include<iostream>
#include<queue>

using namespace std;

typedef pair<int,int> ii;

int main(){
    ii ends;
    priority_queue<pair<int,ii>>Edgelist;
    pair<int,ii>show;
    
    ends = ii(1,3);
    Edgelist.push(pair<int,ii>(2,ends));

    ends = ii(3,4);
    Edgelist.push(pair<int,ii>(5,ends));

    priority_queue<pair<int,ii>>temp;

    temp = Edgelist;

    cout<<temp.top().first<<endl;
    cout<<temp.top().second.first<<" "<<temp.top().second.second<<endl;
    cout<<endl;
    temp.pop();

    

    cout<<temp.top().first<<endl;
    cout<<temp.top().second.first<<" "<<temp.top().second.second<<endl;
    temp.pop();

}