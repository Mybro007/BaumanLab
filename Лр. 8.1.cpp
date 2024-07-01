#include<iostream>

char* CreateBuff(int bufferSize)
{
	char* buffer = new char[bufferSize]{};
	std::cout << "Input a line: ";
	std::cin.getline(buffer, bufferSize);
	buffer[bufferSize - 1] = '\0';
	return buffer;
}

char* InitialLine(char* buffer, int bufferSize, int& firstsize)
{
	int linesize = 0;
	int counter = 0;
	while (!((buffer[counter] == '\0') || (buffer[counter] == 0 && buffer[counter + 1] == 0)))
	{
		++linesize;
		++counter;
	}
	++linesize;
	char* initialline = new char[linesize]{};
	for (int i = 0; i < linesize - 1; ++i)
	{
		initialline[i] = buffer[i];
	}
	initialline[linesize - 1] = '\0';
	delete[] buffer;
	buffer = nullptr;
	firstsize = linesize;
	return initialline;
}

char* Changer(char* initialline, int &firstsize, int &secondsize)
{
	for (int i = 0; i < firstsize-1; ++i)
	{
		//пробелы в начале строки
		if (i == 0 && initialline[i] == ' ')
		{
			int counter = i;
			while (initialline[counter] == ' ')
			{
				++counter;
			}
			for (int j = i + 1; j < firstsize; ++j)
			{
				initialline[j] = initialline[counter];
				++counter;
			}
		}

		//несколько пробелов
		if (i < firstsize - 2 && (initialline[i] == ' ' && initialline[i + 1] == ' '))
		{
			int count = i+1;
			while (initialline[count] == ' ')
			{
				++count;
			}
			for (int j = i+1; j < firstsize ; ++j)
			{
				initialline[j] = initialline[count];
				++count;
			}
		}

		//пробел перед знаком препинания.
		if (i != firstsize - 2 && ((initialline[i] == '.' || initialline[i] == ',' || initialline[i] == '!' || initialline[i] == '?' || initialline[i] == '(' || initialline[i] == ')' || initialline[i] == '-') && initialline[i - 1] == ' '))
		{
			for (int j = i; j < firstsize; ++j)
			{
				initialline[j - 1] = initialline[j];
			}
		}

		//пробелы после знака препинания
		if (i < firstsize - 2 && ((initialline[i] == '.' || initialline[i] == ',' || initialline[i] == '!' || initialline[i] == '?' || initialline[i] == '(' || initialline[i] == ')' || initialline[i] == '-') && initialline[i+1]==' ' && initialline[i+2]==' '))
		{
			int j = i + 1;
			while (initialline[j] != ' ')
			{
				initialline[j] = initialline[j + 1];
				++j;
			}
		}
	}
	//пробелы в конце строки
	for (int i = firstsize - 1; i > 0; --i)
	{
		if (initialline[i] == '\0' && initialline[i - 1] == ' ')
		{
			initialline[i - 1] = initialline[i];
		}
	}

	while (initialline[secondsize] != '\0')
	{
		++secondsize;
	}
	++secondsize;
	char* changedLine = new char[secondsize];
	for (int i = 0; i < secondsize; ++i)
	{
		changedLine[i] = initialline[i];
	}

	delete[] initialline;
	initialline = nullptr;

	return changedLine;
}

void OutputLine(char* line, int size)
{
	std::cout << "|";
	for (int i = 0; i < size; ++i)
	{
		std::cout << line[i];
	}
	std::cout << "|\n";
}

int main()
{
	int bufferSize = 1024;
	int firstsize = 0;
	int secondsize = 0;
	char* buff = CreateBuff(bufferSize);
	char* initialLine = InitialLine(buff, bufferSize, firstsize);
	buff = nullptr;
	OutputLine(initialLine, firstsize);
	char* changedLine = Changer(initialLine, firstsize, secondsize);
	initialLine = nullptr;
	OutputLine(changedLine, secondsize);
	changedLine = nullptr;
	return 0;
}