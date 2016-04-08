#include <stdio.h>
#include <string.h>

char* matcher(char* haystack, char* needle);

int main(){



char arr1[50] = "lorem dolor sit amet dol";
char arr2[20] = "mxdxlxrx";
char *rekt;



rekt = matcher(arr1, arr2);
if(rekt != NULL)
	printf("%s\n",rekt);
else
	printf("%s\n","rekt");
return 0;}

#include <string.h>

char* matcher(char* haystack, char* needle){
int i,j,buldum;
buldum=0;

	if(needle == NULL || haystack == NULL || strlen(needle)>strlen(haystack))
		return NULL;
	else
		for (i = 0; i < strlen(haystack) && buldum==0; i++)
		{
			printf("i-%d\n",i);
			j=0;
			if (needle[j]==haystack[i])
			{	
				printf("arr2'nin ilk elemanı eşleşti\n");
				
				for (; j < strlen(needle) && i+j < strlen(haystack); j+=2)
				{	
					printf("j-%d\n",j);
					if(needle[j]!=haystack[i+j])
					{	printf("Eşleşme bitti\n");
						j=0;
						break;
					}
					else
						printf("sonraki eşleşti\n");
				}
				if (j>(strlen(needle)-1))
				{	
					buldum=1;
					printf("buldum\n");
					return &(haystack[i]);
				}
			}
		}
return NULL;
}
