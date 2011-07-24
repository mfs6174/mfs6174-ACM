/*
ID: mfs6174
PROG: faster read
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

inline long long  get()
{
    char c;
    while (c=getchar(),c<'0'||c>'9');
    long long ret=c-'0';
    while (c=getchar(),c>='0'&&c<='9') ret=ret*10+c-'0';
    return ret;
}

