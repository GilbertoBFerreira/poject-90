#include "../includes/users.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

USER inicializaUser (char* username,char* name, int gender,DATA birth_date,DATA account_creation,char* pay_method,char* account_status) {
	USER user = malloc (sizeof(USER));
	user->username = username;
	user->name = name;
	user->gender = gender;
	user->birth_date = birth_date;
	user->account_creation = account_creation;
	user->account_status = account_status;
	return user;
}

void adicionaUser (HASHUSER h,USER user){
	g_hash_table_insert (h->user,user->username,user);
}


