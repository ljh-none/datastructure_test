#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define MAX 100

typedef struct stack

{

    int top;

    char stack[MAX];  //문자열을 받기 위한 char형 스택

}stack;

 

void init(stack *s)

{

    s->top = -1;

}

 

int isFull(stack *s)

{

    return s->top == MAX - 1; // 0을 제외한 모든 수가 참임. 보통1

}

 

void push(stack *s, int n)

{

    if (isFull(s))

    {

        printf("FULL!");

        printf("\n");

        return;

    }

    else

    {

        s->top++;

        s->stack[s->top] = n;

    }

}

 

void push(stack *s, char n)

{

    if (isFull(s))

    {

        printf("FULL!");

        printf("\n");

        return;

    }

    else

    {

        s->top++;

        s->stack[s->top] = n;

    }

}

 

void pop(stack *s)                      //스택 원소를 삭제하고 출력만 되도록 하였다.

{

    if (s->top == -1)

    {

        printf("empty");

        return;

    }

    else

    {

        printf("%c", s->stack[s->top]);

        s->stack[s->top] = 0;

        s->top--;

    }

}

 

void Display(stack s)

{

    printf("%s", s.stack);

    printf("\n");

}

//여기까지 pop을 제외한 기본 스택 구현 코드이다.

 

void change(stack *s, stack *s_)      //전위표기식에서 후위표기식으로 변환해주는 함수

{

    char n;

    stack k;                                             //표 7-2의 stack[] 역할

    init(&k);

    int temp = 0;

    while (temp != s->top + 1)

    {

        n = s->stack[temp];

        switch (n)                    //연산자 때문에 switch구문을 사용하였다.

        {

        case '(':

            push(&k, '(');

            break;

 

        case ')':                               //괄호 사이의 모든 연산자 출력

            while (k.stack[k.top] != '(')

            {

                push(s_, k.stack[k.top]);  //s_는 후위표기식 저장 스택.

                pop(&k);       //출력이 이루어질 때마다 한문자씩 저장

            }

            k.top--;

            break;

 

        case '+':

            if (k.stack[k.top] == '*')                    //연산자 우선순위

            {

                push(s_, k.stack[k.top]);

                pop(&k);

            }

            else if (k.stack[k.top] == '/')

            {

                push(s_, k.stack[k.top]);

                pop(&k);

            }

            push(&k, '+');

            break;

 

        case '-':

            if (k.stack[k.top] == '*')                    //연산자 우선순위

            {

                push(s_, k.stack[k.top]);

                pop(&k);

            }

            else if (k.stack[k.top] == '/')

            {

                push(s_, k.stack[k.top]);

                pop(&k);

            }

            push(&k, '-');

            break;

 

        case '/':

            if (k.stack[k.top] == '*')                    //연산자 우선순위

            {

                push(s_, k.stack[k.top]);

                pop(&k);

            }

            else if (k.stack[k.top] == '/')

            {

                push(s_, k.stack[k.top]);

                pop(&k);

            }

            push(&k, '/');

            break;

 

        case '*':

            if (k.stack[k.top] == '*')                    //연산자 우선순위

            {

                push(s_, k.stack[k.top]);

                pop(&k);

            }

            else if (k.stack[k.top] == '/')

            {

                push(s_, k.stack[k.top]);

                pop(&k);

            }

            push(&k, '*');

            break;

 

        default:                                 //연산자를 제외한 숫자들 처리

            push(s_, n);

            printf("%c", n);

            break;

        }

        temp++;

    }

    while (k.top != -1)                                     //남아있는 연산자 출력

    {

        push(s_, k.stack[k.top]);

        printf("%c", k.stack[k.top]);

        k.top--;

    }

}

 

void cal(stack *s_)                                           //후위표기식 계산 함수

{

    int sum;

    char n;

    int k[50] = { 0 };      //표 7-3의 stack[]역할

    int k_ = -1;

 

    int temp = 0;

    while (temp != s_->top + 1)

    {

        n = s_->stack[temp];

        switch (n)

        {

        case '+':

            sum = k[k_ - 1] + k[k_];

            k_--;

            k[k_] = sum;

            break;

 

        case '-':

            sum = k[k_ - 1] - k[k_];

            k_--;

            k[k_] = sum;

            break;

 

        case '/':

            sum = k[k_ - 1] / k[k_];

            k_--;

            k[k_] = sum;

            break;

 

        case '*':

            sum = k[k_ - 1] * k[k_];

            k_--;

            k[k_] = sum;

            break;

 

        default:

            k_++;

            k[k_] = (int)n - 48;        //아스키 코드를 이용해 상수로 바꿈

            break;

        }

        temp++;

    }

    printf("%d\n", k[0]);                     //배열의 맨 처음에 있는 계산결과 출력

}

 

int main()

{

    stack s; //중위식

    stack s_; //후위식

    init(&s);

    init(&s_);

    printf("중위식을 입력하세요\n=");

    scanf("%s", s.stack);                        //push의 사용이 까다로워서 우회함

    s.top = strlen(s.stack) - 1;                 //push를 대신해 top의 값 지정

    printf("입력한 중위식 :");

    Display(s);

    printf("변환한 후위식 :");

    change(&s, &s_);                           //중위식->후위식 변환

    printf("\n");

    printf("후위식 계산 :");

    cal(&s_);                                   //후위식 계산

    printf("\n");

}