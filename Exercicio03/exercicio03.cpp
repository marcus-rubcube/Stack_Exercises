# include <stdio.h>
# include <string.h>
# include <conio2.h>
# include <locale.h>
# include "tad.h"
# include <ctype.h>

char convertePolonesa(char exp[50]){
	TpPilha P;
	int num1, num2;
	
	for (int i = 0; exp[i] != '\0'; i++){
		if(isdigit(exp[i])){
			push(P, exp[i]);
		} else {
			num2 = pop(P) - '0';
			num1 = pop(P) - '0';
			if(exp[i] == '+'){
				push(P, (num1 + num2) + '0');
			}
			if(exp[i] == '-'){
				push(P, (num1 - num2) + '0');
			}
			if(exp[i] == '*'){
				push(P, (num1 * num2) + '0');
			}
			if(exp[i] == '/'){
				push(P, (num1 / num2) + '0');
			}
		}
	}
	
	printf("%d\n", pop(P)-'0');
	getch();
}

int main(){
	setlocale(LC_ALL, "");
	char exp[50];
	char resp;
	
	printf("Informe a expressão matemática: ");
	fflush(stdin);
	gets(exp);
	
	convertePolonesa(exp);
}
