/* 
 * Andrew Miller
 * 915113828
 * amiller2@sfsu.edu
 * gcc version 4.9.3 (GCC)
 */
#include "queue.h"
#include <cstdlib>

Queue::Queue() : count(0){
  end = NULL;
  beginning = end;
}


Queue::~Queue() {
  while(!isEmpty())
  {
    dequeue();
  }
}

void Queue::enqueue(int value){
    
  if(this->isEmpty()){
      beginning = new Node(value);
      end = beginning;
  }
  else
  {
      end->next = new Node(value);
      end = end->next;
  }
  
  count ++;
}

int Queue::dequeue(void){
  if( this->isEmpty() )
  {
      return EMPTY_VALUE;
  }
  
  int ret = beginning->value;

  Node *toBeDestroyed = beginning;
  
  beginning = beginning->next;

  delete(toBeDestroyed);
    
  count --;
	
  return ret;
}

int Queue::front(void){
  if(this->isEmpty()){
      return EMPTY_VALUE;
  }
  return beginning->value;
}

bool Queue::isEmpty(void){
  return (count == 0);
}

int Queue::size(void){
  return count;
}

