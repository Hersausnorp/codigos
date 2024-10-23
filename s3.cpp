 #include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

struct empleado{
	char nombre[10];
	char apellido[15];
	float sal_h;
	int horas;
	int horas_extras;
	double sal_neto;
	double fuente;
}emp[100];

int n;

void datos();
void nombre();
void salario_neto();
void retencion_fuente();
void sal_prom();
void total_hx();
void nomina();
void pago_hx();
void rec_fuente();

int main()
{
	datos();
	salario_neto();
	retencion_fuente();
	nombre();
	sal_prom();
	total_hx();
	pago_hx();
	rec_fuente();
	
	return 0;
}

void datos()
{
	cout<<"Numero de empleados: ";
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cout<<"Nombre: ";
		cin>>emp[i].nombre;
		cout<<"Apellido: ";
		cin>>emp[i].apellido;
		cout<<"Salario basico por hora: ";
		cin>>emp[i].sal_h;
		
		cout<<"Horas ordinarias trabajadas [1 a 40]: ";
		cin>>emp[i].horas;
		if(emp[i].horas >= 40)
		{
			emp[i].horas_extras = emp[i].horas - 40;
			emp[i].horas -= emp[i].horas_extras;
		}
		
		getch();
		system("cls");
	}
}

void nombre()
{
	for(int i=0; i<n; i++)
	{
		cout<<emp[i].nombre<<" "<<emp[i].apellido<<endl;	
		cout<<"Salario neto: $"<<emp[i].sal_neto<<endl;
		cout<<"Valor de la retencion en la fuente: $"<<emp[i].fuente<<endl<<endl;
	}
}

void salario_neto()
{
	double sal_h=0, sal_extra=0;

	
	for(int i=0; i<n; i++)
	{
		sal_h = emp[i].sal_h * emp[i].horas;
		sal_extra = (emp[i].sal_h * 0.40) * emp[i].horas_extras;
		emp[i].sal_neto = sal_h + sal_extra; 
	}
}

void retencion_fuente()
{
	double fuente=0, sal_extra;
	
	for(int i=0; i<n; i++)
	{
		sal_extra = (emp[i].sal_h * 0.40) * emp[i].horas_extras;
		
		if(sal_extra > 100000)
		{
			emp[i].fuente = sal_extra * 0.10;
			emp[i].sal_neto -= emp[i].fuente;
		}
	}	
}

void sal_prom()
{
	float prom=0;
	
	for(int i=0; i<n; i++)
	{
		prom += emp[i].sal_neto;
	}
	
	prom /= n;
	
	cout<<"Datos de la empresa"<<endl<<endl;
	nomina();
	cout<<"Salario promedio de los trabajadores: $"<<prom<<endl;
}

void total_hx()
{
	int total=0;
	
	for(int i=0; i<n; i++)
	{
		total += emp[i].horas_extras;
	}
	
	cout<<"Total horas extras laboradas en la empresa: "<<total<<endl;
}

void nomina()
{
	double total=0;
	
	for(int i=0; i<n; i++)
	{
		total += emp[i].sal_neto;
	}
	
	cout<<"Valor total de la nomina: $"<<total<<endl;
}

void pago_hx()
{
	double sal_extra=0;
	
	for(int i=0; i<n; i++)
	{
		sal_extra = (emp[i].sal_h * 0.40) * emp[i].horas_extras;
		
		sal_extra += sal_extra;
	}
	
	cout<<"Total a pagar por concepto de horas extras: $"<<sal_extra<<endl;	
}

void rec_fuente()
{
	double fuente=0;
	
	for(int i=0; i<n; i++)
	{
		fuente += emp[i].fuente;
	}
	
	cout<<"Total recaudado por retencion en la fuente: "<<fuente<<endl;
}
