# 8085-Emulator

This project allows the user to perform basic arithmetic operations, Load and Store operations, Logical operations and Branching Instructions. It also includes a debugger to help the user to debug the program if error is found.

This Project includes following files:
# Arithmetic_Instructions.cpp
	-> Arithmetic Instructions are the instructions which perform basic arithmetic operations such as addition, subtraction and a few more. In 8085 microprocessor, the destination operand is generally the accumulator. In 8085 microprocessor, the destination operand is generally the accumulator.

	-> It includes the code for setting flag bit 0 or 1 for Addition and Subtraction.

	-> It also includes code for performing following operations:
		
		# ADD operation:-
		-> In 8085 Instruction set, ADD R is a mnemonic that stands for “Add contents of R to Accumulator”. As addition is a binary operation, so it requires two operands to be operated on. So input operands will reside on Accumulator and R registers and after addition the result will be stored back on to Accumulator.

		-> Used to add contents of two registers and store it in accumulator. Registers can be A(accumulator),B,C,D,E,H,L.
		Syntax: ADD B (where B can also be any other register)

		# ADI operation:-
		-> In 8085 Instruction set, ADI is a mnemonic, which stands for “ADd Immediate to Accumulator” and here “d8” stands for any 8-bit or 1-Byte of data. This instruction is used to add 8-bit immediate data to the Accumulator. The result of addition will be stored in the Accumulator. So the previous content of the Accumulator will be over written. It occupies 2-Bytes in memory. The flags are affected based on the result.

		-> Used to add any given value entered by user into the contents of acuumulator.
		Syntax: ADI 04H (where 04H can also be any other value)

		# SUI operation:-
		-> In 8085 Instruction set, SUI is a mnemonic that stands for ‘SUbtract Immediate from Accumulator and here d8 stands for any 8-bit or 1-Byte data. This instruction is used to subtract 8-bit immediate data from the Accumulator. The result of the subtraction will be stored in the Accumulator over witting its previous content. As it is an arithmetic instruction, so flag bits are affected based on the result. It is a 2-Byte instruction and occupies 2-Bytes in memory.

		-> Used to subtract any given value entered by user from the content of accumulator.
		Syntax: SUI 04H (where 04H can also be any other value)

		# SUB operation:-
		-> In 8085 Instruction, SUB is a mnemonic that stands for ‘SUBtract contents of R from Accumulator. Here R stands for any of the following registers, or memory location M pointed by HL pair.
		R = A, B, C, D, E, H, L
	
		-> In this instruction content of the register R will get subtracted from the Accumulator and the resultant difference will be stored on the Accumulator replacing the previous content of the Accumulator. Where R can be any of the eight values, so as a result there are eight opcodes for this type of instruction as mentioned in the above table. It occupies only 1-Byte in the memory.

		-> Used to subtract contents of two registers and store the result in accumulator. Registers can be A( Accumulator),B,C,D,E,H,L.
		Syntax: SUB A(where A can also be any other register)

		# DCR operation:-
		-> In 8085 Instruction set, DCR is a mnemonic, which stands for ‘DeCRement’ and ‘R’ stands for any of the following registers, or memory location M pointed by HL pair.R = A, B, C, D, E, H, L, or M.

		-> This instruction is used to decrease the content of register R. Also we can say it will subtract 1 from the register R content. And the decremented value will be stored on to the register R itself. As it is an arithmetic instruction, so all flags, except Cy flag, are affected depending on the result. In those assembly language code where we require down counter, there we can use this instruction. So by design as mentioned, Cy flag is not affected by the execution of this instruction.

		-> Used to decrement the content of any register by 1.
		Syntax: DCR C(where C can also be any other register)

		# INR operation:-
		-> In 8085 Instruction set, INR is a mnemonic that stands for ‘INcRement’ and ‘R’ stands for any of the following registers or memory location M pointed by HL pair.R = A, B, C, D, E, H, L, or M.

		-> This instruction is used to add 1 with the contents of R. So the previous value in R will get increased by amount 1 only. The result of increment will be stored in R updating its previous content. All flags, except Cy flag, are affected depending on the result thus produced. In different assembly language core, this instruction is used for looping or as a count. As R can have any of the eight values as mentioned, so there are eight opcodes possible for this type of instruction. It requires only 1-Byte in memory.
	
		-> Used to increment the content of any register by 1.
		Syntax: INR B(where B can also be any other register)

		# INX operation:-
		-> In 8085 Instruction set, INX is a mnemonic that stands for “INcrementeXtended register” and rp stands for register pair. And it can be any one of the following register pairs.rp = BC, DE, or HL.

		-> This instruction will be used to add 1 to the present content of the rp. And thus the result of the incremented content will remain stored in rp itself. Though it is an arithmetic instruction, note that, flag bits are not at all affected by the execution of this instruction. A register pair is generally used to store 16-bit memory address. If flag bits got affected during increment of a memory address, then it may cause problems in many cases. So as per design of 8085, flag bits are not getting affected by the execution of this instruction INXrp.

		-> As rp can have any one of the three values, there are three opcodes for this type of instruction. It occupies only 1-Byte in memory.

		-> Used to increment the content of any register by 1 while performing 16-bit operations.
		Syntax: INX B(where B can also be any other register)

		# DCX operation:-
		-> In 8085 Instruction set, DCX is a mnemonic that stands for “DeCrementeXtended register” and rp stands for register pair. And it can be any one of the following register pairs:- rp = BC, DE, or HL.

		-> This instruction will be used to subtract 1 from the present content of the rp. And thus the result of the decremented content will remain stored in rp itself. Though, it is an arithmetic instruction, note that flags are not at all affected by the execution of this instruction. A register pair is generally used to store 16-bit memory address. If flag bits got affected during decrement of a memory address, then it may cause problems in many cases. So as per design of 8085, flag bits are not getting affected by the execution of this instruction DCXrp.

		-> As rp can have any one of the three values, there are three opcodes for this type of instruction. It occupies only 1-Byte in memory.

		-> Used to decrement the content of any register by 1 while peforming 16-bit operations.
		Syntax: DCX B(where B can also be any other register)

		# DAD operation:-
		-> In spite of the fact that 8085 is an 8-bit microprocessor, but there are some instructions are there available in the 8085 instruction set which can do 16-bit additions also. As the 8085 internal architecture is only 8-bits, this instruction easily takes double the time needed to add two 8-bit numbers.

		-> Here, DAD is a mnemonic, which stands for Double ADd and also rp stands for any one of the following register pairs as mentioned:- rp = BC, DE, or HL

		-> As rp can have any of the three values, there are three opcodes for this type of instruction. It occupies only 1-Byte in memory.

		-> Used to add content of HL register pair with the content of BC, DE or HL register pair and stores the result on HL register pair.

		-> Syntax:- DAD B(where B can also be any other register)

