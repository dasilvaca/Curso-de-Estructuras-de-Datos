#include <iostream>

using namespace std;

template <typename T>
struct nodo
{
    T dato;
    nodo<T> *siguiente;
};

typedef struct node
{
    int data;
    struct node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    void insert_at_end(int data) // This costs O(n)
    {

        node *temp = this;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new node(data);
        return;
    }

    void insert_in_index(int data, int index) // This costs O(n)
    {
        if (index == 0)
        {
            node *cloned_node = new node(this->data);
            cloned_node->next = this->next;
            this->data = data;
            this->next = cloned_node;
            return;
        }
        node *temp = this;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        node *new_node = new node(data);
        new_node->next = temp->next;
        temp->next = new_node;
        return;
    }
} node;

void insert_at_end(int data, node *&head) // This costs O(1)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new node(data);
    return;
};

void insert_at_end_with_tail(int data, node *&head, node *&tail)
{
    if (head == NULL)
    {
        head = new node(data);
        tail = head;
        return;
    }
    tail->next = new node(data);
    tail = tail->next;
};

void delete_a_node(int data, node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head;

    while (temp->next != NULL && temp->next->data != data)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        return;
    }
    node * deleted = temp ->next;
    temp->next = temp->next->next;
    delete deleted;
}

void delete_ith_node (int i, node* &head){
    int data = 0;
    if (head == NULL)
    {
        return;
    }
    node *temp = head;

    while (temp->next != NULL && data < i - 1)
    {
        temp = temp->next;
        data ++;
    }
    if (temp->next == NULL)
    {
        return;
    }
    node * deleted = temp ->next;
    temp->next = temp->next->next;
    delete deleted;
}

void insert_at_head(int data, node* &head) // This costs O(1)
{
    node *new_node  = new node(data);
    new_node ->next = head;
    head = new_node ;
    return;
};

int add_1(int a)
{ // int a = x;
    return a + 1;
}

int add_2(int a)
{
    return add_1(add_1(a));
}

void add_3(int &a)
{
    a = a + 3;
}

// TODO: add scopes to the guide
// TODO: add pass by value and pass by reference to the guide

int main()
{
    {
        int x = 10;
        cout << add_2(x) << endl; // 12
        add_3(x);
        cout << x << endl; // 10
    }
    //* Listas simplemente enlazadas SIN APUNTADOR AL FINAL
    node *head = NULL;
    insert_at_end(10, head);
    insert_at_end(20, head);
    insert_at_end(30, head);
    insert_at_end(40, head);
    insert_at_end(50, head);
    insert_at_end(200, head);

    delete_ith_node(3, head);


    //! Listas simplemente enlazadas CON APUNTADOR AL FINAL
    node *head_t = NULL;
    node *tail = NULL;
    insert_at_end_with_tail(10, head_t, tail);
    insert_at_end_with_tail(20, head_t, tail);
    insert_at_end_with_tail(30, head_t, tail);
    insert_at_end_with_tail(40, head_t, tail);

    // return 0;
}

// head = new node(10);
// head->insert_in_index(25, 0);
// head->insert_at_end(20);
// head->insert_at_end(30);

// head->insert_in_index(15, 2);

// head = insert_at_head(5, head);
// while (head != NULL)
// {
//     cout << head->data << endl;
//     head = head->next;
// }