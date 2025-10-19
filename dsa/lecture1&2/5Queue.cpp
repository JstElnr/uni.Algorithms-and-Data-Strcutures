#include<iostream>
#include<queue>
using namespace std;

void demo_stl_queue(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout<<q.size()<<endl;
    cout<<q.front()<<endl;
    //REMOVE 
    while(!q.empty()){
        cout<<"Removing: "<<q.front()<<endl;
        q.pop();
    }
}