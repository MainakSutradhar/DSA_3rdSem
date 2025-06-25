#include<iostream>
#define MAX 10
using namespace std;
int arr[MAX];
int front = -1;
int rear = -1;

int isFull(){
    return (front == MAX-1);
}

int isEmpty(){
    return (front == rear);
}

void enqueue(int item){
    rear++;
    arr[rear] = item;
}

int dequeue(){
    front++;
    return arr[front];
}

int peek(){
    return (arr[front+1]);
}

int size(){
    return (rear);
}


void display(){
    cout<<endl;
    for(int i=front+1;i<=rear;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int choice,item;
    do{
        cout<<endl;
        cout<<"Enter your choice : "<<endl;
        cout<<"1. enqueue an element into the queue : "<<endl;
        cout<<"2. dequeue an element from the queue : "<<endl;
        cout<<"3. Peek - Get the front most element : "<<endl;
        cout<<"4. Check whether the queue is full or not : "<<endl;
        cout<<"5. Check whether the queue is empty or not : "<<endl;
        cout<<"6. Get the size of the queue : "<<endl;
        cout<<"7. Display the queue : "<<endl;
        cout<<"8. To exit : ";
        cin>>choice;
        switch(choice){
            case 1:
                if(isFull()){
                    cout<<endl<<"The queue is full"<<endl;
                }   
                else{
                    cout<<endl<<"Enter element to be enqueued : ";
                    cin>>item;
                    enqueue(item);
                    cout<<endl<<"The current queue is : ";
                    display();
                }
                break;
            case 2:
                if(isEmpty()){
                    cout<<endl<<"The queue is empty"<<endl;
                }
                else{
                    item = dequeue();
                    cout<<endl<<"The dequeued item is : "<<item;
                    cout<<endl<<"The current queue is :";
                    display();
                }
                break;
            case 3:
                if(isEmpty()){
                    cout<<endl<<"The queue is empty : "<<endl;
                }
                else{
                    item = peek();
                    cout<<endl<<"The frontmost element of the queue is : "<<item<<endl;
                    }
                break;
            case 4:
                if(isFull()){
                    cout<<endl<<"The queue is full "<<endl;
                    cout<<"And the current queue is :";
                    display();
                }
                else{
                        cout<<endl<<"The queue is not full"<<endl;
                    cout<<"And the current queue is :";
                    display();
                }
                break;
            case 5:
                if(isEmpty()){
                    cout<<endl<<"The queue is empty"<<endl;
                }
                else{
                    cout<<endl<<"The queue is not empty"<<endl;
                    cout<<"And the current queue is :";
                    display();
                }
                break;
            case 6:
                item = size();
                cout<<"The current size of the queue is : "<<item<<endl;
                break;
            case 7:
                if(isEmpty()){
                    cout<<endl<<"The queue is empty"<<endl;
                }
                else{
                    cout<<endl<<"The current queue is :";
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