#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h> 
using namespace std; 
  
// Structure of a Node 
struct Node 
{ 
    char data[30]; 
    struct Node *next; 
    struct Node *prev; 
}; 
void insertEnd(struct Node** start,char value[30]) 
{ 
    // If the list is empty, create a single node 
    // circular and doubly list 
    if (*start == NULL) 
    { 
        struct Node* new_node = new Node; 
        strcpy(new_node->data,value); 
        new_node->next = new_node->prev = new_node; 
        *start = new_node; 
        return; 
    } 
  
    // If list is not empty 
  
    /* Find last node */
    Node *last = (*start)->prev; 
  
    // Create Node dynamically 
    struct Node* new_node = new Node; 
    strcpy(new_node->data,value); 
  
    // Start is going to be next of new_node 
    new_node->next = *start; 
  
    // Make new node previous of start 
    (*start)->prev = new_node; 
  
    // Make last preivous of new node 
    new_node->prev = last; 
  
    // Make new node next of old last 
    last->next = new_node; 
} 
Node* next(struct Node* start) 
{ 
    Node*temp=start;
    temp=temp->next; 
    start=temp;
    printf("i will send %s\n",start->data);
    return start;
} 
Node* prevfun(struct Node* start) 
{ 
    start=start->prev; 
    return start; 

} 
Node* dell(struct Node *& start) 
{ 
    if (start == NULL) 
        return 0; 
    if(start == start->next){
        puts("error you can't dell it");
        return start;
    }
    struct Node *curr = start;
    struct Node *temp = start;
    start=start->next;
    temp = temp->prev;
    temp->next=start;
    start->prev=temp;
    free(curr);
    return start;
} 

  //driver***************************************************************************************************************************************
int main()
{
    printf("main  function***************");
    struct Node* start = NULL; 
    char e[30];
    FILE *q;
    q = fopen("dir.txt", "r");
    if ( q != NULL )
    {
      char line [ 30 ]; /* or other suitable maximum line size */
      while ( fgets ( line, sizeof line, q ) != NULL ) /* read a line */
      {
         fputs ( line, stdout ); /* write the line */
         insertEnd(&start,line);
      }
      fclose ( q );
   }
   else
   {
      perror ("dir.txt"); /* why didn't the file open? */
   }
/*

    do
    {
        fscanf(q," %s", e);
        insertEnd(&start,e);
    }
    while(!feof(q));
    fclose(q);
    */
    char off[1]={'0'};
    while(1){
      //  puts("run");
        FILE *a,*p,*c,*sn;
        FILE *aw,*pw,*cw,*snw;
        a = fopen("next.txt", "r");//next   
        p = fopen("prev.txt", "r");//prev
        c = fopen("dell.txt", "r");//dell
        sn = fopen("sn.txt", "r");//name
        /*
       



        if (p == NULL ||c == NULL||sn == NULL||a == NULL )
        {
            puts("Error while opening the file.\n");
        }
        /*stop here*/
        char stemp[100];
        do
        {
            fscanf(a,"%s",stemp);
        }
        while(!feof(a));
        fclose(a);

        if(strcmp(stemp,"1") == 0){
            puts("next action");
            start=next(start);
            aw = fopen("next.txt", "w");//next
            if(aw == NULL)
            {
                printf("Error! 1");   
                exit(1);             
            }
            fprintf(aw,"%s","0");
            fclose(aw);
            snw = fopen("sn.txt", "w");//name
            if(snw == NULL)
            {
                printf("Error! 2");   
                exit(1);             
            }
            fprintf(snw,"%s",start->data);
            printf("%s",start->data);
            fclose(snw);
        }
        /***********************************************/
        char stemp2[100];
        do
        {
            fscanf(p,"%s",stemp2);
        }
        while(!feof(p));
        fclose(p);

        if(strcmp(stemp2,"1") == 0){
            puts("[*]prev");
            start=prevfun(start);
            pw = fopen("prev.txt", "w");//prev
            if(pw == NULL)
            {
                printf("Error! prev.txt not found");   
                exit(1);             
            }
            fprintf(pw,"%s","0");
            fclose(pw);
            snw = fopen("sn.txt", "w");//name
            if(snw == NULL)
            {
                printf("Error! 2");   
                exit(1);             
            }
            fprintf(snw,"%s",start->data);
            printf("%s",start->data);
            fclose(snw);
        }
/**************************************************/
        char stemp3[100];
        do
        {
            fscanf(c,"%s",stemp3);
        }
        while(!feof(c));
        fclose(c);

        if(strcmp(stemp3,"1") == 0){
            puts("[*]dell");
            start=dell(start);
            if(strcasecmp(start->data,"0")!=0){
                cw = fopen("dell.txt", "w");//dell
                if(cw == NULL)
                {
                    printf("Error! prev.txt not found");   
                    exit(1);             
                }
                fprintf(cw,"%s","0");
                fclose(cw);
                snw = fopen("sn.txt", "w");//name
                if(snw == NULL)
                {
                    printf("Error! 2");   
                    exit(1);             
                }
                fprintf(snw,"%s",start->data);
                printf("%s",start->data);
                fclose(snw);
            }else{
                puts("404 error");
                snw = fopen("sn.txt", "w");//name
                if(snw == NULL)
                {
                    printf("Error! 2");   
                    exit(1);             
                }
                fprintf(snw,"%s","404 error");
                fclose(snw);
            }
        }
    }
}