# Branching_Instructions.cpp
	-> Branching instructions refer to the act of switching execution to a different instruction sequence as a result of executing a branch instruction.

	-> This file includes the code for following bracnhing instruction:-

	#JMP:-
	-> In 8085 Instruction set,there are a set of jump instructions, which can transfer program control to a certain memory location. So after these branching mnemonics we shall have to mention 16-bit target address of the location.

	-> This instruction is used to jump from one memory location to another memory location unconditionally within the range of the program.
	Opcode:- JMP
	Operand:- 16-bit address
	Meaning:- Jump unconditionally
	Explanation:- The program sequence is transferred to the memory address given in the operand.

	-> Syntax:- JMP 3000H(where 3000H can also be any other address location)
              

	#JC:-
	-> In 8085 Instruction set, we are having one mnemonic JC a16, which stands for “Jump if Carry” and “a16” stands for any 16-bit address. This instruction is used to jump to the address a16 as provided in the instruction. But as it is a conditional jump so it will happen if and only if the present carry flag value is 1.If carry flag value is 0, program flow continues sequentially. It is a 3-Byte instruction.

	-> Syntax:- JC 3000H(where 3000H can also be any other address location)

	#JNC:-
	-> In 8085 Instruction set,we are having one mnemonic JNC a16, which stands for “Jump if Not Carry” and “a16”stands for any 16-bit address. This instruction is used to jump to the address a16 as provided in the instruction. But as it is a conditional jump so it will happen if and only if the present carry flag value is 0. If carry flag value is 1, program flow continues sequentially. It is a 3-Byte instruction.

	-> Syntax:- JNC 4000H(where 4000H can also be any other address location)

	#JZ:-
	-> In 8085 Instruction set, we are having one mnemonic JZ a16, which stands for “Jump Zero” and “a16” stands for any 16-bit address. This instruction is used to jump to the address a16 as provided in the instruction. But as it is a conditional jump so it will happen if and only if the present zero flag value is 1. If the zero flag value is 0, program flow continues sequentially. It is a 3-Byte instruction.

	-> Syntax:- JZ 7000H(where 7000H can also be any other address location)

	#JNZ:-
	-> In 8085 Instruction set, we are having one mnemonic JNZ a16, which stands for “Jump if Not Zero” and “a16” stands for any 16-bit address. This instruction is used to jump to the address a16 as provided in the instruction. But as it is a conditional jump so it will happen if and only if the present zero flag value is 0. If zero flag value is 1, program flow continues sequentially. It is a 3-Byte instruction.

	-> Syntax:- JNZ 3000H(where 3000H can also be any other address location)


