#include<iostream>
#include<cmath>

int* InputMass(int const size)
{
	int* arr = new int[size];
	for (int i=0;i<size;++i)
	{
		std::cin>>arr[i];
	}
	return arr;
}

int variant0(int* arr, int const size)
{
	int max=*arr, min=*arr, index=0;
	for(int i=1;i<size;++i)
	{
		if(arr[i]>max)
		{
			max=arr[i];
			index=i;
		}
		else if(arr[i]<min)
		{
			min=arr[i];
		}
	}
	
	int sum=0;
	for(int i=index+1;i<size;++i)
	{
		if (arr[i]>(max+min)/2) sum+=arr[i];
	}
	return sum;
}

int variant1(int* arr, int const size)
{
	int max=*arr, indexMax=0, indexZero=-1;
	for(int i=size-1;i>=0;--i)
	{
		if(arr[i]==0)
		{
			indexZero=i;
			break;
		}
	}
	if(indexZero==-1) return -1;  //the input error
	for(int i=0;i<size;++i)
	{
		if(arr[i]>max)
		{
			max=arr[i];
			indexMax=i;
		}
	}

	int sum=0;
	for(int i=indexMax;i<=indexZero;++i)
	{
		sum+=arr[i];
	}
	return static_cast<float>(sum)/static_cast<float>(abs(indexZero-indexMax+1));
}

int variant2(int* arr, int const size)
{
	int min=*arr, indexMin=0;
	for(int i=0;i<size;i++)
	{
		if(arr[i]<min)
		{
			min=arr[i];
			indexMin=i;
		}
	}
	
	int multiplication=1;
	for(int i=0;i<indexMin;++i)
	{
		if(arr[i]<2*min)
		{
			multiplication*=arr[i];
		}
	}
	return multiplication;
}

void cleaning(int* arr)
{
	delete[] arr;
}

int main()
{
	int size;
	std::cout<<"Input the amount of numbers: ";
	std::cin>>size;
	std::cout<<"Input the sequence: ";
	int* massive = InputMass(size);
	std::cout<<"The answer for variant 0: "<<variant0(massive, size)<<"\n";
	std::cout<<"The answer for variant 1: "<<variant1(massive, size)<<"\n";
	std::cout<<"The answer for variant 2: "<<variant2(massive, size)<<"\n";
	cleaning(massive);
	return 0;
}
