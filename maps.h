#pragma once
#include "rlutil.h"
#include <iostream>
class maps
{
protected:
	char* p;
public:
	void map(char*s){
		p = s;
		
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 120; j++)
			{
				if (i == 0 || i == 19)
				{
					*(s + (i * 120) + j) = 't';
					
					if (j % 2 == 1)
					{
						rlutil::resetColor();
						rlutil::setColor(5);
						rlutil::setBackgroundColor(5);
						rlutil::locate(j + 1, i + 1); std::cout << "t";
					}

					else
					{
						rlutil::resetColor();
						rlutil::setColor(0);
						rlutil::setBackgroundColor(0);
						rlutil::locate(j + 1, i + 1); std::cout << "t";
					}
				}
				else
				{
					if (i == 18)
					{
						if (j % 2 == 1)
						{
							rlutil::resetColor();
							rlutil::setColor(5);
							rlutil::setBackgroundColor(5);
							rlutil::locate(j + 1, i + 1); std::cout << ' ';

							*(s + (i * 120) + j) = ' ';
						}
						else
						{
							rlutil::resetColor();
							rlutil::setColor(0);
							rlutil::setBackgroundColor(0);
							rlutil::locate(j + 1, i + 1); std::cout << ' ';
							
							*(s + (i * 120) + j) = ' ';
						}
					}
					else {
						rlutil::setBackgroundColor(14);
						rlutil::locate(j + 1, i + 1); std::cout << ' ';
						
						*(s + (i * 120) + j) = ' ';
					}
				}
			}
		}
	}
	
};