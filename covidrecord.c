// HEADER FILES
#include <stdio.h> //Use for standard I/O Operation
#include <conio.h>
#include <string.h> //Use for strcmp(),strcpy(),strlen(),etc
#include <stdlib.h>
#include <ctype.h> //  isalpha();

char password[50];
int b, valid = 0;
// FUNCTION DECLERATION
void WelcomeScreen(void); // WelcomeScreen function decleration
void Title(void);         // Title function decleration
void MainMenu(void);      // MainMenu function decleration
void LoginScreen(void);   // LoginScreen function decleration
void Add_rec(void);       // Add_rec function declarationss
void func_list();         // function to list the patient details
void Search_rec(void);    // Search_rec function declaration
void Edit_rec(void);      // Edit_rec function declaration
void Dlt_rec(void);       // Dlt_rec function declaration
void ex_it(void);         // exit function declaration
int checkSerial(int);     // to check if the serial number already exists
void About(void);         // about section about ourself
void All_Data(void);      // All records of vaccinated peoples

struct patient // list of global variable
{
    int S_no;
    int Age;
    char Gender;
    char Name[20];
    char Contact_no[20];
    char Address[30];
    int Ward_no;
    char Vaccine_name[20];
    char vaccinated_date[20];
} r;

int main(void)
{

    system("cls");
    WelcomeScreen(); // Use to call WelcomeScreen function
    Title();         // Use to call Title function
    LoginScreen();   // Use to call Menu function

    return 0;
}

void WelcomeScreen(void) // function for welcome screen
{
    system("color 3");
    system("cls");

    printf("\n\n\n\n\n\n\n\t\t\t\t####################################################");
    printf("\n\t\t\t\t#\t\t WELCOME TO\t\t\t   #");
    printf("\n\t\t\t\t#   BIRTAMODE MUNCIPALITY VACCINATION PROGRAMME    #");
    printf("\n\t\t\t\t####################################################");
    printf("\n\n\n\n\n\t\t\t\t Press any key......");
    getch();       // Use to holds screen for some seconds
    system("cls"); // Use to clear screen
}

void Title(void) // function for title screen
{
    system("color 5");
    system("cls");
    printf("\n\n\t\t----------------------------------------------------------------------------------");
    printf("\n\t\t\t\t      BIRTAMODE MUNCIPALITY  VACCINATION PROGRAMME       ");
    printf("\n\t\t----------------------------------------------------------------------------------");
}

void MainMenu(void) // function decleration
{
    system("cls");
    int choose;
    Title(); // call Title function
    printf("\n\n\n\n\n\t\t\t\t1. Add People Covid Vaccine  Details \n");
    printf("\n\t\t\t\t2. List Details \n");
    printf("\n\t\t\t\t3. Search Details \n");
    printf("\n\t\t\t\t4. Edit Details \n");
    printf("\n\t\t\t\t5. Delete Details \n");
    printf("\n\t\t\t\t6. Data Section\n");
    printf("\n\t\t\t\t7. About \n");
    printf("\n\t\t\t\t8. Exit \n");

    printf("\n\n\n \n\t\t\t\tChoose from 1 to 8: ");
    scanf("%d", &choose);

    switch (choose) // switch to differeht case
    {

    case 1:
        Add_rec(); // Add_rec function is called
        break;
    case 2:
        func_list();
        break;
    case 3:
        Search_rec(); // View_rec function is call
        break;
    case 4:
        Edit_rec(); // Edit_rec function is call
        break;
    case 5:
        Dlt_rec(); // Dlt_rec function is call
        break;

    case 6:
        All_Data();
        break;

    case 7:
        About();
        break;
    case 8:
        ex_it(); // ex_it function is callsss
        break;

    default:
        printf("\t\t\tInvalid entry. Please enter right option :)");
        getch(); // holds screen
    }            // end of switch
}

void ex_it(void) // function to exit
{
    system("cls");
    Title(); // call Title function
    printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING :)");
    getch(); // holds screen
}

void LoginScreen(void) // function for login screen
{
    // list of variables
    char username[20], password[20], user[] = "admin", pass[] = "8855";
    int e = 0, i;

    do
    {
        system("cls");
        Title();
        printf("\n\n\n\t\t USERNAME: ");
        scanf("%s", &username);
        printf("\n\t\t PASSWORD: ");
        for (i = 0; i < 20; i++)
        {
            password[i] = getch();
            if (password[i] == 13)
            {
                break;
            }
            else
            {
                printf("*");
            }
        }
        password[i] = '\0';
        if (strcmp(username, user) == 0 && strcmp(password, pass) == 0)
        {
            MainMenu();
        }
        else
        {
            printf("\n\n");
            printf("\t\t You Enter wrong password Please login again.");
            e++;
            getch();
        }
    } while (e <= 1);
    if (e > 1)
    {
        printf("\n\t\t You have cross the limit. You cannot login. :(");
        getch();
        ex_it();
    }

    system("cls");
}

