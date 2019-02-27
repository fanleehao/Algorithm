#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<sstream>
#include<iomanip>
#include<stack>
#include<map>
#include<bits/stdc++.h>
#define LL long long         //9223372036854775807(19位) 2的63次方
#define debug cout<<"******"<<endl;
#define INF 0x3fffffff
#define MAX 101000
using namespace std;
//素数和问题

int is_prime(int num)
{
    int n;
    for (n = 2; n <= num / 2; n++)
    {
        if (num % n == 0){
            return 0;
        }
    }
    return 1;
}
//https://practice.geeksforgeeks.org/problems/return-two-prime-numbers/0
int main(){
    int N;
    scanf("%d", &N);
    while(N--){
        int num;
        scanf("%d", &num);
        if(num==4)
        {
            cout<<"2 2"<<endl;
        }
        else if(num==6)
        {
            cout<<"3 3"<<endl;
        }
        else {
            for(int i = 2; i*i <= num; i++){
                if(is_prime(i) && is_prime(num - i)){
                    printf("%d %d\n", i, num - i);
                    break;
                }
            }
        }

    }
}
