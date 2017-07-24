#include "Set.h"

sett::sett(char * s)
{
	size = strlen(s);
	str = new char[size + 1];
	strcpy(str, s);
	for (int i(0); i < size; i++)
	{
		for (int j(0); j < size; j++)
		{
			if (str[i] == str[j] && i != j)
			{
				for (int k(j); k <= size; k++)
					str[k] = str[k + 1];
				size--;

			}
		}

	}
	for (int i = size - 1; i>0; i--)
	{
		for (int j = 0; j<i; j++)
		{
			if (str[j] > str[j + 1])

				swap(str[j], str[j + 1]);
		}
	}
	for (int i(0); i < size; i++)
	{
		for (int j(0); j < size; j++)
		{
			if (str[i] == str[j] && i != j)
			{
				for (int k(j); k <= size; k++)
					str[k] = str[k + 1];
				size--;

			}
		}

	}
	for (int i = size - 1; i>0; i--)
	{
		for (int j = 0; j<i; j++)
		{
			if (str[j] > str[j + 1])

				swap(str[j], str[j + 1]);
		}
	}
}

sett::sett(int size_t)
{
	size = size_t;
	str = new char[size + 1];
}

sett::sett()
{
	size = 255;
	str = new char[size + 1];
}

sett::sett(sett &a)
{
	size = a.size;
	str = new char[size + 1];
	str[0] = 0;
	strcpy(str, a.str);
}

sett::~sett()
{
	
	delete[] str;
}
int sett::getsize()
{
	return size;
}

char * sett::getstr()
{
	return str;
}

sett & sett::operator=(const sett &s)
{
	if (this == &s) return *this;
	size = s.size;
	delete[]str;
	str = new char[size + 1];
	strcpy(str, s.str);
	return *this;

}
sett & sett::operator=(const char* s)//sort your string s;
{
	
	if (strcmp(str,s)==0) return *this;
	size = strlen(s);
	delete[]str;
	str = new char[size + 1];
	strcpy(str, s);
	str[size + 1] = 0;
	for (int i(0); i < size; i++)
	{
		for (int j(0); j < size; j++)
		{
			if (str[i] == str[j] && i != j)
			{
				for (int k(j); k <= size; k++)
					str[k] = str[k + 1];
				size--;

			}
		}

	}
	for (int i = size - 1; i>0; i--)
	{
		for (int j = 0; j<i; j++)
		{
			if (str[j] > str[j + 1])

				swap(str[j], str[j + 1]);
		}
	}
	for (int i(0); i < size; i++)
	{
		for (int j(0); j < size; j++)
		{
			if (str[i] == str[j] && i != j)
			{
				for (int k(j); k <= size; k++)
					str[k] = str[k + 1];
				size--;

			}
		}

	}
	for (int i = size - 1; i>0; i--)
	{
		for (int j = 0; j<i; j++)
		{
			if (str[j] > str[j + 1])

				swap(str[j], str[j + 1]);
		}
	}
	return *this;

}

sett sett::operator*(sett &a)
{
	sett s;

	int b = 0;

	int i = 0;
	for (i; i <= size; i++)
	{
		int count = 0;
		for (int j(0); j <= a.size; j++)
		{
			if (str[i] == a.str[j])count++;
		}
		if (count)
		{
			s.str[b++] = str[i];
			s.str[b] = 0;
		}
	}
	s.size = b;
	
	return s;
}

sett sett::operator+(sett &a)
{
	sett s;
	strcpy(s.str, this->str);
	strcat(s.str, a.str);
	s.size = strlen(s.str);
	for (int i(0); i < s.size; i++)
	{
		for (int j(0); j < s.size; j++)
		{
			if (s.str[i] == s.str[j] && i != j)
			{
				for (int k(j); k <= s.size; k++)
					s.str[k] = s.str[k + 1];
				s.size--;

			}
		}

	}
	for (int i = s.size - 1; i>0; i--)
	{
		for (int j = 0; j<i; j++)
		{
			if (s.str[j] > s.str[j + 1])

				swap(s.str[j], s.str[j + 1]);
		}
	}


	/*int x = size;
	for (int i(0); i < a.size; i++)
	{
		int count = 0;
		for (int j(0); j < size; j++)
		{
			if (a.str[i] == str[j])count++;
		}
		if (count == 0)
		{
			s.str[x + 1] = a.str[i];
			x++;
		}
		
	}
	s.str[x + 1] = 0;
	s.size = x;*/
	return s;
}

sett  sett::operator-(const sett&a)
{
	char*s;
	s = new char[20];
	strcpy(s, this->str);
		
	for (int i(0); i < strlen(s); i++)
	{
		for (int j(0); j < a.size; j++)
		{
			if (s[i] == a.str[j])
			{
				int k = i;
				for ( k; k <= strlen(s); k++)				
					s[k] = s[k + 1];
				s[k+1]=0;
								
			}
		}
	}
	

	return sett(s);
}

bool  sett::operator<(sett &a)
{
	int count = 0;
	for (int i(0); i < size; i++)
	{
		for (int j(0); j <a.size; j++)
		{
			if (str[i] == a.str[j]) count++;;
		}
	}
	if (count == size) return true;
	else return false;
}

bool  sett::operator==(sett &s)
{
	if (strcmp(str, s.str) == 0) return true;
	else return false;
}

ostream & operator<<(ostream & print, sett & s)
{
	print << s.str << endl;
	return print;
}

istream & operator >> (istream & read, sett & s)
{
	cin >> s.str;
	s.size = strlen(s.str);
	s.str[s.size + 1] = 0;
	for (int i(0); i < s.size; i++)
	{
		for (int j(0); j < s.size; j++)
		{
			if (s.str[i] == s.str[j] && i != j)
			{
				for (int k(j); k<=s.size; k++)
					s.str[k] = s.str[k + 1];
				s.size--;

			}
		}

	}
	for (int i = s.size - 1; i>0; i--)
	{
		for (int j = 0; j<i; j++)
		{
			if (s.str[j] > s.str[j + 1])

				swap(s.str[j], s.str[j + 1]);
		}
	}
	for (int i(0); i < s.size; i++)
	{
		for (int j(0); j < s.size; j++)
		{
			if (s.str[i] == s.str[j] && i != j)
			{
				for (int k(j); k <= s.size; k++)
					s.str[k] = s.str[k + 1];
				s.size--;

			}
		}

	}
	for (int i = s.size - 1; i>0; i--)
	{
		for (int j = 0; j<i; j++)
		{
			if (s.str[j] > s.str[j + 1])

				swap(s.str[j], s.str[j + 1]);
		}
	}


	return read;
}