# conversion.cpp
	-> This file includes the code for the conversion of hexa-decimal numbers to decimal and vice-versa for both 8-bit and 16-bit numbers.

	-> This file has three functions namely:-
		-> hex_to_dec():- for converting numbers from hexa-decimal to decimal (for both 8 and 16 bit ).

		-> dec_to_hex():- for converting 8-bit numbers from decimal to hexa-decimal.

		-> dec_to_hex16():- for converting 16-bit numbers from decimal to hexa-decimal.


# DataTransfer.cpp
	-> Data tranfer instructions are the instructions which transfers data in the microprocessor. They are also called copy instructions.

	-> This file stores load and store instruction and other related instruction mentioned below:-

	#MOV:-

	-> In 8085 Instruction set, MOV r, M is an instruction where the 8-bit data content of the memory location as pointed by HL register pair will be moved to the register r. Thus this is an instruction to load register r with the 8-bit value from a specified memory location whose 16-bit address is in HL register pair.

	-> As r can have any of the seven values, there are seven opcodes for this type of instruction.

    -> r = A, B, C, D, E, H, or L

	-> Opcode:- MOV
	   Operand:- 	Rd, Sc 
		  		    M, Sc
			 	    Dt, M
	Meaning:- Copy from the source (Sc) to the destination(Dt)
	Explanation:- This instruction copies the contents of the source register into the destination register without any alteration. 
	Example − MOV B, A

	#MVI:-

	-> MVI is a mnemonic, which actually means “Move Immediate”. With this instruction,we can load a register with an 8-bitsor 1-Bytevalue. This instruction supports immediate addressing mode for specifying the data in the instruction. In the instruction “d8” stands for any 8-bit data, and ‘r’ stands for any one of the registers e.g. A, B, C, D, E, H or L. So this r can replace any one of the seven registers.

	-> As ‘r’ can have any of the seven register names, so there are seven opcodes for this type of instruction. It occupies 2-Bytes in the memory.

	-> Opcode:- MVI
	   Operand:- Rd, data
			     M, data
	   Meaning:- Move immediate 8-bit
	   Explanation:- The 8-bit data is stored in the destination register or memory. 
	   Example − MVI A, 55H

	#LDA:-

	-> In 8085 Instruction set, LDA is a mnemonic that stands for LoaD Accumulator with the contents from memory. In this instructionAccumulatorwill get initialized with 8-bit content from the 16-bit memory address as indicated in the instruction as a16. This instruction uses absolute addressing for specifying the data. It occupies 3-Bytes in the memory. First Byte specifies the opcode, and the successive 2-Bytes provide the 16-bit address, i.e. 1-Byte each for each memory location.

	-> Opcode:- LDA
	   Operand:- 16-bit address
	   Meaning:- Load the accumulator
	   Explanation:- The contents of a memory location, specified by a 16-bit address in the operand, are copied to the accumulator.
	   Example − LDA 2034H

	#STA:-

	-> In 8085 Instruction set, STA is a mnemonic that stands for STore Accumulator contents in memory. In this instruction,Accumulator8-bit content will be stored to a memory location whose 16-bit address is indicated in the instruction as a16. This instruction uses absolute addressing for specifying the destination. This instruction occupies 3-Bytes of memory. First Byte is required for the opcode, and next successive 2-Bytes provide the 16-bit address divided into 8-bits each consecutively.

	->  Opcode:- STA
		Operand:- 16-bit address
		Meaning:- Store the accumulator
		Explanation:- The contents of the accumulator are copied into the memory location specified by the operand.
		This is a 3-byte instruction, the second byte specifies the low-order address and the third byte specifies the high-order address.
		Example − STA 325K

	#SET:-

	-> This instruction is used to  set the value to any location.
		Example:- SET 2500H, 05H 
		meaning: store value 05H at location 2500H

	#SHLD:-

	-> In 8085 Instruction set, SHLD is a mnemonic, which stands for Store HLpair using Direct addressing in memory location whose 16-bit address is denoted as a16. As HL pair has to be stored, so it has to be stored in two consecutive locations starting at the address a16. We know that H and L are 8-bit registers. So their contents will be stored in two consecutive memory locations as each memory location can hold 8-bits of data. This instruction uses absolute addressing mode for specifying the destination. It occupies 3-Bytes in the memory.

	->  Opcode:- SHLD
		Operand:- 16-bit address
		Meaning:- Store H and L registers direct
		Explanation:- The contents of register L are stored in the memory location specified by the 16-bit address in the operand and the contents of H register are stored into the next memory location by incrementing the operand.

	-> This is a 3-byte instruction, the second byte specifies the low-order address and the third byte specifies the high-order address.
	Example − SHLD 3225H

	#LHLD:-

	-> In 8085 Instruction set LHLD is a mnemonic that stands for Load HL pair using Direct addressing from memory location whose 16-bit address is denoted as a16. So the previous content of HL register pair will get updated with the new 16-bits value. As HL pair has to be updated, so data comes from two consecutive memory locations starting at the address a16 and also from next address location. This instruction uses absolute addressing mode for specifying the data in the instruction. It occupies 3-Bytes in the memory.

	->  Opcode:- LHLD
		Operand:- 16-bit address
		Meaning:- Load H and L registers direct
		Explanation:- The instruction copies the contents of the memory location pointed out by the address into register L and copies the contents of the next memory location into register H.
		Example − LHLD 3225H

	#XCHG:-

	-> In 8085 Instruction set, there is one mnemonic XCHG, which stands for eXCHanGe. This is an instruction to exchange contents of HL register pair with DE register pair. This instruction uses implied addressing mode. As it is1-Byte instruction, so It occupies only 1-Byte in the memory. After execution of this instruction, the content between H and D registers and L and E registers will get swapped respectively.

	->  Opcode:- XCHG
		Operand:- None
		Meaning:- Exchange H and L with D and E
		Explanation:- The contents of register H are exchanged with the contents of register D, and the contents of register L are exchanged with the contents of register E.
		Example − XCHG

	#LXI:-

	-> In the 8085 Instruction set there are four instructions, which belong to the type LXI rp, d16. These instructions are used to load the 16-bit address into the register pair. We can use this instruction to load data from memory location using the memory address, which is stored in the register pair rp. For an example, if the instruction is LXI H, FE50. It means that the FE50 is loaded into the HL register pair. The rp can be BC, DE, HL or SP.

	->  Opcode:- LXI
		Operand:- Reg. pair, 16-bit data
		Meaning:- Load the register pair immediate
		Explanation:- The instruction loads 16-bit data in the register pair designated in the register or the memory.
		Example − LXI K, 3225H

	#Stax:-

	-> In 8085 Instruction set, STAX is a mnemonic that stands for SToreAccumulator contents in memory pointed by eXtended register denoted as “rp”.Hererp stands for register pair. This instruction uses register indirect addressing for specifying the destination. So using this instruction, the current content of Accumulator will be written to the memory location as pointed by 16-bit address as stored in the register pair. It occupies only 1-Byte in memory.

	-> 	Opcode:- STAX
		Operand:- 16-bit address
		Meaning:- Store the accumulator indirect
		Explanation:- he contents of the accumulator are copied into the memory location specified by the contents of the operand.
		Example − STAX B

