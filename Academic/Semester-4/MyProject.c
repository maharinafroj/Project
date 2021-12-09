#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

#define FEE 35000

#define black 0
#define blue 11
#define green 26
#define yellow 2742
#define violet 1
#define red 444
#define pink 29
#define golden 22
#define ash 24
#define silver 7
#define white 15

typedef struct user
{
    char name[50],id[20],pass[50],mail[50];
    char dob[10];
} mod;

typedef struct student
{
    unsigned long long int id;
    char name[20];
    char ID[20];
    int semester,score,penalty,total;
    char tname[50];
    char cname[50];
    struct member
    {
        unsigned long long int id;
        char name[20];
    } member[2];
} student;
struct junior_student
{
    int semester;
    long long int id;
    int number;
    int waiver;
    int penalty;
};

struct senior_student
{
    int semester;
    long long int id;
    int number;
    int waiver;
    int penalty;
};

struct icpc
{
    char t_name[100];
    int number;
    int penalty;
};

int main()
{
hm:
    home();
    int n,choice,id=123,pass=1;
    char retypepass[50];
    mod u[1000];
    scanf("%d",&n);
    if(n==1)
    {
        system("cls");
        int i,p,o;
pp:
        printf("\tID: ");
        scanf("%d",&i);
        printf("\tPass: ");
        Color(black);
        scanf("%d",&p);
        Color(white);
        if(i==id && p==pass)
        {
            do
            {
                system("cls");
                printf("\t\t\tLog in Successful\n\n");
ap:
                printf("\t 1. CREATE");
                printf("\n\t 2. DISPLAY");
                printf("\n\t 3. ADD");
                printf("\n\t 4. SEARCH");
                printf("\n\t 5. UPDATE");
                printf("\n\t 6. DELETE");
                printf("\n\t 7. SORT BY TOTAL DESC - ON SCREEN");
                printf("\n\t 8. Back");

                printf("\n\nSelect an option- ");
                scanf("%d",&choice);
spos:
                switch(choice)
                {
                case 1:
                    system("cls");
                    printf("\n");
                    create();
                    printf("\n\t\t\tCreated Successfully\n");
                    printf("press any key");
                    getch();
                    system("cls");
                    goto ap;
                    break;
                case 2:
                    system("cls");
                    display();
                    printf("\n\n\t\t\tpress any key");
                    getch();
                    system("cls");
                    goto ap;
                    break;
                case 3:
                    system("cls");
                    printf("\n");
                    add();
                    printf("\n\t\t\tAdded Successfully\n");
                    printf("press any key");
                    getch();
                    system("cls");
                    goto ap;
                    break;
                case 4:
                    system("cls");
                    search();
                    printf("\n\npress any key");
                    getch();
                    system("cls");
                    goto ap;
                    break;
                case 5:
                    system("cls");
                    update();
                    printf("\n\npress any key");
                    getch();
                    system("cls");
                    goto ap;
                    break;
                case 6:
                    system("cls");
                    delete_rec();
                    printf("\n\npress any key");
                    getch();
                    system("cls");
                    goto ap;
                    break;
                case 7:
                    system("cls");
                    contest();
                    printf("\n\npress any key");
                    getch();
                    system("cls");
                    goto ap;
                    break;
                }
            }
            while(choice!=8);
        }
        else
        {
            system("cls");
dp:
            printf("\t\t\tInvalid id or password.\n\n");
            printf("\t1. Try again\n\t2. Home\n\nSelect an option- ");
            scanf("%d",&o);
            if(o==1)
            {
                system("cls");
                goto pp;
            }
            if(o==2)
            {
                system("cls");
                goto hm;
            }
            else
            {
                system("cls");
                goto dp;
            }
        }
    }

    if(n==2)
    {
        system("cls");
        registration();
        printf("1. Home\n2. Exit\n");
        int w;
        scanf("%d",&w);
        if(w==1)
        {
            system("cls");
            goto hm;
        }
        else if(w==2)
            goto exitpos2;
    }

    if(n==3)
    {
        system("cls");
        char id[20],pass[50];
        int ret,option,val;
lp:
        printf("\n\tEnter ID: ");
        scanf("%s",id);
        printf("\n\tEnter Password: ");
        Color(black);
        scanf("%s",pass);
        Color(white);
        ret=login(id,pass);
        if(ret==1)
        {
            system("cls");
            printf("\t\t\tLog in Successful\n\n");
lp2:
            printf("\tMain Menu\n\n");
            printf("\t1. Contest result\n\t2. ICPC result\n\t3. NCPC\n\t4. NGPC\n\t5. Contest Registration\n\t6. Home\n\t7. Exit\n");
            printf("\n\nSelect an option- ");
            scanf("%d",&option);
            if(option==1)
            {
                system("cls");
                val = contest();
                getch();
                system("cls");
            }
            if(option==2)
            {
                system("cls");
                val = icpc();
                printf("\n\npress any key");
                getch();
                system("cls");
            }
            if(option==3)
            {
                system("cls");
                ncpc();
                printf("\n\npress any key");
                getch();
                system("cls");
                goto lp2;
            }
            if(option==4)
            {
                system("cls");
                ngpc();
                printf("\n\npress any key");
                getch();
                system("cls");
                goto lp2;
            }
            if(option==5)
            {
                system("cls");
                input();
                printf("\npress any key");
                getch();
                system("cls");
                goto lp2;
            }
            if(option==6)
            {
                system("cls");
                goto hm;
            }
            if(option==7)
            {
                system("cls");
                goto exitpos2;
            }
            else
            {
                system("cls");
                goto lp2;
            }
        }
        if(ret==0)
        {
            system("cls");
            printf("\t\t\tInvalid user ID or Password! try again...\n\n");
            goto lp;
        }
    }
    if(n==4)
    {
        system("cls");
        noticeread();
        getch();
        system("cls");
        goto hm;
    }
    if(n==5)
    {
        system("cls");
        achievements();
        getch();
        system("cls");
        goto hm;
    }
exitpos:
    if(n==6)
    {
exitpos2:
        system("cls");
        printf("\n\n\n\n\n\t\t\t  Are You Sure?\n");
        printf("\n\t\t  1.Yes\t\t\t  2.No\n\n\t\t\t\t");
        int ex;
        scanf("%d",&ex);
        if(ex==1)
            exit(0);
        else if(ex==2)
        {
            system("cls");
            goto hm;
        }
        else
            goto exitpos;
    }
    else
    {
        system("cls");
        goto hm;
    }
    return 0;
}

