/**==========================
LBYEC2B PROJECT
"Student Expense Tracker"
John Joe Jeffrey Cervantes
Kalvin Yap
==========================**/
#include<math.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int login();

class Menu{
	public:
		int display();
		int Input();
		int Remove();
		void Breakdown();
		int reset();
		void Exit();
};
class File{
	public:
		int readFile(int userNumber);
		int readFile2(int userNumber);
		int Total();
		int resetFile();
		void checker();
};

int main(){
	Menu m;
	File f;
	login();
	f.checker();
	m.display();	
}

int login(){
	char username[20], password[20], ch;
	int characters=0;

	retry: //for goto 
	cout<<"\nEnter your username: ";
	cin>>username;
	cout<<"Enter your password: ";
	characters=0;
	while (1){
		ch = getch();
		if (ch == 13){
			password[characters]='\0';
			break;
		}
		else if (ch == 8){
			if (characters>0){
				characters--;
				cout<<("\b \b");
			}
		}
		else{
			password[characters++]=ch;
			cout<<("* \b");
		}
	}
			
    if(strcmp(username,"animo") == 0 && strcmp(password,"lasalle") == 0){
    	cout<<"\n\nSuccessful Login!\n";
    	system ("Pause");
    	system ("cls");
    	return 1;
	}
	else if(strcmp(username,"admin") == 0 && strcmp(password,"pass") == 0){
    	cout<<"\n\nSuccessful Login!\n";
    	system ("Pause");
    	system ("cls");
    	return 2;
	}
	else{
		cout<<"\n\nThe username or password you entered is incorrect.\n";
			goto retry;
	}
}	