void Add_rec(void)
{
    int num;
    char cont;
    system("cls");
    Title(); // call Title function

    FILE *bm;
    bm = fopen("record.txt", "a");
A:
    fflush(stdin);
    printf("\n\n\t\t Serial_No: ");
    scanf(" %d", &num);
    if (checkSerial(num))
    {
        printf("\t\t (This serial number already exists.)");
        goto A;
    }
    else
    {
        r.S_no = num;
    }
    fflush(stdin);
    printf("\n\t\t Name:");
    fflush(stdin);
    scanf(" %[^\n]", r.Name);
    printf("\n\t\t Gender[M/F/O]:");
    scanf(" %c", &r.Gender);
    printf("\n\t\t Address:");
    scanf(" %[^\n]", r.Address);
    printf("\n\t\t Ward_no:");
    scanf("%d", &r.Ward_no);
    printf("\n\t\t Age:");
    scanf("%d", &r.Age);
    fflush(stdin);

    do
    {
    D:
        printf("\n\t\t Contact no{98xxxxxxxx}:");
        scanf(" %[^\n]", r.Contact_no);
        if (strlen(r.Contact_no) != 10)
        {
            printf("\n\t Sorry :( Invalid. Contact no. must contain 10 numbers. Enter again :)");
            goto D;
        }
        else
        {
            for (b = 0; b < strlen(r.Contact_no); b++)
            {
                if (!isalpha(r.Contact_no[b]))
                {
                    valid = 1;
                }
                else
                {
                    valid = 0;
                    break;
                }
            }
            if (!valid)
            {
                printf("\n\t\t Contact no. contain Invalid character :(  Enter again :)");
                goto D;
            }
        }
    } while (!valid);
    fflush(stdin);

    printf("\n\t\t Vaccine Name:");
    scanf(" %[^\n]", r.Vaccine_name);
    printf("\n\t\t Vaccinated Date(DD-MM-YYYY):");
    scanf(" %[^\n]", r.vaccinated_date);

    fwrite(&r, sizeof(struct patient), 1, bm);
    fclose(bm);
    printf("\n\t\t Success:)");

    printf("\n\n\t\t----------------------------------------------------------------------------------");
    printf("\n\n\t\t Do you want to continue ? ( Press y/Y for yes)\n\t\t ");

    cont = getche();
    system("cls");
    if (cont == 'y')
    {
        Add_rec();
    }
    else
    {
        MainMenu();
    }
}

void func_list()
{
    system("cls");
    Title();
    FILE *fv;
    fv = fopen("Record.txt", "r");
    printf("\n\n\t\t\t!!!!!!!!!!!!!! List Record !!!!!!!!!!!!!\n");

    while (fread(&r, sizeof(struct patient), 1, fv))
    {
        if (r.Age <= 18)
        {

            printf("\n\t\t----------------------------------------------------------------------");
            printf("\n\t\t  Details of under 18 age group :)");
            printf("\n\t\t----------------------------------------------------------------------");
            fflush(stdin);
            printf("\n\t\t Serial No: %d", r.S_no);
            printf("\n\t\t Name: %s", r.Name);
            printf("\n\t\t Gender[M/F]: %c", r.Gender);
            printf("\n\t\t Address: %s", r.Address);
            printf("\n\t\t Ward_No: %d", r.Ward_no);
            printf("\n\t\t Age: %d", r.Age);
            printf("\n\t\t Contact_No: %s", r.Contact_no);
            printf("\n\t\t Vaccine Name: %s", r.Vaccine_name);
            printf("\n\t\t Vaccinated Date(DD-MM-YYYY): %s", r.vaccinated_date);
            printf("\n");
        }
        else if (r.Age <= 50)
        {

            printf("\n\t\t----------------------------------------------------------------------");
            printf("\n\t\t  Details of 18-50 age group :)");
            printf("\n\t\t----------------------------------------------------------------------");
            fflush(stdin);
            printf("\n\t\t Serial No: %d", r.S_no);
            printf("\n\t\t Name: %s", r.Name);
            printf("\n\t\t Gender[M/F]: %c", r.Gender);
            printf("\n\t\t Address: %s", r.Address);
            printf("\n\t\t Ward_No: %d", r.Ward_no);
            printf("\n\t\t Age: %d", r.Age);
            printf("\n\t\t Contact_No: %s", r.Contact_no);
            printf("\n\t\t Vaccine Name: %s", r.Vaccine_name);
            printf("\n\t\t Vaccinated Date(DD-MM-YYYY): %s", r.vaccinated_date);
            printf("\n");
        }
        else
        {

            printf("\n\t\t----------------------------------------------------------------------");
            printf("\n\t\t  Details of above 50 age group :)");
            printf("\n\t\t----------------------------------------------------------------------");
            fflush(stdin);
            printf("\n\t\t Serial No: %d", r.S_no);
            printf("\n\t\t Name: %s", r.Name);
            printf("\n\t\t Gender[M/F]: %c", r.Gender);
            printf("\n\t\t Address: %s", r.Address);
            printf("\n\t\t Ward_No: %d", r.Ward_no);
            printf("\n\t\t Age: %d", r.Age);
            printf("\n\t\t Contact_No: %s", r.Contact_no);
            printf("\n\t\t Vaccine Name: %s", r.Vaccine_name);
            printf("\n\t\t Vaccinated Date(DD-MM-YYYY): %s", r.vaccinated_date);
            printf("\n");
        }
    }

    fclose(fv);
    getch();
    MainMenu();
}

