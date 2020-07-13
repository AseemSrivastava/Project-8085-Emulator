#include<bits/stdc++.h>
using namespace std;
string starting_address="";
int next_address,end_address,A=0,B=0,C=0,D=0,E=0,H=0,L=0;
bool SF=0,ZF=0,AC=0,PF=0,CF=0,error=0,bit_operation=0;
unordered_map<int,string>display_content,address_instruction;
unordered_map<int,int>address_data; //can be value or instruction
#include"Mnemonics.cpp"
#include"utility.cpp"
#include"Arithmetic.cpp"
#include"Branching.cpp"
#include"Load_and_Store.cpp"
#include"Logical.cpp"

int main()
{
	bool check=1;
	while(check==1)
	{
		int temp;
		check=0;
		cout<<"Enter 16 for 16bit operation or 8 for 8bit operation\n";
		cin>>temp;
		if(temp==16)
		{
			bit_operation=1;
			break;
		}
		if(temp==8)break;
		cout<<"Bit operation not found! Enter a valid bit operation\n";	
		check = 1;
	}

	check=1;
	while(check==1)
	{
		check=0;
		cout<<"Enter the starting address between 0000H-FFFFH\n";
		cin>>starting_address;
		if(starting_address.size()!=5)
		{
			cout<<"Enter a 4 digit address Ex:- 1010H\n";
			check=1;
		}
		else
		{
			for(int i=0;i<4;++i)
			{
				if(char_to_int.find(starting_address[i])==char_to_int.end())
				{
					cout<<"Enter a valid address\n";
					check=1;break;
				}
			}
		}
	}

	starting_address.pop_back();
	next_address = hex_to_dec(starting_address);
	string user_instruction,mne;
	int n,i;
	while(true)
	{
		check=1;
		while(check==1)
		{
			check = 0;
			mne="";
			cout<<"Enter a Instruction\n";
			getline(cin>>ws,user_instruction);
			for(int i=0;i<user_instruction.size();++i)user_instruction[i]=toupper(user_instruction[i]);
			i=0;
			while(i<user_instruction.size() &&  user_instruction[i]!=' ')
			{
				mne.push_back(user_instruction[i]);
				++i;
			}
			if(mnemonics.find(mne)==mnemonics.end())
			{
				cout<<"Instruction not found\nRe-enter correct Instruction or type HELP for debugger\n";
				check=1;
			}
			else if(instruction_size[mnemonics[mne].first].first!=user_instruction.size())
			{
				cout<<mne<<" instruction Example:- "<<instruction_size[mnemonics[mne].first].second<<"\n";
				cout<<"Re-enter correct Instruction or type HELP for debugger\n";
				if(user_instruction.size()>instruction_size[mnemonics[mne].first].first)
				{
					cout<<"Did you mean:-  ";
					for(int i=0;i<instruction_size[mnemonics[mne].first].first-1;++i)cout<<user_instruction[i];
					unordered_set<char>registers({'A','B','C','D','E','H','L'});
					if(registers.find(user_instruction[instruction_size[mnemonics[mne].first].first-1])!=registers.end())
					{
						cout<<user_instruction[instruction_size[mnemonics[mne].first].first-1];
					}
					else
					{
						cout<<"valid register name";
					}
					cout<<"\n";
				}
				check=1;	
			}
		}
		if(mnemonics[mne].first==27)break;
		address_instruction[next_address] += user_instruction;
		next_address+=mnemonics[mne].second-'0';
	}
	int temp;
	bool eof=0,jump_setter=0,no_extra_print = 0,jump=0,other_jump = 0;
	end_address = next_address;
	next_address = hex_to_dec(starting_address);
	while(next_address<end_address)
	{
		if(address_instruction.find(next_address)!=address_instruction.end())
		{
			string user_instruction = address_instruction[next_address];
			string temp_address = dec_to_hex(next_address);
			if(temp_address.size()!=4)
			{
				string temp;
				for(int i=0;i<4-temp_address.size();++i)temp.push_back('0');
				temp+=temp_address;
				temp_address=temp;
			}
			if(!no_extra_print)
			{
				display_content[next_address]+=temp_address+"H  ";
				display_content[next_address]+=user_instruction;
				for(int i=display_content[next_address].size();i<=25;++i)display_content[next_address].push_back(' ');
			}
			no_extra_print = 0;
			for(int i=0;i<user_instruction.size();++i)user_instruction[i]=toupper(user_instruction[i]);
			mne = "";
			i=0;
			while(i<user_instruction.size() &&  user_instruction[i]!=' ')
			{
				mne.push_back(user_instruction[i]);
				++i;
			}
			int instruction_id = mnemonics[mne].first;
			switch(instruction_id)
			{
				case 1:
						ADD(user_instruction); // ADD B
						break;
				case 2:
						ADI(user_instruction); // ADI 15H
						break;
				case 3:
						DAD(user_instruction); // DAD B
						break;
				case 4:
						DCR(user_instruction); // DCR B
						break;
				case 5:
						DCX(user_instruction);
						break;
				case 6:
						INR(user_instruction); // INR B 
						break;
				case 7:
						INX(user_instruction);
						break;
				case 8:
						SUB(user_instruction); // SUB A
						break;
				case 9:
						SUI(user_instruction); // SUI 05H
						break;
				case 10:
						SET(user_instruction); // SET 2500, 05H
						break;
				case 11:
						display_content[next_address]+=to_string(SF)+"  "+to_string(ZF)+"  "+to_string(AC)+"  "+to_string(PF)+"  "+to_string(CF)+"  ";
						display_content[next_address]+=dec_to_hex(A)+"H"+" ";
						display_content[next_address]+=dec_to_hex(B)+"H"+" ";
						display_content[next_address]+=dec_to_hex(C)+"H"+" ";
						display_content[next_address]+=dec_to_hex(D)+"H"+" ";
						display_content[next_address]+=dec_to_hex(E)+"H"+" ";
						display_content[next_address]+=dec_to_hex(H)+"H"+" ";
						display_content[next_address]+=dec_to_hex(L)+"H";
						temp = next_address;
						error = JMP(user_instruction,next_address);
						no_extra_print = 1;
						jump = 1;
						if(temp<next_address)
						{
							for(int j=temp+1;j<next_address;++j)
							{
								if(address_instruction.find(j)!=address_instruction.end())
								{
									string user_instr = address_instruction[j];
									string temp_addr = dec_to_hex(j);
									if(temp_addr.size()!=4)
									{
										string tem;
										for(int i=0;i<4-temp_addr.size();++i)tem.push_back('0');
										tem+=temp_addr;
										temp_addr=tem;
									}
									display_content[j]+=temp_addr+"H  ";
									display_content[j]+=user_instr;
									for(int i=display_content[j].size();i<=25;++i)display_content[j].push_back(' ');
									display_content[j]+=to_string(SF)+"  "+to_string(ZF)+"  "+to_string(AC)+"  "+to_string(PF)+"  "+to_string(CF)+"  ";
									display_content[j]+=dec_to_hex(A)+"H"+" ";
									display_content[j]+=dec_to_hex(B)+"H"+" ";
									display_content[j]+=dec_to_hex(C)+"H"+" ";
									display_content[j]+=dec_to_hex(D)+"H"+" ";
									display_content[j]+=dec_to_hex(E)+"H"+" ";
									display_content[j]+=dec_to_hex(H)+"H"+" ";
									display_content[j]+=dec_to_hex(L)+"H";
								}
							}
							no_extra_print = 0;
						}
						break;
				case 12:
						if(CF)
						{
							jump_setter = 1;
							no_extra_print = 1;
							other_jump = 1;
							display_content[next_address]+=to_string(SF)+"  "+to_string(ZF)+"  "+to_string(AC)+"  "+to_string(PF)+"  "+to_string(CF)+"  ";
							display_content[next_address]+=dec_to_hex(A)+"H"+" ";
							display_content[next_address]+=dec_to_hex(B)+"H"+" ";
							display_content[next_address]+=dec_to_hex(C)+"H"+" ";
							display_content[next_address]+=dec_to_hex(D)+"H"+" ";
							display_content[next_address]+=dec_to_hex(E)+"H"+" ";
							display_content[next_address]+=dec_to_hex(H)+"H"+" ";
							display_content[next_address]+=dec_to_hex(L)+"H";
							temp = next_address;
							error = JC(user_instruction,next_address);
							if(temp<next_address)
							{
								for(int j=temp+1;j<next_address;++j)
								{
									if(address_instruction.find(j)!=address_instruction.end())
									{
										string user_instr = address_instruction[j];
										string temp_addr = dec_to_hex(j);
										if(temp_addr.size()!=4)
										{
											string tem;
											for(int i=0;i<4-temp_addr.size();++i)tem.push_back('0');
											tem+=temp_addr;
											temp_addr=tem;
										}
										display_content[j]+=temp_addr+"H  ";
										display_content[j]+=user_instr;
										for(int i=display_content[j].size();i<=25;++i)display_content[j].push_back(' ');
										display_content[j]+=to_string(SF)+"  "+to_string(ZF)+"  "+to_string(AC)+"  "+to_string(PF)+"  "+to_string(CF)+"  ";
										display_content[j]+=dec_to_hex(A)+"H"+" ";
										display_content[j]+=dec_to_hex(B)+"H"+" ";
										display_content[j]+=dec_to_hex(C)+"H"+" ";
										display_content[j]+=dec_to_hex(D)+"H"+" ";
										display_content[j]+=dec_to_hex(E)+"H"+" ";
										display_content[j]+=dec_to_hex(H)+"H"+" ";
										display_content[j]+=dec_to_hex(L)+"H";
									}
								}
									no_extra_print = 0;
							}
						}
						break;
				case 13:
						if(!CF)
						{
							jump_setter = 1;
							no_extra_print = 1;
							other_jump = 1;
							display_content[next_address]+=to_string(SF)+"  "+to_string(ZF)+"  "+to_string(AC)+"  "+to_string(PF)+"  "+to_string(CF)+"  ";
							display_content[next_address]+=dec_to_hex(A)+"H"+" ";
							display_content[next_address]+=dec_to_hex(B)+"H"+" ";
							display_content[next_address]+=dec_to_hex(C)+"H"+" ";
							display_content[next_address]+=dec_to_hex(D)+"H"+" ";
							display_content[next_address]+=dec_to_hex(E)+"H"+" ";
							display_content[next_address]+=dec_to_hex(H)+"H"+" ";
							display_content[next_address]+=dec_to_hex(L)+"H";
							temp = next_address;
							error = JNC(user_instruction,next_address); //
							if(temp<next_address)
							{
								for(int j=temp+1;j<next_address;++j)
								{
									if(address_instruction.find(j)!=address_instruction.end())
									{
										string user_instr = address_instruction[j];
										string temp_addr = dec_to_hex(j);
										if(temp_addr.size()!=4)
										{
											string tem;
											for(int i=0;i<4-temp_addr.size();++i)tem.push_back('0');
											tem+=temp_addr;
											temp_addr=tem;
										}
										display_content[j]+=temp_addr+"H  ";
										display_content[j]+=user_instr;
										for(int i=display_content[j].size();i<=25;++i)display_content[j].push_back(' ');
										display_content[j]+=to_string(SF)+"  "+to_string(ZF)+"  "+to_string(AC)+"  "+to_string(PF)+"  "+to_string(CF)+"  ";
										display_content[j]+=dec_to_hex(A)+"H"+" ";
										display_content[j]+=dec_to_hex(B)+"H"+" ";
										display_content[j]+=dec_to_hex(C)+"H"+" ";
										display_content[j]+=dec_to_hex(D)+"H"+" ";
										display_content[j]+=dec_to_hex(E)+"H"+" ";
										display_content[j]+=dec_to_hex(H)+"H"+" ";
										display_content[j]+=dec_to_hex(L)+"H";
									}
								}
								no_extra_print = 0;
							}
						}
						break;
				case 14:
						if(ZF)
						{
							jump_setter = 1;
							no_extra_print = 1;
							other_jump = 1;
							display_content[next_address]+=to_string(SF)+"  "+to_string(ZF)+"  "+to_string(AC)+"  "+to_string(PF)+"  "+to_string(CF)+"  ";
							display_content[next_address]+=dec_to_hex(A)+"H"+" ";
							display_content[next_address]+=dec_to_hex(B)+"H"+" ";
							display_content[next_address]+=dec_to_hex(C)+"H"+" ";
							display_content[next_address]+=dec_to_hex(D)+"H"+" ";
							display_content[next_address]+=dec_to_hex(E)+"H"+" ";
							display_content[next_address]+=dec_to_hex(H)+"H"+" ";
							display_content[next_address]+=dec_to_hex(L)+"H";
							temp = next_address;
							error = JZ(user_instruction,next_address); //
							if(temp<next_address)
							{
								for(int j=temp+1;j<next_address;++j)
								{
									if(address_instruction.find(j)!=address_instruction.end())
									{
										string user_instr = address_instruction[j];
										string temp_addr = dec_to_hex(j);
										if(temp_addr.size()!=4)
										{
											string tem;
											for(int i=0;i<4-temp_addr.size();++i)tem.push_back('0');
											tem+=temp_addr;
											temp_addr=tem;
										}
										display_content[j]+=temp_addr+"H  ";
										display_content[j]+=user_instr;
										for(int i=display_content[j].size();i<=25;++i)display_content[j].push_back(' ');
										display_content[j]+=to_string(SF)+"  "+to_string(ZF)+"  "+to_string(AC)+"  "+to_string(PF)+"  "+to_string(CF)+"  ";
										display_content[j]+=dec_to_hex(A)+"H"+" ";
										display_content[j]+=dec_to_hex(B)+"H"+" ";
										display_content[j]+=dec_to_hex(C)+"H"+" ";
										display_content[j]+=dec_to_hex(D)+"H"+" ";
										display_content[j]+=dec_to_hex(E)+"H"+" ";
										display_content[j]+=dec_to_hex(H)+"H"+" ";
										display_content[j]+=dec_to_hex(L)+"H";
									}
								}
								no_extra_print = 0;
							}
						}
						break;
				case 15:
						if(!ZF)
						{
							jump_setter = 1;
							no_extra_print = 1;other_jump = 1;
							display_content[next_address]+=to_string(SF)+"  "+to_string(ZF)+"  "+to_string(AC)+"  "+to_string(PF)+"  "+to_string(CF)+"  ";
							display_content[next_address]+=dec_to_hex(A)+"H"+" ";
							display_content[next_address]+=dec_to_hex(B)+"H"+" ";
							display_content[next_address]+=dec_to_hex(C)+"H"+" ";
							display_content[next_address]+=dec_to_hex(D)+"H"+" ";
							display_content[next_address]+=dec_to_hex(E)+"H"+" ";
							display_content[next_address]+=dec_to_hex(H)+"H"+" ";
							display_content[next_address]+=dec_to_hex(L)+"H";
							temp = next_address;
							error = JNZ(user_instruction,next_address); //
							if(temp<next_address){
								for(int j=temp+1;j<next_address;++j)
								{
									if(address_instruction.find(j)!=address_instruction.end())
									{
										string user_instr = address_instruction[j];
										string temp_addr = dec_to_hex(j);
										if(temp_addr.size()!=4)
										{
											string tem;
											for(int i=0;i<4-temp_addr.size();++i)tem.push_back('0');
											tem+=temp_addr;
											temp_addr=tem;
										}
										display_content[j]+=temp_addr+"H  ";
										display_content[j]+=user_instr;
										for(int i=display_content[j].size();i<=25;++i)display_content[j].push_back(' ');
										display_content[j]+=to_string(SF)+"  "+to_string(ZF)+"  "+to_string(AC)+"  "+to_string(PF)+"  "+to_string(CF)+"  ";
										display_content[j]+=dec_to_hex(A)+"H"+" ";
										display_content[j]+=dec_to_hex(B)+"H"+" ";
										display_content[j]+=dec_to_hex(C)+"H"+" ";
										display_content[j]+=dec_to_hex(D)+"H"+" ";
										display_content[j]+=dec_to_hex(E)+"H"+" ";
										display_content[j]+=dec_to_hex(H)+"H"+" ";
										display_content[j]+=dec_to_hex(L)+"H";
									}
								}
								no_extra_print = 0;
							}
						}
						break;
				case 16:
						MOV(user_instruction); // MOV A, B
						break;
				case 17:
						MVI(user_instruction); // MVI A, 54H
						break;
				case 18:
						LXI(user_instruction); // LXI H, 5050H
						break;
				case 19:
						LDA(user_instruction); // LDA 4000H
						break;
				case 20:
						STA(user_instruction); // STA 8000H
						break;
				case 21:
						LHLD(user_instruction); // LHLD 4000H
						break;
				case 22:
						SHLD(user_instruction); // SHLD 4000H
						break;
				case 23:
						STAX(user_instruction);
						break;
				case 24:
						XCHG(); // XCHG
						break;
				case 25:
						CMA(); // CMA
						break;
				case 26:
						CMP(user_instruction); // CMP B
						break;
				case 27:
						end_address = next_address;
						eof = 1;
						break;
				/*case 28:
						HELP(user_instruction);
						break;
				*/default:
						error = 1;
						cout<<"You found a bug\n";
			}
			if(eof)break;
			if(!jump_setter && !jump)
			{
				display_content[next_address]+=to_string(SF)+"  "+to_string(ZF)+"  "+to_string(AC)+"  "+to_string(PF)+"  "+to_string(CF)+"  ";
				display_content[next_address]+=dec_to_hex(A)+"H"+" ";
				display_content[next_address]+=dec_to_hex(B)+"H"+" ";
				display_content[next_address]+=dec_to_hex(C)+"H"+" ";
				display_content[next_address]+=dec_to_hex(D)+"H"+" ";
				display_content[next_address]+=dec_to_hex(E)+"H"+" ";
				display_content[next_address]+=dec_to_hex(H)+"H"+" ";
				display_content[next_address]+=dec_to_hex(L)+"H";
				if(!other_jump)next_address+=mnemonics[mne].second-'0';
			}
			other_jump = 0;	
			jump = 0;
			jump_setter = 0;
		}
		else error = 1;
		if(error)break;
	}
	if(error)cout<<"ERROR occured!\n";
	else 
	{
		cout<<"Addr      Mne             SF ZF AC PF CF  A   B   C   D   E   H   L\n";
		for(int i=hex_to_dec(starting_address);i<end_address;++i)
		{
			if(display_content.find(i)!=display_content.end())
			{
				for(int j=0;j<68;++j)
				cout<<display_content[i][j];
				cout<<"\n";
			}
		}
	}
	return 0;
}
