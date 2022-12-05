#include<iostream>
using namespace std;

int cqueue[5];
int front=-1,rear=-1,n=5;
void insertcq(int val){
    if((front==0 && rear==n-1)||(front==rear+1)){
        cout<<"Queue Overflow!\n";
        return;
    }
    if(front==-1){
        front=0;
        rear=0;
    }
    else{
        rear=(rear+1)%n;
    }
    cqueue[rear]=val;
}
void deletecq(){
    if(front==-1){
        cout<<"Queue underflow\n";
        return;
    }
    cout<<"Element deleted from queue is: "<<cqueue[front]<<endl;
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        if(front==n-1){
            front=0;
        }
        else{
            front=front+1;
        }
    }
}
void displaycq(){
    int f=front,r=rear;
    if(front==-1){
        cout<<"Queue is empty!\n";
        return;
    }
    cout<<"Queue elements are: \n";
    if(f<=r){
        while(f<=r){
            cout<<cqueue[f]<<" ";
            f++;
        }
    }
    else{
        while(f<=n-1){
            cout<<cqueue[f]<<" ";
            f++;
        }
        f=0;
        while(f<=r){
            cout<<cqueue[f]<<" ";
            f++;
        }
    }
    cout<<endl;
}
void reverse_displaycq(){
    int f=front,r=rear;
    if(front==-1){
        cout<<"Queue is empty!\n";
        return;
    }
    cout<<"Queue elements are: \n";
    if(f<=r){
        while(f<=r){
            cout<<cqueue[r]<<" ";
            r--;
        }
    }
    else{
        while(r>=0){
            cout<<cqueue[r]<<" ";
            r--;
        }
        r=n-1;
        while(r>=f){
            cout<<cqueue[r]<<" ";
            r--;
        }
    }
    cout<<endl;
}
int main(){
    int ch,n,val;
cout<<"1. Insert Elements in Queue(Enqueue)\n2. Delete Element in Queue(Dequeue)\n3. Display Elements in Queue\n4. Display Elements in reverse order\n0. Exit\n";
    do{
    cout<<"Enter your choice: ";
    cin>>ch;
    switch (ch)
    {
    case 1:
            cout<<"Enter element: ";
            cin>>val;
            insertcq(val);
        break;
    case 2:
        deletecq();
        cout<<"Last element in the queue deleted.\n";
        break;
    case 3: 
        displaycq();
        break;
    case 4: 
        reverse_displaycq();
        break;
    case 0:
        cout<<"Exiting.....\n";
        return 0;
    default:
        cout<<"INVALID CHOICE!!!! PLEASE ENTER AGAIN: ";
        break;
    }
    }while(ch!=0);
    return 0;
}
