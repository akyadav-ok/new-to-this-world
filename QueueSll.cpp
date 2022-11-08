#include<iostream>
#include"linkQue7.cpp"
using namespace std;

class Queue
{
	public:
		SLL* obj;
		Queue()
		{
			obj=new SLL();
		}
		void enqueue(int datum)
		{
			obj->insertatTail(datum);
		}
		int dequeue()
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
		void display()
		{
			obj->display();
		}
	
};
int main()
{
	Queue obj;
	obj.enqueue(20);
	obj.enqueue(20);
	obj.display();
	return 0;
}
