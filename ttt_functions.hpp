#include <vector>


void display_board(std::vector<char> current_marks);
std::vector<char> start_game();
std::vector<char> take_turn(char turn, std::vector<char> current_marks);
char switch_turn(char turn);
bool check_win(std::vector<char> current_marks, char turn);