# InstructionList.cpp
	-> This file has unordered map which is used to assign number to each instruction and it also includes a map which is used to guide user with right instruction syntax if in case the user input the wrong instruction.


# Logical_Instructions.cpp
	-> This file include two instructions:-
		-> CMA:- Used to complement the content of acuumulator.
			-> In 8085 Instruction set, logical type there is one complement instruction with the mnemonic CMA. It actually stands for “CoMplement the Accumulator”. It performs1's complement operation on the current contents of Accumulator, and the result is stored back in the Accumulator replacing its previous contents. It is to be noted that, there are no other instructions tocomplement any other register’s contents. Though it is a logicaltype of instruction, Flag bits are not affected by the execution of this instruction. It occupies only 1 Byte in memory.

			-> Syntax:- CMA 

		-> CMP:- Used to compare the contents of two registers.
			-> Compare (register or memory) with accumulator (CMP R/M) –
				This is a 1-byte instruction. It compares the data byte in the register or memory with the contents of accumulator.

    		-> If A less than (R/M), the CY flag is set and Zero flag is 	reset.
    		-> If A equals to (R/M), the Zero flag is set and CY flag is 	reset.
    		-> If A greater than (R/M), the CY and Zero flag are reset.

			-> When memory is an operand, its address is specified by HL Pair. No contents are modified; however all remaining flags    (S, P, AC) are affected according to the result of subtraction.

			-> Syntax:- CMP B

# message.cpp
	-> Used to print helping statement

# start.cpp
	-> It is the main file and the execution of program will start from this file only.

# to run the program ( in linux )
	-> goto the folder path where all files are extracted using terminal
	-> and in terminal run the following cmd:
		g++ start.cpp
		./a.out

# note
	-> the following program is tested and compiled on ubuntu 20.04(LTS) with g++ (Ubuntu 9.3.0-10ubuntu2) 9.3.0 compiler.