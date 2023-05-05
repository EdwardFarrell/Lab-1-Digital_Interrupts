/* Digital Input will always look for the condition, so the code would be always 
 Interrupt routines are programmed to execute on timed events or  by events that occur externally in 
hardware.
In this program, interrupt is given by external hardware (joystick position - left, right,up and down).
Hardware debouncer would be two cross-coupled NAND gates form a very simple Set-Reset (SR) latch.
Software debouncerwould be to look for a number of sequential readings of the switch, 
e.g. if the input changes from 0 to 1 and then continues to read 1 for the next ten samples then the switch
 has been pressed.
*/
#include "mbed.h"
#include "C12832.h"

C12832 lcd(p5, p7, p6, p8, p11);

InterruptIn up(p15);
InterruptIn down(p12);
InterruptIn left(p13);
InterruptIn right(p16);

void flip_up()
 {
    lcd.locate(35,0);
    lcd.printf("Up\n");
  }

  void flip_down()
 {
    lcd.locate(35,20);
    lcd.printf("Down\n");
  }

  void flip_left()
 {
    lcd.locate(0,10);
    lcd.printf("Left\n");
    wait(2);
  }

  void flip_right()
 {
    lcd.locate(65,10);
    lcd.printf("Right\n");
        
  }
 
int main() 
    {
 
    up.rise(&flip_up); 
    down.rise(&flip_down);
    left.rise(&flip_left);
    right.rise(&flip_right);
   
    }
