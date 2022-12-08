#include <iostream>
#include <vector>
using namespace std;



class Numbers {
public:
    int x;
};



int main(){
    vector<Numbers> listofnumbers;
    Numbers *x1 = new Numbers;
    Numbers *x2 = new Numbers;
    Numbers *x3 = new Numbers;
    Numbers *x4 = new Numbers;

    x1->x = 2;
    x2->x = 1;
    x3->x = 3;
    x4->x = 7;

    listofnumbers.push_back(*x1);
    listofnumbers.push_back(*x2);
    listofnumbers.push_back(*x3);
    listofnumbers.push_back(*x4);

    vector<Numbers>::iterator it;

    for(it = listofnumbers.begin(); it!=listofnumbers.end(); ++it){
        std::cout<<it->x;
    }

    return 0;
}