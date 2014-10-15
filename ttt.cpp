// Jeff Hamlin
// 6 June 2014
// ttt.cpp
// Implementation file for the TicTacToe class

#include "ttt.h"
#include <iostream>
#include <iomanip>
#include <string>

#define clear system("clear")

#define RESET      		"\033[0m"
#define BLACK      		"\033[30m"          /* Black */
#define RED                     "\033[31m"          /* Red */
#define GREEN   		"\033[32m"          /* Green */
#define YELLOW     		"\033[33m"          /* Yellow */
#define BLUE        		"\033[34m"          /* Blue */
#define MAGENTA  	   	"\033[35m"          /* Magenta */
#define CYAN      		"\033[36m"          /* Cyan */
#define WHITE       		"\033[37m"          /* White */
#define BOLDBLACK	   	"\033[1m\033[30m"   /* Bold Black */
#define BOLDRED                 "\033[1m\033[31m"   /* Bold Red */
#define BOLDGREEN               "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW              "\033[1m\033[33m"   /* Bold Yellow */
#define BOLDBLUE                "\033[1m\033[34m"   /* Bold Blue */
#define BOLDMAGENTA             "\033[1m\033[35m"   /* Bold Magenta */
#define BOLDCYAN                "\033[1m\033[36m"   /* Bold Cyan */


