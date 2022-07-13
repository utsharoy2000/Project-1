#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

int inlock,curval,sh;
char xnam[100],ypas[100],uunam[100];

///\n\n\t\t\t\t\t\t\t\t\t

///display
void intro(void);
void search(void);
void result();

///search
void choice();

///account
void regsystem();
void loginsystem();
void append ();
bool check ();
void showdata();
void dltacnt();

///payment
void payment();

///choice
void introchoice();
void loginchoice();
void resultchoice();
void paymentchoice();

///profile
void profilereg();
void profile();
void editprofile();
void gotoxy(int xcor,int ycor)
{
    COORD coord;
    coord.X=xcor;
    coord.Y=ycor;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


struct np
{
    char name[100];
    char password[100];
    char fname [100];
    char lname [100];
    char uname [100];
    char phn [100];
    char add [150];
    int  lock;
    struct np *next;
};
struct np *root;

struct savedata
{
    char hotel_name[100];
    char transportation_name[30];
    char dd[30];
    int pep;
    int  cost_paid;
    int pass;
    struct savedata *nxt;
};
struct savedata *rot;

//\t\t\t\t
int main()
{
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t        ==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t        ==                                           ==");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t        ==             WELCOME                       ==");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t        ==                    TO                     ==");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t        ==                      TOURNEST             ==");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t        ==                                           ==");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t        ==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tDO YOU ALREADY HAVE AN ACCOUNT???\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t  YES OR NO???\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t  => ");

    ///**********reg and login page

    char log[4];
    scanf("%s",log);
    strlwr(log);
    if(strcmp(log,"no")==0)
    {
        regsystem();
    }

    else
    {

        loginsystem();
    }

    ///********************begin****
     system("cls");
    intro();
}



void regsystem()
{
    char first_name [100];
    char last_name [100];
    char username [100];
    char phone_ [100];
    char address_ [150];
    char user_name [100];
    char user_pass [100];

    system("cls");

    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t#############################################################");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t##########                 Sign Up                 ##########");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t#############################################################\n");

    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tEnter First Name: ");
    scanf(" %[^\n]%*c", first_name);


    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tEnter Last Name: ");
    scanf(" %[^\n]%*c", last_name);

    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tEnter User Name: ");
    scanf(" %[^\n]%*c", username);

    strcpy(uunam,username);

    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tEnter Phone Number: ");
    scanf(" %[^\n]%*c", phone_);

    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tEnter Address: ");
    scanf(" %[^\n]%*c", address_);

    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tEnter E-Mail: ");
    scanf(" %[^\n]%*c", user_name);
    strcpy(xnam,user_name);

    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tEnter Password: ");
    scanf(" %[^\n]%*c", user_pass);
    strcpy(ypas,user_pass);


    inlock++;
    curval = inlock;  ///WITHOUT LOGIN VALUE TO INSERT THE PAYMENT SAVEDATA
    append (user_name, user_pass, inlock, first_name, last_name, username, phone_,address_);

}


void append (char person_name[], char password[], int inlock, char first_name[], char last_name[], char username[], char phone_[], char address_[])
{
    struct np *tmp;

    tmp = (struct np*) malloc (sizeof (struct np) );

    strcpy (tmp->name, person_name);
    strcpy (tmp->password, password);
    strcpy (tmp->fname, first_name);
    strcpy (tmp->lname, last_name);
    strcpy (tmp->uname, username);
    strcpy (tmp->phn, phone_);
    strcpy (tmp->add, address_);

    tmp->lock = inlock;
    tmp->next = root;
    root = tmp;
}



