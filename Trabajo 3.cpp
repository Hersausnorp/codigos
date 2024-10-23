
#define color SetConsoleTextAttribute
//	black = 0,
//	dark_blue = 1,
//	dark_green = 2,
//	dark_aqua,dark_cyan = 3,
//	dark_red = 4,
//	dark_purple = 5,dark_pink = 5,dark_magenta = 5,
//	dark_yellow = 6,
//	dark_white = 7,
//	gray = 8,
//	blue = 9,
//	green = 10,
//	aqua = 11 ,cyan = 11,
//	red = 12,
//	purple = 13,
//	pink = 13;
// magenta = 13;
//	yellow = 14,
//	white = 15
#include<iostream>
#include<iomanip>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<cstdlib>
#include<windows.h>
#include <locale.h> 

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

struct Cargos{
	
	long id_cargo; //Para Validar
	char nombre_cargo[50];
	float sueldo;
	
};

struct Bancos{
	
	long id_banco; //Para Validar
	char nombre_banco[50];
	
};

struct Empleados{
	
	long id_empleado;
	char apellidos[60];
	char nombre[40];
	char sexo;
	
	long id_cargo; //Asignacion si existe
	long id_banco; //Asignacion si existe
	
	char tipo_cuenta[40];
	char num_cuenta[40];
	
};

//FUNCIONES MAIN
void menu();

void registro_cargo();
void registro_banco();
void registro_empleado();

void consulta();

void reporte();

//Adicionales VALIDACIONES


bool validar_cargo(long);
bool validar_banco(long);
bool validar_empleado(long);

long long sueldo_cargo(long);
string nombre_banco(long);
string nombre_cargo(long);

//EXTRA

void UpperCase(char*);
bool validar_creacion_archivos();
bool validar_creacion_empleado();

//MAIN

int main(){
	
	setlocale(LC_ALL,"spanish");
	menu();
	
	return 1-1;
}

//MENU

void menu(){
	
	int op;
	
	do{
		system("cls");
		color(console,14);
		cout<<"\n\t MENU PRINCIPAL\n ";
		cout<<"\n 1. ";color(console,7);
		cout<<"Registro de Cargos.";color(console,14);
		cout<<"\n 2. ";color(console,7);
		cout<<"Registro de Bancos.";color(console,14);
		cout<<"\n 3. ";color(console,7);
		cout<<"Registro de Empleados.";color(console,14);
		cout<<"\n 4. ";color(console,7);
		cout<<"Consulta de un empleado.";color(console,14);
		cout<<"\n 5. ";color(console,7);
		cout<<"Reporte general";color(console,14);
		cout<<"\n 6. ";color(console,12);
		cout<<"Salir del programa";
		color(console,7);
		
		cout<<"\n\n -> ";color(console,11);
		cin>>op;
		color(console,7);
		
		switch(op){
			
			case 1:	
				registro_cargo();
				break;
			case 2:	
				registro_banco();
				break;
			case 3: 
				registro_empleado();
				break;	
			case 4:	
				consulta();
				break;
			case 5:	
				reporte();
				break;
			case 6:	//Salir.
				break;
			
			default:
				
				color(console,12);
				cout<<"\n Error: seleccion no valida.";
				color(console,7);
				cout<<"\n [OK] Continuar presiona cualquier tecla";
				
				break;	
			
		}
		
	}while(op != 6);
	
	color(console,12);
	cout<<"\n Programa Finalizado con Exito.";
	color(console,7);
	
}


//EXTRA FUNCION

void UpperCase(char *texto){
	
	for(int x = 0; x < strlen(texto); x++){
		
		texto[x] = toupper(texto[x]);	
		
	}
	
}


bool validar_creacion_archivos(){
	
	bool resp = true;
	string texto;
	//Cargo
	
	texto = "\n Faltan requerimientos como: ";	
	
	ifstream bin_cargo("Cargos.txt", ios::in | ios::binary);
	
	if(bin_cargo.fail()){
		
		texto += "\n Aun no se ha creado un archivo \"CARGOS\" ";
		
		resp = false;
		
	}
	bin_cargo.close();
	
	//Banco
	
	fstream bin_banco("Bancos.txt", ios::in | ios::binary);
	
	if(bin_banco.fail()){
		
		texto += "\n Aun no se ha creado un archivo \"BANCOS\" ";
		
		resp = false;
		
	}
	bin_banco.close();
	
	if(resp == false){
		color(console,12);
		cout<<texto;
		color(console,7);
	}
	
	return resp;
	
}


