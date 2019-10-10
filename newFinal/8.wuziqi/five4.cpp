//9.46
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    bool checkBoard(vector<vector<int>> board){
        //1.输赢个数
        int m=board.size();
        int n=board[0].size();
        int num1=0;
        int num2=0;
        int lastNum=0;
        bool hasWinner=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    num1++;
                }
                if(board[i][j]==2){
                    num2++;
                }
            }
        }
        cout<<num1<<":"<<num2<<endl;
        if(num1==num2){
            lastNum=2;
        }else if(num1==num2+1){
            lastNum=1;
        }else{
            return false;
        }
        vector<string> cross;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            	if(board[i][j]==0) continue;
                if(board[i][j]==lastNum){
                    if(checkAll(i,j,board)){
                        vector<string> tmp=getAll(i,j,board);
                        if(!hasWinner){
                            hasWinner=true;
                            cross=getU(i,j,board);
                        }
                        else{
                            //求交集
                            vector<string> ivec(5);
                            sort(cross.begin(),cross.end());
                            sort(tmp.begin(),tmp.end());
                            auto it=set_intersection(cross.begin(),cross.end(),tmp.begin(),tmp.end(),ivec.begin());
                            ivec.resize(it-ivec.begin());
                            cross=ivec;
                            if(cross.empty()){
                                return false;
                            }
                        }
                    }
                    
                }
                else{
                    if(checkAll(i,j,board)){return false;}
                }
            }
        }
        if(hasWinner&&cross.empty()){
            cout<<"haha"<<endl;
            return false;
        }
        return true;
    }
    bool checkAll(int i,int j,vector<vector<int>> board){
        if(checkU( i, j, board)||checkU( i, j,board)||checkU( i, j, board)||checkU( i, j, board)) return true;
        return false;
    }
    vector<string> getAll(int i,int j,vector<vector<int>> board){
        vector<string> res;
        if (checkU( i, j, board)){
            for(string s:getU(i,j, board)){
                res.push_back(s);
            }
        }
        if (checkRU( i, j, board)){
            for(string s:getRU(i,j,board)){
                res.push_back(s);
            }
        }
        if (checkR( i, j, board)){
            for(string s:getR(i,j,board)){
                res.push_back(s);
            }
        }
        if (checkRD( i, j, board)){
            for(string s:getRD(i,j,board)){
                res.push_back(s);
            }
        }
        return res;
    }
    bool checkU(int i,int j,vector<vector<int>> board){
        int num=board[i][j];
        int m=board.size();
        int n=board[0].size();
        if(i<4){
            return false;
        }
        for(int k=0;k<5;k++){
            if(board[i-k][j]!=num)
                return false;
        }
        return true;
    }
    vector<string> getU(int i,int j,vector<vector<int>> board){
        vector<string> res;
        int num=board[i][j];
        int m=board.size();
        int n=board[0].size();
        for(int k=0;k<5;k++){
            res.push_back(to_string(i-k)+"-"+to_string(j));
        }
        return res;
    }
    bool checkRU(int i,int j,vector<vector<int>> board){
        int num=board[i][j];
        int m=board.size();
        int n=board[0].size();
        if(i<4||j>n-5){
            return false;
        }
        for(int k=0;k<5;k++){
            if(board[i-k][j+k]!=num)
                return false;
        }
        return true;
    }
    vector<string> getRU(int i,int j,vector<vector<int>> board){
        vector<string> res;
        int num=board[i][j];
        int m=board.size();
        int n=board[0].size();
        for(int k=0;k<5;k++){
            res.push_back(to_string(i-k)+"-"+to_string(j+k));
        }
        return res;
    }
    bool checkR(int i,int j,vector<vector<int>> board){
        int num=board[i][j];
        int m=board.size();
        int n=board[0].size();
        if(j>n-5){
            return false;
        }
        for(int k=0;k<5;k++){
            if(board[i][j+k]!=num)
                return false;
        }
        return true;
    }
    vector<string> getR(int i,int j,vector<vector<int>> board){
        vector<string> res;
        int num=board[i][j];
        int m=board.size();
        int n=board[0].size();
        for(int k=0;k<5;k++){
            res.push_back(to_string(i)+"-"+to_string(j+k));
        }
        return res;
    }
    bool checkRD(int i,int j,vector<vector<int>> board){
        int num=board[i][j];
        int m=board.size();
        int n=board[0].size();
        if(i>m-5||j>n-5){
            return false;
        }
        for(int k=0;k<5;k++){
            if(board[i+k][j+k]!=num)
                return false;
        }
        return true;
    }
    vector<string> getRD(int i,int j,vector<vector<int>> board){
        vector<string> res;
        int num=board[i][j];
        int m=board.size();
        int n=board[0].size();
        for(int k=0;k<5;k++){
            res.push_back(to_string(i+k)+"-"+to_string(j+k));
        }
        return res;
    }
    
};
int main(){
    //0
    vector<vector<int>> board({
        {0,0,0,0,0,1,0,2,0,0},
        {0,0,0,0,0,1,0,2,0,0},
        {0,0,0,0,0,1,0,2,0,0},
        {0,0,0,0,0,1,0,2,0,0},
        {0,0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,1,0,2,0,0},
        {0,0,0,0,0,1,0,0,2,0},
        {0,0,0,0,0,1,0,2,0,0},
        {0,0,0,0,0,1,0,2,0,0},
        {0,0,0,0,0,1,0,2,0,0},
    });
    //1
    vector<vector<int>> board2({
        {2,0,2,0,2,1,0,2,0,0},
        {2,0,2,0,2,1,0,2,1,0},
        {0,0,0,0,2,1,0,1,0,0},
        {0,0,2,0,2,1,1,2,0,0},
        {0,0,0,1,1,1,1,1,0,0},
        {0,0,0,0,1,1,0,2,0,0},
        {0,0,0,1,0,1,0,0,2,0},
        {0,0,1,0,0,1,0,2,0,0},
        {2,1,0,0,0,1,0,2,0,0},
        {1,0,2,0,0,2,0,2,0,0},
    });
    //1
    vector<vector<int>> board3({
        {2,0,2,0,2,1,0,2,0,0},
        {2,0,2,0,2,1,0,2,1,0},
        {0,0,0,0,2,1,0,1,0,0},
        {0,0,2,0,2,1,1,2,0,0},
        {0,0,0,1,1,1,1,1,0,0},
        {0,0,0,0,1,1,0,2,0,0},
        {0,0,0,1,0,1,0,0,2,0},
        {0,0,1,0,0,1,0,2,0,0},
        {2,1,0,0,0,1,0,2,0,0},
        {1,0,2,0,0,2,0,2,0,0},
    });
    vector<vector<int>> board4({
        {2,0,2,0,2,1,0,2,0,0},
        {2,0,2,0,2,1,0,2,1,0},
        {0,0,0,0,2,1,0,1,0,0},
        {0,0,2,0,2,1,1,2,0,0},
        {0,0,0,1,1,1,1,1,0,0},
        {0,0,0,0,1,1,0,2,2,0},
        {0,0,0,1,0,1,0,0,2,0},
        {0,0,1,0,0,1,0,2,2,0},
        {2,1,0,0,0,1,0,2,0,0},
        {1,0,2,0,0,1,0,2,0,0},
    });
    vector<vector<int>> board5({
        {1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    });
    Solution s;
    cout<<s.checkBoard(board)<<endl;
    cout<<s.checkBoard(board2)<<endl;
    cout<<s.checkBoard(board3)<<endl;
    cout<<s.checkBoard(board4)<<endl;
    cout<<s.checkBoard(board5)<<endl;
    return 0;
}
