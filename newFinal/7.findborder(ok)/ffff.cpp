#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findU(vector<vector<char>> board,int x,int y,int m,int n,char K){
      int out=0;
      int in=x;
      while(out<in){
        int mid=(out+in)/2;
        bool hasEle=false;
        for(int i=0;i<n;i++){
          if(board[mid][i]==K){
            hasEle=true;
            break;
          }
        }
        if(!hasEle){out=mid+1;}//向内
        else{in=mid;}//向外
      }
      return in;
    }
    int findD(vector<vector<char>> board,int x,int y,int m,int n,char K){
      int out=m-1;
      int in=x;
      while(out>in){
        int mid=(out+in)/2+1;//+1
        bool hasEle=false;
        for(int i=0;i<n;i++){//
          if(board[mid][i]==K){//
            hasEle=true;
            break;
          }
        }
        if(!hasEle){out=mid-1;}//向内
        else{in=mid;}
      }
      return in;
    }
    int findL(vector<vector<char>> board,int x,int y,int m,int n,char K){
      int out=0;//
      int in=y;//
      while(out<in){
        int mid=(out+in)/2;
        bool hasEle=false;
        for(int i=0;i<m;i++){//
          if(board[i][mid]==K){//
            hasEle=true;
            break;
          }
        }
        if(!hasEle){out=mid+1;}//向内
        else{in=mid;}
      }
      return in;
    }
    int findR(vector<vector<char>> board,int x,int y,int m,int n,char K){
      int out=n-1;//
      int in=y;//
      while(out>in){
        int mid=(out+in)/2+1;
        bool hasEle=false;
        for(int i=0;i<m;i++){//
          if(board[i][mid]==K){//
            hasEle=true;
            break;
          }
        }
        if(!hasEle){out=mid-1;}//向内
        else{in=mid;}
      }
      return out;
    }
    void fun(vector<vector<char>> board,int x,int y){
      int m=board.size(),n=board[0].size();
      char K=board[x][y];
      cout<<findU(board,x,y,m,n,K)<<endl;
      cout<<findD(board,x,y,m,n,K)<<endl;
      cout<<findL(board,x,y,m,n,K)<<endl;
      cout<<findR(board,x,y,m,n,K)<<endl;
    }
};

int main() {
  vector<vector<char>> board({
    {'1','1','1','1','1','1','1','1','0','1'},
    {'1','0','0','0','0','0','0','1','0','1'},
    {'1','0','1','1','1','1','0','1','0','1'},
    {'1','0','1','0','0','1','0','1','0','1'},
    {'1','0','1','0','1','1','0','1','0','1'},
    {'1','0','1','0','0','0','0','1','0','1'},
    {'1','0','1','1','1','1','1','1','0','1'},
    {'1','0','0','0','0','0','0','0','0','1'},
    {'1','1','1','1','1','1','1','1','1','1'}
  });
  Solution s;
  s.fun(board,4,4);
  return 0;
}
