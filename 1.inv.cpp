/*************************************************************************
	> File Name: 1.inv.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 11 Apr 2021 11:19:26 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main(){
    int inv[7] = {0};
    inv[1] = 1;
    for(int i = 2; i < 7; i++){
        inv[i] = ((-(7 / 2) * inv[7%i]) % 7 + 7)%7;
    }
    for(int i = 2; i < 7; i++){
        cout << i << ": " << inv[i] << endl;
    }
    return 0;
}
