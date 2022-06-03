/*************************************************************************
	> File Name: rand.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 26 Mar 2021 10:13:47 AM CST
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
    srand(time(0));
    int arr[26];
    int  sum = 0;
    for(int i = 0; i < 26; i++){
        arr[i] = rand() % 1000;
        sum += arr[i];
    }
    printf("26\n");
    for(int i = 0; i < 26; i++){
        printf("%c %lf\n", i + 'A', 1.0 *arr[i] / sum);
    }
    return 0;
}
