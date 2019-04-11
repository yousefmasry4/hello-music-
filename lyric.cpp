#include<windows.h>
#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>
#include<time.h>
using namespace std;
/* structure of a stack node */
struct Node { 
    char data[100],t[10],d[10]; 
    struct Node* next; 
}; 
void enQueue(Node *& head,char data[100],char t[10],char d[10]){

    Node* temp=new Node();
    strcpy(temp->data,data);
    strcpy(temp->t,t);
    strcpy(temp->d,d);
    temp->next=NULL;
    Node* var=head;
    if(head == NULL){
        head=temp;
        return ;
    }
    while(var->next){
        var=var->next;
    }
    var->next=temp;
}
void deQueue(Node *& h,char data[100],char t[10],char d[10],int empty){
	if(h==NULL){
		empty=1;
		return ; // dummy variable
	}
	else{
		Node *p;
		empty=0;
		strcpy(data,h->data);
		strcpy(t,h->t);
		strcpy(d,h->d);
		p=h;
		h=h->next;
		delete p;
		if(h==NULL)
			t=NULL;
	}
}
int main() 
{ 
    
    char data[100],start[10],dur[10];
    int qwe;
    /* Create a queue with items 1 2 3*/
    FILE *play;
    clock_t begin;
    while(1){
        startagain:
        qwe=1;
        play= fopen("play.txt", "r");//next
        char io[10];
        do
        {
            fscanf(play,"%s",io);
        }
        while(!feof(play));
        fclose(play);
        printf("[*]run....%s",io);
        if(strcmp(io,"1")==0){
            puts("[*]play");
            begin = clock()-(60.0);
            break;
        }
    }
    Node * q=new Node();
    q=NULL;
    char line[100],t[10],a[100],d[10];
    static const char filename[] = "lytemp.txt";
    FILE *file = fopen ( filename, "r" );
    if ( file != NULL )
    {
         while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
         {
       //     fputs ( line, stdout ); /* write the line */
            strcpy(a,line);
       //     printf("x=%s",a);
            if( fgets ( line, sizeof line, file ) != NULL ){
           //     fputs ( line, stdout ); /* write the line */
                strcpy(t,line);
             //   printf("t=%f",atof(t));
            }
            if( fgets ( line, sizeof line, file ) != NULL ){
           //     fputs ( line, stdout ); /* write the line */
                strcpy(d,line);
           //     printf("d=%f",atof(d));
            }
            enQueue(q,a,t,d); 
            /*
            int dd;
            char z[100],x[10],c[100];
            deQueue(q,z,x,c,dd);
            puts(c);
            exit(1);
            */
         }
         fclose ( file );
     }
     else
     {
        goto startagain;
     }
    while(1){
        FILE *show;
        show= fopen("play.txt", "r");//next
        char sh[10];
        if( fgets ( sh, sizeof sh, show ) != NULL ){
            puts("[*]play ation");
        }
        fclose(show);
        FILE *a,*p,*c;
        a = fopen("next.txt", "r");//next   
        p = fopen("prev.txt", "r");//prev
        c = fopen("dell.txt", "r");//dell
        char stemp[100];
        if( fgets ( stemp, sizeof stemp, a ) != NULL ){
            puts("[*]next ation");
        }
        fclose(a);
        char stemp2[100];
        if( fgets ( stemp2, sizeof stemp2, p ) != NULL ){
            puts("[*]previous ation");
        }
        fclose(p);
        char stemp3[100];
        if( fgets ( stemp3, sizeof stemp3, c ) != NULL ){
            puts("[*]dell ation");
        }
        fclose(c);
        if(strcmp(sh,"0")==0 ||strcmp(stemp3,"1")==0||strcmp(stemp2,"1")==0||strcmp(stemp,"1")==0){
            puts("[*]break for some action");
            goto startagain;
        }//mtnsash tdef next we keda
        int empty=0;
        FILE *snw;
     //   while(q){

     //       puts(data);
     //   }
     //   exit(0); 
     //   puts(data);
     //   printf("__{%s",dur);
        if (qwe == 1){
            deQueue(q,data,start,dur,empty);
            qwe=0;
        }
        if(empty){
            snw = fopen("ly.txt", "w");//name
            if(snw == NULL)
            {
                printf("Error! in open ly.txt");   
                exit(1);             
            }
            fprintf(snw,"%s","song lyrics not found  please rename file name to summary name");
            fclose(snw);
        }else{
            clock_t t = clock();
            float r,rr;
            r=atof(start);
            rr=atof(dur)+r;
            printf("time = %f , %f\n",r,rr);
            t=t-begin;
            double time_spent = (((double)t)/600)-35;
            printf("time = %f < %f  && %f > %f\n",time_spent,r,time_spent,rr);
            if(time_spent > r && time_spent < rr){
                puts(data);
                deQueue(q,data,start,dur,empty);
                puts(start);
                puts(dur);
            /////////////////////
                snw = fopen("ly.txt", "w");//name
                if(snw == NULL)
                {
                    printf("Error! in open ly.txt");   
                    exit(1);             
                }

                fprintf(snw,"%s",data);
                fclose(snw);
              //  Sleep(atof(dur));
            }
        }
    }
    return 0; 
} 
