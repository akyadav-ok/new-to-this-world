#include <iostream>
using namespace std;

class Node 
{   
	public:
		int data ;
		Node *next;
		
		
		Node (int data)
		{
			this -> data=data;
			this ->next = NULL ;
			
		}
		
		
		
		
		
		~Node()
		{
			int value=this->data;
			if(this->next!=NULL)
			{
				delete next;
				this->next=NULL;
			}
			cout<<"Memory is free for Node With Data  "<< value<<endl ;
				
			
		}
		
		
		
	
};

void insertAtHead(Node* &head,int d)
		{
			//create  new node
			Node *temp= new Node(d);
			temp->next=head;
			head=temp; 
		}
		
		void print (Node * & head)
		{
			Node *temp=head;
			
			while(temp !=NULL)
			{
				cout<<temp->data<<" ";
				temp=temp->next;
				
			}
			cout<<endl;
			
		}
		
		
		void insertAtTail(Node * & tail, int d)
		{
			//create  new node at Tail or at the End ;
			Node *temp= new Node(d);
			tail->next=temp;
			tail=temp;   // tail = tail ->next; 
		}
		
		void insertAtPosition(Node *&tail,Node *&head,int position, int d)
		{
			Node *temp = head;
			int count=1;
			
			while(count < position -1 )
			{
				temp = temp->next;
				count++;
			}
			
			// create a node for d 
			
			Node * nodetoInsert = new Node(d);
			nodetoInsert->next=temp ->next;
			temp->next = nodetoInsert;
			
			
			if (position == 1)
			{
				insertAtHead(head, d);
				return;
			}
			
			if (temp->next==NULL)
			{
				insertAtTail(tail,d);
				return;
				
			}
			
		}
		
		
		void deleteNode(int position, Node* &head,Node* &tail)
		{
			//delete first or Starting node.
			
			if(position==1)
			{
				Node* temp = head;
				head=head->next;
				temp->next=NULL;
				delete temp;
			}
			else {
				Node*  curr=head;
				Node*  prev=NULL;
				
				int count=1;
				while (count < position )
				{
					prev=curr;
					curr=curr->next;
					count++;
					
				}
				if(curr->next==NULL)
				{
					tail=prev;
				} 
				prev->next=curr->next;
				curr->next=NULL;
				
				delete curr;
			}
		}
		



int main()
{
	Node * node1=new Node(10);
	
	Node * head= node1 ;
	Node * tail = node1 ;
	
	print(head);
	cout<< endl;cout<< endl;
	
	insertAtHead(head, 12 );
	print(head );
	cout<< endl;cout<< endl;
	
	insertAtHead(head,15);
	print(head);
	cout<< endl;cout<< endl;
	
	insertAtTail(tail,12);
	print(head);
	cout<< endl;cout<< endl;
	
	insertAtTail(tail,15);
	print(head);
	cout<< endl;
	cout<< endl;
	
	insertAtPosition(tail,head,4,22);
	print(head);
	
	cout<< endl;cout<< endl;
	
	cout<<" Head : "<<head ->data<<endl;
	cout<<" Tail : "<<tail ->data<<endl;
	
	cout<<"Hello !!";cout<<endl;
	
	deleteNode(6,head,tail);
	print(head);
	cout<<endl;
	
	cout<<"Hello !!";
	
	cout<<" Head : "<<head ->data<<endl;
	cout<<" Tail : "<<tail ->data<<endl;
	
	
	return 0;
	
}
