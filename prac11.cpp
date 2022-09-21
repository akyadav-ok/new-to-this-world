#include<iostream>
using namespace std;

class Stack{
	private:
		double * arr;
		int size;
		int top;
	public:	
	
	Stack(int s){
		size=s;
		arr=new double[s];
		top=-1;
		
	}
	
	void push(double elem){
		if((size-top)>1){
			top++;
			arr[top]=elem;
		}
		else{
			cout<<"Stack overflow "<<endl;
		}
	}
	void pop(){
		if(top>=0)
			top--;
		else
			cout<<"Stack underflow "<<endl;
	}
	double peek(){
		if(top>=0)
		return arr[top];
		else{
			cout<<"Stack is empty "<<endl;
		}
	}
	bool isEmpty(){
		if(top<0)
		return true;
		else
		return false;
	}
};
