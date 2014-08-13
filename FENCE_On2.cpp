#include <iostream>
#include <stdio.h>

using namespace std;

void call_process()
{
	int input_cnt;
	int max_high;
	int max_area=0;	
	int high[20001] ={0,};	
	int i, j;
	int t_area = 0;
	int w=0;

	cin >> input_cnt;

	for(int i=0; i < input_cnt; ++i){
		int temp;
		cin >> temp;

		high[i] = temp;

		if(max_high < temp)
			max_high = temp;
	}

	for(i=1; i <= max_high; ++i){
		for(j=0; j<input_cnt;++j){
			if(high[j] < i){
				t_area = i*w;				
				w = 0;
				if(max_area < t_area)
					max_area = t_area;				
			}
			else
				w++;
		}

		t_area = i * w;
		w = 0;
		if(max_area < t_area)
			max_area = t_area;
	}
	printf("%d\n",max_area);
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
