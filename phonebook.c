#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>


struct contact{
char name[50];
char last_name[50];
char addres[50];
char Email[50];
char mobile_number[50];
char home_phone_number[50];	
};


void menu();
int insert_contact();
int get_how_many_contacts();
int compare(char s1[] , char s2[]);
void show_contacts();
void show_contact(struct contact m);
void search_by_name(char name[]);
void search_by_last_name(char name[]);
void search_by_email(char name[]);
void search_by_mobile_number(char name[]);
void delete_contact(char name[],char last_name[]);
int edit_contact(char name[], char last_name[]);
int sort_contacts();

int main(){
	
int choice;	

int how_many_contacts;
	
char name[50];	
char last_name[50];
bool finisher_of_the_loop = false;
	
while(true){

if (finisher_of_the_loop == false){
	
menu();	
printf("\n");
scanf("%d",&choice);	

if (choice == 1){
insert_contact();	
sort_contacts();
how_many_contacts = get_how_many_contacts();
printf("how_many_contacts = %d",how_many_contacts);
}

if (choice == 2){
how_many_contacts = get_how_many_contacts();
if (how_many_contacts == -1){
printf("\contacts list is empty\n");
break;
}
how_many_contacts = get_how_many_contacts();
printf("\nhow_many_contacts = %d",how_many_contacts);
printf("\n");
sort_contacts();
show_contacts();	
}

if (choice == 3){
if (how_many_contacts == -1){
printf("\ncontacts list is empty\n");
break;
}
printf("\nplease enter name:\n");
scanf("%s",&name);	
printf("\n");
search_by_name(name);
}

if (choice == 4){
if (how_many_contacts == -1){
printf("\ncontacts list is empty\n");
break;
}
printf("\nplease enter last_name:\n");
scanf("%s",&name);	
printf("\n");
search_by_last_name(name);
}

if (choice == 5){
if (how_many_contacts == -1){
printf("\ncontacts list is empty\n");
break;
}
printf("\nplease enter email:\n");
scanf("%s",&name);	
printf("\n");
search_by_email(name);
}


if (choice == 6){
if (how_many_contacts == -1){
printf("\ncontacts list is empty\n");
break;
}
printf("\nplease enter mobile number:\n");
scanf("%s",&name);	
printf("\n");
search_by_mobile_number(name);
}

if (choice == 7){
if (how_many_contacts == -1){
printf("\ncontacts list is empty\n");
break;
}
printf("\nplease enter name:\n");
scanf("%s",&name);	
printf("\n");
printf("\nplease enter last_name:\n");
scanf("%s",&last_name);	
printf("\n");
delete_contact(name,last_name);
sort_contacts();
}


if (choice == 8){
if (how_many_contacts == -1){
printf("\nnam ra vared konid\n");
break;
}
printf("\nplease enter name:\n");
scanf("%s",&name);	
printf("\n");
printf("\nplease enter last_name:\n");
scanf("%s",&last_name);	
printf("\n");
edit_contact(name,last_name);
sort_contacts();
}

	
if (choice == 9){
finisher_of_the_loop = true;
}
	
}//if finisher_of_the_loop == false
else{
break;	
}		
	
}//while


}//int main


void menu(){
	
printf("\nmenu:");	
printf("\n1.add contact");	
printf("\n2.show all contacts");	
printf("\n3.search by name");
printf("\n4.search by last_name");
printf("\n5.search by email");
printf("\n6.search by mobile_number");
printf("\n7.delete contact");
printf("\n8.edit contact");
printf("\n9.exit\n");	
	
}


int insert_contact(){
	
FILE *fp;
  fp = fopen("result.txt", "a+");

struct contact m;
char a[50],b[50],c[50],d[50],e[50],f[50];
printf("\nplease enter name\n");
scanf("%s",&a);
strcpy(m.name , a);

printf("\nplease enter last_name\n");
scanf("%s",&b);
strcpy(m.last_name , b);


printf("\nplease enter address\n");
scanf("%s",&c);
strcpy(m.addres , c);

printf("\nplease enter email\n");
scanf("%s",&d);
strcpy(m.Email , d);

printf("\nplease enter mobile number\n");
scanf("%s",&e);
strcpy(m.mobile_number , e);

printf("\nplease enter home phone_number\n");
scanf("%s",&f);
strcpy(m.home_phone_number , f);



  fputs(m.name,fp);
  fputs("\t",fp);
  fputs(m.last_name,fp);
  fputs("\t",fp);
  fputs(m.addres,fp);
  fputs("\t",fp);
  fputs(m.Email,fp);
  fputs("\t",fp);
  fputs(m.mobile_number,fp);
  fputs("\t",fp);
  fputs(m.home_phone_number,fp);
  fputs("\n",fp);  
  fclose(fp);	
  
  return 1;
		
}


int get_how_many_contacts(){
 FILE *fp;
 fp = fopen("result.txt","a+");
int size = 0;
struct contact c;
char str[1000];

while (fgets(str,1000,fp) != NULL)
{	
size = size + 1;
}

fclose(fp);

return size;
}


