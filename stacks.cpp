#include <iostream>

using namespace std;

typedef struct node{
    int data;
    node* next;

    node (int data){
        this -> data = data;
        this -> next = NULL;
    }

}node;

// Push
void push(int data, node* &top){
    node* new_node = new node(data);
    new_node -> next = top;
    top = new_node;
    return;
}

// Peek
int peek(node* &top){
    if (top) return top -> data;
    cout<<"Error, stack is empty";
    return -1;
}

// Pop
int pop(node* &top){
    node* temp = top;
    int data = temp -> data;
    top = top -> next;
    delete temp;
    return data;
}

int main(){
    node *stack1 = NULL, *stack2 = NULL;
    push(1, stack1);
    push(2, stack1);
    push(3, stack1);
    push(4, stack1);
    push(5, stack1);
    push(6, stack1);
    push(7, stack1);
    push(8, stack1);
    push(9, stack1);
    push(10, stack1);
    push(11, stack1);
    push(12, stack1);
    push(pop(stack1), stack2);
    push(pop(stack1), stack2);
    push(pop(stack1), stack2);
    push(pop(stack1), stack2);
    push(pop(stack1), stack2);
    push(pop(stack1), stack2);
    push(pop(stack1), stack2);
    push(pop(stack1), stack2);
    push(pop(stack1), stack2);

    return 0;
}