//****************************************************************
// VITOS                Техническая справка            ver. 1.63 *
//                                                               *
// Данный код представляет собой не самый простой калькулятор.   *
// Он умеет складывать,умножать,делить,возводить в степень,      *
// вычитать числа. Берет данные из файла                         *
// Также присутствуют функции нахождения факториала и квадратного*
// корня из числа.Каждый блок кода расписан.Была задействована   *
// доп.библиотека math,для корня и степени.Присутствуют различные*
// условные операторы,циклы.Помимо вышеперечисленного,делает     *
// различные операции над векторами.                             *
//_______________________________________________________________*
// Принцип работы калькулятора с файлами!!!                      *
// 1. Файл input.txt - входной, калькулятор берет данные из него*
//    !!!ПОСЛЕДОВАТЕЛЬНОСТЬ ВВОДА ДАННЫХ В КАЛЬКУЛЯТОР!!!        *
// Если хотите работать с векторами:                             *
// A. В текстовом файле пишите "v" - вектора;                    *
// B. МЕЖДУ СИМВОЛАМИ ДОЛЖЕН БЫТЬ ПРОБЕЛ!                        *
// С. Пишется размер вектора                                     *
// D. Пишутся координаты ПЕРВОГО вектора через ПРОБЕЛ            *
// E. Пишутся координаты ВТОРОГО ветора через ПРОБЕЛ             *
// G. Пишется знак операции "+","-","*"                          *
// H. Сохраняете файл и закрываете его                           *
// ПРИМЕР: v 3 -1 2 5 2 7 4 -                                    *
//_______________________________________________________________*
// Если хотите работать с числами:                               *
// А. Пишите ПЕРВОЕ число                                        *
// В. Пишите знак операции "+","-","*","^","/","!","#"           *
// С. Пишите ВТОРОЕ число                                        *
// ВНИМАНИЕ! Если хотите найти факториал(!) или корень(#)        *
// второе число писать НЕ нужно!                                 *
// ПРИМЕР: n 5 + 94                                              *
//_______________________________________________________________*
// 2. Файл output.txt - выводной, калькулятор выводит в него     *
// данные после выполнения операции.                             *
//_______________________________________________________________*
//                              Программу сделал Виталий Черников*
//****************************************************************

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

    // Переменные.Тут я говорю какие переменные будут использоваться
    // в моем коде и какой у них тип данных.
    char o,d,m,input[50],output[50],j;
    float *a,*b,*Q,c,x,y,w;
    int size;
    long int p=1;

    // запускаем код
    do {

    // просим ввести нам названия файлов

    printf("Enter the name of the input file in the format (name.txt): \n");
    scanf("%s", &input);
    printf("Enter the name of the output file in the format (name.txt): \n");
    scanf("%s", &output);

    // Создание файла, для работы с данными из файла

    FILE *fin,*fan;
    fin = fopen(input,"r");
    fan = fopen(output,"a");

    // выделяю место под вектора
    a=malloc(size*sizeof(int));
    b=malloc(size*sizeof(int));
    Q=malloc(size*sizeof(int));

    //БЛОК ПРИВЕТСТВИЯ
    fprintf(fan,"$           $       $ $$$ $$$$$  $$   $$$   \n");
    fprintf(fan,"$            $     $   $    $   $  $  $     \n");
    fprintf(fan,"$$$  $  $     $   $    $    $  $    $  $    \n");
    fprintf(fan,"$ $   $        $ $     $    $   $  $    $   \n");
    fprintf(fan,"$$$  $          $     $$$   $    $$   $$$   \n");
    fprintf(fan,"\n");
    fprintf(fan,"\n");
    fprintf(fan,"Welcome to the not-so-simple calculator!\n");
    fprintf(fan,"\n");

    // Блок приветствия. Блок приветствия был добавлен после создания всего
    // кода.Он необходим для 1. Красоты и 2.авторсокго права. Чтобы пользователь
    // знал кто создал код :)
    // БЛОК ВЫБОРА

    fscanf(fin," %c",&o);
    // Блок выбора. Тут пользователь выбирает с чем хочет работать.

    if(o=='v'){
        fscanf(fin,"%d",&size);
        for(int i=0;i<size;i++)
        {fscanf(fin,"%f",&a[i]);}
        for(int i=0;i<size;i++)
        {fscanf(fin,"%f",&b[i]);}
        fscanf(fin," %c", &d);
        switch(d){
            case '+':
            fprintf(fan,"(");
            for(int i=0;i<size;i++)
            {Q[i]=a[i]+b[i];
            fprintf(fan,"%0.3f ",a[i]);}
            fprintf(fan,") ");
            fprintf(fan,"%c ",d);
            fprintf(fan,"(");
            for(int i=0;i<size;i++)
            {fprintf(fan,"%0.3f ",b[i]);}
            fprintf(fan,") = ");
            for(int i=0;i<size;i++)
            {fprintf(fan,"%0.3f ",Q[i]);}
            break;
            case '-':
            fprintf(fan,"(");
            for(int i=0;i<size;i++)
            {Q[i]=a[i]-b[i];
            fprintf(fan,"%0.3f ",a[i]);}
            fprintf(fan,") ");
            fprintf(fan,"%c ",d);
            fprintf(fan,"(");
            for(int i=0;i<size;i++)
            {fprintf(fan,"%0.3f ",b[i]);}
            fprintf(fan,") = ");
            for(int i=0;i<size;i++)
            {fprintf(fan,"%0.3f ",Q[i]);}
            break;
            case '*':
            fprintf(fan,"(");
            for(int i=0;i<size;i++)
            {Q[i] = a[i]*b[i];}
            for(int i=0;i<size;i++)
            {c=Q[i] + c;
            fprintf(fan,"%0.3f ",a[i]);}
            fprintf(fan,") ");
            fprintf(fan,"%c ",d);
            fprintf(fan,"(");
            for(int i=0;i<size;i++)
            {fprintf(fan,"%0.3f ",b[i]);}
            fprintf(fan,") = ");
            for(int i=0;i<size;i++)
            {fprintf(fan,"%0.3f ",c);}
            break;
            default:
            fprintf(fan,"Error:invalid operation\n");}

        free(a);
        free(b);
        free(Q);
        }

        // Векторные операции сверху. Пользователь вводит координаты вектора
        // операцию и там используются ячейки памяти под данные.
        // после вывода результата, ячейки очищаюся

    else if(o=='n'){
        // БЛОК 1
        fscanf(fin,"%f",&x);

        // Блок 1. Здесь пользователю показывается предложение
        // на ввод первого.Он вводит и переменной
        // x присваевается значение первого введенного числа

        // БЛОК 2
        fscanf(fin,"%s",&m);
        // Блок 2. Пользователю показывается сообщение о
        // выборе операции и доступные операции. Также есть
        // пояснения по некоторым операциям.

        // БЛОК 3
        if(m=='+'||m=='-'||m=='*'||m=='/')
          {fscanf(fin,"%f",&y);}
          else if(m=='^')
          {fscanf(fin,"%f",&y);}

        // Блок 3. Данный блок необходим для предоставления пользователю
        // ввода второго числа,если того требует операция.
        // БЛОК 4

          switch(m){
           case '+':
           w=x+y;
           fprintf(fan,"%.3f ",x);
           fprintf(fan,"%c",m);
           fprintf(fan," %.3f",y);
           fprintf(fan," = ");
           fprintf(fan,"%.3f",w);
           break;
           case '-':
           w=x-y;
           fprintf(fan,"%.3f ",x);
           fprintf(fan,"%c",m);
           fprintf(fan," %.3f",y);
           fprintf(fan," = ");
           fprintf(fan,"%.3f",w);
           break;
           case '*':
           w=x*y;
           fprintf(fan,"%.3f ",x);
           fprintf(fan,"%c",m);
           fprintf(fan," %.3f",y);
           fprintf(fan," = ");
           fprintf(fan,"%.3f",w);
           break;
           case '/':
           if(y==0)
           fprintf(fan,"Error:cannot be divided by 0\n");
           else{
           w=x/y;
           fprintf(fan,"%.3f ",x);
           fprintf(fan,"%c",m);
           fprintf(fan," %.3f",y);
           fprintf(fan," = ");
           fprintf(fan,"%.5f",w);}
           break;
           case '!':
              if(x<0)
              fprintf(fan,"Еrror:negative number");
              else if (x==0){
              fprintf(fan,"%.3f ",x);
         	  fprintf(fan,"%c",m);
              fprintf(fan," = ");
              fprintf(fan,"1");}
              else if (x==1){
              fprintf(fan,"%.3f ",x);
              fprintf(fan,"%c",m);
              fprintf(fan," = ");
              fprintf(fan,"1");}
              else if(x-(int)x!=0)
              fprintf(fan,"Error: You can't use fractional numbers");
              else {
              for(float i=1; i<=x; i++)
              {p=p*i;}
              fprintf(fan,"%.3f ",x);
              fprintf(fan," %c",m);
              fprintf(fan," = ");
              fprintf(fan,"%li\n",p);}
            break;
            case '^':
              if(y==0){
             fprintf(fan,"%.3f ",x);
              fprintf(fan,"%c",m);
              fprintf(fan," %.3f",y);
              fprintf(fan," = ");
              fprintf(fan,"1");}
              else{
              fprintf(fan,"%.3f ",x);
              fprintf(fan,"%c",m);
              fprintf(fan," %.3f",y);
              fprintf(fan," = ");
              fprintf(fan,"%0.5f",pow(x,y));}
            break;
            case '#':
              if (x<0)
              fprintf(fan,"Error:negative number");
              else
              fprintf(fan,"%.3f ",x);
              fprintf(fan,"%c",m);
              fprintf(fan," = ");
              fprintf(fan,"%.5f",sqrt(x));
            break;
            default:
            fprintf(fan,"Error:invalid operation");}}

    // Блок 4. Здесь происходит все самое важное. Условный оператор
    // switch анализирует, какую операцию выбрал пользователь и
    // выбирает нужный алгоритм действий. Также в некоторых случаях
    // есть условный оператор if и цикл for
    // Для реализации функции извлечения корня из числа и
    // нахождения степени пришлось дополнительно
    // подключить библиотеку math.h

    else{fprintf(fan,"Error:negative number\n");}

    fclose(fan);
    fclose(fin);

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
