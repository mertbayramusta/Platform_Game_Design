#include "rlutil.h"
#include "maps.h"
#include "menu.h"
#include "bootleneck.h"
#include "game_over.h"
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#define waitkey rlutil::anykey("Press any key to continue...\n")
int a = 12; int b = 2; //enemy başlangıç koordinatları
int life = 3, money = 0;

int main() {
	menu men;
	int r, c;
	std::string title = "Hotel Reyna";
	game_over gameover;
	srand((unsigned)time(NULL));
	rlutil::setConsoleTitle(title);
	r = rlutil::trows();
	c = rlutil::tcols();
	char game[20][120];
	rlutil::hidecursor();
	bootleneck b;
	maps m;
	rlutil::setColor(10);
	rlutil::locate(40, 27);
	waitkey;
	rlutil::resetColor();
	rlutil::cls();
	m.map(*game);
	b.random();
	
	int f, g, exit = 0;
	int x = 1; int y = 18; unsigned int cnt = 0;
	while (life > 0) {

		rlutil::setBackgroundColor(14);
		rlutil::locate(x, y); std::cout << 'O'; // Output player
		f = x; g = y; //previous locates
		rlutil::setBackgroundColor(14);
		char k = getch(); // Get character

		if (k == 'a') {
			if (game[y][x - 1] == 't')
			{
				rlutil::resetColor();
				rlutil::setBackgroundColor(14);
				rlutil::locate(x, y); std::cout << ' ';
				y = 18;
				continue;
			}
			else if (game[y][x - 1] == '$')
			{

				money++;
				game[y][x - 1] = ' ';
				--x;

			}
			else if (game[y + 1][x - 1] != 't')
			{
				rlutil::resetColor();
				rlutil::setBackgroundColor(14);
				rlutil::locate(x, y); std::cout << ' ';
				y = 18;
				x--;
			}
			else if (x == 0)
			{
				continue;
			}
			else if (game[y][x - 1] == 'W') {
				life--;
				--x;
			}
			else  if (game[y][x - 1] != 'k')
			{
				x--;
			}

		}

		else if (k == 'd') {
			if (game[y][x + 1] == 't')
			{
				rlutil::resetColor();
				rlutil::setBackgroundColor(14);
				rlutil::locate(x, y); std::cout << ' ';
				y = 18;
				continue;
			}
			else if (game[y][x - 1] == '$')
			{

				money++;
				game[y][x - 1] = ' ';
				++x;

			}
			else if (game[y + 1][x + 1] != 't')
			{
				rlutil::resetColor();
				rlutil::setBackgroundColor(14);
				rlutil::locate(x, y); std::cout << ' ';
				y = 18;
				x++;
			}
			else if (game[y][x + 1] == 'W')
			{
				life--;
				++x;
			}
			else if (game[y][x + 1] != 'k')
			{
				x++;
			}

		}

		else if (k == 'w') {
			if (game[y - 1][x] == 't')
			{
				rlutil::resetColor();
				rlutil::setBackgroundColor(14);
				rlutil::locate(x, y); std::cout << ' ';
				y = 18;
				continue;
			}
			else if (game[y][x - 1] == '$')
			{

				money++;
				game[y][x - 1] = ' ';
				--y;

			}
			else if (game[y + 1][x - 1] != 't')
			{
				rlutil::resetColor();
				rlutil::setBackgroundColor(14);
				rlutil::locate(x, y); std::cout << ' ';
				y = 18;
			}
			else if (game[y - 1][x] == 'W')
			{

				life--;
				--y;
			}

			else if (game[y - 1][x] != 'k')
			{
				y--;
			}
		}

		else if (k == 's') {
			if (game[y + 1][x] == 't')
			{
				continue;
			}
			else if (game[y][x - 1] == '$')
			{

				money++;
				game[y][x - 1] = ' ';
				++y;

			}
			else if (game[y + 1][x] == 'W')
			{

				life--;
				++y;
			}
			else if (x == 30)
			{
				continue;
			}
			else if (game[y + 1][x] != 'k')
			{
				y++;
			}
		}

		else if (k == ' ') {
			if (y - 10 > 1)
			{
				y -= 10;
				y = 2;
			}
		}
		else if (k == rlutil::KEY_ESCAPE) { break; }
		rlutil::setBackgroundColor(14);
		rlutil::locate(f, g); std::cout << ' ';
		rlutil::locate(1, 2); std::cout << "score:" << money;
		rlutil::locate(115, 2); std::cout << "life:" << life;
		rlutil::locate(110, 16); std::cout << "Next Level!";
		rlutil::locate(116, 18); std::cout << "-->";
		rlutil::locate(1, 16); std::cout << "Previous Level!";
		rlutil::locate(1, 18); std::cout << "<--";
	}
		gameover.gameover(money, life);

		rlutil::locate(40, 27);
		waitkey;

		return 0;
}
