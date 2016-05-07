/*
	kliorange
	TEST3 : Built the function sroot() 
	and overload three time by int , long int ,double type.
*/

#include <iostream>

void StoLorder(int &a, int &b)
{

	if(a>b)
	{
		a=a+b;
		b=a-b;
		a=a-b;
	}
	else
		return ;
}

int main(int argc, char const *argv[])
{
	int a,b;
	cin>>"A :">>a>>\n>>"B :">>b;
	cout"A :"<<a<<\n<<"B :"<<b<<endl;
	return 0;
}
