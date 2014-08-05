#include <iostream>
#include <string>
#include <list>

using namespace std;

//#define _debugging_

void call_process()
{
	char input[1001];
	
	cin >> input;

	string temp = input;
	list<string> token;	
	for (int i = 0; i < temp.length(); i+=2)
		token.push_back(temp.substr(i,2));		
		
	token.sort();
	list<string>::iterator p_token = token.begin();
	while (p_token != token.end())
	{
		cout << *p_token;
		p_token++;
	}

	cout << endl;	
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