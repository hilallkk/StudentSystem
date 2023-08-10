#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>

struct student{
	char name[20];
	char surname[20];
	char department[30];
	int sno;
	int sclass;
}class1;

void homepage();
int main();
int counter;
int search();
int add();
int searchByName();
void deleteRecord();
void show();
void gotoxy(int,int);

int change(){
	printf("a");
	
		system("cls");
	int button,no,readed,readed1,tno,tclass,tchange,button1;
	char tname[20],tsurname[20],tdepartment[30];
	FILE *fptr1,*fptr2;
	bool situation=false;
	fptr1=fopen("C:\\Users\\Hilal\\Desktop\\record.txt","r");
	printf("Please enter the number you are looking for:");
	scanf("%d",&no);
	while(!feof(fptr1)){
		fscanf(fptr1,"%s%s%s%d%d",class1.name,class1.surname,class1.department,&class1.sno,&class1.sclass);
		readed++;
		if(no==class1.sno){
			situation=true;
			printf("\nName:%s\nSurname:%s\nDepartment:%s\nNo:%d\nClass:%d\n",class1.name,class1.surname,class1.department,class1.sno,class1.sclass);
			printf("Press the 2 for edit record:");
			scanf("%d",&button);
			if(button==2){
				printf("\n---EDIT---");
				printf("\nName:");
				scanf("%s",tname);
				printf("\nSurname:");
				scanf("%s",tsurname);
				printf("\nDepartment:");
				scanf("%s",tdepartment);
				printf("\nNo:");
				scanf("%d",&tno);
				printf("\nClass:");
				scanf("%d",&tclass);
                fclose(fptr1);
                break;
                
		}
		}
				situation=false;
}
		printf("\nPress 3 if you want to save the edit, press 4 if you want to discard the changes:");
		scanf("%d",&tchange);
		if(tchange==4){
					printf("\nChanges discard");
				}
					
    	else if(tchange==3){
		fptr1=fopen("C:\\Users\\Hilal\\Desktop\\record.txt","r");
		fptr2=fopen("C:\\Users\\Hilal\\Desktop\\record2.txt","a+");
    	while(!feof(fptr1)){
		fscanf(fptr1,"%s%s%s%d%d",class1.name,class1.surname,class1.department,&class1.sno,&class1.sclass);
		if(no!=class1.sno){
			fprintf(fptr2,"\n%s\n%s\n%s\n%d\n%d",class1.name,class1.surname,class1.department,class1.sno,class1.sclass);
		}
		readed1++;
	}
    fprintf(fptr2,"\n%s\n%s\n%s\n%d\n%d",tname,tsurname,tdepartment,tno,tclass);
    fclose(fptr2);
    fclose(fptr1);
    printf("\nChanges saved");
    remove("record.txt");
    rename("record2.txt","record.txt");
}

    
        printf("\nPress 1 to return to the homepage,press 2 to end the process:\n");
	scanf("%d",&button1);
	switch(button1){
		case 1:
			homepage();
			break;
		case 2:
			exit(0);
			break;
	
	}
   
}
int search(){
	system("cls");
	int button,no,readed;
	FILE *fptr1;
	bool situation=false;
	fptr1=fopen("C:\\Users\\Hilal\\Desktop\\record.txt","r");
	printf("Please enter the number you are looking for:");
	scanf("%d",&no);
	while(!feof(fptr1)){
		fscanf(fptr1,"%s%s%s%d%d",class1.name,class1.surname,class1.department,&class1.sno,&class1.sclass);
		readed++;
		if(no==class1.sno){
			situation=true;
			printf("\nName:%s\nSurname:%s\nDepartment:%s\nNo:%d\nClass:%d\n",class1.name,class1.surname,class1.department,class1.sno,class1.sclass);
		}
    }
    fclose(fptr1);
    
    if(situation==false){
    	printf("\nStudent not found");
	}
    printf("\nPress 1 to return to the homepage,press 2 to search another number,press 3 to end the process:\n");
	scanf("%d",&button);
	switch(button){
		case 1:
			homepage();
			break;
		case 2:
			search();
			break;
		case 3:
			exit(0);
			break;
	
	}
     
}
int searchByName(){
	system("cls");
	FILE *fptr1;
	int i,readed,button;
	bool situation=false;
	char name[20];
	printf("Please enter the name you are looking for:");
	scanf("%s",name);
	fptr1=fopen("C:\\Users\\Hilal\\Desktop\\record.txt","r");
	while(!feof(fptr1)){
		fscanf(fptr1,"%s%s%s%d%d",class1.name,class1.surname,class1.department,&class1.sno,&class1.sclass);
		readed++;
		if(strcmp(class1.name,name)==0){
			situation=true;
			printf("\nName:%s\nSurname:%s\nDepartment:%s\nNo:%d\nClass:%d\n",class1.name,class1.surname,class1.department,class1.sno,class1.sclass);
		}
	} 
	fclose(fptr1);
	
	if(situation==false){
		printf("\nStudent not found");
	}
	
	printf("\nPress 1 to return to the homepage,press 2 to search another name,press 3 to end the process:\n");
	scanf("%d",&button);
	switch(button){
		case 1:
			homepage();
			break;
		case 2:
			searchByName();
			break;
		case 3:
			exit(0);
			break;
	
	}
}
int add(){
	system("cls");
	FILE *fptr1,*fptr2;
	fptr1=fopen("C:\\Users\\Hilal\\Desktop\\record.txt","a+");
	fptr2=fopen("C:\\Users\\Hilal\\Desktop\\record.txt","r");
	bool h;
	int choice,button;
    int i,readed,temporary;	
	    do{
	    
	    bool situation1=true;
		while(situation1==true){
		int flag=0;
		printf("No:");
		scanf("%d",&temporary);
		while(!feof(fptr2)){
		  fscanf(fptr2,"%s%s%s%d%d",class1.name,class1.surname,class1.department,&class1.sno,&class1.sclass);
		   if(temporary==class1.sno){
		   	flag++;
		   }
	}
	 if(flag==0){
	 	situation1=false;
	 }
	 else if(flag>0){
	 	printf("Number you entered is used.Try again\n");
	 }
}
	
	if(situation1==false){
		class1.sno=temporary;
	}	
		printf("Name:");
		scanf("%s",class1.name);
		printf("Surname:");
		scanf("%s",class1.surname);
		printf("Department:");
		scanf("%s",class1.department);

	
		printf("Class:");
		scanf("%d",&class1.sclass);
		fprintf(fptr1,"\n%s\n%s\n%s\n%d\n%d",class1.name,class1.surname,class1.department,class1.sno,class1.sclass);
		printf("For add press 1,to finish press any button(must be a number):\n");
		scanf("%d",&choice);
		counter++;
		if(choice==1){
			h=false;
		}
		else{
			h=true;
		}
	}while(h==false);
	fclose(fptr1);
	fclose(fptr2);
	printf("Press 1 to return to the homepage, press 2 to end the process:\n");
	scanf("%d",&button);
	switch(button){
		case 1:
			homepage();
			break;
		case 2:
			exit(0);
			break;

	
}
}

