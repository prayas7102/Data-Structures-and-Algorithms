#include <iostream>
#include <vector>
using namespace std;

void inline printVectorString(vector<string> s)
{
    for (auto i : s)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

int main()
{

    return 0;
}