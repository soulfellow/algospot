#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//#define _debug_mode_

#define MAX_LANGTH	81

#if defined _debug_mode_
ifstream r_file;

bool get_testData(char* pData)
{
	if (r_file.eof())
	{
		cout << "file eof !!" << endl << "exit!!" << endl;
		return false;
	}

	r_file.getline(pData, MAX_LANGTH);
	
	return true;
}
#endif

void call_process(void)
{
	char input[MAX_LANGTH];
	int res;
		
#if defined _debug_mode_
	res = get_testData(input);
	if (res != true)
	{
		cout << "error input data count !!" << endl;
	}

	cout << input << endl;
	string str_temp =input;

#else
	string str_temp;

	getline(cin, str_temp);
	
#endif
			
	int pos;

	while ((pos = str_temp.find("%20")) >= 0)
	{
		str_temp.erase(pos, 3);
		str_temp.insert(pos, " ");
	}
	while ((pos = str_temp.find("%21")) >= 0)
	{
		str_temp.erase(pos, 3);
		str_temp.insert(pos, "!");
	}
	while ((pos = str_temp.find("%24")) >= 0)
	{
		str_temp.erase(pos, 3);
		str_temp.insert(pos, "$");
	}

	while ((pos = str_temp.find("%28")) >= 0)
	{
		str_temp.erase(pos, 3);
		str_temp.insert(pos, "(");
	}
	while ((pos = str_temp.find("%29")) >= 0)
	{
		str_temp.erase(pos, 3);
		str_temp.insert(pos, ")");
	}
	while ((pos = str_temp.find("%2a")) >= 0)
	{
		str_temp.erase(pos, 3);
		str_temp.insert(pos, "*");
	}
	int cnt_25 = 0;
	int index_25[28] = { -1, };
	string str_temp_25 = str_temp;
	while ((pos = str_temp_25.find("%25")) >= 0)
	{		
		index_25[cnt_25] = pos + (cnt_25 *3);
		cnt_25++;
		str_temp_25.erase(pos, 3);
	}
	for (int i = cnt_25-1; i >= 0 ; i--)
	{
		str_temp.erase(index_25[i],3);
		str_temp.insert(index_25[i], "%");
	}

	cout << str_temp << endl;
}

int main()
{
	int res = true;
	string temp;
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
	char cnt_temp;
	res = get_testData(&cnt_temp);
	loop = atoi(&cnt_temp);
	
	if (res != true)
	{
		cout << "input data error in test file !!" << endl;
	}
#else
	//cin >> loop;	
	getline(cin, temp);	

	loop = stoi(temp);

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