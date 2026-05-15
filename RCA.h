#ifndef MY_CLASS_H
#define MY_CLASS_H

class RCA1802 {	
	public:
		uint16_t reg[16];
		uint8_t D;
		uint8_t P, N, X;
		uint16_t A;
		uint16_t PC;
		bool data_flag;
	private:
		uint8_t *memory;
	public: 
		
	private:	

		//register operations
		void INC(uint8_t opcode); //increments register N; 1N
		void DEC(uint8_t opcode); //decrements register N; 2N
		void IRX(uint8_t opcode); //increments register X; 60
		void GLO(uint8_t opcode); //When I = 8, the low order byte of the register specified by N replaces the byte in the 
						//D-register; 8N
		void PLO(uint8_t opcode); //When I = A, the reverse of the above happens; AN
		void GHI(uint8_t opcode); //When I = 9, the high order byte of the register specified by N replaces the byte in the D register; 9N
		void PHI(uint8_t opcode); //When I = B, reverse of the above happens; BN
		
		//memory operations
		void LDN(uint8_t opcode); //When I = 0 and N != 0, the external memory byte referenced by N replaces the byte in the D register
		void LDA(uint8_t opcode); //When I = 4, same as above except address in R[N] is also incremented 
		void LDX(uint8_t opcode); //When I = F and N = 0, memory byte in mem[R[X]] replaces byte in D reg
		void LDXA(uint8_t opcode); //when I = 7 and N = 2, mem[R[X]] replaces byte in D reg, and R[X] is incremented
		void LDI(uint8_t opcode); //When I = F, and N = 8, mem[R[P]] replaces byte in D reg, and R[P] is incremented
   		void STR(uint8_t opcode); //When I = 5, mem[R[N]] is replaced by the byte in D 
		void STXD(uint8_t opcode);//When I = 7 and n = 3, mem[R[X]] = D, and R[X] is decremented by 1

}
