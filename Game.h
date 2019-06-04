#ifndef _GAME_H_
#define _GAME_H_

#include "Board.h"
#include "Renderer.h"
#include "PIN_LPC17xx.h"
#include "stack.h"
#include "interrupt_handler.h"

// define'y dla pozycji przyciskow statkow
#define StatkiX 210
#define StatkiW 10
#define StatkiH 10
#define JednoY  35
#define DwuY    50
#define TrzyY   65
#define CzteroY 85
#define PiecioY 100

// pozycja ustaw
#define UstawX 165
#define UstawY 240
#define UstawW 40
#define UstawH 20

// przyciski
#define PrzyciskW 10
#define PrzyciskH 15
#define PrzyciskiStrzalkiY 263

#define PrzyciskLewoX  163
#define PrzyciskGoraX  175
#define PrzyciskPrawoX 190
#define PrzyciskDolX   201



typedef struct
{		
		Board m_ourboard;
		uint8_t m_shipLeft[4];
		uint8_t m_state;
		bool m_running;
		uint8_t m_command;
		bool m_turn;
		uint32_t m_shoots[10]; //nasze strzaly
} Game;

void init(Game* g);
void run(Game* g);
void handleTurn(Game* g, uint16_t *x, uint16_t* y, uint16_t *fixedX, uint16_t* fixedY);
void sendShot(uint16_t x, uint16_t y);
void checkForHit(Game* g,char* newMessage,uint16_t receivedX,uint16_t receivedY);
void drawShots(Game* g);
void checkForGameEnd(Game* g, char* buff);
#endif
