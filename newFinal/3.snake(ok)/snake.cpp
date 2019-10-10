#include<iostream>
using namespace std;
//3.45
class Solution{
public:
  int get(int i,int j,int m,int n){
    int L1=max(i+j-n+1,0);
    int L2=min(n,i+j+1);
    int L3=max(i+j+1-m+1,0);
    int res1=L1*n+((L2-L3+1)*(L2+L3)/2);
    if((i+j)%2==1) return res1-min(m-1-i,j);
    else return res1-min(n-1-j,i);
  }
  void printMat(int m,int n){
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        cout<<get(i,j,m,n)<<":";
      }
      cout<<endl;
    }
  }
};

int main(){
  Solution s;
  s.printMat(10,3);
  return 0;
}