#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// --- STACK YAPISI (Array Tabanlı) ---
char stack[MAX];
int top = -1;

// Stack'e eleman ekle
void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

// Stack'ten eleman çıkar
char pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}

// Stack'in tepesindeki elemana bak (Silmeden)
char peek() {
    if (top == -1) return -1;
    return stack[top];
}

// Operatör Önceliğini Belirle (Higher value = Higher precedence)
int precedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Karakterin operand (sayı/harf) olup olmadığını kontrol et
int isOperand(char ch) {
    return isalnum(ch); // C kütüphanesinden (a-z, A-Z, 0-9 kontrolü)
}

// --- ANA ALGORİTMA: INFIX -> POSTFIX ---
void infixToPostfix(char* infix, char* postfix) {
    int i = 0; // Infix indisi
    int j = 0; // Postfix indisi
    char x;

    // String bitene kadar dön
    while (infix[i] != '\0') {
        
        // 1. Eğer OPERAND ise direkt çıktıya yaz
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i];
        }
        
        // 2. Eğer SOL PARANTEZ '(' ise Stack'e at
        else if (infix[i] == '(') {
            push(infix[i]);
        }
        
        // 3. Eğer SAĞ PARANTEZ ')' ise
        else if (infix[i] == ')') {
            // '(' görene kadar Stack'tekileri pop et ve çıktıya yaz
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Sol parantezi '(' stackten at (çıktıya yazma)
        }
        
        // 4. Eğer OPERATÖR ise (+, -, *, /)
        else {
            // Stack boş değilse VE Stack tepesindeki operatörün önceliği
            // gelen operatörden büyük veya eşitse -> POP ET
            while (top != -1 && precedence(peek()) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            // Sonra gelen operatörü PUSH et
            push(infix[i]);
        }
        i++;
    }

    // 5. String bitti, Stack'te kalanları boşalt
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // String sonlandırıcı
}

// --- TEST MAIN ---
int main() {
    char infix1[] = "a*b+c";
    char postfix1[MAX];

    char infix2[] = "(a+b)*c";
    char postfix2[MAX];

    // Örnek 1
    infixToPostfix(infix1, postfix1);
    printf("Infix: %s\n", infix1);
    printf("Postfix: %s\n\n", postfix1);

    // Stack'i temizle (top'ı sıfırla)
    top = -1; 

    // Örnek 2
    infixToPostfix(infix2, postfix2);
    printf("Infix: %s\n", infix2);
    printf("Postfix: %s\n", postfix2);

    return 0;
}