void deleteRecord(){
	system("cls");
	FILE *fptr1,*fptr2;
	int no,readed=0,button,flag=0;
	fptr1=fopen("C:\\Users\\Hilal\\Desktop\\record.txt","r");
	fptr2=fopen("C:\\Users\\Hilal\\Desktop\\record2.txt","a+");
	printf("Enter the number of the student you want to deregister:");
	scanf("%d",&no);
	while(!feof(fptr1)){
		fscanf(fptr1,"%s%s%s%d%d",class1.name,class1.surname,class1.department,&class1.sno,&class1.sclass);
		if(no!=class1.sno){
			fprintf(fptr2,"\n%s\n%s\n%s\n%d\n%d",class1.name,class1.surname,class1.department,class1.sno,class1.sclass);
			
		}
		else if(no==class1.sno){
			flag++;
		}
		readed++;
	}
	if(flag==0){
		printf("No records found");
	}
	else if(flag>0){
		printf("Student registration deleted");
	}
	fclose(fptr1);
	fclose(fptr2);
	
	remove("record.txt");
	rename("record2.txt","record.txt");
	
	printf("\nPress 1 to return to the homepage, press 2 to delete the record,press 3 to end the process:\n");
	scanf("%d",&button);
	switch(button){
		case 1:
			homepage();
			break;
		case 2:
			deleteRecord();
			break;
        case 3:
        	exit(0);
        	break;
	
}
	
}

