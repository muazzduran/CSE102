/* #part3
In this part, you will implement a function that counts the occurrences of a substring in the a given
string using the matcher function that you wrote in part2. Note that you will match only the odd
indexed characters.*/

#include <string.h>
#include <stdio.h>

/* Prototip(ler) */
int count(char* str, char* substr);

int main(){

char Str[50] = "ecececec"; /* Aranacak cümle */
char Substr[20] = "ece"; /* Aranacak kelime */

printf ("%d\n",count(Str, Substr)); /* Return degerini bastirma */

return 0;
}


int count(char* str, char* substr){
int i,j,numerator;
numerator=0;
	/* If kontrol icin var. Aranan cumle stringi bos mu , aranan kelime stringi 
    bos mu , aranan kelime aranacak cumleden uzun mu diye 3 kontol gerekli */
	if(str == NULL || substr == NULL || strlen(substr)>strlen(str))
		return 0;
	/* Eger kontrolleri gecerse islemlere gecebilir */	
	else
		for (i = 0; i < strlen(str) ; i++)
		/* Cumledeki ilk harf ile kelimenin ilk harfi arasinda arama baslatan 
		for dongusu. Kelimenin hep ilk harfine , cumlenin sirasiyla tüm 
		harflerine bakacak */
		{
			if (substr[0]==str[i])
			/* Her zaman kelimenin ilk harfi ile cümlenin harfleri 
			arasında karsilastirma yapacak ve esit harf bulunca ikinci for'a 
			girecek ve orada da ikiser atlamali eslesmeye bakacak*/
			{					
				for (j=0; j < strlen(substr) && i+j < strlen(str); j+=2)
				/* Ikiser atlamali olarak cümle ile kelime arasinda arama. 
				Alttaki if'de hem i'yi hem de j'yi arttırıp ikiser atlayarak 
				aramayi kontrol ediyor*/
				{	
					if(substr[j]!=str[i+j])
					/* Ilk harf uymustu ama eger iki sonraki harf uymaz ise 
					break yapıp ciksin ve for ile baska keilemeler arasin */
					{
						break;
					}				
				}
				
				if (j>=strlen(substr))
				/* Cift sayida harfi olan kelimeler icin 
				gerekli olan kontrol if'i*/
				{	
					numerator++; /* Kac kere aranan kelime bulundu sayaci */		
				}
			}
		}
return numerator; /* Bulunan kelime sayaci. Hic yoksa sifir doner */
}