void loginsystem()
{
    char username [100];
    char userpass [100];
    int val,cheked,clct;
    while(1)
    {

        system("cls");

        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t#############################################################");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t##########                 Sign In                 ##########");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t#############################################################\n");

        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tE-MAIL: ");
        scanf(" %[^\n]%*c", username);
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tPassword: ");
        scanf(" %[^\n]%*c", userpass);
        val = check(username, userpass, &clct);
        if(val)
        {
            cheked = 1;
            break;
        }
        else
        {
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t   WRONG E-MAIL OR PASSWORD, WOULD YOU LIKE TO TRY AGAIN???\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tYES OR NO???\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t=> ");
            char t[4];
            scanf("%s",t);
            strlwr(t);
            if(strcmp(t,"no")==0)
            {
                main();
            }
            else
                continue;
        }
    }


    curval = clct;
    if(cheked)
    {
        intro();
        //loginchoice(clct); //// clct is lock value
    }
    else
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tNull");
}



bool check (char log_n[],char log_p[], int *key)
{
    struct np *chc = root;
    while(chc != NULL)
    {
        if (strcmp (chc->name, log_n) == 0 && strcmp (chc->password, log_p) == 0)
        {
            *key = chc->lock;
            strcpy(uunam,chc->uname);
            return true;
        }
        else
        {
            chc=chc->next;
        }
    }
    return false;
}


void showdata(int clct)
{
    struct savedata *chc = rot;
    while(chc != NULL)
    {
        if (chc->pass == clct)
        {
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tYour Date: %s",chc->dd);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tYour Travel Companion: %d",chc->pep);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tYour Travel Place: %s",chc->hotel_name);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tYour Transportation: %s",chc->transportation_name);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tTotal Cost For Tour: %d Tk.",chc->cost_paid);
            break;
        }
        else
        {
            chc=chc->nxt;
        }
    }
    paymentchoice(curval,clct);

}

void intro()
{

    system("cls");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t WELCOME %s", uunam);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Enjoy Your Tour With TourNest");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t     Some Popular Places..."); ///lot's of places to write....

    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t       |||=-=-=-=-=-=-=-=-=-=-=-=-=|||");
    printf(" |||=-=-=-=-=-=-=-=-=-=-=-=-=|||");
    printf("\n\t\t\t\t\t\t\t\t\t\t       |||=                       =|||");
    printf(" |||=                       =|||");
    printf("\n\t\t\t\t\t\t\t\t\t\t       |||=      Sajek Valley     =|||");
    printf(" |||=       Cox's Bazar     =|||");
    printf("\n\t\t\t\t\t\t\t\t\t\t       |||=                       =|||");
    printf(" |||=                       =|||");
    printf("\n\t\t\t\t\t\t\t\t\t\t       |||=-=-=-=-=-=-=-=-=-=-=-=-=|||");
    printf(" |||=-=-=-=-=-=-=-=-=-=-=-=-=|||");

    printf("\n\n\t\t\t\t\t\t\t\t\t\t       |||=-=-=-=-=-=-=-=-=-=-=-=-=|||");
    printf(" |||=-=-=-=-=-=-=-=-=-=-=-=-=|||");
    printf("\n\t\t\t\t\t\t\t\t\t\t       |||=                       =|||");
    printf(" |||=                       =|||");
    printf("\n\t\t\t\t\t\t\t\t\t\t       |||=        Jaflong        =|||");
    printf(" |||=        Sundarban      =|||");
    printf("\n\t\t\t\t\t\t\t\t\t\t       |||=                       =|||");
    printf(" |||=                       =|||");
    printf("\n\t\t\t\t\t\t\t\t\t\t       |||=-=-=-=-=-=-=-=-=-=-=-=-=|||");
    printf(" |||=-=-=-=-=-=-=-=-=-=-=-=-=|||");

    printf("\n\n\t\t\t\t\t\t\t\t\t\t       |||=-=-=-=-=-=-=-=-=-=-=-=-=|||");
    printf(" |||=-=-=-=-=-=-=-=-=-=-=-=-=|||");
    printf("\n\t\t\t\t\t\t\t\t\t\t       |||=                       =|||");
    printf(" |||=                       =|||");
    printf("\n\t\t\t\t\t\t\t\t\t\t       |||=      Kaptai Lake      =|||");
    printf(" |||=         Nilgiri       =|||");
    printf("\n\t\t\t\t\t\t\t\t\t\t       |||=                       =|||");
    printf(" |||=                       =|||");
    printf("\n\t\t\t\t\t\t\t\t\t\t       |||=-=-=-=-=-=-=-=-=-=-=-=-=|||");
    printf(" |||=-=-=-=-=-=-=-=-=-=-=-=-=|||");

    introchoice(curval);
}

