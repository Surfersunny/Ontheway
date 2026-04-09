#include "lcd_bsp.h"

extern uint8_t page;

extern uint8_t mode;
extern uint8_t duty;
extern float vel;

extern uint8_t R;
extern uint8_t K;

extern uint32_t count;
extern float MH;
extern float ML;

char s[20];
extern uint32_t counter;

void lcd_show() {
	switch (page) {
		case 0:
			LCD_DisplayStringLine(Line1, (uint8_t*)"        DATA     ");
		
			if (mode == 0) LCD_DisplayStringLine(Line3, (uint8_t*)"     M=L  ");
			else LCD_DisplayStringLine(Line3, (uint8_t*)"     M=H     ");
		
			sprintf(s, "     P=%d%%     ", duty);
			LCD_DisplayStringLine(Line4, (uint8_t*)s);
			
			sprintf(s, "     V=%.1f     ", vel);
			LCD_DisplayStringLine(Line5, (uint8_t*)s);
		
			break;
		
		case 1:
			LCD_DisplayStringLine(Line1, (uint8_t*)"        PARA   ");
		
			sprintf(s, "     R=%d      ", R);
			LCD_DisplayStringLine(Line3, (uint8_t*)s);
		
			sprintf(s, "     K=%d      ", K);
			LCD_DisplayStringLine(Line4, (uint8_t*)s);
		
			LCD_DisplayStringLine(Line5, (uint8_t*)"                   ");
		
			break;
		
		case 2:
			LCD_DisplayStringLine(Line1, (uint8_t*)"        RECD   ");
		
			sprintf(s, "     N=%d      ", count);
			LCD_DisplayStringLine(Line3, (uint8_t*)s);
		
			sprintf(s, "     MH=%.1f      ", MH);
			LCD_DisplayStringLine(Line4, (uint8_t*)s);
		
			sprintf(s, "     ML=%.1f      ", ML);
			LCD_DisplayStringLine(Line5, (uint8_t*)s);
		
			break;
	}
}