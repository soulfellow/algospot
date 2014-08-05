#include <iostream>
#include <math.h>

using namespace std;

//#define _debugging_

void call_process()
{	
	long long int play_cnt, win_cnt;
	int win_ratio = 0;
	long double t_cnt;

	cin >> play_cnt >> win_cnt;

	if (play_cnt == win_cnt)
	{
		cout << -1 << endl;
		return;
	}
	
	win_ratio = win_cnt*100 / play_cnt;

	t_cnt = (long double)((win_ratio + 1)*play_cnt - (100 * win_cnt)) / (long double)(99 - win_ratio);
	
	if (t_cnt > 2000000000)
	{
		cout << -1 << endl;
		return;
	}
		
	printf("%ld\n", (long long int)ceil(t_cnt));
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