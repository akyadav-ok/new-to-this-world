#include<iostream>
#include "prac11.cpp"

using namespace std;
 
bool isOperand(char c)
{
    // If the character is a digit then it must
    // be an operand
    return isdigit(c);
}
 
double evaluatePrefix(Stack c,string exp)
{
    
 
    for (int j = exp.size() - 1; j >= 0; j--) {
 
        // Push operand to Stack
        // To convert exprsn[j] to digit subtract
        // '0' from exprsn[j].
        if (isOperand(exp[j]))
            c.push(exp[j] - '0');
 
        else {
 
            // Operator encountered
            // Pop two elements from Stack
            double o1 = c.peek();
            c.pop();
            double o2 = c.peek();
            c.pop();
 
            // Use switch case to operate on o1
            // and o2 and perform o1 O o2.
            switch (exp[j]) {
            case '+':
                c.push(o1 + o2);
                break;
            case '-':
                c.push(o1 - o2);
                break;
            case '*':
                c.push(o1 * o2);
                break;
            case '/':
                c.push(o1 / o2);
                break;
            }
        }
    }
 
    return c.peek();
}


double evaluatePostfix(Stack c,string post)
{
	for(int i=0 ; i<post.length();i++)
	{
	    if(post[i]>='0'&& post[i]<='9')
		{
			c.push(post[i]-'0');
		}
		else{
			double op2=c.peek();
			c.pop();
			double op1=c.peek();
			c.pop();
			
			switch(post[i])
			{
				case'+':
					c.push(op1+op2);
					break;
				case'-':
					c.push(op1-op2);
					break;
				case'*':
					c.push(op1*op2);
					break;	
				case'/':
					c.push(op1/op2);
					break;
				
			}
			
		}	
			
	}
	
	return c.peek();
}





int main()
{
	Stack s(15);
	/*string Pre;
	cout<<"Enter Prefix Expression : ";
	cin>> Pre;
	cout<<"Prefix Expression :"<<endl;
	cout<<"Ans - "<<evaluatePrefix(s,Pre)<<endl; */
	
	string Post;
	cout<<"Enter Postfix Expression : ";
	cin>> Post;
	cout<<"Postfix Expression :"<<endl;
	cout<<"Ans - "<<evaluatePostfix(s,Post)<<endl;
	return 0;
		
}








