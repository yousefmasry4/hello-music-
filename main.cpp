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
void next(struct Node* start) 
{ 
    start=start->next; 
} 
void prevfun(struct Node* start) 
{ 
    start=start->prev; 
} 
int dell(struct Node *& start) 
{ 
    if (start == NULL) 
        return 3; 
    if(start == start->next){
        free(start);
        return 3;
    }
    struct Node *curr = start;
    struct Node *temp = start;
    start=start->next;
    temp = temp->prev;
    temp->next=start;
    start->prev=temp;
    free(curr);
    return 1;
} 

  //driver***************************************************************************************************************************************
int main()
{
    struct Node* start = NULL; 
    char e[30];
    FILE *q;
    q = fopen("dir.txt", "r");
    do
    {
        fscanf(q,"%s", e);
        insertEnd(&start,e);
    }
    while(!feof(q));
    fclose(q);
    while(1){
      //  puts("run");
        FILE *a,*p,*c,*sn;
        a = fopen("next.txt", "r");//next
        p = fopen("prev.txt", "r");//prev
        c = fopen("dell.txt", "r");//dell
        sn = fopen("sn.txt", "r");//name
        FILE *aw,*pw,*cw,*snw;
        aw = fopen("next.txt", "w");//next
        pw = fopen("prev.txt", "w");//prev
        cw = fopen("dell.txt", "w");//dell
        snw = fopen("sn.txt", "w");//name
        if (p == NULL ||c == NULL||sn == NULL||a == NULL )
        {
            puts("Error while opening the file.\n");
            exit(0);
        }
        /*stop here*/
        int temp=0;
        char stemp[100];
        do
        {
            fscanf(a,"%s",stemp);
        }
        while(!feof(a));
        puts("file eqq");
        printf("==%s\n",stemp);
        fclose(a);
        if(temp == 1){
            puts("next action");
            next(start);
            fprintf(aw,0);
            fclose(aw);
            fprintf(snw,start->data);
            fclose(snw);
            continue;
        }
        temp=0;
        fscanf(p,"%d",temp);
        fclose(p);
        if(temp == 1){
            prevfun(start);
            fprintf(pw,0);
            fclose(pw);
            fprintf(snw,start->data);
            fclose(snw);
            continue;
        }
        temp=0;
        fscanf(c,"%d",&temp);
        printf("%d",temp);
        break;
        fclose(c);
        if(temp == 1){
            printf("dell");
            int c=dell(start);
            if(c==3){
                //null;
                fprintf(snw,"404 error");
                fclose(snw);
            }else{
                fprintf(snw,start->data);
                fclose(snw);
            }
            fprintf(cw,0);
            fclose(cw);
            continue;
        }

    }
}