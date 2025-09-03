
/*Q1. Write a menu driven program for Date in a C. Declare a structure Date having data members 
day, month, year. Implement the following functions. 
void initDate(struct Date* ptrDate); 
void printDateOnConsole(struct Date* ptrDate); 
void acceptDateFromConsole(struct Date* ptrDate); */
#include<stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

void initDate(struct Date *ptrDate)
{
    ptrDate->day = 10;
    ptrDate->month=4;
    ptrDate->year=2025;

    
}
void printDateOnConsole(struct Date *ptrDate)
{
printf("Day : %d\n",ptrDate->day);
printf("Month : %d\n",ptrDate->month);
printf("Year : %d\n",ptrDate->year);

}

void acceptDateFromConsole(struct Date *ptrDate){
printf("Enter Date: \n");
scanf("%d",&ptrDate->day);

printf("Enter Month: \n");
scanf("%d",&ptrDate->month);

printf("Enter Year: \n");
scanf("%d",&ptrDate->year);
}

int main()
{
    struct Date d;

    initDate(&d);
    printDateOnConsole(&d);
    acceptDateFromConsole(&d);
    printDateOnConsole(&d);

    return 0;
    
    
}