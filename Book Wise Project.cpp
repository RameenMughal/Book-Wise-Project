// Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// Functions
void bookwise();
void login();
void addbook();
void bookslist();
void removebook();
void issuebook();
void viewissuedbooks();

// Structures
struct books
{   int id;
    char bookname[50];
    char authorname[50];
    char date[15];
}b;
struct student
{
	int id;
	int rollnumber;
	char studentname[50];
	char studentclass[50];
	char bookname[50];
    char authorname[50];
	char date[15];
}s;

// File declaration
FILE *fp;

// Menu main function
int main()
{
	int choice;
	
	// Heading And Login 
	printf("\t\t\t##############################################################");
	printf("\n\t\t\t###                                                        ###");
	printf("\n\t\t\t###           BOOK WISE LIBRARY MANAGEMENT SYSTEM          ###");
	printf("\n\t\t\t###                                                        ###");
	printf("\n\t\t\t##############################################################");
	login();
		
	// Main Menu
	while(1){
		system("cls");
		bookwise();
		printf("\n\t\t\t--------------------------------------------------------------");
	    printf("\n\t\t\t                           Menu                               ");
	    printf("\n\t\t\t--------------------------------------------------------------");
	    printf("\n\t\t1. Add Book");
	    printf("\n\t\t2. Books List");
	    printf("\n\t\t3. Remove Book");
	    printf("\n\t\t4. Issue Book");
	    printf("\n\t\t5. View Issued Books");
	    printf("\n\t\t6. Exit");
	    printf("\n\t\tEnter your choice = ");
	    scanf("%d" ,&choice);
	    
	    switch(choice)
	    {case 1:
	    	{addbook();
	        break;}
	    case 2:
	    	{bookslist();
	    	break;}
	    case 3:
	    	{removebook();
	    	break;}
	    case 4:
	    	{issuebook();
	    	break;}
	    case 5:
	    	{viewissuedbooks();
	    	break;}
	    case 6:
	    	{printf("\t\t===========THANK YOU FOR USING BOOKWISE===========");
			exit(0);}}}
	
	return 0;
}

void bookwise()
{
	printf("\t\t\t##############################################################");
    printf("\n\t\t\t###                        BOOK WISE                       ###");
    printf("\n\t\t\t##############################################################");
}

void login()
{
	// Declaration
	int cmpusername,cmppassword;
	char username[20],password[20];
	char defaultusername[] = "neduniversity";
	char defaultpassword[] = "ned123";
	
	// Heading
	printf("\n\t\t\t--------------------------------------------------------------");
	printf("\n\t\t\t                              Login                           ");
	printf("\n\t\t\t--------------------------------------------------------------");
	
	// Input Values
	printf("\n\n\t\tUsername = ");
	scanf("%s" ,&username);
	printf("\t\tPassword = ");
	scanf("%s" ,&password);
	
	// Compare the input values from default username and password
	cmpusername = strcmp(username,defaultusername);
	cmppassword = strcmp(password,defaultpassword);
	
	// Conditions which is correct and incorrect
	if(cmpusername==0 && cmppassword==0)
        {printf("\n\t\tLogin Successfull");
        sleep(2);}
 	else if(cmpusername!=0 && cmppassword==0)
	    {printf("\n\t\tUsername is incorrect");
 	    printf("\n\t\tPress Enter to correct");
        while (getchar() != '\n');
            getchar();
        system("cls");
        bookwise();
 	    login();}
    else if(cmpusername==0 && cmppassword!=0)
	    {printf("\n\t\tPassword is incorrect");
 	    printf("\n\t\tPress Enter to correct");
        while (getchar() != '\n');
            getchar();
        system("cls");
        bookwise();
 	    login();}
    else
	   {printf("\n\t\tUsername and password are incorrect");
 	    printf("\n\t\tPress Enter to correct");
        while (getchar() != '\n');
            getchar();
        system("cls");
        bookwise();
 	    login();}
}

void addbook(){
    
    // Headings
    system("cls");
    bookwise();
    printf("\n\t\t\t--------------------------------------------------------------");
	printf("\n\t\t\t                           Add Book                           ");
	printf("\n\t\t\t--------------------------------------------------------------");
	
	// To open a file 
    fp= fopen ("Books List.txt","a");
    
    // Input Values
    printf("\n\t\tEnter book id: ");
    scanf("%d",&b.id);
	
	printf("\t\tEnter book name: " );
    fflush(stdin);
    gets(b.bookname);
    b.bookname[strcspn(b.bookname, "\n")] = '\0'; 

    printf("\t\tEnter author name: " );
    fflush(stdin);
    gets(b.authorname);
    b.authorname[strcspn(b.authorname, "\n")] = '\0';

    printf("\n\t\tBook added successfully");
    
    // To write in and close the file
    fprintf(fp, "\n\n\t\t|%5d    |  %-31s | %-31s |\n", b.id, b.bookname, b.authorname);
    fclose(fp);

    printf("\n\t\tEnter any key to continue ");
    while (getchar() != '\n');
    getchar();
}

