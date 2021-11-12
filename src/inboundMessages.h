#pragma once

void initializeBars();

void setLED(int digit, int led, bool state);

void messageHandler(byte messageType, byte msg[], byte msgSize);