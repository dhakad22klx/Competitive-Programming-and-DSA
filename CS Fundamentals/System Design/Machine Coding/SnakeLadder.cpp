#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class Player
{
    public:

        string name;
        int position;
        int moves;

        Player(string s) 
        {
            name = s;
            position = 0;
            moves = 0;
        }


        int rollDice() 
        {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dis(1, 6);
            return dis(gen);
        }

        // void move(int spaces) 
        // {
        //     position += spaces;
        //     moves++;
        // }

        //my change

        void move(int newPos)
        {
            // this->position = newPos;
            position = newPos;
            moves++;
        }
};
class Board
{
    public : 

        int size;

        vector<int> playerPositions;
        vector<int> snakePositions;
        vector<int> ladderPositions;

        // Board(int s)
        // {
        //     size = s;
        // }
        //this is needed if we decide it initialize it by calling constructer

        void movePlayer(Player &p, int roll) 
        {
            int newPos = p.position + roll;

            if (newPos > size) 
            {
                return;
            }

            for (int i = 0; i < ladderPositions.size(); i += 2) 
            {
                if(newPos == ladderPositions[i]) 
                {
                    newPos = ladderPositions[i + 1];
                    break;
                }
            }
            for (int i = 0; i < snakePositions.size(); i += 2) 
            {
                if(newPos == snakePositions[i]) 
                {
                    newPos = snakePositions[i + 1];
                    break;
                }
            }
            // p.position = newPos;
            //my update 
            p.move(newPos);
        }
        bool checkWinner(Player &p) 
        {
            if (p.position == size) 
            {
                cout<<size<<endl;
                // cout << p.name << " wins!" << endl;
                cout<< p.name << " wins! " << " in " << p.moves <<" moves."<<endl;

                return true;
            }
            return false;
        }
};
class Game 
{
    public:
        Board board;
        vector<Player> players;
        vector<pair<int, int>> snakes;
        vector<pair<int, int>> ladders;
        // Game(int boardSize, vector<string> playerNames, vector<pair<int, int>> s, vector<pair<int, int>> l) : board(boardSize) 
        Game(int boardSize, vector<string> playerNames, vector<pair<int, int>> s, vector<pair<int, int>> l)
        {
            board.size = boardSize;

            for (int i = 0; i < playerNames.size(); i++) 
            {
                players.push_back(Player(playerNames[i]));
            }
            snakes = s;
            //or
            //this->snakes = s;
            ladders = l;

            //or this->ladders = l;

            initializeBoard();
        }
        void initializeBoard() 
        {
            for (int i = 0; i < snakes.size(); i++) 
            {
                board.snakePositions.push_back(snakes[i].first);
                board.snakePositions.push_back(snakes[i].second);
            }

            for (int i = 0; i < ladders.size(); i++) 
            {
                board.ladderPositions.push_back(ladders[i].first);
                board.ladderPositions.push_back(ladders[i].second);
            }
        }
        void play() 
        {
            while (true) 
            {
                for (int i = 0; i < players.size(); i++) 
                {
                    int roll = players[i].rollDice();

                    cout << players[i].name << " rolled a " << roll << endl;

                    board.movePlayer(players[i], roll);

                    cout << players[i].name << " is now on square " << players[i].position << endl;

                    if (board.checkWinner(players[i])) 
                    {
                        return;
                    }
                }
            }
        }
};

int main() 
{
   vector<string> playerNames = {"Player 1", "Player 2"};

   vector<pair<int, int>> snakes = {{17, 7}, {54, 34}};

   vector<pair<int, int>> ladders = {{62, 81}, {87, 96}};

   Game game(100, playerNames, snakes, ladders);

   game.play();

   return 0;
}
