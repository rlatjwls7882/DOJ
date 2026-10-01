#include<bits/stdc++.h>
#include "calculator.h"
using namespace std;

int calculate(int a, int b, char op) {
    if(op=='*')return a*b;
    if(op=='+')return a+b;
    if(op=='-')return a-b;
    return a/b;
}
