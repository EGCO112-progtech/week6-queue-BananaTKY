

typedef struct 
{
	 NodePtr headPtr,tailPtr;
	int size;
}Queue;

void enqueue_struct(Queue* q, int x) ;
int dequeue_struct(Queue *q) ;

void enqueue_struct(Queue* q, int x)
{
  Node *new_node=(Node*) malloc(sizeof(Node));
  if(new_node)
  {  
    new_node -> data = x ;
    new_node -> nextPtr = NULL ;
    if(q -> size == 0) //1st node
    {
        q -> headPtr = new_node ;
    }
    else  // node อื่นๆ
    {
        q -> tailPtr -> nextPtr = new_node ;
    }   /*Finish enqueue */
    q -> tailPtr = new_node ;
    q -> size++ ;
  }
}


int dequeue_struct(Queue *q)
{
  NodePtr t = q -> headPtr;
   if(q -> size > 0)
   {
      int value = t -> data;
      q -> headPtr = t -> nextPtr ;
      if(q -> headPtr == NULL)
      {
        q -> tailPtr = NULL ;
      }
      free(t) ;
      q -> size-- ;

          /*Finish dequeue */

      return value;
   }
   printf("Empty queue\n");

   return 0;
}

