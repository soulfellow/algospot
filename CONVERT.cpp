#include <iostream>

using namespace std;

//#define _debugging_

void call_process()
{	
	static int count = 0;
	double val;
	char input[3] = { 0, };
	
	cin >> val;
	cin >> input;
	
	cout << ++count << " ";

	switch (input[0])
	{
	case 'k' :		
		printf("%.4lf lb\n", val*2.2046);
		break;
	case 'l' :
		if (input[1] == 'b')
		{			
			printf("%.4lf kg\n", val*0.4536);
			break;
		}		
		printf("%.4lf g\n", val*0.2642);
		break;	
	case 'g' :		
		printf("%.4lf l\n", val*3.7854);
		break;
	}	
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