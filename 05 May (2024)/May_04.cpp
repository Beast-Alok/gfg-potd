#include <bits/stdc++.h>
using namespace std;

int main(){
    int x = 25;
    int i;
    for (i = 1; i*i < x; i++)
    {
        if(x%i == 0){
            cout<<i<<" ";
        }
    }
    if(i - (x/i) == 1){
        i--;
    }

    for (; i>= 1; i--)
    {
        if(x%i == 0){
            cout<<x/i<<" ";
        }
    }
    
    return 0;
}