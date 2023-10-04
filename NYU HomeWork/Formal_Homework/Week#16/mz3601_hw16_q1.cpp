#include <fstream>
#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>

using namespace std;

bool symbol_balance_checker(ifstream& in_stream);

int main()
{
    ifstream in_stream;
    string input, first;
    
    cout << "please type file name: ";
    getline(cin, input);
    in_stream.open(input);
    if(in_stream.fail()){
        cout << "Input file open failed.\n";
        exit(1);
    }
    if(symbol_balance_checker(in_stream) == true)
      cout<<"The symbol is balanced.";
    else 
      cout<<"The symbol is not balanced.";  
    
    in_stream.close();
    return 0;
}

bool symbol_balance_checker(ifstream& in_stream){
  stack<char> symbol;
  in_stream.ignore(9999, 'b');
  
  string input;
  getline(in_stream, input);
  while(input != "egin"){
       in_stream.ignore(9999, 'b');
       getline(in_stream, input);
  }
  while(getline(in_stream, input))
  {
    if(input == "end"){
       break;
    }
    else{
      for(int i = 0; i < input.size(); i++){
        if(input[i] == '(' || input[i] == '{' || input[i] == '['){
            symbol.push(input[i]);
        } 
        else if(input[i] == ')' || input[i] == '}' || input[i] == ']'){
          if(symbol.empty()){
            return false;
          }
          else{
            //if input[i] 和 symbol.top 对上 则 symbol.pop()
            //else return false
            switch(input[i]){
                case ')':
                   if(symbol.top() == '('){
                    symbol.pop();
                    break;
                   }
                   else 
                     return false;
                case ']':
                   if(symbol.top() == '['){
                    symbol.pop();
                    break;
                   }
                   else 
                     return false;   
                case '}':
                   if(symbol.top() == '{'){
                    symbol.pop();
                    break;
                   }
                   else 
                     return false;        
            }
          }
        }
      } 
    }
  }
    

return (input == "end" && symbol.empty());
}