#include <iostream>
#include <list>

using namespace std;

//#define _debugging_

void call_process()
{	
	int input;
	list<int> ilis;	
	int div;
	cin >> input;

	ilis.push_back(1);

	div = input / 2;
	for (int i = 2; i <= div; ++i)
	{
		if (input %i == 0)
			ilis.push_back(i);
	}
	
	list<int>::iterator ilter = ilis.begin();

	int sum=0;
	while (ilter != ilis.end())
	{
		sum += *ilter;		
		ilter++;
	}

	if (sum <= input)
	{
		cout << "not weird" << endl;
		return;
	}

	ilter = ilis.end();
	int t_input = input;
	for (int j = ilis.size(); j>=1; --j)
	{
		ilter--;
		t_input -= *ilter;

		if (t_input < 0)
			t_input += *ilter;
						
		if (t_input == 0)
		{
			cout << "not weird" << endl;
			return;
		}
	}
	cout << "weird" << endl;
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