#include <stdio.h>
#include <stdlib.h>
#include "hlinkedlist.h"

struct LinkedList new_LL()
{

    struct LinkedList LL;
    LL.head = NULL;
    LL.tail = NULL;
    LL.cardinality = 0;
    return LL;
}

void insert( struct LinkedList *LL, int data )
{
    
    struct Node *n = malloc( sizeof( struct Node ) );
    n->data = data;
    
    if( LL->head != NULL )
    {
        n->next = LL->head;
        LL->head = n;
    }
    else
    {
        LL->head = LL->tail = n;
    }
    LL->cardinality++;
}

int removefromhead( struct LinkedList *LL )
{
    if( LL->head != NULL )
    {
        struct Node *temp = LL->head;
        LL->head = LL->head->next;
        int data = temp->data;
        free( temp );
        LL->cardinality--;
        return data;
    }
    exit( 1 );
    
}

void append( struct LinkedList *LL, int data )
{
    struct Node *n = malloc( sizeof( struct Node ) );
    n->data = data;
    
    if( LL->head != NULL ) /* if the list is not empty */
    {
        LL->tail->next = n;
        LL->tail = LL->tail->next;
    }   
    else /* the list is empty */
        LL->head = LL->tail = n;

}

int pop( struct LinkedList *LL )
{
    if( LL->head == NULL )
        exit( 1 );
        
    int temp;
    if( LL->head == LL->tail )
    {
        temp = LL->head->data;
        free( LL->head );
        LL->tail = LL->head = NULL;
        return temp;
    }
    else
    {
        struct Node *temp = LL->tail;
        LL->tail = LL->tail->prev;
        free( temp );
    }
        
}


int retrieve( struct LinkedList *LL, int index )
{
    int c = 0; 
    for( struct Node *p = LL->head; p != NULL; p = p->next, c++ )
        if( c==index )
           return p->data; 
    
    exit( 1 );
}

int search( struct LinkedList *LL, int data )
{

    for( struct Node *p = LL->head; p != NULL; p = p->next )
        if( p->data == data )
            return 1;
    
    return 0;

}

int isempty( struct LinkedList *LL )
{
    
    return LL->cardinality == 0;

}


void cleanup( struct LinkedList *LL )
{

    while( !isempty( LL ) )
        removefromhead( LL );
    
}

int main( int argc, char* argv[] )
{

    struct LinkedList a = new_LL();
    
    insert( &a, 1 );
    insert( &a, 2 );
    insert( &a, 3 );

    for( struct Node *p = a.head; p != NULL; p = p->next )
        printf( "%d\n", p->data );

    printf( "%d\n", a.cardinality );

    cleanup( &a );
    
    for( struct Node *p = a.head; p != NULL; p = p->next )
        printf( "%d\n", p->data );


    printf( "%d\n", a.cardinality );

    return 0;
}
