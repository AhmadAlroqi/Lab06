#include <stdio.h>
#include <stdlib.h>

int StrengLength(char *text);

int main() {
    char *text = malloc(30 * sizeof(char));
    if (text == NULL) { 
        printf("no memory allocated\n");
	return 1;
    }

     printf("please enter text: ");
       fgets(text, 30, stdin); 
	for(int i=0 ; i<=30; i++){
		printf("%c", text[i]);
	}
	printf("\n");

    int length = StrengLength(text); 
      printf("Length: %d\n", length);

      text= realloc(text, length *sizeof(char));
      // printf("%lu",sizeof(text));

     char *reverse = malloc(length * sizeof(char));
  	for(int j=0;j<=length; j++ ){
	    reverse[j]=text[length-j];
		printf("%c", reverse[j]);
	}
	printf("\n");

    free(text);
    free(reverse);

    return 0;
}

int StrengLength(char *text) {
    int count= 0;
    for (int i= 0; text[i]!= '\0' && text[i]!= '\n'; i++) {
        count++;
    }
    return count;
}

