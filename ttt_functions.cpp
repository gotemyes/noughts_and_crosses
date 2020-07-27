#include <iostream>
#include <vector>

void display_board(std::vector<char> current_marks) {
  //current_marks is a 9 elements vector containing the current marks
  std::cout << " _____\n";
  std::cout << "|" << current_marks[0] << "|" << current_marks[1] << "|" << current_marks[2] << "|\n";
  std::cout << "|" << current_marks[3] << "|" << current_marks[4] << "|" << current_marks[5] << "|\n";
  std::cout << "|" << current_marks[6] << "|" << current_marks[7] << "|" << current_marks[8] << "|\n";
  std::cout << " \u203E\u203E\u203E\u203E\u203E\n";
}


std::vector<char> start_game() {
  std::cout << "Let's play Noughts and Crosses!\n";
  std::vector<char> current_marks = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
  display_board(current_marks);
  return current_marks;
}

std::vector<char> take_turn(char turn, std::vector<char> current_marks) {
  int move;
  if (turn == 'x') {
    std::cout << "Crosses move: ";
    std::cin >> move;
    std::cout << "\n";
    while ((move>8)||(move<0)||current_marks[move]!=' ') {
      std::cout << "Not a valid move, please choose a valid move: ";
      std::cin >> move;
      std::cout << "\n";
    }
    current_marks[move] = 'x';
  } else {
    std::cout << "Noughts move: ";
    std::cin >> move;
    std::cout << "\n";
    while ((move>8)||(move<0)||current_marks[move]!=' ') {
      std::cout << "Not a valid move, please choose a valid move: ";
      std::cin >> move;
      std::cout << "\n";
    }
    current_marks[move] = 'o';
  }
  return current_marks;
}

char switch_turn(char turn) {
  if (turn == 'o') {
    return 'x';
  } else if (turn == 'x') {
    return 'o';
  } else {
    std::cout << "Something gone wrong...";
    return '~';
  }
}

bool check_win(std::vector<char> current_marks, char turn) {
  if ((current_marks[0]==current_marks[1])&&(current_marks[0]==current_marks[2])&&(current_marks[0]==turn)&&(current_marks[1]==turn)&&(current_marks[2]==turn)) {
    return true;
  } else if ((current_marks[3]==current_marks[4])&&(current_marks[4]==current_marks[5])&&(current_marks[3]==turn)&&(current_marks[4]==turn)&&(current_marks[5]==turn)) {
    return true;
  } else if ((current_marks[6]==current_marks[7])&&(current_marks[6]==current_marks[8])&&(current_marks[6]==turn)&&(current_marks[7]==turn)&&(current_marks[7]==turn)) {
    return true;
  } else if ((current_marks[0]==current_marks[3])&&(current_marks[0]==current_marks[6])&&(current_marks[0]==turn)&&(current_marks[3]==turn)&&(current_marks[6]==turn)) {
    return true;
  } else if ((current_marks[1]==current_marks[4])&&(current_marks[1]==current_marks[7])&&(current_marks[1]==turn)&&(current_marks[4]==turn)&&(current_marks[5]==turn)) {
    return true;
  } else if ((current_marks[2]==current_marks[5])&&(current_marks[2]==current_marks[8])&&(current_marks[2]==turn)&&(current_marks[5]==turn)&&(current_marks[8]==turn)) {
    return true;
  } else if ((current_marks[0]==current_marks[4])&&(current_marks[0]==current_marks[8])&&(current_marks[0]==turn)&&(current_marks[4]==turn)&&(current_marks[8]==turn)) {
    return true;
  } else if ((current_marks[2]==current_marks[4])&&(current_marks[2]==current_marks[6])&&(current_marks[2]==turn)&&(current_marks[4]==turn)&&(current_marks[6]==turn)) {
    return true;
  } else {
    return false;
  }
}
