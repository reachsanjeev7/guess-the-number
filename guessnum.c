#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
int read_int(int *intp)
{
	char buf[16];
	char *retp;
	char *endptr;
	long input;

	retp = fgets(buf, sizeof(buf), stdin);
	if (retp == NULL)
		return -1;
	input = strtol(retp, &endptr, 10);

	if (*endptr != '\n')
		return -2;
	if (input > INT_MAX)
		return -2;
	if (input < INT_MIN)
		return -2;
	return 0;
}
int main(void)
{
	srand(time(NULL));
	int temp, guess_num, input_num, guess_count = 1;

	guess_num = rand() % 100;
	while (1) {
		printf("Enter your number : ");
		scanf("%d", &input_num);
		temp = read_int(&input_num);
		if (temp == 0) {
			if (guess_num == input_num) {
				printf("Hurray! You found the number ");
				printf("in %d guesses.\n", guess_count);
				break;
			} else if (input_num > guess_num) {
				printf("Your number is larger.\n\n");
				guess_count++;
			} else {
				printf("Your number is smaller.\n\n");
				guess_count++;
			}
		} else {
			printf("enter only integer\n");
		}
	}
}

