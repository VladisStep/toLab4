#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct StackElem{

    double n;
    struct StackElem *next;

}StackElem;


typedef struct Stack{

    struct StackElem *topElem;

}Stack;


Stack *initStack(){
    Stack *a  = malloc(sizeof(Stack));
    a -> topElem = NULL;
    return a;
}


void push(Stack *elements, double num){

    StackElem *a = malloc(sizeof(StackElem));
    a->n = num;

    if(elements -> topElem == NULL){
        
        a -> next = NULL;
        elements->topElem = a;       
    }
    
    else{
        
      a -> next = elements -> topElem;
      elements -> topElem = a;          
    }
}

Stack *pop(Stack *elements){

    if(elements -> topElem -> next == NULL){
        
        free(elements -> topElem);
        elements -> topElem = NULL;
        return elements;
    }
    
    else{
        
        StackElem *a = elements -> topElem;
        elements -> topElem = elements -> topElem -> next;
        free(a);
        return elements;
    }

}


int isEmpty(Stack *elements){

    return elements -> topElem == NULL;
}


int main() {
    
    Stack *heads = initStack();
    clock_t start, stop;
   int  i;
	double num;
	start = clock();
	for(i = 0; i < 1000; i++){
		scanf("%lf", &num);
		push(heads, num);	
	}
	stop = clock();	
	printf("%lf\n",(double)(stop - start)/CLOCKS_PER_SEC);

    return 0;
}
