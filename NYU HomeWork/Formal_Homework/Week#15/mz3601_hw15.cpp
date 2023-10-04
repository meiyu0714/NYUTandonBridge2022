#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
struct ListNode{
    string name;
    double pay;
    double owe;
    ListNode* link;
};

typedef ListNode* NodePtr;

void head_insert(NodePtr& the_head, string the_name, double amount);
//Precondition: The pointer variable head points to 
//the head of a linked list
//Postcondition: A new Node containing name, pay and own(=0)
//has been added at the head of the linked list

double average(const NodePtr& head, int count);
//Precondition: The pointer variable head points to 
//the head of a linked list and count is not zero
//Postcondition: calculate the average of head->pay

void amount_owed(NodePtr& head, double average); 
//Precondition: The pointer variable head points to 
//the head of a linked list and average has value
//Postcondition: calculate owed = average - pay;
//if owe == 0, cout<<he/she is fine

void list_to_vector(const NodePtr& head, vector<ListNode>& list);

bool cmp(ListNode s1, ListNode s2);

int main(){
    ifstream in_stream;
    string file_name;

    cout<<"Enter the filename: ";
    cin>>file_name;

    in_stream.open(file_name);
    if(in_stream.fail()){
        cout<<"Input file opening failed.\n";
        exit(1);
    }

    NodePtr head; 
    head = new ListNode;
    double amount;
    string name;
    char space;
    int member_count = 0;

    while(in_stream>>amount)
    {
        in_stream.ignore(66,' ');//in case name include space before them
        getline(in_stream, name);
        if(member_count == 0){
            head->name = name;
            head->pay = amount;
            head->owe = 0;
            head->link = nullptr;
        }
        else{
            head_insert(head, name, amount);
        }
        member_count ++;
    }//order of nodes is reversed.

    //calculate the average number
    double ave_amount = average(head, member_count);
    
    //calculate the owe. if owe = 0, cout he/she is fine
    amount_owed(head, ave_amount);
    
    //nested list to vector
    vector<ListNode> list;
    list_to_vector(head, list);

    //sort by owe: positive to negative big to small
    sort(list.begin(), list.end(), cmp);

    //do the calculation
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(6);

    int start = 0, end = list.size() - 1;
    while(start < end)
    {
        double balance = list[start].owe + list[end].owe;
        if(balance < 0){
            cout<<list[start].name<<", you give "<<list[end].name<<" $"
                <<list[start].owe<<endl;
            list[end].owe = balance;
            start ++;    
        }
        else if(balance == 0){
            cout<<list[start].name<<", you give "<<list[end].name<<" $"
                <<list[start].owe<<endl;
            start ++;
            end --;    
        }
        else{//balance > 0
            cout<<list[start].name<<", you give "<<list[end].name<<" $"
                <<(list[end].owe * (-1))<<endl;
            list[start].owe = balance;    
            end --;
        }
    }
    
    cout.precision(2);

    cout<<"In the end, you should all have spent arount $"<<ave_amount<<endl;
    in_stream.close(); 

    return 0;
    
}

void head_insert(NodePtr& the_head, string the_name, double amount){
    NodePtr temp_ptr;
    temp_ptr = new ListNode;

    temp_ptr -> pay = amount;
    temp_ptr -> name = the_name;
    temp_ptr -> owe = 0;

    temp_ptr -> link = the_head;
    the_head = temp_ptr;
}

double average(const NodePtr& head, int count){
    if(count == 0){
        return 0;
    }
    else{
        NodePtr iter;
        double overall_payment = 0;
        for(iter = head; iter != nullptr; iter = iter->link){
            overall_payment = (iter->pay) + overall_payment;
        }
        return overall_payment/count;
    }
}

void amount_owed(NodePtr& head, double average){
    NodePtr iter;
    for(iter = head; iter != nullptr; iter = iter->link){
        iter->owe = average - iter->pay;
        if(iter->owe == 0)
          cout<<iter->name<<", you don't need to do anything\n";
    }
}

void list_to_vector(const NodePtr& head, vector<ListNode>& list){
    for(NodePtr iter = head; iter != nullptr; iter = iter->link){
        if(iter->owe != 0){
            ListNode a;
            a.name = iter->name;
            a.pay = iter->pay;
            a.owe = iter->owe;
            a.link = nullptr;
            list.push_back(a);
        }
      }
}

bool cmp(ListNode s1, ListNode s2){
    return s1.owe > s2.owe;
}