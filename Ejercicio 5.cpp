#include<iostream>
using namespace std;

void temperaturas();
void temp_promedio(float);
void temp_max();
void temp_min();

int main()
{
	temperaturas();
	
	
	return 0;
}

void temperaturas()
{
	int temp, suma=0, tem_max=0, tem_min=999;
	
	for(int i=1; i<=24; i++)
	{
		do{
			cout<<"Ingrese la temperatura de las ["<<i-1<<":00]: ";
			cin>>temp;
			suma+=temp;
			if(temp < -30 || temp > 100)
			{
				cout<<"Solo temperaturas de entre [-30] a [100]."<<endl<<endl;
			}			
		}while(temp < -30 || temp > 100);	
		
		if(temp > tem_max)
		{
			tem_max = temp;
		}
		
		if(temp < tem_min)
		{
			tem_min = temp;
		}
	}
	
	cout<<"Temperatura Maxima: "<<tem_max<<endl;
	cout<<"Temperatura Minima: "<<tem_min<<endl;	
	temp_promedio(suma);
}

void temp_promedio(float suma)
{
	cout<<"La temperatura promedio es: "<<suma/24<<endl;	
}