void search()
{
    system("cls");
    char place[100];

    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t            =======================");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t            ||      PLACE     ||");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t         =======================");

    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWhere Would You Like To Go?\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t=> ");
    scanf(" %[^\n]%*c",place);
    result(place);
}


void result(char place[])
{

    ///****hotels****
    char save_hotels[100][100],shh[100];
    int aaaa;

    system("cls");

    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t            =======================");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t            ||      HOTEL     ||");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t         =======================");

    for(int i=1; i<strlen(place); i++)
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t     %d. %s Hotel\n", i, place);
        strcpy(save_hotels[i-1],place);
        char temp=place[i-1];
        place[i-1]=place[i];
        place[i]=temp;
    }
    aaaa=strlen(place);
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t     %d. NONE Hotel\n", aaaa);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t    Which Hotel Would You Like To Choose?\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t=> ");
    scanf("%d",&sh);
    if(sh==aaaa)
    {
        strcpy(save_hotels[sh],"NONE");
        strcpy(shh,"NONE");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t   You Choose %s Hotel.",save_hotels[sh]);
    }
    else
    {
        strcpy(shh,save_hotels[sh-1]);
         printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t   %s Hotel, Is An Excellent Choice ^-^.",save_hotels[sh-1]);
    }

    ///*******************************************************************

    ///save the hotel to a structure with a specific key for the account***
    ///end of hotel section

    ///****vehicles****
    system("cls");
    int veh;
    char save_veh[50];

    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t          ==============================");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t          ||     TRANSPORTATION    ||");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t       ==============================");

    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t    What Type Of Transportation Would You Like To Choose??");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t1. Bus\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t2. Private Car\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t3. Bike\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t4. Plane\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t5. Boat Or Launch\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t6. None\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tChoose = ");
    scanf("%d",&veh);
    ///save the vehicle choice
    if(veh==1)
    {
        strcpy(save_veh,"Bus");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  You Want To Go Via Bus");
    }
    if(veh==2)
    {
        strcpy(save_veh,"Private Car");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  You Want To Go Via Private Car");

    }
    if(veh==3)
    {
        strcpy(save_veh,"Bike");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  You Want To Go Via Bike");
    }
    if(veh==4)
    {
        strcpy(save_veh,"Plane");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  You Want To Go Via Plane");
    }
    if(veh==5)
    {
        strcpy(save_veh,"Boat Or Launch");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  You Want To Go Via Boat Or Launch");
    }
    if(veh!=1 && veh!=2 && veh!=3 && veh!=4 && veh!=5)
    {
        strcpy(save_veh,"NONE");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t   You Choose NONE Of The Transportation Way");
    }

     if(strcmp(save_hotels[sh],"NONE")==0 && strcmp(save_veh,"NONE")==0)
     {
          system("cls");
         introchoice(curval);
     }

    else
    {
        system("cls");
        char deci[4];
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t     Are You Sure Would You Like To Book %s Hotel & Transport Via %s?\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t       => YES OR NO\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t       => ",shh,save_veh);
    scanf("%s",deci);
    strlwr(deci);
    if(strcmp(deci,"yes")==0)
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWould You Like To Pay Now?\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t      => YES OR NO\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t      => ");

        char p[4];
        scanf("%s",p);
        strlwr(p);
        if(strcmp(p,"no")==0)
        {
             system("cls");
            resultchoice(shh,save_veh,curval);
        }

        else
        {

            payment(shh,save_veh);
        }
    }
    else
    {
        int cl = sizeof(save_hotels)/sizeof(char *);
        int vl = sizeof(save_veh)/sizeof(char *);
        int c2 = sizeof(shh)/sizeof(char *);
        memset(save_hotels,0,cl);
        memset(shh,0,c2);
        memset(save_veh,0,vl);
        introchoice(curval);
    }
    }

}


