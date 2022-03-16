#include<iostream>
using namespace std;


// The struct node here we can use class also here
struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
// Basic definition of linkedlist
class LinkedList{
    public:
        Node* head = NULL;

    void Insert_at_tail(int data){
        Node* new_Node = new Node(data);

        if(head == NULL){
            head = new_Node;
            return;
        }
        Node* temp = head;

        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_Node;
    }
    void Print_Nodes(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"-->";
            temp = temp->next;
        }
    }
    void insert_at_head(int data){
        Node* new_Node = new Node(data);
        if(head == NULL){
            head = new_Node;
            return;
        }
        new_Node->next = head;
        head = new_Node;
        return;
    }
    void delete_Node(int val){
        if(head == NULL)
            return;
        if(head->data == val){
            Node *pt = head;
            head = head->next;
            delete pt;
            return;
        }
        Node *pt = head;
        while(pt->next->data != val){
            pt = pt->next;
        }
        Node* temp = pt->next;
        pt->next = pt->next->next;
        delete(temp);
        return;
    }

    bool Search(int val){
        Node* temp = head;
        if(head==NULL)
            return false;
        while(temp!=NULL){
            if(temp->data == val)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void Append_last_k_node(int k){
        int l=0;
        Node* temp = head;
        while(temp->next!=NULL){
            l++;
            temp = temp->next;
        }
        l++;
        temp->next = head;

        if(k > l){
            return;
        }
        temp = head;
        l = l - k;
        while(l--){
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
    }
    
    void put_even_after_odd(){

        if(head == NULL && head->next == NULL){
            return;
        }

        Node* odd = head;
        Node* even = head->next;
        Node* even_head = even;
        int count=0;
        while(odd->next!= NULL && even->next!=NULL){
            count++;
            if(count%2 == 1){
            odd->next = even->next;
            odd = odd->next;
            }else{
                even->next = odd->next;
                even = even->next;
            }
        }
        odd->next = even_head;
        if(odd->next != NULL){
            even->next = NULL;
        }
        //odd->next = even_head;
    }

};

//Now i have to reverse a linked list for both iterative and recurssive method
//Iterative

void rev_link_itera(Node* &head){
    Node* pre = NULL;
    Node* cur = head;
    Node* nex;

    if(head == NULL || head->next == NULL)
        return;
        // head;

    while(cur!=NULL){
        nex = cur->next;
        cur->next = pre;

        pre = cur;
        cur = nex;
    }
    head = pre;
    return;
    //return pre;
}

// Now reccursive method for reversing the linked list

Node *rev_link_rec(Node* head){
    //Base condition
    if(head==NULL || head->next == NULL)
        return head;

    //reccursive condition
    Node* new_head = rev_link_rec(head->next);

    head->next->next = head;
    head->next = NULL;
    return new_head;
}
// The question is reverse k nodes in a linked list
// In this question we reverse the list k each time like ki k is 2
// And the list is 1->2->3->4->5->6
// Then this becomes 2->1->4->3->6->5

Node* rev_fir_k(Node* head,int k){
    
    int count=0;
    Node* pre = NULL;
    Node* cur = head;
    Node* nex;

    if(head == NULL || head->next == NULL){
        return head;
    }

    while(count<k && cur!=NULL){
        nex = cur->next;
        cur->next = pre;
        count++;
        pre = cur;
        cur=nex;
    }
    Node* new_node = rev_fir_k(cur,k);
    head->next = new_node;
    return pre;
}

//Now we have to use floyd algorithm to find the cycle in the linked list
//  1. Check if any cycle is present.
//  2. Make a cycle the position is given.
//  3. Remove a cycle in the linked list.
//1. 

bool check_cycle(Node* head){
    if(head == NULL){
        return false;
    }
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        if(fast == slow)
            return true;
        
        fast = fast->next->next;
        slow = slow->next;
    }
    return false;
}

//  2. Creating a cycle at position given
void create_cycle(Node* &head,int pos){
    Node* temp = head;
    Node* ptr;
    int val=0;
    while(temp->next!=NULL){
        val++;
        if(val == pos){
            ptr = temp;
        }
        temp = temp->next;
    }
    temp->next = ptr;
}

//  3. Now we have to remove the cycle here
//This code is not cross checked for the non cycle linked list so use care fully
//Now this is cross checked

void remove_cycle(Node* &head){
    //cout<<"called"<<endl;
    if(check_cycle == false)
        return;
    //cout<<"called 2"<<endl;
    Node* slow = head;
    Node* fast = head;
    while(true){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            break;

        
    }
    //cout<<"called 3"<<endl;
    fast = head;
    while(true){
        if(fast->next == slow->next){
            break;
        }
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
}


int main(){
    LinkedList list1;
    cout<<"here 1 "<<endl;
    for(int i=0;i<5;i++){
        list1.Insert_at_tail(i*i);
    }
    for(int i=0;i<5;i++){
        list1.insert_at_head(i);
    }
    list1.insert_at_head(100);
    // for(int i=0;i<5;i++){
    //     list1.delete_Node(i*i);
    //     list1.Print_Nodes();
    //     cout<<endl;
    // }
    // list1.Print_Nodes();
    // cout<<endl;
    // list1.head = rev_link_rec(list1.head);

    // list1.Print_Nodes();
    // cout<<endl;
    // list1.head = rev_fir_k(list1.head,3);
    // list1.Print_Nodes();
    // if(check_cycle(list1.head)){
    //     cout<<"Cycle present"<<endl;
    // }else{
    //     cout<<"No cycle present"<<endl;
    // }

    // create_cycle(list1.head,3);
    
    // if(check_cycle(list1.head)){
    //     cout<<"Cycle present"<<endl;
    // }else{
    //     cout<<"No cycle present"<<endl;
    // }

    // remove_cycle(list1.head);

    //cout<<"Hellow ved"<<endl;
    // if(check_cycle(list1.head)){
    //     cout<<"Cycle present"<<endl;
    // }else{
    //     cout<<"No cycle present"<<endl;
    // }
    cout<<"Ghurrahu singh"<<endl;
    list1.Print_Nodes();
    list1.put_even_after_odd();
    cout<<endl<<"After modifying program"<<endl;
    list1.Print_Nodes();
    return 0;
}