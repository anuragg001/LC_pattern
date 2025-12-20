//progrma to implement lexical anaysis 
#include <stdio.h>




int main(){



    if(isaplha(input[i])){
        j=0;
        while(isalnum(input[i])){
            token[j++]=input[i++];

        }
        token[j]='\0';

        if(isKeyword(token)){
            printf("<KEYWORD , %s>\n",token);
            
        }
    }
}