#include "lcd_bsp.h"

extern uint8_t UI;
extern uint8_t mode;
extern float temperature;
extern uint16_t rpm;
extern uint8_t TH;

char s[20];

void lcd_show() {
	LCD_Clear(White);
	
	switch (UI) {
		case 0:
			LCD_DisplayStringLine(Line1, (uint8_t*)"        DATA        ");
			switch (mode) {
				case 0:
					LCD_DisplayStringLine(Line3, (uint8_t*)"      MODE:AUTO     ");
					break;
				case 1:
					LCD_DisplayStringLine(Line3, (uint8_t*)"      MODE:MANU     ");
					break;
			}
			sprintf(s, "      TEMP:%.1f     ", temperature);
			LCD_DisplayStringLine(Line4, (uint8_t*)s);
			sprintf(s, "      SPEED:%d     ", rpm);
			LCD_DisplayStringLine(Line5, (uint8_t*)s);
			break;
		case 1:
			LCD_DisplayStringLine(Line1, (uint8_t*)"        SET        ");
			sprintf(s, "      TH:%d     ", TH);
			LCD_DisplayStringLine(Line3, (uint8_t*)s);
			break;
	}
}