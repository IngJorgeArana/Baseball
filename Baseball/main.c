#include <stdio.h>
#include <stdlib.h>

#define clear() printf("\033[H\033[J") 
#define Bateador() rand()%5
/*La funcion que puse aqui arriba (clear()) la puse porque tengo un sistema operativo diferente,
Solo cambia las funciones clear que estan en el codigo por system("CLS"); y no va a haber problema*/


const char *P_mineros[14];
const char *P_dorados[14];
void jugadores();
void Empezar();
void Pitcher(int pitcher, int turno);
void Ganar_perder();
void Imprime_resultados();
void Grabar_datos();
void Juega_equipo(int inning, char *bat, char *pitch, int turno);
int inning;
int carrerasD;
int carrerasM;
FILE *fp;

int main (int argc, char *argv[])
{
	int op=0;
	printf("******************************************\n*                                        *\n*           PROYECTO FORMATIVO           *\n*          SIMULADOR DE BASEBALL         *\n*              MAGALY RIVERO             *\n*                                        *\n******************************************\n\n\n");
	start:printf("Elige una opcion:\n1) Empezar simulacion del partido.\n2) Ver jugadores de cada equipo.\n3) Salir.\n");
	scanf("%d",&op);
	switch (op){
	case 1:{
			clear();
			Empezar();
			break;
		   }
	case 2:{
			clear();
			jugadores();
			goto start;
			break;
		   }
	case 3:{
			clear();
			printf("Adios!!\n\n");
			break;
		   }
	default:{
				printf("\n\nOpcion invalida\n\n");
				goto start;
			}
			}
			
			return 0;
}

void jugadores(){
	int op;
	seleccion:printf("Selecciona el equipo del cual quieres ver los jugadores:\n1) Dorados de Chihuahua.\n2) Mineros de Parral\n3) Volver al menu principal.\n");
	scanf("%d",&op);
	switch (op){
	case 1:{
			clear();
			printf("Catchers:\n -1 Isidro Piña\n -20 Carlos Gonzalez\n -29 Hector Hurtado\n -38 Carlos Rodriguez\n\n");
			printf("Infielders:\n -10 Omar Mendoza\n -16 Alejandro Ahumada\n -25 Alejandro Bobadilla\n -24 Ramon Orantes\n -44 Jose Castañeda\n -51 Benjamin Gil\n -78 Francisco Mendez\n\n");
			printf("Outfielders:\n -18 Wilfredo Arano\n -19 Jacob Cruz\n -26 Fernando Rios\n -42 Ricardo Gastelum\n -57 Eder Salcedo\n -59 Luis Carlos Garcia\n\n");
			printf("Pitchers:\n -11 Angel Araiza\n -12 Oscar Bernal\n -14 Eddy Ramos\n -28 Humberto Montemayor\n -34 Jose de Jesus Jimenez\n -39 Ramon Garcia\n -46 Leo Medrano\n -48 Mauro Nieblas\n -54 Angel Castro\n -56 Miguel Angel Lopez\n -58 Jose Silva\n -77 Ivan Cordoba\n -91 Makoto Suzuki\n -93 Caludio Sanchez\n\n");
			goto seleccion;
			break;
		   }
	case 2:{
			clear();
			printf("Catchers:\n -2 Aaron Chavez\n -1 Victor Hugo Chavez\n -3 Alvaro Ruiz\n\n");
			printf("Infielders:\n -4 Alberto Guevara\n -13 Alejandro Alvarado\n -7 Alexis Prieto\n -10 Diego Gutierrez\n -11 Hugo Gutierrez\n -8 Jesus Yañez\n -5 Jonatan Quiñonez\n -9 Julian Villanueva\n -6 Mario Rodriguez\n -12 Rafael Arambula\n\n");
			printf("Outfielders:\n -18 Cirilio Vazquez\n -14 Jose Alberto Luna\n -16 Jose Torres\n -15 Omar Chairez\n -17 Ramon Espinoza\n -19 Samuel Dominguez\n\n");
			printf("Pitchers:\n -20 Alan Gaxiola\n -22 Alejandro Loya\n -21 Antonio Miranda\n -30 Benjamin Vasquez\n -28 Daniel Jusaino\n -24 Daniel Valdez\n -23 Emilio Guerrero\n -27 Erik Sagarnaga\n -26 Fernando Vasquez\n -25 Humberto Gutierrez\n -32 Hector Favela\n -29 Julio Contreras\n -31 Mario Perea\n\n");
			goto seleccion;
			break;
		   }
	case 3:{
			clear();
			break;
		   }
	default:{
				printf("\n\nOpcion invalida\n\n");
				goto seleccion;
			}
			}
}

