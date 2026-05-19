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
		D = memory[reg[X]];
	}
}

void RCA1802::LDXA(uint8_t opcode){
	uint8_t i, n;
	i = isolate_i(opcode);
	n = isolate_n(opcode);
	if ((i = 0x7) && (n == 0x2)){
		D = memory[reg[X]];
		reg[X] += 1;	
	}

}

void RCA1802::LDI(uint8_t opcode){
	uint8_t i, n;
	i = isolate_i(opcode);
	n = isolate_n(opcode);
	if ((i == 0xF) && (n == 8)){
		D = memory[reg[P]];
	        reg[P]++;	
	}

}

void RCA1802::STR(uint8_t opcode){
	uint8_t i, n;
	i = isolate_i(opcode);
	n = isolate_n(opcode);
	memory[reg[n]] = D;
	return; 


}

void RCA1802::STXD(uint8_t opcode){
	uint8_t i, n;
	i = isolate_i(opcode);
	n = isolate_n(opcode);
	memory[reg[X]] = D;
	reg[X]--;
}

//Logic Operations

void RCA1802::OR(uint8_t opcode){
	D = memory[reg[X]] || D;
}

void RCA1802::ORI(uint8_t opcode){
	D = memory[reg[P]] || D;
	reg[P]++;
}

void RCA1802::XOR(uint8_t opcode){
	D = ((!memory[reg[X]] & D) || (!D & memory[reg[X]]));
	return;
}

void RCA1802::XRI(uint8_t opcode){
	D = ((!memory[reg[P]] & D) || (!D & memory[reg[P]]));
	reg[P]++;
	return;
}

void RCA1802::AND(uint8_t opcode){
	D = memory[reg[X]] && D;
	return;
}

void RCA1802::ANI(uint8_t opcode){
	D = memory[reg[P]] && D;
	reg[P]++;
	return;
}

void RCA1802::SHR(uint8_t opcode){
	data_flag = 0b00000001 & D;
	D = D >> 1;
	D = D & 0b01111111
	return;	
}

void RCA1802::SHL(uint8_t opcode){
	uint8_t move = D & 0b10000000;
	move = move >> 7;
	D = D << 1;
	data_flag = move;
	return;

}

void RCA1802::SHRC(uint8_t opcode){
	D = D >> 1;
	D = (data_flag << 7) + D;
	data_flag = 0b00000001 & D;
	//write logic formula fo this one
	return;
}

