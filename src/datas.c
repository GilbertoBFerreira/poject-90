#include "../includes/datas.h"

DATA atribuiData (char* data){
        int i;
        char *temp, *aux;
        DATA novaData;
        aux = strdup (data);
	temp = (strsep(&aux,"/"));
	novaData->dia = atoi(strdup(temp));
	temp = (strsep(&aux,"/"));
	novaData->mes = atoi(strdup(temp));
	temp = (strsep(&aux,"/"));
	novaData->ano = atoi(strdup(temp));
        return novaData;
}
