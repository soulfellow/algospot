#include <iostream>
#include <string>

using namespace std;

//#define _debugging_

typedef unsigned char BYTE;
void call_process()
{
	char matrix[20][20] = { 0, };
	int row, column;
	string b_input;
	string b_output;
	BYTE alpa = 0;

	cin >> row >> column >> b_input;

	for (int i = 0; i < row; ++i)
	{
		for(int j=0; j < column; ++j)
			matrix[i][j] = b_input[i*column + j];			
	}

	for (int i = 0; i < column; ++i)
		b_output += matrix[0][i];

	int t_row = row;
	int t_column = column;
	int sw = -1;
	int x = 0, y = column-1;
	while (t_row-1 >0 && t_column > 0)
	{
		//위에서 아래 & 오른쪽에서 왼쪽
		for (int i = t_row - 1; i > 0; --i)
		{
			if (sw == -1)	//위에서 아래
				++x;
			else			//아래에서 위
				--x;
			b_output += matrix[x][y];
		}

		for (int j = t_column - 1; j > 0; --j)
		{
			if (sw == -1)		//오른쪽에서 왼쪽
				--y;
			else
				++y;		//왼쪽에서 오른쪽
			b_output += matrix[x][y];
		}

		sw *= -1;
		--t_row;
		--t_column;
	}
	
	if(row > column)
	{
		//위에서 아래 & 오른쪽에서 왼쪽
		for (int i = t_row - 1; i > 0; --i)
		{
			if (sw == -1)	//위에서 아래
				++x;
			else			//아래에서 위
				--x;
			b_output += matrix[x][t_column - 1];
		}
	}

	for(int i=0; i < b_output.length()/5; ++i)
	{
		for(int j=0; j<5; ++j)
		{
			if(b_output[i*5+j]=='1')
				alpa |= 1 << (4-j);
		}
		if (alpa == 0)
			cout << " ";
		else
			printf("%c",alpa+64);
		alpa = 0;
	}
	cout << endl;
}

int main(void)
{
	int loop;

	cin >> loop;

	int cnt = 0;
	while (loop--)
	{
		++cnt;
		cout << cnt << " ";
		call_process();
	}

#if defined _debugging_
	while (1);
#endif

	return 0;
}