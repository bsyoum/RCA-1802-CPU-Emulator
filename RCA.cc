#include <iostream> 
#include "RCA.h"

//REGISTER OPERATIONS

uint8_t isolate_n(uint8_t opcode){
	uint8_t n;
	n = opcode && 0b00001111;
	return n;	
}

uint8_t isolate_i(uint8_t opcode){
	uint8_t i;
	i = opcode && 0b11110000;
	i = i >> 4;
	return i;
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

//MEMORY REFERENCE

void RCA1802::LDN(uint8_t opcode){
	uint8_t i, n;
	i = isolate_i(opcode);
	n = isolate_n(opcode);
	if ((i == 0) && (n != 0)){
		D = memory[n];
	}



}

void RCA1802::LDA(uint8_t opcode){
	uint8_t i, n;
	i = isolate_i(opcode);
	n = isolate_n(opcode);
	if (i == 4){
		D = memory[reg[n]];
		reg[n] += 1;
	}
	return;
}

void RCA1802::LDX(uint8_t opcode){
	uint8_t i, n;
	i = isolate_i(opcode);
	n = isolate_n(opcode);
	if ((i == 0xF) && (n == 0)){
		D = memory[X];
	}
}

void RCA1802::LDXA(){
	uint8_t i, n;
	i = isolate_i(opcode);
	n = isolate_n(opcode);
	if ((i = 0x7) && (n == 0x2)){
		
	}
}
