#include <iostream>
using namespace std;

class GameChecker // class to check the game conditions
{
private:
    /* data */
public:
    bool RuleKO;
    bool RuleKill;
    bool RuleSuicide;
    bool checkRuleKO(vector <vector <int>>);
    bool checkRuleKill(vector <vector <int>>);
    bool checkRuleSuicide(vector <vector <int>>);
};

bool GameChecker::checkRuleKO(vector<vector<int>>)
{
return false;
}

inline bool GameChecker::checkRuleKill(vector<vector<int>> board)
{
return false;
}

inline bool GameChecker::checkRuleSuicide(vector<vector<int>> board)
{
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board.size(); j++){
            if (i == 0 && j == 0){
                //check 2 (left-up corner)
                if (board[i][j] != board[i][j+1] && board[i][j]);
            }
            else if(i == 0 && j == board.size()-1){
                //check 2 (right-up corner)
            }
            else if(i == board.size()-1 && j == 0){
                // check 2 (left-bottom corner)
            }
            else if(i == board.size()-1 && j == board.size()-1){
                // check 2 (right-bottom corner)
            }
            else if(i == 0){
                // 3 up edge
            }
            else if(j == 0){
                // 3 left edge
            }
            else if(i == board.size()-1){
                // 3 bottom edge
            }
            else if(j == board.size()-1){
                // 3 right edge
            }
            else{
                // simple situations
            }
        }
    }
return true;
}


