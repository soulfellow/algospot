#include <iostream>

using namespace std;

void call_process()
{
	cout << "Hello Algospot!" << endl;
}

int main(void)
{
	int loop;

	cin >> loop;

	while(loop--)
	{
		call_process();
	}

	return 0;
}