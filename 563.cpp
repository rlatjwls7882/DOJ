#include "factorial.h"
#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    int r=1;
    while(n-->1)r*=n+1;
    return r;
}
