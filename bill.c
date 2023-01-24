#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *replace(char *s,char *new_word,char *old_word)
{
int new_length = strlen(new_word);
int old_length = strlen(old_word);
int i=0,count=0;
for(i=0;s[i]!='\0';i++)
{
    if(strstr(&s[i],old_word)==&s[i])
    {
        count++;
        i=i+old_length-1;
    }
}
char * resultstring ;
resultstring = (char*)malloc(i+count*(new_length -old_length));
i=0;

while(*s)
{
    if(strstr(s,old_word)==s)
    {
        strcpy(&resultstring[i],new_word);
        i+=new_length;
        s+=old_length;
    }
    else
    {
        resultstring[i] =*s;
        s++;
        i++;
    }
}
resultstring[i]='\0';

return resultstring;

}


int main()
{

char str[2000],ch;
FILE *ptr1,*ptr2;
ptr1=fopen("nn.txt","r");
fgets(str,200,ptr1);
int i=0;

    do {
        ch = fgetc(ptr1);
        // printf("%c", ch);
      str[i]=ch;
      i++;

    } while (ch != EOF);


fclose(ptr1);
// make next file
char *newstr =str;

printf("\n\n\n");

printf("      |||||||||||||||||||||||||||||||||||||||||||    Enter Your Money Specificatioin    |||||||||||||||||||||||||||||||||||||||||||\n");




// this code for calculating principal amount


int principal,years,return_value;
float rate;

printf("Enter Your Amount :- ");
scanf("%d",&principal);
printf("\n");
getchar();

printf("Enter years :- ");
scanf("%d",&years);
printf("\n");
getchar();

printf("Enter rate :- ");
scanf("%f",&rate);
printf("\n");
getchar();


	for( int i=0;i<years;i++)
	{
		return_value= principal *(1+rate);
	}


char principal_c[100],rate_c[100],years_c[100],return_value_c[100];


sprintf(principal_c, "%d", principal);
sprintf(rate_c, "%f", rate);
sprintf(years_c, "%d", years);
sprintf(return_value_c, "%d", return_value);

// for statement


newstr = replace(newstr, principal_c,"{Amount}");
newstr = replace(newstr,rate_c,"{Rate}");
newstr = replace(newstr,years_c,"{years}");
newstr = replace(newstr,return_value_c,"{Real_Amount}");




ptr2=fopen("gf.txt","w");
fprintf(ptr2,"%s",newstr);
printf("\n");
printf(" %s",newstr);
fclose(ptr2);


}
