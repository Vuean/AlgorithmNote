#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
    return a > b;   // 可以理解为当a>b时，把a放在b前面
}

int main(){
    int a[] = {3, 1, 4, 2};
    sort(a, a+4, cmp);
    // sort(a, a+4);
    for(int i=0; i < 4; i++){
        cout << a[i] << " ";
    }
}