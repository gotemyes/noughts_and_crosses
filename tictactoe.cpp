#include <iostream>
#include <vector>
#include "ttt_functions.hpp"



int main() {

  bool cross_win = false;
  bool nought_win = false;
  char turn = 'x';
  int turns = 0;

  std::vector<char> current_marks = start_game();

  while ((!cross_win)&&(!nought_win)&&(turns<9)) {

    // current player takes their turn
    current_marks = take_turn(turn,current_marks);


    // display the board
    display_board(current_marks);

    // check if there is a winner
    if (turn=='x') {
      cross_win = check_win(current_marks, turn);
    } else if (turn =='o') {
      nought_win = check_win(current_marks, turn);
    }


    if (cross_win) {
      std::cout << "Crosses Win!\n";
    } else if (nought_win) {
      std::cout << "Noughts Win!\n";
    }

    // switch whose turn it is
    turn = switch_turn(turn);

    // increase the turn count
    turns++;
  }

  if ((!cross_win)&&(!nought_win)) {
    std::cout << "It's a draw!\n";
  }


}
