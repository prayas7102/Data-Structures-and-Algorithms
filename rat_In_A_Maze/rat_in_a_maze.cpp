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

void ratInAMaze(int arr[][],int i, int j, vector<string> &paths, vector<vector<int>> &visited){
    
}

int main()
{
    // rat in a maze
    int arr[4][4]={{1,0,0,0},{1,1,0,0},{1,1,0,0},{0,1,1,1}};
    vector<string> paths;
    vector<vector<int>> visited;
    ratInAMaze(arr,0,0,paths,visited);
    printVectorString(paths);

    return 0;
}