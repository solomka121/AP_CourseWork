#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BUS BUS;
static BUS *front = NULL,*temp,*ptr;

typedef struct BUS{
    int num;                            //number bus
    char name[20];                      //fullanme
    int trip;                           //num of trip
    char av[2];                         //availability
    int attention;                      //count of attention

    BUS *next;                          //pointer next
}BUS;

int count_of_elements();                //кількість елементів
void new_information(BUS *ptr);         //перехід
void delete_elements();                 //видалити елемент за позицією
void add_information();                 //додати елемент
void all_information();                 //уся присутня інформація
void availability_of_elements();        //наявність. + -> так , - ->ні
void count_of_attention();              //шукаєм елемент з найбільшою кількістю порушень
void sorting();                         //сортування
void swap_char(char *p,char *q);         //допоміжна функція для сорутвання
void write_new_infromation();           //змінити інформацію
void first_letter();                    //перша літера
void write_to_file();                   //запис у файл
void read_from_file();                  //інформація вже є в файлі

int main(){
    int a;
    do {
        printf("\t\t\tMenu\n");
        printf("\t\t1- Add element \n");
        printf("\t\t2- Show information\n");
        printf("\t\t3- Delete element\n");
        printf("\t\t4- Availability\n");
        printf("\t\t5- Max count of attention\n");
        printf("\t\t6- Sorting\n");
        printf("\t\t7- Change information\n");
        printf("\t\t8- First letter\n");
        printf("\t\t9- Write to file\n");
        printf("\t\t10-Read from file\n");
        printf("\t\t0- Exit\n");
        printf("--------------------\n");
        printf("Enter position : ");
        scanf("%d",&a);
        printf("--------------------\n");

        switch(a){
            case 1:
                add_information();                  //готово
                break;
            case 2:
                //count_of_elements();              //готово
                all_information();                  //готово
                break;
            case 3:
                delete_elements();                  //готово
                break;
            case 4:
                availability_of_elements();         //готово
                break;
            case 5:
                count_of_attention();               //готово
                break;
            case 6:
                sorting();                          //готово
                break;
            case 7:
                write_new_infromation();            //готово
                break;
            case 8:
                first_letter();                     //готово
                break;
            case 9:
                write_to_file();                    //готово
                break;
            case 10:
                read_from_file();                   //готово
                break;
            case 0:
                printf("Well...Exit...");
                exit(0);
            default:
                printf("Enter correct number.\n");
                break;
        }
    }while(1);{
        return 0;
    }
}

/////////////////////count of elements//////////////////

int count_of_elements(){
    int count=0;
    if(front == NULL){
        return count;
    }else{
        BUS *temp = front;
        while (temp != NULL){
            count++;
            temp = temp->next;
        }
        //printf("Count of elements %d .\n",count);
        return count;
    }
}

//////////////////////////next elements/////////////////////

void new_information(BUS *ptr){
    if(front == NULL){
        front = ptr;
        return;
    }else{
        BUS *temp = front;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ptr;
    }
}

//////////////////////list of information////////////////////

void all_information(){
    if(front == NULL){
        printf("Oh..I don't see anything :(\n");
        return;
    }else{
        BUS *temp = front;
        printf("\nBUS number|\tFullname |\tTrip |\tAvailability|\tAttention|\n");
        printf("------------------------------------------------------------------\n");
        while (temp != NULL) {
            printf(" %9d |%12.20s |%10d |%13.5s |%12d|\n",temp->num,temp->name,temp->trip,temp->av,temp->attention);
            printf("------------------------------------------------------------------\n\n");
            temp = temp->next;
        }
    }
}

/////////////////////information//////////////////////////

void add_information(){
    BUS *ptr = malloc(sizeof(BUS));
    ptr->next = NULL;

    /*Числа ,які дорівнюють нулю або менше
    нуля - не підходять . Потрібно знову
    ввести значення*/

    do{
        printf("BUS number: ");
        scanf("%d",&ptr->num);                  //number bus
    }while(ptr->num<=0);

    printf("Fullname : ");                      //fullanme
    scanf("%s",ptr->name);

    do{
        printf("Trip :");                       //number trip
        scanf("%d",&ptr->trip);
    }while(ptr->trip<=0);

    printf("Availability : ");                  //availability , + -> yes, - ->no
    scanf("%s",ptr->av);

    do{
        printf("Attention :");                  //number of attention
        scanf("%d",&ptr->attention);
    }while(ptr->attention<0);

    new_information(ptr);
}

/////////////////////delete elements//////////////////////////

void delete_elements(){
    int value, position, i = 0;
    value = count_of_elements();
    temp=front;
    if(front == NULL){
        printf("Oh..I don't see anything :(\n");
        return ;
    }else{
        //number to delete
        printf("Enter position : ");
        scanf("%d",&position);

        if (position > 0 && position <= value) {
            if (position == 1) {
                temp = temp -> next;
                front = temp;
            } else {
                while (temp != 0) {
                    if (i == (position - 1)) {
                        ptr->next = temp->next;
                        break;
                    } else {
                        i++;
                        ptr = temp;
                        temp = temp -> next;
                    }
                }
            }
        }else{
            printf("I don't see this elements\n");
        }
    }
}

