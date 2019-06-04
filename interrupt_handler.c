#include "interrupt_handler.h"
#include "Board.h"
#include "Game.h"
#include "stack.h"

extern Stack stack;
extern Game game;
int counter = 0;
char receivedDataBuffer[16];

// funkcja wysylajaca string przez interfejs UART plytki
void sendString(const char * str)
{
	while (*str != '\0')
	{
		if(LPC_UART0->LSR & (1 << 5))
		{
			LPC_UART0->THR = *str;
			str++;
		}
	}
}

// funkcja obslugi przerwan z ekranu dotykowego
void EINT3_IRQHandler()
{
	int pos_x,pos_y,wys_x,wys_y;
	char buffer[32];
	touchpanelGetXY(&pos_x, &pos_y);
	wys_x = (double)pos_y / 4095 * LCD_MAX_X;
	wys_y = (double)pos_x / 4095 * LCD_MAX_Y;
	if(!(pos_x == 0 || pos_y == 0)){
		//sprintf(buffer,"%4d %4d\n",wys_x,wys_y);
		push(&stack,(unsigned short)wys_x,(unsigned short)wys_y);
	}
	//sendString(buffer);
	LPC_GPIOINT->IO0IntClr = 1 << 19;
	
}

// obsluga przerwania od UART0
void UART0_IRQHandler()
{
	char c = LPC_UART0->RBR;
	receivedDataBuffer[counter++] = c;
	if(c == ';')
	{
		receivedDataBuffer[counter] = '\0';
		counter = 0;
		game.m_command = 1;
		if(game.m_state == 0 && !strcmp(receivedDataBuffer, "RDY;"))
		{
			game.m_turn = 0;
		}
	}
	LPC_UART0->IIR;
}
