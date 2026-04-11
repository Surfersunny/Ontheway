#include "lcd_bsp.h"

extern uint8_t page;
extern float freq1;
extern float freq2;
extern float PF;
extern uint8_t mode;

char s[21];

void lcd_show() {
	switch (page) {
		case 0:
			LCD_DisplayStringLine(Line1, (uint8_t*)"        DATA        ");
			
			sprintf(s, "     F1=%dHz      ", (int)freq1);
			LCD_DisplayStringLine(Line3, (uint8_t*)s);
		
			sprintf(s, "     F2=%dHz      ", (int)freq2);
			LCD_DisplayStringLine(Line4, (uint8_t*)s);
		
			if (mode == 0) LCD_DisplayStringLine(Line5, (uint8_t*)"     MODE=KEY       ");
			else LCD_DisplayStringLine(Line5, (uint8_t*)"     MODE=USART   ");
		
			break;
		
		case 1:
			LCD_DisplayStringLine(Line1, (uint8_t*)"        PARA         ");
		
			sprintf(s, "      PF=%dHz    ", (int)PF);
			LCD_DisplayStringLine(Line3, (uint8_t*)s);
		
			LCD_DisplayStringLine(Line4, (uint8_t*)"                   ");
		
			LCD_DisplayStringLine(Line5, (uint8_t*)"                   ");
		
			break;
	}
}