//VALIDACIONES

bool validar_cargo(long id_cargo){
	
	ifstream bin("Cargos.txt",ios::in | ios::binary);
	
	if(bin.fail()){
	//	cout<<"\n [Error al abrir \"Cargo.txt\" ]";	
		bin.close();
		return false;
		
	}
	
	Cargos aux;
	
	bin.read(reinterpret_cast<char*> (&aux), sizeof(Cargos));
	
	while(!bin.eof()){
		
		if(aux.id_cargo == id_cargo){

			return true;
		}
		
		bin.read(reinterpret_cast<char*> (&aux), sizeof(Cargos));
		
	}
	
	bin.close();
	
	return false;
	
}

bool validar_banco(long id_banco){
	
	ifstream bin("Bancos.txt",ios::in | ios::binary);
	
	if(bin.fail()){
	//	cout<<"\n [Error al abrir \"Bancos.txt\" ]";	
		return false;
	}
	
	Bancos aux;
	
	bin.read(reinterpret_cast<char*> (&aux), sizeof(Bancos));
	
	while(!bin.eof()){
		
		if(aux.id_banco == id_banco){
			
			return true;
		}
		
		bin.read(reinterpret_cast<char*> (&aux), sizeof(Bancos));
		
	}
	
	bin.close();
	
	return false;
	
}

bool validar_empleado(long id_empleado){
	
	ifstream bin("Empleados.txt",ios::in | ios::binary);
	
	if(bin.fail()){
	//	cout<<"\n [Error al abrir \"Empleados.txt\" ]";	
		bin.close();
		return false;
	}
	
	Empleados aux;
	
	bin.read(reinterpret_cast<char*> (&aux), sizeof(Empleados));
	
	while(!bin.eof()){
		
		if(aux.id_empleado == id_empleado){
			
			return true;
		}
		
		bin.read(reinterpret_cast<char*> (&aux), sizeof(Empleados));
		
	}
	
	bin.close();
	
	return false;
	
}

bool validar_creacion_empleado(){
	
	ifstream bin("Empleados.txt", ios::in | ios::binary);
	
	if(bin.fail()){
		color(console,12);
		cout<<"\n Aun no se ha creado un archivo ";color(console,4);cout<<"\"EMPLEADOS\" ";
		cout<<"\n Ingrese empleados primero.";
		color(console,7);	
		return false;
	}
	
	bin.close();
	
	return true;
}


//FUNCIONES CLAVES DE REGISTRO

void registro_cargo(){
	
	Cargos nuevo_cargo;
	int op;
	
	do{
		system("cls");
		color(console,14);
		cout<<"\n\tREGISTRO DE CARGOS\n";
		
		cout<<"\n 1. ";color(console,7);
		cout<<"Añadir.";color(console,14);
		cout<<"\n 0. ";color(console,7);
		cout<<"Salir.";
		cout<<"\n\n -> ";color(console,11);
		cin>>op;
		color(console,7);
		
		if(op != 1 && op != 0){
			
			color(console,12);
			cout<<"\n Error: seleccion no valida.";
			color(console,7);
			cout<<"\n [OK] Continuar presiona cualquier tecla";
			getch();
			
		}else if(op == 0){
			
			return;
			
		}else{
			
			system("cls");
			color(console,14);
			cout<<"\n\tREGISTRO DE CARGOS\n";
			color(console,7);
			cout<<"\n Ingrese el ID del cargo: ";	color(console,11);
			cin>>nuevo_cargo.id_cargo;	color(console,7);
			
			if(!validar_cargo(nuevo_cargo.id_cargo)){
				
				cout<<" Nombre del cargo: ";	color(console,11);
				fflush(stdin);
				gets(nuevo_cargo.nombre_cargo);	color(console,7);
				
				cout<<" Sueldo vigente: ";	color(console,11);
				cin>>nuevo_cargo.sueldo;	color(console,7);
				
				//Añadir
				ofstream bin_add("Cargos.txt",ios::app | ios::binary);
				
				if(bin_add.fail()){
					color(console,12);
					cout<<"\n [Error al abrir ";color(console,4);
					cout<<"\"Cargos.txt\"";color(console,12);
					cout<<" como escritura]";
					color(console,7);	
				} 
				
				bin_add.write(reinterpret_cast<char*>(&nuevo_cargo),sizeof(Cargos));
				
				bin_add.close();
				
				color(console,10);
				cout<<"\n\n Cargo registrado con exito.";
				color(console,7);
				getch();
				
			}else{
				color(console,3);
				cout<<"\n Ya existe este Cargo [OK]";
				color(console,7);
				getch();
				
			}
						
		}
		
	}while(true);
	
	
}


