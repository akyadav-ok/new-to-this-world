#include<iostream>
#include "MyStack_Char.cpp"
using namespace std;
 
bool isOperand(char x)
{
   return (x >= 'a' && x <= 'z') ||
          (x >= 'A' && x <= 'Z');
}
 
bool isOperator(char x)
{
    switch (x) {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
} 







// Get Infix for a given postfix
// expression
string getInfix(Stack c,string exp)
{
    
    
    for (int i=0; exp[i]!='\0'; i++)
    {
        // Push operands
        if (isOperand(exp[i]))
        {
           string op(1, exp[i]);
           c.push(op);
        }
 
        // We assume that input is
        // a valid postfix and expect
        // an operator.
        else
        {
            string op1 = c.peek();
            c.pop();
            string op2 = c.peek();
            c.pop();
            c.push("(" + op2 + exp[i] +
                   op1 + ")");
        }
    }
 
    // There must be a single element
    // in stack now which is the required
    // infix.
    return c.peek();
}
 

string postToPre(Stack c,string exp)
{
    
 
    // length of expression
    int length = exp.size();
 
    // reading from right to left
    for (int i = 0; i < length; i++) {
 
        // check if symbol is operator
        if (isOperator(exp[i])) {
 
            // pop two operands from stack
            string op1 = c.peek();
            c.pop();
            string op2 = c.peek();
            c.pop();
 
            // concat the operands and operator
            string temp = exp[i] + op2 + op1;
 
            // Push string temp back to stack
            c.push(temp);
        }
 
        // if symbol is an operand
        else {
 
            // push the operand to the stack
           c.push(string(1, exp[i]));
        }
    }
 
    string ans = "";
    while (!c.isEmpty()) {
        ans += c.peek();
        c.pop();
    }
    return ans;
} 
 
 
 
 
 //((((a*b)-c)+(d/f))+(x*z))
 

int main()
{   
    Stack  s(15);
    string exp; //= "ab*c+";
    cout<<"Enter a Postfix Expression :";
    cin>>exp;
    cout <<"Infix :" <<getInfix(s,exp)<<endl;
    cout << "Prefix : " << postToPre(s,exp)<<endl;
    return 0;
}