void payment(char shh[],char save_veh[],int sh)
{
    system("cls");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t#############################################################");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t##########                Date & Person            ##########");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t#############################################################\n");
    int pay,de,h;
    char date[30];
    if(strcmp(shh,"NONE")==0 && strcmp(save_veh,"NONE")==0)
    {
        pay = 0;
        system("cls");
        paymentchoice(curval);
    }
    else if(strcmp(shh,"NONE")==0 && strcmp(save_veh,"NONE")!=0)
    {

        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  Going Date : ");
        scanf(" %[^\n]*c",date);

        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  Members : \n\n\t\t\t\t\t\t\t\t\t\t\t\t\t     => ");
        scanf("%d",&h);

        pay = strlen(save_veh)*500*h;
    }
    else if(strcmp(shh,"NONE")!=0 && strcmp(save_veh,"NONE")==0)
    {

        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  Going Date : ");
        scanf(" %[^\n]*c",date);

        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  Members : \n\n\t\t\t\t\t\t\t\t\t\t\t\t\t     =>");
        scanf("%d",&h);

        pay = strlen(shh)*500*h;
    }
    else
    {

        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  Going Date : ");
        scanf(" %[^\n]*c",date);

        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  Members: \n\n\t\t\t\t\t\t\t\t\t\t\t\t\t     =>");
        scanf("%d",&h);
        pay=strlen(shh)*500+strlen(save_veh)*500*h;
    }

    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t     Your Total Cost For Trip: %d Tk.",pay);

    system("cls");

    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t           ==========================");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t           ||      PAYMENT      ||");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t        ==========================");

    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t    How Would You Like To Pay The Bill?\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tChoose Your Method To Pay:\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t    1. Mobile Banking\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t    2. Card\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t    3. Bank");
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tWhich Would You Like To Choose, 1 2 or 3?\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t     => ");

    scanf("%d",&de);

    if(de==1)
    {
        system("cls");
        int pref;
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t Thank You For Choosing Mobile Bank");

        printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t           ======================");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t           ||    Mobile Bank   ||");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t           ======================");

        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t        1. Bkash\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t        2. Rocket\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t        3. Nagad\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tWhich One Would You Prefer?\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t    => ");

        scanf("%d",&pref);
        if(pref==1)
        {
            int mon,pao;
            system("cls");

            printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t           ======================");
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t           ||       BKash      ||");
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t           ======================");

            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tPlease Enter Your Number & PIN-");
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Mobile Number: ");
            scanf("%d",&mon);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t    PIN: ");
            scanf("%d",&pao);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  THANK YOU, PAYMENT DONE!!!");
        }
        if(pref==2)
        {
            int mon,pao;
            system("cls");

            printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t           ======================");
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t           ||      Rocket      ||");
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t           ======================");

            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tPlease Enter Your Number & PIN- ");
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Mobile Number: ");
            scanf("%d",&mon);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t    PIN: ");
            scanf("%d",&pao);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  THANK YOU, PAYMENT DONE!!!");
        }
        if(pref==3)
        {
            int mon,pao;
            system("cls");

            printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t           ======================");
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t           ||       Nagad      ||");
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t           ======================");

            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tPlease Enter Your Number & PIN-");
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Mobile Number: ");
            scanf("%d",&mon);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t    PIN: ");
            scanf("%d",&pao);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  THANK YOU, PAYMENT DONE!!!");
        }
    }
    if(de==2)
    {
        int pref;
        system("cls");
        system("cls");

        printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tThank You For Choosing Card");

        printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t           ======================");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t           ||       Card       ||");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t           ======================");

        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t        1.VISA\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t        2.Master Card\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t        3.ATM Card\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tWhich One Would You Prefer?\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t=> ");

        scanf("%d",&pref);
        if(pref==1)
        {
            int card,cv;
            char nm[100],exp[50],add[50],con[50];
            system("cls");

            printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t           ======================");
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t           ||     VISA Card    ||");
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t           ======================");

            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Card number: ");
            scanf("%d",&card);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Name: ");
            scanf(" %[^\n]%*c",nm);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Address: ");
            scanf(" %[^\n]%*c",add);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Country: ");
            scanf(" %[^\n]%*c",con);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    CVV: ");
            scanf("%d",&cv);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Exp: ");
            scanf(" %[^\n]%*c",exp);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    THANK YOU, PAYMENT DONE!!!");
        }

        if(pref==2)
        {
            int card,cv;
            char nm[100],exp[50],add[50],con[50];
            system("cls");

            printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t           ======================");
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t           ||    Master Card   ||");
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t           ======================");

            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Card number: ");
            scanf("%d",&card);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Name: ");
            scanf(" %[^\n]%*c",nm);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Address: ");
            scanf(" %[^\n]%*c",add);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Country: ");
            scanf(" %[^\n]%*c",con);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    CVV: ");
            scanf("%d",&cv);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Exp: ");
            scanf(" %[^\n]%*c",exp);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    THANK YOU, PAYMENT DONE!!!");
        }

        if(pref==3)
        {
            int card,cv;
            char nm[100],exp[50],add[50],con[50];
            system("cls");

            printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t           ======================");
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t           ||     ATM Card     ||");
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t           ======================");

            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Card number: ");
            scanf("%d",&card);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Name: ");
            scanf(" %[^\n]%*c",nm);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Address: ");
            scanf(" %[^\n]%*c",add);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Country: ");
            scanf(" %[^\n]%*c",con);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    CVV: ");
            scanf("%d",&cv);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Exp: ");
            scanf(" %[^\n]%*c",exp);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    THANK YOU, PAYMENT DONE!!!");
        }
    }
    ///.....
    if(de==3)
    {
        system("cls");
        printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tThank you for choosing Bank");

        printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t           ======================");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t           ||       Bank       ||");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t           ======================");

        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t       This Is Our Merchant Number: 01XXXXXXXXXX\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t      THANK YOU!!!\n");
    }

    struct savedata *tempo;
    tempo = (struct savedata*) malloc (sizeof (struct savedata) );
    strcpy (tempo->hotel_name, shh);
    strcpy (tempo->transportation_name, save_veh);
    strcpy(tempo->dd,date);
    tempo->pep = h;
    tempo->cost_paid = pay;
    tempo->pass = curval;
    tempo->nxt = rot;
    rot = tempo;
    system("cls");
    paymentchoice(curval);

}

