#include "lcd_bsp.h"

extern uint8_t lock;
extern float adc_1;
extern float adc_2;

uint8_t show1, show2;
char s[20];
void lcd_show() {
	LCD_DisplayStringLine(Line0, (uint8_t*)"       ANGLE");
	LCD_DisplayStringLine(Line1, (uint8_t*)"    R37      R38");
	LCD_DisplayStringLine(Line5, (uint8_t*)"     -        =");
	
	if (lock == 0) {
		LCD_Clear(White);
		
		/*  Very careful!!!!!!About value-angle correspondence,not difficult but need classification and patience!!!!!! */
		
		if (0 <= adc_1 && adc_1 < (3.3 / 28.0)) show1 = 0;
		else if (3.3 * 27.0 / 28.0 <= adc_1 && adc_1 <= 3.3) show1 = 14;
		else {
			for (uint8_t i = 1; i < 14; i++) {
				if (3.3 * (2*i - 1) / 28.0 <= adc_1 && adc_1 < 3.3 * (2*i + 1) / 28.0) show1 = i;
			}
		}
		
		if (0 <= adc_2 && adc_2 < (3.3 / 28.0)) show2 = 0;
		else if (3.3 * 27.0 / 28.0 <= adc_2 && adc_2 <= 3.3) show2 = 14;
		else {
			for (uint8_t i = 1; i < 14; i++) {
				if (3.3 * (2*i - 1) /28.0 <= adc_2 && adc_2 < 3.3 * (2*i + 1) / 28.0) show2 = i;
			}
		}
		
		if (show1 == show2) {
			switch (show1) {
				case 0:
					LCD_DisplayStringLine(Line2, (uint8_t*)"  *        + ");
					break;
				case 1:
					LCD_DisplayStringLine(Line3, (uint8_t*)" *        +  ");
					break;
				case 2:
					LCD_DisplayStringLine(Line4, (uint8_t*)"*        +   ");
					break;
				case 3:
					LCD_DisplayStringLine(Line5, (uint8_t*)"*        +   ");
					break;
				case 4:
					LCD_DisplayStringLine(Line6, (uint8_t*)"*        +   ");
					break;
				case 5:
					LCD_DisplayStringLine(Line7, (uint8_t*)" *        +  ");
					break;
				case 6:
					LCD_DisplayStringLine(Line8, (uint8_t*)"  *        + ");
					break;
				case 7:
					LCD_DisplayStringLine(Line9, (uint8_t*)"     *        +");
					break;
				case 8:
					LCD_DisplayStringLine(Line8, (uint8_t*)"        *        +");
					break;
				case 9:
					LCD_DisplayStringLine(Line7, (uint8_t*)"         *        +");
					break;
				case 10:
					LCD_DisplayStringLine(Line6, (uint8_t*)"          *        +");
					break;
				case 11:
					LCD_DisplayStringLine(Line5, (uint8_t*)"          *        +");
					break;
				case 12:
					LCD_DisplayStringLine(Line4, (uint8_t*)"          *        +");
					break;
				case 13:
					LCD_DisplayStringLine(Line3, (uint8_t*)"         *        +");
					break;
				case 14:
					LCD_DisplayStringLine(Line2, (uint8_t*)"        *        +");
					break;
			}
		}
		else {
			switch (show2) {
				case 0:
					LCD_DisplayStringLine(Line2, (uint8_t*)"  *      ");
					break;
				case 1:
					LCD_DisplayStringLine(Line3, (uint8_t*)" *       ");
					break;
				case 2:
					LCD_DisplayStringLine(Line4, (uint8_t*)"*        ");
					break;
				case 3:
					LCD_DisplayStringLine(Line5, (uint8_t*)"*        ");
					break;
				case 4:
					LCD_DisplayStringLine(Line6, (uint8_t*)"*        ");
					break;
				case 5:
					LCD_DisplayStringLine(Line7, (uint8_t*)" *       ");
					break;
				case 6:
					LCD_DisplayStringLine(Line8, (uint8_t*)"  *      ");
					break;
				case 7:
					LCD_DisplayStringLine(Line9, (uint8_t*)"     *   ");
					break;
				case 8:
					LCD_DisplayStringLine(Line8, (uint8_t*)"        * ");
					break;
				case 9:
					LCD_DisplayStringLine(Line7, (uint8_t*)"         * ");
					break;
				case 10:
					LCD_DisplayStringLine(Line6, (uint8_t*)"          *");
					break;
				case 11:
					LCD_DisplayStringLine(Line5, (uint8_t*)"          *");
					break;
				case 12:
					LCD_DisplayStringLine(Line4, (uint8_t*)"          *");
					break;
				case 13:
					LCD_DisplayStringLine(Line3, (uint8_t*)"         * ");
					break;
				case 14:
					LCD_DisplayStringLine(Line2, (uint8_t*)"        *  ");
					break;
			}	
			switch (show1) {
				case 0:
					LCD_DisplayStringLine(Line2, (uint8_t*)"           + ");
					break;
				case 1:
					LCD_DisplayStringLine(Line3, (uint8_t*)"          + ");
					break;
				case 2:
					LCD_DisplayStringLine(Line4, (uint8_t*)"        +  ");
					break;
				case 3:
					LCD_DisplayStringLine(Line5, (uint8_t*)"        + ");
					break;
				case 4:
					LCD_DisplayStringLine(Line6, (uint8_t*)"        + ");
					break;
				case 5:
					LCD_DisplayStringLine(Line7, (uint8_t*)"          + ");
					break;
				case 6:
					LCD_DisplayStringLine(Line8, (uint8_t*)"           + ");
					break;
				case 7:
					LCD_DisplayStringLine(Line9, (uint8_t*)"              +");
					break;
				case 8:
					LCD_DisplayStringLine(Line8, (uint8_t*)"                 +");
					break;
				case 9:
					LCD_DisplayStringLine(Line7, (uint8_t*)"                  +");
					break;
				case 10:
					LCD_DisplayStringLine(Line6, (uint8_t*)"                   +");
					break;
				case 11:
					LCD_DisplayStringLine(Line5, (uint8_t*)"                   +");
					break;
				case 12:
					LCD_DisplayStringLine(Line4, (uint8_t*)"                   +");
					break;
				case 13:
					LCD_DisplayStringLine(Line3, (uint8_t*)"                  +");
					break;
				case 14:
					LCD_DisplayStringLine(Line2, (uint8_t*)"                 +");
					break;
			}
		}			
		}
}