void home()
{
    printf("\t\t\tBUBT Programming Contest Manager\n\n");
    printf("\t1. Administration Panel\n");
    printf("\t2. User Registration\n");
    printf("\t3. Log in\n");
    printf("\t4. Notice\n");
    printf("\t5. Our Achievements\n");
    printf("\t6. Exit\n");
    printf("\nSelect an option- ");
}

void noticeread()
{
    FILE *notF;
    char ch;
    notF = fopen("notice.txt","r");
    if(notF==NULL)
        printf("File Doesn't exits\n");
    else
    {
        while(!feof(notF))
        {
            ch = fgetc(notF);
            printf("%c",ch);
        }
        printf("\n\n");
        fclose(notF);
    }
}

void achievements()
{
    FILE *achvF;
    char ch;
    achvF = fopen("achivements.txt","r");
    if(achvF==NULL)
        printf("File doesn't exits\n");
    else
    {
        while(!feof(achvF))
        {
            ch = fgetc(achvF);
            printf("%c",ch);
        }
        printf("\n\n");
        fclose(achvF);
    }
}

void Color(int ForgC)
{
    WORD wColor;
    //We will need this handle to get the current background attribute
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if (GetConsoleScreenBufferInfo(hStdOut, & csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return 0;
}

void create()
{
    student *s;
    FILE *fp;
    FILE *fp1;
    int n, i, j;
    printf("Enter how many students you want : ");
    scanf("%d",&n);

    s = (student*)calloc(n, sizeof(student));
    fp = fopen("mystudents.txt","a");

    for(i=0; i<n; i++)
    {

        printf("Enter ID: ");
        scanf("%s",s[i].ID);
        printf("Enter Name : ");
        scanf("%s",s[i].name);
        printf("Enter Semester: ");
        scanf("%d",&s[i].semester);
        printf("Enter Score: ");
        scanf("%d",&s[i].score);
        printf("Enter Penalty: ");
        scanf("%d",&s[i].penalty);
        s[i].total = s[i].score - s[i].penalty;
        fprintf(fp,"\n%s %s %d %d %d %d",s[i].ID,s[i].name,s[i].semester,s[i].score,s[i].penalty,s[i].total);
    }
    fclose(fp);


        fp1 = fopen("input.txt","a");
        for(int i=0;i<n;i++){
        fprintf(fp1,"\n%d %s %d %d",s[i].semester,s[i].ID,s[i].score,s[i].penalty);
        }
        fclose(fp1);

}
void regAccess(){
student s[1000];
FILE *fp=fopen("reg.txt","r");




}
void display()
{
    student s1[1000];
    FILE *fp;
    char read[300];
    int i=0,j;
    fp = fopen("mystudents.txt","r");
    if(fp==NULL){
    printf("\n\t\t\t\t\tFile:mystudents.txt is missing!");
     }
    while(!feof(fp)){
    if(fgets(read,1000,fp)==NULL){
    break;
     }
    sscanf(read,"%s %s %d %d %d %d",s1[i].ID,s1[i].name,&s1[i].semester,&s1[i].score,&s1[i].penalty,&s1[i].total);
    i++;
    }

    for(j=0;j<i;j++){
    printf("ID:%s  NAME:%s  Semester:%d  Solved:%d  Penalty:%d\n",s1[j].ID,s1[j].name,s1[j].semester,s1[j].score,s1[j].penalty);
    }
    printf("\n\nTotal Records: %d\n",i);
    fclose(fp);
}





void add()
{
 create();
}

void search()
{
    int found = 0;
    char id[20];
    printf("Enter ID to Search : ");
    scanf("%s",id);
    student s1[1000];
    FILE *fp;
    char read[300];
    int i=0,j;
    fp = fopen("mystudents.txt","r");
    if(fp==NULL){
    printf("\n\t\t\t\t\tFile:mystudents.txt is missing!");
     }
    while(!feof(fp)){
    if(fgets(read,1000,fp)==NULL){
    break;
     }
    sscanf(read,"%s %s %d %d %d %d",s1[i].ID,s1[i].name,&s1[i].semester,&s1[i].score,&s1[i].penalty,&s1[i].total);
    i++;
    }

    for(j=0;j<i;j++){
    if(strcmp(id,s1[j].ID)==0){
    found=1;
    printf("ID:%s  NAME:%s  Semester:%d  Solved:%d  Penalty:%d  Total:%d\n",s1[j].ID,s1[j].name,s1[j].semester,s1[j].score,s1[j].penalty,s1[j].total);
    }
    }
    if(found!=1){
    printf("Record not found!!!");
    }

    fclose(fp);
}

void update()
{
int found = 0;
    char id[20],name[20];
    int sem,score,panelty,total;
    printf("Enter ID to UPDATE : ");
    scanf("%s",id);
    student s1[1000];
    FILE *fp,*fpp,*fp1;
    char read[300];
    int i=0,j;
    fp = fopen("mystudents.txt","r");
    if(fp==NULL){
    printf("\n\t\t\t\t\tFile:mystudents.txt is missing!");
     }
    while(!feof(fp)){
    if(fgets(read,1000,fp)==NULL){
    break;
     }
    sscanf(read,"%s %s %d %d %d %d",s1[i].ID,s1[i].name,&s1[i].semester,&s1[i].score,&s1[i].penalty,&s1[i].total);
    i++;
    }
    fclose(fp);
     fpp = fopen("mystudents.txt","w");

    for(j=0;j<i;j++){
    if(strcmp(id,s1[j].ID)==0){
    found=1;
    printf("Enter New Name : ");
            scanf("%s",s1[j].name);
            printf("Enter New Semester: ");
            scanf("%d",&s1[j].semester);
            printf("Enter New Score: ");
            scanf("%d",&s1[j].score);
            printf("Enter New Penalty: ");
            scanf("%d",&s1[j].penalty);
            s1[j].total = s1[j].score - s1[j].penalty;
    }
    fprintf(fpp,"%s %s %d %d %d %d\n",s1[j].ID,s1[j].name,s1[j].semester,s1[j].score,s1[j].penalty,s1[j].total);

    }
    fclose(fpp);
    fp1 = fopen("input.txt","w");
    for(int j=0;j<i;j++){
    fprintf(fp1,"%d %s %d %d\n",s1[j].semester,s1[j].ID,s1[j].score,s1[j].penalty);

    }

    if(found!=1){
    printf("Record not found!!!");
    }

    fclose(fp1);
}

void delete_rec()
{
    student s1[1000];
    FILE *fp, *fp1, *fp2;
    int i=0,j,found = 0;
    char id[20],read[300];
    printf("Enter ID to delete:");
    scanf("%s",id);
    fp = fopen("mystudents.txt","r");
    if(fp==NULL){
    printf("\n\t\t\t\t\tFile:mystudents.txt is missing!");
     }
    while(!feof(fp)){
    if(fgets(read,1000,fp)==NULL){
    break;
     }
    sscanf(read,"%s %s %d %d %d %d",s1[i].ID,s1[i].name,&s1[i].semester,&s1[i].score,&s1[i].penalty,&s1[i].total);
    if(strcmp(id,s1[i].ID)==0){
    j=i;
    }
    i++;
    }
    found=j;
    if(found){
    fclose(fp);
    fp1= fopen("mystudents.txt","w");
    for(int k=0;k<i;k++){
    if(k!=j){
    fprintf(fp1,"%s %s %d %d %d %d\n",s1[k].ID,s1[k].name,s1[k].semester,s1[k].score,s1[k].penalty,s1[k].total);
    }
    }
    fclose(fp1);

    fp2= fopen("input.txt","w");
    for(int k=0;k<i;k++){
    if(k!=j){
    fprintf(fp1,"%d %s %d %d\n",s1[k].semester,s1[k].ID,s1[k].score,s1[k].penalty);
    }
    }

    fclose(fp2);
    }
    else
    printf("record not found");

    }

void sort_total_on_screen()
{
    student *s, s1;
    FILE *fp;
    int i,j;
    fp = fopen("mystudents.txt","r");
    fseek(fp,0,SEEK_END);
    int n = ftell(fp)/sizeof(student);
    s = (student*)calloc(n,sizeof(student));
    rewind(fp);
    for(i=0; i<n; i++)
        fread(&s[i],sizeof(student),1,fp);
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(s[i].total < s[j].total)
            {
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        printf("\n%-5llu",s[i].id);
        printf("%9s",s[i].name);
        printf("%4llu",s[i].semester);
        printf("%4llu",s[i].score);
        printf("%4llu",s[i].penalty);
        printf("%5llu",s[i].total);
    }
    fclose(fp);
}

void sort_total_in_file()
{
    student *s, s1;
    FILE *fp;
    int i,j;
    fp = fopen("mystudents.txt","r");
    fseek(fp,0,SEEK_END);
    int n = ftell(fp)/sizeof(student);
    s = (student*)calloc(n,sizeof(student));
    rewind(fp);

    for(i=0; i<n; i++)
        fread(&s[i],sizeof(student),1,fp);
    fclose(fp);

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(s[i].total < s[j].total)
            {
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }
    }
    fp = fopen("mystudents.txt","w");
    for(i=0; i<n; i++)
    {
        printf("\n%-5llu",s[i].id);
        printf("%9s",s[i].name);
        printf("%4llu",s[i].semester);
        printf("%4llu",s[i].score);
        printf("%4llu",s[i].penalty);
        printf("%5llu",s[i].total);
        fwrite(&s[i],sizeof(student),1,fp);
    }
    fclose(fp);
}
int count_student(){
student s1[1000];
    FILE *fp;
    char read[300];
    int i=0,j;
    fp = fopen("mystudents.txt","r");
    if(fp==NULL){
    printf("\n\t\t\t\t\tFile:mystudents.txt is missing!");
     }
    while(!feof(fp)){
    if(fgets(read,1000,fp)==NULL){
    break;
     }
    sscanf(read,"%s %s %d %d %d %d",s1[i].ID,s1[i].name,&s1[i].semester,&s1[i].score,&s1[i].penalty,&s1[i].total);
    i++;
    }
    return i;
}
int login(char idno[],char password[])
{
    char read[200];
    mod user[100]; //max number of user
    int i=0;
    int ret=0;
    FILE *fp=fopen("reg.txt","r");
    if(fp==NULL)
    {
        printf("\nFile:reg.txt is missing!");
    }
    while(!feof(fp))
    {
        if(fgets(read,200,fp)==NULL)
        {
            break;
        }
        sscanf(read,"%s %s %s %s %s",user[i].name,user[i].id,user[i].mail,user[i].pass,user[i].dob);
        i++;
    }
    fclose(fp);
    for(int i=0; i<100; i++)
    {
        if(strcmp(idno,user[i].id)==0 && strcmp(password,user[i].pass)==0)
            ret=1;
    }
    return ret;
}

void registration()
{
    char name[50],id[20],mail[50],pass[50],pass2[50],dob[20];
    FILE *reg=fopen("reg.txt","a");
    position1:
    printf("Username: ");
    scanf("%s",name);
    printf("Enter your id: ");
    scanf("%s",id);
    printf("Enter your mail: ");
    scanf("%s",mail);
    printf("Enter your pass: ");
    Color(black);
    scanf("%s",pass);
    Color(white);
    printf("Retype your pass: ");
    Color(black);
    scanf("%s",pass2);
    Color(white);
    if(strcmp(pass,pass2)==0)
    {
        printf("Date of birth: ");
        scanf("%s",dob);
        printf("\nAre you sure the following information are correct?\n\n");
        printf("\t\tName: %s\n\t\tID  : %s\n\t\tMail: %s\n\t\tDOB : %s\n\t\t",name,id,mail,dob);
        printf("\n1. Procced\n2. Try again\n\t\t");
        int optionreg;
        scanf("%d",&optionreg);
        if(optionreg==1)
        {
            fprintf(reg,"%s %s %s %s %s\n",name,id,mail,pass,dob);
            system("cls");
            printf("\n\t\t\tRegistration Successful\n");
        }
        else
        {
            system("cls");
            goto position1;
        }
    }
    else
    {
        system("cls");
        printf("\t\t\tYour password doesn't match.Try again.\n\n");
        goto position1;
    }
    fclose(reg);
}
void ncpc()
{
    FILE *NCPC;
    char ch;
    NCPC = fopen("Ncpc.txt","r");
    if(NCPC==NULL)
        printf("File Doesn't exits\n");
    else
    {
        while(!feof(NCPC))
        {
            ch = fgetc(NCPC);
            printf("%c",ch);
        }
        printf("\n\n");
        fclose(NCPC);
    }
}
void ngpc()
{
    FILE *NGPC;
    char ch;
    NGPC = fopen("Ngpc.txt","r");
    if(NGPC==NULL)
        printf("File Doesn't Exits\n");
    else
    {
        while(!feof(NGPC))
        {
            ch = fgetc(NGPC);
            printf("%c",ch);
        }
        printf("\n\n");
        fclose(NGPC);
    }
}
int contest()
{
    FILE *fp;
    fp = fopen("input.txt", "r");
    int n=count_student();
    ///printf("Enter the number of students: ");
    //fscanf(fp, "%d", &n);

    struct junior_student st_j[n], temp_j;
    struct senior_student st_s[n], temp_s;

    int i, j, sem, count_j = 0, count_s = 0;

    for(i = 0; i < n; i++)
    {
        ///printf("Semester: ");
        fscanf(fp, "%d", &sem);
        if(sem >= 1 && sem <= 4)
        {
            st_j[count_j].semester = sem;
            ///printf("Enter ID of student %d: ", i+1);
            fscanf(fp, "%lld", &st_j[count_j].id);
            ///printf("Enter number of student %d: ", i+1);
            fscanf(fp, "%d", &st_j[count_j].number);
            ///printf("Enter penalty of student %d: ", i+1);
            fscanf(fp, "%d", &st_j[count_j].penalty);

            count_j++;
        }
        else if(sem >= 5 && sem <= 8)
        {
            st_s[count_s].semester = sem;
            ///printf("Enter ID of student %d: ", i+1);
            fscanf(fp, "%lld", &st_s[count_s].id);
            ///printf("Enter number of student %d: ", i+1);
            fscanf(fp, "%d", &st_s[count_s].number);
            ///printf("Enter penalty of student %d: ", i+1);
            fscanf(fp, "%d", &st_s[count_s].penalty);

            count_s++;
        }
    }

    //printf("Input is taken from the file named input.txt \n");
    fclose(fp);

    ///sort based on number
    ///sort_st_j
    for(i = 0; i < count_j; i++)
    {
        for(j = 1; j < count_j; j++)
        {
            if(st_j[j].number > st_j[j-1].number)
            {
                temp_j = st_j[j];
                st_j[j] = st_j[j-1];
                st_j[j-1] = temp_j;
            }
        }
    }


    ///sort_st_s
    for(i = 0; i < count_s; i++)
    {
        for(j = 1; j < count_s; j++)
        {
            if(st_s[j].number > st_s[j-1].number)
            {
                temp_s = st_s[j];
                st_s[j] = st_s[j-1];
                st_s[j-1] = temp_s;
            }
        }
    }

    ///sort based on penalty
    ///sort_st_j
    for(i = 0; i < count_j; i++)
    {
        for(j = 1; j < count_j; j++)
        {
            if(st_j[j].number == st_j[j-1].number && st_j[j].penalty < st_j[j-1].penalty)
            {
                temp_j = st_j[j];
                st_j[j] = st_j[j-1];
                st_j[j-1] = temp_j;
            }
        }
    }


    ///sort_st_s
    for(i = 0; i < count_s; i++)
    {
        for(j = 1; j < count_s; j++)
        {
            if(st_s[j].number == st_s[j-1].number && st_s[j].penalty < st_s[j-1].penalty)
            {
                temp_s = st_s[j];
                st_s[j] = st_s[j-1];
                st_s[j-1] = temp_s;
            }
        }
    }


    ///waiver and semester fee
    //Junior
    for(i = 0; i < count_j; i++)
    {
        if(i < 3)
            st_j[i].waiver = 40;
        else if(i < 6)
            st_j[i].waiver = 25;
        else
            st_j[i].waiver = 0;
    }
    //Senior
    for(i = 0; i < count_s; i++)
    {
        if(i < 3)
            st_s[i].waiver = 40;
        else if(i < 6)
            st_s[i].waiver = 25;
        else
            st_s[i].waiver = 0;
    }

wrong:
    printf("\n\t\t1. For individual result\n\t\t2. For total result\n");
    printf("\nSelect an option- ");

    int result_switch;
    scanf("%d", &result_switch);
    system("cls");

    if(result_switch == 1)
    {
        long long int temp_id;
        printf("Enter your ID: ");
        scanf("%lld", &temp_id);


        for(i = 0; i < count_j; i++)
        {
            if(st_j[i].id == temp_id)
                break;
        }
        if(i != count_j)
        {
            printf("Rank  Semester  ID No     Score   Penalty    Waiver (JUNIOR)\n");
            printf("%d        %d      %lld    %d      %d        %.2f tk (%d %%)\n", i+1, st_j[i].semester, st_j[i].id, st_j[i].number, st_j[i].penalty, ((float)st_j[i].waiver/100 * FEE), st_j[i].waiver);
        }
        ///..................


        for(i = 0; i < count_s; i++)
        {
            if(st_s[i].id == temp_id)
                break;
        }
        if(i != count_s)
        {
            printf("Rank  Semester  ID No     Score   Penalty    Waiver (SENIOR)\n");
            printf("%d        %d      %lld    %d      %d        %.2f tk (%d %%)\n", i+1, st_s[i].semester, st_s[i].id, st_s[i].number, st_s[i].penalty, ((float)st_s[i].waiver/100 * FEE), st_s[i].waiver);
        }
    }

    else if(result_switch == 2)
    {
        printf("Rank  Semester  ID No     Score   Penalty    Waiver (JUNIOR)\n");

        for(i = 0; i < count_j; i++)
        {
            printf("%d        %d      %lld    %d      %d        %.2f tk (%d %%)\n", i+1, st_j[i].semester, st_j[i].id, st_j[i].number, st_j[i].penalty, ((float)st_j[i].waiver/100 * FEE), st_j[i].waiver);
        }
        printf("Rank  Semester  ID No     Score   Penalty    Waiver (SENIOR)\n");

        for(i = 0; i < count_s; i++)
        {
            printf("%d        %d      %lld    %d      %d        %.2f tk (%d %%)\n", i+1, st_s[i].semester, st_s[i].id, st_s[i].number, st_s[i].penalty, ((float)st_s[i].waiver/100 * FEE), st_s[i].waiver);
        }
    }
    else
    {
        printf("You have entered a wrong number.\n\n");
        goto wrong;
    }

    return 1;
}

int icpc()
{
    FILE *fp;
    fp = fopen("icpc.txt", "r");

//    printf("Inputs are taken from file named icpc.txt\n");
    int n, i, j;
    fscanf(fp, "%d", &n);

    struct icpc st[n], temp;
    for(i = 0; i < n; i++)
    {
        ///printf("Team name : ");
        fscanf(fp, "%s", st[i].t_name);

        ///printf("Solve number : ");
        fscanf(fp, "%d", &st[i].number);

        ///printf("Penalty : ");
        fscanf(fp, "%d", &st[i].penalty);
    }
    ///sort_based_solved_number
    for(i = 0; i < n; i++)
    {
        for(j = 1; j < n; j++)
        {
            if(st[j].number > st[j-1].number)
            {
                temp = st[j];
                st[j] = st[j-1];
                st[j-1] = temp;
            }
        }
    }
    ///sort based on penalty
    for(i = 0; i < n; i++)
    {
        for(j = 1; j < n; j++)
        {
            if(st[j].number == st[j-1].number && st[j].penalty < st[j-1].penalty)
            {
                temp = st[j];
                st[j] = st[j-1];
                st[j-1] = temp;
            }
        }
    }
    printf("Sorted: \n");
    for(i = 0; i < n; i++)
    {
        printf("Rank   Team Name     Number     Penalty\n");
        printf("%d     %s         %d       %d\n", i+1, st[i].t_name, st[i].number, st[i].penalty);
    }
    return 1;
}

void input()
{
    student *s;
    FILE *fp;
    int p,i,j,n=1;

    s = (student*)calloc(n, sizeof(student));
    fp = fopen("contestreg.txt","a");

    for(i=0; i<n; i++)
    {
        printf("\nWhich Contest: ");
        scanf(" %[^\n]s",s[i].cname);
        printf("\nTeam Name: ");
        scanf(" %[^\n]s",s[i].tname);
        printf("\nEnter how many team members: ");
        scanf("%d",&p);
        for(j=0; j<p; j++)
        {
            printf("\nEnter ID: ");
            scanf("%llu",&s[i].member[j].id);
            fflush(stdin);
            printf("\nMember Name: ");
            scanf("%[^\n]s",s[i].member[j].name);
        }
        fwrite(&s[i],sizeof(student),1,fp);
    }
    fclose(fp);
    Color(blue);
    printf("\n\t\t--------Information has been uploaded successfully--------\n");
    Color(white);
}
