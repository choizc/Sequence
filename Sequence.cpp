#include"Sequence.h"
#include<fstream>
#include<string>
#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<string.h>
#define MAXCHAR  1500000

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
	clock_t st = clock();

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

	clock_t ed = clock();
	cout << double (ed - st) / CLOCKS_PER_SEC << endl;

	return longest1;
}

//A way searched from Baidu named 后缀数组
int comlen(char *p, char *q)
{
	int i = 0;
	while (p[i] == q[i++]);
	return --i;
}
int pstrcmp(const void *p1, const void *p2)
{
	return strcmp(*(char* const *)p1, *(char* const*)p2);
}

char c[MAXCHAR], *a[MAXCHAR];

string Sequence::longestRepeated()
{
	clock_t st = clock();

	int nlength = count.length();
	int maxlen = 0, maxi = 0;

	for (int i = 0; i < count.length(); ++i)
	{
		a[i] = &c[i];
		c[i] = count[i];
	}
	c[nlength] = 0;
	qsort(a, nlength, sizeof(char*), pstrcmp);
	for (int i = 0;i<nlength-1;++i)
	{
		int temp = comlen(a[i], a[i + 1]);
		if (temp > maxlen)
		{
			maxlen = temp;
			maxi = i;
		}
	}
	string result;
	result.assign(a[maxi], maxlen);

	clock_t ed = clock();
	cout << double(ed - st) / CLOCKS_PER_SEC << endl;

	return result;
}


