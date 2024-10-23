/*

Nicolas David Henao Zuñiga	 		0222110040
Juan Pablo Fontalvo Lora			0222110018 
Andres Felipe Valencia Paternina	0222110032


*/
#include<iostream>
#include<string.h> //Al final ni se uso

using namespace std;


int validar(int NUMERO,int LIMITE_INFERIOR,int LIMITE_SUPERIOR);

void descomponer(int NUMERO,int *VECTOR_DIGITOS,int &LONGITUD_VECTOR);

void romano(int NUMERO,char *VECTOR_ROMANO);

int main(){
	
	int numero;
	int limite = 3000; //Hasta que numero quiere encontrar.
	int op = 0;
	
	do{
		system("cls");
		cout<<"\n CONVERTIDOR NUMERO A ROMANO\n";
		cout<<"\n- El Limite es de 1 hasta "<<limite-1<<".\n";
		
		//	VERIFICACION DEL NUMERO
		do{
			cout<<"\n Ingrese el numero: ";
			cin>>numero;	
			
			if(validar(numero,1,limite) == 0){
				cout<<"\n ERROR: Opcion nuero fuera del rango.\n";
			}
			
		}while(validar(numero,1,limite) == 0);
		
		//FUNCION ROMANO
		
		char numero_romano[] = "               ";
			
		romano(numero,numero_romano);
		
		cout<<"\n Romano: ";
		cout<<numero_romano;
		
		//	CONFIRMAR BUCLE
		cout<<"\n\n ¿Desea ingresar otro numero?";
		  cout<<"\n  1. Si \n  2. No";
		
		do{
	
			cout<<"\n     ->";
			cin>>op;	
			
			if(op != 1 and op !=2){
				cout<<"\n ERROR: Opcion no valida.\n";
			}
			
		}while(op != 1 and op !=2);
		
	}while(op == 1);
	
	cout<<"\n By: Nicolas David Henao.";
	cout<<"\n     Andres Felipe Valencia.";
	cout<<"\n     Juan Pablo Fontalvo.";
	
	return 1-1;
}

int validar(int numero,int lim_inf,int lim_sup){
	
	if(numero >= lim_inf && numero < lim_sup){
		return 1;
	}
	else{
		return 0;
	}
	
}

void descomponer(int numero,int *digito,int &longitud){
	
	longitud = 0;
	
	for(;numero > 0; longitud++){
		
		digito[longitud] = numero%10;
		numero /= 10;
	}
	
	//Invierto el vector.
	for(int x = 0,y = longitud-1,aux = 0; x < longitud/2; x++, y--){
		
		aux = digito[x];
		digito[x] = digito[y];
		digito[y] = aux;
		
	}
	
}

void romano(int numero,char *numero_romano){
	
	int digito[10]; //Guardar el numero descompuesto.
	int longitud = 0;
	int repetir = 0;
	int num;
	
	char letra[2]; 
	
	char roman[4][3] = {"IV","XL","CD","M"};
	
	descomponer(numero,digito,longitud);
	
	for(int valor = longitud-1, x = 0,z = 0; valor >= 0; valor--,x++, z++){

		num = digito[z]; //z recorre el numero
		
		if(num >= 1 and num < 4){
			
			numero_romano[x] = roman[valor][0];
			letra[0] = roman[valor][0];
			num -=1;
			
		}else if(num == 4){
			
			numero_romano[x] = roman[valor][0];x++; //x recorre la cantidad de caracteres puestas.
			numero_romano[x] = roman[valor][1];
			num = 0;
			
		}else if(num >= 5 and num < 9){
			
			num-=5;
			numero_romano[x] = roman[valor][1];
			letra[0] = roman[valor][0];
			
			
		}else if(num == 9){
			
			numero_romano[x] = roman[valor][0];x++;
			numero_romano[x] = roman[valor+1][0];
			num = 0;
			
		}else{
			x--;
		}
		
		for(int y = 0; y < num; y++){
			
			x++;
			numero_romano[x] = letra[0];

		}
		
	}
	
}











