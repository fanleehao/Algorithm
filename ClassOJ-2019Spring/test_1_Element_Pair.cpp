#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<sstream>
#include<iomanip>
#define LL long long         //9223372036854775807(19位) 2的63次方
#define debug cout<<"******"<<endl;
#define INF 0x3fffffff
#define MAX 101000
using namespace std;

int main(){
    string line;
    stringstream ss;
    getline(cin, line);
    ss<<line;

    vector<int> arr;
    int i =0;
    while(ss>>i){arr.push_back(i);}


    int N;
    scanf("%d", &N);
    int res = 0;
    int len = arr.size();
    sort(arr.begin(), arr.end());

    if(N < arr[0]){
        printf("%d\n", res);
        return 0;
    }
    for(int i = 0; i < len; i++){
        if(arr[i] > N) break;
        int temp;
        for(int j = i + 1; j < len; j++){
            if(arr[i] + arr[j] > N)
                break;
            else if(arr[i] + arr[j] == N)
                res++;
        }
    }

    printf("%d\n", res);
    return 0;
}
