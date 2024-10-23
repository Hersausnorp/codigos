#include<iostream>
#include<conio.h>
using namespace std;

struct Fabrica{
	char nombre[14];
	float hora_aus;
	int tornillos_def;
	int tornillos_prod;
	int grado;
}trab[100];

int n;

void datos();
void grados();
int condicion(int);

int main()
{
	cout<<"Digite el numero de trabajadores: ";
	cin>>n;
	cout<<"\n";
	
	datos();
	grados();
	
	return 0;
}

void datos()
{
	for(int i=0; i<n; i++)
	{
		cout<<"Nombre del empleado: ";
		cin>>trab[i].nombre;
		cout<<"Horas de ausencia: ";
		cin>>trab[i].hora_aus;
		cout<<"Tornillos producidos: ";
		cin>>trab[i].tornillos_prod;
		cout<<"Tornillos defectuosos: ";
		cin>>trab[i].tornillos_def;
		cout<<"\n";
	}
	
}

void grados()
{
	for(int i=0; i<n; i++)
	{
		trab[i].grado = condicion(i);
		cout<<trab[i].nombre<<endl<<"Grado "<<trab[i].grado<<endl;
	}
	
}

int condicion(int i)
{
	int res=0;
	
	if(trab[i].hora_aus <= 3.5)
	{
		res += 7;
	}
		
	if(trab[i].tornillos_prod > 10000)
	{
		res += 8;
	}
	
	if(trab[i].tornillos_def < 300)
	{
		res += 9;
	}
	
	if(res == 0)
	{
		return 5;
	}
	
	if(res <= 9)
	{
		return res;
	}
	
	if(res == 15)
	{
		return 12;
	}
	
	if(res == 16)
	{
		return 13;
	}
	
	if(res == 17)
	{
		return 15;
	}
	
	if(res > 20)
	{
		return 20;
	}	
	
}
