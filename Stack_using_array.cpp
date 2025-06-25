#include<iostream>
#define MAX 10
using namespace std;
int arr[MAX];
int top = -1;

int isFull(){
    return (top == MAX -1);
}

int isEmpty(){
    return (top == -1);
}

void push(int item){
    top++;
    arr[top] = item;
}

void pop(){
    top--;
}

int peek(){
    return arr[top];
}

int size(){
    return (top+1);
}

void display(){
    cout<<endl;
    for(int i=top;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int choice,item;
    do{
        cout<<endl;
        cout<<"Enter your choice : "<<endl;
        cout<<"1. Push an element onto the stack : "<<endl;
        cout<<"2. Pop an element from the stack : "<<endl;
        cout<<"3. Peek - Get the top most element : "<<endl;
        cout<<"4. Check whether the stack is full or not : "<<endl;
        cout<<"5. Check whether the stack is empty or not : "<<endl;
        cout<<"6. Get the size of the stack : "<<endl;
        cout<<"7. Display the stack : "<<endl;
        cout<<"8. To exit : ";
        cin>>choice;
        switch(choice){
            case 1:
                if(isFull()){
                    cout<<endl<<"The stack is full"<<endl;
                }   
                else{
                    cout<<endl<<"Enter element to be pushed : ";
                    cin>>item;
                    push(item);
                    cout<<endl<<"The current stack is : ";
                    display();
                }
                break;
            case 2:
                if(isEmpty()){
                    cout<<endl<<"The stack is empty"<<endl;
                }
                else{
                    pop();
                    cout<<endl<<"The current stack is :";
                    display();
                }
                break;
            case 3:
                if(isEmpty()){
                    cout<<endl<<"The stack is empty : "<<endl;
                }
                else{
                    item = peek();
                    cout<<endl<<"The topmost element of the stack is : "<<item<<endl;
                    }
                break;
            case 4:
                if(isFull()){
                    cout<<endl<<"The stack is full "<<endl;
                    cout<<"And the current stack is :";
                    display();
                }
                else{
                    cout<<endl<<"The stack is not full"<<endl;
                    cout<<"And the current stack is :";
                    display();
                }
                break;
            case 5:
                if(isEmpty()){
                    cout<<endl<<"The stack is empty"<<endl;
                }
                else{
                    cout<<endl<<"The stack is not empty"<<endl;
                    cout<<"And the current stack is :";
                    display();
                }
                break;
            case 6:
                item = size();
                cout<<"The current size of the stack is : "<<item<<endl;
                break;
            case 7:
                if(isEmpty()){
                    cout<<endl<<"The stack is empty"<<endl;
                }
                else{
                    cout<<endl<<"The current stack is :";
                    display();
                }
                break;
            case 8:
                break;
            default:
                cout<<endl<<"Enter a valid choice "<<endl;
        }
    }while(choice!=8);
        
}