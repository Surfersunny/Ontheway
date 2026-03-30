#include "lcd_bsp.h"

extern uint8_t page;
extern uint8_t word1;
extern uint8_t word2;
extern uint8_t word3;

extern uint16_t freq;
extern uint8_t duty;

char string[20];

void lcd_show() {
	LCD_Clear(White);
	
	switch (page) {
		case 0:
			LCD_DisplayStringLine(Line1, (uint8_t*)"       PSD      ");
		
			if (word1 == 11) LCD_DisplayStringLine(Line3, (uint8_t*)"    B1:@      ");
			else {
				sprintf(string, "    B1:%d      ", word1);
				LCD_DisplayStringLine(Line3, (uint8_t*)string);
			}
			
			if (word2 == 11) LCD_DisplayStringLine(Line4, (uint8_t*)"    B2:@      ");
			else {
				sprintf(string, "    B2:%d      ", word2);
				LCD_DisplayStringLine(Line4, (uint8_t*)string);
			}
			
			if (word3 == 11) LCD_DisplayStringLine(Line5, (uint8_t*)"    B3:@      ");
			else {
				sprintf(string, "    B3:%d      ", word3);
				LCD_DisplayStringLine(Line5, (uint8_t*)string);
			}
			break;
		case 1:
			LCD_DisplayStringLine(Line1, (uint8_t*)"       STA      ");
			sprintf(string, "    F:%dHz      ", freq);
			LCD_DisplayStringLine(Line3, (uint8_t*)string);
			sprintf(string, "    D:%d%%      ", duty);
			LCD_DisplayStringLine(Line4, (uint8_t*)string);
			break;
	}
}