#include <iostream>
#include <fstream>
using namespace std;

// argc = argument count, argv = argument vector
int main(int argc, char *argv[]){

    // // argumente
    // cout << argc << endl;
    // for(int i = 0; i < argc; i++){
    //     cout << "Arg " << i << " este " << argv[i] << endl;
    // }

    // //citire tastatura
    // int n; cin >> n;

    // //citire tastatura
    // ifstream fin;
    // int n; fin >> n;

    istream *in;

    if (argc == 1 || argc > 3){
        cout << "Usage: " << argv[0] << " 0/1" << endl;
        return 1;
    }

    int citire;
    citire = argv[1][0] - '0';

    if (citire == 1){
        in = &cin;
    } else {
        fstream* fin = new fstream("date.in");
        in = fin;
    }

    int n; *in >> n;
    int v[10];

    for(int i = 0; i < n; i++){
        *in >> v[i];
    }
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }

    cout << endl;

    return 0;
}