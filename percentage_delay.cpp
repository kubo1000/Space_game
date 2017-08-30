#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

//-----------------------------------
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}

void loading(){
	for(int i=0;i<=100;++i){
		printf("\r[%3d%%]",i);
		Sleep(100);
	}
}

int main(int argc, char *argv[])
{
	gotoxy(5,5);
	printf("Done \n");
  return 0;
}
