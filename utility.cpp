#include<bits/stdc++.h>
using namespace std;

int hex_to_dec(string s)
{
	int n=s.size()-1,pow=0,result=0;
	for(int i=n;i>=0;--i)
	{
		int mul=1;
		for(int j=1;j<=pow;++j)
		{
			mul*=16;
		}
		result+=char_to_int[s[i]]*mul;
		//cout<<char_to_int[s[i]]<<" "<<result<<"\n";
		++pow;
	}
	return result;
}

string dec_to_hex(int &number)
{
	int shift_bit=1,shifting=8,counter=1,dec_val=0,mul_val=1;
	string hex_val;
	for(int i=0;i<shifting;++i)
	{
		if(number&shift_bit)dec_val+=mul_val;
		if(counter==4)
		{
			counter=mul_val=1;
			hex_val.push_back(int_to_char[dec_val]);
			dec_val=0;
		}
		else
		{
			mul_val*=2;
			++counter;
		}
		shift_bit<<=1;
	}
	reverse(hex_val.begin(),hex_val.end());
	return hex_val;
}