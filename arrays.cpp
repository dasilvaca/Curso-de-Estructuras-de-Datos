#include<iostream>


using namespace std;

int main(){
    int arr[5];
    cout << arr[3]<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<endl;
    }
    int *p = arr;
    return 0;
}