#include<iostream>
using namespace std;

void productoria();

int main()
{
	productoria();
	
	return 0;
}

void productoria()
{
	double n, prod=1;
	
	cout<<"Ingrese N: ";
	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
		prod*=i;
	}
	
	cout<<"La productoria es: "<<prod<<endl;
	
}
