#include <iostream>
#include <stack>

using namespace std;

//#define _debugging_

void call_process()
{
	stack<char> t_stk;
	char input[10001] = { 0, };

	cin >> input;
		
	string i_temp = input;
	char c_temp;
	for (int i = 0; i < i_temp.length(); ++i)
	{
		switch (input[i])
		{
		case '[':
		case '(':
		case '{':
			t_stk.push(input[i]);
			break;
		case ']':
			if (t_stk.empty())
			{
				cout << "NO" << endl;
				return;
			}
			c_temp = t_stk.top();
			if (c_temp != '[')
			{
				cout << "NO" << endl;
				return;
			}
			t_stk.pop();
			break;
		case ')':
			if (t_stk.empty())
			{
				cout << "NO" << endl;
				return;
			}
			c_temp = t_stk.top();
			if (c_temp != '(')
			{
				cout << "NO" << endl;
				return;
			}
			t_stk.pop();
			break;
		case '}':
			if (t_stk.empty())
			{
				cout << "NO" << endl;
				return;
			}
			c_temp = t_stk.top();
			if (c_temp != '{')
			{
				cout << "NO" << endl;
				return;
			}
			t_stk.pop();
			break;			
		}
	}
	
	if (!t_stk.empty())
	{
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;
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