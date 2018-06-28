#include "Sequence.h"
#include<fstream>
#include<string>
#include<iostream>
#include <ctime>
Sequence::Sequence()
{
}

Sequence::Sequence(string filename)
{
	fstream file(filename.c_str(), ios::in);
	while (!file)
	{
		cerr << "File could not be opened." << endl;
	}
	string a;
	while (file >> a)
	{
		count += a;
	}
}

Sequence::~Sequence()
{
}

int Sequence::length()
{
	int n = 0;
	return n = count.length();
}

int Sequence::numberOf(char base)
{
	int num = 0;
	for (int i = 0; i < count.length(); ++i)
	{
		if (count[i] == base)
		{
			num++;
		}
	}
	return num;
}

string Sequence::longestConsecutive()
{
	clock_t st=clock();
	string longest1, longest2;
	string temp = count;
	char a = count[0];
	longest1 = a;
	for (int i = 0; i < count.length()+1; i++)
	{
		if (longest2.length()>longest1.length())
		{
			longest1 = longest2;
		}

		if (a == count[i])
		{
			longest2 = longest2 + count[i];
		}
		else
		{
			a = count[i];
			longest2 = count[i];
		}
	}
	clock_t ed=clock();
	cout<<double (ed-st) / CLOCKS_PER_SEC<<endl;

	return longest1;
}

string Sequence::longestRepeated()
{
	return string();
}


