/********************************************************/
/* Project Title: CALENDER IN C 		   	*/
/* Student Name1: ANKIT GARG	Enrollment # : 10103623	*/
/* Student Name2: RAJUL KUKREJA	Enrollment # : 10103509	*/
/* Batch        : B6 			               	*/
/********************************************************/





#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<process.h>
#include<ctype.h>

char *month[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
char *day[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
struct yr
{
int date;
int month;
int year;
}c,d;

struct memo
{
char note[50];
struct yr a;
}b;

void intro()
{
    int i,gd,n=0,gm,errorcode,x=0;
    clrscr();
    detectgraph(&gd,&gm);
    initgraph(&gd, &gm, "e:\\tc\\bgi" );
    errorcode=graphresult();
    if(errorcode!=grOk)
    {
    printf("graphics error %d", grapherrormsg(errorcode));
    getch();
    exit(0);
    }
    setcolor(6);
    setfillstyle(11,2);
    bar(0, 0, 640, 480);
    setfillstyle(SOLID_FILL,2);
    bar(50, 50, 590, 430);
    setfillstyle(1,14);
    bar(100, 100, 540, 380);
    settextstyle(4,0,3);
    outtextxy(150,110,"MADE BY...");
    outtextxy(200,150,"Ankit garg");
    outtextxy(250,175,"$");
    outtextxy(240,200,"Rajul kukreja");
    settextstyle(3,0,2);
    outtextxy(225,400,"Loading");
    while(x<=360)
    {
    if(x%100==0)
    {
    n++;
    for(i=0;i<n;i++)
    {
    settextstyle(3,0,2);
    outtextxy(300+10*i,400,".");
    delay(2);
    }
    }
    delay(10);
    setfillstyle(1,3) ;
    pieslice(490,330,0,x,40);
    x++;
    }
    setfillstyle(1, 14);
    bar(450,250,540,380);

    setfillstyle(SOLID_FILL,2);
    bar(225,385, 590, 430);
    randomize();
    while(!kbhit())
    {
    setcolor(random(15));
    settextstyle(3,0,2);
    outtextxy(175,300,"press any key to continue...");
    delay(50);
    }
closegraph();
}

void end()
{
int gd,gm,errorcode;
    clrscr();
    detectgraph(&gd,&gm);
    initgraph(&gd, &gm, "e:\\tc\\bgi" );
     errorcode=graphresult();
    if(errorcode!=grOk)
    {
    printf("graphics error %d", grapherrormsg(errorcode));
    getch();
    exit(0);
    }
    setcolor(12);
    setfillstyle(11,2);
    bar(0, 0, 640, 480);
    setfillstyle(SOLID_FILL,2);
    bar(50, 50, 590, 430);
    setfillstyle(1,14);
    bar(100, 100, 540, 380);
    settextstyle(5,0,5);
    outtextxy(200,200,"THANK YOU");
    getch();
closegraph();
}

char menu()
{
char ch;
int gd,gm,errorcode;
clrscr();
detectgraph(&gd,&gm);
initgraph(&gd, &gm, "e:\\tc\\bgi" );
errorcode=graphresult();
if(errorcode!=grOk)
    {
    printf("graphics error %d", grapherrormsg(errorcode));
    getch();
    exit(0);
    }
 setcolor(14);
 settextstyle(5,0,3);
 outtextxy(110,120,"1.Know the day");
 outtextxy(110,150,"2.Print the month");
 outtextxy(110,180,"3.Enter details to file");
 outtextxy(110,210,"4.print details from file");
 outtextxy(110,240,"0.EXIT");
 outtextxy(110,270,"ENTER YOUR CHOICE : ");
 setcolor(1);
 setlinestyle(0,2,1);
 rectangle(88,111,438,303);
 setcolor(5);
 rectangle(90,109,436,305);
 setcolor(9);
 rectangle(92,107,434,307);
 ch=getch();
 flushall();
 fflush(stdin);
 closegraph();
return ch;
}

int nofdays(int mm,int yy)
{
switch(mm)
   {
      case 1 : return(31);
      case 2 : if(yy%400==0)
	       return(29);
	       else if (yy%100==0)
	       return(28);
	       else if(yy%4==0)
	       return(29);
	       else
	       return(28);
      case 3 : return(31);
      case 4 : return(30);
      case 5 : return(31);
      case 6 : return(30);
      case 7 : return(31);
      case 8 : return(31);
      case 9 : return(30);
      case 10: return(31);
      case 11: return(30);
      case 12: return(31);
      default: return(-1);
   }
}
int getday(int dd,int mm,int yy)
{

/*
according to wikipedia...
web address: http://en.wikipedia.org/wiki/Calculating_the_day_of_the_week
-------------------------------------------------------------------------------------------
Centuries table
1700–1799     4     (Still Julian Calendar in Great Britain and its colonies until 1752)    
1800–1899     2
1900–1999     0
2000–2099     6
2100–2199     4
2200–2299     2
2300–2399     0
2400–2499     6
2500–2599     4
2600–2699     2
------------------------------------------------------------------------------------------
Months table
January      0 (in leap year 6)
February     3 (in leap year 2)
March        3
April        6
May          1
June         4
July         6
August       2
September    5
October      0
November     3
December     5
------------------------------------------------------------------------------------------
Days table
Sunday    0
Monday    1
Tuesday   2
Wednesday 3
Thursday  4
Friday    5
Saturday  6
------------------------------------------------------------------------------------------
this and methodology for getting daycode of a month is the base of this function taken from wikipedia.com
*/






int i,temp,t1=0,t2=0;
temp=6;
{

for(i=100;i<yy;i+=100)
{
if(temp<=0)
{
temp=6;
continue;
}
temp-=2;
}
}
temp+=(yy%100);
temp+=(yy%100)/4;
temp+=dd;
t2=nofdays(2,yy);
{
switch(mm)
{
      case 1 :if(t2==29)
		temp+=6;
	      else
		temp+=0;
	      break;
      case 2 :if(t2==29)
		temp+=2;
	      else
		temp+=3;
	      break;
      case 3 : temp+=3;
		break;
      case 4 : temp+=6;
		break;
      case 5 : temp+=1;
		break;
      case 6 : temp+=4;
		break;
      case 7 : temp+=6;
		break;
      case 8 : temp+=2;
		break;
      case 9 : temp+=5;
		break;
      case 10: temp+=0;
		break;
      case 11: temp+=3;
		break;
      case 12: temp+=5;
		break;
      default: temp+=0;
}
}
t1=temp%7;
return t1;
}

void printmonth(int mm,int yy)
{
int a,b,i,gd,gm,errorcode;
char c;
a=getday(1,mm,yy);
b=nofdays(mm,yy);
clrscr();
fflush(stdin);
flushall();
    detectgraph(&gd,&gm);
    initgraph(&gd, &gm, "e:\\tc\\bgi" );
    errorcode=graphresult();
    if(errorcode!=grOk)
    {
    printf("graphics error %d", grapherrormsg(errorcode));
    getch();
    exit(0);
    }
setcolor(6);
setfillstyle(11,2);
bar(0, 240, 640, 480);
setfillstyle(SOLID_FILL,2);
bar(40, 280, 600, 440);
settextstyle(4,0,1);
printf("\n\n\n\t\t\t\t%s  %d\n\n\t\t",month[mm-1],yy);
printf("sun    mon    tue    wed    thurs  fri    sat ");
printf("\n\t\t-----  -----  -----  -----  -----  -----  -----\n\n\t\t");
for(i=0;i<a;i++)
printf("       ");
for(i=1;i<=b;i++)
{
if((i+a-1)%7==0)
printf("\n\t\t");
{
if(i<10)
{
printf("%d      ",i);
}
else if(i>=10 && i<100)
{
printf("%d     ",i);
}
else
printf("%d    ",i);
}
}
keys:
outtextxy(50,290,"Press w or s keys to go forwards or backwards by one month");
outtextxy(50,320,"press a or d keys to go backwards or forward by one year");
flushall();
c=getch();
if(tolower(c)=='w' || tolower(c)=='s' || tolower(c)=='a' || tolower(c)=='d')
{
if(c=='w')
{
if(mm==12)
{
closegraph();
printmonth(1,yy+1);
}
else
{
closegraph();
printmonth(mm+1,yy);
}
}
else if(c=='s')
{
if(mm==1 && yy>1)
{
closegraph();
printmonth(12,yy-1);
}
else if(mm==1 && yy<=1)
{
outtextxy(50,350,"you have reached month 1 of year 1...");
outtextxy(50,380,"Can't go back anymmore");
goto keys;
}
else
{
closegraph();
printmonth(mm-1,yy);
}
}
else if(c=='a')
{
if(yy<=1)
{
outtextxy(50,350,"Can't go back yearwise anymore...");
outtextxy(50,380,"You have reached year 1");
goto keys;
}
closegraph();
printmonth(mm,yy-1);
}
else if(c=='d')
{
closegraph();
printmonth(mm,yy+1);
}
}
else
{
outtextxy(50,350,"INVALID KEY..");
outtextxy(50,380,"Returning to main screen...");
getch();
closegraph();
}
}

void infile()
{
char choice;
int gd,gm,errorcode;
FILE *p,*q;
char ch='y';
menu1:
clrscr();
detectgraph(&gd,&gm);
initgraph(&gd, &gm, "e:\\tc\\bgi" );
errorcode=graphresult();
if(errorcode!=grOk)
    {
    printf("graphics error %d", grapherrormsg(errorcode));
    getch();
    exit(0);
    }
 setcolor(14);
 settextstyle(5,0,3);
	 outtextxy(110,120,"1.Enter a note and date");
	 outtextxy(110,150,"2.Enter date of birth");
	 outtextxy(110,180,"3.Delete all notes");
	 outtextxy(110,210,"4.Delete all DOB's");
	 outtextxy(110,240,"0.EXIT");
	 outtextxy(110,270,"ENTER YOUR CHOICE : ");
 setcolor(1);
 setlinestyle(0,2,1);
 rectangle(88,111,438,303);
 setcolor(5);
 rectangle(90,109,436,305);
 setcolor(9);
 rectangle(92,107,434,307);
 flushall();
 fflush(stdin);
 choice=getch();
 closegraph();
 clrscr();
switch(choice)
{
case '1':
	ch='y';
	if((p=fopen("e:\\tc\\files\\note.DAT","a"))==NULL)//opens a file in append mode
	{
	printf("\nCANNOT OPEN FILE note.DAT !!!!!!\n");
	getch();
	goto menu1;
	}
	printf("\n\t\tEnter details to be entered\n\n");
	while(ch=='y')
	{
	reenter:
	printf("\nEnter date month and year in which note is to be stored:\n");
	scanf("%d %d %d",&b.a.date,&b.a.month,&b.a.year);
	if(b.a.date>nofdays(b.a.month,b.a.year))
	{
	printf("Please enter a valid date..");
	getch();
	goto reenter;
	}
	if(b.a.month<0||b.a.month>13)
	{
	printf("Please enter a valid month..");
	getch();
	goto reenter;
	}
	if(b.a.year<1)
	{
	printf("Year should be greater than 0");
	getch();
	goto reenter;
	}
	printf("Enter note to be stored at this date:\n");
	flushall();
	fflush(stdin);
	gets(b.note);
	fwrite(&b,sizeof(b),1,p);
	printf("\n\n\tContinue with same option(y/n)...  ");
	ch=getch();
	}
	fcloseall();
	clrscr();
	goto menu1;
case '2':
	ch='y' ;
	if((q=fopen("e:\\tc\\files\\dob.DAT","a"))==NULL)//opens a file in append mode
	{
	printf("\nCANNOT OPEN FILE dob.DAT !!!!!!\n");
	getch();
	goto menu1;
	}
	printf("\n\t\tEnter details to be entered\n\n");
	while(ch=='y')
	{
	printf("\nEnter DOB in format of DD MM YY:\n");
	scanf("%d %d %d",&b.a.date,&b.a.month,&b.a.year);
	if(b.a.date>nofdays(b.a.month,b.a.year))
	{
	printf("Please enter a valid date..");
	getch();
	goto reenter;
	}
	if(b.a.month<0||b.a.month>13)
	{
	printf("Please enter a valid month..");
	getch();
	goto reenter;
	}
	if(b.a.year<1)
	{
	printf("Year should be greater than 0");
	getch();
	goto reenter;
	}
	printf("Enter name of person whose DOB is entered\n");
	flushall();
	fflush(stdin);
	gets(b.note);
	fwrite(&b,sizeof(b),1,q);
	printf("\n\n\tWant to enter more data(y/n)...  ");
	ch=getch();
	}
	fcloseall();
	clrscr();
	goto menu1;
case '3':if((q=fopen("e:\\tc\\files\\note.DAT","w"))==NULL)
	{
	printf("\nCANNOT OPEN FILE dob.DAT !!!!!!\n");
	getch();
	goto menu1;
	}
	printf("\n\n\n\t\tALL NOTES DELETED...\n\t\tpress any key to continue..");
	getch();
	fcloseall();
	clrscr();
	goto menu1;
case '4':if((q=fopen("e:\\tc\\files\\dob.DAT","w"))==NULL)
	{
	printf("\nCANNOT OPEN FILE dob.DAT !!!!!!\n");
	getch();
	goto menu1;
	}
	printf("\n\n\n\t\tALL DOB's DELETED...\n\t\tpress any key to continue..");
	getch();
	fcloseall();
	clrscr();
	goto menu1;
case '0':
	goto end;
default:
	clrscr();
	detectgraph(&gd,&gm);
	initgraph(&gd, &gm, "e:\\tc\\bgi" );
	errorcode=graphresult();
	if(errorcode!=grOk)
		{
		printf("graphics error %d", grapherrormsg(errorcode));
		getch();
		exit(0);
		}
	setcolor(3);
	setfillstyle(4,5);
	bar(0, 0, 640, 480);
	settextstyle(4,0,3);
	outtextxy(150,110,"Wrong key entered...");
	outtextxy(200,150,"Please enter a valid key");
	getch();
	closegraph();
	goto menu1;
}
end:
fcloseall();
}

void outfile()
{
char choice,name[50];
int x=0,gd,gm,errorcode;
FILE *p,*q;
char ch='y';
clrscr();
menu1:
clrscr();
detectgraph(&gd,&gm);
initgraph(&gd, &gm, "e:\\tc\\bgi" );
errorcode=graphresult();
if(errorcode!=grOk)
    {
    printf("graphics error %d", grapherrormsg(errorcode));
    getch();
    exit(0);
    }
 setcolor(14);
 settextstyle(5,0,1);
 outtextxy(60,120,"1.To see notes and dates stored within a specific period");
 outtextxy(60,150,"2.To see date of births stored within a specific period");
 outtextxy(60,180,"3.To find birth date by name");
 outtextxy(60,210,"4.To see all notes stored till now");
 outtextxy(60,240,"5.To see all birthdays stored till now");
 outtextxy(60,270,"0.EXIT");
 outtextxy(60,300,"ENTER YOUR CHOICE : ");
 setcolor(1);
 setlinestyle(0,2,1);
 rectangle(38,111,528,333);
 setcolor(5);
 rectangle(40,109,526,335);
 setcolor(9);
 rectangle(42,107,524,337);
 flushall();
 fflush(stdin);
 choice=getch();
 closegraph();
 clrscr();
switch(choice)
{
case '1':
	one:
	ch='y';
	while(ch=='y')
	{
	clrscr();
	printf("\n\t\tEnter details of period to be searched and shown..\n\n");
	printf("\nEnter starting month and year\n");
	flushall();
	fflush(stdin);
	scanf("%d %d",&c.month,&c.year);
	printf("\nEnter ending month and year\n");
	scanf("%d %d",&d.month,&d.year);
	if(c.month<0||c.month>12||d.month<0||d.month>12)
	{
		printf("ERROR...\nplease enter months between 1 and 12");
		getch();
		goto one;
	}
	if(c.year==d.year)
	{
	if(c.month>d.month)
	{
		printf("ERROR...\nplease enter months in correct order");
		getch();
		goto one;
	}
	}
	else if(c.year>d.year)
	{
		printf("ERROR...\nplease enter years in correct order");
		getch();
		goto one;
	}
	if((p=fopen("e:\\tc\\files\\note.DAT","r"))==NULL)//opens a file in read mode
	{
	printf("\nCannot open file note.DAT\n");
	getch();
	goto menu1;
	}
	x=0;
	while((fread(&b,sizeof(b),1,p))!=NULL)
	{
	if(b.a.year==c.year)
		{
		if(c.month<=b.a.month)
		{
		x++;
		printf("\nNote stored on %d %s %d is:  ",b.a.date,month[b.a.month-1],b.a.year);
		puts(b.note);
		continue;
		}
		}
	else if(b.a.year>c.year && b.a.year<d.year)
		{
		x++;
		printf("\nNote stored on %d %s %d is:  ",b.a.date,month[b.a.month-1],b.a.year);
		puts(b.note);
		continue;
		}
	else if(b.a.year==d.year)
		{
		if(d.month>=b.a.month)
		{
		x++;
		printf("\nNote stored on %d %s %d is:  ",b.a.date,month[b.a.month-1],b.a.year);
		puts(b.note);
		continue;
		}
		}
       }
       if(x==0)
       {
       printf("\nNo Notes within given period have been found in our database!!!\n");
       }
	getch();
	printf("\nDo you want to find notes in any other period(y/n)...  ");
	ch=getch();
	fcloseall();
      }
	fcloseall();
	goto menu1;
case '2':
	two:
	ch='y';
	while(ch=='y')
	{
	clrscr();
	printf("\nEnter details of period to be searched and shown..\n\n");
	printf("\nEnter starting month and year\n");
	flushall();
	fflush(stdin);
	scanf("%d %d",&c.month,&c.year);
	printf("\nEnter ending month and year\n");
	scanf("%d %d",&d.month,&d.year);
	if(c.month<0||c.month>12||d.month<0||d.month>12)
	{
		printf("ERROR...\nplease enter months between 1 and 12");
		getch();
		goto two;
	}
	if(c.year==d.year)
	{
	if(c.month>d.month)
	{
		printf("ERROR...\nplease enter months in correct order");
		getch();
		goto two;
	}
	}
	else if(c.year>d.year)
	{
		printf("ERROR...\nplease enter years in correct order");
		getch();
		goto two;
	}
	if((q=fopen("e:\\tc\\files\\dob.DAT","r"))==NULL)//opens a file in read mode
	{
	printf("\nCANNOT OPEN FILE dob.DAT !!!!!!\n");
	getch();
	goto menu1;
	}
	x=0;
	while((fread(&b,sizeof(b),1,q))!=NULL)
	{
	if(b.a.year==c.year)
		{
		if(c.month<=b.a.month)
		{
		x++;
		printf("\n%d. ",x);
		puts(b.note);
		printf("has birthday on %d %s %d\n\n",b.a.date,month[b.a.month-1],b.a.year);
		continue;
		}
		}
	else if(b.a.year>c.year && b.a.year<d.year)
		{
		x++;
		printf("\n%d. ",x);
		puts(b.note);
		printf("has birthday on %d %s %d\n\n",b.a.date,month[b.a.month-1],b.a.year);
		continue;
		}
	else if(b.a.year==d.year)
		{
		if(d.month>=b.a.month)
		{
		x++;
		printf("\n%d. ",x);
		puts(b.note);
		printf("has birthday on %d %s %d\n\n",b.a.date,month[b.a.month-1],b.a.year);
		continue;
		}
		}
       }
       if(x==0)
       {
       printf("\nNo birthdays within given period have been found in our database!!!\n");
       }
	getch();
	fcloseall();
	printf("\nDo you want to find birthdays in any other period(y/n)...  ");
	ch=getch();
      }
       fcloseall();
	goto menu1;
case '3':
	ch='y';
	while(ch=='y')
	{
	clrscr();
	printf("\nEnter name of person whose birthdate is to be found..\n\n");
	flushall();
	fflush(stdin);
	gets(name);
	if((q=fopen("e:\\tc\\files\\dob.DAT","r"))==NULL)//opens a file in read mode
	{
	printf("\nCANNOT OPEN FILE note.DAT !!!!!!\n");
	getch();
	goto menu1;
	}
	x=0;
	while((fread(&b,sizeof(b),1,q))!=NULL)
	{
	if(strcmpi(b.note,name)==0)//strcmpi compares two strings without case sensitivity
		{
		x++;
		printf("\n%d. ",x);
		puts(name);
		printf("has birthday on %d %s %d\n\n",b.a.date,month[b.a.month-1],b.a.year);
		continue;
		}
	}
	if(x==0)
	{
	printf("\nNo matching name found...");
	}
	getch();
	fcloseall();
	printf("\nDo you want to find more birthdays by searching names (y/n)...  ");
	ch=getch();
      }
      fcloseall();
	goto menu1;
case'4':
	clrscr();
	if((p=fopen("e:\\tc\\files\\note.DAT","r"))==NULL)//opens a file in read mode
	{
	printf("\nCANNOT OPEN FILE note.DAT !!!!!!\n");
	getch();
	goto menu1;
	}
	x=0;
	while((fread(&b,sizeof(b),1,p))!=NULL)
	{
	x++;
	printf("\nNote stored on %d %s %d is:  ",b.a.date,month[b.a.month-1],b.a.year);
	puts(b.note);
	continue;
	}
	if(x==0)
	{
	 printf("\n\n\n\t\tFILE IS EMPTY...");
	}
	getch();
	fcloseall();
	goto menu1;
case '5':
	clrscr();
	if((q=fopen("e:\\tc\\files\\dob.DAT","r"))==NULL)//opens a file in read mode
	{
	printf("\nCANNOT OPEN FILE dob.DAT !!!!!!\n");
	getch();
	goto menu1;
	}
	x=0;
	while((fread(&b,sizeof(b),1,p))!=NULL)
	{
	x++;
	printf("\n%d. ",x);
	puts(b.note);
	printf("has birthday on %d %s %d.\n\n",b.a.date,month[b.a.month-1],b.a.year);
	continue;
	}
	if(x==0)
	{
	 printf("\n\n\n\t\tFILE IS EMPTY...");
	}
	getch();
	fcloseall();
	goto menu1;
case '0':
	goto end;
default:
	clrscr();
	detectgraph(&gd,&gm);
	initgraph(&gd, &gm, "e:\\tc\\bgi" );
	errorcode=graphresult();
	if(errorcode!=grOk)
		{
		printf("graphics error %d", grapherrormsg(errorcode));
		getch();
		exit(0);
		}
	setcolor(3);
	setfillstyle(4,5);
	bar(0, 0, 640, 480);
	settextstyle(4,0,3);
	outtextxy(150,110,"wrong key entered...");
	outtextxy(200,150,"Please enter a valid key");
	getch();
	closegraph();
	goto menu1;
}
end:
fcloseall();
}

void main()
{

char ch='1';
int dd,mm,yy,gd,gm,errorcode;
intro();
clrscr();
getch();//to take up in account a char by which "press a key to cont..." in prev function breaks
while(ch!='0')
{      start:
	 ch=menu();
	switch (ch)
      {
	date:case '1': clrscr();
			printf("\n\n\tEnter date (DD MM YYYY) : ");
			scanf("%d %d %d",&dd,&mm,&yy);
		  if(yy<=0)
		  {
		   printf("\nYear entered should be greater than 0\nPlease reenter details");
		   getch();
		   goto date;
		  }
		  if(mm<=0 || mm>12)
		  {
		  printf("\nPlease enter a valid month...\nPlease re-enter details\n");
		  getch();
		  goto date;
		  }
		  if(dd<0 || dd>nofdays(mm,yy))
		  {
		  printf("\nPlease enter a valid date...\nPlease re-enter details\n");
		  getch();
		  goto date;
		  }
		  printf("\n\nOn %d %s %d Day is : %s",dd,month[mm-1],yy,day[getday(dd,mm,yy)]);
		  flushall();
		  getch();
		  closegraph();
		  break;
	month:case '2': printf("\nEnter month and year (MM YYYY) : ");
		   scanf("%d %d",&mm,&yy);
		   printf("\n\n");
		  if(yy<=0)
		  {
		   printf("\nYear entered should be greater than 0\nplease reenter details");
		   goto month;
		  }
		   if(mm<=0 || mm>12)
		  {
		  printf("\nPlease enter a valid month...\nplease re-enter details\n");
		  goto month;
		  }
		  printmonth(mm,yy);
		   flushall();
		   break;
	case '3' :infile();
		  break;
	case '4' :outfile();
		  break;
	case '0' : end();
		   exit(0);
		   break;
	default:
		clrscr();
		detectgraph(&gd,&gm);
		initgraph(&gd, &gm, "e:\\tc\\bgi" );
		errorcode=graphresult();
		if(errorcode!=grOk)
		{
		printf("graphics error %d", grapherrormsg(errorcode));
		getch();
		exit(0);
		}
		setcolor(3);
		setfillstyle(4,5);
		bar(0, 0, 640, 480);
		settextstyle(4,0,3);
		outtextxy(150,110,"wrong key entered...");
		outtextxy(200,150,"Please enter a valid key");
		getch();
		closegraph();
		goto start;
	 }
}
getch();
}
