#include<iostream>

using namespace std;

struct card{
    int value;
    char suit;
};



int main(){
    card c1, c2;
    c1.value = 10;
    c1.suit = 'H';
    c2.value = 5;
    c2.suit = 'D';
    cout << c1.value << c1.suit << endl;
    card *p1 = &c1;
    cout << p1->value << p1->suit << endl;
    return 0;

}