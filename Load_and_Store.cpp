#include<bits/stdc++.h>
using namespace std;

void MOV(string &user_instruction)
{
	int tmp;
	int i=user_instruction.size()-1;
	while(i>=0 && user_instruction[i]<'A' && user_instruction[i]>'Z')--i;
	switch(user_instruction[i])
	{
		case 'A':
				tmp=A;
				break;
		case 'B':
				tmp=B;
				break;
		case 'C':
				tmp=C;
				 break;
		case 'D':
				tmp=D;
				break;
		case 'E':
				tmp=E;
				break;
		case 'H':
				tmp=H;
				break;
		case 'L':
				tmp=L;
				break;
		default: 
				cout<<"You found a bug!";
	}
	--i;
	while(i>=0 && user_instruction[i]<'A' && user_instruction[i]>'Z')--i;
	switch(user_instruction[i])
	{
		case 'A':
				A=tmp;
				break;
		case 'B':
				B=tmp;
				break;
		case 'C':
				C=tmp;
				 break;
		case 'D':
				D=tmp;
				break;
		case 'E':
				E=tmp;
				break;
		case 'H':
				H=tmp;
				break;
		case 'L':
				L=tmp;
				break;
		default: 
				cout<<"You found a bug!";
	}
}

void MVI(string &user_instruction)
{
	string hex_number = "";
	hex_number.push_back(user_instruction[7]);
	hex_number.push_back(user_instruction[8]);
	int tmp = hex_to_dec(hex_number);
	switch(user_instruction[4])
	{
		case 'A':
				A=tmp;
				break;
		case 'B':
				B=tmp;
				break;
		case 'C':
				C=tmp;
				 break;
		case 'D':
				D=tmp;
				break;
		case 'E':
				E=tmp;
				break;
		case 'H':
				H=tmp;
				break;
		case 'L':
				L=tmp;
				break;
		default: 
				cout<<"You found a bug!";
	}
}

void LDA(string &user_instruction)
{
	string address = "";
	for(int i=4;i<=7;++i)address.push_back(user_instruction[i]);
	A = address_data[hex_to_dec(address)];
}

void STA(string &user_instruction)
{
	string address = "";
	for(int i=4;i<=7;+i)address.push_back(user_instruction[i]);
	address_data[hex_to_dec(address)] = A;
}

void SET(string &user_instruction)
{
	string address = "";
	string str_data = "";
	for(int i=4;i<=7;++i)address.push_back(user_instruction[i]);
	if(hex_to_dec(address)>=hex_to_dec(starting_address) && hex_to_dec(address)<=hex_to_dec("FFFF"))
	{
		for(int i=10;i<=user_instruction.size()-2;++i)str_data.push_back(user_instruction[i]);
		int int_data = hex_to_dec(str_data);
		address_data[hex_to_dec(address)] = int_data;
	}
	else cout<<"Invalid address or data\n";
}

void SHLD(string &user_instruction)
{
	string address = "";
	for(int i=5;i<=8;++i)address.push_back(user_instruction[i]);
	address_data[hex_to_dec(address)] = L;
	int temp = hex_to_dec(address);
	++temp;
	address_data[temp] = H;
}

void LHLD(string &user_instruction)
{
	string address = "";
	for(int i=5;i<=8;++i)address.push_back(user_instruction[i]);
	L = address_data[hex_to_dec(address)];
	int temp = hex_to_dec(address);
	++temp;
	H = address_data[temp];
}

void XCHG()
{
	swap(H,D);
	swap(L,E);
}

void LXI(string &user_instruction)
{
	string address1 = "",address2 = "";
	for(int i=7;i<=8;++i)address1.push_back(user_instruction[i]);
	for(int i=9;i<=10;++i)address2.push_back(user_instruction[i]);
	switch(user_instruction[4])
	{
		case 'B':
				C = address_data[hex_to_dec(address2)];
				B = address_data[hex_to_dec(address1)];	
				break;
		case 'D':
				E = address_data[hex_to_dec(address2)];
				D = address_data[hex_to_dec(address1)];
				break;
		case 'H':
				L = address_data[hex_to_dec(address2)];
				H = address_data[hex_to_dec(address1)];
				break;
		default: 
				cout<<"You found a bug!";
	}
}

void STAX(string &user_instruction)
{
	string address = "";
	switch(user_instruction[5])
	{
		case 'B':
				address = dec_to_hex(B)+dec_to_hex(C);
				address_data[hex_to_dec(address)] = A;
				break;
		case 'D':
				address = dec_to_hex(D)+dec_to_hex(E);
				address_data[hex_to_dec(address)] = A;
				break;
		case 'H':
				address = dec_to_hex(H)+dec_to_hex(L);
				address_data[hex_to_dec(address)] = A;
				break;
		default: 
				cout<<"You found a bug!";
	}
}

