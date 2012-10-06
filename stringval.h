#include<string>
#include<sstream>

int val(const string &x)
{
    istringstream t(x);
    int r;
    t>>r;
    return r;
}

string str(int x)
{
    ostringstream t;
    t<<x;
    return t.str();
}