void registro_banco(){
	
	Bancos nuevo_banco;
	int op;
	
	do{
		system("cls");
		color(console,14);
		cout<<"\n\tREGISTRO DE BANCOS\n";
		
		cout<<"\n 1. ";color(console,7);
		cout<<"Añadir.\n ";color(console,14);
		cout<<"0. ";color(console,7);
		cout<<"Salir.";
		cout<<"\n\n -> ";color(console,11);
		cin>>op;color(console,7);
		
		if(op != 1 && op != 0){
			
			color(console,12);
			cout<<"\n Error: seleccion no valida.";
			color(console,7);
			cout<<"\n [OK] Continuar presiona cualquier tecla";
			getch();
			
		}else if(op == 0){
			
			return;
			
		}else{
			
			system("cls");
			color(console,14);
			cout<<"\n\tREGISTRO DE BANCOS\n";
			color(console,7);
			cout<<"\n Ingrese el ID del banco: ";	color(console,11);
			cin>>nuevo_banco.id_banco;	color(console,7);
			
			if(!validar_banco(nuevo_banco.id_banco)){
				
				cout<<" Nombre del banco: ";	color(console,11);
				fflush(stdin);
				gets(nuevo_banco.nombre_banco);		color(console,7);
				
				//Añadir
				ofstream bin_add("Bancos.txt",ios::app | ios::binary);
				
				if(bin_add.fail()){
					
					color(console,12);
					cout<<"\n [Error al abrir ";color(console,4);
					cout<<"\"Bancos.txt\" ";color(console,12);
					cout<<"como escritura]";
					color(console,7);	
				} 
				
				bin_add.write(reinterpret_cast<char*>(&nuevo_banco),sizeof(Bancos));
				
				bin_add.close();
				
				color(console,10);
				cout<<"\n\n Banco registrado con exito.";
				color(console,7);
				getch();
				
				
			}else{
				color(console,3);
				cout<<"\n Ya existe este Banco [OK]";
				color(console,7);
				getch();
				
			}
						
		}
		
	}while(true);
	
}


