// https://leetcode.com/problems/valid-sudoku/description/

// simple implementation, do as directed, use set to find duplicate
// TC : O(1), technically grid is fixed, 9x9
// SC : O(1), bcz again grid is fixed, 9x9

class Solution {
public:

    // genereic function to check validity for a 3x3 board
    bool check(vector<vector<char>>& board, unordered_set<char>& st, int x, int y){

        st.clear();
        for(int i=x; i<x+3; i++){
            for(int j=y; j<y+3; j++){
                if(board[i][j] != '.' && st.find(board[i][j]) != st.end()){
                    return false;
                }
                st.insert(board[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        // check each row
        unordered_set<char>st;
        for(int i=0; i<9; i++){
            
            st.clear();
            for(int j=0; j<9; j++){
                
                if(board[i][j] != '.' && st.find(board[i][j]) != st.end()){
                    return false;
                }
                st.insert(board[i][j]);
            }
        }

        // check each col
        for(int i=0; i<9; i++){
            
            st.clear();
            for(int j=0; j<9; j++){
                
                if(board[j][i] != '.' && st.find(board[j][i]) != st.end()){
                    return false;
                }
                st.insert(board[j][i]);
            }
        }

        // check all 3x3 boards
        if(!check(board, st, 0, 0)) return false;
        if(!check(board, st, 0, 3)) return false;
        if(!check(board, st, 0, 6)) return false;
        if(!check(board, st, 3, 0)) return false;
        if(!check(board, st, 3, 3)) return false;
        if(!check(board, st, 3, 6)) return false;
        if(!check(board, st, 6, 0)) return false;
        if(!check(board, st, 6, 3)) return false;
        if(!check(board, st, 6, 6)) return false;

        return true;
    }
};