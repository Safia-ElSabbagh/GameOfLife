#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace std;

class Universe {

public:

    void initilaize(int(&board)[20][20]) {
        int pos = 1;
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                board[i][j] = 0;     // initialize all cells to dead
                cout << setw(4) << pos + i + j << ' ';
            }
            cout << endl;
            pos += 19;
        }


        while (true) {
            int index;
            cout << "Enter the position of the cell you want to make it live (from 1 to 400):" << endl;
            cout << "If you want to exit enter (-1):";
            cin >> index;

            if (index == -1) break;
            else if ((index < 1) || (index > 400)) {
                cerr << " Invalid position (out of bound)!" << endl;
                continue;
            }
            else {
                board[((index - 1) / 20)][(index - 1) % 20] = 1;
            }
        }

        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                if (board[i][j] != 1)
                    board[i][j] = 0;
                cout << setw(4) << board[i][j];
            }
            cout << endl;
        }
    }

    void Reset(int(&board)[20][20]) {
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                board[i][j] = 0;     // reset all cells to dead (0)
                cout << setw(4) << board[i][j] << ' ';
            }
            cout << endl;
        }
    }

    int count_neighbours(int board[20][20], int row, int col) {
        int count = 0;
        // the neighbour cells to check
        int cellsToCheck[8][2] = { {-1,-1}, {-1,0}, {-1,1}, {0,-1},
                                   {0,1}, {1,-1}, {1,0}, {1,1} };

        // check each surrounding cell
        for (auto& cell : cellsToCheck) {
            int newRow = row + cell[0];
            int newCol = col + cell[1];

            if (newRow >= 0 && newRow < 20 && newCol >= 0 && newCol < 20) {
                //Valid cells only
                if (board[newRow][newCol] == 1)
                    count++;
            }

        }

        return count;

    }

    void next_generation(int board[20][20]) {
        // copy the board 34an a3ml check 3ala kolo ba3den a8yar
        int temp_board[20][20];
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                temp_board[i][j] = board[i][j];
            }
        }

        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                int neighbours = count_neighbours(temp_board, i, j);
                if (neighbours <= 1)
                    board[i][j] = 0;
                else if (neighbours >= 4)
                    board[i][j] = 0;
                else if (temp_board[i][j] == 1 && (neighbours == 2 || neighbours == 3))
                    board[i][j] = 1;
                else if (temp_board[i][j] == 0 && neighbours == 3)
                    board[i][j] = 1;

            }
        }
    }

    void display(int board[20][20]) {
        // Clear the console
        system("cls");

        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                if (board[i][j] == 1)
                    cout << setw(4) << '*' << ' ';
                else
                    cout << setw(4) << ' ' << ' ';


            }
            cout << endl;
        }
    }

    void run(int board[20][20]) {
        int num;
        cout << "Enter number of generations:";
        cin >> num;
        while (num > 0) {
            next_generation(board);
            display(board);
            // Add delay time between each generation so user can see each gen not only the final.
            this_thread::sleep_for(chrono::milliseconds(500));
            num--;
        }
    }

};


int main() {
    int board[20][20] = { 0 };

    Universe u;

    while (true) {
        int choice;
        cout << "Choose what to do:\n1)start game\n2)Reset board\n3)exit" << endl;
        cin >> choice;
        if (choice == 1) {
            system("cls");
            u.initilaize(board);
            u.run(board);
        }
        else if (choice == 2) {
            system("cls");
            u.Reset(board);
        }
        else if (choice == 3) {
            exit(0);
        }
        else {
            cerr << "invalid choice choose again!" << endl;
            continue;
        }
    }
    return 0;
}