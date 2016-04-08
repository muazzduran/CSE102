/*#part1
In this part of the homework, you will calculate the character frequency of a given string. You will
handle only the ASCII letters and digits. Any other characters such as punctuation marks and
whitespaces will be handled as the same.
Second parameter’s length is fixed and equals to 37. First 26 elements of it are letters in ascending
order, next 10 elements are digits and the last one is for the other characters. You should not modify
the order. Note that case sensitivity has no effect on letter frequency.*/

#include <stdio.h>
#define ALPHABET_LETTER_NUMBER 26

/* Prototip(ler) */
void freq(char* str, int* fr);

int main(){

	int fr[37];
	char giris;
	/* Test stringi*/
	freq("abCd Ef ghIj kLM nopr stuv yzwxq 123 4 5 6 7 890 00 ?? |",fr);
	/* Terminale bastırıp gorelim diye printf */
	printf("\t \t LETTERS \t \n");
	printf("A => %d \t", fr[0]); printf("B => %d \t", fr[1]); printf("C => %d \t", fr[2]); 
	printf("D => %d \t", fr[3]); printf("E => %d \t", fr[4]); printf("F => %d \t", fr[5]); 
	printf("G => %d \n", fr[6]); printf("H => %d \t", fr[7]); printf("I => %d \t", fr[8]); 
	printf("J => %d \t", fr[9]); printf("K => %d \t", fr[10]);printf("L => %d \t", fr[11]); 
	printf("M => %d \t", fr[12]);printf("N => %d \n", fr[13]);printf("O => %d \t", fr[14]); 
	printf("P => %d \t", fr[15]);printf("Q => %d \t", fr[16]);printf("R => %d \t", fr[17]);
	printf("S => %d \t", fr[18]);printf("T => %d \t", fr[19]);printf("U => %d \n", fr[20]); 
	printf("V => %d \t", fr[21]);printf("W => %d \t", fr[22]);printf("X => %d \t", fr[23]);
	printf("Y => %d \t", fr[24]);printf("Z => %d \t \n \n", fr[25]);
	
	printf("\t \t NUMBERS \t \n");
	printf("0 => %d \t", fr[26]);printf("1 => %d \t", fr[27]);printf("2 => %d \t", fr[28]); 
	printf("3 => %d \t", fr[29]);printf("4 => %d \t", fr[30]);printf("5 => %d \t", fr[31]); 
	printf("6 => %d \n", fr[32]);printf("7 => %d \t", fr[33]);printf("8 => %d \t", fr[34]); 
	printf("9 => %d \t \n \n", fr[35]);
	
	printf("Others => %d \n",fr[36]);

	return 0;
}


void freq(char* str, int* fr){
    
    int i;
	
	for(i=0;i<37;i++) /*Arrayin tum elemanlarini sifirlama islemi*/
		fr[i]=0;
    
    /* Fr'deki i'yinci elemanin degerini arttirma islemleri */
    for(i=0;str[i]!='\0';i++)
    {
    	if(str[i]>='a' && str[i]<='z') 
	    	fr[str[i]-'a']++;    
	    	/* Gelen karakter kucuk harf ise
	    	onu kucuk a'dan cikar ki bi sayi bulasin 
	    	ve o sayi fr[0-26] arasi bi deger olsun */
	    	
	    else if(str[i]>='A' && str[i]<='Z')
            fr[str[i]-'A']++;      
            /* Gelen karakter buyuk harf ise
            onu BUYUK A'dan cikar ki bi sayi bulasin 
            ve o sayi fr[0-26] arasi bi deger olsun */
            
		else if (str[i]>='0' && str[i]<='9') 
    		fr[(str[i]-'0') + ALPHABET_LETTER_NUMBER ]++;
    		/* Gelen karakter rakam ise 
    	    ona alfabedeki harf sayisini (26) ekle 
    		ve fr [ 27- 35 ] arasi bi deger olsun*/
    	
    	else
	    	fr[36]++;
	    	/* Gelen karakter harf ve rakam disinda bir sey ise 
    	    sadece 36.array indeksini arttir */
    }
}