void bookslist()
{
	// Declaration
	char line[150];
	
	// Headings
	system("cls");
	bookwise();
	printf("\n\t\t\t--------------------------------------------------------------");
	printf("\n\t\t\t                          Books List                          ");
	printf("\n\t\t\t--------------------------------------------------------------\n");
	
	// To read and show from the file
	fp = fopen("Books List.txt" ,"r");
	
	while (fgets(line, sizeof(line), fp) != NULL)
    {printf("%s", line);}
    printf("\n\t\tEnter any key to continue");
    while (getchar() != '\n');
    getchar();
	fclose(fp);
}

void removebook()
{
	// Declaration
	int delid,found=0;
	char line[150];
	
	// Headings
	system("cls");
	bookwise();
	printf("\n\t\t\t--------------------------------------------------------------");
	printf("\n\t\t\t                      Remove Book                             ");
	printf("\n\t\t\t--------------------------------------------------------------\n");
	
	// Input Values
	printf("\n\t\tEnter Book ID to remove = ");
	scanf("%d" ,&delid);
	
	// Declare a temporary file
	FILE *ft;
	
	// To write in temporary file and read from books list
	ft = fopen("Temp.txt" ,"w");
	fp = fopen("Books List.txt" ,"r");
	
	// To find the Book ID
    while(fgets(line, sizeof(line), fp)!=NULL)
    {sscanf(line, "\t\t| %5d", &b.id);
	if (b.id == delid)
        {found = 1;}
        else
        {fprintf(ft, "%s", line);}}
        
    if(found==1)
    {printf("\n\t\tID %d removed successfully" ,delid);}

    // Close both files
    fclose(fp);
    fclose(ft);

    // Remove and update the Books List file
    remove("Books List.txt");
    rename("Temp.txt", "Books List.txt");

    if(!found)
    {printf("\n\t\tBook with ID %d not found.", delid);}

    printf("\n\t\tEnter any key to continue");
    while (getchar() != '\n');
    getchar();
}

void issuebook()
{
	// To set the current date
    char myDate[15];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(s.date, myDate);

    // Declaration
    int found=0;
    int idchoice;
    char line[150];
    
    // Headings
    system("cls");
    bookwise();
    printf("\n\t\t\t--------------------------------------------------------------");
    printf("\n\t\t\t                          Issuing Book                          ");
    printf("\n\t\t\t--------------------------------------------------------------\n");

    // Input Value
    printf("\n\t\tEnter Book id to issue: ");
    scanf("%d", &idchoice);

    // Open the file and check the required Book ID
    fp = fopen("Books List.txt", "r");

    while(fgets(line, sizeof(line), fp) != NULL)
    {sscanf(line, "\n\t\t|%5d", &b.id);
    if(b.id == idchoice)
        {found=1;
        break;}}

    // Close the file
    fclose(fp);

    // Conditions to check if the book is found
    if(b.id != idchoice)
       {printf("\n\t\tNo book found with this id\n");
        printf("\n\t\tEnter any key to continue");
        while (getchar() != '\n');
            getchar();}
    else
       { // Input Values
        printf("\t\tEnter Student Id: ");
        fflush(stdin);
        scanf("%d", &s.id);
        
        printf("\t\tEnter Student Name: ");
        fflush(stdin);
        gets(s.studentname);

        printf("\t\tEnter Student Class: ");
        fflush(stdin);
        gets(s.studentclass);

        printf("\t\tEnter Student Roll: ");
        scanf("%d", &s.rollnumber);

        printf("\n\t\tBook Issued Successfully\n\n");

        fp = fopen("Issue Book.txt", "a");
        fprintf(fp, "\n|%8d  |  %-31s|  %-31s|  %-10d|  %-10d|  %10s|\n", s.id, s.studentname, s.studentclass, s.rollnumber, b.id, s.date);
        fclose(fp);

        printf("\t\tEnter any key to continue");
        while (getchar() != '\n');
        getchar();}
}

void viewissuedbooks()
{
	// Declaration
	char line[150];
	
	// Headings
	system("cls");
	bookwise();
	printf("\n\t\t\t--------------------------------------------------------------");
	printf("\n\t\t\t                       Issued Book List                       ");
	printf("\n\t\t\t--------------------------------------------------------------\n");
	
	// To read and show from file
	fp = fopen("Issue Book.txt" ,"r");
	while (fgets(line, sizeof(line), fp) != NULL)
    {printf("%s", line);}
    
    printf("\n\t\tEnter any key to continue");
    while (getchar() != '\n');
        getchar();
        
    // Close the file
	fclose(fp);
}
