#include "power.h"
#include<bits/stdc++.h>
using namespace std;

int power(int a, int b){
    int r=1;
    while(b--)r*=a;
    return r;
}