void Empezar(){
	P_dorados[0]="Angel Araiza";
	P_dorados[1]="Oscar Bernal";
	P_dorados[2]="Eddy Ramos";
	P_dorados[3]="Humberto Montemayor";
	P_dorados[4]="Jose de Jesus Jimenez";
	P_dorados[5]="Ramon Garcia";
	P_dorados[6]="Leo Medrano";
	P_dorados[7]="Mauro Nieblas";
	P_dorados[8]="Angel Castro";
	P_dorados[9]="Miguel Angel Lopez";
	P_dorados[10]="Jose Silva";
	P_dorados[11]="Ivan Cordoba";
	P_dorados[12]="Makoto Suzuki";
	P_dorados[13]="Caludio Sanchez";
	P_mineros[0]="Alan Gaxiola";
	P_mineros[1]="Alejandro Loya";
	P_mineros[2]="Antonio Miranda";
	P_mineros[3]="Benjamin Vasquez";
	P_mineros[4]="Daniel Jusaino";
	P_mineros[5]="Daniel Valdez";
	P_mineros[6]="Emilio Guerrero";
	P_mineros[7]="Erik Sagarnaga";
	P_mineros[8]="Fernando Vasquez";
	P_mineros[9]="Humberto Gutierrez";
	P_mineros[10]="Hector Favela";
	P_mineros[11]="Julio Contreras";
	P_mineros[12]="Mario Perea";
	int turno;
	printf("Bienvenidos damas y caballeros a un nuevo partido de Baseball en este su Estadio Monumental de Chihuauha.\nEn esta ocasion tenemos la fortuna de tener el encuentro de los Dorados de Chihuahua vs Los Mineros de Parral.\nComo siempre el equipo visitante ira primero.\nMucha suerte a los Mineros de Parral.\n\n");
	int checkpoint=1;
	do{
	printf("Presione 0 para empezar el partido.\n\n");
	scanf("%c",&checkpoint);
	}while (checkpoint<1);
	clear();
   fp = fopen("/home/jorge/Desktop/outmarcador.dat", "w+");
	for(inning =1;inning<=9;inning++){
		Grabar_datos();
		turno=0;
		Juega_equipo(inning, P_mineros, P_dorados, turno);
		clear();
		turno=1;
		Juega_equipo(inning, P_dorados, P_mineros, turno);
		clear();
	}
   fclose(fp);
}


