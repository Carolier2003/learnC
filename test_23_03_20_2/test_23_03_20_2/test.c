#include<stdio.h>
#include<string.h>
/*********Begin*********/
struct candidate {
	char name[50];
	int votes;
};

/*********End**********/
int main(void)
{
	/*********Begin*********/
	int n;
	struct candidate c[3];
	strcpy(c[0].name, "Li");
	strcpy(c[1].name, "Zhang");
	strcpy(c[2].name, "Sun");
	c[0].votes = c[1].votes = c[2].votes = 0;
	scanf("%d", &n);
	char temp[20];
	int i = 0;
	for (i = 0; i < n; i++) {
		scanf("%s", &temp);
		if (strcmp(temp, c[0].name)== 0)
			c[0].votes++;
		if(strcmp(temp, c[1].name)== 0)
			c[1].votes++;
		if (strcmp(temp, c[2].name) == 0)
			c[2].votes++;
	}
	for (i = 0; i < 3; i++) {
		printf("%s:%d\n", c[i].name, c[i].votes);
	}
	/*********End**********/
	return 0;
}//