///*******************************************for reg.......................

void profilereg(int curval)
{
    system("cls");
    struct np *chc = root;

    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  *****************************\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t  ********             ********\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t  *******    PROFILE    *******\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t  ********             ********\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t  *****************************\n");

    while(chc != NULL)
    {
        if (chc->lock == curval)
        {
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Name: %s %s",chc->fname,chc->lname);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    E-Mail: %s",chc->name);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Phone: %s",chc->phn);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Address: %s",chc->add);
            break;
        }
        else
        {
            chc=chc->next;
        }
    }
    introchoice(curval);
}

///*******************************************for login.......................

void profile(int clct)
{
    system("cls");
    struct np *chc = root;

    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  *****************************\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t  ********             ********\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t  *******    PROFILE    *******\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t  ********             ********\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t  *****************************\n");

    while(chc != NULL)
    {
        if (chc->lock == clct)
        {
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Name: %s %s",chc->fname,chc->lname);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    E-Mail: %s",chc->name);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Phone: %s",chc->phn);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Address: %s",chc->add);
            break;
        }
        else
        {
            chc=chc->next;
        }
    }
    introchoice(clct);
}


void settings(int curval)
{
    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t        **                                     **");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t         ***-----------------------------------***");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t          ****             SETTING             ****");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t         ***-----------------------------------***");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t        **                                     **");

    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t       1. Edit Profile\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t       2. Support and FAQ\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t       3. Log Out\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t       4. Delete Account\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t       5. Back Home\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t       => ");
    int x;
    scanf("%d",&x);

    switch(x)
    {
    case 1:
    {
        system("cls");
        editprofile(curval);
        break;
    }
    case 2:
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t     *******************************\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t     *********** Support ***********\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t     ***********    &    ***********\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t     ***********   FAQ   ***********\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t     *******************************\n");

        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t              Team TourNest");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Any Problem Feel Free To Contact US");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t        Email: tournest@gmail.com");
        settings(curval);
        break;
    }
    case 3:
    {
        system("cls");
        main();
        break;
    }
    case 4:
    {
        system("cls");
        dltacnt(curval);
        break;
    }
    case 5:
    {
        system("cls");
        intro();
        break;
    }

    }

}


