#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

struct estudiante{
	long codigo;
	char nombre[10];
	char seg_nombre[10];
	char seg_apellido[15];
	char apellido[15];
	char carrera[30];
	int semestre;
	char asig[20];
	char asig1[20];
	char asig2[20];
	char asig3[20];
	char asig4[20];
	float nota;
	float nota1;
	float nota2;
	float nota3;
	float nota4;
	float prom;
}est[100];

int n;

void datos_estudiante();
void notas();
void mayor_p();

int main()
{	
	datos_estudiante();
	notas ();
	mayor_p();
	
	return 0;
}

void datos_estudiante()
{
	cout<<"Digite numero de estudiantes: ";
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cout<<"\n"<<i+1<<". Codigo de estudiante: ";
		cin>>est[i].codigo;
		cout<<"Nombre: ";
		cin>>est[i].nombre;
		cout<<"Segundo nombre: ";
		cin>>est[i].seg_nombre;
		cout<<"Apellido: ";
		cin>>est[i].apellido;
		cout<<"Segundo apellido: ";
		cin>>est[i].seg_apellido;
		cout<<"Carrera: ";
		cin>>est[i].carrera;
		cout<<"Semestre: ";
		cin>>est[i].semestre;
	}
	
}

void notas()
{
	cout<<"\n";
	
	for(int i=0; i<n; i++)
	{
		cout<<est[i].nombre<<" "<<est[i].seg_nombre<<" "<<est[i].apellido<<" "<<est[i].seg_apellido<<endl;
			
		cout<<"Asignatura 1: ";
		cin>>est[i].asig;	
		do{
			cout<<"Nota definitiva de "<<est[i].asig<<": ";
			cin>>est[i].nota;
			if(est[i].nota < 0 || est[i].nota > 5)
			{
				cout<<"\nCOLOQUE UNA NOTA ENTRE 0 A 5"<<endl<<endl;
			}
		}while(est[i].nota < 0 || est[i].nota > 5);
		
		
		cout<<"\nAsignatura 2: ";	
		cin>>est[i].asig1;
		do{
			cout<<"Nota definitiva de "<<est[i].asig1<<": ";
			cin>>est[i].nota1;
			if(est[i].nota1 < 0 || est[i].nota1 > 5)
			{
				cout<<"\nCOLOQUE UNA NOTA ENTRE 0 A 5"<<endl<<endl;
			}
		}while(est[i].nota1 < 0 || est[i].nota1 > 5);
		
		cout<<"\nAsignatura 3: ";
		cin>>est[i].asig2;
		do{
			cout<<"Nota definitiva de "<<est[i].asig2<<": ";
			cin>>est[i].nota2;
			if(est[i].nota2 < 0 || est[i].nota2 > 5)
			{
				cout<<"\nCOLOQUE UNA NOTA ENTRE 0 A 5"<<endl<<endl;
			}
		}while(est[i].nota2 < 0 || est[i].nota2 > 5);
		
		cout<<"\nAsignatura 4: ";
		cin>>est[i].asig3;
		do{
			cout<<"Nota definitiva de "<<est[i].asig3<<": ";
			cin>>est[i].nota3;
			if(est[i].nota3 < 0 || est[i].nota3 > 5)
			{
				cout<<"\nCOLOQUE UNA NOTA ENTRE 0 A 5"<<endl<<endl;
			}
		}while(est[i].nota3 < 0 || est[i].nota3 > 5);
		
		cout<<"\nAsignatura 5: ";
		cin>>est[i].asig4;
		do{
			cout<<"Nota definitiva de "<<est[i].asig4<<": ";
			cin>>est[i].nota4;
			if(est[i].nota4 < 0 || est[i].nota4 > 5)
			{
				cout<<"\nCOLOQUE UNA NOTA ENTRE 0 A 5"<<endl<<endl;
			}
		}while(est[i].nota4 < 0 || est[i].nota4 > 5);
		
		est[i].prom = (est[i].nota + est[i].nota1 + est[i].nota2 + est[i].nota3 + est[i].nota4) / 5;
		
		cout<<"\nPromedio del semestre: "<<est[i].prom;
		cout<<"\nPresione una tecla para continuar";
		
		getch();
		system("cls");
	}
		
}

void mayor_p()
{
	long Codigo=0;
	int Semestre=0;
	float mayor=0;
	char Nombre[10], Apellido[15], Carrera[30], s_nombre[10], s_apellido[15];
	
	for(int i=0; i<n; i++)
	{
		if(mayor < est[i].prom)
		{
			mayor = est[i].prom;
			strcpy(Nombre, est[i].nombre);
			strcpy(Apellido, est[i].apellido);
			strcpy(Carrera, est[i].carrera);
			Codigo = est[i].codigo;
			Semestre = est[i].semestre;
			strcpy(s_nombre, est[i].seg_nombre);
			strcpy(s_apellido, est[i].seg_apellido);
		}
	}
	
	cout<<"Estudiante con el mayor promedio"<<endl;
	cout<<Codigo<<endl;
	cout<<Nombre<<" "<<s_nombre<<" "<<Apellido<<" "<<s_apellido<<endl;
	cout<<Carrera<<endl;
	cout<<"Semestre: "<<Semestre<<endl;
	cout<<"Promedio: "<<mayor<<endl;
	
}
