#include "lcd_bsp.h"

extern uint8_t page;
extern float VR37;
extern uint32_t freq;
extern float VP1;

char s[21];

void lcd_show() {
	LCD_Clear(White);
	
	switch (page) {
		case 0:
			LCD_DisplayStringLine(Line3, (uint8_t*)"        DATA   ");
		
			sprintf(s, "     VR37:%.2fV  ", VR37);
			LCD_DisplayStringLine(Line4, (uint8_t*)s);

			sprintf(s, "     PA7:%dHz  ", freq);
			LCD_DisplayStringLine(Line5, (uint8_t*)s);
		
			break;
		
		case 1:
			LCD_DisplayStringLine(Line3, (uint8_t*)"        PARA   ");
			
			sprintf(s, "      VP1:%.1fV  ", VP1);
			LCD_DisplayStringLine(Line4, (uint8_t*)s);
		
			break;
	}		
}