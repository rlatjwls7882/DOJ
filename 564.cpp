#include "digit_sum.h"
#include<bits/stdc++.h>
using namespace std;

int digit_sum(int n){
    string s=to_string(n);
    int r=0;
    for(auto e:s)r+=e-'0';
    return r;
}
