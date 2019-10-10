//3.20
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class Solution{
public:
  void mydel(string &s,char c){
    auto p=find(s.begin(),s.end(),c);
    s.erase(p);
  }
  bool hupai(string card){
    queue<string> q({card});
    while(!q.empty()){
      auto tmp=q.front();
      q.pop();
      //1.判断胡牌
      if(tmp.size()==2&&tmp[0]==tmp[1]) return true;
      //2.删除包子
      for(int i=2;i<tmp.size();i++){
        if(tmp[i]==tmp[i-1]&&tmp[i]==tmp[2-2]) 
          q.push(tmp.substr(0,i-2)+tmp.substr(i+1));
      }
      //3.删除顺子
      for(int i=0;i<7;i++){
        if(count(tmp.begin(),tmp.end(),'0'+i)>=1&&
           count(tmp.begin(),tmp.end(),'0'+i+1)>=1&&
           count(tmp.begin(),tmp.end(),'0'+i+2)>=1){
          string newStr=tmp;
          mydel(newStr,'0'+i);
          mydel(newStr,'0'+i+1);
          mydel(newStr,'0'+i+2);
          q.push(newStr);
        }
      }
        
    }
    return false;
  }
};
int main(){
  Solution s;
  string card1="11223344";
  cout<<s.hupai(card1)<<endl;
  return 0;
}