void registro_empleado(){
	
	if(validar_creacion_archivos() ==  false){
		getch();
		return;
	}
	
	Empleados nuevo_empleado;
	int op;
	
	do{
		system("cls");
		color(console,14);
		cout<<"\n REGISTRO DE EMPLEADOS\n";
		
		cout<<"\n 1. ";color(console,7);
		cout<<"Añadir.\n ";color(console,14);
		cout<<"0. ";color(console,7);
		cout<<"Salir.";
		cout<<"\n\n -> ";color(console,11);
		cin>>op;color(console,7);
		
		if(op != 1 && op != 0){
			
			color(console,12);
			cout<<"\n Error: seleccion no valida.";
			color(console,7);
			cout<<"\n [OK] Continuar presiona cualquier tecla";
			getch();
			
		}else if(op == 0){
			
			return;
			
		}else{
			system("cls");
			color(console,14);
			cout<<"\n REGISTRO DE EMPLEADOS\n";
			color(console,7);
			cout<<"\n Ingrese el ID del empleado: ";color(console,11);
			cin>>nuevo_empleado.id_empleado;	color(console,7);
			
			if(!validar_empleado(nuevo_empleado.id_empleado)){
				
				cout<<" Nombre del empleado: ";	color(console,11);
				fflush(stdin);
				gets(nuevo_empleado.nombre);	color(console,7);
				
				UpperCase(nuevo_empleado.nombre);
				
				cout<<" Apellidos del empleado: ";	color(console,11);
				fflush(stdin);
				gets(nuevo_empleado.apellidos);	color(console,7);
				
				UpperCase(nuevo_empleado.apellidos);
				
				do{
					cout<<" Sexo empleado [M]asculino - [F]emenino: ";	color(console,11);
					cin>>nuevo_empleado.sexo;	color(console,7);
					
					nuevo_empleado.sexo = toupper(nuevo_empleado.sexo);
					
					if(nuevo_empleado.sexo != 'F' and nuevo_empleado.sexo != 'M'){
						color(console,12);
						cout<<"\n Error: seleccion no valida.\n\n";
						color(console,7);
						
					}else{
						break;
					}
					
				}while(true);
				
				do{
					cout<<" Ingresar ID del cargo: ";	color(console,11);
					cin>>nuevo_empleado.id_cargo;	color(console,7);
					
					if(validar_cargo(nuevo_empleado.id_cargo) == false){
						
						color(console,12);
						cout<<"\n El ID del cargo no existe.\n\n";
						color(console,7);
						
					}else{
						break;
					}
					
				}while(true);
				
				do{
					cout<<" Ingresar ID del banco: ";	color(console,11);
					cin>>nuevo_empleado.id_banco;		color(console,7);
					
					if(validar_banco(nuevo_empleado.id_banco) == false){
						
						color(console,12);
						cout<<"\n El ID del banco no existe.\n\n";
						color(console,7);
						
					}else{
						break;
					}
					
				}while(true);
					
					cout<<"\n Indique el tipo de cuenta:";color(console,14);
					cout<<"\n 1. ";color(console,7);
					cout<<"Cuenta de AHORRO";color(console,14);
					cout<<"\n 2. ";color(console,7);
					cout<<"Cuenta CORRIENTE";
				
				do{
					cout<<"\n\n -> ";	color(console,11);
					cin>>op;	color(console,7);
					
					switch(op){
						
						case 1: strcpy(nuevo_empleado.tipo_cuenta,"AHORROS");
							break;
						case 2:	strcpy(nuevo_empleado.tipo_cuenta,"CORRIENTE");
							break;
						
						default: color(console,12);
								cout<<"\n Error: Opcion no valida.";
								color(console,7);
							break;
					}
					
				}while(op =! 1 && op != 2);
				
				cout<<"\n Numero de cuenta: ";	color(console,11);
				fflush(stdin);
				gets(nuevo_empleado.num_cuenta);	color(console,7);
				
				//Añadir
				ofstream bin_add("Empleados.txt",ios::app | ios::binary);
				
				if(bin_add.fail()){
					color(console,12);
					cout<<"\n [Error al abrir ";color(console,4);
					cout<<"\"Empleados.txt\" ";color(console,12);
					cout<<"como escritura]";
					color(console,7);
				} 
				
				bin_add.write(reinterpret_cast<char*>(&nuevo_empleado),sizeof(Empleados));
				
				bin_add.close();
				
				color(console,10);
				cout<<"\n\n Empleado registrado con exito.";
				color(console,7);
				getch();
				
			}else{
				color(console,3);
				cout<<"\n Ya esta registrado este Empleado [OK]";
				color(console,7);
				getch();
				
			}
					
		}
		
	}while(true);
	
	
}

void consulta(){
	
	if(validar_creacion_empleado() == false){
		getch();
		return;
	}
	
	Empleados consulta;
	int op;
	long id_empleado;
	do{
		system("cls");
		color(console,14);
		cout<<"\n\tCONSULTA DE EMPLEADO\n";

		cout<<"\n 1.";color(console,7);
		cout<<" Consultar.";color(console,14);
		cout<<"\n 0.";color(console,7);
		cout<<" Salir.";color(console,7);
		cout<<"\n\n -> ";	color(console,11);
		cin>>op;	color(console,7);
		
		if(op != 1 && op != 0){
			
			color(console,12);
			cout<<"\n Error: seleccion no valida.";
			color(console,7);
			cout<<"\n [OK] Continuar presiona cualquier tecla";
			getch();
			
		}else if(op == 0){
			
			return;
			
		}else{
			
			system("cls");
			color(console,14);
			cout<<"\n\tCONSULTA DE EMPLEADO\n";
			color(console,7);
			cout<<"\n Ingrese el ID del empleado: ";	color(console,11);
			cin>>id_empleado;	color(console,7);
			
			if(validar_empleado(id_empleado) == true){
				
				ifstream bin_con("Empleados.txt", ios::in | ios::binary);
				
				if(bin_con.fail()){
					
					color(console,12);
					cout<<"\n Error al abrir ";color(console,4);
					cout<<"\"Empleados.txt\".";color(console,7);
					getch();
					break;
				}
				
				bin_con.read(reinterpret_cast<char*> (&consulta),sizeof(Empleados));
				
				while(!bin_con.eof()){
					
					if(consulta.id_empleado == id_empleado){
						break;
					}
					
					bin_con.read(reinterpret_cast<char*> (&consulta),sizeof(Empleados));
				}
				
				cout<<"\n\n Nombre: ";	color(console,9);
				cout<<consulta.nombre;	color(console,7);
				cout<<"\n Apellido: ";	color(console,9);
				cout<<consulta.apellidos;	color(console,7);
				cout<<"\n Sexo: ";	color(console,3);
				cout<<consulta.sexo;	color(console,7);
				cout<<"\n Cargo: ";	color(console,9);
				cout<<nombre_cargo(consulta.id_cargo);	color(console,7);
				cout<<"\n   Sueldo: ";color(console,6);
				cout<<"$"<<sueldo_cargo(consulta.id_cargo);	color(console,7);
				cout<<"\n Banco: ";	color(console,9);
				cout<<nombre_banco(consulta.id_banco);	color(console,7);
				cout<<"\n   Tipo: ";	color(console,9);
				cout<<consulta.tipo_cuenta;	color(console,7);
				cout<<"\n   # Cuenta: ";	color(console,9);
				cout<<consulta.num_cuenta;	color(console,7);
				
				cout<<"\n\n [OK] Continuar.. ";
				getch();
				
			}else{
				color(console,12);
				cout<<"\n No existe este empleado [OK]";
				color(console,7);
				getch();
				
			}
						
		}
		
	}while(true);
	
}


