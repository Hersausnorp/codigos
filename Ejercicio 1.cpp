#include<iostream>
using namespace std;

void mcd();

int main()
{
	mcd();
	
	return 0;
}

void mcd()
{
	int n1, n2, mcd=0, a=0;
	
	cout<<"Ingrese un numero: ";cin>>n1;
	cout<<"Ingrese otro numero: ";cin>>n2;
	
	if(n1 > 0 and n2 > 0)
	{
		do{
			a = n1 % n2;
			
			if(a != 0)
			{
				n1 = n2;
				n2 = a;
			}
			else
			{
				mcd = n2;
			}
		}while(a != 0);
	}
	else
	{
		cout<<"INGRESA NUMEROS MAYORES A 0.";
	}
	
	cout<<"'\nEl Maximo comun divisor de los numeros es: "<<mcd<<endl;
	
}
