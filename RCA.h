#ifndef MY_CLASS_H
#define MY_CLASS_H

class RCA1802 {	
	public:
		uint16_t reg[16];
		uint8_t D;
	private:
		uint8_t *memory;
	public: 
		
	private:	

		//register operations
		void INC(); //increments register N; 1N
		void DEC(); //decrements register N; 2N
		void IRX(); //increments register X; 60
		void GLO(); //When I = 8, the low order byte of the register specified by N replaces the byte in the D register; 8N
		void PLO(); //When I = A, the reverse of the above happens; AN
		void GHI(); //When I = 9, the high order byte of the register specified by N replaces the byte in the D register; 9N
		void PHI(); //When I = B, reverse of the above happens; BN
		
		//memory operations
		void LDN(); //When I = 0 and N != 0, the external memory byte referenced by N replaces the byte in the D register
		void LDA(); //When I = 4, same as above except address in R[N] is also incremented 
		void LDX(); //When I = F and N = 0, memory byte in mem[R[X]] replaces byte in D reg
		void LDXA(); //when I = 7 and N = 2, mem[R[X]] replaces byte in D reg, and R[X] is incremented
		void LDI(); //When I = F, and N = 8, mem[R[P]] replaces byte in D reg, and R[P] is incremented
   		void STR(); //When I = 5, mem[R[N]] is replaced by the byte in D 
		void STXD();//When I = 7 and n = 3, mem[R[X]] = D, and R[X] is decremented by 1

}
