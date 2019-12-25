#include<iostream>

using namespace std;

void queen(int x,int y,int board[8][8]){
    board[x][y] = 5;
    int a = x;
    do{
        a--;
        board[a][y] = 1;
    }while(a!=0);
    int b = x;
    do{
        b++;
        board[b][y] = 1;
    }while(b!=7);
}

void print(int board[8][8]){
    for(int i =0;i<8;i++){
        for(int j =0;j<8;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
}

int main(){
    int board[8][8] = {0};
    queen(2,2,board);
    print(board);
}