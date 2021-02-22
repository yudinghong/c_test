#include <stdio.h>
#include <string.h>

int main(void)
{
	char statement[1000] = "";
	scanf("%s", statement);
	int index = 0;
	int len = (int)strlen(statement);
	int operNumA = 0;
	int operNumB = 0;
	int operateFlag = -1; // 0 add 1 dec 2 equal
	while(index < len && operateFlag != 2){
		switch(statement[index]){
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			{
				operNumB = operNumB * 10 + (statement[index] - '0');
				break;	
			}
			case '+':
			case '-':
			case '=':
			{
				if (operateFlag == -1){
					operNumA = operNumB;
				}
				else if(operateFlag == 0) {
					operNumA += operNumB;
				}
				else if(operateFlag == 1) {
					operNumA -= operNumB;
				}
				operNumB = 0;
				if (statement[index] == '+'){
					operateFlag = 0;	
				}
				else if (statement[index] == '-'){
					operateFlag = 1;
				}
				else if (statement[index] == '='){
					operateFlag = 2;	
				}
				break;
			}
			default: break;
		}
		index++;
	}
	printf("%d", operNumA);
	return 0;
}