long long sueldo_cargo(long id_cargo){
	
	ifstream bin("Cargos.txt",ios::in | ios::binary);
	
	if(bin.fail()){
		color(console,12);	
		cout<<"\n Fallo al abrir ";color(console,4);
		cout<<"\"Cargos.txt\".";
		color(console,7);
		return 0;
	}
	
	Cargos sueldo;
	
	bin.read(reinterpret_cast<char*>(&sueldo),sizeof(Cargos));
	
	while(!bin.eof()){
		
		if(id_cargo == sueldo.id_cargo){
			
			return sueldo.sueldo;
			
		}
		
		bin.read(reinterpret_cast<char*>(&sueldo),sizeof(Cargos));
	}
	
	bin.close();
	
}

string nombre_cargo(long id_cargo){
	
	ifstream bin("Cargos.txt",ios::in | ios::binary);
	
	if(bin.fail()){
		color(console,12);
		cout<<"\n Fallo al abrir ";	color(console,4);
		cout<<"\"Cargos.txt\".";	color(console,7);
		return "";
	}
	
	Cargos cargo;
	
	bin.read(reinterpret_cast<char*>(&cargo),sizeof(Cargos));
	
	while(!bin.eof()){
		
		if(id_cargo == cargo.id_cargo){
			
			return cargo.nombre_cargo;
			
		}
		bin.read(reinterpret_cast<char*>(&cargo),sizeof(Cargos));
	}
	
	bin.close();
	
}

string nombre_banco(long id_banco){
	
	ifstream bin("Bancos.txt",ios::in | ios::binary);
	
	if(bin.fail()){
		color(console,12);
		cout<<"\n Fallo al abrir ";color(console,4);
		cout<<"\"Bancos.txt\".";	color(console,7);
		return "";
	}
	
	Bancos banco;
	
	bin.read(reinterpret_cast<char*>(&banco),sizeof(Bancos));
	
	while(!bin.eof()){
		
		if(id_banco == banco.id_banco){
			
			return banco.nombre_banco;
			
		}
		bin.read(reinterpret_cast<char*>(&banco),sizeof(Bancos));
	}
	
	bin.close();
	
}


