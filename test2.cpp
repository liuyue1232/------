/*************************************************************************
	> File Name: test2.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 May 2021 08:04:23 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
#include<string>
#include<sstream>
#include<set>
#include<time.h>
#include<unordered_set>
#include<stack>
#include<stdint.h>
#include<queue>
using namespace std;

priority_queue<int> q;

int main(){
    int n, x, t, ans = 0;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &x);
        q.push(-x);
    }
    while(--n){
        t = 0;
        t -= q.top();
        q.pop();
        t -= q.top();
        q.pop();
        ans += t;
        q.push(-t);
    }
    printf("%d",ans);
    return 0;
}
