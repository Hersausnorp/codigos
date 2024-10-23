#include<iostream>
using namespace std;

void calificaciones();

int main()
{
	
	calificaciones();
		
	return 0;
}

void calificaciones()
{
	int c1=0, c2=0, c3=0, c4=0, c5=0, est;
	float cal;
	
	cout<<"Ingrese numero de estudiantes: ";
	cin>>est;
	
	for(int i=1; i<=est; i++)
	{
		do{
			cout<<"Ingrese la calificacion del estudiante "<<i<<": ";
			cin>>cal;
		}while(cal < 1 || cal > 10);
		
		if(cal < 4)
		{
			c1++;
		}
		else if(cal < 6)
		{
			c2++;
		}
		else if(cal < 8)
		{
			c3++;
		}
		else if(cal < 9)
		{
			c4++;
		}
		else
		{
			c5++;
		}
	}
	
	cout<<"Calificaciones de [0] a [3.99]: "<<c1<<endl;
	cout<<"Calificaciones de [4] a [5.99]: "<<c2<<endl;
	cout<<"Calificaciones de [6] a [7.99]: "<<c3<<endl;
	cout<<"Calificaciones de [8] a [8.99]: "<<c4<<endl;
	cout<<"Calificaciones de [9] a [10]: "<<c5<<endl;
	
}
