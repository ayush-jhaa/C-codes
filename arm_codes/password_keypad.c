#include <lpc21xx.h>
#include "types.h"
#include "defines.h"
#include "delay.h"
#include "lcd_defines.h"
#include "types.h"

int main() {
    u8 KeyV = 0;
    s32 i = 0;
    s32 j = 0;
    InitLCD();
    InitKPM();

    while (1) {
        u32 r[5] = {1, 2, 3, 4, 5};
        u32 k[5];
        u32 flag = 1;

        if (i == 5) {
            cmdLCD(GOTO_LINE1_POS0);

            for (j = 0; j < 5; j++) {
                if (r[j] != k[j]) {
                    flag = 0;
                    break;
                }
            }

            if (flag == 1) {
                strLCD("Password match");
            } else if (flag == 0) {
                strLCD("Password does");
							  cmdLCD(GOTO_LINE2_POS0);
							  strLCD("not match");
            }

            delay_ms(500);
            cmdLCD(CLEAR_LCD);
            i = 0;
        }

        KeyV = keyscan();

        cmdLCD(GOTO_LINE1_POS0 + i);
        u32LCD(KeyV);
        k[i] = KeyV;
        i++;

        if (i == 5) {
            delay_ms(300);
            cmdLCD(CLEAR_LCD);
        }

        while (!colscan());
    }

    return 0;
}
