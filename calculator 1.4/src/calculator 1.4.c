//****************************************************************
// VITOS                Техническая справка             ver. 1.4 *
//                                                               *
// Данный код представляет собой простейший калькулятор. Он умеет*
// складывать,умножать,делить,возводить в степень,вычитать числа.*
// Также присутствуют функции нахождения факториала и квадратного*
// корня из числа.Каждый блок кода расписан.Была задействована   *
// доп.библиотека math,для корня и степени.Присутствуют различные*
// условные операторы,циклы.Помимо вышеперечисленного,делает     *
// различные операции над векторами.                             *
//                              Программу сделал Виталий Черников*
//****************************************************************

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

    // Переменные.Тут я говорю какие переменные будут использоваться
    // в моем коде и какой у них тип данных.
    char o,d,m,j;
    float *a,*b,*Q,c,x,y,w;
    int size;
    long int p=1;

    // выделяю место под вектора

    //БЛОК ПРИВЕТСТВИЯ
    printf("$           $       $ $$$ $$$$$  $$   $$$   \n");
    printf("$            $     $   $    $   $  $  $     \n");
    printf("$$$  $  $     $   $    $    $  $    $  $    \n");
    printf("$ $   $        $ $     $    $   $  $    $   \n");
    printf("$$$  $          $     $$$   $    $$   $$$   \n");
    printf("\n");
    printf("\n");
    printf("Welcome to the not-so-simple calculator!\n");
    printf("\n");

    // Блок приветствия. Блок приветствия был добавлен после создания всего
    // кода.Он необходим для 1. Красоты и 2.авторсокго права. Чтобы пользователь
    // знал кто создал код :)

    do {

    // БЛОК ВЫБОРА
    printf("What do you want to work with?\n");
    printf("1-Vectors\n");
    printf("2-Numbers\n");
    scanf(" %c",&o);
    // Блок выбора. Тут пользователь выбирает с чем хочет работать.

    if(o=='1'){
        printf("Enter the size of the vectors: \n");
        scanf("%d",&size);
        a=malloc(size*sizeof(int));
        b=malloc(size*sizeof(int));
        Q=malloc(size*sizeof(int));
        printf("Enter the first vector: \n");
        for(int i=0;i<size;i++)
        {scanf("%f",&a[i]);}
        printf("Enter the second vector: \n");
        for(int i=0;i<size;i++)
        {scanf("%f",&b[i]);}
        printf("What operation do you want to perform?(+,-,*): \n");
        scanf(" %c", &d);
        switch(d){
            case '+':
            for(int i=0;i<size;i++)
            {printf("%0.3f \n",a[i]+b[i]);}
            break;
            case '-':
            for(int i=0;i<size;i++)
            {printf("%0.3f \n",a[i]-b[i]);}
            break;
            case '*':
            for(int i=0;i<size;i++)
            {Q[i] = a[i]*b[i];}
            for(int i=0;i<size;i++)
            {c=Q[i] + c;}
            printf("%0.f \n",c);
            break;
            default:
            printf("Error:invalid operation\n");}

        free(a);
        free(b);
        free(Q);
        }

        // Векторные операции сверху. Пользователь вводит координаты вектора
        // операцию и там используются ячейки памяти под данные.
        // после вывода результата, ячейки очищаюся

    else if(o=='2'){
        // БЛОК 1
        printf("Enter the first number:\n");
        scanf("%f",&x);

        // Блок 1. Здесь пользователю показывается предложение
        // на ввод первого.Он вводит и переменной
        // x присваевается значение первого введенного числа

        // БЛОК 2
        printf("What operation do you want to perform?\n");
        printf("Available operations: +,-,*,/,!,^,#\n");
        printf("(! finding the factorial of the first number)\n");
        printf("(^ find the degree of a number)\n");
        printf("(# extract the root from the first number)\n");
        scanf("%s",&m);
        // Блок 2. Пользователю показывается сообщение о
        // выборе операции и доступные операции. Также есть
        // пояснения по некоторым операциям.

        // БЛОК 3
        if(m=='+'||m=='-'||m=='*'||m=='/')
          {printf("Enter the second number:\n");
          scanf("%f",&y);}
          else if(m=='^')
          {printf("Enter the degree:\n");
          scanf("%f",&y);}

        // Блок 3. Данный блок необходим для предоставления пользователю
        // ввода второго числа,если того требует операция.
        // БЛОК 4

          switch(m){
           case '+':
           w=x+y;
           printf("%.3f\n",w);
           break;
           case '-':
           w=x-y;
           printf("%.3f\n",w);
           break;
           case '*':
           w=x*y;
           printf("%.3f\n",w);
           break;
           case '/':
           if(y==0)
           printf("Error:cannot be divided by 0\n");
           else{
           w=x/y;
           printf("%.5f\n",w);}
           break;
           case '!':
              if(x<0)
              printf("Еrror:negative number\n");
              else if (x==0)
              printf("1\n");
              else if (x==1)
              printf("1\n");
              else if(x-(int)x!=0)
              printf("Error: You can't use fractional numbers\n");
              else {
              for(float i=1; i<=x; i++)
              {p=p*i;}
              printf("%li\n",p);}
            break;
            case '^':
              if(y==0){
              printf("1\n");}
              else{
              printf("%0.5f\n",pow(x,y));}
            break;
            case '#':
              if (x<0)
              printf("Error:negative number\n");
              else
              printf("%.5f\n",sqrt(x));
            break;
            default:
            printf("Error:invalid operation\n");}}

    // Блок 4. Здесь происходит все самое важное. Условный оператор
    // switch анализирует, какую операцию выбрал пользователь и
    // выбирает нужный алгоритм действий. Также в некоторых случаях
    // есть условный оператор if и цикл for
    // Для реализации функции извлечения корня из числа и
    // нахождения степени пришлось дополнительно
    // подключить библиотеку math.h
    else{printf("Error:negative number\n");}
    // БЛОК 5
        printf("Do you want to continue? (y/n)\n");
        scanf("%s",&j);
        while ((j != 'y') && (j !='n'))
            {printf("Do you want to continue? (y/n)\n");
            scanf("%s",&j);}
    }
    while(j=='y');

        // Блок 5. Выводит сообщение о продолдении и если пользователь
        // отвечает удовлетворительно,программа продолжает свою работу,
        // в противном случае завершается.
    return 0; }
