#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Px_Info{
	char category[20];
	char LastName[20];
	char FirstName[20];
	char MiddleName[20];
	char Contacts[20];
	
	struct Px_Adress{
		char HouseNo[20];
		char Street[20];
		char Barangay[20];
		char City[20];
		char Province[20];
		
		char Sex[20];
		char DateofBirth[20];
		char Vaccine[20];
		char VaccineDate[20];
	}a;
};
void getDetails(struct Px_Info p);
void importFile(struct Px_Info p);
void displayInfo();
int main(){
	int opt;
	
	while(true){
	
	printf("[1] - Add New record\n");
	printf("[2] - Import Record\n");
	printf("[3] - Display All Records\n");
	printf("[4] - Exit\n");
	printf("What Do you want to do?\n");
	scanf("%d",&opt);
	
	switch(opt){
		case 1:
			struct Px_Info P1;
				
			printf("Enter Category: \n");
			scanf(" %[^\n]",P1.category);
			printf("Enter Last Name: \n");
			scanf(" %[^\n]",P1.LastName);
			printf("Enter First Name: \n");
			scanf(" %[^\n]",P1.FirstName);
			printf("Enter Middle Name: \n");
			scanf(" %[^\n]",P1.MiddleName);
			printf("Enter Contacts: \n");
			scanf(" %[^\n]",P1.Contacts);
			printf("~~Address~~\n");
			printf("Enter House Number: \n");
			scanf(" %[^\n]",P1.a.HouseNo);
			printf("Enter Street: \n");
			scanf(" %[^\n]",P1.a.Street);
			printf("Enter Barangay: \n");
			scanf(" %[^\n]",P1.a.Barangay);
			printf("Enter City: \n");
			scanf(" %[^\n]",P1.a.City);
			printf("Enter Province: \n");
			scanf(" %[^\n]",P1.a.Province);
			printf("Enter Sex: \n");
			scanf(" %[^\n]",P1.a.Sex);
			printf("Enter Date of Birth: \n");
			scanf(" %[^\n]",P1.a.DateofBirth);
			printf("Enter Vaccine Manufacturer: \n");
			scanf(" %[^\n]",P1.a.Vaccine);
			printf("Enter Vaccination Date: \n");
			scanf(" %[^\n]",P1.a.VaccineDate);
			printf("YOUR RECORD HAS BEEN SAVED SUCCESSFULLY\n");
			getDetails(P1);
			system("pause");
			system("cls");
			break;
		case 2:
			struct Px_Info P2;
			printf("Enter File Name: \n");
			scanf("%s",P2.FirstName);
			importFile(P2);
			
			system("pause");
			system("cls");
			break;
		case 3:
			printf("Displaying Records...\n");
			displayInfo();
			system("pause");
			system("cls");
			break;
		case 4:
			return(0);
			
		default:
			printf("Invalid Input! Please Try Again\n");
			system("pause");
			system("cls");
			
	}
	
}	
}
void getDetails(struct Px_Info p){
	
	FILE *fp = fopen("Vaxx.txt","a");
	fprintf(fp, "Category: %s\n",p.category);
	fprintf(fp, "Last Name: %s\n",p.LastName);
	fprintf(fp, "First Name: %s\n",p.FirstName);
	fprintf(fp, "Middle Name: %s\n",p.MiddleName);
	fprintf(fp, "Contact Number: %s\n",p.Contacts);
	
	fprintf(fp, "House Number: %s\n",p.a.HouseNo);
	fprintf(fp, "Street: %s\n",p.a.Street);
	fprintf(fp, "Barangay: %s\n",p.a.Barangay);
	fprintf(fp, "City: %s\n",p.a.City);
	fprintf(fp, "Province: %s\n",p.a.Province);
	fprintf(fp, "Sex: %s\n",p.a.Sex);
	fprintf(fp, "Date of Birth: %s\n",p.a.DateofBirth);
	fprintf(fp, "Vaccine Manufacturer: %s\n",p.a.Vaccine);
	fprintf(fp, "Vaccination Date: %s\n",p.a.VaccineDate);

	fclose(fp);
}
void importFile(struct Px_Info p){
	
	FILE *fp;
	char *fName = p.FirstName;
	
	fp = fopen(fName,"r");
	if(fp == NULL){
        printf("File does not exist... Unable to proceed\n");
    }
    else{
    
    char singleLine[150];
	
	while(!feof(fp)){
		fgets(singleLine, 150,fp);
		
		FILE *fpointer = fopen("Vaxx.txt","a");
		printf("%s",singleLine);
		fprintf(fpointer, "%s",singleLine);
		fclose(fpointer);
		
	
	};
		printf("\n");
		printf("RECORD HAS BEEN IMPORTED SUCCESSFULLY\n");
        fclose(fp);
	}
}
void displayInfo(){
	
	FILE *fp = fopen("Vaxx.txt","r");
	
	char singleLine[150];
	
	while(!feof(fp)){
		fgets(singleLine, 150,fp);
		printf("%s",singleLine);
	};
	fclose(fp);
	
}


















































