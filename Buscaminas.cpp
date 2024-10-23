
#define color SetConsoleTextAttribute
#define salida GetStdHandle

#define gris 8
#define rojo 4

#include<iostream>
#include<math.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<cstdlib>
using namespace std;

HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);

struct Tabla{
	
	int tablero[10][10];
	char vista[10][10];
};


struct Punto{
	int x;
	int y;
};


void loop(Tabla);
bool movimiento(char,Punto&);
void marcador(Punto, Tabla&);
void despejar(Punto, Tabla&);
void crear_minas(Tabla&, Punto);
void despejarCercanas(int, int, Tabla &);
bool despejarUna(int, int, Tabla &);

int main()
{
	
	setlocale(LC_ALL,"spanish");
	
	Tabla t;
	
	for(int x = 0; x < 10; x++){
		
		for(int y = 0; y < 10; y++){
			t.tablero[x][y] = 0;
			t.vista[x][y] = '#';
			
		}
		
	}
	
	loop(t);
	
	
	return 0;
}

int marcas = 0;

bool movimiento(char var, Punto &p)
{	
	if(p.x == 0 && var == 'a' || p.y == 0 && var == 'w'){
		return false;
	}
	if(p.x == 9 && var == 'd' || p.y == 9 && var == 's'){
		return false;
	}

	switch(var){
		
		case 'w'://Arriba
			p.y--;
			break;
		case 'a'://Izquierda
			p.x--;
			break;
		case 's'://Abajo
			p.y++;
			break;
		case 'd'://Derecha
			p.x++;
			break;
		
	}
	
}

void marcador(Punto p, Tabla &t)
{
	if(t.vista[p.x][p.y] == '#'){
		marcas++;
		t.vista[p.x][p.y] = '|';
		
	}else if(t.vista[p.x][p.y] == '|'){
		marcas--;
		t.vista[p.x][p.y] = '#';
	}
		
}

void crear_minas(Tabla &t, Punto p)
{	
	for(int x = 0; x < 10; x++){
		
		for(int y = 0; y < 10; y++){
			t.tablero[x][y] = 0;
			t.vista[x][y] = '#';
			
		}
		
	}

	srand(time(NULL));

	for(int i=0; i<12; i++)
	{
		int x = rand() % 10;
		int y = rand() % 10;
		
		if(p.x == x && p.y == y){
			i--;
		}else if(t.tablero[x][y] != -1){
			
			t.tablero[x][y] = -1;
			
			for(int k = 1; k < 9; k++){
				int auxx = x;
				int auxy = y;
				
				switch(k){
					
					case 1:
						auxx++;
						break;
					case 2:
						auxx++;
						auxy++;
						break;
					case 3:
						auxy++;
						break;
					case 4:
						auxy--;
						break;
					case 5:
						auxy--;
						auxx--;
						break;
					case 6:
						auxx--;
						break;
					case 7:
						auxx--; 
						auxy++;
						break;
					case 8:
						auxy--;
						auxx++;
						break;
				}
					
				if( auxx < 10 && auxy < 10 && auxy >= 0 && auxx >= 0){
					
					if(t.tablero[auxx][auxy] != -1){
						t.tablero[auxx][auxy]++;	
					}	
					
				}
				
			}
			
		}
	}
	
}

void despejar(Punto p, Tabla &t)
{		
	static bool usado = false;
	
	if(t.tablero[p.x][p.y] == -1){
		color(Console,rojo);
		t.vista[p.x][p.y] = '×';
		cout<<"PERDISTE HERMANO.";
		color(Console,7);
		
	}else if(usado == false){
		usado =true;
		despejarCercanas(p.x,p.y,t);
		
	}else{
		
		if(despejarUna(p.x,p.y,t) == false){
			color(Console,rojo);
			cout<<"				GAME OVER";
			crear_minas(t,p);
			color(Console,7);
		}
	}

}

bool despejarUna(int x, int y, Tabla &t){
	
	if(t.tablero[x][y] >= 0 &&  t.vista[x][y] == '#'){
		t.vista[y][x] = '+';
		return true;
	}
	
	if(t.vista[x][y] == '|'){
		color(Console,rojo);
		cout<<"\n No puedes realizar esta accion, desmarca";
		color(Console,7);
		return true;
	}
	
	return false;
}

void despejarTodo(Tabla &t){
	
	for(int x = 0; x < 10; x++){
		
		for(int y = 0; y < 10; y++){
			
			if(t.tablero[x][y] > 0){
				t.vista[x][y] = '+';
			}
			if(t.tablero[x][y] < 0){
				t.vista[x][y] = '×';
			}
			
		}
		
	}
	
}

