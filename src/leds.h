#pragma once

// The Slave Selecte pin for the led controller
#define LED_CS 10

//the opcodes for the MAX7221 and MAX7219
#define OP_NOOP   0x00
#define OP_DIGIT0 0x01
#define OP_DIGIT1 0x02
#define OP_DIGIT2 0x03
#define OP_DIGIT3 0x04
#define OP_DIGIT4 0x05
#define OP_DIGIT5 0x06
#define OP_DIGIT6 0x07
#define OP_DIGIT7 0x08
#define OP_DECODEMODE  0x09
#define OP_INTENSITY   0x0A
#define OP_SCANLIMIT   0x0B
#define OP_SHUTDOWN    0x0C
#define OP_DISPLAYTEST 0x0F



//functions to control led rows at a time
void setLedReg(uint8_t opcode, byte val);

// functions to diplay mapped values into 10 segment led bars
void show_in_bar_1(int value);
void show_in_bar_2(int value);
void show_in_bar_3(int value);
void show_in_bar_4(int value);