void show(){
	system("cls");
	FILE *fptr1;
	int readed,i,process;
    fptr1=fopen("C:\\Users\\Hilal\\Desktop\\record.txt","r");

	
	printf("------------STUDENT LIST------------");
	while(!feof(fptr1)){
		fscanf(fptr1,"%s%s%s%d%d",class1.name,class1.surname,class1.department,&class1.sno,&class1.sclass);
		readed++;
		printf("\n%d\nName:%s\nSurname:%s\nDepartmen:%s\nNo:%d\nClass:%d\n",readed,class1.name,class1.surname,class1.department,class1.sno,class1.sclass);
	}
    fclose(fptr1);
    printf("\n");
    printf("*********");
    printf("\nCurrent:%d",readed);
    printf("\nPress 1 to return to the homepage, press 2 to end the process:\n");
	scanf("%d",&process);
	switch(process){
		case 1:
			homepage();
			break;
		case 2:
			exit(0);
			break;
	
	}
}

void homepage(){
	int process;
	system("cls");
	gotoxy(30,8);
	printf("1.Student Search By Number");
	gotoxy(30,10);
	printf("2.Add Student");
	gotoxy(30,12);
	printf("3.Delete Student");
	gotoxy(30,14);
	printf("4.Show Class");
	gotoxy(30,16);
	printf("5.Student Search By Name");
	gotoxy(30,18);
	printf("6.Change Record");
	gotoxy(30,20);
	printf("7.Exit");
	gotoxy(30,22);

	printf("Click the action you want to do:");
	scanf("%d",&process);
	switch(process){
		case 1:
			search();
			break;
		case 2:
			add();
			break;
		case 3:
			deleteRecord();
			break;
		case 4:
			show();
			break;
		case 5:
			searchByName();
			break;
		
		case 6:
			change();
			break;
		
		case 7:
			system("cls");
			printf("Exiting...");
			exit(0);
			break;
		     	
	}
}

void gotoxy(int x,int y)
{
	COORD coord ;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int main(){
	
	char enickn[20],tnickn[20]="hilal";   //enickn---(entered nick name ,tnickn---(true nick name)
	char tpswrd[6]="keles";             //tpswrd---(true password)
	char epswrd[6];                    //epswrd---(entered password)                        
    int i;
	bool spswrd=true,snickn=true;     //spswrd---(situation password) ,snickn---(situation nickname)
	//bool kno=true;
	gotoxy(50,10);
    printf("...WELCOME...");
    gotoxy(40,12);
    printf("You Are Redirected To The Login Screen");
    sleep(2);
    while(spswrd!=false && snickn!=false){
    int flag=0,flag1=0;
    system("cls");
    gotoxy(30,10);
    printf("NickName:");
    scanf("%s",enickn);
    for(i=0;i<5;i++){
    	if(tnickn[i]!=enickn[i]){
    		flag1++;
		}
    	
	}
	gotoxy(30,12);
    printf("Password: ");  
    for (i = 0; i < 5; i++)  
    {  
        epswrd[i] = getch();  
        printf("*");   
    }  
    epswrd[i] = '\0';  
    printf( "\n" );  
for(i=0;i<5;i++){
	if(tpswrd[i]!=epswrd[i]){
	    flag++;	
	}
}
   	if(flag==0  && flag1==0){
		spswrd=false;
		snickn=false;
		homepage();
	}
	else{
        if(flag1>0 & flag>0){
        	gotoxy(30,14);
        	printf("No records found");
		}
		else if(flag>0){
			gotoxy(30,14);
			printf("Wrong password");
		}
		else if(flag1>0){
			gotoxy(30,14);
			printf("Wrong nickname");
		}
		gotoxy(30,16);
		printf("Try again\n");
		sleep(2);
	}
	}
    
    
}
