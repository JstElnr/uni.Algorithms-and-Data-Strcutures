//c++ built-in stack
#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> st;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);

    cout<<st.top()<<endl;//60
    st.pop();
    st.pop();
    cout<<st.top()<<endl;//40
    cout<<st.size()<<endl;
    cout<<st.empty();
    return 0;
}

//Custom stack implementation:
class Stack{
    public:
    Node *top;
    int sz;

    Stack(){
        top=NULL;
        sz=0;
    }

    void push(int data){
        Node *node=new Node(data);
        node->next=top;
        top=node;
        sz++;
    }

    void pop(){
        if(top!=NULL){
            top=top->next;
            sz--;
        }
    }

    int size(){
        return this->sz;
    }

    bool empty(){
        return (sz==0);
    }
};

//Classic Problem: Balanced Brackets Check if brackets are properly balanced: (), [], {}

#include<iostream>
#include<stack>
using namespace std;

    bool is_ok(string s){
        stack<char> st;

        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                if(s[i]=='}' && st.top()!='{'){
                    return false;
                }
                if(s[i]==']' && st.top()!='['){
                    return false;
                }
                if(s[i]==')' && st.top()!='('){
                    return false;
                }
                st.pop();
            }
        }
        return (st.empty());
    }
    int main(){
        string s;
        cin>>s;
        if(is_ok(s)) cout<<"YES";
        else cout<<"NO";
        return 0;
    }