#include <stdio.h>
#include <stdlib.h>

#define LIMIT 1000

int main(void)
{
	FILE *fin,*fout;
	int N;
	int i;
	char *sp;
	char *c;
	char *tmp;
	char s[LIMIT];
	if(!(fin = fopen("input.txt","r")))
	{
		printf("Error open of input file \n");
		getchar();
		return 0;
	}
	if(!(fout = fopen("output.txt","w")))
	{
		printf("Error open of output file \n");
		getchar();
		return 0;
	}
	printf("Emter N = ");
	scanf("%d",&N);
	while(fgets(s,sizeof(s),fin))
	{
		c = s;
		i = 0;
		sp = 0;
		while(*c)
		{
			if(*c==' '||*c==','||*c=='.'||*c=='\n'||*c=='\0')
			{
				i += sp?1:0;
				if(i==N)
				{
					tmp = sp;
					while(*sp++ = *c++);
					break;
				}
				sp = 0;
			}
			else sp = !sp?c:sp;
			c++;
		}
		fputs(s,fout);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}