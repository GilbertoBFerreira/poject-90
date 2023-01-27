#include "../includes/rides.h"

#define LINHAS 1000000

void acrescentaRide (RIDEL ridel, RIDE ride) {
    RIDEL new = malloc(sizeof(RIDEL));
    new->curr_ride = ride;
    new->next = NULL;
    if(ridel->curr_ride == NULL) ridel = new;
    else {
        RIDEL temp;
        while(ridel->next != NULL) {
            temp = ridel->next;
        }
        temp = new;
	free(temp);
    }
}

int adicionarR(char* line, RIDEL h){
    int id,driver,distance,score_user, score_driver;
    float tip;
    char* fields = strdup(line);
    DATA3 date;
    RIDE ride;
    char resto;
    char *temp , *name, *city, *user, *comment;
    int res = 1;

    for(int i=0; (temp =(strsep(&fields, ";"))) != NULL && i<10; i++){
        switch (i){
            case 0:
                id = atoi (strdup (temp));
                break;
            case 1:
                date = atribuiData3 (strdup(temp));
                break;
            case 2:
                driver = atoi (strdup(temp));
                break;
            case 3:
                user = strdup (temp);
                break;
            case 4:
                city = strdup(temp);
                break;
            case 5:
                distance = atoi (strdup (temp));
                break;
            case 6:
                score_user = atoi (strdup (temp));
                break;
            case 7:
                score_driver = atoi (strdup (temp));
                break;
            case 8:
                tip = atof (strdup (temp));
                break;
            case 9:
                comment = strdup (temp);
            }
	}
    ride = inicializaRide(id,date,driver, user, city,distance, score_user, score_driver, tip, comment);
    while (h->curr_ride != NULL) h = h->next;
    acrescentaRide (h,ride);
    
    res = 0;

    return res;
}
    

void adicionarRide(RIDEL h){
    FILE *f = fopen ("ficheiros/rides.csv", "r+");
    char* file = malloc(sizeof(char*)*LINHAS);

    while(fgets(file, LINHAS, f)){
        char *temp = strdup(file);
        char *line = strdup((strsep(&temp, "\n")));
        adicionarR(line, h);
    }
    fclose(f);
}

