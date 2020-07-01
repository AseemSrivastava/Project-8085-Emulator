#include<'main.h'>
using namespace std;

void ADD(string &user_instruction)
{
	switch(user_instruction[4])
	{
		case 'A':
				A+=A; 
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