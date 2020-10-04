#include<iostream>
using namespace std;

void help()
{
	cout<<"Arithmetic Instructions\n
		ADD Ex:- ADD B\n
		ADI Ex:- ADI 45H\n
		SUI Ex:- SUI 24H\n
		SUB Ex:- SUB D\n
		DCR Ex:- DCR A\n
		INR Ex:- INR B\n
		INX Ex:- INX B\n
		DCX Ex:- DCX B\n
		DAD Ex:- DAD B\n\n
		Logical Instructions\n
		CMA Ex:- CMA\n
		CMP Ex:- CMP B\n\n
		Branching Instructions\n
		JMP Ex:- JMP 4000H\n
		JC Ex:- JC 4000H\n
		JNC Ex:- JNC 5000H\n
		JZ Ex:- JZ 8000H\n\n
		Load and Store Instructions\n
		MOV Ex:- MOV B, A\n
		MVI Ex:- MVI A, 54H\n
		LDA Ex:- LDA 4000H\n
		STA Ex:- STA 4000H\n
		SHLD Ex:- 4000H\n
		LHLD Ex:- LHLD 5000H\n
		XCHG Ex:- XCHG\n
		LXI Ex:- LXI H, 4000H\n
		STAX Ex:- STAX B\n\n
		";
}

void help_debug()
{
	cout<<"helping debug\n";
}
