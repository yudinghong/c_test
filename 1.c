#include <stdio.h>
#include <string.h>
void printArr(int *arr, int nums, char *str){
	printf("now num array: ");	
	for(int i=0; i < nums; i++){
		printf("%d ", *(arr+i));
	}
	printf("\n");
	printf("now operator array: ");
	for(int i=0; i < nums; i++){
		printf("%c ", *(str+i));
	}
	printf("\n");
}

int main(void)
{
	char statement[1000] = "2+4-23+4*7*3/4+43*2-2*3+9/3=";
//	scanf("%s", statement);

	int index = 0;
	int len = (int)strlen(statement);
	int operNum = 0;
	int operNumArr[1000] = {0};
	char operatorArr[1000] = {0};
	int nums= 0;
	while(index < len){
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
				operNum = operNum * 10 + (statement[index] - '0');
				break;	
			}
			default: 
			{
				operNumArr[nums] = operNum;
				operNum = 0;
				printf("add to arr: %d\n", operNumArr[nums]);
				if (nums > 0) {
					// if current operator is + or -, calculate pre num and top num
					if ((statement[index] == '=') ||
					(statement[index] == '+' || statement[index] == '-') || 
					((statement[index] == '*' || statement[index] == '/') && (operatorArr[nums-1] == '*' || operatorArr[nums-1] == '/'))){
						switch(operatorArr[nums-1]){
							case '+': 
							{
								operNumArr[nums-1] = operNumArr[nums-1] + operNumArr[nums];break;
							}
							case '-': 
							{
								operNumArr[nums-1] = operNumArr[nums-1] - operNumArr[nums];break;
							}
							case '*': 
							{
								operNumArr[nums-1] = operNumArr[nums-1] * operNumArr[nums];break;
							}
							case '/': 
							{
								operNumArr[nums-1] = operNumArr[nums-1] / operNumArr[nums];break;
							}
							default: break;
						}	
						operatorArr[nums-1] = statement[index];
					}
					else {
						operatorArr[nums] = statement[index];	
						nums++; 
					}
					printArr(operNumArr, nums, operatorArr);
				}
				else {
					printf("add operator: %c\n", statement[index]);
					operatorArr[nums] = statement[index];	
					nums++;
				}
			}
		}
		index++;
	}
	printArr(operNumArr, nums, operatorArr);
	printf("nums: %d", nums);
	int i = 0;
	while(i < nums-1){
		switch(operatorArr[i]){
			case '+': 
			{
				operNumArr[0] = operNumArr[0] + operNumArr[i+1];break;
			}
			case '-': 
			{
				operNumArr[0] = operNumArr[0] - operNumArr[i+1];break;
			}
//			case '*': 
//			{
//				operNumArr[0] = operNumArr[i] * operNumArr[i+1];break;
//			}
//			case '/': 
//			{
//				operNumArr[0] = operNumArr[i] / operNumArr[i+1];break;
//			}
			default: break;
		}	
		i++;
	}
	printf("\n%d", operNumArr[0]);
	return 0;
}
