#include <iostream>

using namespace std;

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

void insert_at_head(int data, node *head) // This costs O(1)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
    return;
};



int main()
{
    node *head = NULL;
    head = new node(10);
    head->insert_in_index(25, 0);
    head->insert_at_end(20);
    head->insert_at_end(30);

    head->insert_in_index(15, 2);

    insert_at_head(5, head);
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
    return 0;
}