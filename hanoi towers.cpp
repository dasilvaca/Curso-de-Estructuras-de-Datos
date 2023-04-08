#include<iostream>

using namespace std;

typedef struct node
{
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

} node;

// Push
void push(int data, node *&top)
{
    node *new_node = new node(data);
    new_node->next = top;
    top = new_node;
    return;
}

// Peek
int peek(node *&top)
{
    if (top)
        return top->data;
    cout << "Error, stack is empty";
    return -1;
}

// Pop
int pop(node *&top)
{
    node *temp = top;
    int data = temp->data;
    top = top->next;
    delete temp;
    return data;
}

// enum tower = {A, B, C};

int main()
{

    node *stackA = NULL, *stackB = NULL, *stackC = NULL;
    bool valid_secuence = true;
    int DiskAmount = 3;
    for (int i = 1; i <= DiskAmount; i++)
    {
        push(1, stackA);
    }
    string Mov = "";
    while (Mov != "X X")
    {
        cin >> Mov;
        // Mov[0] --> Source
        // Mov[2] --> Destination
        int piece;
        char P, Q;
        P = Mov[0];
        Q = Mov[2];
        if (P == 'A')
        {
            if (stackA != NULL)
                piece = pop(stackA);
            else
                valid_secuence = false;
        }
        else if (P == 'B')
        {
            if (stackB != NULL)
                piece = pop(stackB);
            else
                valid_secuence = false;
        }
        else if (P == 'C')
        {
            if (stackC != NULL)
                piece = pop(stackC);
            else
                valid_secuence = false;
        }
        else valid_secuence = false;
        if (valid_secuence){
            if (Q == 'A') push(piece, stackA);
            else if (Q == 'B') push(piece, stackB);
            else if (Q == 'C') push(piece, stackC);
        }

    }

    return 0;
}