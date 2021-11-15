#include <LedControl.h>


extern LedControl lc; //reference to max7219 instance declared in main.cpp

byte digit[5] {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000}; //array to store the max7219 digit values to be used by the 4 led bars.

// arrays to store mask for bit manupulation depending on the led bar
byte bar1Mask[2] {0b00000000, 0b00111111};
byte bar2Mask[2] {0b11000000, 0b00001111};
byte bar3Mask[2] {0b11110000, 0b00000011};
byte bar4Mask[2] {0b11111100, 0b00000000};


// These functions apply a mask to the byte controlling the lower and upper part of each led bar and set a value on it leaving ones for other bars alone
void show_in_bar_1(int value){
    switch (value){          
          case 1:            
            digit[0] = 0b10000000;
            lc.setRow(0,0,digit[0]);
            digit[1] &= bar1Mask[1];            
            lc.setRow(0,1,digit[1]);
            break;        
          case 2:            
            digit[0] = 0b11000000;
            lc.setRow(0,0,digit[0]);
            digit[1] &= bar1Mask[1];            
            lc.setRow(0,1,digit[1]);
            break;
          case 3:            
            digit[0] = 0b11100000;
            lc.setRow(0,0,digit[0]);
            digit[1] &= bar1Mask[1];            
            lc.setRow(0,1,digit[1]);
            break;
          case 4:            
            digit[0] = 0b11110000;
            lc.setRow(0,0,digit[0]);
            digit[1] &= bar1Mask[1];
            lc.setRow(0,1,digit[1]);
            break;
          case 5: 
            digit[0] = 0b11111000;
            lc.setRow(0,0,digit[0]);
            digit[1] &= bar1Mask[1];            
            lc.setRow(0,1,digit[1]);
            break;
          case 6:             
            digit[0] = 0b11111100;
            lc.setRow(0,0,digit[0]);
            digit[1] &= bar1Mask[1];            
            lc.setRow(0,1,digit[1]);
            break;
          case 7:            
            digit[0] = 0b11111110;
            lc.setRow(0,0,digit[0]);
            digit[1] &= bar1Mask[1];            
            lc.setRow(0,1,digit[1]);
            break;
          case 8:             
            digit[0] = 0b11111111;
            lc.setRow(0,0,digit[0]);
            digit[1] &= bar1Mask[1];            
            lc.setRow(0,1,digit[1]);
            break;
          case 9:
            digit[0] = 0b11111111;
            lc.setRow(0,0,digit[0]);
            digit[1] &= bar1Mask[1];
            digit[1] |= 0b10000000;
            lc.setRow(0,1,digit[1]);
            break;
          case 10:
            digit[0] = 0b11111111;
            lc.setRow(0,0,digit[0]);
            digit[1] &= bar1Mask[1];
            digit[1] |= 0b11000000;
            lc.setRow(0,1,digit[1]);
            break;
          default:            
            digit[0] = 0b00000000;            
            lc.setRow(0,0,digit[0]);
            digit[1] &= bar1Mask[1];
            lc.setRow(0,1,digit[1]);                        
            break; 
        }
}

void show_in_bar_2(int value){
    switch (value){        
          case 1:            
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00100000;
            lc.setRow(0,1,digit[1]);
            digit[2] &= bar2Mask[1];            
            lc.setRow(0,2,digit[2]);
            break;        
          case 2:            
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00110000;
            lc.setRow(0,1,digit[1]);
            digit[2] &= bar2Mask[1];            
            lc.setRow(0,2,digit[2]);
            break;
          case 3:            
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111000;
            lc.setRow(0,1,digit[1]);
            digit[2] &= bar2Mask[1];            
            lc.setRow(0,2,digit[2]);
            break;
          case 4:            
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111100;
            lc.setRow(0,1,digit[1]);
            digit[2] &= bar2Mask[1];
            lc.setRow(0,2,digit[2]);
            break;
          case 5: 
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111110;
            lc.setRow(0,1,digit[1]);
            digit[2] &= bar2Mask[1];            
            lc.setRow(0,2,digit[2]);
            break;
          case 6:             
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111111;
            lc.setRow(0,1,digit[1]);
            digit[2] &= bar2Mask[1];            
            lc.setRow(0,2,digit[2]);
            break;
          case 7:            
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111111;
            lc.setRow(0,1,digit[1]);
            digit[2] &= bar2Mask[1];
            digit[2] |= 0b10000000;            
            lc.setRow(0,2,digit[2]);
            break;
          case 8:             
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111111;
            lc.setRow(0,1,digit[1]);
            digit[2] &= bar2Mask[1];
            digit[2] |= 0b11000000;            
            lc.setRow(0,2,digit[2]);
            break;
          case 9:
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111111;
            lc.setRow(0,1,digit[1]);
            digit[2] &= bar2Mask[1];
            digit[2] |= 0b11100000;
            lc.setRow(0,2,digit[2]);
            break;
          case 10:
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111111;
            lc.setRow(0,1,digit[1]);
            digit[2] &= bar2Mask[1];
            digit[2] |= 0b11110000;
            lc.setRow(0,2,digit[2]);
            break;
          default:
            digit[1] &= bar2Mask[0];            
            lc.setRow(0,1,digit[1]);
            digit[2] &= bar2Mask[1];
            lc.setRow(0,2,digit[2]);
            break;
        }
}

