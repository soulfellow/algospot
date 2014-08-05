#include <iostream>
#include <string>
#include <list>

using namespace std;

//#define _debugging_

void call_process()
{	
	string t_str;
	list<string> token_lis;
	int pos, res;
	int val[2];

	getline(cin, t_str);

	while ((pos = t_str.find(" ")) >= 0)
	{
		token_lis.push_back(t_str.substr(0, pos));	
		t_str = t_str.substr(pos + 1, t_str.length());	
	}
	token_lis.push_back(t_str);

	list<string>::iterator tlter = token_lis.begin();

	for (int i = 0; i < 2; ++i )
	{			
		switch ((*tlter)[0])
		{
		case 'z':	//zero
			val[i] = 0;
				break;
		case 'o':	//one
			val[i] = 1;
			break;
		case 't':	//two, three, ten
			switch ((*tlter)[1])
			{
			case 'w':
				val[i] = 2;
				break;
			case 'h':
				val[i] = 3;
				break;
			case 'e':
				val[i] = 10;
				break;
			}
			break;
		case 'f':	//four, five
			switch ((*tlter)[1])
			{
			case 'o':
				val[i] = 4;
				break;
			case 'i':
				val[i] = 5;
					break;				
			}
			break;
		case 's':	//six, seven
			switch ((*tlter)[1])
			{
			case 'i':
				val[i] = 6;
				break;
			case 'e':
				val[i] = 7;
				break;
			}
			break;
		case 'e':	//eight
			val[i] = 8;
			break;
		case 'n':	//nine
			val[i] = 9;
			break;
		}							
		tlter++;
		tlter++;
	}

	tlter = token_lis.begin();
	tlter++;

	switch ((*tlter)[0])
	{
	case '+':
		res = val[0] + val[1];		
		break;
	case '-':
		res = val[0] - val[1];		
		break;
	case '*':
		res = val[0] * val[1];		
		break;
	}

	string r_str;
	switch (res)
	{
	case 0:
		r_str = "zero";
		break;
	case 1:
		r_str = "one";
		break;
	case 2:
		r_str = "two";
		break;
	case 3:
		r_str = "three";
		break;
	case 4:
		r_str = "four";
		break;
	case 5:
		r_str = "five";
		break;
	case 6:
		r_str = "six";
		break;
	case 7:
		r_str = "seven";
		break;
	case 8:
		r_str = "eight";
		break;
	case 9:
		r_str = "nine";
		break;
	case 10:
		r_str = "ten";
		break;
	default:
		cout << "No" << endl;
		return;
	}
	tlter = token_lis.end();
	tlter--;
	if (r_str.length() != (*tlter).length())
	{
		cout << "No" << endl;
		return;
	}
	
	list<char> input_lis,res_lis;

	for (int i = 0; i < r_str.length(); ++i)
	{
		res_lis.push_back(r_str[i]);
		input_lis.push_back((*tlter)[i]);
	}
	res_lis.sort();
	input_lis.sort();

	list<char>::iterator rlter = res_lis.begin();
	list<char>::iterator ilter = input_lis.begin();
	while (rlter != res_lis.end())
	{
		if (*rlter != *ilter)
		{
			cout << "No" << endl;
			return;
		}
		rlter++;
		ilter++;
	}

	cout << "Yes"<< endl;
}

int main(void)
{
	int loop;
	string temp;

	getline(cin, temp);
	loop = stoi(temp);

	while(loop--)
	{
		call_process();
	}

#if defined _debugging_
	while (1);
#endif

	return 0;
}