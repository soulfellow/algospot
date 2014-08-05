#include <iostream>
#include <string>

using namespace std;

//#define _debugging_

string day[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
int max_mm[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void call_process()
{
	int mm, dd;
	char c_day[10] = { 0, };
	int index;
	int output[7] = { 0, };

	cin >> mm >> dd >> c_day;

	string temp = c_day;
	for (int i = 0; i < 7; ++i)
	{
		if (temp == day[i])
		{
			index = i;
			break;
		}
	}

	int temp_dd = dd;
	output[index] = temp_dd;
	int cnt = 0;
	for (int i = index-1; i >= 0; --i)
	{
		++cnt;
		int cal = dd - cnt;
		if (cal < 1)
		{
			int t_mm = mm-1;
			if (t_mm == 0)
				t_mm = 12;

			cal = max_mm[t_mm-1] + cal;

		}
			output[i] = cal;
	}
	
	cnt = 0;
	for (int i = index + 1; i <7; ++i)
	{
		++cnt;
		int cal = dd + cnt;
		if (cal > max_mm[(mm-1)])
		{
			cal = cal - max_mm[(mm-1)];

		}
		output[i] = cal;
	}

	for (int i = 0; i < 7; ++i)
	{
		cout << output[i];
		if (i != 6)
			cout << " ";
	}
	cout << endl;
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