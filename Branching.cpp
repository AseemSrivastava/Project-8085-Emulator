#include<bits/stdc++.h>
using namespace std;

bool JMP(string &user_instruction,int &next_address)
{
	string address_temp="";
	for(int i=4;i<=7;++i)address_temp.push_back(user_instruction[i]);
	int add_int = hex_to_dec(address_temp);
	if(address_instruction.find(add_int)!=address_instruction.end())next_address = add_int;
	else return true;
	return false;
}

bool JC(string &user_instruction,int &next_address)
{
	string address_temp="";
	for(int i=3;i<=6;++i)address_temp.push_back(user_instruction[i]);
	int add_int = hex_to_dec(address_temp);
	if(address_instruction.find(add_int)!=address_instruction.end())next_address = add_int;
	else return true;
	CF = 0;
	return false;
}

bool JNC(string &user_instruction,int &next_address)
{
	string address_temp="";
	for(int i=4;i<=7;++i)address_temp.push_back(user_instruction[i]);
	int add_int = hex_to_dec(address_temp);
	if(address_instruction.find(add_int)!=address_instruction.end())next_address = add_int;
	else return true;
	return false;
}

bool JZ(string &user_instruction,int &next_address)
{
	string address_temp="";
	for(int i=3;i<=6;++i)address_temp.push_back(user_instruction[i]);
	int add_int = hex_to_dec(address_temp);
	if(address_instruction.find(add_int)!=address_instruction.end())next_address = add_int;
	else return true;
	ZF = 0;
	return false;
}

bool JNZ(string &user_instruction,int &next_address)
{
	string address_temp="";
	for(int i=4;i<=7;++i)address_temp.push_back(user_instruction[i]);
	int add_int = hex_to_dec(address_temp);
	if(address_instruction.find(add_int)!=address_instruction.end())next_address = add_int;
	else return true;
	return false;
}