void show_in_bar_3(int value){
    switch (value){            
            case 1:            
            digit[2] &= bar3Mask[0];
            digit[2] |= 0b00001000;
            lc.setRow(0,2,digit[2]);
            digit[3] &= bar3Mask[1];            
            lc.setRow(0,3,digit[3]);
            break;        
          case 2:            
            digit[2] &= bar3Mask[0];
            digit[2] |= 0b00001100;
            lc.setRow(0,2,digit[2]);
            digit[3] &= bar3Mask[1];            
            lc.setRow(0,3,digit[3]);
            break;
          case 3:            
            digit[2] &= bar3Mask[0];
            digit[2] |= 0b00001110;
            lc.setRow(0,2,digit[2]);
            digit[3] &= bar3Mask[1];            
            lc.setRow(0,3,digit[3]);
            break;
          case 4:            
            digit[2] &= bar3Mask[0];
            digit[2] |= 0b00001111;
            lc.setRow(0,2,digit[2]);
            digit[3] &= bar3Mask[1];
            lc.setRow(0,3,digit[3]);
            break;
          case 5: 
            digit[2] &= bar3Mask[0];
            digit[2] |= 0b00001111;
            lc.setRow(0,2,digit[2]);
            digit[3] &= bar3Mask[1];
            digit[3] |= 0b10000000;            
            lc.setRow(0,3,digit[3]);
            break;
          case 6:             
            digit[2] &= bar3Mask[0];
            digit[2] |= 0b00001111;
            lc.setRow(0,2,digit[2]);
            digit[3] &= bar3Mask[1];
            digit[3] |= 0b11000000;            
            lc.setRow(0,3,digit[3]);
            break;
          case 7:            
            digit[2] &= bar3Mask[0];
            digit[2] |= 0b00001111;
            lc.setRow(0,2,digit[2]);
            digit[3] &= bar3Mask[1];
            digit[3] |= 0b11100000;            
            lc.setRow(0,3,digit[3]);
            break;
          case 8:             
            digit[2] &= bar3Mask[0];
            digit[2] |= 0b00001111;
            lc.setRow(0,2,digit[2]);
            digit[3] &= bar3Mask[1];
            digit[3] |= 0b11110000;            
            lc.setRow(0,3,digit[3]);
            break;
          case 9:
            digit[2] &= bar3Mask[0];
            digit[2] |= 0b00001111;
            lc.setRow(0,2,digit[2]);
            digit[3] &= bar3Mask[1];
            digit[3] |= 0b11111000;
            lc.setRow(0,3,digit[3]);
            break;
          case 10:
            digit[2] &= bar3Mask[0];
            digit[2] |= 0b00001111;
            lc.setRow(0,2,digit[2]);
            digit[3] &= bar3Mask[1];
            digit[3] |= 0b11111100;
            lc.setRow(0,3,digit[3]);
            break;
          default:
            digit[2] &= bar3Mask[0];            
            lc.setRow(0,2,digit[2]);
            digit[3] &= bar3Mask[1];
            lc.setRow(0,3,digit[3]);
            break;
        }


}

void show_in_bar_4(int value){
    switch (value){
          case 1:            
            digit[3] &= bar4Mask[0];
            digit[3] |= 0b0000010;
            lc.setRow(0,3,digit[3]);
            digit[4] &= bar4Mask[1];            
            lc.setRow(0,4,digit[4]);
            break;        
          case 2:            
            digit[3] &= bar4Mask[0];
            digit[3] |= 0b0000011;
            lc.setRow(0,3,digit[3]);
            digit[3] &= bar4Mask[1];            
            lc.setRow(0,4,digit[4]);
            break;
          case 3:            
            digit[3] &= bar4Mask[0];
            digit[3] |= 0b0000011;
            lc.setRow(0,3,digit[3]);
            digit[4] &= bar4Mask[1];
            digit[4] |= 0b1000000;            
            lc.setRow(0,4,digit[4]);
            break;
          case 4:            
            digit[3] &= bar4Mask[0];
            digit[3] |= 0b0000011;
            lc.setRow(0,3,digit[3]);
            digit[4] &= bar4Mask[1];
            digit[4] |= 0b1100000;
            lc.setRow(0,4,digit[4]);
            break;
          case 5: 
            digit[3] &= bar4Mask[0];
            digit[3] |= 0b0000011;
            lc.setRow(0,3,digit[3]);
            digit[4] &= bar4Mask[1];
            digit[4] |= 0b11100000;            
            lc.setRow(0,4,digit[4]);
            break;
          case 6:             
            digit[3] &= bar4Mask[0];
            digit[3] |= 0b0000011;
            lc.setRow(0,3,digit[3]);
            digit[4] &= bar4Mask[1];
            digit[4] |= 0b11110000;            
            lc.setRow(0,4,digit[4]);
            break;
          case 7:            
            digit[3] &= bar4Mask[0];
            digit[3] |= 0b0000011;
            lc.setRow(0,3,digit[3]);
            digit[4] &= bar4Mask[1];
            digit[4] |= 0b11111000;            
            lc.setRow(0,4,digit[4]);
            break;
          case 8:             
            digit[3] &= bar4Mask[0];
            digit[3] |= 0b0000011;
            lc.setRow(0,3,digit[3]);
            digit[4] &= bar4Mask[1];
            digit[4] |= 0b11111100;            
            lc.setRow(0,4,digit[4]);
            break;
          case 9:
            digit[3] &= bar4Mask[0];
            digit[3] |= 0b0000011;
            lc.setRow(0,3,digit[3]);
            digit[4] &= bar4Mask[1];
            digit[4] |= 0b11111110;
            lc.setRow(0,4,digit[4]);
            break;
          case 10:
            digit[3] &= bar4Mask[0];
            digit[3] |= 0b0000011;
            lc.setRow(0,3,digit[3]);
            digit[4] &= bar4Mask[1];
            digit[4] |= 0b11111111;
            lc.setRow(0,4,digit[4]);
            break;
          default:
            digit[3] &= bar4Mask[0];            
            lc.setRow(0,3,digit[3]);
            digit[4] &= bar4Mask[1];
            lc.setRow(0,4,digit[4]);
            break;
        }
}