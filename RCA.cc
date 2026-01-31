#include <iostream> 
#include "RCA.h"

//ARITHMETIC INSTRUCTIONS

uint8_t isolate_n(uint8_t opcode){
	uint8_t n;
	n = opcode && 0b00001111;
	return n;	
}
void RCA1802::INC(uint8_t opcode){
	uint8_t n;
	n = isolate_n(opcode);
	reg[N] = reg[N] + 1;
	reg[P] += 1;
	return;
}

void RCA1802::DEC(uint8_t opcode){
	uint8_t n;
	n = isolate_n(opcode);
	reg[N] = reg[N] - 1;
	reg[P] += 1;
	return;
}

void RCA1802::IRX(uint8_t opcode){
	reg[X] = reg[X] + 1;
	reg[P] += 1;
	return;
}

void RCA1802::GLO(uint8_t opcode){
	uint8_t low = isolate_n(reg[N]);
	D = low;
	reg[P] += 1;
	return;
}

void RCA1802::PLO(uint8_t opcode){
	reg[N] = reg[N] && 0b11110000;
	reg[N] = reg[N] + D;
	reg[P]+=1;
	return; 
}

void RCA1802::GHI(uint8_t opcode){
	uint8_t high;
	high = (reg[N] && 0b11110000) >> 4;
	D = high;
	reg[P]+=1;
	return;
}

void RCA1802::PHI(uint8_t opcode){
	reg[N] = reg[N] && 0b11110000;
	reg[N] = reg[N] + D;
	reg[P] += 1;
	return;
}

//Memory instructions

