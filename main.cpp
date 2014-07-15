#include "mbed.h"
#include "C12832.h"
// Read temperature from LM75BD

I2C i2c(p28, p27);
C12832 lcd(p5, p7, p6, p8, p11);
const int addr = 0x90;

int main() {
    char cmd[2];
    while (1) {
        cmd[0] = 0x01;
        cmd[1] = 0x00;
        i2c.write(addr, cmd, 2);
 
        wait(0.5);
 
        cmd[0] = 0x00;
        i2c.write(addr, cmd, 1);
        i2c.read(addr, cmd, 2);
 
        float tmp = (float((cmd[0]<<8)|cmd[1]) / 256.0);
        lcd.cls();
        lcd.locate(0,3);
        lcd.printf("Temp = %.3f\n", (float)tmp);
    }
}