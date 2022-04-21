#include <iostream>
#include<vector>
using namespace std;
string ans(string s){
        if(s=="one"){
            return "1";
        }
        if(s=="two"){
            return "2";
        }
        if(s=="three"){
            return "3";
        }
        if(s=="four"){
            return "4";
        }
        if(s=="five"){
            return "5";
        }
        if(s=="six"){
            return "6";
        }
        if(s=="seven"){
            return "7";
        }
        if(s=="eight"){
            return "8";
        }
        if(s=="nine"){
            return "9";
        }
}
int main()
{
    int n,j=0;
    string s = "two one nine six triple eight one six four";
    vector<string> s2;
    string s1;
    string k="";
    for(int i=0;s[i]!='\0';i++){
        if(s[i]==' '){
            s2.push_back(k);
            k="";
        }
        else {
            k = k + s[i];
        }
    }
    for(int i=0;i<s2.size();i++){
        if(s2[i]=="double"){
            s1+=ans(s2[i+1]);
            s1+=ans(s2[i+1]);
            i++;
            continue;
        }
        if(s2[i]=="triple"){
            s1+=ans(s2[i+1]);
            s1+=ans(s2[i+1]);
            s1+=ans(s2[i+1]);
            i++;
            continue;
        }
        s1+=ans(s2[i]);
    }
    cout<<s1;
    return 0;
}
