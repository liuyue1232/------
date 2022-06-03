/*************************************************************************
	> File Name: 1.string_match.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 05 Apr 2021 01:00:46 PM CST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;



int brute_force(const char *s, const char *t){
    for(int i = 0; s[i]; i++){
        int flag = 1;
        for(int j = 0; t[j]; j++){
            if(s[i+j] == t[j]) continue;
            flag = 0;
            break;
        }
        if(flag == 1) return i;
    }
    return -1;
}

void getNext(const char *t, int *next){
    next[0] = -1;
    int j = -1;
    for(int i = 1; t[i]; i++){
        while(j != -1 && t[j + 1] != t[i]) j = next[j];
        if(t[j + 1] == t[i]) j+=1;
        next[i] = j;
    }
    return;
}


int kmp(const char *s, const char *t){
    int n = strlen(t);
    int *next = (int *)malloc(sizeof(int) * n + 1);
    getNext(t,next);
    for(int i = 0, j = -1; s[i]; i++){
        while(j != -1 && s[i] - t[j + 1]) j = next[j];
        if(s[i] == t[j + 1]) j += 1;
        if(t[j + 1] == 0) return i - n + 1;
    }
    free(next);
    return -1;
}

int sunday(const char*s, const char *t){
    int offset[256];
    int n = strlen(t), m = strlen(s);
    for(int i = 0; i < 256; i++) offset[i] = n + 1;
    for(int i = 0; t[i]; i++) offset[t[i]]= n -i;
    for(int i = 0; i  + n <= m; i += offset[s[i+n]]){
        int flag = 1;
        for(int j = 0; t[j] && flag; j++){
            flag = flag && (s[i + j] == t[j]);
        }
        if(flag) return i;
    } 
    return -1;
}

int main(){
    char s[100], t[100];
    while(scanf("%s%s",s,t) != EOF){
        printf("brute_force(%s %s) = %d\n", s,t, brute_force(s,t));
        printf("kmp(%s %s) = %d\n",s,t,kmp(s , t));
        printf("sunday(%s %s) = %d\n", s,t,sunday(s,t));
    }

    return 0;
}

