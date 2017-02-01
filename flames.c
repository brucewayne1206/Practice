# Practice
#include<stdio.h>
#include<string.h>
void shell(char flames[])
{
	printf("\n-------------------------------\n|");
	for(int i=0;flames[i]!='\0';i++)
	{
		if(flames[i]!='0')
		{
			printf("%c   |",flames[i]);
		}
		else
		{
			printf("    |");
		}
	}
	printf("\n-------------------------------\n");
}
int strike(char n1[],char n2[])
{
	int flag=0;
	for(int i=0;n1[i]!='\0';i++)
	{
		if(n1[i]!=' ')
		{
			flag=0;
			int k=i+1;
			for(int j=0;n2[j]!='\0';j++)
			{
				if(n1[i]==n2[j])
				{
					n2[j]='0';
					flag++;
					while(n1[k]!='\0')
					{
						if(n1[i]==n1[k])
						{
							n1[k]='0';
						}
						k++;
					}
					
				}
				if(n2[j]==' ')
				{
					n2[j]='0';
				}
			}
			if(flag!=0)
			{
				n1[i]='0';
			}
		}
		else
		{
			n1[i]='0';
		}
	}
	return 0;
}
int fstrike(char f[],int cnt)
{
	int i=-1,fcnt=0,c=0;
	while(c<5)
	{
		i=(i+1)%6;
		if(f[i]!='0')
		{
			fcnt++;
		}
		if(fcnt==cnt)
		{
			f[i]='0';
			fcnt=0;
			shell(f);
			c++;
		}
	}
}
void display(char f[], char n1[], char n2[])
{
	for(int i=0;f[i]!='\0';i++)
	{
		switch(f[i])
		{
			case 'F':	printf("\n%s and %s are good FRIENDS\n",n1,n2);
					break;
			case 'L':	printf("\nOoo! %s is in LOVE with %s\n",n1,n2);
					break;
			case 'A':	printf("\nJust AFFECTION between %s and %s?\n",n1,n2);
					break;
			case 'M':	printf("\n%s is going to MARRY %s?\n",n1,n2);
					break;
			case 'E':	printf("\n%s and %s are ENEMIES\n",n1,n2);
					break;
			case 'S':	printf("\n%s and %s are BROTHERS/SISTERS\n",n1,n2);
					break;
		}
	}
}
int main()
{
	char n1[100],n2[100],m1[100],m2[100];
	int cnt,i,k=0,fcnt=0;
	char f[]="FLAMES";
	char fname[100];
	printf("Enter Name 1: ");
	scanf("%s",n1);
	strcpy(m1,n1);
	printf("Enter Name 2: ");
	scanf("%s",n2);
	strcpy(m2,n2);
	strike(n1,n2);
	for(i=0;n1[i]!='\0';i++)
	{
		if(n1[i]!='0')
		{
			fname[k++]=n1[i];
		}
	}
	for(i=0;n2[i]!='\0';i++)
	{
		if(n2[i]!='0')
		{
			fname[k++]=n2[i];
		}
	}
	fname[k]='\0';
	cnt=k;
	shell(f);
	fstrike(f,cnt);
	display(f,m1,m2);
	return 0;
}
