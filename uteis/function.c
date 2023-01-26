#include<stdio.h>

char* hello_word() {
    return "Hello  Word";
}

void print_hello_word(char* hello) {
    printf("%s\n", hello_word());
}

int main(){
    print_hello_word(hello_word());

    return 0;
}