#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack <char> stk;

    string s = "a*(b+c/(d-e)*f)+g";
    string s1;
    int l;

    l = s.length();
    for(int i = 0; i < l; i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '('){
            stk.push(s[i]);
        }
        else if(s[i] == ')'){
            while(stk.top() != '('){
                s1 = s1 + stk.top();
                stk.pop();
            }
            stk.pop();  //pop '('
            s1 = s1 + stk.top(); 
            stk.pop();
        }
        else
            s1 = s1 + s[i];        
    }
    while(!stk.empty()){
        s1 = s1 + stk.top();
        stk.pop();
    }
    cout << s1 << "\n";

    return 0;
}