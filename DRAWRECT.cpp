#include <iostream>
#include <fstream>

using namespace std;

//#define _debug_mode_

#if defined _debug_mode_
ifstream r_file;

bool get_testData(int* pData)
{
	if (r_file.eof())
	{
		cout << "file eof !!" << endl << "exit!!"<< endl;
			return false;
	}
	
	r_file >> *pData;
	
	return true;
}
#endif

void call_process(void)
{
	int inputData[6];
	int temp;
	int res;
	int x, y;
#if defined _debug_mode_
	for (int i = 0; i < 6; i++)
	{
		res = get_testData(&temp);
		if (res != true)
		{
			cout << "error input data count !!" << endl;
		}
		
		inputData[i] = temp;

		if(i%2==0)
			cout << endl;

		cout << inputData[i] << " ";		
	}
	cout << endl << "result : ";
#else
	for(int i=0; i < 6; i++)
	{
		cin >> inputData[i];
	}	
#endif

	if (inputData[0] == inputData[2])
		x = inputData[4];
	else if (inputData[2] == inputData[4])
		x = inputData[0];
	else
		x = inputData[2];

	if (inputData[1] == inputData[3])
		y = inputData[5];
	else if (inputData[3] == inputData[5])
		y = inputData[1];
	else
		y = inputData[3];

	cout << x << " " << y << endl;
}

int main()
{
	int res = true;
	char temp;
	int loop = 0;
	
#if defined _debug_mode_
	r_file.open("test.txt", ios::in);
	if (r_file.fail())
	{
		r_file.close();
		cout << "no exist test file!" << endl;
		
		getchar();
		return -1;
	}
#endif

#if defined _debug_mode_
	res = get_testData(&loop);
	//loop = atoi(&temp);
	
	if (res != true)
	{
		cout << "input data error in test file !!" << endl;
	}
#else
		cin >> loop;
#endif

	while (loop > 0)
	{		
#if defined _debug_mode_
		cout << loop << endl;
#endif
		
		call_process();
		loop--;
	}

#if defined _debug_mode_
	r_file.close();
#endif

	getchar();
	return 0;
}