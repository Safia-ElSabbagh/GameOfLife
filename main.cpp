#include <iostream>
#include <iomanip>

using namespace std;

class Universe{
  //  int board[20][20];

public:
     /*int getBoard() const{
         for(int i = 0; i<20; ++i){
             for(int j = 0; j<20; ++j){
                 return board[i][j];
             }
         }
    }*/
   /* void setBoard(const int arr[20][20]){
         for(int i = 0; i<20; ++i){
             for(int j = 0; j<20; ++j){
                 board[i][j] = arr[i][j];
             }
         }
     }*/

    void initilaize(int(&board)[20][20]) {
       int pos = 1;
       for (int i = 0; i < 20; ++i) {
           for (int j = 0; j < 20; ++j) {
               board[i][j] = pos +i + j;
               cout << setw(4) << board[i][j] << ' ';
           }
           cout << endl;
           pos += 19;
       }


       while (true) {
           int index;
           cout << "Enter the position of the cell you want to make it live (from 0 to 399):" << endl;
           cout << "If you want to exit enter (-1)";
           cin >> index;
           cout<< (index -1)/20 << "  " << (index -1)%20 << endl;

           if (index == -1) break;
           else if ((index < 1) || (index > 399)) {
               cerr << " Invalid position (out of bound)!" << endl;
               continue;
           } else {

               board[((index -1) / 20)][(index -1)% 20] = 1;
           }
       }
       for (int i = 0; i < 20; ++i) {
           for (int j = 0; j < 20; ++j){
               if(board[i][j] != 1)
                   board[i][j] = 0;
               cout<<  setw(4) << board[i][j];
           }
           cout<< endl;
       }
   }

   void Reset(int(&board)[20][20]) {
       int pos;
       for (int i = 0; i < 20; ++i) {
           for (int j = 0; j < 20; ++j) {
               board[i][j] = pos + i + j;
               cout << setw(4) << board[i][j] << ' ';
           }
           cout << endl;
           pos += 19;
       }
   }

   int count_neighbours(int board[20][20],int row, int col) {
       int count = 0;
       // the neighbour cells to check
       int cellsToCheck[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1},
                               {0,1}, {1,-1}, {1,0}, {1,1}};

        // check each surrounding cell
       for (auto& cell : cellsToCheck) {
           int newRow = row + cell[0];
           int newCol = col + cell[1];

           if (newRow >= 0 && newRow < 20 && newCol >= 0 && newCol < 20) {
               //Valid cells only
               if(board[newRow][newCol] == 1)
                   count++;
           }

       }

       return count;

   }



};


int main() {
    int board[20][20];

    Universe u;

    u.initilaize(board);
    u.count_neighbours(board,2,4);

    return 0;
}