#include<iostream>
using namespace std;

class CircularQueue{
private:
    int front;
    int rear;
    int arr[5];
    int itemCount;

public:
    CircularQueue(){
              front=-1;
              itemCount=0;
              rear=-1;
              for(int i=0;i<5;i++)
                arr[i]=0;
          }
    bool isEmpty(){
        if(front==-1 && rear==-1)
            return true;
        else
            return false;
    }
    bool isFull(){
        if((rear+1)%5==front)
            return true;
        else
            return false;
    }
    void enqueue(int val){
        if(isFull()){
            cout<<"Queue full"<<endl;
            return;
        }
        else if(isEmpty()){
            rear=0;
            front=0;
            arr[rear]=val;
        }
        else{
            rear=(rear+1)%5;
            arr[rear]=val;
        }
        itemCount++;
    }
    int dequeue(){
        int x=0;
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return x;
        }
        else if(rear==front){
            x=arr[rear];
            rear=-1;
            front=-1;
            itemCount--;
            return x;
        }
        else{
            cout<<"Front value: "<<front<<endl;
        x=arr[front];
        arr[front]=0;
        front = (front+1)%5;
        itemCount--;
        return x;
        }
    }
    int count(){
        return itemCount;
    }
    void display(){
        cout<<"All values in the queue are - "<<endl;
        for(int i=0;i<5;i++)
            cout<<arr[i]<<" ";
    }
};

int main(){
    CircularQueue Q1;
        int option;
        do{
        cout<<"\n\n What operation do you want to perform ? Select Option number. Enter 0 to exit. "<<endl;
        cout<<"1. Enqueue() "<<endl;
        cout<<"2. Dequeue() "<<endl;
        cout<<"3. isEmpty() "<<endl;
        cout<<"4. isFull()  "<<endl;
        cout<<"5. count()   "<<endl;
        cout<<"6. display() "<<endl;
        cout<<"7. Clear screen"<<endl<<endl;

        cin>>option;
        switch(option){
                case 1:
                    int value;
                    cout<<"Enter the value : "<<endl;
                    cin>>value;
                    Q1.enqueue(value);
                    break;
                case 2:
                    int t;
                    t=Q1.dequeue();
                    cout<<"The Element removed is : "<<t<<endl;

                    break;
                case 3:
                    if(Q1.isEmpty())
                        cout<<"This Queue is Empty : "<<endl;
                    else
                        cout<<"This Queue is not Empty : "<<endl;

                    break;
                case 4:
                    if(Q1.isFull())
                        cout<<"This Queue is Full : "<<endl;
                    else
                        cout<<"This Queue is not full : "<<endl;
                    break;
                case 5:
                int number;
                number=Q1.count();
                cout<<"Total number of elements are : "<<number<<endl;

                    break;
                case 6:
                Q1.display();

                    break;
                case 7:

                    break;
            }

        }while(option!=0);

            return 0;
        }