// function displays menu, returns user's choice
char TicTacToe::Menu1()
{
    string choice;
    
    // show logo
    clear;
    cout <<"------------------------------------------------------------------------  " <<endl;
	cout <<"****** ******   ****  ******     ***       ****   ******   ****    *****  " <<endl;
	cout <<"****** ******  ****** ******    ** **     ******  ******  ******   **     " <<endl;
	cout <<"  **     **   **        **     **   **   **         **   **    **  ****   " <<endl;
	cout <<"  **     **   **        **    ** *** **  **         **   **    **  ****   " <<endl;
	cout <<"  **   ******  ******   **   **       **  ******    **    ******   **     " <<endl;
	cout <<"  **   ******   ****    **  **         **  ****     **     ****    *****  " <<endl;
	cout <<"------------------------------------------------------------------------  " <<endl;
	cout <<"                             Jeff Hamlin                                  " <<endl;
    
    cout << "Press enter to start game ...";
    cin.get();
    clear;
    
    // validates choice
    while(choice Jef!= "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && toupper(choice[0]) != 'E')
    {
	
        cout << "Please enter your choice:";
        cout << "\n\t1) Start a new game with two new players.";
        cout << "\n\t2) New game against computer";
        cout << "\n\t3) Quick start game with two players.";
        cout << "\n\t4) View current winner.";
        cout << "\n\t5) Exit (You can press 'E' or 'Exit' to during gameplay quit game)";
        cout << RESET << "\n>>";
        cin >> choice;
        
        if(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && toupper(choice[0]) != 'E')
        {
            clear;
            cout << RED << "Error: Invalid choice. Please choose either 1, 2. 3,  4 or 5." << endl;
        }
    }
    clear;
    
    
    return choice[0];
    
}

char TicTacToe::Menu2()
{
    string choice;
    
    clear;
    
    // validates choice
    while(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && toupper(choice[0]) != 'E')
    {
	
        cout << "Please enter your choice:";
        cout << "\n\t1) Start a new game with two new players.";
        cout << "\n\t2) New game against computer";
        cout << "\n\t3) Continue current game with the same two players.";
        cout << "\n\t4) View current winner.";
        cout << "\n\t5) Exit (You can press 'E' or 'Exit' to during gameplay quit game) ";
        cout << RESET << "\n>>";
        cin >> choice;
        
        if(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && toupper(choice[0]) != 'E')
        {
            clear;
            cout << RED << "Error: Invalid choice. Please choose either 1, 2. 3, 4 or 5." << endl;
        }
    }
    clear;

    return choice[0];
    
}

// sets player's name
void TicTacToe::SetPlayers(char MenuChoice, Player &p1, Player &p2)
{    
    // prompts for player one's name
    cout << "Player 1, please enter your name: ";
    cin.ignore();
    getline(cin, p1.name);
    cout << endl;
    cout << p1.name << " would you like to be X's, or O's?  ";
    cin >> p1.symbol;
    
    // validates symbol choice
    while(toupper(p1.symbol) != 'X' && toupper(p1.symbol) != 'O')
    {
        clear;
    	//re;
        cout << RED << "Error: choice must be either and 'X' or an 'O'" << endl;
        cout <<" \n" << p1.name << " would you like to be X's, or O's?  " << RESET;
        cin >> p1.symbol;
    }
    
    // saves player 2's symbol as opposite of player 1's
    p1.symbol = toupper(p1.symbol);
    if (p1.symbol == 'X')
        p2.symbol = 'O';
    
    else
        p2.symbol = 'X';
    
    
    clear;
    
    
    // if playing against computer
    if (MenuChoice == '2')
    {
        p2.name = "Computer";
        player2 = p2;
    }
    
    // if playing against another user
    else
    {
        // prompts for player 2's name
        cout << "Player 2, please enter your name: ";
        cin.ignore();
        getline(cin, p2.name);
        player2 = p2;
    }
    
    player1 = p1;
    
    clear;
}


// resets the board
void TicTacToe::BoardReset()
{
    // resets board
	board[0][0] = '1';
	board[0][1] = '2';
	board[0][2] = '3';
	board[1][0] = '4';
	board[1][1] = '5';
	board[1][2] = '6';
	board[2][0] = '7';
	board[2][1] = '8';
	board[2][2] = '9';
	cout << endl <<endl;
    cout <<"\t" << "-------------" << endl; // top - placement
	for (int i = 0; i<3; i++)
	{
        cout << "\t";
		for (int j=0; j<3; j++)
		{
			cout << "| " << board[i][j] << " ";
		}
		cout << "| ";
		cout << endl <<"\t" << "-------------" << endl;
	}
}


// displays the board
void TicTacToe::DisplayBoard()
{
    cout << endl <<endl;
    cout <<"\t" << "-------------" << endl; // top - placement
	for (int i = 0; i<3; i++)
	{
        cout << "\t";
		for (int j=0; j<3; j++)
		{
		
			// if P1, display char in cyan
			if (board[i][j] == 'X')
					cout << "| " << CYAN << board[i][j]  << RESET << " ";
				
			// if if P2, display char in magenta
			else if (board[i][j] == 'O')
				cout << "| " << MAGENTA << board[i][j]  << RESET << " ";
			
			// else if numbered
			else
				cout << "| " << board[i][j] << " ";
		}
		cout << "| ";
		cout << endl <<"\t" << "-------------" << endl;
	}
    
}


// function allows user to choose their position
void TicTacToe::ChoosePosition(int count, Player p1, Player p2)
{
    char position;
    bool validate = false;
    
    // Player 1 choice
    if (count%2 == 1)
    {
        // Loops while player 1 chooses a taken position
        //    validate becomes true when player chooses open position
        while (validate == false)
        {
            
            cout <<"\n" <<  p1.name << ". Please choose a position: ";
            cin >> position;
            
            if (position == '1')
            {
                if(board[0][0] == 'X' || board[0][0] == 'O')
                {
                    cout << RED << "Error: Position Taken" <<endl;
                }
                else
                {
                    board[0][0] = (p1.symbol);
                    validate = true;
                }
            }
            
            else if (position == '2')
            {
                if(board[0][1] == 'X' || board[0][1] == 'O')
                {
                    cout << RED <<"Error: Position Taken" <<endl;
                }
                else
                {
                    board[0][1] = (p1.symbol);
                    validate = true;
                }
            }
            
            else if (position == '3')
            {
                if(board[0][2] == 'X' || board[0][2] == 'O')
                {
                    cout << RED <<"Error: Position Taken" <<endl;
                }
                else
                {
                    board[0][2] = (p1.symbol);
                    validate = true;
                }
            }
            
            else if (position == '4')
            {
                if(board[1][0] == 'X' || board[1][0] == 'O')
                {
                    cout << RED <<"Error: Position Taken" <<endl;
                }
                
                else
                {
                    board[1][0] = (p1.symbol);
                    validate = true;
                }
            }
            
            else if (position == '5')
            {
                if(board[1][1] == 'X' || board[1][1] == 'O')
                {
                    cout << RED <<"Error: Position Taken" <<endl;
                }
                else
                {
                    board[1][1] = (p1.symbol);
                    validate = true;
                }
            }
            
            else if (position == '6')
            {
                if(board[1][2] == 'X' || board[1][2] == 'O')
                {
                    cout << RED <<"Error: Position Taken" <<endl;
                }
                else
                {
                    board[1][2] = (p1.symbol);
                    validate = true;
                }
            }
            
            else if (position == '7')
            {
                if(board[2][0] == 'X' || board[2][0] == 'O')
                {
                    cout << RED <<"Error: Position Taken" <<endl;
                }
                else
                {
                    board[2][0] = (p1.symbol);
                    validate = true;
                }
            }
            
            else if (position == '8')
            {
                if(board[2][1] == 'X' || board[2][1] == 'O')
                {
                    cout << RED <<"Error: Position Taken" <<endl;
                }
                else
                {
                    board[2][1] = (p1.symbol);
                    validate = true;
                }
            }
            
            else if (position == '9')
            {
                if(board[2][2] == 'X' || board[2][2] == 'O')
                {
                    cout << RED <<"Error: Position Taken" <<endl;
                }
                else
                {
                    board[2][2] = (p1.symbol);
                    validate = true;
                }
            }
            
            // if user chooses to exit program
            else if (toupper(position) == 'E')
            {
            	cout << "Program will now quit. Goodbye!" << endl; 
            	exit(0);
            }
            
            else
                cout << RED << "Error: Invalid choice";
            
        }   /* Ends validation while loop */
        
        cout << RESET; // Resets colors in case of error
        
    }       /* Ends player 1's choice */
    
    
    // Player 2 choice
    if (count%2 == 0)
    {
        // Loops while player 2 chooses a taken position
        // validate becomes true when player chooses open position
        while (validate == false)
        {
            
            cout <<"\n" <<  p2.name << ". Please choose a position: ";
            cin >> position;
            
            
            if (position == '1')
            {
                if(board[0][0] == 'X' || board[0][0] == 'O')
                {
                    cout << RED <<"Error: Position Taken" <<endl;
                }
                else
                {
                    board[0][0] = (p2.symbol);
                    validate = true;
                }
            }
            
            else if (position == '2')
            {
                if(board[0][1] == 'X' || board[0][1] == 'O')
                {
                    cout << RED <<"Error: Position Taken" <<endl;
                }
                else
                {
                    board[0][1] = (p2.symbol);
                    validate = true;
                }
            }
            
            else if (position == '3')
            {
                if(board[0][2] == 'X' || board[0][2] == 'O')
                {
                    cout << RED <<"Error: Position Taken" <<endl;
                }
                else
                {
                    board[0][2] = (p2.symbol);
                    validate = true;
                }
            }
            
            else if (position == '4')
            {
                if(board[1][0] == 'X' || board[1][0] == 'O')
                {
                    cout << RED <<"Error: Position Taken" <<endl;
                }
                
                else
                {
                    board[1][0] = (p2.symbol);
                    validate = true;
                }
            }
            
            else if (position == '5')
            {
                if(board[1][1] == 'X' || board[1][1] == 'O')
                {
                    cout << RED <<"Error: Position Taken" <<endl;
                }
                else
                {
                    board[1][1] = (p2.symbol);
                    validate = true;
                }
            }
            
            else if (position == '6')
            {
                if(board[1][2] == 'X' || board[1][2] == 'O')
                {
                    cout << RED <<"Error: Position Taken" <<endl;
                }
                else
                {
                    board[1][2] = (p2.symbol);
                    validate = true;
                }
            }
            
            else if (position == '7')
            {
                if(board[2][0] == 'X' || board[2][0] == 'O')
                {
                    cout << RED <<"Error: Position Taken" <<endl;
                }
                else
                {
                    board[2][0] = (p2.symbol);
                    validate = true;
                }
            }
            
            else if (position == '8')
            {
                if(board[2][1] == 'X' || board[2][1] == 'O')
                {
                    cout << RED <<"Error: Position Taken" <<endl;
                }
                else
                {
                    board[2][1] = (p2.symbol);
                    validate = true;
                }
            }
            
            else if (position == '9')
            {
                if(board[2][2] == 'X' || board[2][2] == 'O')
                {
                    cout << RED <<"Error: Position Taken" <<endl;
                }
                else
                {
                    board[2][2] = (p2.symbol);
                    validate = true;
                }
            }
            
            // if user chooses to exit program
            else if (toupper(position) == 'E')
            {	
            	cout << "Thank you for playing. Goodbye!" << endl; 
            	exit(0);
            }
            	
            else
                cout << RED << "Error: Invalid choice";
            
        }   /* Ends validation while loop */
        
        cout << RESET; // Resets colors in case of error
        
    }       /* Ends player 1's choice */
    
    clear;
}


// function checks if there is a winner
bool TicTacToe::CheckforWinner(int count, int &tieGame, Player &p1, Player &p2)
{
    bool winner = false;
    
    // checks for winner
    if ((board[0][0] == board[0][1] && board[0][0] == board[0][2]) ||   // Top row
        (board[1][0] == board[1][1] && board[1][0] == board[1][2]) ||   // Middle row
        (board[2][0] == board[2][1] && board[2][0] == board[2][2]) ||   // Bottom row
        (board[0][0] == board[1][0] && board[0][0] == board[2][0]) ||   // Left column
        (board[0][1] == board[1][1] && board[0][1] == board[2][1]) ||   // Middle column
        (board[0][2] == board[1][2] && board[0][2] == board[2][2]) ||   // Right column
        (board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||   // Diagonal, top left to bottom right (\)
        (board[2][0] == board[1][1] && board[2][0] == board[0][2]))     // Diagonal, top right to bottom left (/)
    {
        winner = true;
        // if player one wins
        if(count %2 == 1)
        {
            cout << p1.name << " is the winner! " <<endl <<endl;
            cout << "Press enter to continue ...";
            cin.ignore().get();
            p1.score++;     // adds score to player one
        }
        // if player two wins
        else
        {
            cout << p2.name << " is the winner! " <<endl <<endl;
            cout << "Press enter to continue ...";
            cin.ignore().get();
            p2.score++;     // adds score to player two
        }
    }   /*  Ends checking for a winner  */
    
    
	// if there is no winner
    else
        winner = false;
    
    
    // Checks for cats game (tie game) if there is no winner
    if (winner == false)
    {
		// if each space is filled with an 'X' or 'O', not numbered
		// and there was no winner from previous if statement
        if ((board[0][0] == 'X' || board[0][0] == 'O')  &&
            (board[0][1] == 'X' || board[0][1] == 'O') &&
            (board[0][2] == 'X' || board[0][2] == 'O') &&
            (board[1][0] == 'X' || board[1][0] == 'O') &&
            (board[1][1] == 'X' || board[1][1] == 'O') &&
            (board[1][2] == 'X' || board[1][2] == 'O') &&
            (board[2][0] == 'X' || board[2][0] == 'O') &&
            (board[2][1] == 'X' || board[2][1] == 'O') &&
            (board[2][2] == 'X' || board[2][2] == 'O'))
        {
            winner = true;
            cout << "TIE GAME" << endl;
            tieGame++;
            cout << "Press enter to continue ...";
            cin.ignore().get();
        }  /*  Ends checking for a tie  */
        
        // if there is no winner, or tie
        else
            winner = false;
        
    }
    return winner;
}


// Function displays player's scores
void TicTacToe::DisplayScore(int tieGame, Player p1, Player p2)
{
    if (p1.score > p2.score)
	{
    	cout << endl;
    	cout << left << setw(20) << "Name" << right << setw(4) << "Wins" << setw(6) << "Loses" << setw(5) << "Ties";
    	cout << "\n-----------------------------\n";
    	cout << BOLDBLUE;
    	cout << left << setw(20) << p1.name << right << setw(4) << p1.score << setw(6) << p2.score << setw(5) << tieGame << endl;
    	cout << RESET;
    	cout << left << setw(20) << p2.name << right << setw(4) << p2.score << setw(6) << p1.score << setw(5) << tieGame << endl;
    	cout << endl;
    }
    
    else if (p2.score > p1.score)
    {
 	  	cout << endl;
		cout << left << setw(20) << "Name" << right << setw(4) << "Wins" << setw(6) << "Loses" << setw(5) << "Ties";
  	  	cout << "\n-----------------------------\n";
  	  	cout << BOLDBLUE;
  	  	cout << left << setw(20) << p2.name << right << setw(4) << p2.score << setw(6) << p1.score << setw(5) << tieGame << endl;
  	  	cout << RESET;
  	  	cout << left << setw(20) << p1.name << right << setw(4) << p1.score << setw(6) << p2.score << setw(5) << tieGame << endl;
  	  	cout << endl;
    }
    
    else
    {
    	cout << endl;
		cout << left << setw(20) << "Name" << right << setw(4) << "Wins" << setw(6) << "Loses" << setw(5) << "Ties";
  	  	cout << "\n-----------------------------\n";
  	  	cout << left << setw(20) << p1.name << right << setw(4) << p1.score << setw(6) << p2.score << setw(5) << tieGame << endl;
  	  	cout << left << setw(20) << p2.name << right << setw(4) << p2.score << setw(6) << p1.score << setw(5) << tieGame << endl;
  	  	cout << endl;
    }
    
    cout << "Press enter to continue ...";
    cin.get();
}

// resets user's scores
void TicTacToe::ScoreReset(int &tieGame, Player &p1, Player &p2)
{
    tieGame = 0;
    p1.score = 0;
    p2.score = 0;
}

// determines who is currently winning
int TicTacToe::GetWinner(int &cWnr, Player p1, Player p2)
{
	// if tie game
	if (p1.score == p2.score)
		cWnr = 0;
    
    // if Player 1 is winning
	else if (p1.score > p2.score)
		cWnr = 1;
    
    // if Player 2 is winning
	else if (p1.score < p2.score)
		cWnr = 2;
		
	return cWnr;
}
