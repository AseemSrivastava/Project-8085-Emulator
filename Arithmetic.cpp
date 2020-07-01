#include<bits/stdc++.h>
using namespace std;

void ADD(string &user_instruction)
{
	switch(user_instruction[4])
	{
		case 'A':
				A+=A; 
				// cout<<A<<"\n";
				break;
		case 'B':
				A+=B; 
				break;
		case 'C':
				A+=C;
				 break;
		case 'D':
				A+=D;
				break;
		case 'E':
				A+=E;
				break;
		case 'H':
				A+=H;
				break;
		case 'L':
				A+=L;
				break;
		default: 
				cout<<"You found a bug!";
	}
}

void ADI(string &user_instruction)
{
	string hex_number;
	hex_number.push_back(user_instruction[4]);
	hex_number.push_back(user_instruction[5]);
	A+=hex_to_dec(hex_number);
	// cout<<A<<"\n";
}

void SUB(string &user_instruction)
{
	switch(user_instruction[4])
	{
		case 'A':
				A-=A;
				break;
		case 'B':
				A-=B; 
				break;
		case 'C':
				A-=C;
				 break;
		case 'D':
				A-=D;
				break;
		case 'E':
				A-=E;
				break;
		case 'H':
				A-=H;
				break;
		case 'L':
				A-=L;
				break;
		default: 
				cout<<"You found a bug!";
	}
}

void DAD(string &user_instruction)
{

	switch(user_instruction[4])
	{
		case 'B':
				A-=B;
				break;
		case 'D':
				A-=D;
				break;
		case 'H':
				A-=H;
				break;
		default: 
				cout<<"You found a bug!";
	}
}