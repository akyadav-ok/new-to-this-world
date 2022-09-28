#include<iostream>
using namespace std;
class MyQueue 
{
	private :
		int front,rear;
		int size;
		int *arr;
	public :
		MyQueue(int s)
		{
			size =s;
			arr=new int[size];
			
		}


		bool isEmpty()
		{
			if(front==-1)
	
				return true;
			else
				return false;
		
		}

		bool isFull()
		{
			if (rear==size-1)
				return true;
			else
				return false;
		
		}

		int elementAtFront()
		{	 
			if (isEmpty())
				cout<<"Queue is Empty "<<endl;
			else 
				return arr[front];
				
	
		}
		int elementAtRear()
		{
			if(isEmpty())
			{
				cout<<"Queue is Empty ";
								
			}
			else 
				return arr[rear];
		}
		int count()
		{
			if(isEmpty())
				return 0;
			else 
				return rear-front+1;
				
		}
		void Enqueue(int elem)
		{
			if(isFull())
			{
				cout<<"Overflow";
			}
			else if (isEmpty())
			{
				front++;rear++;
				arr[rear]=elem;
			}
			else
			{
				rear++;
				arr[rear]=elem;
			}
			
		}
		
		void dequeue()
		{
			if(count()==0)
			{
				cout<<" Underflow "<<endl;
				
			}
			else if (count()==1)
			{
				front=-1;
				rear=-1;
				
			}
			else 
				front ++;
		}
		
		void display()
		{
			if(!isEmpty())
			{
				for(int i=front;i<=rear;i++)
				{
					cout<<arr[i];
					
				}
			}
			else
				cout<<"Empty ";
		}
		
		~MyQueue()
		{
			delete[]arr;
		}
};

int main()
{
	MyQueue s(15);
	s.Enqueue(5);
	s.Enqueue(4);
	s.Enqueue(6);
	s.dequeue();
	s.Enqueue(7);
	s.display();
	
}
