#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

struct estadistica{
	long codigo;
	int edad;
	int sexo;
	int carrera;
}est[100];

int n;

void datos();
void prom_edad();
void n_est();
void p_hombres();
void p_mujeres_industrial();


int main()
{
	datos();
	n_est();
	prom_edad();
	p_hombres();
	p_mujeres_industrial();
	
	return 0;	
}

void datos()
{
	cout<<"Numero de estudiantes: ";
	cin>>n;
	cout<<"\n";
	
	for(int i=0; i<n; i++)
	{
		cout<<i+1<<". Codigo del estudiante: ";
		cin>>est[i].codigo;
		cout<<"Edad del estudiante: ";
		cin>>est[i].edad;
		
		do{
			cout<<"Sexo 1. Masculino | 2. Femenino: ";
			cin>>est[i].sexo;
			if(est[i].sexo < 1 || est[i].sexo > 2)
			{
				cout<<"\nERROR"<<endl;
			}
		}while(est[i].sexo < 1 || est[i].sexo > 2);
		
		do{
			cout<<"\nCarrera \n1. Ing industrial \n2. Ing electrica \n3. Ing mecanica \n4. Ing electronica \n5. Ing de sistemas \n6 Tecnologia de sistemas";
			cout<<"\n\nOpcion: ";
			cin>>est[i].carrera;	
		}while(est[i].carrera < 1 || est[i].carrera > 6);
		
		getch();
		system("cls");
	}
}

void n_est()
{
	int ind=0, elec=0, mec=0, elect=0, sist=0, tec_sis=0;
	
	for(int i=0; i<n; i++)
	{
		if(est[i].carrera == 1)
		{
			ind++;
		}
		else if(est[i].carrera == 2)
		{
			elec++;
		}
		else if(est[i].carrera == 3)
		{
			mec++;
		}
		else if(est[i].carrera == 4)
		{
			elect++;
		}
		else if(est[i].carrera == 5)
		{
			sist++;
		}
		else
		{
			tec_sis++;
		}
	}
	
	cout<<"\nEstudiantes en cada carrera "<<endl<<endl;
	cout<<"1. Ing industrial: "<<ind<<endl;
	cout<<"2. Ing electrica: "<<elec<<endl;
	cout<<"3. Ing mecanica: "<<mec<<endl;
	cout<<"4. Ing electronica: "<<elect<<endl;
	cout<<"5. Ing de sistemas: "<<sist<<endl;
	cout<<"6. Tecnologia de sistemas: "<<tec_sis<<endl;	
}

void prom_edad()
{
	float prom=0;
	
	for(int i=0; i<n; i++)
	{
		prom += est[i].edad;
	}
	
	prom /= n;
	
	cout<<"\nPromedio de edad: "<<prom<<endl;
}

void p_hombres()
{
	float h=0, m=0, porcentaje=0;
	
	for(int i=0; i<n; i++)
	{
		if(est[i].sexo == 1)
		{
			h++;
		}
		else
		{
			m++;
		}
	}
	
	porcentaje = (h * 100) / n;
	
	cout<<"Porcentaje de hombres: "<<porcentaje<<"% "<<endl;
	
}

void p_mujeres_industrial()
{
	float h=0, m=0, porc=0, ind=0;
	
	for(int i=0; i<n; i++)
	{
		if(est[i].carrera == 1)
		{
			ind++;
			if(est[i].sexo == 1)
			{
				h++;
			}
			else
			{
				m++;
			}
		}
	}
	
	porc = (m * 100) / ind;

	cout<<"Porcentaje de mujeres en Ing industrial: "<<porc<<"% "<<endl;
	
}
