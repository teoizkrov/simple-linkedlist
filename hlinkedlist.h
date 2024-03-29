struct Node
{
    int data;
    struct Node *next;

};
struct LinkedList
{

    struct Node *head;
    struct Node *tail;
    int cardinality;
};

struct LinkedList new_LL();
void insert( struct LinkedList *, int );
int removefromhead( struct LinkedList * );

int pop( struct LinkedList * );
void append( struct LinkedList *, int );

void cleanup( struct LinkedList * );
int isempty( struct LinkedList * );
int retrieve( struct LinkedList *, int );
int search( struct LinkedList *, int );


/*
 *Might add a function that returns a pointer to where it found an item, instead
 *of starting from the beginning if per se I wanted to search and remove
 */
