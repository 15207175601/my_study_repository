#include<stdio.h>
/*#define SIZE 4
int main(void)
{
	short dates[SIZE];
	short * pti;
	short index;
	double bills[SIZE];
	double * ptf;

	pti = dates;
	ptf = bills;

	printf("%23s %15s\n", "short", "double");
	for (index = 0; index < SIZE; index++)
		printf("pointers + %d: %10p %10p\n", index, pti + index, ptf + index);
	getchar();
	return 0;
}*/
/*#define MONTHS 12
int main(void)
{
	int days[MONTHS] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int index;

	for (index = 0; index < MONTHS; index++)
		printf("Month %2d has %d days.\n", index + 1, *(days + index));

	getchar();
	return 0;
}*/
/*#define MSG "I am a symbolic string constant."
#define MAXLENGTH 81
int main(void)
{
	char words[MAXLENGTH] = "I am a string in an array.";
	const char * pt1 = "Something is pointing at me.";
	puts("Here are some strings:");
	puts(MSG);
	puts(words);
	puts(pt1);
	words[8] = 'p';
	puts(words);

	getchar();
	return 0;
}*/
/*int main(void)
{
	printf("%s, %p, %c\n", "we", "are", *"space farers");

	getchar();
	return 0;
}*/
/*#define MSG "I'm special"
int main(void)
{
	char ar[] = MSG;
	const char * pt = MSG;
	printf("address of \"I'm special\": %p \n", "I'am special");
	printf("		address ar: %p\n", ar);
	printf("		address pt: %p\n", pt);
	printf("		address of MSG: %p\n", MSG);
	printf("address of \"I'm special\": %p \n", "I'am special");

	getchar();
	return 0;
}*/
/*#define SLEN 40
#define LIM 5
int main(void)
{
	const char *mytalents[LIM] = {
		"Adding numbers swiftly",
		"Multiplying accurately","Stashing data",
		"Following instructions to the letter",
		"Understanding the C language"
	};
	char yourtalents[LIM][SLEN] = {
		"Walking in a straight line",
		"Sleeping","Watching television",
		"Mailing letters","Reading email"
	};
	int i;

	puts("let's compare talents.");
	printf("%-36s %-25s\n", "My Talents", "Your Talents");
	for (i = 0; i < LIM; i++)
		printf("%-36s %-25s\n", mytalents[i], yourtalents[i]);
	printf("\nsizeof mytalents: %zd, sizeof yourtalents: %zd\n",
		sizeof(mytalents), sizeof(yourtalents));

	getchar();
	return 0;
}*/
/*int main(void) {
	const char * mesg = "Don't be a fool!";
	const char * copy;

	copy = mesg;
	printf("%s\n", copy);
	printf("mesg = %s; &mesg = %p; value = %p\n", mesg, &mesg, mesg);
	printf("copy = %s; &copy = %p; value = %p\n", copy, &copy, copy);
	getchar();
	return 0;
}*/
/*#define STLEN 81
int main(void)
{
	char words[STLEN];

	puts("Enter a string, please.");
	gets(words);
	printf("your string twice:\n");
	printf("%s\n", words);
	puts(words);
	puts("Dones.");

	getchar();
	return 0;
}*/
/*#define STLEN 14
int main(void)
{
	char words[STLEN];

	puts("enter a string, please.");
	fgets(words, STLEN, stdin);
	printf("your string twice(puts(), then fputs()):\n");
	puts(words);
	fputs(words,stdout);
	puts("enter another string, please.");
	fgets(words, STLEN, stdin);
	printf("your string twice(puts(), then fputs()):\n");
	puts(words);
	fputs(words, stdout);
	puts("done.");

	getchar();
	getchar();
	getchar();
	return 0;
}*/
/*#define STLEN 10
int main(void)
{
	char words[STLEN];
	int i;

	puts("enter strings (empty line to quit):");
	while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
		//fputs(words, stdout);
	{
		i = 0;
		while (words[i] != '\n'&&words[i] != '\0')
			i++;
		if (words[i] == '\n')
			words[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
		puts(words);
	}
	puts("done.");

	getchar();
	getchar();
	getchar();
	return 0;
}*/
/*#define STLEN 10
int main(void)
{
	char words[STLEN];
	int i;

	puts("enter strings (empty line to quit):");
	while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
		fputs(words, stdout);

	puts("done.");

	getchar();
	getchar();
	getchar();
	return 0;
}*/
/*int main(void)
{
	char name1[11], name2[11];
	int count;

	printf("please enter 2 names.\n");
	count = scanf_s("%5s %10s", name1, 11,name2,11);
	printf("I read the %d names %s and %s.\n", count, name1, name2);
	getchar();
	getchar();
	getchar();
	
	return 0;
}*/
#define DEF "I am a #defined string."
int main(void) {
	char str1[80] = "an array was initialized to me.";
	const char * str2 = "a pointer was initialized to me.";

	puts("I'm an argument to puts().");
	puts(DEF);
	puts(str1);
	puts(str2);
	puts(&str1[5]);
	puts(str2 + 4);

	getchar();
	return 0;
}