void show_contacts(){
 FILE *fp;
 fp = fopen("result.txt", "a+");
struct contact c;
int counter = 1;
char str[1000];
printf("\n\n");
while (fgets(str,1000,fp)!= NULL)
{
printf("%d:%s",counter,str);	
counter = counter + 1;
}

fclose(fp);

}




void show_contact(struct contact m){
printf("\nname:%s,last_name:%s,address:%s,email:%s,mobile_number:%s,home_phone_number:%s\n",m.name,m.last_name,m.addres,m.Email,m.mobile_number,m.home_phone_number);
}


void search_by_name(char name[]){
	
printf("entered name is:%s",name);	
	
 FILE *fp;
 fp = fopen("result.txt", "a+");
int how_many_contacts = get_how_many_contacts();
struct contact c[how_many_contacts];
int counter = 0;
while (!feof(fp))
{
fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s",&c[counter].name,&c[counter].last_name,&c[counter].addres,&c[counter].Email,&c[counter].mobile_number,&c[counter].home_phone_number);	
counter = counter + 1;
}

int detect = -1;
int i;
for(i = 0 ; i < how_many_contacts ; i++){
if (strcmp(name , c[i].name) == 0 )
detect = i;	
}
	
if (detect != -1){
show_contact(c[detect]);	
}else{
printf("\nthe contact you are looking for does not exist'\n");	
}	
	
	
}


void search_by_last_name(char name[]){
	
printf("entered last_name is:%s",name);	
	
 FILE *fp;
 fp = fopen("result.txt", "a+");
int how_many_contacts = get_how_many_contacts();
struct contact c[how_many_contacts];
int counter = 0;
while (!feof(fp))
{
fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s",&c[counter].name,&c[counter].last_name,&c[counter].addres,&c[counter].Email,&c[counter].mobile_number,&c[counter].home_phone_number);	
counter = counter + 1;
}

int detect = -1;
int i;
for(i = 0 ; i < how_many_contacts ; i++){
if (strcmp(name , c[i].last_name) == 0 )
detect = i;	
}
	
if (detect != -1){
show_contact(c[detect]);	
}else{
printf("\nthe contact you are looking for does not exist\n");	
}	
	
	
}


void search_by_email(char name[]){
	
printf("entered email is:%s",name);	
	
 FILE *fp;
 fp = fopen("result.txt", "a+");
int how_many_contacts = get_how_many_contacts();
struct contact c[how_many_contacts];
int counter = 0;
while (!feof(fp))
{
fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s",&c[counter].name,&c[counter].last_name,&c[counter].addres,&c[counter].Email,&c[counter].mobile_number,&c[counter].home_phone_number);	
counter = counter + 1;
}

int detect = -1;
int i;
for(i = 0 ; i < how_many_contacts ; i++){
if (strcmp(name , c[i].Email) == 0 )
detect = i;	
}
	
if (detect != -1){
show_contact(c[detect]);	
}else{
printf("\nthe contact you are looking for does not exist\n");	
}	
	
	
}



void search_by_mobile_number(char name[]){
	
printf("entered mobile_number is:%s",name);	
	
 FILE *fp;
 fp = fopen("result.txt", "a+");
int how_many_contacts = get_how_many_contacts();
struct contact c[how_many_contacts];
int counter = 0;
while (!feof(fp))
{
fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s",&c[counter].name,&c[counter].last_name,&c[counter].addres,&c[counter].Email,&c[counter].mobile_number,&c[counter].home_phone_number);	
counter = counter + 1;
}

int detect = -1;
int i;
for(i = 0 ; i < how_many_contacts ; i++){
if (strcmp(name , c[i].mobile_number) == 0 )
detect = i;	
}
	
if (detect != -1){
show_contact(c[detect]);	
}else{
printf("\nthe contact you are looking for does not exist\n");	
}	
	
	
}





int compare(char s1[] , char s2[]){
int size = sizeof(s1)/sizeof(s1[0]);
	int i;
	for(i = 0 ; i < size ; i++)
{
	if (s1[i]>s2[i])
	return 1;
	else if(s1[i]< s2[i])
	return -1;
	else{
	continue;
    }
}
return 0;
}


void delete_contact(char name[],char last_name[]){
			
 FILE *fp;
 fp = fopen("result.txt", "r");
int how_many_contacts = get_how_many_contacts();
struct contact c[how_many_contacts];
int counter = 0;
while (!feof(fp))
{
fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s",&c[counter].name,&c[counter].last_name,&c[counter].addres,&c[counter].Email,&c[counter].mobile_number,&c[counter].home_phone_number);
counter = counter + 1;
}


fclose(fp);


FILE *sf;
 sf = fopen("result.txt", "w");


int i ;


for(i = 0 ; i < how_many_contacts ; i++){
if ((strcmp(name , c[i].name) == 0 )&&(strcmp(last_name , c[i].last_name) == 0 )){
continue;	
}
  fputs(c[i].name,sf);
  fputs("\t",sf);
  fputs(c[i].last_name,sf);
  fputs("\t",sf);
  fputs(c[i].addres,sf);
  fputs("\t",sf);
  fputs(c[i].Email,sf);
  fputs("\t",sf);
  fputs(c[i].mobile_number,sf);
  fputs("\t",sf);
  fputs(c[i].home_phone_number,sf);
  fputs("\n",sf);  
  	
}
fclose(sf);
}
	


