
# RCA 1802 Notes
## 1. General:

- The RCA1802 is an 8 bit byte microprocessor  with 9 types of instructions: Branching instructions, register operations, arithmetic operations, logic operations, memory 		reference operations, skip operations, control operations, and i/o byte transfer operations. In total, there are 91 operations. 
- Has simple phase clock, 8-bit parallel bus configuration, direct memory addressing up to 65,536 bytes.
- Instructions are 16 bits long and are formatted in the following way: IXPN, where I and N
 		specify the type of instruction
- 2048 Bytes of RAM
- the COSMAC 6502 Has a hex keyboard, 8-bit I/O port, Audio cassette interface, RCA1802 CPU, 512 Byte ROM operating system,
 		video interface, tone circuit, 5V Power supply, and various software programs.
## 2. Architecture:
### A. Registers:
- The internal structure of the 1802 microprocessor is relatively simple, which results in a number of system advantages.
- It is based around a register array comprising 16 general purpose 16 bit scratch-pad registers
- There are three additional four bit registers labeled "N", "P", and "X", that hold the 4 bit binary codes that are used to select individual 16 bit 					scratch-pad registers
- The register content, which is considered two bytes may be sequentially placed on the eight external memory address lines for read and write 						operations. Memory or I/O data used in COSMAC operations re transferred by means of the common data bus
- ALU performs arithmetic and logical operations. The byte stored in the D register is one operand, and the byte on the bus is the second operand. The 					resultant byte replaces the byte in the D register. Also, there's a carry flag

### B. Instruction Format:
- COSMAC operations are specified by a sequence of instruction codes stored in external memory with a one byte instruction format being typical for most 				instructions
- There are two four bit digits in each instruction, labeled I and N. For example, for the instruction 01011010, I would be 0101 or 5 and N would be 1010 or A (10)
- Most instructions require two cycles, one to fetch or read the appropriate instruction byte from memory, then store the two hex digits to registers I 	and N. During 		the second machine cycle, the actual instruction is executed.
- Any of the 16, 16-bit registers can be used as the program counter. Which one is used is designated by P
- Although most of the instructions are one byte, some are two or three bytes in length. The immediate and short-branch instructions have a two-byte format, and 		the long branch instructions have a three byte format. The long-skip instructions are 1 byte.
### C. Timing
- Fetch and execute cycles are labeled State 0 and State 1 respectively. Most instructions require two cycles, but the long branch and long skip instructions 		require two machine cycles for execution for a total of 3 cycles
### D. Addressing Modes
- There are four basic modes of addressing in the COSMAC architecture: register, register-indirect, immediate, and stack.
- In register addressing, the address of the operand is contained in the four lower order bits, the "N" of the instruction byte.
- Register-indirect is a variant of indirect addressing, utilizing CPU registers as pointers to memory
- Unrelated to addressing modes, but COSMAC allows for multiple program counters by using any of the registers as the counter at a given time
## 3. Instruction Repertoire: 
### A. Intro
- Each CPU instruction is fetched in the S0 cycle and executed in the S1 cycle, with the exception of long branch instructions, which require two S1 cycles. There are eight general classes, as noted earlier, with each instruction being designated by its two digit hex code

 
 
 
