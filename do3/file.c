#include <stdio.h>

typedef struct S{

	int a;
	int b;
}S;

void sum(S* str){
	str->a += str->b;	
}

void swap(S* str){

	int n =  str->a;
	str->a = str->b;
	str->b = n;
}

void poww(S* str){
	int i;
	int a = str->a;
	if(str->b == 0) 
		str->a = 1;
	
	else
		for(i = 1; i < str->b; i++){
	
		str->a *= a;
		} 
}

void func(S* str, void(*foo[])(S*)){
	int i;
	for(i = 0; i < 3; i++)
	foo[i](str);

}


int main(){
	int a, b;
	S type;
void(*foo[3])(S*);

	foo[0] = sum;
	foo[1] = swap;
	foo[2] = poww;
	
	scanf("%d %d", &a, &b);
	type.a = a;
	type.b = b;
	 func(&type,foo);
	printf("%d %d\n", type.a, type.b);
}