void Juega_equipo(int inning, char *bat, char *pitch, int turno){
	int outs=0, tiro, contador=0, foul=0, bola=0, strike=0, first=NULL, second=NULL, third=NULL;
	if (turno==0){
		printf("%d° inning: Juega Mineros\n\n", inning);
		Imprime_resultados();
		}
	else{
		printf("%d° inning: Juega Dorados\n\n", inning);
		Imprime_resultados();
		}
	while(outs<3){
		printf("\n\nMarcador actual: Dorados %d - Mineros %d\n Outs %d",carrerasD,carrerasM,outs);
		
		bola=0, strike=0;
		if(foul==2){
			outs++;
			foul=0;
		}
		if(strike==3){
			outs++;
			strike=0;
		}
		sifoul:Pitcher(inning-1,turno);
		Bateando:if(contador<=13){
			tiro=Bateador();
			contador++;
		}
		else{
			contador=0;
			goto Bateando;
		}
		switch (tiro){
			case 0:{
				int tipo1=rand()%7;
				switch(tipo1){
					case 0:{
					if(turno==1){
							printf("%s ha bateado un HIT\n",P_dorados[contador]);	
							if(third!=NULL){
								carrerasD++;
								printf("Carrera anotada por %s",P_dorados[third]);
							}
						}
						else{
							printf("%s ha bateado un HIT\n",P_mineros[contador]);	
							if(third!=NULL){
								carrerasM++;
								printf("Carrera anotada por %s",P_mineros[third]);
							}
						}
						third=second;
						second=first;
						first=contador;
						break;
					}
					case 1:{
						if(turno==1){
							printf("%s ha bateado un HIT\n",P_dorados[contador]);
							if(third!=NULL){
								carrerasD++;
								printf("Carrera anotada por %s",P_dorados[third]);
							}
						}
						else{
							printf("%s ha bateado un HIT\n",P_mineros[contador]);	
							if(third!=NULL){
								carrerasM++;
								printf("Carrera anotada por %s",P_mineros[third]);
							}
						}
						third=second;
						second=first;
						first=contador;
						break;
					}
					case 2:{
						if(turno==1){
							printf("%s ha bateado un HIT\n",P_dorados[contador]);	
							if(third!=NULL){
								carrerasD++;
								printf("Carrera anotada por %s",P_dorados[third]);
							}
						}
						else{
							printf("%s ha bateado un HIT\n",P_mineros[contador]);	
							if(third!=NULL){
								carrerasM++;
								printf("Carrera anotada por %s",P_mineros[third]);
							}
						}
						third=second;
						second=first;
						first=contador;
						break;
					}
					case 3:{
						if(turno==1){
							printf("%s ha bateado un DOUBLE\n",P_dorados[contador]);	
							if(third!=NULL){
								carrerasD++;
								printf("Carrera anotada por %s",P_dorados[third]);
							}	
							if(second!=NULL){
								carrerasD++;
								printf("Carrera anotada por %s",P_dorados[second]);
							}
						}
						else{
							printf("%s ha bateado un DOUBLE\n",P_mineros[contador]);	
							if(third!=NULL){
								carrerasM++;
								printf("Carrera anotada por %s",P_mineros[third]);
							}	
							if(second!=NULL){
								carrerasM++;
								printf("Carrera anotada por %s",P_mineros[second]);
							}
						}
						second=first;
						first=contador;
						break;
					}
					case 4:{
						if(turno==1){
							printf("%s ha bateado un TRIPLE\n",P_dorados[contador]);	
							if(third!=NULL){
								carrerasD++;
								printf("Carrera anotada por %s",P_dorados[third]);
							}	
							if(second!=NULL){
								carrerasD++;
								printf("Carrera anotada por %s",P_dorados[second]);
							}
							if(first!=NULL){
								carrerasD++;
								printf("Carrera anotada por %s",P_dorados[first]);
							}
						}
						else{
							printf("%s ha bateado un TRIPLE\n",P_mineros[contador]);	
							if(third!=NULL){
								carrerasM++;
								printf("Carrera anotada por %s",P_mineros[third]);
							}	
							if(second!=NULL){
								carrerasM++;
								printf("Carrera anotada por %s",P_mineros[second]);
							}
							if(first!=NULL){
								carrerasM++;
								printf("Carrera anotada por %s",P_mineros[first]);
							}
						}
						first=contador;
						break;
					}
					case 5:{
						if(turno==1){
							printf("%s ha bateado un HOME RUN!!\n",P_dorados[contador]);
							carrerasD++;	
							if(third!=NULL){
								carrerasD++;
								printf("\nCarrera anotada por %s",P_dorados[third]);
							}	
							if(second!=NULL){
								carrerasD++;
								printf("\nCarrera anotada por %s",P_dorados[second]);
							}
							if(first!=NULL){
								carrerasD++;
								printf("\nCarrera anotada por %s",P_dorados[first]);
							}
						}
						else{
							printf("%s ha bateado un HOME RUN!!\n",P_mineros[contador]);
							carrerasM++;	
							if(third!=NULL){
								carrerasM++;
								printf("\nCarrera anotada por %s",P_mineros[third]);
							}	
							if(second!=NULL){
								carrerasM++;
								printf("\nCarrera anotada por %s",P_mineros[second]);
							}
							if(first!=NULL){
								carrerasM++;
								printf("\nCarrera anotada por %s",P_mineros[first]);
							}
						}
						break;
					}
					default:{
						if(turno==1){
							printf("%s ha bateado un tiro elevado y queda fuera\n",P_dorados[contador]);
						}
						else{
							printf("%s ha bateado un tiro elevado y queda fuera\n",P_mineros[contador]);
						}
						outs++;
					}
				}
				break;
			}
			case 1:{
				int tipo2=rand()%2;
				if (tipo2==0){
					if(turno==1){
						printf("Foul de %s\n",P_dorados[contador]);
					}
					else{
						printf("Foul de %s",P_mineros[contador]);
					}
					if(strike<2){
						strike++;
					}
					goto sifoul;
				}
				else{
					if(turno==1){
						printf("%s ha bateado un tiro elevado y queda fuera\n",P_dorados[contador]);
					}
					else{
						printf("%s ha bateado un tiro elevado y queda fuera\n",P_mineros[contador]);
					}
					outs++;
				}
				break;
			}
			default:{
				int tipo3=rand()%2;
				if (tipo3==0){
						printf("Bola!");
					if(turno==1){
					}
					else{
						printf("Bola!");
					}
					bola++;
					if(bola<4){
						goto sifoul;
					}
					else{	
						if(third!=NULL&&turno==1){
							carrerasD++;
							printf("Se otorga boleto a %s",P_dorados[third]);
						}	
						else if(third!=NULL&&turno==0){
							carrerasM++;
							printf("Se otorga boleto a %s",P_mineros[third]);
						}
						third=second;
						second=first;
						first=contador;
					}
				}
				else{
					if(turno==1){
						printf("STRIKE %d!!",strike+1);
					}
					else{
						printf("STRIKE %d!!",strike+1);
					}
					strike++;
					if(strike==3){
						outs++;
					}
					else{
						goto sifoul;
					}
				}
			}
		}
	}
		
	char checkpoint;
	printf("\n\nPresione una tecla para pasar a siguiente seccion.\n");
	scanf("%c",&checkpoint);
}

