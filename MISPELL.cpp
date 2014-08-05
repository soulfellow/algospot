#include <iostream>
#include <string>

using namespace std;

//#define _debugging_

void call_process()
{	
	static int count = 0;
	int index;
	char input[81] = { 0, };
	
	cin >> index;
	cin >> input;
	
	cout << ++count << " ";

	string output = input;
	cout << output.substr(0, index-1) << output.substr(index, output.length()) << endl;
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