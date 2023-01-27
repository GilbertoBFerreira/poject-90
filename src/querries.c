#include "../includes/catalogo.h"
#define DATAREF "09/10/2022"


typedef struct avald{
    int viagens;
    float avaliaçao_driver;
} *AVALD ;

typedef struct avalu{
    int viagens;
    float avaliaçao_user;
} *AVALU ;

GHashTable *get_HashDrivers(HASHDRIVER l){
    return l->driver;
}


char* getDriversCarClass(DRIVER d){
    return d->car_class;
}

int getIdDriver (RIDE d){
    return d->driver;
}

int getIdRide (RIDE d){
    return d->id;
}

char* getRideCity (RIDE d){
    return d->city;
}
 
int getDistance (RIDE d){
    return d->distance;
}

int getEvalD (RIDE d){
    return d->score_driver;
}

char* getUser (RIDE d){
    return d->user;
}

int getEvalU (RIDE d){
    return d->score_user;
}

//1


int calculaIdade (DATA2 birth_date){
    

    int mes[] = { 31, 28, 31, 30, 31, 30,
                    31, 31, 30, 31, 30, 31 };
    
    DATA2 current_date = atribuiData (DATAREF);
 

    if (birth_date.dia > current_date.dia) {
        current_date.dia = current_date.dia + mes[birth_date.mes - 1];
        current_date.mes = current_date.mes - 1;
    }
    
    if (birth_date.mes > current_date.mes) {
        current_date.ano = current_date.ano - 1;
        current_date.mes = current_date.mes + 12;
    }
 
    int calcular_dia = current_date.dia - birth_date.dia;
    int calcular_mes = current_date.mes - birth_date.mes;
    int calcular_ano = current_date.ano - birth_date.ano;
 
    return calcular_ano;
}


void evalMediaD (int IdDriver, RIDEL t){
    int avaltot = 0;
    AVALD driver = malloc (sizeof (AVALD));
    driver->viagens = 0; driver->avaliaçao_driver = 0;

    for ( ; t != NULL; t = t->next){
        if (IdDriver == getIdDriver (t->curr_ride)) {avaltot += getEvalD (t->curr_ride); 
                                                    driver->viagens ++;}
    }
    driver->avaliaçao_driver = avaltot / driver->viagens;
}


void evalMediaU (char* username, RIDEL t){
    int avaltot =0 ;
    AVALU user = malloc (sizeof (AVALU));
    user->viagens = 0; user->avaliaçao_user = 0;

    for ( ; t != NULL; t = t->next){
        if (username == getUser (t->curr_ride)) {avaltot += getEvalU (t->curr_ride); 
                                                    user->viagens ++;}
    }
    user->avaliaçao_user = avaltot / user->viagens;
}


//4
	


char* verificaClasse(int id_driver,HASHDRIVER d)
{
    GHashTable* temp = NULL;
    temp=get_HashDrivers(d);
    int* idDriver = &id_driver;
    DRIVER dr = g_hash_table_lookup(temp,idDriver);
    char* classe = getDriversCarClass(dr);
    g_hash_table_destroy(temp);
    
    return classe;
}


int query4 (HASHDRIVER t, RIDEL d, char* city){
    int soma = 0;
    int cidade = 0;
    double media;

    for ( ; d->curr_ride != NULL; d = d->next){
        if (verificaCidade (city,d->curr_ride) == 1) {

                cidade++;

                if (verificaClasse (getIdDriver (d->curr_ride), t) == "Basic") {
                                soma += 3.25 + 0.62 * getDistance (d->curr_ride);
                }
                
                else if (verificaClasse (getIdDriver (d->curr_ride), t) == "Green") {
                                soma += 4 + 0.79 * getDistance (d->curr_ride);
                }
                
                else if (verificaClasse (getIdDriver (d->curr_ride), t) == "Premium") {
                                soma += 5.20 + 0.94 * getDistance (d->curr_ride);
                }
                }
       }

    media = soma / cidade;

    return media;
    }