int edit_contact(char name[],char last_name[]){
	
		
 FILE *fp;
 fp = fopen("result.txt", "r");
int how_many_contacts = get_how_many_contacts();
struct contact c[how_many_contacts],m;
int counter = 0;
while (!feof(fp))
{
fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s",&c[counter].name,&c[counter].last_name,&c[counter].addres,&c[counter].Email,&c[counter].mobile_number,&c[counter].home_phone_number);
counter = counter + 1;
}
fclose(fp);


int i ;
int detect = 0;
int the_one_that_should_change = 0;

for(i = 0 ; i < how_many_contacts ; i++){
if ((strcmp(name , c[i].name) == 0 )&&(strcmp(last_name , c[i].last_name) == 0 )){
detect = 1;	
the_one_that_should_change = i;
}
}

if(detect == 1){
	
char a[50],b[50],c[50],d[50],e[50],f[50];
printf("\nplease enter new name\n");
scanf("%s",&a);
strcpy(m.name , a);

printf("\nplease enter new last_name\n");
scanf("%s",&b);
strcpy(m.last_name , b);


printf("\nplease enter new address\n");
scanf("%s",&c);
strcpy(m.addres , c);

printf("\nplease enter new email\n");
scanf("%s",&d);
strcpy(m.Email , d);

printf("\nplease enter new mobile_number\n");
scanf("%s",&e);
strcpy(m.mobile_number , e);

printf("\nplease enter new home phone_number\n");
scanf("%s",&f);
strcpy(m.home_phone_number , f);

	
}
else{
printf("\nthe contact you are looking for does not exist\n");	
return -1;
}



FILE *sf;
 sf = fopen("result.txt", "w");

for(i = 0 ; i < how_many_contacts ; i++){
	
  if (i == the_one_that_should_change){
  fputs(m.name,sf);
  fputs("\t",sf);
  fputs(m.last_name,sf);
  fputs("\t",sf);
  fputs(m.addres,sf);
  fputs("\t",sf);
  fputs(m.Email,sf);
  fputs("\t",sf);
  fputs(m.mobile_number,sf);
  fputs("\t",sf);
  fputs(m.home_phone_number,sf);
  fputs("\n",sf);	
  }
  else{
  fputs(c[i].name,sf);
  fputs("\t",sf);
  fputs(c[i].last_name,sf);
  fputs("\t",sf);
  fputs(c[i].addres,sf);
  fputs("\t",sf);
  fputs(c[i].Email,sf);
  fputs("\t",sf);
  fputs(c[i].mobile_number,sf);
  fputs("\t",sf);
  fputs(c[i].home_phone_number,sf);
  fputs("\n",sf);  
  }
}
fclose(sf);

return 0;
}



	
	
int sort_contacts(){	
	
 FILE *fileobj;
 fileobj = fopen("result.txt", "r");
int i , j;
int how_many_contacts = get_how_many_contacts();
struct contact c[how_many_contacts];
int counter = 0;
while (!feof(fileobj))
{
fscanf(fileobj,"%s\t%s\t%s\t%s\t%s\t%s",&c[counter].name,&c[counter].last_name,&c[counter].addres,&c[counter].Email,&c[counter].mobile_number,&c[counter].home_phone_number);
counter = counter + 1;
}
fclose(fileobj);


struct contact temp_contact;
int temp;
int temp2;
for(i=0;i<how_many_contacts;i++){
for(j=0;j<how_many_contacts-1;j++){	
temp = compare(c[j].last_name,c[j+1].last_name);
if (temp == 1){
//if previous contact is bigger than next contact compating(last_name).
temp_contact = c[j];
c[j] = c[j+1];
c[j+1] = temp_contact;
}
else if(temp == 0){
//if previous contact is equal to next contact (last_name) we should check name too
temp2 = compare(c[j].name,c[j+1].name);
if(temp2 == 1){
temp_contact = c[j];
c[j] = c[j+1];
c[j+1] = temp_contact;	
}
}
else
continue;
}		
}


FILE *fileobj1;
 fileobj1 = fopen("result.txt", "w");
for(i=0;i<how_many_contacts;i++){
  
  fputs(c[i].name,fileobj1);
  fputs("\t",fileobj1);
  fputs(c[i].last_name,fileobj1);
  fputs("\t",fileobj1);
  fputs(c[i].addres,fileobj1);
  fputs("\t",fileobj1);
  fputs(c[i].Email,fileobj1);
  fputs("\t",fileobj1);
  fputs(c[i].mobile_number,fileobj1);
  fputs("\t",fileobj1);
  fputs(c[i].home_phone_number,fileobj1);
  fputs("\n",fileobj1);  
  
}
fclose(fileobj1);


return 1;
	
}




