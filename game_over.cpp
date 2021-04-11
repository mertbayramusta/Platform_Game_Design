#include "game_over.h"
#include "rlutil.h"
void game_over::gameover(int money,int life) {

	rlutil::setColor(10);
	rlutil::locate(45, 15);
	std::cout << "G A M E  O V E R! ";

	rlutil::setBackgroundColor(0);
	rlutil::setColor(10);
	rlutil::locate(1, 1);
	std::cout << "Highest Score:" << money << std::endl;
	rlutil::locate(50, 1);
	std::cout << "Life: " << life << std::endl;;
	rlutil::locate(100, 1);
	std::cout << "Bank:" << money << std::endl;;

	rlutil::setBackgroundColor(0);
	std::cout << ' ';

}
game_over::game_over()
{

}