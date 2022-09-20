#include <iostream>
using namespace std;




class sStack {
    int top;
    int MAX;
    char* a;
 
public:

    sStack(int size){
        top = -1;
        MAX = size;
        a = new char [MAX];
    }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
};

bool sStack::isEmpty(){
    return (top < 0); 
} 

bool sStack::isFull(){
    return (top == MAX - 1); 
    
} 

int sStack::peek(){ 
    return a[top]; 
    
} 
bool sStack::push(int x) {
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        top++;
        a[top] = x;
        return true;
    }
}
int sStack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow"; 
        return INT_MIN; 
    } 
    else { 
        int x = a[top]; 
        top--; return x; 
    }
}
/*int main()
{
	
 
 cout<<"Working !!";	
}*/



