#include <iostream>

using namespace std;

//#define _debugging_

void call_process()
{
	int link[51][51] = {0,};
	int town_cnt =0;
	int day = 0;
	int s_town;
	int print_town[51] = {0,};
	int load_cnt[51] = {0,};	//index의 마을에서 연결된 길의 수
	
	cin >> town_cnt >> day >> s_town;
	
	// 세로 : 해당 마을 번호  가로 : 해당 마을로 길이 있는지 여부
	for(int i=0; i<town_cnt;++i)
	{
		int cnt = 0;		//index의 마을에서 연결된 길의 수 count
		for(int j=0; j<town_cnt; ++j)	
		{
			int temp =0;
			cin >> temp;
			link[i][j] = temp;
			
			if(temp == 1)
				cnt++;
		}
		load_cnt[i] = cnt;
	}
	
	int print_cnt = 0;
	cin >> print_cnt;
	
	for(int i=0; i < print_cnt; ++i)	
	{		
		cin >> print_town[i];
	}
	
///
	for(int i=0; i < town_cnt; ++i)
	{
		cout << i << " : " << load_cnt[i] << "  ";
	}
	cout << endl;
///
	
	//day에 따른 확률 계산
	double e_probab[51] = {0,};		//day에 index마을에 도착할 확률
	double s_probab = 1/load_cnt[s_town];				//처음 출발지에서의 다른마을로 갈 확률
		
	for(int k=1; k <= day; ++k)
	{
		for(int i=0; i<town_cnt; ++i)
		{
			double probab = 0;
			for(int j=0; j<town_cnt; ++j)
			{
				if(link[i][j] == 1)
				{
					if(k==1)
						probab+= s_probab * 1/load_cnt[j];
					else
						probab += e_probab[j] * 1/load_cnt[j];
				}
			}
			e_probab[i] = probab;
		}
	}
	
	for(int i=0; i < print_cnt; ++i)
		printf("%0.8f ", e_probab[print_town[i]]);
	
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