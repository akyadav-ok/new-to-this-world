#include<iostream>
#include"linkQue7.cpp"
using namespace std;

class Stack
{
	public:
		SLL* obj;
		Stack()
		{
			obj=new SLL();
		}
		void push(int datum)
		{
			obj->insertatHead(datum);
		}
		int pop()
		{
			try
			{
				int d=obj->deletefromHead();
			}
			catch(const char*string)
			{
				throw "underflow";
			}
		}
		void elementAtTop()
		{
			obj->displayTop();
		}
	    void displayStack()
	    {
	    	obj->display();
		}
};
int main()
{
	Stack obj;
	obj.push(20);
	obj.push(20);
	obj.elementAtTop();
	cout<<endl;
	obj.displayStack();
	return 0;
}
