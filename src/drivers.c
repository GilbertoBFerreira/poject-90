#include "../includes/drivers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>



typedef struct cidades{
        int porto;
        int sp;
        int lisboa;
        int sl;
        int braga;
        int sb;
        int faro;
        int sf;
        int setubal;
        int ss;
} *CIDADE;

typedef struct data2{
        int dia;
        int mes;
        int ano;
} DATA2;

typedef struct hDrivers {
        GHashTable *driver;
} *HASHDRIVER;

typedef struct driver{
        int id;
        char* name;
        DATA2 birth_date;
        int gender;
        char* car_class;
        char* license_plate;
        int city;
        DATA2 account_creation;
        char* account_status;
} *DRIVER;

DATA2 atribuiData (char* data){
        int i;
        char *temp, *aux;
        DATA2 data2;
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

int genderToint (char* gender){
        int g;
        if (gender == "M") {
                g = 0;
                return g;
        }
        else if (gender == "F"){
                g = 1;
                return g;
        }
}

int classeToint (char* classe){
        int c;
        if (classe == "Basic") {
                c = 0;
                return c;
        }
        else if (classe == "Green"){
                c = 1;
                return c;
        }
        else if (classe == "Premium"){
                c = 2;
                return c;
        }
}



int atribuiCidade (char* cidade){
	int c;
	if (cidade == "Porto"){
		c=0;
		return c;
	}
	else if (cidade == "Lisboa"){
		c=1;
		return c;
	}
	else if (cidade == "Braga"){
		c=2;
		return c;
	}
	else if (cidade == "Faro"){
		c=3;
		return c;
	}
	else if (cidade == "Setúbal"){
		c=4;
		return c;
	}
}


DRIVER inicializaDriver (int id,char* name, DATA2 birth_date, int gender,char* car_class,char* license_plate, int city, DATA2 account_creation,char* account_status){
	DRIVER driver = malloc (sizeof(DRIVER));
	driver->id = id;
	driver->name = name;
	driver->birth_date = birth_date;
        driver->gender = gender;
        driver->car_class = car_class;
        driver->license_plate = license_plate;
        driver->city = city;
	driver->account_creation = account_creation;
	driver->account_status = account_status;
	return driver;
}

void adicionaDriver (HASHDRIVER h,DRIVER driver){
	g_hash_table_insert (h->driver,&(driver->id),driver);
}

int getCidade (DRIVER d){
	return d->city;
}