void Search_rec(void) // search function
{
    int sno;
    int flag = 0;
    system("cls");
    Title(); // call Title function
    FILE *bm;
    printf("\n\n\t\t\t!!!!!!!!!!!!!! Search Details !!!!!!!!!!!!!\n");
    fflush(stdin);
    printf("\n\t\t Serial No:");
    scanf("%d", &sno);
    bm = fopen("Record.txt", "r");
    while (fread(&r, sizeof(r), 1, bm))
    {
        if (sno == r.S_no)
        {
            flag = 1;
            printf("\n\t\t Serial No: %d", r.S_no);
            fflush(stdin);
            printf("\n\t\t Name:%s", r.Name);
            printf("\n\t\t Gender[M/F]: %c", r.Gender);
            printf("\n\t\t Address: %s", r.Address);
            printf("\n\t\t Ward_No: %d", r.Ward_no);
            printf("\n\t\t Age: %d", r.Age);
            printf("\n\t\t Contact_No: %s", r.Contact_no);
            printf("\n\t\t Vaccine Name: %s", r.Vaccine_name);
            printf("\n\t\t Vccinated Date(DD MM YY): %s", r.vaccinated_date);
        }
    }
    if (flag != 1)
    {
        printf("Result could not be found:");
    }
    fclose(bm);
    getch();
    MainMenu();
}

void Edit_rec(void)

