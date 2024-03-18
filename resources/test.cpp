#include <iostream>

using namespace std;

struct info {
    int id;
    int val;
};

int main(){
    int x = 5;

    cout << "Adresa lui x: " << &x << endl;
    cout << "x: " << x << endl;

    int* ptr = &x;

    cout << endl;
    cout << "Adresa lui ptr: " << &ptr << endl;
    cout << "ptr: " << ptr << endl;
    cout << "Ce este stocat la adresa din ptr: " << *ptr << endl;

    info obj;
    obj.id = 0;
    obj.val = 24;
    
    info* ptrObj = &obj;
    cout << (*ptrObj).val << endl;
    cout << endl;
    cout << ptrObj -> val << endl;
    

    return 0;
}