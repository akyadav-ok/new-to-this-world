#include <iostream>
using namespace std;

class Node 
{   
	public:
		int data ;
		Node *next;
   

};

Node * top;

void push(int data)
{
	Node * temp = new Node();
	if(!temp){
		cout<<"stack Overflow";
		return;
	}
	temp->data=data;
	temp->next=top;
	top=temp;
	
}

int isEmpty(){
	
	return top==NULL;
	
}

int peek()
{
	if(!isEmpty())
		return top->data;
	else 
		return 1;
}



void pop(){
	
	Node* temp;
	
	if(top==NULL){
		
		cout<<"Stack Underflow !!"<<endl;
		exit(1);
		
	}
	else {
		
		temp=top;
		
		top=top->next;
		cout<<endl;
		cout<<"Poped Element is ::"<<temp->data<<endl;
		delete temp; // deallocate memory 
		            //free the memory 
		            // inbuilt Function free();
		            // i.e. delete the Node;
		            
		
	}
	
}


void display()
{
	Node * temp;
	
	if (top==NULL){
		
		cout<<"STack Underflow ";
		return;
		
	}
	else{
		
		temp=top;
		while(temp!=NULL)
		{
			cout<<temp->data
			<<"->";
			
			temp=temp->next;
			
		}
	}
	
}


int main()
{
	cout<<"hello !!"<<endl;
	int x,y,z;
	
	int n ;
	z:
	cout<<"1. Push Element "<<endl;
	cout<<"2  Pop Element "<<endl;
	cout<<"3. Display Element "<<endl;
	
	cout<<"Enter Your Choice:'n' :: ";
	cin >> n;
	cout<<endl;
	
	if (n==1)
	{
		int d, k;
		cout<<"1. Push () is called . "<<endl;
		x:
			cout<<"Enter Element to be Pushed:'k' :: ";
			cin>>k;
			cout<<endl;
			push(k);
			
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
		cout<<"1. Pop() is called  "<<endl;
		y:
			pop();
			display();
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
		display();cout<<endl;
		cout<<"Top Element is :: "<<peek()<<endl;
		goto z;
	}
	if(n!=1 && n!=2 && n!=3)
	{   
	    cout<<"  !! INVALID INPUT !!  "<<endl;
		exit(1);
	}
	
	
	
	
	
	
	
	return 0;
	
	
	
	
	
	
	
	
}
