#include <stdio.h>

#define LIMIT 1000

int main(void)
{
	FILE *fin,*fout;
	int N;
	int i;
	char *sp;
	char *c;
	int ch;
	char *tmp;
	char s[LIMIT];
	if(!(fin = fopen("input.txt","r")))
	{
		printf("Error open of input file \n");
		getchar();
		return 1;
	}
	if(!(fout = fopen("output.txt","w")))
	{
		printf("Error open of output file \n");
		getchar();
		return 1;
	}
	printf("Enter N = ");
	scanf("%d",&N);
	while(fgets(s,sizeof(s),fin))
	{
		c = s;
		i = 0;
		sp = 0;
		ch = 0;
		while(*c)
		{
			if((*c < 'a' || *c >'z') && (*c < 'A' || *c > 'Z') && ( *c < '0' || *c > '9'))
			{
				if(!ch)
				{
					i += sp?1:0;
					if(i==N)
					{
						tmp = sp;
						while(*sp++ = *c++);
						break;
					}
				}
				ch = 0;
				sp = 0;
			}
			else 
			{
				if(*c >= '0' && *c <= '9') ch = 1;
				sp = !sp?c:sp;
			}
			c++;
		}
		fputs(s,fout);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
