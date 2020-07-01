#include<bits/stdc++.h>
using namespace std;
unordered_map<int,string>display_content;
int A=0,B=0,C=0,D=0,E=0,H=0,L=0;
bool S=0,Z=0,AC=0,P=0,CY=0;
#include"Mnemonics.cpp"
#include"utility.cpp"
#include"Arithmetic.cpp"
#include"Branching.cpp"
#include"Load_and_Store.cpp"
#include"Logical.cpp"

int main()
{
	bool check=1;
	int bit_operation;
	while(check==1)
	{
		check=0;
		cout<<"Enter 16 for 16bit operation or 8 for 8bit operation\n";
		cin>>bit_operation;
		if(bit_operation==16)break;
		if(bit_operation==8)break;
		cout<<"Bit operation not found! Enter a valid bit operation\n";	
		check = 1;
	}

	check=1;
	string address="";
	while(check==1)
	{
		check=0;
		cout<<"Enter the starting address between 0000H-FFFFH\n";
		cin>>address;
		if(address.size()!=5)
		{
			cout<<"Enter a 4 digit address Ex:- 1010H\n";
			check=1;
		}
		else
		{
			for(int i=0;i<4;++i)
			{
				if(char_to_int.find(address[i])==char_to_int.end())
				{
					cout<<"Enter a valid address\n";
					check=1;break;
				}
			}
		}
	}

	while(true)
	{
		check=1;
		string user_instruction,mne;
		int n,i;
		while(check==1)
		{
			check = 0;
			mne="";
			cout<<"Enter a Instruction\n";
			getline(cin>>ws,user_instruction);
			i=0;
			while(user_instruction[i]!=' ')
			{
				mne.push_back(user_instruction[i]);
				++i;
			}
			if(mnemonics.find(mne)==mnemonics.end())
			{
				cout<<"Instruction not found\nRe-enter correct Instruction or type HELP for debugger\n";
				check=1;
			}
		}
		int instruction_id = mnemonics[mne].first;

		switch(instruction_id)
		{
			case 1:
					ADD(user_instruction);
					break;
			case 2:
					ADI(user_instruction);
					break;
			/*case 3:
					DAD(user_instruction);
					break;
			case 4:
					DCR(user_instruction);
					break;
			case 5:
					DCX(user_instruction);
					break;
			case 6:
					INR(user_instruction);
					break;
			case 7:
					INX(user_instruction);
					break;
			case 8:
					SUB(user_instruction);
					break;
			case 9:
					SUI(user_instruction);
					break;
			case 10:
					SET(user_instruction);
					break;
			case 11:
					JMP(user_instruction);
					break;
			case 12:
					JC(user_instruction);
					break;
			case 13:
					JNC(user_instruction);
					break;
			case 14:
					JZ(user_instruction);
					break;
			case 15:
					JNZ(user_instruction);
					break;
			case 16:
					MOV(user_instruction);
					break;
			case 17:
					MVI(user_instruction);
					break;
			case 18:
					LXI(user_instruction);
					break;
			case 19:
					LDA(user_instruction);
					break;
			case 20:
					STA(user_instruction);
					break;
			case 21:
					LHLD(user_instruction);
					break;
			case 22:
					SHLD(user_instruction);
					break;
			case 23:
					STAX(user_instruction);
					break;
			case 24:
					XCHG(user_instruction);
					break;
			case 25:
					CMA(user_instruction);
					break;
			case 26:
					CMP(user_instruction);
					break;
			case 27:
					EOF(user_instruction);
					break;
			case 28:
					HELP(user_instruction);
					break;
			*/default:
					cout<<"You found a bug\n";	
		}

	}
	return 0;
}