void despejarCercanas(int x, int y, Tabla &t){
	
	for(int k = 1; k < 9; k++){
			
			int auxx = x;
			int auxy = y;
				
			switch(k){
					
				case 1:
					auxx++;
					break;
				case 2:
					auxx++;
					auxy++;
					break;
				case 3:
					auxy++;
					break;
				case 4:
					auxy--;
					break;
				case 5:
					auxy--;
					auxx--;
					break;
				case 6:
					auxx--;
					break;
				case 7:
					auxx--; 
					auxy++;
					break;
				case 8:
					auxy--;
					auxx++;
					break;
			}
				
			
				
			if( auxx < 10 && auxy < 10 && auxy >= 0 && auxx >= 0){
				
				int random = (rand() % 4) + 1;
				
				if(t.tablero[auxx][auxy] >= 0 && t.vista[auxx][auxy] == '#'){
					t.vista[auxx][auxy] = '+';
					
					if(random > 3){
						
						despejarCercanas(auxx,auxy,t);
					}
		
				}	
					
			}
				
		}
	
}

void loop(Tabla t)
{
	char var = '\0';
	char prevar;
	
	bool primera_vez = false;
	
	Punto p;
	p.x = 0;
	p.y = 0;
	
	int colors[9] = {10,2,11,3,9,13,5,6,4};
	
	do
	{
		
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});
		
		cout<<" Teclas para presionar: \n";
		cout<<" q -- salir\n";
		cout<<" W A S D -- movimiento\n";
		cout<<" Enter -- despejar\n";
		cout<<" Espacio -- marcar\n";
		cout<<" r - Reiniciar";
		cout<<"\n : "<<var;
		cout<<"\n X: "<<p.x<<"\tY:"<<p.y;
		color(Console,6);
		cout<<"\n\n MARCAS: "<<marcas<<"          ";
		color(Console,7);
		cout<<"\n              ";
		
		for(int y=0; y < 10; y++)
		{
			for(int x=0; x < 10; x++)
			{
				
				if(p.x == x && p.y == y){
					color(Console,15);
					cout<<"[";
					color(Console,7);
				}else if(x - 1 == p.x && x != 0 && p.y == y){
					
				}else{
					cout<<" ";
				}
				
				if(t.vista[x][y] == '|'){
					color(Console,rojo);
					cout<<t.vista[x][y];
				}else if(t.vista[x][y] == '+'){
					
					if(t.tablero[x][y] > 0){
						color(Console,colors[t.tablero[x][y]]);
						cout<<t.tablero[x][y];
					}else{
						color(Console,gris);
						t.vista[x][y] == '+';
					}
					
					color(Console,gris);
					
				}else{
					cout<<t.vista[x][y];
				}
				
				color(Console,7);
				
//				if(t.tablero[x][y] == -1){
//					cout<<"×";
//				}else if(t.tablero[x][y] != 0){ 
//					
//					cout<<t.tablero[x][y];
//					
//				}else{
//					cout<<"#";
//				}
				
				if(p.x == x && p.y == y){
					color(Console,15);
					cout<<"]";
					color(Console,7);
				}
				
			}
			cout<<"\n              ";
		}
		
		var = (char)getch();
		
		movimiento(var,p);
		
		switch(var){
			case (int)' ':
				
				if(marcas >= 12){
	
					color(Console,rojo);
					cout<<" No puedes poner mas marcas";
					color(Console,7);
					break;
				}
				
//				cout<<"ESPACIO        ";
				marcador(p, t); 
				break;
				
			case 13:
//				cout<<"Enter          ";
				
				if(primera_vez == false){
					primera_vez = true;
					marcas = 0;
					crear_minas(t,p);
					despejar(p,t);
					break;
				}
				
				despejar(p,t);	
				
			case (int)'r':
				color(Console,rojo);
				cout<<"R para reintentar.";
				color(Console,7); 
				if(getch() == (int)'q'){
					exit(0);
				}
				
				marcas = 0;
				primera_vez = false;
				crear_minas(t,p);
				break;
		}
		
		int cont = 0;
		int cont2 = 0;
		for(int x = 0; x <10; x++){
			
			for(int y = 0; y < 10; y++){

				if(t.vista[x][y] == '+'){
					cont2++;
				}
				
			}
		}
		
		if(cont2 == (10*10)-12){
			
			color(Console,2);
			cout<<"\n   GANASTE   \n";
			color(Console,7);
			exit(0);
		}
		
		cout<<"                                          ";
		cout<<"\n                                          ";
		
	}while(var != 'q');
	
	cout<<"\nSALIENDO...";
	
}

