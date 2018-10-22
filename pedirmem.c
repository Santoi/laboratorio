#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define LEN 10

typedef enum {
	FEMALE,
	MALE,
	OTHER
} gender_t;

typedef struct birthday {
		int day;
		int month;
		int year;
} birthday_t;

typedef struct {
	char name[MAX_NAME];
	birthday_t * date;
	gender_t gender;
} person_t;

person_t * save_data(int);

int main(void){
	person_t * person;
	int cant;
	char cant_str [LEN], *endp;
	puts("Ingresar cantidad de personas");
	fgets(cant_str, LEN, stdin);
	cant = strtol(cant_str, &endp, 10);
	person = save_data(cant);
	if(!person)
		fprintf(stderr, "%s\n", "no mem");
	else{
		for (size_t i = 0; i < cant; i++){
			printf("nombre: %s\n", person[i].name);
			printf("fecha de nacimiento: %d/%d/%d\n", person[i].date->day, person[i].date->month, person[i].date->year);
		}
	}
	return 0;
}

person_t * save_data(int cant){
	person_t * person;
	char aux[LEN], *endp;
	gender_t gen;
	
	if(!(person = (person_t *) malloc (sizeof(person_t) * cant)))
		return NULL;
		
	for (size_t i = 0; i < cant; i++){
		puts("nombre");
		fgets(person[i].name, MAX_NAME, stdin);
		// saco el \n
		person[i].name[strlen(person[i].name) - 1] = '\0';
		
		puts("genero:\n1. mujer\n2. hombre\n3. otro");
		fgets(aux, LEN, stdin);
		gen = strtol(aux, &endp, 10);
		
		switch(gen){
			case FEMALE:
				person[i].gender = FEMALE;
				break;
			case MALE:
				person[i].gender = MALE;
				break;
			case OTHER:
				person[i].gender = OTHER;
				break;
			default:
				puts("mal jeje");
				break;
		}
		
		if(!(person[i].date = (birthday_t *) malloc (sizeof(birthday_t))))
			return NULL;
		puts("ingresar fecha de nacimiento");
		puts("anio");
		fgets(aux, LEN, stdin);
		person[i].date->year = strtol(aux, &endp, 10);
		
		puts("mes");
		fgets(aux, LEN, stdin);
		person[i].date->month = strtol(aux, &endp, 10);
		
		puts("dia");
		fgets(aux, LEN, stdin);
		person[i].date->day = strtol(aux, &endp, 10);
	}
	return person;
}	