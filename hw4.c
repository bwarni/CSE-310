//Michael Warnick
//CSE 310: Algorithms and Data Structures
//HW 4: 100 Points
//Due Sunday, July 2nd by 11:59 pm Online

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_NAME_LEN 30
#define MAX_ACADEMIC_LEN 10

typedef struct studentRec
{
   char name[MAX_NAME_LEN]; 
   double gpa;

   char academic[MAX_ACADEMIC_LEN];
   int key;   
   struct studentRec *next;
} studentRec_t;


#define TABLE_SIZE 10000
studentRec_t *hashTable[TABLE_SIZE];

int HASH_FUNC(int key)
{
   return (key % TABLE_SIZE);
}

void hashTable_init(studentRec_t *hashTable[TABLE_SIZE])
{
   int i;
   for(i=0;i<TABLE_SIZE;i++)
     hashTable[i] = NULL;
}

int INSERT(studentRec_t *hashTable[TABLE_SIZE],
     char name[], double gpa, char academic[], int key)
{
   int index;
   studentRec_t *p_rec;

   index = HASH_FUNC(key);
   p_rec = (studentRec_t *) malloc(sizeof(studentRec_t));
   
   strcpy(p_rec->name, name); 
   p_rec->gpa = gpa;
   strcpy(p_rec->academic, academic); 
   p_rec->key = key;
   
   p_rec->next = hashTable[index];
   hashTable[index] = p_rec;
   
   return 1;
}

int SEARCH(studentRec_t *hashTable[TABLE_SIZE],
     char name[], double *p_gpa, char academic[], int *p_key)
{
   int index;
   studentRec_t *p_rec;
   index = HASH_FUNC(*p_key);
   p_rec = hashTable[index];

   while (p_rec != NULL)
   {
      if (p_rec->key == *p_key)
      {
        
        strcpy(name, p_rec->name); 
        *p_gpa = p_rec->gpa;
        strcpy(academic, p_rec->academic); 
        *p_key = p_rec->key;
        
        return 1; 
      }
      p_rec = p_rec->next;
   }

   return 0; 
}

int DELETE(studentRec_t *hashTable[TABLE_SIZE], int *p_key)
{
   int index;
   studentRec_t *p_rec, *p_prev;

   index = HASH_FUNC(*p_key);

   p_rec = hashTable[index];
   p_prev = NULL;

   while (p_rec != NULL)
   {
      if (p_rec->key == *p_key)
      {
        if (p_prev != NULL)
          p_prev->next = p_rec->next;
        else
           hashTable[index] = p_rec->next;
        free(p_rec);
        return 1; 
      }
      p_prev = p_rec;
      p_rec = p_rec->next;
  }

   return 0; 
}

int main()
{
  int choice, ret, key;
  double gpa;
  char name[MAX_NAME_LEN], academic[MAX_ACADEMIC_LEN];

  hashTable_init(hashTable);
  while (1)
  {
    printf("\nHash Table Implementation\n");
    printf("==========================\n");
    printf("1.Insert a Record(user enters the name, GPA, Academic level, Key (Key should be between 0 - 65536))\n");
    printf("2.Search the table(user enters a key for search) key should be between 0 - 65536\n");
    printf("3.Delete a record (user enter a key of the record to be deleted)\n");
    printf("4.Exit\n");
    printf("Enter your choice: \n");
    scanf("%d", &choice);
    switch(choice)
    {
       case 1:
            printf(" \n");
            printf("'Insert a Record' Selected\n");
            printf("==========================\n");
            printf("Enter student's name to be inserted: ");
            scanf("%s", name);
            printf("Enter student's GPA to be inserted: ");
            scanf("%lf", &gpa);
            printf("Enter student's academic level to be inserted: ");
            scanf("%s",academic);
            printf("Enter key at which element to be inserted(0 - 65536): ");
            scanf("%d", &key);
            if((key > 65536) || (key < 0)){
                printf("\nKey Value not valid. Please re-enter a value 0 - 65536: ");
                scanf("%d",&key);
            }
            ret = INSERT(hashTable, name, gpa, academic, key);
            if (ret == 1){
                printf("\nStudent Record Added!\n");
            }
            else{
                printf("\nError! Student Record Not Added!\n");
            }
            break;

       case 2: 
            printf("\n'Search the Table' Selected\n");
            printf("==========================\n");
            printf("Enter the key to be searched: ");
            scanf("%d", &key);
            ret = SEARCH(hashTable, name, &gpa, academic, &key);
            if (ret == 1){
                printf("\nTable Search Successful!\n");
                printf("\nStudent Record at key %d \n", key);
                printf("--------------------------\n");
                printf("Name: %s \n", name);
                printf("GPA: %lf \n", gpa);
                printf("Academic Level: %s \n", academic);
            }
            else{
                printf("\nNo Student Records found with that key!\n");
            }
            break;

       case 3: 
            printf("\n'Delete Record' Selected\n");
            printf("==========================\n");
            printf("Enter a key of the record to be deleted: ");
            scanf("%d", &key);
            ret = DELETE(hashTable, &key);
            if (ret == 1){
                printf("\nDeletion was Successful!\n");
            }
            else{
                printf("\nDeletion was Unsuccessful! No Student Records found with that key!\n");
            }
            break;

       case 4: 
            exit(0);

    }
  }
}
