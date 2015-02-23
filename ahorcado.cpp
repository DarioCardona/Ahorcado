#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <string.h>
#include <ctype.h>


using namespace std;
int menu();


int main(int argc,char** argv){
	srand(time(0));
	char conti;
	bool sal=true;
	do{
	int num=rand()% 24+1;

	char palabra [30];
	int cont=1;
	fstream leer("diccionario.txt",ios::in);

	while(leer.getline(palabra,30)){
		if (cont == num)
		{
			break;
		}
		cont++;
	}
	
	int vuelta=0;//int que maneja la cantidad de vueltas y errore
	char ans;// char que ingresa el usuario
	char resp [30];
	char tablero [6][6];
			for(int f=0;f<6;f++){// llenado del tablero
				for(int c=0;c<6;c++){
					tablero[f][c]=' ';
				}

				
			}
			char vis [strlen(palabra)];//  palabra que se mostrara al usuario
			for (int i = 0; i < strlen(palabra); ++i)
			{
				vis[i]='*';
			}


			int good=0; // int que maje los aciertos

	switch(menu()){ // switch que contrala que opcion de solicita el jugador
		case 1:{// ahorcado por letra con 7 oportunidades de fallo;
			while(vuelta<=7){
				
				bool entro=false;
				if (good==strlen(palabra))// bool que controla el ganador

				{
					cout<<"Felicidades usted adivino la palabra escondida"<<endl;
					break;
				}
				cout<<"Ingrese letra: "<<endl;
				cin>>ans;
				 ans =(toupper(ans));// convertir el char en mayuscula
				 for (int i = 0; i < strlen(vis); ++i)
				 {
				 	if(ans==vis[i]){
				 		cout<<"Esa letra ya fue ingresada"<<endl;
				 		good--;
				 	}
				 }
				for (int i = 0; i < strlen(palabra) ; i++)// for que compara la letra ingresada por la palabra
				{
					if (ans==palabra[i])
					{
						entro=true;
						vis[i]=ans;
						good++;
					}
				}
				

				if (entro==false)
				{
					vuelta++;
				}

				cout<<"Su Cantidad de aciertos es:  "<<good<<" y de errores: "<<vuelta<<endl;
				for(int f=0;f<6;f++){// imprecion del tablero
					for(int c=0;c<6;c++){
						if(vuelta==1){// if que hace el poste;
							if (c==5)
							{
								tablero[f][c]='|';
							}
						}else if(vuelta==2){// if que hace la parte superior
							tablero[0][3]='-';
							tablero[0][4]='-';
						}else if(vuelta==3){// if que hace la parte correa
							tablero[0][2]='|';
							tablero[1][2]='|';
						}else if(vuelta==4){// if que hace los brazos
							tablero[3][1]='/';
							tablero[3][3]='\\';
						}else if(vuelta==5){// if que hace las piernas
							tablero[5][1]='/';
							tablero[5][3]='\\';
						}else if(vuelta==6){// if que hace el acdomen
							tablero[3][2]='|';
							tablero[4][2]='|';
						}else if(vuelta==7){// if que hace la cara
							tablero[2][2]='0';

						}else if(vuelta==8){// if que hace la cara
							tablero[2][2]='x';

						}
						cout<<tablero[f][c];

					}

					cout<<endl;
				}
				cout<<vis<<endl;
			}
			cout<<"la palabra era: "<<palabra<<endl;

		}

		break;
		case 2:{int avan=0;// ahorcado por palabra con 4 oportunidades de fallo;
			while(vuelta<5){
				avan=good;

				
				cout<<"Ingrese la palabra porfavor: "<<endl;
				cin>>resp;
				
				for (int i = 0; i < strlen(resp); ++i)// for que pasa a uppercase
				{
					resp[i]=(toupper(resp[i]));
				}
				
				int minus;
				if (strlen(resp)>strlen(palabra))// for que determina el menor length
				{
					minus=strlen(palabra);
				}else{
					minus=strlen(resp);
				}
				
				for (int i = 0; i < strlen(vis); ++i)//for que reevalua los aciertos
				 {
				 	if(resp[i]==vis[i]){
				 		
				 		good--;
				 	}
				 }
				
				bool show=false;

				for (int i = 0; i < minus; ++i)
				{
					if (palabra[i]==resp[i])
					{
					vis[i]=palabra[i];
					good++;

					}
				}
				if (good==strlen(palabra))// bool que controla el ganador

				{
					cout<<"Felicidades usted adivino la palabra escondida"<<endl;
					break;
				}
				if (avan<good)
				{
					show=true;
				}

				if (show==false)
				{
					vuelta++;
				}

				cout<<"Su Cantidad de aciertos es:  "<<good<<" y de errores: "<<vuelta<<endl;
				for(int f=0;f<6;f++){ // imprecion del tablero
					for(int c=0;c<6;c++){
						if(vuelta==1){// if que hace el poste;
							if (c==5)
							{
								tablero[f][c]='|';
							}
							tablero[0][3]='-';
							tablero[0][4]='-';
							tablero[0][2]='|';
							tablero[1][2]='|';

						}else if(vuelta==2){
							tablero[5][1]='/';
							tablero[5][3]='\\';
							tablero[3][1]='/';
							tablero[3][3]='\\';
						}else if(vuelta==3){
							tablero[3][2]='|';
							tablero[4][2]='|';
						} else if(vuelta==4){
							tablero[2][2]='0';

						} else if(vuelta==5){
							tablero[2][2]='x';

						}
						cout<<tablero[f][c];  
					}
					cout<<endl;
				}
				
				cout<<"La pista de su palabra es: "<<vis<<endl;	 
			}
			cout<<"la palabra era: "<<palabra<<endl;
		}
		
		break;
		default :{
			cout<<"Gracias por utlizar nuestro programa"<<endl;
			conti='n';
			sal=false;
		}

	}
	if (sal==true)
	{
		cout<<"Desea seguir seguir jugando[S/N] "<<endl;
		cin>>conti;
		conti=(toupper(conti));
	}
	leer.close();
	}while (conti=='S');
	
	return 0;
}


int menu(){
	int resp;
	cout<<"1- Ahorcado por letra "<<endl;
	cout<<"2- Ahorcado por palabras"<<endl;
	cout<<"3- Salir"<<endl;
	cin>>resp;
	return resp;

}


