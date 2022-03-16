#include<iostream>
using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int arr[10];

    public:
        Queue(){
            for(int i=0;i<10;i++)
                arr[i]=0;
            front=rear=-1;
        }
        bool isfull(){
            if(front==9)
                return true;
            else
                return false;
        }
        bool isEmpty(){
            if(front==rear)
                return true;
            else
                return false;
        }
        int count(){
            int co;
            co=front-rear;
            return co;
        }
        void diplay(){
            cout<<"The array elements are following : "<<endl;
            for(int i=0;i<10;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
        void enqueue(int value){
            if(isfull())
                cout<<"The Queue is Full : "<<endl;
            else{
                front++;
                arr[front]=value;
            }
            cout<<"Elements Successfully entered : "<<endl;
        }
        int dequeue(){
            if(isEmpty()){
                cout<<"The Queue is Empty : "<<endl;
                return 0;
            }
            else{
                int t;
                rear++;
                t=arr[rear];
                arr[rear]=0;
                return t;
            }
        }


};

int main(){
    Queue Q1;
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
            if(Q1.isfull())
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
        Q1.diplay();

            break;
        case 7:

            break;
    }

}while(option!=0);

    return 0;
}
