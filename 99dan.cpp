#include <iostream>
using namespace std;

int main(){
    for (int i = 2; i < 10; i++){
        cout << "구구단" << i << "단" << endl;;
        for (int j = 1; j < 10; j++){
            cout << i << "X" << j << "=" << i*j << endl;
        }
    }
    return 0;
}
