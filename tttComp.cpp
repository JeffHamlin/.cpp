// Jeff Hamlin
// tttComp.cpp
// 16 June 2014
// This file controls the computer's turn

//#include "ttt.cpp"
#include "ttt.h"
#include <iostream>
#include <string>

using namespace std;

void TicTacToe::Computer(int count, Player p1, Player p2)
{
    char position;
    bool validate = false;
    int compChoice;
    int compCounter = 0;
    
    // seeds number for random computer choice
    srand(time(NULL));
    
    // Player 1 choice
    if (count%2 == 1)
    {
        // Loops while player 1 chooses a taken position
        // validate becomes true when player chooses open position
        while (validate == false)
        {
            
            cout <<"\n" <<  p1.name << ". Please choose a position: ";
            cin >> position;
            
            if (position == '1')
            {
                if(board[0][0] == 'X' || board[0][0] == 'O')
                {
                    cout << RED <<"Error: Position Taken" <<endl;
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
    
    
    /****************************************************
                     COMPUTER'S CHOICE              
    *****************************************************/
    
    if (count%2 == 0)
    {
        cout << p2.name << "'s turn.";
		
        // Loops while player 2 chooses a taken position
        //    validate becomes true and loop ends
		//	  when computer chooses open position
        while (validate == false)
        {
			// counter assures computer goes through other options. Without this,
			//   it will keep trying to choose same position even if it's taken already
            compCounter++;
			
            // checks if there is a winning spot for computer
            //   if computer is almost winning, it will choose the winning position.
            if (compCounter == 1)
            {
            if      (((board [0][1] == p2.symbol) && (board[0][1] == board[0][2])) ||           // Row 1
                     ((board [1][0] == p2.symbol) && (board[1][0] == board[2][0])) ||
                     ((board [1][1] == p2.symbol) && (board[1][1] == board[2][2])))
            {
                if (board[0][0] == 'X' || board[0][0] == 'O')
                {
                    compChoice = 1;
                }
                
                else
                {
                    board[0][0] = (p2.symbol);
                    compChoice = 1;
                    validate = true;
                }
            }
            }
            
            
            else if (compCounter == 2)
            {
            if (((board [0][0] == p2.symbol) && (board[0][0] == board[0][2])) ||
                     ((board [1][1] == p2.symbol) && (board[1][1] == board[2][1])))
            {
                if (board[0][1] == 'X' || board[0][1] == 'O')
                {
                    compChoice = 2;
                }
                else
                {
                    board[0][1] = (p2.symbol);
                    compChoice = 2;
                    validate = true;
                }
            }
            }
            
            
            else if (compCounter == 3)
            {
            if (((board [0][0] == p2.symbol) && (board[0][0] == board[0][1])) ||
                     ((board [1][2] == p2.symbol) && (board[1][2] == board[2][2])) ||
                     ((board [2][0] == p2.symbol) && (board[2][0] == board[1][1])))
            {
                if (board[0][2] == 'X' || board[0][2] == 'O')
                {
                    compChoice = 3;
                }
                
                else
                {
                    board[0][2] = (p2.symbol);
                    compChoice = 3;
                    validate = true;
                }
            }
            }
            
            
            else if (compCounter == 4)
            {
            if (((board [1][1] == p2.symbol) && (board[1][1] == board[1][2])) ||        // Row 2
                     ((board [0][0] == p2.symbol) && (board[0][0] == board[2][0])))
            {
                if (board[1][0] == 'X' || board[1][0] == 'O')
                {
                    compChoice = 4;
                }
                
                else
                {
                    board[1][0] = (p2.symbol);
                    compChoice = 4;
                    validate = true;
                }
            }
            }
            
            
            else if (compCounter == 5)
            {
            if (((board [1][0] == p2.symbol) && (board[1][0] == board[1][2])) ||
                     ((board [0][1] == p2.symbol) && (board[0][1] == board[2][1])) ||
                     ((board [0][0] == p2.symbol) && (board[0][0] == board[2][2])) ||
                     ((board [2][0] == p2.symbol) && (board[2][0] == board[0][2])))
            {
                if (board[1][1] == 'X' || board[1][1] == 'O')
                {
                    compChoice = 5;
                }
                
                else
                {
                    board[1][1] = (p2.symbol);
                    compChoice = 5;
                    validate = true;
                }
            }
            }
            
            
            else if (compCounter == 6)
            {
            if (((board [1][0] == p2.symbol) && (board[1][0] == board[1][1])) ||
                     ((board [0][2] == p2.symbol) && (board[0][2] == board[2][2])))
            {
                if (board[1][2] == 'X' || board[1][2] == 'O')
                {
                    compChoice = 6;
                }
                
                else
                {
                    board[1][2] = (p2.symbol);
                    compChoice = 6;
                    validate = true;
                }
            }
            }
            
            else if (compCounter == 7)
            {
            if (((board [2][1] == p2.symbol) && (board[2][1] == board[2][2])) ||        // Row 3
                     ((board [0][0] == p2.symbol) && (board[0][0] == board[1][0])) ||
                     ((board [1][1] == p2.symbol) && (board[1][1] == board[0][2])))
            {
                if (board[2][0] == 'X' || board[2][0] == 'O')
                {
                    compChoice = 7;
                }
                
                else
                {
                    board[2][0] = (p2.symbol);
                    compChoice = 7;
                    validate = true;
                }
            }
            }
            
            else if (compCounter == 8)
            {
            if(((board [2][0] == p2.symbol) && (board[2][0] == board[2][2])) ||
                    ((board [0][1] == p2.symbol) && (board[0][1] == board[1][1])))
            {
                if (board[2][1] == 'X' || board[2][1] == 'O')
                {
                    compChoice = 8;
                }
                
                else
                {
                    board[2][1] = (p2.symbol);
                    compChoice = 8;
                    validate = true;
                }
            }
            }
            
            else if (compCounter == 9)
            {
            if(((board [2][0] == p2.symbol) && (board[2][0] == board[2][1])) ||
                    ((board [0][2] == p2.symbol) && (board[0][2] == board[1][2])) ||
                    ((board [0][0] == p2.symbol) && (board[0][0] == board[1][1])))
            {
                if (board[2][2] == 'X' || board[2][2] == 'O')
                {
                    compChoice = 9;
                }
                
                else
                {
                    board[2][2] = (p2.symbol);
                    compChoice = 9;
                    validate = true;
                }
            }
            }	// End checking for computer's winning spot
            
            // checking if player 1 is about to win
            else if (compCounter == 10)
            {
            if      (((board [0][1] == p1.symbol) && (board[0][1] == board[0][2])) ||           // Row 1
                     ((board [1][0] == p1.symbol) && (board[1][0] == board[2][0])) ||
                     ((board [1][1] == p1.symbol) && (board[1][1] == board[2][2])))
            {
                if (board[0][0] == 'X' || board[0][0] == 'O')
                {
                    compChoice = 1;
                }
                
                else
                {
                    board[0][0] = (p2.symbol);
                    compChoice = 1;
                    validate = true;
                }
            }
            }
            
            
            else if (compCounter == 11)
            {
            if (((board [0][0] == p1.symbol) && (board[0][0] == board[0][2])) ||
                     ((board [1][1] == p1.symbol) && (board[1][1] == board[2][1])))
            {
                if (board[0][1] == 'X' || board[0][1] == 'O')
                {
                    compChoice = 2;
                }
                else
                {
                    board[0][1] = (p2.symbol);
                    compChoice = 2;
                    validate = true;
                }
            }
            }
            
            
            else if (compCounter == 12)
            {
            if (((board [0][0] == p1.symbol) && (board[0][0] == board[0][1])) ||
                     ((board [1][2] == p1.symbol) && (board[1][2] == board[2][2])) ||
                     ((board [2][0] == p1.symbol) && (board[2][0] == board[1][1])))
            {
                if (board[0][2] == 'X' || board[0][2] == 'O')
                {
                    compChoice = 3;
                }
                
                else
                {
                    board[0][2] = (p2.symbol);
                    compChoice = 3;
                    validate = true;
                }
            }
            }
            
            
            else if (compCounter == 13)
            {
            if (((board [1][1] == p1.symbol) && (board[1][1] == board[1][2])) ||        // Row 2
                     ((board [0][0] == p1.symbol) && (board[0][0] == board[2][0])))
            {
                if (board[1][0] == 'X' || board[1][0] == 'O')
                {
                    compChoice = 4;
                }
                
                else
                {
                    board[1][0] = (p2.symbol);
                    compChoice = 4;
                    validate = true;
                }
            }
            }
            
            
            else if (compCounter == 14)
            {
            if (((board [1][0] == p1.symbol) && (board[1][0] == board[1][2])) ||
                     ((board [0][1] == p1.symbol) && (board[0][1] == board[2][1])) ||
                     ((board [0][0] == p1.symbol) && (board[0][0] == board[2][2])) ||
                     ((board [2][0] == p1.symbol) && (board[2][0] == board[0][2])))
            {
                if (board[1][1] == 'X' || board[1][1] == 'O')
                {
                    compChoice = 5;
                }
                
                else
                {
                    board[1][1] = (p2.symbol);
                    compChoice = 5;
                    validate = true;
                }
            }
            }
            
            
            else if (compCounter == 15)
            {
            if (((board [1][0] == p1.symbol) && (board[1][0] == board[1][1])) ||
                     ((board [0][2] == p1.symbol) && (board[0][2] == board[2][2])))
            {
                if (board[1][2] == 'X' || board[1][2] == 'O')
                {
                    compChoice = 6;
                }
                
                else
                {
                    board[1][2] = (p2.symbol);
                    compChoice = 6;
                    validate = true;
                }
            }
            }
            
            else if (compCounter == 16)
            {
            if (((board [2][1] == p1.symbol) && (board[2][1] == board[2][2])) ||        // Row 3
                     ((board [0][0] == p1.symbol) && (board[0][0] == board[1][0])) ||
                     ((board [1][1] == p1.symbol) && (board[1][1] == board[0][2])))
            {
                if (board[2][0] == 'X' || board[2][0] == 'O')
                {
                    compChoice = 7;
                }
                
                else
                {
                    board[2][0] = (p2.symbol);
                    compChoice = 7;
                    validate = true;
                }
            }
            }
            
            else if (compCounter == 17)
            {
            if(((board [2][0] == p1.symbol) && (board[2][0] == board[2][2])) ||
                    ((board [0][1] == p1.symbol) && (board[0][1] == board[1][1])))
            {
                if (board[2][1] == 'X' || board[2][1] == 'O')
                {
                    compChoice = 8;
                }
                
                else
                {
                    board[2][1] = (p2.symbol);
                    compChoice = 8;
                    validate = true;
                }
            }
            }
            
            else if (compCounter == 18)
            {
            if(((board [2][0] == p1.symbol) && (board[2][0] == board[2][1])) ||
                    ((board [0][2] == p1.symbol) && (board[0][2] == board[1][2])) ||
                    ((board [0][0] == p1.symbol) && (board[0][0] == board[1][1])))
            {
                if (board[2][2] == 'X' || board[2][2] == 'O')
                {
                    compChoice = 9;
                }
                
                else
                {
                    board[2][2] = (p2.symbol);
                    compChoice = 9;
                    validate = true;
                }
            }
            }
            
            /******************************
             End checking for almost winner
             ******************************/
            
            
            // if no almost winner, computer chooses random position
            else if (compCounter == 19)
            {
                //generate a random number from 1 to 9
                compChoice = rand()%9 + 1;
                
                if (compChoice == 1)
                {
                    if(board[0][0] == 'X' || board[0][0] == 'O')
                        validate = false;
                    
                    else
                    {
                        board[0][0] = (p2.symbol);
                        validate = true;
                    }
                }
                
                else if (compChoice == 2)
                {
                    if(board[0][1] == 'X' || board[0][1] == 'O')
                        validate = false;
                    
                    else
                    {
                        board[0][1] = (p2.symbol);
                        validate = true;
                    }
                }
                
                else if (compChoice == 3)
                {
                    if(board[0][2] == 'X' || board[0][2] == 'O')
                        validate = false;
                    
                    else
                    {
                        board[0][2] = (p2.symbol);
                        validate = true;
                    }
                }
                
                else if (compChoice == 4)
                {
                    if(board[1][0] == 'X' || board[1][0] == 'O')
                        validate = false;
                    
                    else
                    {
                        board[1][0] = (p2.symbol);
                        validate = true;
                    }
                }
                
                else if (compChoice == 5)
                {
                    if(board[1][1] == 'X' || board[1][1] == 'O')
                        validate = false;
                    
                    else
                    {
                        board[1][1] = (p2.symbol);
                        validate = true;
                    }
                }
                
                else if (compChoice == 6)
                {
                    if(board[1][2] == 'X' || board[1][2] == 'O')
                        validate = false;
                    
                    else
                    {
                        board[1][2] = (p2.symbol);
                        validate = true;
                    }
                }
                
                else if (compChoice == 7)
                {
                    if(board[2][0] == 'X' || board[2][0] == 'O')
                        validate = false;
                    
                    else
                    {
                        board[2][0] = (p2.symbol);
                        validate = true;
                    }
                }
                
                else if (compChoice == 8)
                {
                    if(board[2][1] == 'X' || board[2][1] == 'O')
                        validate = false;
                    
                    else
                    {
                        board[2][1] = (p2.symbol);
                        validate = true;
                    }
                }
                
                else if (compChoice == 9)
                {
                    if(board[2][2] == 'X' || board[2][2] == 'O')
                        validate = false;
                    
                    else
                    {
                        board[2][2] = (p2.symbol);
                        validate = true;
                    }
                }
            } /* Ends computer's random position choice */
            
            else
                compCounter = 0;

            
        } /* Ends validation while loop */
        
        // tests computer's random choice
        cout << p2.name << "\'s choice: " << compChoice << endl;
        
    }     /* Ends player 2's choice */
    
    system("clear");
}
