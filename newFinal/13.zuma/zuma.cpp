#include<isotream>
using namespace std;
class Solution {
public:
    int findMinStep(string board, string hand) {
        unordered_map<char,int> have;
        for(char c:hand) ++have[c];
        int res=zoma(board,have);
        return res==INT_MAX?-1:res;
    }
    int zoma(string board,  unordered_map<char,int> &have){
        board=del(board);
        if(board.empty()) return 0;
        int j=0,res=INT_MAX;
        for(int i=0;i<=board.size();i++){
            if(i<board.size()&&board[i]==board[j]) continue;
            int need=3-(i-j);
            if(need<=have[board[j]]){
                have[board[j]]-=need;
                string newboard=board.substr(0,j)+board.substr(i);
                int t=zoma(newboard,have);
                if(t!=INT_MAX) res=min(res,need+t);
                have[board[j]]+=need;
            }
            j=i;
        }
        return res;
    }
    string del(string s){//删除连续三个的
        int j=0;
        for(int i=0;i<=s.size();i++){
            if(i < s.size()&&s[i]==s[j]) continue;
            if(i-j>=3){return del(s.substr(0,j)+s.substr(i));}
            else j=i;
        }
        return s;
    }
};