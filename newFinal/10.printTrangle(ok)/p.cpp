//2.33
#include<iostream>
#include<vector>
using namespace std;

vector<string> getTriangle(int N){
    if(N==1){
        return{" /\\ ",
               "/__\\"};
    }
    vector<string> pre=getTriangle(N-1);
    vector<string> res(2*pre.size(),string(2*pre[0].size(),' '));
    int m=pre.size();
    int n=pre[0].size();
    for(int i=0;i<pre.size();i++){
        for(int j=0;j<pre[i].size();j++){
            res[i][j+n/2]=pre[i][j];
            res[i+m][j]=pre[i][j];
            res[i+m][j+n]=pre[i][j];
        }
    }
    return res;
}

int main(){
    vector<string> res=getTriangle(4);
    for(string s:res){
        cout<<s<<endl;
    }
    return 0;
}
