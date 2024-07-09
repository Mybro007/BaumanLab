#include<iostream>
#include<string>

class Person
{
	public:
		Person(std::string fio)
		{
			parcer(fio);
		}
	private:
		std::string name;
		std::string surname;
		std::string patronimic;
	public:
		std::string get_fullname()
		{
			return name + ' ' + surname + ' ' + patronimic;
		}

		void parcer(std::string fio)
		{
			int i = 0;
			while (fio[i] != ' ')
			{
				++i;
			}
			name = fio.substr(0, i);
			int j = i + 1;
			while (fio[j] != ' ')
			{
				++j;
			}
			patronimic = fio.substr(i + 1, j - 1 - i);
			surname = fio.substr(j + 1, fio.length() - j - 1);
		}

		void changer(std::string suf1, std::string suf2)
		{
			int pos;
			pos = surname.find(suf1);
			if (suf1.length() == suf2.length())
			{
				int n = 0;
				for (int i = pos; i < pos + suf2.length(); ++i)
				{
					surname[i] = suf2[n];
					++n;
				}
			}
			else
			{
				std::string copy1;
				copy1 = surname.substr(0, pos);
				std::string copy2;
				copy2 = surname.substr(pos + suf1.length(), surname.length() - (pos + suf1.length()));
				surname = copy1 + suf2 + copy2;
			}
		}
};

int main()
{	
	int n;
	std::cout << "Enter the number of input strings: ";
	std::cin >> n;
	std::string* fios = new std::string[n];
	std::getline(std::cin, *fios);
	for (int i = 0; i < n; ++i)
	{
		std::cout << "Input the " << i + 1 << " string (name surname patronimic): ";
		std::getline(std::cin, fios[i]);
	}
	std::string suf1;
	std::string suf2;
	std::cout << "Input the suffix you want to change: (for example: 'ov', 'idze', 'chuk', 'ko'): ";
	std::cin >> suf1;
	std::cout << "Input the suffix you want to replace with: (for example: 'ov', 'idze', 'chuk', 'ko'): ";
	std::cin >> suf2;
	for (int i = 0; i < n; ++i)
	{
		Person* person = new Person(fios[i]);
		std::cout << "Initial full name: " << person->get_fullname() << "\n";
		person->changer(suf1, suf2);
		std::cout << "Changed full name: " << person->get_fullname() << "\n\n\n";
	}
	return 0;
}