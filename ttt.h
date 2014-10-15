// Jeff Hamlin
// 6 June 2014
// ttt.h
// defines TicTacToe class

#ifndef _ttt_
#define _ttt_


#include <iostream>
#include <string>


using namespace std;

// Creates sctruct for players data
struct Player
{
	string name;
	char symbol;
	int score;
};


class TicTacToe
{
private:
	Player player1, player2;
    int currentWinner, tie;
    char board[3][3];
    
    
public:
    TicTacToe(int& tieGame, int& cWnr, Player& p1, Player& p2)
    {
        tie = tieGame;
        player1 = p1;
        player2 = p2;
        p1.name = "player 1";
        p2.name = "player 2";
        p1.symbol = 'X';
        p2.symbol = 'O';
        p1.score = 0;
        p2.score = 0;
        tieGame = 0;
        cWnr = 0;
        
        currentWinner = cWnr;
        tie = tieGame;
        player1 = p1;
        player2 = p2;
        
        // sets for loop, initializes board to '0'
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                board[i][j] = '0';
            }
        }
        
    }
    
    // setter functions
    void SetPlayers(char, Player&, Player&);
	void BoardReset();
    void ScoreReset(int&, Player&, Player&);
    
    // getter functions
    int GetWinner(int&, Player, Player);
    
    // other member functions
    char Menu1();
    char Menu2();
    void DisplayBoard();
    void ChoosePosition(int, Player, Player);
    bool CheckforWinner(int, int&, Player&, Player&);
    void Computer(int, Player, Player);
    void DisplayScore(int, Player, Player);
    
};


#endif /* defined(_ttt_) */
