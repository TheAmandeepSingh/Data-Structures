/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
            Iterate 0th index - ( -> )
            Stack - } ] )  
Output: true

Example 3:

Input: s = "(]"
Output: false

([)] false

Input - ( [ { } ] ) true
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

bool validParenthesis(const string& p){
    if(p.length() == 0) return false;
    if(p.length() == 1) return false;

    unordered_map<char, char> m {{'{', '}'}, {'[', ']'}, {'(', ')'}};

    for(auto b : m){
        cout << b.first << " " << b.second <<endl;
    }

    stack<char> s; //Input - ()[]{}
    for(auto c: p){
        auto iter = m.find(c); // ]
        if(iter != m.end()){ // {"{", "}"}, {"[", "]"}, {"(", ")"
             s.push(iter->second);// s -> ]
        }

        if(s.size() > 0 && s.top() == c) { // 1 && [== ]
            s.pop();  // empty
        }
    }

    if(s.size() == 0) return true;

    return false;
}

int main(){
    string input(")");
    if(validParenthesis(input)){
        cout<< "'" << input << "'" << " is a valid parenthesis." <<endl;
    }
    else{
        cout<< "'" << input << "'" << " is not a valid parenthesis."<<endl;
    }

    return 0;
}