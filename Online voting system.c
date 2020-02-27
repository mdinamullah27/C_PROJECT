#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#define PWD "fivestar"
#define UN "FIVESTAR"
typedef struct voter_information
{
    char name[20];
    long int id;
    char m_name[50];
    char f_name[50];
    char b_date[30];
    struct voter_information *next;
} node;
void menu();
void main_logs();
void voter_insert();
void admin();
void admin_password();
void winner();
void exit_msg();
void adminpassword();
int pin();
node *head=NULL;
int count1=0,count2=0,count3=0,c=0;

int main()
{
    welcome_message();
    system("cls");
    printf("\n\n\n");
    printf("\n\n\n");
     printf("\t\t\tWELCOME TO ONLINE VOTING SYSTEM\n");
     printf("\t\t\t________________________________\n\n");
     printf("\t\t\tPRESS 1 FOR LOGING VOTE MAIN LOGS\n");
     int b;
     system("COLOR 10");
    scanf("%d",&b);
     while(b!=1){
            printf("Invalid choice!!!!!!\n");
            printf("\t\t\tAGAIN PRESS 1 FOR LOGING VOTE MAIN LOGS\n");
            scanf("%d",&b);
             }
     main_logs();
     return 0;

}
void welcome_message(void)
{
    system("COLOR B1");
    system("cls");
    printf("\n\n\t   WELCOME\n");
    Sleep(300);
    printf("\n    Online Voting System\n");
    Sleep(300);
    printf( "_______________________________________\n\n\n");
    Sleep(300);
    printf(" SUBMITTED TO\n\n");
    Sleep(300);
    printf("    Mahfuzur Rahman Raju\n");
    Sleep(300);
    printf("    Lecturer,\n    Daffodil International University\n\n");
    Sleep(300);
    printf(" Faculty Name\n");
    Sleep(300);
    printf("\t Computer Science & Engineering");
    Sleep(300);
    printf("\n\n");
    printf("\t\t\t\t\t");
    printf("SUBMITTED BY\n\n");
    Sleep(300);
    printf("\t\t\t\t\t");

    printf("\t\t\t\t\t");
    printf("INAM ULLAH KHAN(191-15-2575)\n");
    Sleep(300);


    fflush(stdin);
    printf("Press Enter a keyword to continue>>>");
    getch();
}


void main_logs()
{
    char menuOpt;
    int isExit = 0;
    system("COLOR E2");
    do
    {
        menu();
        fflush(stdin);
        menuOpt = (char)getch();
        switch(menuOpt)
        {
        case '1':
        {
            voter_insert();
            break;
        }
        case '2':
        {
            vote_entry();
            break;
        }
        case '3':
        {
            admin();
            break;
        }

        case '4':
        {
            winner();
            break;
        }
        case '5':
        {
            exit_msg();
            isExit = 1;
            fflush(stdin);
            break;
        }
        default:
        {
            system("cls");
            printf("Invalid Input!");
            getch();
        }
        }
    }
    while(isExit == 0);

}


void menu()
{
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t[1]. For voter Insert>>>\n\n");
    Sleep(300);
    printf("\t\t\t[2]. For vote entry>>>\n\n");
    Sleep(300);
    printf("\t\t\t[3]. For Admin panel>>>\n\n");
    Sleep(300);
    printf("\t\t\t[4]. For winer>>>\n\n");
    Sleep(300);
    printf("\t\t\t[5]. For Exit>>>\n\n");
    Sleep(300);

}


void voter_insert()
{
    system("cls");
    admin_password();
    system("cls");
    node *temp;
    long int id;
    char Ma_name[50];
    char Fa_name[50];
    char D_birth[30];
    char name[50];
    printf("\n\n\n");
    printf("\t\tEnter National Id of a Voter  :  ");
    fflush(stdin);
    scanf("%d",&id);
    printf("\n\t\tEnter Name of a Voter         :  ");
    fflush(stdin);
    gets(name);
    printf("\n\t\tEnter Father's Name of a Voter:  ");
    fflush(stdin);
    gets(Fa_name);
    printf("\n\t\tEnter Mother's Name of a Voter:  ");
    fflush(stdin);
    gets(Ma_name);
    printf("\n\t\tEnter Date of Birth of a Voter:  ");
    fflush(stdin);
    gets(D_birth);
    temp=(node*)malloc(sizeof(node));
    temp->id=id;
    strcpy(temp->name,name);
    strcpy(temp->f_name,Fa_name);
    strcpy(temp->m_name,Ma_name);
    strcpy(temp->b_date,D_birth);
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        node *p;
        p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }
    printf("\n\n\n");
}


