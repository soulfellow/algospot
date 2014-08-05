#include <iostream>
#include <math.h>

using namespace std;

//#define _debugging_

typedef unsigned char BYTE;
void call_process()
{
	char input[8] = { 0, };
	BYTE h_code=0;
	
	cin >> input;
		
	for (int i = 0; i < 7; ++i)
	{
		if (input[i] == '1')
			h_code |=1 << i;
	}

	BYTE ck1=0, ck2=0, ck3=0;
	bool f_err = true;
	BYTE index = 0;

	ck1 = ((h_code >> 0) & 1) + ((h_code >> 2) & 1) + ((h_code >> 4) & 1) + ((h_code >> 6) & 1);	//0,2,4,6	
	ck2 = ((h_code >> 1) & 1) + ((h_code >> 2) & 1) + ((h_code >> 5) & 1) + ((h_code >> 6) & 1);	//1,2,5,6	
	ck3 = ((h_code >> 3) & 1) + ((h_code >> 4) & 1) + ((h_code >> 5) & 1) + ((h_code >> 6) & 1);	//3,4,5,6	
	
	if ((0 == ck1 % 2)&& (0== ck2 % 2)&& (0 == ck3 % 2))
		f_err = false;
	
	if (!f_err)
	{	
		cout << ((h_code >> 2) & 1) << ((h_code >> 4) & 1) << ((h_code >> 5) & 1) << ((h_code >> 6) & 1) << endl;
		return;
	}
	
	if (ck1 % 2)
		index |= (ck1 % 2);
	
	if (ck2 % 2)
		index |= (ck2 % 2) << 1;
	
	if (ck3 % 2)
		index |= (ck3 % 2 )<< 2;
			
	if (((h_code >> (index - 1)) &1)== 0)
	{
		h_code |= 1 << (index - 1);
	}
	else
	{
		h_code -= pow((double)2, (double)(index - 1));
	}
		
	cout << ((h_code >> 2) & 1) << ((h_code >> 4) & 1) << ((h_code >> 5) & 1) << ((h_code >> 6) & 1) << endl;	
}

int main(void)
{
	int loop;

	cin >> loop;

	while (loop--)
	{
		call_process();
	}

#if defined _debugging_
	while (1);
#endif

	return 0;
}