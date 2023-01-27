#include "../includes/parseDrives.h"

#define LINHAS 10000

int adicionarD(char *line, HASHDRIVER h){
    int id;
    char *fields = strdup(line);
    DATA2 birth_date, account_creation;
    int city,gender;
    char resto;
    char *temp ,*name, *account_status, *car_class, *license_plate ;
    DRIVER driver;
    int res = 1;

    for(int i=0; (temp =(strsep(&fields, ";"))) != NULL && i<9; i++){
        switch (i){
            case 0:
                id = atoi (strdup (temp));
                break;
            case 1:
                name = strdup (temp);
                break;
            case 2:
                birth_date = atribuiData (strdup(temp));
                break;
            case 3:
                gender = genderToint (strdup (temp));
                break;
            case 4:
                car_class = strdup(temp);
                break;
            case 5:
                license_plate = strdup (temp);
                break;
            case 6:
                city = atribuiCidade(strdup (temp));
                break;
            case 7:
                account_creation = atribuiData (strdup(temp));
                break;
            case 8:
                account_status = strdup (temp);
                break;
            }
	}
    driver = inicializaDriver(id,name,birth_date,gender,car_class,license_plate,city,account_creation,account_status);
    if (g_hash_table_lookup(h->driver,&id) == NULL) adicionaDriver (h,driver);
    else res = 0;
   return res; 
}

void adicionarDrivers(HASHDRIVER h){
    FILE *f = fopen ("ficheiros/drivers.csv", "r+");
    char* file = malloc(sizeof(char*)*LINHAS);
        while(fgets(file, LINHAS, f)){
        char *temp = strdup(file);
        char *line = strdup((strsep(&temp, "\n")));
        adicionarD(line, h);
	}
    fclose(f);
}