void editprofile(int curval)
{
    system("cls");
    int x;
    struct np *a = root;
    char name[100];
    char password[100];
    char fname [100];
    char lname [100];
    char uname [100];
    char phn [100];
    char add [150];

    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t     *****************************\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t     ********             ********\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t     ******* EDIT PROFILE  *******\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t     ********             ********\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t     *****************************\n");

    while(a!=NULL)
    {
        if(a->lock==curval)
        {
            while(x!=8)
            {
                printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t       What Do You Want To Change?");
                printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t            1. First Name  ");
                printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t            2. Last Name   ");
                printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t            3. User Name   ");
                printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t            4. Phone Number   ");
                printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t            5. ADDRESS  ");
                printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t            6. E-Mail      ");
                printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t            7. Password    ");
                printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t            8. None        \n\n\t\t\t\t            => ");
                scanf("%d",&x);

                switch(x)
                {
                case 1:
                {
                    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t          1. First Name: ");
                    scanf(" %[^\n]%*c",fname);
                    strcpy(a->fname,fname);
                    break;
                }
                case 2:
                {
                    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t          2. Last Name: ");
                    scanf(" %[^\n]%*c",lname);
                    strcpy (a->lname,lname);
                    break;
                }
                case 3:
                {
                    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t          3. User Name: ");
                    scanf(" %[^\n]%*c",uname);
                    strcpy (a->uname,uname);
                    break;
                }
                case 4:
                {
                    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t          4. Phone Number: ");
                    scanf(" %[^\n]%*c",phn);
                    strcpy (a->phn,phn);
                    break;
                }
                case 5:
                {
                    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t          5. Address: ");
                    scanf(" %[^\n]%*c",add);
                    strcpy (a->add,add);
                    break;
                }
                case 6:
                {
                    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t          6. E-Mail: ");
                    scanf(" %[^\n]%*c",name);
                    strcpy (a->name,name);
                    break;
                }
                case 7:
                {
                    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t          7. Password: ");
                    scanf(" %[^\n]%*c",password);
                    strcpy (a->password,password);
                    break;
                }
                case 8:
                {
                    system("cls");
                    break;
                }
                }
            }

            system("cls");
            introchoice(curval);
        }
        else
        {
            a = a->next;
        }

    }
}


void dltacnt(int curval)
{
    system("cls");
    struct np *del = root;
    int h=0;
    while(del!=NULL)
    {
        if(del->lock==curval)
        {
            free(del);
            if(h==0)
            {
                root = NULL;
            }
            else
            {
                root = root->next;
            }

            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t      *****************************\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t      ********             ********\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t      ****** ACCOUNT DELETED ******\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t      ********             ********\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t      *****************************\n");

            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t      Your Account Has Been Deleted -_-");
            main();
            break;
        }
        else
        {
            h++;
            del= del->next;
        }
    }
}