Menu::display(){
	Menu m;
	File f;
	int Choice, total;
	up:
		total = f.Total();
	printf("\n==========================================\n");
	printf("\t STUDENT EXPENSES TRACKER");
	printf("\n==========================================\n");
	printf ("\t   Total Expsenses: %d\n",total);
	printf("==========================================\n");
	printf ("Choose An Option Below: \n\n");
	printf (" 1. Input Fees\n");
	printf (" 2. Remove Fees\n");
	printf (" 3. Expense Breakdown\n");
	printf (" 4. Reset Expenses\n");
	printf (" 5. Exit\n"); 
	scanf ("%d", &Choice);
	system ("cls");
	switch (Choice)
	{
	case 1: 
		m.Input();
	case 2: 
		m.Remove();
	case 3:
		m.Breakdown();
	case 4:
		m.reset();
	case 5: printf ("Thank You and Have a Great Day Ahead!\n");
		m.Exit();
		break;
	default: printf("Not in the Choices\n\n");
		goto up;
	}
}
Menu::Input(){
	File f;
	int input;
	printf("\n==========================================\n");
	printf("\t STUDENT EXPENSES TRACKER");
	printf("\n==========================================\n");
	printf("Choose Input\n\n");
	printf(" 1. Tuition\n");
	printf(" 2. Project Expenses\n");
	printf(" 3. Books\n");
	printf(" 4. Travel\n");
	printf(" 5. Food\n");
	printf(" 6. Misc\n");
	printf(" 7. Go Back\n");
	scanf("%d",&input);
	system ("cls");
	switch (input){
		case 1:
			f.readFile(1);
			display();
		case 2:
			f.readFile(2);
			display();
			
		case 3:
			f.readFile(3);
			display();
			
		case 4:
			f.readFile(4);
			display();
			
		case 5:
			f.readFile(5);
			display();
			
		case 6:
			f.readFile(6);
			display();
			
		case 7:
			display();
	}
	
}
Menu::Remove(){
	File f;
	int input;
	printf("\n==========================================\n");
	printf("\t STUDENT EXPENSES TRACKER");
	printf("\n==========================================\n");
	printf("Choose Input\n\n");
	printf(" 1. Tuition\n");
	printf(" 2. Project Expenses\n");
	printf(" 3. Books\n");
	printf(" 4. Travel\n");
	printf(" 5. Food\n");
	printf(" 6. Misc\n");
	printf(" 7. Go Back\n");
	scanf("%d",&input);
	system ("cls");
	switch (input){
		case 1:
			f.readFile2(1);
			display();
		case 2:
			f.readFile2(2);
			display();
			
		case 3:
			f.readFile2(3);
			display();
			
		case 4:
			f.readFile2(4);
			display();
			
		case 5:
			f.readFile2(5);
			display();
			
		case 6:
			f.readFile2(6);
			display();
			
		case 7:
			display();
	}
	
}
Menu::reset(){
	int Choice;
	Menu m;
	File f;
	strt:
	printf("\n==========================================\n");
	printf("\t      ARE YOU SURE?");
	printf("\n==========================================\n\n");
	printf ("\t 1. Yes\t\t 2.No\n\n");
	scanf ("%d", &Choice);
	system ("cls");
	switch (Choice)
	{
	case 1: 
		f.resetFile();
	case 2: 
		m.display();
	default:
		printf("Choose from the options given.\n\n");
	system("Pause");
	system("cls");
	m.display();
	}
}
File::readFile(int userNumber){
	char buf[200];
	int labelsNumber = userNumber-1;
	const char *labels[5];
	int array[6];
	int count = 0;
	bool cont;
	int num;
	labels[0] = "Tuition Expenses";
	labels[1] = "Project Expenses";
	labels[2] = "Book Expenses";
	labels[3] = "Travel Expenses";
	labels[4] = "Food Expenses";
	labels[5] = "Miscallaneous Fees";
	
	FILE *ptr, *ptr2;
	ptr = fopen("Expenses.txt","r");
   	
   	//scan all the items placed in array
   	fgets(buf, sizeof(buf), ptr);
  	sscanf(buf, "%d %d %d %d %d %d", 
	  &array[0], &array[1], &array[2], &array[3], &array[4], &array[5]);
	
	printf("\n==========================================\n");
	printf("\t Enter %s: ",labels[labelsNumber]);
	printf("\n==========================================\n");
   	scanf("%d",&num);
   	
	  
  	fclose(ptr);
  	
   	ptr2 = fopen("testKalv.txt","a");
   	//put said array in new file
   	//for loop in c
   	//it deletes the line you want 
   	
   	for(int i =0; i<=5;i++){
   		
   		if (i ==labelsNumber){		
   			array[i]=num+array[i];		
		   }
   		fprintf(ptr2,"%d ",array[i]);
   	}
   	
   	const char* name = "Expenses.txt";
   	//rename file to original file
    fclose(ptr2);
    remove(name);
    rename("testKalv.txt", name);
    system("cls");
}
File::readFile2(int userNumber){
	char buf[200];
	int labelsNumber = userNumber-1;
	const char *labels[5];
	int array[6];
	int count = 0;
	bool cont;
	int num;
	labels[0] = "Tuition Reduction";
	labels[1] = "Project Reduction";
	labels[2] = "Book Reduction";
	labels[3] = "Travel Reduction";
	labels[4] = "Food Reduction";
	labels[5] = "Miscallaneous Reduction";
	
	FILE *ptr, *ptr2;
	ptr = fopen("Expenses.txt","r");
   	
   	//scan all the items placed in array
   	fgets(buf, sizeof(buf), ptr);
  	sscanf(buf, "%d %d %d %d %d %d", 
	  &array[0], &array[1], &array[2], &array[3], &array[4], &array[5]);
	
	printf("\n==========================================\n");  
	printf("\t Enter %s: ",labels[labelsNumber]);
	printf("\n==========================================\n");
   	scanf("%d",&num);
   	
	  
  	fclose(ptr);
  	
   	ptr2 = fopen("testKalv.txt","a");
   	//put said array in new file
   	//for loop in c
   	//it deletes the line you want 
   	
   	for(int i =0; i<=5;i++){
   		
   		if (i ==labelsNumber){		
   			array[i]=array[i]-num;		
		   }
   		fprintf(ptr2,"%d ",array[i]);
   	}
   	
   	const char* name = "Expenses.txt";
   	//rename file to original file
    fclose(ptr2);
    remove(name);
    rename("testKalv.txt", name);
    system("cls");
}
File::Total(){
	FILE *fp;
	int array[5], total=0;
  	char buf[128];

  	fp = fopen("Expenses.txt", "r");
  	if(fp == NULL)
  	{
    return 0;
  	}

  	fgets(buf, sizeof(buf), fp);
  	sscanf(buf, "%d %d %d %d %d %d %d %d %d %d", 
	  &array[0], &array[1], &array[2], &array[3], &array[4], &array[5]);
  	fclose(fp);
  	
  	for (int i=0;i<6;i++){
  		total = total + array[i];
	  }
	  return total;
}
File::resetFile(){
	FILE *ptr;
	ptr = fopen("test.txt","a");
	for(int i=0;i<=5;i++){
		fprintf(ptr,"0 ");
	}
	const char* name = "Expenses.txt";
	//rename file to original file
    fclose(ptr);
    remove(name);
    rename("test.txt", name);
    system("cls");
}
void File::checker(){
	FILE *ptr, *ptr2;
	int i;
	ptr = fopen("Expenses.txt","r");
	if(ptr == NULL)
  	{
  	ptr2 = fopen("Expenses.txt","a");
    for(int i =0; i<=5;i++){
   		
   		fprintf(ptr2,"0 ");
   	}
   	fclose(ptr2);
  	}
  	fclose(ptr);
}
void Menu::Breakdown(){
	FILE *fp;
	Menu m;
	int total=0;
	int array[5];
  	char buf[128];

  	fp = fopen("Expenses.txt", "r");
  	if(fp == NULL)
  	{
    puts("No Inputted Expenses.");
    system ("Pause");
	system ("cls");
    m.display();
  	}

  	fgets(buf, sizeof(buf), fp);
  	sscanf(buf, "%d %d %d %d %d %d %d %d %d %d", 
	  &array[0], &array[1], &array[2], &array[3], &array[4], &array[5]);
  	fclose(fp);
  	
  	for (int i=0;i<6;i++){
  		total = total + array[i];
	  }
	
	printf("\n==========================================\n");
	printf("\t     CURRENT EXPENSES");
	printf("\n==========================================\n");
  	printf("Tuition: %d\n", array[0]);
  	printf("Project Expenses: %d\n", array[1]);
  	printf("Books: %d\n", array[2]);
  	printf("Travel: %d\n", array[3]);
  	printf("Food: %d\n", array[4]);
  	printf("Misc: %d\n", array[5]);
  	printf("==========================================\n");
  	printf("\t     Total: %d\n", total);
  	printf("==========================================\n");
  	
  	system ("Pause");
  	system ("cls");
  	
  	display();
}
void Menu::Exit(){
	exit(0);
}
