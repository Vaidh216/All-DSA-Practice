#include<iostream>
using namespace std;

class Node{
public:
    int key;
    int data;
    Node* next;
    Node(){
        key=0;
        data=0;
        next=NULL;
    }
    Node(int k,int d){
        key=k;
        data=d;
        next=NULL;
    }
};

class SinglyLinkedList{
public:
    Node* head;

    SinglyLinkedList(){
        head=NULL;
    }
    SinglyLinkedList(Node *n){
        head=n;
    }

    // Check if node exista using key value
    Node* nodeExists(int k){
        Node* temp=NULL;

        Node* ptr=head;
        while(ptr!=NULL){

            if(ptr->key==k){
                temp=ptr;
            }
            ptr=ptr->next;
        }
        return temp;
    }
    //2. Append a node to the list
    void appendNode(Node *n){
        if(nodeExists(n->key)!=NULL){
            cout<<"Node already exits with key value : "<<n->key<<". Append another node with different key value"<<endl;
        }else{
            if(head==NULL){
                head=n;
                cout<<"Node appended"<<endl;
            }else{
                Node *ptr = head;
                while(ptr->next!=NULL){
                    ptr=ptr->next;
                }
                ptr->next=n;
                cout<<"Node Appended"<<endl;
            }

        }

    }
    //3. Prepend Node - Arrach a node at the start
    void prependNode(Node* n){
        if(nodeExists(n->key)!=NULL){
            cout<<"Node already exits with key value : "<<n->key<<". Append another node with different key value"<<endl;
        }else{
            n->next=head;
            head=n;
            cout<<"Node Prepended"<<endl;
        }
    }
    //4. Insert a node after a particular node in the list
    void inserNodeAfter(int k,Node *n){
        Node* ptr=nodeExists(k);
        if(ptr==NULL){
            cout<<"No node exits with key value: "<<k<<endl;
        }else{
            if(nodeExists(n->key)!=NULL){
                cout<<"Node already exits with key value : "<<n->key<<". Append another node with different key value"<<endl;}
            else{
                n->next=ptr->next;
                ptr->next=n;
                cout<<"Node inserted"<<endl;
            }

        }

    }
    //5. Delete node by unique key
    void deleteNodeBYkey(int k){
        if(head==NULL){
            cout<<"Singe liked list already empty, Cant delete"<<endl;
        }
        else if(head!=NULL){
            if(head->key==k){
                head=head->next;
                cout<<"Node Unlinked with key values : "<<k<<endl;
            }
            else{
                Node* temp=NULL;
                Node* prevptr=head;
                Node* currentptr=head->next;
                while(currentptr!=NULL){

                    if(currentptr->key==k){
                        temp=currentptr;
                        currentptr=NULL;
                    }else{
                        prevptr=prevptr->next;
                        currentptr=currentptr->next;
                    }
                }
                if(temp!=NULL){

                    prevptr->next=temp->next;
                    cout<<"Node UNLINKED with keys value : "<<k<<endl;
                }else{
                    cout<<"Node Doesn't exist with key value : "<<k<<endl;
                }
            }
        }
    }

    //6. Update node
    void updateNodeByKey(int k,int d){
        Node*ptr=nodeExists(k);
        if(ptr!=NULL){
            ptr->data=d;
            cout<<"Node Data Updated Successfully"<<endl;
        }else{
            cout<<"Node Doesn't exit with key value : "<<k<<endl;
        }
    }
    //7. printing
    void printList(){
        if(head==NULL){
            cout<<"No node in singly linked list"<<endl;
        }
        else{
            cout<<endl<<"Singly Linked list Values : ";
            Node* temp=head;
            while(temp!=NULL){
                cout<<"("<<temp->key<<","<<temp->data<<") --> ";
                temp=temp->next;
            }
        }
    }
};

int main(){
    SinglyLinkedList s;
    int option;
    int key1,k1,data1;
    do{
        cout<<"\nWhat operation do you want to perform? Select Option number. Enter 0 ti exit."<<endl;
        cout<<"1. appendNote()"<<endl;
        cout<<"2. prependNode()"<<endl;
        cout<<"3. insertnodeafter()"<<endl;
        cout<<"4. deleteNodebykey()"<<endl;
        cout<<"5. updateNodebykey()"<<endl;
        cout<<"6. print()"<<endl;
        cout<<"7. Clear screen"<<endl<<endl;

        cin>>option;
        Node* n1=new Node();

        switch(option){

        case 0:
            break;
        case 1:
            cout<<"Append Node Operation \nEnter key & data oof the Node to be appended"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.appendNode(n1);
            break;

        case 2:
            cout<<"Prepend Node operation \nEnter key & data of the node to be prepended"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.prependNode(n1);
            break;

        case 3:
            cout<<"Insert node after operation \nEnter key of existing Node after which you want to insert this new node :"<<endl;
            cin>>k1;
            cout<<"Enter ket & data of the new NOde first: "<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;

            s.inserNodeAfter(k1,n1);
            break;

        case 4:
            cout<<"Delete node by mey operation -\nEnter key of the node to be deleted: "<<endl;
            cin>>k1;
            s.deleteNodeBYkey(k1);
            break;

        case 5:
            cout<<"Upadate Node by key operation -\n Enter key & new data to be updated"<<endl;
            cin>>key1;
            cin>>data1;
            s.updateNodeByKey(key1,data1);
            break;
        case 6:
            s.printList();
            break;

        case 7:
            system("cls");
            break;
        default:
            cout<<"Enter proper option :"<<endl;
        }

    }while(option!=0);


    return 0;
}
