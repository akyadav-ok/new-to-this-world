#include <iostream>
using namespace std;

class Node 
{   
	public: 
		int data ;
		Node *next;
   
   		Node(int d)
   		{
   			data =d ;
   			next=NULL;
   			
		}

};

class Queue 
{
	
	
	
	public:
		Node * front ,*rear;
		
		Queue(){
			front = rear = NULL;
			
		}
		
		void EnQueue(int x)
		{
			Node* temp= new Node(x);
			
			if(front == NULL)
			{
				front=rear=temp;
				return;
			}
			
			rear->next=temp;
			rear=temp;
			
			
		}
		
		void DeQueue(){
			
			if(isEmpty())
			{
				
				cout<<" Queue is Empty !!! "<<endl;
				return;
			
			}
			
			Node *delnode=front;
			front = front->next;
			
			delete delnode;
			
		}
		
		int peek()
		{
			if (isEmpty())
			{
				cout<<" Queue is Empty !!! "<<endl;
				return 1;
			}
			
			return front->data;
			
		}
		
		bool isEmpty()
		{
			if (front==NULL)
				return true;
			
			return false;	
			
		}
		
		void display()
		{
			if(isEmpty())
				cout<<"Queue is Empty";
				
			else{
			
			Node* now=front;
			while (now!=NULL)
			{
				cout<<now->data;
				now=now->next;
				cout<<endl;
			}
		    
			delete now;}
			
		}
		
	
		
		
};



int main ()
{
	
	Queue q;
    q.EnQueue(10);
    q.EnQueue(20);
 //   q.DeQueue();
 //   q.DeQueue();
    q.EnQueue(30);
    q.EnQueue(40);
    q.EnQueue(50);
  //  q.DeQueue();

	q.display();
	q.peek();
    cout << "Queue Front : " << (q.front)->data << endl;
    cout << "Queue Rear : " << (q.rear)->data;
    cout<<endl;
	



    /* 
	
	int x,y,z;
	
	int n ;
	z:
	cout<<"1. Enter Element "<<endl;
	cout<<"2  Delete Element "<<endl;
	cout<<"3. Display Element "<<endl;
	
	cout<<"Enter Your Choice:'n' :: ";
	cin >> n;
	cout<<endl;
	
	if (n==1)
	{
		int d, k;
		cout<<"1. EnQueue () is called . "<<endl;
		x:
			cout<<"Enter Element to be Pushed:'k' :: ";
			cin>>k;
			cout<<endl;
			q.EnQueue(k);
			
			cout<<"      Want to Add More Elements "<<endl;
			cout<<"     If YES Enter 0  "<<endl;
			cout<<"      If NO Enter Any Value  "<<endl;
			cout<<"d:";
			cin>>d;
			
				if (d==0)				
					goto x;
						 
			goto z;		 
	}
	if (n==2)
	{   
		int d,k;
		cout<<"1. DeQueue() is called  "<<endl;
		y:
			q.DeQueue();
			q.display();
		cout<<"Want to Continue Poping  "<<endl;
		cout<<"If YES Enter 0 "<<endl;
		cout<<"If NO Enter any No "<<endl;
		cout<<"d: "<<endl;
		cin >>d;
			if(d==0)
				goto y;
				
		goto z;	
	}
	if (n==3)
	{
		cout<<"3. Display() is called  "<<endl;
		q.display();cout<<endl;
		cout<<"Top Element is :: "<<peek()<<endl;
		goto z;
	}
	if(n!=1 && n!=2 && n!=3)
	{   
	    cout<<"  !! INVALID INPUT !!  "<<endl;
		exit(1);
	}
	
	
	
	 */
	
	
	
	
	return 0;
	
	
}