////////////////////////sorting/////////////////////////
void swap_char(char *p,char *q){         //функція ,яка приймає значення і міняє місцями
    char t[20] = "";
    strcpy(t,p);
    strcpy(p,q);
    strcpy(q,t);
}

void sorting(){
    if(front == NULL){
        printf("Oh..I don't see anything :(\n");
        return;
    }else{
        BUS *temp = front,*index=NULL;
        int sort,sort1,sort2;

        while(temp!=NULL){
            index=temp->next;
            while(index!=NULL){
                if(temp->num > index->num){
                    sort = temp->num;
                    sort1 = temp->trip;
                    sort2 = temp->attention;

                    temp->num = index->num;
                    temp->trip = index->trip;
                    temp->attention = index->attention;

                    swap_char(index->name,temp->name);
                    swap_char(index->av,temp->av);

                    index->num = sort;
                    index->trip = sort1;
                    index->attention = sort2;
                }index=index->next;
            }temp=temp->next;
        }
    }all_information();
}

////////////////BUS + - ///////////////////////////////////////////

void availability_of_elements(){
    if(front == NULL){
        printf("Oh..I don't see anything :(\n");
        return;
    }
    BUS *temp = front;
    char *availability;
    printf("Enter availability: ");//вводимо характеристику ,яка цікавить
    scanf("%s",availability);
    printf("\nBUS number|\tFullname |\tTrip |\tAvailability|\tAttention|\n");
    printf("------------------------------------------------------------------\n");
    while (temp!= NULL) {
        if(strcmp(temp->av,availability)==0){
            printf(" %9d |%12.20s |%10d |%13.5s |%12d|\n",temp->num,temp->name,temp->trip,temp->av,temp->attention);
            printf("------------------------------------------------------------------\n\n");
        }
        temp = temp->next;
    }
}

///////////////////////////////max attention////////////////

void count_of_attention(){

    if(front == NULL){
        printf("Oh..I don't see anything :(\n");
        return;
    }
    BUS *temp = front;
    int max = 0;
    printf("\t\tThe Largest number of violations\n");
    printf("\nBUS number|\tFullname |\tTrip |\tAvailability|\tAttention|\n");
    printf("------------------------------------------------------------------\n");

    for(;temp!=NULL;temp=temp->next){
        if(max<temp->attention){
            max=temp->attention;
        }
    }
    BUS *index = front;
    for(;index!=NULL;index=index->next){
        if(index->attention == max){
            printf(" %9d |%12.20s |%10d |%13.5s |%12d|\n",index->num,index->name,index->trip,index->av,index->attention);
            printf("------------------------------------------------------------------\n");
        }
    }
}

///////////////////////write new informayion////////////////

void write_new_infromation(){

    int value, position, i = 0;
    value = count_of_elements();
    temp=front ;
    if(front == NULL){
        printf("Oh..I don't see anything :(\n");
        return ;
    }else{
        printf("Enter position : ");
        scanf("%d",&position);

        if (position > 0 && position <= value) {
            if (position == 1) {
                temp = temp -> next;
                front = temp;
            } else {
                while (temp != 0) {
                    if (i == (position - 1)) {
                        ptr->next = temp->next;
                        break;
                    } else {
                        i++;
                        ptr = temp;
                        temp = temp -> next;
                    }
                }
            }add_information();
        }else{
            printf("Element to change not found\n");
        }
    }
}

///////////////////first letter/////////////////////////////

void first_letter(){
    char *letter;

    if(front == NULL){
        printf("Oh..I don't see anything :(\n");
        return;
    }else{
        BUS *temp = front;

        printf("Enter letter to search : ");                    // вводимо букву для пошуку
        scanf("%s",letter);
        printf("People with such surnames start on ' %s ' :\n",letter);

        printf("\nBUS number|\tFullname |\tTrip |\tAvailability|\tAttention|\n");
        printf("------------------------------------------------------------------\n");
        while(temp!=NULL){
            if(strncmp(temp->name, letter,1)==0){
                printf(" %9d |%12.20s |%10d |%13.5s |%12d|\n",temp->num,temp->name,temp->trip,temp->av,temp->attention);
                printf("------------------------------------------------------------------\n\n");
            }
            temp = temp->next;
        }
    }
}

/////////////////////////file///////////////////////////////

void write_to_file(){
    if(front == NULL){
        printf("Nothing to write to file...\n");
        return;
    }else{
        FILE *f = fopen("D:\\f.txt","w");

        if(f == NULL){
            printf("File is not available.\n");
        }else{
            BUS *temp = front;
            while(temp!=NULL){
                fprintf(f," %9d %12.20s %10d %13.5s %12d\n",temp->num,temp->name,temp->trip,temp->av,temp->attention);
                temp = temp->next;
            }
            printf("Information was written to the file.\n");
            fclose(f);
        }
    }
}

void read_from_file(){
    FILE* f;
    f = fopen("D:\\f.txt", "r");
    if (f == NULL) {
        printf("File is not available. \n");
        return ;
    }else{
        BUS *node = (BUS*)malloc(sizeof(BUS));
        while (fscanf(f,"%d %s %d %s %d",&node->num,node->name,&node->trip,node->av,&node->attention)!=EOF) {
            node->next = front;
            front=node;
            node = malloc(sizeof(BUS));
        }all_information();
    }
    fclose(f);
}