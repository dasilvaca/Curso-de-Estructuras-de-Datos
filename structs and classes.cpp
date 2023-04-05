#include <iostream>

using namespace std;

typedef struct card
{
    int value;
    char suit;
} card;
typedef struct punto
{
    int x;
    int y;
} punto;

int main()
{

    punto *p = new punto();
    p->x = 5;
    p->y = 10;
    int a = 5;
    int *puntero_a_entero = &a;
    int b = *puntero_a_entero;
    *puntero_a_entero = 10;
    card c1, c2;
    c1.value = 10;
    c1.suit = 'H';
    c2.value = 5;
    c2.suit = 'D';
    cout << c1.value << c1.suit << endl;
    card *p1 = &c1;
    cout << p1->value << p1->suit << endl;
    cout << sizeof(card) << endl;
    return 0;
}