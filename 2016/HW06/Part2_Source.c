/* #part2
In this part, you will write a function for finding substring(s) in a given string. Instead of matching
the exact substring, you are asked to match only odd indexed characters. For example, if we look for
the “lerom” in “lorem ipsum dolor sit amet.” you’ll match the first word because 1st, 3rd and 5th
letters of the “lorem” matches with “lerom”.
The return value of this function is a character pointer to the first letter of the first occurrence of the
needle in the haystack. If there is no match, function returns null (i.e. 0).*/

#include <stdio.h>
#include <string.h>

/* Prototip(ler) */
char* matcher(char* haystack, char* needle);

int main(){

/* Aranacak kelimelerden olusan cumle stringi*/
char Haystack[50] = "lorem dolor sit amet dol";
/* Cumlede bulunacak kelime*/
char Needle[20] = "dolar";
char *ptr;

ptr = matcher(Haystack, Needle);
if(ptr != NULL)
	printf("%s\n",ptr);
else
	printf("%s\n","NULL");
return 0;}

char* matcher(char* haystack, char* needle){
int i,j,found;
found=0;
    /* If kontrol icin var. Aranan cumle stringi bos mu , aranan kelime stringi 
    bos mu , aranan kelime aranacak cumleden uzun mu diye 3 kontol gerekli */
	if(needle == NULL || haystack == NULL || strlen(needle)>strlen(haystack))
		return NULL;
	/* Eger kontrolleri gecerse islemlere gecebilir */	
	else
		for (i = 0; i < strlen(haystack) && found==0; i++)
		/* Cumledeki ilk harf ile kelimenin ilk harfi arasinda arama baslatan 
		for dongusu. Found isimli flag tuttum ki flag 1 olunca ciksin*/
		{
			if (needle[0]==haystack[i])
			/* Her zaman kelimenin ilk harfi ile cümlenin harfleri 
			   arasında karsilastirma yapacak ve esit harf bulunca ikinci for'a 
			   girsin ve orada da ikiser atlamali eslesmeye baksin*/
			{	
				for (j=0; j < strlen(needle) && i+j < strlen(haystack); j+=2) 
				/* ikiser atlamali olarak cümle ile kelime arasinda arama */
				{	
					if(needle[j]!=haystack[i+j]) 
					/* İlk harf uymustu ama eger iki sonraki harf uymaz ise 
					   break yapıp ciksin ve for ile baska keilemeler arasin */
					{
						break;
					}
				}
				
				if (j>=strlen(needle))
				/* Cift sayida harfi olan kelimeler icin 
				   gerekli olan kontrol if'i*/
				{	
					found=1; /* Eger bir kelime uydu ise flag degerini 0'dan 
					            1 yap ve ilk for dongusunu kir. Bulunan kelime 
					            ve sonrasini gonder */
					return &(haystack[i]); /* Bulunan i'yinci eleman sonrasini 
					                         gondermek icin kullanılan yontem */
				}
			}
		}
return NULL; /* Eger icerideki return olmaz ise son care buraya gel */
}
