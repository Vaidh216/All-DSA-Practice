#include<iostream>
using namespace std;

class stack{
public:
    int arr[10];
    int top=-1;
    stack(){
        for(int i=0;i<10;i++)
            arr[i]=0;
        top=-1;
    }
    bool isfull(){
        if(top==9)
            return true;
        return false;
    }
    void peek(){
        cout<<"The Elements at i is : "<<arr[top]<<endl;
    }
    void count(){
        cout<<"Total elements are : "<<top+1<<endl;
    }
    void display(){
        cout<<"The Elements are : "<<endl;
        for(int i=0;i<10;i++)
            cout<<arr[i]<<endl;
    }
    void change(int i,int element){
        arr[i-1]=element;
        cout<<"Successfully changed the value : "<<endl;
        top=i-1;
    }
    bool isempty(){
        if(top==-1)
            return true;
        else
            return false;
    }
    void push(int value){
        if(isfull()){
            cout<<"Elements cannot be entered because stack is full : "<<endl;
        }
        else{
            top++;
            arr[top]=value;
            cout<<"Elemts entered : "<<endl;
        }
    }
    void pop(){
        if(isempty()){
            cout<<"Element cannot be deleted, Because stack is emptied : "<<endl;
        }
        else{
        int t=arr[top];
        arr[top]=0;
        top--;
        cout<<"The element removed is : "<<t<<endl;
        }
    }
};

int main(){
    stack s1;
    int option;

    do{ cout<<endl<<endl;
        cout<<"Enter 0 for exit          : "<<endl;
        cout<<"Press 1. For Push         : "<<endl;
        cout<<"Press 2. For pop          : "<<endl;
        cout<<"Press 3. For isempty      : "<<endl;
        cout<<"Press 4. For isFull       : "<<endl;
        cout<<"Press 5. For Peek         : "<<endl;
        cout<<"Press 6. For Display      : "<<endl;
        cout<<"Press 7. For count        : "<<endl;
        cout<<"Press 8. For Change       : "<<endl;
        cin>>option;
        cout<<endl<<endl;
        switch (option){
            case 1:
                cout<<"Enter the value : ";
                int t;
                cin>>t;
                s1.push(t);
            break;
        case 2:
            s1.pop();
            break;
        case 3:
            if(s1.isempty())
                cout<<"The stack is empty : "<<endl;
            else
                cout<<"The stack is not empty : "<<endl;
            break;
        case 4:
            if(s1.isfull())
                cout<<"The stack is full : "<<endl;
            else
                cout<<"The stack is not full : "<<endl;
            break;
        case 5:
            cout<<"Peek is ";
            s1.peek();
            break;
        case 6:
            cout<<"Displaying the valuess : "<<endl;
            s1.display();
            break;
        case 7:
            cout<<"The number of elements are : "<<endl;
            s1.count();
            break;
        case 8:
            cout<<"Enter the position and value : "<<endl;
            int pos,value;
            cin>>pos>>value;
            s1.change(pos,value);
            break;
        default:
            cout<<"Wrong option entered : "<<endl;
            break;

        }
    }while(option!=0);
    cout<<endl<<endl;
    cout<<"Operation completed : "<<endl;
    cout<<"The elements are    : "<<endl;
    s1.display();


    return 0;
}
