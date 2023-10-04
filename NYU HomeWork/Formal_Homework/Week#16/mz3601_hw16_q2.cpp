#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

template<class T>
class Queues{
    vector<T> q;
    int start;
public:
    Queues(): start(0){} //check the vector
    //Initializes the object to an empty stack.
    
    void push(T x){q.push_back(x);}
    //Postcondition: x has been added to the stack

    void pop(){
        if(q.empty()){
          cout << "Queue is empty.\n";
          exit(1);}
        else  
          start ++;
    }
    //Precondition: the stck is not empty.
    //Removes the top symbol from the stack.

    int front(){
        if(q.empty()){
          cout << "Queue is empty.\n";
          exit(1);
        }
        else
            return q[start];
    }
    //Returns the front most element of the stack

    int back(){
        if(q.empty()){
          cout << "Queue is empty.\n";
          exit(1);
        }
        else
          return q[q.size()-1];}
    //Returns the back most element of the stack
    
    int size(){
        if(q.empty()){
          cout << "Queue is empty.\n";
          exit(1);
        }
        else
          return q.size() - start;}
    //Returns the size of the stack

    bool empty() const{return (start >= q.size()-1);}
    //Returns true if the stack is empty. Returns false otherwise

    void clear(){
      q.clear(); 
      q.size == 0;
    }
};

int main(){
    Queues<int> a;

    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.pop();
    a.pop();
    cout<<a.front()<<endl;
    cout<<a.size()<<endl; 
    cout<<a.back()<<endl;
    if(a.empty())
     cout<<"empty\n";
     else cout<<"not empty\n";

    return 0;
}
