#include "bootleneck.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <iostream>
#include "maps.h"
char game[20][120];
void bootleneck::random()
{
	srand(time(NULL));
	int ran[20], ran1[20], ra[20], cc[20];
	for (int bg = 0; bg < 20; bg++)
	{
		ran[bg] = rand() % 10 + 8;

	}
	for (int bg = 0; bg < 20; bg++) 
	{
		ran1[bg] = rand() % 110 + 5;
	}
	for (int i = 0; i < 20; i++)
	{
		ra[i] = rand() % 7 + 4;
	}
	for (int i = 0; i < 20; i++)
	{
		cc[i] = rand() % 2;
	}
	
	for (int i = 0; i < 20; i++)
	{
		cc[i] = rand() % 2;
	}
	
	rlutil::resetColor();			
	for (int rand = 0; rand < 20; rand++)
	{
		for (int leng = 0; leng < ra[rand]; leng++)
		{
			if (game[ran[rand] - 1][ran1[rand]] != 't')
			{
				rlutil::setBackgroundColor(14);
				rlutil::setColor(4);
				rlutil::locate(ran1[rand], ran[rand] - 1); std::cout << '$';
				game[ran[rand] - 1][ran1[rand] - 1] = '$';
				rlutil::locate(ran1[leng], ran[leng] - 1); std::cout << 'W';
				game[ran[leng] - 1][ran1[leng] - 1] = 'W';

			}
			if (game[ran[rand]][ran1[rand] - 1] != '$')
			{
				rlutil::setColor(5);
				rlutil::setBackgroundColor(5);
				rlutil::locate(ran1[rand], ran[rand]); std::cout << 't';
				ran1[rand]++;
				game[ran[rand]][ran1[rand] - 1] = 't';
			}
		}
	}
}
