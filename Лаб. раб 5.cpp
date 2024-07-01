#include<iostream>

int* InputMass(int const Size)
{
	int* Mass = new int[Size];
	std::cout<<"Input the sequence: ";
	for(int i=0;i<Size;++i)
	{
		std::cin>>Mass[i];
	}
	return Mass;
}

void FirstOutput(int* Mass, int const Size)
{
	std::cout<<"Your sequence: ";
	for(int i=0;i<Size;++i)
	{
		std::cout<<Mass[i]<<" ";
	}
	std::cout<<"\n\n";
}

void Variant0(int* Mass, int const Size)
{
	int PositiveCount=0;
	int ZeroCount=Size-1;
	
	for(int i=0;i<Size;++i)
	{
		if (Mass[i]>0)
		{
			std::swap(Mass[i], Mass[PositiveCount]);
			++PositiveCount;
		}
		else if(Mass[i]==0)
		{
			std::swap(Mass[i], Mass[ZeroCount]);
			--ZeroCount;
		}
	}
	std::cout<<PositiveCount<<"\n";
	for(int i=0;i<PositiveCount;++i)
	{
		for(int j=0;j<PositiveCount-1;++j)
		{
			if(Mass[j]>Mass[j+1])
			{
				std::swap(Mass[i], Mass[j]);
			}
		}
	}
}

void SecondOutput(int* Mass, int const Size)
{
	std::cout<<"Sorted sequence: ";
	for(int i=0;i<Size;++i)
	{
		std::cout<<Mass[i]<<" ";
	}
}

void Cleaning(int* Mass)
{
	delete[] Mass;
}

int main()
{
	int Size;
	std::cout<<"Input the size of sequence: ";
	std::cin>>Size;
	int* Mass = InputMass(Size);
	FirstOutput(Mass, Size);
	Variant0(Mass, Size);
	SecondOutput(Mass, Size);
	Cleaning(Mass);
	return 0;
}
