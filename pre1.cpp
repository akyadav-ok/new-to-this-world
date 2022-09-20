#include<iostream>
#include "stack220.cpp"
#include<algorithm>
using namespace std;

bool isOperator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/')
	{
		return true;
	}
	else 
	{
		return false;
	}
}

int precedence(char c)
{
	if(c=='*'||c=='/')
		return 2;
	else if (c=='+'||c=='-')
		return 1;
	else 
		return -1;
		
}

string InfixToPrefix(sStack c,string infix)
{
	string prefix;
	
	reverse(infix.begin(),infix.end());
	
	for (int i=0; i<infix.length();i++)
	{
		if(infix[i]=='(')
		{
			infix[i]=')';
			
		}
		else if(infix[i]==')')
		{
			infix[i]='(';
			
		}
	}
	
	for (int i=0; i<infix.length();i++)
	{
		if((infix[i]>='a'&& infix[i]<='z')||(infix[i]>='A' && infix[i]<='Z'))
		{
			prefix+=infix[i];
				
		}
		else if (infix[i]=='(')
		{
			c.push(infix[i]);
		}	
		else if(infix[i]==')')
		{
			while((c.peek()!='(')&&(!c.isEmpty()))
			{
				
				prefix+=c.peek();
				c.pop();
				
			}
			if(c.peek()=='(')
			{
				c.pop();
				
			}
			
		}
		else if (isOperator(infix[i]))
		{
			if(c.isEmpty())
			{
				c.push(infix[i]);
			}
			else
			{
				if (precedence(infix[i])>precedence(c.peek()))
				{
					c.push(infix[i]);
				}
				else if (precedence(infix[i])==precedence(c.peek()))
				{
					c.push(infix[i]);
				}
				else 
				{
					while((!c.isEmpty())&&precedence(infix[i])<=precedence(c.peek()))
					{
						prefix+=c.peek();
						c.pop();
					}
					c.push(infix[i]);
				}
				
			}
			
		}
	}
	while(!c.isEmpty())
	{
		prefix+=c.peek();
		c.pop();
	}
	
	reverse(prefix.begin(),prefix.end());
	
	return prefix;
}


string InfixToPostfix(sStack c,string infix)
{
	string postfix;
	
	for (int i=0;i<infix.length();i++)
	{
		if((infix[i]>='a'&& infix[i]<='z')||(infix[i]>='A'&& infix[i]<='Z'))
		{
			postfix+=infix[i];	
				
		}
		else if (infix[i]=='(')
		{
			c.push(infix[i]);
		}
		else if (infix[i]==')')
		{
			while((c.peek()!='(')&& (!c.isEmpty()))
			{
				postfix+=c.peek();
				c.pop();
			
			}
			if(c.peek()=='(')
			{
				c.pop();
			}
		}
		else if (isOperator(infix[i])) // or only else {.....}
		{
			if(c.isEmpty())
			{
				c.push(infix[i]);
				
			}
			else
			{
				if(precedence(infix[i])>precedence(c.peek()))
				{
					c.push(infix[i]);
					
				}
				else if(precedence(infix[i])==precedence(c.peek()))
				{
					c.push(infix[i]);
				}
			
				else//(if(precedence(infix[i])>precedence(c.peek())))
                {
                	 while((!c.isEmpty())&&(precedence(infix[i])<=precedence(c.peek())))
                	 {
                	 	postfix+=c.peek();
                	 	c.pop();
                	 	
					 }
					 c.push(infix[i]);
				}
			}
			
			
		}
		
	}
	while (!c.isEmpty())
	{
		postfix+=c.peek();
		c.pop();
	}
	
	return postfix;
}



int main()
{
	string infix,prefix,postfix;
	cout<<"Enter a Infix Expression - "<<endl;
	cin>>infix;
	sStack s(15);
	cout<<"Infix Expression -- "<<infix<<endl;
	
	prefix=InfixToPrefix(s,infix);
	
	cout<<endl<<"Prefix Expression-- "<<prefix;
	postfix=InfixToPostfix(s, infix);
	cout<<endl<<"Postfix Expression: "<<postfix;
	
	
	return 0;
}
