#include<iostream>
using namespace std;

class Stack{
	private:
		string* arr;
		int size;
		int top;
	public:	
	
	Stack(int s){
		size=s;
		arr=new string[s];
		top=-1;
		
	}
	
	void push(string elem){
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
	string peek(){
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

/*int main(){
	Stack abc(5);
	abc.push(86);
	abc.push(65);
	abc.push(54);
	abc.push(20);
	
	cout<<abc.peek()<<endl;
	abc.pop();
		cout<<abc.peek()<<endl;
	abc.pop();
	cout<<abc.peek()<<endl;
	return 0;
}*/
