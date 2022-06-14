#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Movie Movie;
static Movie *front = NULL,*temp,*ptr;

typedef struct Movie{

    char name[20];
    int release_year;
    char  genre[20];
    char country[20];
    char director[20];
    float rating;

    Movie *next;                          //pointer next
}Movie;

int count_of_elements();                //кількість елементів
void new_information(Movie *ptr);         //перехід
void delete_elements();                 //видалити елемент за позицією
void add_information();                 //додати елемент
void all_information();                 //уся присутня інформація
void Search();
void movies_of_country();        // movies of country
void movies_of_country_by_genre();              // movies of country and director
void movies_of_genre_by_year();
void movies_by_director();
void sorting();                         //сортування
void swap_char(char *p,char *q);         //допоміжна функція для сорутвання
void write_new_infromation();           //змінити інформацію
void write_to_file();                   //запис у файл
void read_from_file();                  //інформація вже є в файлі

int main(){
    int a;
    do {
        printf("\t\t\tMenu\n");
        printf("\t\t1- Add element \n");
        printf("\t\t2- Show information\n");
        printf("\t\t3- Delete element\n");
        printf("\t\t4- Search\n");
        printf("\t\t5- ------\n");
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
                Search();         //готово
                break;
            case 5:
                //count_of_attention();               //готово
                break;
            case 6:
                sorting();                          //готово
                break;
            case 7:
                write_new_infromation();            //готово
                break;
            case 8:
                //first_letter();                     //готово
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

void Search() {
    int a;
    printf("\t\t\tSearch Menu\n");
    printf("\t\t1- Movies of country\n");
    printf("\t\t2- Movies of genre by country\n");
    printf("\t\t3- Movies by director\n");
    printf("\t\t4- Movies of genre later than _\n");
    printf("\t\t0- Exit\n");
    printf("--------------------\n");
    printf("Enter position : ");
    scanf("%d", &a);
    printf("--------------------\n");

    switch (a) {
        case 1:
            movies_of_country();         //готово
            break;
        case 2:
            movies_of_country_by_genre();
            break;
        case 3:
            movies_by_director();
            break;
        case 4:
            movies_of_genre_by_year();
            break;
        case 6:
            //sorting();                          //готово
            break;
        case 0:
            printf("Well...Exit...");
            exit(0);
        default:
            printf("Enter correct number.\n");
            break;
    }
}

/////////////////////count of elements//////////////////

int count_of_elements(){
    int count=0;
    if(front == NULL){
        return count;
    }else{
        Movie *temp = front;
        while (temp != NULL){
            count++;
            temp = temp->next;
        }
        //printf("Count of elements %d .\n",count);
        return count;
    }
}

//////////////////////////next elements/////////////////////

void new_information(Movie *ptr){
    if(front == NULL){
        front = ptr;
        return;
    }else{
        Movie *temp = front;
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
        Movie *temp = front;
        printf("\nMovie Name    |\tRelease Year |\tGenre |\tCountry |\tDirector |\tRating |\n");
        printf("----------------------------------------------------------------------------------\n");
        while (temp != NULL) {
            printf(" %12s |%13d |%7s |%8s |%15s |%13.1f|\n",temp->name,temp->release_year,temp->genre,temp->country,temp->director,temp->rating);
            printf("----------------------------------------------------------------------------------\n\n");
            temp = temp->next;
        }
    }
}

/////////////////////information//////////////////////////

void add_information(){
    Movie *ptr = malloc(sizeof(Movie));
    ptr->next = NULL;

    /*Числа ,які дорівнюють нулю або менше
    нуля - не підходять . Потрібно знову
    ввести значення*/

    printf("Movie Name : ");                      //movie name
    scanf("%s",ptr->name);

    printf("Release Year: ");                   //
    scanf("%d",&ptr->release_year);

    printf("Genre : ");                      //
    scanf("%s",ptr->genre);

    printf("Contry : ");                      //
    scanf("%s",ptr->country);

    printf("Director : ");                  //
    scanf("%s",ptr->director);

    do{
        printf("Rating :");                  //
        scanf("%f",&ptr->rating);
    }while(ptr->rating<0 || ptr->rating>10);

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
void swap_char(char *p,char *q){         //Strings Place Change
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
        Movie *temp = front,*index=NULL;
        int sort,sort1;

        while(temp!=NULL){
            index=temp->next;
            while(index!=NULL){
                if(temp->rating < index->rating){

                    sort = temp->release_year;
                    sort1 = temp->rating;

                    temp->release_year = index->release_year;
                    temp->rating = index->rating;

                    swap_char(index->name , temp->name);
                    swap_char(index->genre , temp->genre);
                    swap_char(index->country , temp->country);
                    swap_char(index->director , temp->director);

                    index->release_year = sort;
                    index->rating = sort1;
                }index=index->next;
            }temp=temp->next;
        }
    }all_information();
}

////////////////Movie + - ///////////////////////////////////////////

void movies_of_country(){
    if(front == NULL){
        printf("Oh..I don't see anything :(\n");
        return;
    }
    Movie *temp = front;
    char *country;
    printf("Enter Country: "); // Enter Country To Sort by 
    scanf("%s",country);
    printf("\nMovie Name    |\tRelease Year |\tGenre |\tCountry |\tDirector |\tRating |\n");
    printf("----------------------------------------------------------------------------------\n");
    while (temp!= NULL) {
        if(strcmp(temp->country,country)==0){
            printf(" %12s |%13d |%7s |%8s |%15s |%13.1f|\n",temp->name,temp->release_year,temp->genre,temp->country,temp->director,temp->rating);
            printf("----------------------------------------------------------------------------------\n\n");
        }
        temp = temp->next;
    }
}

void movies_of_country_by_genre(){
    if(front == NULL){
        printf("Oh..I don't see anything :(\n");
        return;
    }
    Movie *temp = front;
    char *country = malloc(sizeof(country));
    char *genre = malloc(sizeof(genre));
    printf("Enter country: "); // Enter Country To Sort by
    scanf("%s",country);
    printf("Enter Genre: "); // Enter Country To Sort by
    scanf("%s",genre);
    printf("\nMovie Name    |\tRelease Year |\tGenre |\tCountry |\tDirector |\tRating |\n");
    printf("----------------------------------------------------------------------------------\n");
    while (temp!= NULL) {
        if(strcmp(temp->genre,genre)==0 && strcmp(temp->country,country)==0){
            printf(" %12s |%13d |%7s |%8s |%15s |%13.1f|\n",temp->name,temp->release_year,temp->genre,temp->country,temp->director,temp->rating);
            printf("----------------------------------------------------------------------------------\n\n");
        }
        temp = temp->next;
    }
}

void movies_by_director(){
    if(front == NULL){
        printf("Oh..I don't see anything :(\n");
        return;
    }
    Movie *temp = front;
    char *director;
    printf("Enter director: "); // Enter Country To Sort by
    scanf("%s",director);
    printf("\nMovie Name    |\tRelease Year |\tGenre |\tCountry |\tDirector |\tRating |\n");
    printf("----------------------------------------------------------------------------------\n");
    while (temp!= NULL) {
        if(strcmp(temp->director,director)==0){
            printf(" %12s |%13d |%7s |%8s |%15s |%13.1f|\n",temp->name,temp->release_year,temp->genre,temp->country,temp->director,temp->rating);
            printf("----------------------------------------------------------------------------------\n\n");
        }
        temp = temp->next;
    }
}

void movies_of_genre_by_year(){
    if(front == NULL){
        printf("Oh..I don't see anything :(\n");
        return;
    }
    Movie *temp = front;
    char *genre = malloc(sizeof(genre));
    int *year = malloc(sizeof(year));
    printf("Enter Genre: "); // Enter Country To Sort by
    scanf("%s",genre);
    printf("Enter year: "); // Enter Country To Sort by
    scanf("%s", year);
    printf("\nMovie Name    |\tRelease Year |\tGenre |\tCountry |\tDirector |\tRating |\n");
    printf("----------------------------------------------------------------------------------\n");
    while (temp!= NULL) {
        if(strcmp(temp->genre,genre)==0 && temp->release_year > year){
            printf(" %12s |%13d |%7s |%8s |%15s |%13.1f|\n",temp->name,temp->release_year,temp->genre,temp->country,temp->director,temp->rating);
            printf("----------------------------------------------------------------------------------\n\n");
        }
        temp = temp->next;
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

/////////////////////////file///////////////////////////////

void write_to_file(){
    if(front == NULL){
        printf("Nothing to write to file...\n");
        return;
    }else{
        FILE *f = fopen("movies.txt","w");

        if(f == NULL){
            printf("File is not available.\n");
        }else{
            Movie *temp = front;
            while(temp!=NULL){
                fprintf(f," %12s %13d %7s %8s %15s %13.1f\n",temp->name,temp->release_year,temp->genre,temp->country,temp->director,temp->rating);
                temp = temp->next;
            }
            printf("Information was written to the file.\n");
            fclose(f);
        }
    }
}

void read_from_file(){
    FILE* f;
    f = fopen("movies.txt", "r");
    if (f == NULL) {
        printf("File is not available. \n");
        return ;
    }else{
        Movie *node = (Movie*)malloc(sizeof(Movie));
        while (fscanf(f," %s %d %s %s %s %f",&node->name,&node->release_year,&node->genre,&node->country,&node->director,&node->rating)!=EOF) {
            node->next = front;
            front=node;
            node = malloc(sizeof(Movie));
        }all_information();
    }
    fclose(f);
}