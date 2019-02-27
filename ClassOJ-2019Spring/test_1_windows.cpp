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
//4 3 5 4 3 3 6 7
//3
//out:27

LL sum(vector<int> &vec, int st, int en){
    LL total = 0;
    for(int i = st; i <= en; i++){
        total += vec[i];
    }
    //cout<<total<<endl;
    return total;
}

int main()
{
    string line;
    getline(cin, line);
    stringstream ss;
    ss<<line;
    int a[100];
//    cout<<ss<<endl;
    vector<int> vec;
    int i =0;
    while(ss>>i){vec.push_back(i);}     //通过stringtream和vector
    int vec_size = vec.size();
//    for(int i = 0; i < vec.size(); i++){
//        cout<<vec[i]<<" ";
//    }

    int width;
    cin>>width;

    int index = 0;
    LL res = 0;
    vector<int>::iterator max_item;
    while(index + width <= vec_size){
        //temp = vec;
        max_item = max_element(vec.begin() + index, vec.begin() + index + width);
        cout<<*max_item<<endl;
        res += *max_item;
        index++;
    }
    cout<<res<<endl;


    return 0;
}
