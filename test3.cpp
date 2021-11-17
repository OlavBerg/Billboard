#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {

    vector<int> int_list;
    int_list.push_back(8);
    int_list.push_back(3);
    int_list.push_back(4);

    for(int i : int_list) {
        cout << i << endl;
    }

    return 0;
}





/*
for(int i=0; i < vector.size(); i++){
   vector[i].doSomething();
}
*/