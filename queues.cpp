#include<iostream>


using namespace std;

typedef struct node{
    int data;
    node* next;

    node(int data){
        this -> data = data;
        this -> next = NULL;
    };
}node;

// Enqueue
void enqueue(int data, node* &front, node* &rear){
    node* new_node = new node(data);
    if (front == NULL){
        front = new_node;
        rear = front;
        return;
    }
    rear -> next = new_node;
    rear = new_node;
    return;
}

// Dequeue
int dequeue(node* &front){
    node* temp = front;
    int data = temp -> data;
    front = front -> next;
    delete temp;
    return data;
}

typedef struct revendedor{
    int boletas;
    int id;
    revendedor* next;

    revendedor(int boletas, int id){
        this -> boletas = boletas;
        this -> id = id;
        this -> next = NULL;
    };
}revendedor;

// Enqueue
void enqueue(int boletas, int id, revendedor* &front, revendedor* &rear){
    revendedor* new_node = new revendedor(boletas, id);
    if (front == NULL){
        front = new_node;
        rear = front;
        return;
    }
    rear -> next = new_node;
    rear = new_node;
    return;
}

// Dequeue
pair<int, int> dequeue(revendedor* &front){
    revendedor* temp = front;
    int boletas = temp -> boletas;
    int id = temp -> id;
    front = front -> next;
    delete temp;
    return {id, boletas};
}


int main(){
    int n, t; // N revendedores y T boletas
    cin>>n>>t;
    revendedor *front = NULL, *rear = NULL;
    bool tickets_available = true;
    int i = 1;
    for(; i <= n; i ++){
        int r, k; // r identificador del revendedor, k la cantidad de boletas que compra
        cin>>r>>k;
        if (t - k > 0) {
            if (i % 5) enqueue(k, r, front, rear);
            t -= k;
        }
        else{
            cout<<k<<' '<<t<<'\n';
            tickets_available = false;
            }
    }
    for (; tickets_available && front != NULL; i= (i + 1) % 5){
        pair<int, int> rev = dequeue(front); // rev.first = id, rev.second = boletas
        if (t - rev.second > 0){
            if (i % 5) enqueue(rev.second, rev.first, front, rear);
            t -= rev.second;
        }
        else{
            cout<<rev.first<<' '<<t<<'\n';
            tickets_available = false;
        }
    }

    if (tickets_available) cout<<"quedaron boletas disponibles\n";
}