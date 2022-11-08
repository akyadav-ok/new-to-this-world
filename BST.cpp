#include <iostream >
using namespace std;

class BNode
{     
	public:
		int data;
		BNode *left;
		BNode *right ;
		
		BNode (int datam, BNode *l=NULL, BNode *r=NULL)
		{
			data = datam;
			left = l ;
			right = r;
			
		}

};

class MyBST
{
	public:
		BNode *root;
		MyBST()
		{
			root=NULL;
			
		}
		
		boole isEmpty ()
		{
			if (root==NULL)
				return true;
		    else 
		    	return false;

		}
			
		void insert(BNode *rroot)
		{
			if (root==NULL)
			{
				root=rroot;
				cout<<"Value Inseerted "<<endl;
			
			}
			else
			{
				BNode *temp= root ;
				while (temp!=temp)
				{
					
				}
			}
		}
};

int main()
{
	int option;
	do
	{  
		cout<<"what operation do you want to perform  ?"
		   <<" Selectoption from the menu below ."<<". Enter 0 to exit ::  "<<endl;
		
		cout<<"1.Insert Node  "<<endl;
		cout<<"2.Search Node  "<<endl; 
		cout<<"3.Delete Node  "<<endl;
		cout<<"4.Display BST  "<<endl;
		cout<<"5.Clear Screen  "<<endl;
		cout<<"0.To Exit Program   "<<endl;
		
		cin>>option;
		
		switch(option)
		{
			case 0:
				break;
			case 1:
				cout<<"Insert "<<endl;
				break;
			case 2:
				cout<<"Search "<<endl;
				break;
				
			case 3:
				cout<<"Display "<<endl;
				break;
					
			default:
				cout<<"Enter Prpoer Option Number ";
				
				
		}
		  	
		
	}while(option!=0);

	return 0;
}
