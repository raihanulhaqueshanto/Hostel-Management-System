#include <stdio.h>
#include <string.h>
void main_menu(); //THE MAIN SCREEN OF THE SYSTEM WHICH CONTAINS ALL THE INSTRUCTIONS.
void backkey(); //TAKES THE USER BACK TO THE MAIN MENU AFTER PERFORMING ANY OPERATION.
void add_student();//ADDS STUDENT AND THEIR INFOS IN STRUCTURE.
void search_student();//SEARCHES A ROOM TO GET THE DETAILS OF A STUDENT.
void student_list();//DISPLAYS ALL THE INFOS OF ALL THE STUDENTS AND SAVES IT TO A TEXT FILE.
//HERE WE CREATED AND DECLARED THE STRUCTURE
struct student
{
    char name[50];
    char father_name[50];
    char mother_name[50];
    char gender[15];
    int age;
    char claSS[15];
    int phone;
    int guardian_phone;
    int room;

} stu[200];
//THE HOSTEL HAS ONLY 200 ROOMS FOR NOW.
int n;
//MADE THIS GLOBAL BECAUSE ALMOST ALL THE FUNCTIONS ARE GOING TO USE THIS :3
int main()
{
    main_menu();

    return 0;
}
void main_menu()
{
    printf("********************************************************************************\n");
    printf("********************************************************************************\n");
    printf(" \n");
    printf("\t  Welcome to North South University Hostel Management System \n");
    printf("\t              A Nice Place to Live and Study\n");
    printf("\n");
    printf("********************************************************************************\n");
    printf("********************************************************************************\n");
    printf(" \n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf(" \n");
    printf("Press linked numbers to perform operations \n");
    printf("1-Add Student \n");
    printf("2-Search Student\n");
    printf("3-Check Student List\n");
    //  printf("4-Delete Students\n");
    printf(" \n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf(" \n");
    printf("\nPress any number:\n");
    int x;
    scanf("%d",&x);
    switch(x)
    {
    case 1:
        add_student();
        break;
    case 2:
        search_student();
    case 3:
        student_list();
    default:
        main_menu();
    }




}
void add_student()
{
    int i;
    printf("How many students you want to entry now?\n");
    scanf("%d",&n);
    printf("Enter required fields: \n");
    for(i=0; i<n; i++)
    {
        printf("-----------------------------------------\n");
        printf("Enter Name for Student %d: \n",i+1);
        scanf("%s", stu[i].name);
        printf("Enter Name for Student's Father %d: \n",i+1);
        scanf("%s", stu[i].father_name);
        printf("Enter Name for Student's Mother %d: \n",i+1);
        scanf("%s",stu[i].mother_name);
        printf("Enter Gender for Student %d: \n",i+1);
        scanf("%s",stu[i].gender);
        printf("Enter Age for Student %d: \n",i+1);
        scanf("%d", &stu[i].age);
        printf("Enter Class for Student %d: \n",i+1);
        scanf("%s",stu[i].claSS);
        printf("Enter Phone for Student %d: \n",i+1);
        scanf("%d", &stu[i].phone);
        printf("Enter Phone for Guardian %d: \n",i+1);
        scanf("%d", &stu[i].guardian_phone);
        printf("Enter Assigned room no for Student %d: \n",i+1);
        scanf("%d", &stu[i].room);
        printf("Data entry for student %d completed!\n",i+1);
        printf("\n");
    }
    backkey();
}
void search_student()
{
    printf("Enter the room number of the Student to search: \n");
    int search,i;
    scanf("%d",&search);
    for(i=0; i<n; i++)
    {
        if(search == stu[i].room)
        {
            printf("Details of the Student assigned to room %d: \n",search);
            printf("Name: %s \n",stu[i].name);
            printf("Father's Name: %s\n",stu[i].father_name);
            printf("Mother's Name: %s\n",stu[i].mother_name);
            printf("Gender: %s\n",stu[i].gender);
            printf("Age: %d\n",stu[i].age);
            printf("Class: %s\n",stu[i].claSS);
            printf("Student's Phone No: +88 0%d\n",stu[i].phone);
            printf("Guardian's Phone No: +88 0%d\n",stu[i].guardian_phone);
            printf("Room No: %d\n",stu[i].room);
        }
    }
    backkey();

}
void student_list()
{
    printf("Here is the list of all the Students: \n");
    int i;
    for(i=0; i<n; i++)
    {
        printf("-----------------------------------------------\n");
        printf("Details of the Student assigned to room %d: \n",i+1);
        printf("Name: %s \n",stu[i].name);
        printf("Father's Name: %s\n",stu[i].father_name);
        printf("Mother's Name: %s\n",stu[i].mother_name);
        printf("Gender: %s\n",stu[i].gender);
        printf("Age: %d\n",stu[i].age);
        printf("Class: %s\n",stu[i].claSS);
        printf("Student's Phone No:+88 0%d\n",stu[i].phone);
        printf("Guardian's Phone No:+88 0%d\n",stu[i].guardian_phone);
        printf("Room No: %d\n",stu[i].room);
        printf(" \n");
    }
    //HERE WE ARE USING FILES
    FILE *p,*q;
    p = fopen("StudentList.txt","w");
    q = fopen("StudentList.txt","r");
    for(i=0; i<n; i++)
    {
        fprintf(p,"Details of the Student assigned to room %d: \n",i+1);
        fprintf(p,"Name: %s \n",stu[i].name);
        fprintf(p,"Father's Name: %s\n",stu[i].father_name);
        fprintf(p,"Mother's Name: %s\n",stu[i].mother_name);
        fprintf(p,"Gender: %s\n",stu[i].gender);
        fprintf(p,"Age: %d\n",stu[i].age);
        fprintf(p,"Class: %s\n",stu[i].claSS);
        fprintf(p,"Student's Phone No: %d\n",stu[i].phone);
        fprintf(p,"Guardian's Phone No: %d\n",stu[i].guardian_phone);
        fprintf(p,"Room No: %d\n",stu[i].room);
        fprintf(p," \n");
    }
    fclose(p);
    backkey();
}
void backkey()
{
    printf("Enter 0 to return to main menu\n");
    int backkey;
    scanf("%d",&backkey);
    if(backkey == 0)
        main_menu();
    else
        printf("Error! you pressed the wrong key!");
}