void Pitcher(int pitcher, int turno){
	int lanzamiento=rand()%4,a;
	if (turno==0){
		switch (lanzamiento){
		case 0:{
			printf("\n%s envio una bola rapida\n",P_mineros[pitcher]);
			break;
			}
		case 1:{
			printf("\n%s envio una bola curva\n",P_mineros[pitcher]);
			break;
			}
		case 2:{
			printf("\n%s envio una bola pesada\n",P_mineros[pitcher]);
			break;
			}
		default:{
			printf("\n%s envio una bola resvaladiza\n",P_mineros[pitcher]);
			}
		}
	}
	else{
		switch (lanzamiento){
		case 0:{
			printf("\n%s envio una bola rapida\n",P_dorados[pitcher]);
			break;
			}
		case 1:{
			printf("\n%s envio una bola curva\n",P_dorados[pitcher]);
			break;
			}
		case 2:{
			printf("\n%s envio una bola pesada\n",P_dorados[pitcher]);
			break;
			}
		default:{
			printf("\n%s envio una bola resvaladiza\n",P_dorados[pitcher]);
			}
		}
	}
	scanf("%d",&a);
}

void Imprime_resultados(){
	printf("Dorados %d - Mineros %d\n ",carrerasD,carrerasM);
}

void Grabar_datos(){
   fprintf(fp,"Entrada %d   Dorados %d - Mineros %d\n ",inning,carrerasD,carrerasM);
}

