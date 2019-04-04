#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Stack{
    double n[1001];
    int topElem;

}Stack;

Stack *initStack(){
    Stack *a= malloc(sizeof(Stack));
    a->topElem = -1;
    return a;
}


void push(Stack *a, double num){
  
    ++(a->topElem);
    
   a->n[a->topElem] = num;
        
}

void pop(Stack *a){  
    --(a->topElem);
}

int top(Stack *a){
    return (a->n[a->topElem]);
}
int isEmpty(Stack *a){

    return a->topElem == -1;
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
