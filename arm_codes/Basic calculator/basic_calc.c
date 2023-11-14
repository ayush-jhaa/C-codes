#include <lpc21xx.h>
#include "types.h"
#include "defines.h"
#include "delay.h"
#include "lcd_defines.h"
#include "types.h"

int main() {
    u8 KeyV;
    u32 first = 0;
    u8 second = 0;
    u32 third = 0;
    u32 flag = 1;
    u32 enter = 0;
    u32 result = 0;

    InitLCD();
    InitKPM();

    while (1) {
        KeyV = keyscan();

        // Correct the `if` condition
        if ((KeyV >= '1' && KeyV <= '9')) {
            if (flag) {
                first = first * 10 + (KeyV - '0');
                charLCD(KeyV);
            } else {
                third = third * 10 + (KeyV - '0');
                charLCD(KeyV);
            }
        } else if (KeyV == '+' || KeyV == '-' || KeyV == '*' || KeyV == '/') {
            second = KeyV;
            charLCD(KeyV);
            flag = 0;
        } else if (KeyV == '=') {
            enter = 1;
        }

        if (enter) {
            u32 add, sub, mul, div;
            switch (second) {
                case '+':
                    result = first + third;
                    break;
                case '-':
                    result = first - third;
                    break;
                case '*':
                    result = first * third;
                    break;
                case '/':
                   
                        result = first / third;
                    break;
                default:
                    strLCD("Invalid operation");
            }

            cmdLCD(CLEAR_LCD); // Clear the LCD screen before displaying the result
            u32LCD(result);
            delay_ms(500);
            cmdLCD(CLEAR_LCD);
            flag = 1;
            enter = 0;
            first = 0;  // Reset the first operand for the next calculation
            third = 0; // Reset the third operand for the next calculation
        }

        while (!colscan());
    }

    return 0;
}