{
    FILE *bm, *ft;
    int flag = 1;
    int sno, num;

    system("cls");
    Title(); // call Title window
    ft = fopen("temp.txt", "a");
    bm = fopen("Record.txt", "r");
    if (bm == NULL)
    {
        printf("\n\t Cannot open file!! ");
        getch();
        MainMenu();
    }
    printf("\n\n\t\t\t!!!!!!!!!!!!!! Edit Details !!!!!!!!!!!!!\n");
    fflush(stdin);
    printf("\n\t\t Serial No: ");
    scanf(" %d", &sno);
    while (fread(&r, sizeof(struct patient), 1, bm))
    {
        if (sno == r.S_no)
        {
            printf("\n\t\t----------------------------------------------------------------------");
            printf("\n\t\t!!!!!!!!!!!!!!Details!!!!!!!!!!!!!!!!!");
            printf("\n\t\t----------------------------------------------------------------------");
            fflush(stdin);

            printf("\n\t\t Serial No: %d\n", r.S_no);
            printf("\n\t\t Name:%s", r.Name);
            printf("\n\t\t Gender[M/F]: %c", r.Gender);
            printf("\n\t\t Address: %s", r.Address);
            printf("\n\t\t Ward_No: %d", r.Ward_no);
            printf("\n\t\t Age: %d", r.Age);
            printf("\n\t\t Contact_No: %s", r.Contact_no);
            printf("\n\t\t Vaccine Name: %s", r.Vaccine_name);
            printf("\n\t\t Vaccinated Date(DD MM YY): %s", r.vaccinated_date);
            printf("\n\t\t----------------------------------------------------------------------");
            printf("\n\t\t!!!!!!!!!!!!!!!!!!!!!!!Add New Details!!!!!!!!!!!!!");
            printf("\n\t\t----------------------------------------------------------------------");
        A:
            printf("\n\n\t\t Serial_No: ");
            scanf(" %d", &num);
            if (checkSerial(num))
            {
                printf("\t\t (This serial number already exists.)");
                goto A;
            }
            else
            {
                r.S_no = num;
            }
            fflush(stdin);
            printf("\t\t Name:");
            scanf(" %[^\n]", r.Name);
            printf("\n\t\t Gender[M/F]:");
            scanf("%s", &r.Gender);
            printf("\n\t\t Address:");
            scanf("%s", r.Address);
            printf("\n\t\t Ward_No:");
            scanf("%d", &r.Ward_no);
            printf("\n\t\t Age:");
            scanf("%d", &r.Age);
            printf("\n\t\t Contact_No:");
            scanf(" %[^\n]", &r.Contact_no);
            printf("\n\t\t Vaccine Name:");
            scanf(" %[^\n]", r.Vaccine_name);
            printf("\n\t\t Vaccinated Date(DD MM YY):");
            scanf(" %[^\n]", r.vaccinated_date);
            fwrite(&r, sizeof(r), 1, ft);
        }
        else
        {
            fwrite(&r, sizeof(struct patient), 1, ft);
            flag = 1;
        }
    }
    fclose(ft);
    fclose(bm);
    remove("Record.txt");
    rename("temp.txt", "Record.txt");
    if (flag == 1)
    {
        printf("\n\t\trRecord update successful:)");
    }
    else
        printf("\n\t\tRecord could not be updated:)");
    getch();
    MainMenu();
}

void Dlt_rec()
{
    int sno;

    int flaag = 0;
    system("cls");
    Title(); // call Title function
    FILE *bm, *ft;
    ft = fopen("temp_file.txt", "a");
    bm = fopen("Record.txt", "r");
    printf("\n\n\t\t\t!!!!!!!!!!!!!! Delete Record !!!!!!!!!!!!!\n");
    fflush(stdin);
    printf("\n\t\t Serial No:");
    scanf("%d", &sno);
    while (fread(&r, sizeof(struct patient), 1, bm))
    {
        if (sno != r.S_no)
        {
            fwrite(&r, sizeof(struct patient), 1, ft);
        }
        else
        {
            flaag = 1;
        }
    }

    fclose(bm);
    fclose(ft);
    remove("Record.txt");
    rename("temp_file.txt", "Record.txt");
    if (flaag == 1)
    {
        printf("record deleted sucessfully");
    }
    else
    {
        printf("Record couldn't be Found And Cannot Be Deleted");
    }
    getch();
    MainMenu();
}
void About(void)
{
    system("cls");
    Title();
    printf("\n");
    printf("\tThis Program is Design For Covid vaccine record.\n\tWe Three Group of Students Designed it for the college project.\n\tAs you can see,we are newbies and our program is for keeping record of people who have been vaccinated.\n ");
    printf("\n\tDesigned By:\n\tRachan Phuyal\n\tSujan Khatiwoda\n\tUjjwal Dahal\n");

    getch();
    MainMenu();
}

void All_Data()
{
    char rc="m";
    char sk="f";
    int count = 0, i = 0, j = 0, male = 0, female = 0;
    FILE *mm;

    system("cls");
    Title(); // call Title window

    mm = fopen("Record.txt", "r");
    if (mm == NULL)
    {
        printf("\n\t Cannot open file!! ");
        getch();
        MainMenu();
    }

    while (fread(&r, sizeof(struct patient), 1, mm))
    {
        if (r.Age < 18)
        {
            count++;
        }
        else if (r.Age > 18 && r.Age < 50)
        {
            i++;
        }
        else if (r.Age > 50)
        {
            j++;
        }
       
    }
    printf("\n\t\t Under 18: %d ", count);
    printf("\n\t\t Between (18-50): %d ", i);
    printf("\n\t\t Above 50: %d", j);
    printf("\n\t\t Total: %d", count + i + j);
   

    getch();
    MainMenu();
}
int checkSerial(int serial)
{
    FILE *fp = fopen("record.txt", "r");
    int flag = 0;

    while (fread(&r, sizeof(struct patient), 1, fp))
    {
        if (r.S_no == serial)
        {
            flag = 1;
        }
    }

    fclose(fp);
    return flag;
}
