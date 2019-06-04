#ifndef _BOARD_H_
#define _BOARD_H_
#include "Ship.h"

#define AllyXCoor 19
#define AllyYCoor 19
#define AllyWidth 150
#define AllyHeight 150

#define EnemyXCoor 19
#define EnemyYCoor 157
#define EnemyWidth 150
#define EnemyHeight 150

/*
00 - brak statku  - nie strzelony
01 - statek - nie strzelony
10 - brak statku - strzal
11 - statek - trafiony


jeden 4pola
dwa 3pola
trzy 2pola
cztery 1pole
*/



typedef struct
{
		Ship m_ships[10];	
} Board;

#endif