///******************************************options*****************************************************************

void introchoice(int curval)
{

    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t        **                                     **");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t         ***-----------------------------------***");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t          ****             OPTIONS             ****");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t         ***-----------------------------------***");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t        **                                     **");

    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t         1. Search\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         2. Profile\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         3. Payment\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         4. Setting\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         5. Logout\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         6. Quit\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         => ");


    int c;
    scanf("%d",&c);
    switch(c)
    {
    case 1:
    {
        system("cls");
        search();
        break;
    }
    case 2:
    {
        system("cls");
        profilereg(curval);
        break;
    }
    case 3:
    {
        system("cls");
        showdata(curval);
        break;
    }
    case 4:
    {
        system("cls");
        settings(curval);
        break;
    }

    case 5:
    {
        system("cls");
        main();
        break;
    }
    case 6:
    {
        return;
    }
    default:
    {
        break;
    }

    }
}


void loginchoice(int clct)
{

    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t        **                                     **");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t         ***-----------------------------------***");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t          ****             OPTIONS             ****");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t         ***-----------------------------------***");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t        **                                     **");

    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t         1. Home\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         2. Search\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         3. Profile\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         4. Payment\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         5. Setting\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         6. Logout\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         7. Quit\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         => ");


    int c;
    scanf("%d",&c);
    switch(c)
    {
    case 1:
    {
        intro();
        break;
    }
    case 2:
    {
        search();
        break;
    }
    case 3:
    {
        profile(clct);
        break;
    }
    case 4:
    {
        showdata(clct);
        break;
    }
    case 5:
    {
        settings(clct);
        break;
    }

    case 6:
    {
        main();
        break;
    }
    case 7:
    {
        return ;
    }
    default:
    {
        break;
    }

    }
}


void resultchoice(char save_hotels[],char save_veh[],int curval)
{

    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t        **                                     **");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t         ***-----------------------------------***");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t          ****             OPTIONS             ****");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t         ***-----------------------------------***");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t        **                                     **");

    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t         1. Home\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         2. Search\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         3. Payment\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         4. Profile\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         5. Payment\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         6. Setting\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         7. Logout\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         8. Quit\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         => ");


    int c;
    scanf("%d",&c);
    switch(c)
    {
    case 1:
    {
        intro();
        break;
    }
    case 2:
    {
        search();
        break;
    }

    case 3:
    {
        payment(save_hotels,save_veh,sh);
        break;
    }
    case 4:
    {
        profile(curval);
        break;
    }
    case 5:
    {
        showdata(curval);
        break;
    }
    case 6:
    {
        settings(curval);
        break;
    }
    case 7:
    {
        main();
        break;
    }
    case 8:
    {
        return ;
    }
    default:
    {

        break;
    }

    }
}


void paymentchoice(int curval)
{

    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t        **                                     **");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t         ***-----------------------------------***");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t          ****             OPTIONS             ****");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t         ***-----------------------------------***");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t        **                                     **");

    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t         1. Home\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         2. Profile\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         3. Search\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         4. Payment\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         5. Setting\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         6. Logout\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         7. Quit\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t         => ");

    int c;
    scanf("%d",&c);
    switch(c)
    {
    case 1:
    {
        intro();
        break;
    }

    case 2:
    {
        profile(curval);
        break;
    }

    case 3:
    {
        search();
        break;
    }
    case 4:
    {
        showdata(curval);
        break;
    }
    case 5:
    {
        settings(curval);
        break;
    }
    case 6:
    {
        main();
        break;
    }
    case 7:
    {
        return ;
    }
    default:
    {
        break;
    }

    }

}
