#include <iostream>

using namespace std;

//#define _debugging_

void call_process()
{
	int max, temp;
	int sum = 0;
		
	cin >> max;
	for (int i = 0; i < 9; i++)
	{
		cin >> temp;
		sum += temp;
	}

	if (sum <= max)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
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