#include "../includes/rides.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINHAS 1000000

typedef struct data3{
        int dia;
        int mes;
        int ano;
} DATA3;


typedef struct ride {
        int id;
    DATA3 date;
    int driver;
    char* user;
    char* city;
    int distance;
    int score_user;
    int score_driver;
    float tip;
    char* comment;
} *RIDE;

typedef struct ridel
{
  RIDE curr_ride;
  struct ridel *next;
} *RIDEL;



DATA3 atribuiData3 (char* data){
        int i;
        char *temp, *aux;
        DATA3 data2;
        aux = strdup (data);
        for (i=0;(temp=(strsep(&aux,"/"))) != NULL && i<3;i++){

                switch(i){
                        case 0:
                                data2.dia = atoi (strdup(temp));
                                break;
                        case 1:
                                data2.mes = atoi (strdup(temp));
                                break;
                        case 2:
                                data2.ano = atoi (strdup(temp));
                                break;
                }
        }
        return data2;
}



RIDE inicializaRide ( int id, DATA3 date, int driver, char* user, char* city, int distance, int score_user, int score_driver, float tip, char* comment) {
	RIDE ride = malloc (sizeof(RIDE));
	ride->id = id;
	ride->date = date;
	ride->driver;
	ride->user = user;
	ride->city = city;
	ride->distance = distance;
	ride->score_user = score_user;
	ride->score_driver = driver;
	ride->tip = tip;
	ride->comment = comment;

	return ride;

}
