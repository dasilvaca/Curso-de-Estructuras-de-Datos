#include<iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    node(node *prev, int data)
    {
        this->data = data;
        this->next = NULL;
        prev->next = this;
    }
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // void insert(int data)
    // {
    //     node *nuevo = new node(data);
    //     node *temp = this;
    //     while(temp->next != NULL)
    //     {
    //         temp = temp->next;
    //     }
    //     temp->next = nuevo;
    // }
}node;


int main()
{
    node *head = new node(10);
    head->next = new node(head, 20);

    
}