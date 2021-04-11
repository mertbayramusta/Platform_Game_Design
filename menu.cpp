#include "menu.h"
#include "rlutil.h"
#include <iostream>
menu:: menu() {
	rlutil::setColor(10);
	rlutil::locate(40, 10);
	std::cout << "Welcome to Our Game: HOTEL REYNA !";

	rlutil::setBackgroundColor(0);
	rlutil::setColor(10);
	rlutil::locate(1, 1);
	rlutil::setColor(10);
	rlutil::locate(1, 22);
	std::cout << "| This is you! Get all your coins!" << std::endl;
	std::cout << "v" << std::endl;
	std::cout << "O";
	rlutil::locate(50, 22);
	std::cout << "All rights reserved." << std::endl;
	rlutil::locate(50, 23);
	std::cout << "(C)2019" << std::endl;
	rlutil::locate(100, 22);
	std::cout << "Licensed by:" << std::endl;
	rlutil::locate(100, 23);
	std::cout << "A. Simge ALMAS";
	rlutil::locate(100, 24);
	std::cout << "Mert BAYRAMUSTA";
	rlutil::locate(100, 25);
	std::cout << "Zeynep OZDOGAN";
	rlutil::setBackgroundColor(0);
	rlutil::setColor(10);
	std::cout << ' ';

}
