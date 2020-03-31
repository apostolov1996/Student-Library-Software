#include <stdio.h>
#include <string.h>
#define MAXCHAR 20
#define MAXSTUDENT 100
typedef struct {
	char name[MAXCHAR];
	char surname[MAXCHAR];
	char city [MAXCHAR];
	int year;
} Students;

int main () {
	/* VARIABLES */
	Students student[MAXSTUDENT];
	Students coppyStudent[MAXSTUDENT];
	Students changePosition;
	char null[1];
	int i;
	int j;
	int position;
	int k;
	int nonEmptyCounter;
	int emptyCounter;
	int operation;
	int turnback;
	char city[MAXCHAR];
	int different;
	int max;
	
	null[0]='\0';
	null[1]='\0';
	
	FILE *years;
	FILE *names;
	FILE *surnames;
	FILE *cities;
	
	/* STUDENTS DATA
	
	1) Here you can insert data about the students.
	2) If the slot is empty, we have empty strings (name, surname, city) and year=0
	
	*/
	
	/* DATA INPUT*/
	years=fopen("years.txt", "r");
	names=fopen("names.txt", "r");
	surnames=fopen("surnames.txt", "r");
	cities=fopen("cities.txt", "r");
	if(years&&names&&surnames&&cities) {
	    for (i=0; i<MAXSTUDENT; i=i+1) {
		    fscanf(years, "%d", &student[i].year);
		    fscanf(names, "%s", student[i].name);
		    fscanf(surnames, "%s", student[i].surname);
		    fscanf(cities, "%s", student[i].city);
		}
	} else {
		printf("Error. Can't open data files.");
	}
	fclose(years);
	fclose(names);
	fclose(surnames);
	fclose(cities);
	printf("YOUR PERSONAL STUDENT LIST LIBRARY!\n");
	
	/* MENU */
	do {
		printf("______________________________________________________________________\n");
		printf("1) Insert a new student on the first place of the list.\n");
		printf("2) Insert a new student on the end of the list.\n");
		printf("3) Cancell student information.\n");
		printf("4) General view of the student list.\n");
		printf("5) Order the student list. (From younger to older).\n");
		printf("6) Exit.\n");
		printf("Operation: ");
		scanf("%d", &operation);
		
		if (operation==1) {
			printf("This option allows you to insert a new student at the first position of the list.\n");
			printf("Please insert the requested data.\n");
			printf("______________________________________________________________________\n");
			/* OPERATIONS */
			/* Calculate non empty slots*/
			nonEmptyCounter=0;
			for (i=0; i<MAXSTUDENT; i=i+1) {
				if (student[i].year!=0) {
					nonEmptyCounter=nonEmptyCounter+1;
				}else{
				}
			}
			emptyCounter=MAXSTUDENT-nonEmptyCounter;
			printf("You have %d empty slots.\n", emptyCounter);
			/* INSERT NEW STUDENTS IF WE HAVE FREE SPACE */
			if (emptyCounter!=0) {
				for (i=0; i<MAXSTUDENT; i=i+1) {
					coppyStudent[i+1].year=student[i].year;
					strcpy(coppyStudent[i+1].name, student[i].name);
					strcpy(coppyStudent[i+1].surname, student[i].surname);
					strcpy(coppyStudent[i+1].city, student[i].city);
				}
				printf("Insert student name: ");
				scanf("%s", coppyStudent[0].name);
				printf("Insert student surname: ");
				scanf("%s", coppyStudent[0].surname);
				printf("Insert student borncity: ");
				scanf("%s", coppyStudent[0].city);
				printf("Insert student bornyear: ");
				scanf("%d", &coppyStudent[0].year);
				for (i=0; i<MAXSTUDENT; i=i+1) {
					student[i].year=coppyStudent[i].year;
					strcpy(student[i].name, coppyStudent[i].name);
					strcpy(student[i].surname, coppyStudent[i].surname);
					strcpy(student[i].city, coppyStudent[i].city);
				}
			} else {
				printf("You don't have enough free space. Please cancell some data and try again.\n");
			}
			/* DATA SAVINGS INTO SOLID DIRECTORY .TXT FILES */
			years=fopen("years.txt", "w");
			names=fopen("names.txt", "w");
			surnames=fopen("surnames.txt", "w");
			cities=fopen("cities.txt", "w");
			if (years&&names&&surnames&&cities) {
				for (i=0; i<MAXSTUDENT; i=i+1) {
					fprintf(years, "%d\n", student[i].year);
					fprintf(names, "%s\n", student[i].name);
					fprintf(surnames, "%s\n", student[i].surname);
					fprintf(cities, "%s\n", student[i].city);
				}
			} else {
				printf("Can't open data files.\n");
			}
			fclose(years);
			fclose(names);
			fclose(surnames);
			fclose(cities);
			/* END OF DATA SAVINGS, NEW OPTION REQUEST*/
			printf("______________________________________________________________________\n");
			printf("Insert 0 to turn back at the main menu.\n");
			printf("Insert any other number to exit from the software.\n");
			printf("Operation: ");
			scanf("%d", &turnback);
		} else if (operation==2) {
			printf("This operation allows you to insert a new student at the end of the list.\n");
			printf("Please insert the requested data.\n");
			printf("______________________________________________________________________\n");
			/*OPERATIONS */
			/* Calculate non empty slots */
			nonEmptyCounter=0;
			for (i=0; i<MAXSTUDENT; i=i+1) {
				if (student[i].year!=0) {
					nonEmptyCounter=nonEmptyCounter+1;
				}else{
				}
			}
			emptyCounter=MAXSTUDENT-nonEmptyCounter;
			printf("You have %d empty slots.\n", emptyCounter);
			/* DATA SAVE IF WE HAVE ENOUGH FREE SPACE */
			if (emptyCounter!=0) {
			    printf("Insert student name: ");
			    scanf("%s", student[nonEmptyCounter].name);
			    printf("Insert student surname: ");
			    scanf("%s", student[nonEmptyCounter].surname);
			    printf("Insert student borncity: ");
			    scanf("%s", student[nonEmptyCounter].city);
			    printf("Insert student bornyear: ");
			    scanf("%d", &student[nonEmptyCounter].year);
			} else {
				printf("You don't have enough free space. Please cancell some data and try again.\n");
			}
			/* DATA SAVINGS INTO SOLID .TXT DATA DIRECTORY */
			years=fopen("years.txt", "w");
			names=fopen("names.txt", "w");
			surnames=fopen("surnames.txt", "w");
			cities=fopen("cities.txt", "w");
			if (years&&names&&surnames&&cities) {
				for (i=0; i<MAXSTUDENT; i=i+1) {
					fprintf(years, "%d\n", student[i].year);
					fprintf(names, "%s\n", student[i].name);
					fprintf(surnames, "%s\n", student[i].surname);
					fprintf(cities, "%s\n", student[i].city);
				}
			} else {
				printf("Can't open data files.\n");
			}
			fclose(years);
			fclose(names);
			fclose(surnames);
			fclose(cities);
			printf("______________________________________________________________________\n");
			printf("Insert 0 to turn back at the main menu.\n");
			printf("Insert any other number to exit from the software.\n");
			printf("Operation: ");
			scanf("%d", &turnback);
		} else if (operation==3) {
			printf("This option cancells information data about every student born in the inserted city.\n");
			printf("______________________________________________________________________\n");
			/* OPERATIONS */
			printf("Insert city: ");
			scanf("%s", city);
			for (i=0; i<MAXSTUDENT; i=i+1) {
				different=strcmp(student[i].city, city);
				if (different==0) {
					strcpy(student[i].city, null);
					strcpy(student[i].name, null);
					strcpy(student[i].surname, null);
					student[i].year=0;
				} else {
				}
			} 
			for (i=0; i<MAXSTUDENT; i=i+1) {
				strcpy(coppyStudent[i].name, null);
				strcpy(coppyStudent[i].surname, null);
				strcpy(coppyStudent[i].city, null);
				coppyStudent[i].year=0;
			}
			for (i=0; i<MAXSTUDENT; i=i+1) {
				for (j=0; j<MAXSTUDENT; j=j+1) {
					if (student[j].year!=0) {
						strcpy(coppyStudent[i].name, student[j].name);
						strcpy(coppyStudent[i].surname, student[j].surname);
						strcpy(coppyStudent[i].city, student[j].city);
						coppyStudent[i].year=student[j].year;
						strcpy(student[j].name, null);
						strcpy(student[j].surname, null);
						strcpy(student[j].city, null);
						student[j].year=0;
						j=MAXSTUDENT;
					}else{
					}
				}
			}
			for (i=0; i<MAXSTUDENT; i=i+1) {
				strcpy(student[i].name, coppyStudent[i].name);
				strcpy(student[i].surname, coppyStudent[i].surname);
				strcpy(student[i].city, coppyStudent[i].city);
				student[i].year=coppyStudent[i].year;
			} 
			/* DATA SAVINGS */
			years=fopen("years.txt", "w");
			names=fopen("names.txt", "w");
			surnames=fopen("surnames.txt", "w");
			cities=fopen("cities.txt", "w");
			if (years&&names&&surnames&&cities) {
				for (i=0; i<MAXSTUDENT; i=i+1) {
					fprintf(years, "%d\n", student[i].year);
					fprintf(names, "%s\n", student[i].name);
					fprintf(surnames, "%s\n", student[i].surname);
					fprintf(cities, "%s\n", student[i].city);
				}
			} else {
				printf("Can't open data files.\n");
			}
			fclose(years);
			fclose(names);
			fclose(surnames);
			fclose(cities);
			printf("______________________________________________________________________\n");
			printf("Insert 0 to turn back at the main menu.\n");
			printf("Insert any other number to exit from the software.\n");
			printf("Operation: ");
			scanf("%d", &turnback);
		} else if (operation==4) {
			printf("This option shows you the full student list.\n");
			printf("______________________________________________________________________\n");
			/* OPERATIONS */
			for (i=0; i<MAXSTUDENT; i=i+1) {
				if (student[i].year!=0) {
				   printf("Student %d\n", i+1);
				   printf("Name: %s\n", student[i].name);
				   printf("Surname: %s\n", student[i].surname);
				   printf("Borncity: %s\n", student[i].city);
				   printf("Bornyear: %d\n", student[i].year);
				   printf("______________________________________________________________________\n");
			    } else {
				}
			}
			printf("______________________________________________________________________\n");
			printf("Insert 0 to turn back at the main menu.\n");
			printf("Insert any other number to exit from the software.\n");
			printf("Operation: ");
			scanf("%d", &turnback);
		} else if (operation==5) {
			printf("This option allows you to order properly the student list. After this operation the list is going to be ordered on the next way:\n");
			printf("From the younger to the older student.\n");
			printf("______________________________________________________________________\n");
			/* OPERATIONS */
			for (i=0; i<MAXSTUDENT; i=i+1) {
				for (j=i; j<MAXSTUDENT; j=j+1) {
					if (student[i].year<=student[j].year){
						strcpy(changePosition.name, student[i].name);
						strcpy(changePosition.surname, student[i].surname);
						strcpy(changePosition.city, student[i].city);
						changePosition.year=student[i].year;
						strcpy(student[i].name, student[j].name);
						strcpy(student[i].surname, student[j].surname);
						strcpy(student[i].city, student[j].city);
						student[i].year=student[j].year;
						strcpy(student[j].name, changePosition.name);
						strcpy(student[j].surname, changePosition.surname);
						strcpy(student[j].city, changePosition.city);
						student[j].year=changePosition.year;
					} else {
					}
				}
			}
			/* DATA SAVINGS */
			years=fopen("years.txt", "w");
			names=fopen("names.txt", "w");
			surnames=fopen("surnames.txt", "w");
			cities=fopen("cities.txt", "w");
			if (years&&names&&surnames&&cities) {
				for (i=0; i<MAXSTUDENT; i=i+1) {
					fprintf(years, "%d\n", student[i].year);
					fprintf(names, "%s\n", student[i].name);
					fprintf(surnames, "%s\n", student[i].surname);
					fprintf(cities, "%s\n", student[i].city);
				}
			} else {
				printf("Can't open data files.\n");
			}
			fclose(years);
			fclose(names);
			fclose(surnames);
			fclose(cities);
			printf("______________________________________________________________________\n");
			printf("Insert 0 to turn back at the main menu.\n");
			printf("Insert any other number to exit from the software.\n");
			printf("Operation: ");
			scanf("%d", &turnback);
		} else if (operation==6) {
			turnback=1;
		} else {
			printf("Non supported operation.\n");
			turnback=0;
		}
	} while (turnback==0);
	
	printf("\nGoodbye!\n");
	
	
}
