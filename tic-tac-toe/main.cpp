// Tic Tac Toe Game
#include<iostream>

class Player
{
    public:
    std::string name;
    char symbol;
    Player(std::string name, char symbol)
    {
        this->name = name;
        this->symbol = symbol;
    }
};

class Board{
    public:
    char board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
     void printBoard() {
        std::cout << "   |   |   " << std::endl;
        std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
        std::cout << "   |   |   " << std::endl;
        std::cout << "---|---|---" << std::endl;
        std::cout << "   |   |   " << std::endl;
        std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
        std::cout << "   |   |   " << std::endl;
        std::cout << "---|---|---" << std::endl;
        std::cout << "   |   |   " << std::endl;
        std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << std::endl;
        std::cout << "   |   |   " << std::endl;
    };
    
};

void make_move(Player player, Board &board, int position)
{
    while(position < 0 || position > 8 || board.board[position] != ' ')
    {
        std::cout << "Invalid move. Please enter a valid position: ";
        std::cin >> position;
    }
    board.board[position] = player.symbol;
}

void check_winner(Board board, int &winner)
{
    //check for the diagonals
    if(board.board[0] == board.board[4] && board.board[4] == board.board[8] && board.board[0] != ' ')
    {
        winner = 1;
    }
    else if(board.board[2] == board.board[4] && board.board[4] == board.board[6] && board.board[2] != ' ')
    {
        winner = 1;
    }
    //check for the rows
    else if(board.board[0] == board.board[1] && board.board[1] == board.board[2] && board.board[0] != ' ')
    {
        winner = 1;
    }
    else if(board.board[3] == board.board[4] && board.board[4] == board.board[5] && board.board[3] != ' ')
    {
        winner = 1;
    }
    else if(board.board[6] == board.board[7] && board.board[7] == board.board[8] && board.board[6] != ' ')
    {
        winner = 1;
    }
    //check for the columns
    else if(board.board[0] == board.board[3] && board.board[3] == board.board[6] && board.board[0] != ' ')
    {
        winner = 1;
    }
    else if(board.board[1] == board.board[4] && board.board[4] == board.board[7] && board.board[1] != ' ')
    {
        winner = 1;
    }
    else if(board.board[2] == board.board[5] && board.board[5] == board.board[8] && board.board[2] != ' ')
    {
        winner = 1;
    }
    else
    {
        winner = 0;
    }
}

void check_tie(Board board, int &winner)
{
    int count = 0;
    for(int i = 0; i < 9; i++)
    {
        if(board.board[i] != ' ')
        {
            count++;
        }
    }
    if(count == 9)
    {
        winner = 2;
    }
}

int main()
{
    Player player1("Player 1", 'X');
    Player player2("Player 2", 'O');
    Board board;
    board.printBoard();
    int winner = 0;
    int turn = 0;

    while(winner == 0)
    {
        if(turn % 2 == 0)
        {
            std::cout << player1.name << "'s turn. Enter a position: ";
            int position;
            std::cin >> position;
            make_move(player1, board, position-1);
            check_winner(board, winner);
            if(winner == 1)
            {
                std::cout << player1.name << " wins!" << std::endl;
                break;
            }
            check_tie(board, winner);
            if(winner == 2)
            {
                std::cout << "It's a tie!" << std::endl;
                break;
            }
        }
        else
        {
            std::cout << player2.name << "'s turn. Enter a position: ";
            int position;
            std::cin >> position;
            make_move(player2, board, position-1);
            check_winner(board, winner);
            if(winner == 1)
            {
                std::cout << player2.name << " wins!" << std::endl;
                break;
            }
            check_tie(board, winner);
            if(winner == 2)
            {
                std::cout << "It's a tie!" << std::endl;
                break;
            }
        }
        board.printBoard();
        turn++;
    }


    return 0;
}