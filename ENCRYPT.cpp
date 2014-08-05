#include <iostream>
#include <string>
#include <list>

using namespace std;

//#define _debugging_

void call_process()
{
	char input[101] = { 0, };
	char output[101] = { 0, };

	cin >> input;

	string temp = input;
	int len = temp.length();
	if (len % 2)	
	{
		//odd
		output[len] = NULL;
		for (int i = 0; i < len; i += 2)
		{
			output[i / 2] = input[i];
			if (i == len - 1)
				break;
			output[(len + i) / 2 + 1] = input[i + 1];
		}
	}
	else
	{
		//even
		output[len] = NULL;
		for (int i = 0; i < len; i += 2)
		{
			output[i / 2] = input[i];
			output[(len +i)/2] = input[i + 1];
		}
	}
	string out_temp = output;
	
	cout << out_temp << endl;
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