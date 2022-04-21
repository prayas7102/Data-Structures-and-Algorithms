#include <iostream>

using namespace std;

int main()
{
    int i=0,j=0,a[3][3]={{0,1,2}, {4,5,6}, {8,9,10}},toggle=1,retain=0;
    for(i=0;i<3;i++){
        if(toggle){
          for(j=retain;j<3;j++){
            cout<<a[j][i]<<endl;
          }
          retain=j-1;
        }
        else{
           for(j=retain;j>=0;j--){
            cout<<a[j][i]<<endl;
           }
           retain=0;
        }
        toggle=!toggle;
    }
    return 0;
}
