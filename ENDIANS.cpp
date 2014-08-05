#include <iostream>

using namespace std;

//#define _debugging_

void call_process()
{
	unsigned int val, con_val;
	
	cin >> val;

	con_val = 0;
	con_val |= (val & 0xFF) << 24;
	con_val |= (val & 0xFF00) << 8;
	con_val |= (val & 0xFF0000) >> 8;
	con_val |= (val & 0xFF000000) >> 24;
	
	cout << con_val << endl;
}

int main(void)
{
	int loop;

	cin >> loop;

	while(loop--)
	{
		call_process();
	}

#if defined _debugging_
	while (1);
#endif

	return 0;
}