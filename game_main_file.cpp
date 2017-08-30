#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;
//-----------------------------------
class board;
class spaceship;
void gotoxy(int x, int y);
void clear_screen(char fill);
void check_spaceship(bool play);
void loading();
void greeting();
//-----------------------------------

void gotoxy(int x, int y){
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}

void clear_screen(char fill = ' ') {
    COORD tl = {0,0};
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, fill, cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
}

void loading(){
	for(int i=0;i<=100;++i){
		printf("\r[%3d%%]",i);
		Sleep(40);
	}
  clear_screen();
}

void greeting(){
  gotoxy(15,0);
  cout << "Welcome Commander!" << endl;
  gotoxy(5,1);
  cout << "You will recive your spaceship in few seconds" << endl;
  loading();
}

class board{
  public:
    void fill_board();
    void show_board();
  private:
    char board_matrix[5][10];
};

void board::fill_board(){
	for(int i=0; i<5; i++){
		for(int j=0; j<10; j++){
			board_matrix[i][j] = 176;
	   }
  }
}

void board::show_board(){
  for(int i=0; i<5; i++){
		for(int j=0; j<10; j++){
			cout << board_matrix[i][j];
	   }
     cout << endl;
  }
}

class spaceship{
  public:
    void show_spaceship();
    void set_position(int row, int col);
    void go_up();
    void go_down();
    void go_left();
    void go_right();
    int give_row();
    int give_col();
    void set_score(int num);
    void add_score(int num);
    int give_score();
  private:
    int spaceship_row;
    int spaceship_col;
    int score;
};

void spaceship::set_position(int row, int col){
  spaceship_row = row;
  spaceship_col = col;
}

void spaceship::go_up(){
  spaceship_col--;
}

void spaceship::go_down(){
  spaceship_col++;
}

void spaceship::go_left(){
  spaceship_row--;
}

void spaceship::go_right(){
  spaceship_row++;
}

void spaceship::show_spaceship(){
  gotoxy(spaceship_row, spaceship_col);
  cout << '}';
}

int spaceship::give_row(){
  return spaceship_row;
}

int spaceship::give_col(){
  return spaceship_col;
}

void spaceship::set_score(int num){
  score = num;
}

void spaceship::add_score(int num){
  score += num;
}

int spaceship::give_score(){
  return score;
}

int main(int argc, char *argv[])
{
  greeting();
  board game_board;
  game_board.fill_board();
  spaceship player;
  player.set_score(0);
  player.set_position(0,2);
  bool play = true;
  while(play){
    game_board.show_board();
    if ( kbhit() ){
        int key_code = getch();
        if(key_code == 119){ //up
          player.go_up();
        }
        else if(key_code == 115){ // down
          player.go_down();
        }
        else if(key_code == 100){ // down
          player.go_right();
        }
        else if(key_code == 97){ // down
          player.go_left();
        }
        else if(key_code == 27){ // down
          play = false;
        }
      }
    player.show_spaceship();
    player.add_score(1);
    Sleep(100);
    clear_screen();
  }
  cout << "Your score: " << player.give_score() << endl;
  return 0;
}
//ERRORS
