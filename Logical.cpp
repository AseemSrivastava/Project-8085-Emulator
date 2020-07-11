#include<bits/stdc++.h>
using namespace std;

void CMA()
{
	A^=255;
}

void CMP(string &user_instruction)
{
	SF=0,ZF=0,AC=0,PF=0,CF=0;
	int tmp=0;
	switch(user_instruction[4])
	{
		case 'A':
				tmp=flag_on_off_8bit_SUB(A);
				break;
		case 'B':
				tmp=flag_on_off_8bit_SUB(A,B);
				break;
		case 'C':
				tmp=flag_on_off_8bit_SUB(A,C);
				 break;
		case 'D':
				tmp=flag_on_off_8bit_SUB(A,D);
				break;
		case 'E':
				tmp=flag_on_off_8bit_SUB(A,E);
				break;
		case 'H':
				tmp=flag_on_off_8bit_SUB(A,H);
				break;
		case 'L':
				tmp=flag_on_off_8bit_SUB(A,L);
				break;
		default: 
				error = 1;
				cout<<"You found a bug!\n";
	}
	cout<<tmp<<"\n";
}