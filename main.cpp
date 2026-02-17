#include <iostream>
#include "normal_dentaku.hpp"
#include "base_n_num.hpp"
#include "rateAPI.hpp"

using namespace std;

void main(){
    cout << 123 << endl;
    int num;
    cin >> num;
    switch (num)
    {
    case 1:
        normalDentaku();
        break;
    case 2:
        baseNnum();
        break;
    case 3:
        rateAPI();
        break;
    
    default:
        break;
    }
    cout << "program end" << endl;
}