void vote_entry()
{
   long long int  pin2;
   long long int k=pin();
    node *p;
    p=head;
    int n;
    int id;
    printf("\n\n\t\tEnter your National Id : ");

    scanf("%d",&id);

    while(p!=NULL)
    {
        if(p->id==id )
        {
         printf("A verification pin has send to your number \n pls Enter correct pin\n");

         Sleep(5000);
         system("cls");
         printf("\t\t\t\t\t\n\n\n\n\n\nYour pin is:%lld\n",k);
         scanf("%lld",&pin2);
         if(pin2==k)
          {

            voting();

          }
          else{
            printf("YOur pin is wrong!!!");
            break;
          }
        }
        else
        {
            printf("\n\n");
            Sleep(200);
            printf("\t\tYour Voter Id  is Wrong......\n");

            Sleep(200);
            printf("\t\tPlease Re_Enter....\n");
            Sleep(200);
             p=p->next;
        }


    }

}
void voting()
{
    int n;
    system("cls");
    printf("\n\n\n\t\t\t[1] Awami league(Boat)\n");
    Sleep(300);
    printf("\n\t\t\t[2] Bangladesh National Party(BNP)\n");
    Sleep(300);
    printf("\n\t\t\t[3] Bangladesh Jatio Party(BJP)\n\n\n\n");
    Sleep(300);
    printf("\tEnter your choice : ");
    fflush(stdin);
    scanf("%d",&n);
    if(n==1)
    {
        count1++;
    }
    else if(n==2)
    {
        count2++;
    }
    else if(n==3)
    {
        count3++;
    }
    else
    {
        printf("Invalid Input ,,,,,Try again\n");
    }

    printf("\n\n\n");
    printf("\t\t......You Have Give Your vote Successfully.......\n\n");
    Sleep(200);
    printf("\t\t......You Can't Give Vote More Than 1 Time.......\n\n");
    Sleep(200);
    printf("\t[1].For Present Winner....\n\n");
    printf("\t[2].For Exit....\n\n");
    Sleep(100);
    char t;

    t=(char)getch();

    switch(t)
    {
        case '1':
    {
        winner();
        break;
    }
    case '2':
    {
        exit_msg();
        break;
    }
    default:
    {
        printf("\t\tInvalid Input.....\n\n");
        break;
    }
    }

}
void admin()
{
    system("cls");
    admin_password();
    printf("\n\n\n");
    printf("\t\t\t[1].For show Votes : ");
    int s;
    scanf("%d",&s);
    if(s==1)
    {
        show();
    }
    else
    {
        Sleep(300);
        printf("Invalid Input\n");
    }
    printf("\n\n\n");
    Sleep(300);
    printf("\t\t\t[1].For Main Logs.....\n\n");
    Sleep(300);
    printf("\t\t\t[2].For Exit.....\n\n");

    char t;
    t=(char)getch();
    switch(t)
    {
    case '1':
    {
        main_logs();
        break;
    }
    case '2':
    {
        exit_msg();
        break;
    }
    default:
    {
        Sleep(300);
        printf("\t\tInvalid Input.....\n\n");
        break;
    }
    }
}
void show()
{
    system("cls");
    printf("\n\n");
    printf("\t\tAwami League Got  %d  Votes\n\n",count1);
    Sleep(300);
    printf("\t\tBNP Got  %d  Votes\n\n",count2);
    Sleep(300);
    printf("\t\tBJP Got  %d  Votes\n\n",count3);
    Sleep(300);
}
void winner()
{
    system("cls");
    if(count1>count2&&count1>count3)
    {
        Sleep(300);
        printf("\n\n\t\t>>>>>> Winner is Awami League >>>>>>\n\n");
        Sleep(300);
    }
    else if(count2>count3)
    {
        printf("\n\n\t\t>>>>>> Winner is Bangladesh National Party >>>>>>\n\n");
    }
    else
    {
        printf("\n\n\t\t>>>>>> Winner is Bangladesh Jatiyo Party >>>>>>\n\n");
    }
    char t;
    printf("\t[1].For Main Logs....\n\n");
    Sleep(100);
    printf("\t[2].For Exit....\n\n");
    t=(char)getch();
    switch(t)
    {
    case '1':
    {
        main_logs();
        break;
    }
    case '2':
    {
        exit_msg();
        break;
    }
    default:
    {
        Sleep(300);
        printf("\t\tInvalid Input.....\n\n");
        break;
    }
    }
}
void exit_msg()
{
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t\t\t\t....Thank You....\n\n\n\n\n\n");
    exit(0);

}
void admin_password()
{
    int i=0;
    char username[10];
    char password[10];
    system("COLOR 7");
    do
    {
        if(i>0)
        {
             system("cls");
            printf("\t\t\t\t\t\t\n\n\n\n\nInvalid Password\n");
            getch();
        }

        if(i>5)
        {
            printf("Access Denied\n");
            return;
        }
        else{
             system("cls");
        printf("\n\n\n\t\t\tEnter User Name >>>");
        fflush(stdin);
        gets(username);
        printf("\n\t\t\tEnter Password >>>");
        fflush(stdin);
        gets(password);
        i++;
        }
    }while(((strcmp(password, PWD)) != 0 || (strcmp(username, UN)) != 0));
}

//pin generate:
int pin()
{
    system("COLOR 4");
    long long int pin2;
    pin2 = rand()+rand()+rand()*11111;
    return pin2;
}