void reporte(){
	
	if(validar_creacion_empleado() == false){

		getch();
		return;
	}
	
	system("cls");
	color(console,14);
	cout<<endl<<setw(65)<<"REPORTE GENERAL\n";
	color(console,7);
	//LINEA
	cout<<endl<<" ";
	for(int x = 0; x < 114; x++){
		cout<<"-";
	}
	
	cout<<"\n |";color(console,14);
	cout<<setw(15)<<"ID Empleado";color(console,7);
	cout<<" |";color(console,14);
	cout<<setw(20)<<"Apellidos";color(console,7);
	cout<<" |";color(console,14);
	cout<<setw(13)<<"Nombre";color(console,7);
	cout<<" |";color(console,14);
	cout<<setw(11)<<"Sueldo";color(console,7);
	cout<<" |";color(console,14);
	cout<<setw(15)<<"Banco";color(console,7);
	cout<<" |";color(console,14);
	cout<<setw(10)<<"Tipo";color(console,7);
	cout<<" |";color(console,14);
	cout<<setw(15)<<"# de Cuenta";color(console,7);
	cout<<" |";
	
	//LINEA
	
	cout<<endl<<" ";
	for(int x = 0; x < 114; x++){
		cout<<"-";
	}
	
	Empleados empleado;
	
	ifstream bin("Empleados.txt",ios::in | ios::binary);
	
	if(bin.fail()){
		
		color(console,12);
		cout<<"\n Fallo en abrir ";	color(console,4);
		cout<<"\"Empleados.txt\".";	color(console,7);
		return;
	}
	
//	Variables para el texto
	long long promedio = 0;
	int cant = 0;
	int mayor_sueldo = 0;
	int menor_sueldo = 99999999;
	long id_menor;
	long id_mayor;
	int sueldos[3] = {0,0,0};
	int col = 7;
	
	Empleados mayor;
	Empleados menor;
	
	
	bin.read(reinterpret_cast<char*>(&empleado),sizeof(Empleados));
	while(!bin.eof()){
		
		cout<<"\n |";
		cout<<setw(15)<<empleado.id_empleado;
		cout<<" |";
		cout<<setw(20)<<empleado.apellidos;
		cout<<" |";
		cout<<setw(13)<<empleado.nombre;
		cout<<" |";
		cout<<setw(11)<<sueldo_cargo(empleado.id_cargo);
		cout<<" |";
		cout<<setw(15)<<nombre_banco(empleado.id_banco);
		cout<<" |";
		cout<<setw(10)<<empleado.tipo_cuenta;
		cout<<" |";
		cout<<setw(15)<<empleado.num_cuenta;
		cout<<" |";
		
		// Calculos
		long long sueldo = sueldo_cargo(empleado.id_cargo);
		promedio += sueldo;
		cant++;
		
		if(mayor_sueldo < sueldo){
			
			mayor_sueldo = sueldo;
			mayor = empleado;
		}
		
		if(cant == 1){
			
			menor_sueldo = mayor_sueldo;
			menor = empleado;
		}
		
		if(menor_sueldo > sueldo){
			menor_sueldo = sueldo;
			menor = empleado;
		}
		
		if(sueldo < 2000000){
			
			sueldos[0]++;
			
		}else if(sueldo < 5000000){
			
			sueldos[1]++;
			
		}else{
			
			sueldos[2]++;
			
		}
		
		bin.read(reinterpret_cast<char*>(&empleado),sizeof(Empleados));
	}

	//LINEA
	cout<<endl<<" ";
	for(int x = 0; x < 114; x++){
		cout<<"-";
	}
	
	cout<<"\n\n Sueldo promedio: ";color(console,6);
	cout<<"$"<<promedio/cant;color(console,7);
	
	cout<<"\n Empleado con ";color(console,10);
	cout<<"mayor ";color(console,7);
	cout<<"sueldo: ";color(console,10);
	cout<<mayor.nombre<<" "<<mayor.apellidos<<" con ";color(console,6);
	cout<<"$"<<sueldo_cargo(mayor.id_cargo);color(console,7);
	
	cout<<"\n Empleado con ";color(console,12);
	cout<<"menor";color(console,7);
	cout<<" sueldo: ";color(console,12);
	cout<<menor.nombre<<" "<<menor.apellidos<<" con ";color(console,6);
	cout<<"$"<<sueldo_cargo(menor.id_cargo);color(console,7);
	
	cout<<"\n Menor a 2 Millones: ";	color(console,9);
	cout<<(sueldos[0]*100/cant)<<"%";	color(console,7);
	cout<<"\n Entre 2 y 5 Millones: ";	color(console,9);
	cout<<(sueldos[1]*100/cant)<<"%";	color(console,7);
	cout<<"\n Superior a 5 Millones: ";	color(console,9);
	cout<<(sueldos[2]*100/cant)<<"%";	color(console,7);
	
	cout<<endl<<endl<<" - [OK]";
	
	/*
	cout<<endl;
	cout<<"-";
	cout<<setw((10/2) + (strlen("I")/2))<<"I"<<setw(10 - ((10/2) + (strlen("I")/2)));
	cout<<" ";cout<<"-";
	cout<<endl;
	*/
	getch();
}










