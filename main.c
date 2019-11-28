#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* argv[] )
{


    return 0;
}


struct Node
{

    int data;
    struct Node *next;

};

struct LinkedList
{

    struct Node *head;
    int cardinality;

};

struct LinkedList new_LL()
{

    struct LinkedList LL;
    LL.head = NULL;
    LL.cardinality = 0;
    return LL;
}

void insert( struct LinkedList *LL, int data )
{

    if( LL->head == NULL )
        LL->head->data = data;
    else
    {
 
        struct Node *n = malloc( sizeof( struct Node ) );
        n->data = data;
        LL->head->next = n; 
    
    }
    LL->cardinality++;
}

void removefromhead( struct LinkedList *LL )
{
    if( LL->head != NULL )
    {
        struct Node *temp = LL->head;
        LL->head = LL->head->next;
        free( temp );
        LL->cardinality--;
    }
}

int retrieve( struct LinkedList *LL, int index )
{
    int c = 0; 
    for( struct Node *p = LL->head; p != NULL; p++, c++ )
        if( c==index )
           return p->data; 
    
    exit( 1 );
}

int search( struct LinkedList *LL, int data )
{

    for( struct Node *p = LL->head; p != NULL; p++ )
        if( p->data == data )
            return 1;
    
    return 0;

}




