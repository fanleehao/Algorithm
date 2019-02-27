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
//sample
//1 2 3 4 5 6 7
//3 5
//2
//out  4


int main()
{
    string line;
    stringstream ss;
    getline(cin, line);

    ss<<line;
    vector<int> vec;
    int i =0;
    while(ss>>i){vec.push_back(i);}     //通过stringtream和vector
    int vec_size = vec.size();

    int left, right;
    scanf("%d%d", &left, &right);
    int k;
    scanf("%d", &k);

    vector<int> subvec(vec.begin()  + left - 1, vec.begin() + right);
//    for(int j=0;j<subvec.size();j++){
//        printf("%d\t", subvec[j]);
//    }
    sort(subvec.begin(), subvec.end());
    printf("%d\n", subvec[k-1]);



    return 0;
}
