#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.c>
#include <ctype.h>
//Desenvolvido por: Douglas Geller e Carlos Eduardo Oliveira da Silva

int main()
{
    setlocale(LC_ALL, "");
    char dificuldade;
    int  i, j, ii, jj, x, erro, eixoX = 0, eixoY = 0, V[9], M [9][9] = {{5,3,0,0,7,0,0,0,0},
                                                                        {6,0,0,1,9,5,0,0,0},
                                                                        {0,9,8,0,0,0,0,6,0},
                                                                        {8,0,0,0,6,0,0,0,3},
                                                                        {4,0,0,8,0,3,0,0,1},
                                                                        {7,0,0,0,2,0,0,0,6},
                                                                        {0,6,0,0,0,0,2,8,0},
                                                                        {0,0,0,4,1,9,0,0,5},
                                                                        {0,0,0,0,8,0,0,7,9}};
    int MM [9][9] = {{2,8,6,1,9,0,0,4,7},
                     {3,0,0,0,2,0,1,5,6},
                     {5,4,1,0,0,0,8,9,2},
                     {1,9,0,6,0,0,0,8,0},
                     {6,3,0,8,0,0,5,7,9},
                     {8,5,0,3,7,9,4,0,0},
                     {7,0,5,0,0,0,6,0,4},
                     {0,0,3,0,4,6,7,2,0},
                     {0,6,8,2,3,7,9,1,0}};

    textcolor(9); //Cor azul claro
    printf("\n\t\t\t\tWelcome to Sudoku\nRegras do Jogo:\nNão é permitido ter 2 números iguais na mesma coluna, nem na mesma linha e também em seus quadrantes 3x3.\n\nBOA SORTE!\n");
    textcolor(7); //Cor Padrão
    printf("\nAtualmente, é possível escolher entre duas dificuldades:\n\n\tFácil\t\t     Difícil\n  2|8|6|1|9|0|0|4|7\t5|3|0|0|7|0|0|0|0\n  3|0|0|0|2|0|1|5|6\t6|0|0|1|9|5|0|0|0\n  5|4|1|0|0|0|8|9|2\t0|9|8|0|0|0|0|6|0\n  1|9|0|6|0|0|0|8|0\t8|0|0|0|6|0|0|0|3\n  6|3|0|8|0|0|5|7|9\t4|0|0|8|0|3|0|0|1\n  8|5|0|3|7|9|4|0|0\t7|0|0|0|2|0|0|0|6\n  7|0|5|0|0|0|6|0|4\t0|6|0|0|0|0|2|8|0\n  0|0|3|0|4|6|7|2|0\t0|0|0|4|1|9|0|0|5\n  0|6|8|2|3|7|9|1|0\t0|0|0|0|8|0|0|7|9");
    printf("\n\nDigite a dificuldade escolhida: F-FÁCIL  D-DIFÍCIL\n");
    fflush(stdin);
    scanf("%c", &dificuldade);
    dificuldade = toupper(dificuldade);//Transforma em maiúsculo

    switch (dificuldade){
        case 'D': printf("A dificuldade escolhida foi: Difícil\t\tO jogo vai começar!!!");
    do{ //começa o jogo
    erro = 0; //Zera os erros a cada loop
    //Mostra a matriz
    textcolor(1); //Cor azul
    printf("\n\n\tC1\tC2\tC3\tC4\tC5\tC6\tC7\tC8\tC9\n\n\n"); //Imprime as colunas
    fflush(stdin);
    for (i=0;i<9;i++){
    textcolor(1); //Cor azul
    printf("L%d", i+1); // Imprime as linhas
            fflush(stdin);
        for (j=0;j<9;j++){
            textcolor(7); //Cor padrão para elementos fixos
            if(eixoX==0 && eixoY==0){ //significa que é o primeiro desenho
                printf("\t%d", M[i][j]);
            }else{
                if (i == eixoX && j== eixoY){
                   textcolor(4);
                }
                printf("\t%d", M[i][j]);
            }
            textcolor(4);
        }
    printf("\n\n\n");
    }

    textcolor(7); // Cor padrão
    //Alterar algum número na matriz
    printf("Digite a linha que deseja alterar: ");
    scanf("%d",&i);
    printf("Digite a coluna que deseja alterar: ");
    scanf("%d",&j);
        if (M[i-1][j-1] == M[0][0]){
        textcolor(4);
        printf("\nO Número na L%d/C%d não é alterável\n", i, j);}
            else{
            printf("Digite o número que deseja inserir neste local: ");
            textcolor(4);
            scanf("%d",&M[i-1][j-1]);}
            eixoX = i-1;
            eixoY = j-1;
            //M[eixoX][eixoy]


    //Verificação de '0'
    for (j=0;j<9;j++){
        for(i=0;i<9;i++){
            if((M[i][j]) == 0){
            erro+=3;}
        }
    }

    //Verificação de números repetidos em colunas
    for (j=0;j<9;j++){
        for(i=0;i<9;i++){
            for(ii=0; ii<i; ii++){
            if((M[i][j]) == (M[ii][j]) && (M[i][j]) != 0){
                printf("\nNúmero repetido na L%d/L%d C%d\n", i+1, ii+1, j+1);
                erro++;}
            }
        }
    }
    //Verificação de números repetidos em linhas
    for (i=0;i<9;i++){
        for(j=0;j<9;j++){
            for(jj=0; jj<j; jj++){
            if((M[i][j]) == (M[i][jj]) && (M[i][j]) != 0){
                printf("\nNúmero repetido na C%d/C%d L%d\n", j+1, jj+1, i+1);
                erro++;}
            }
        }
    }
    //Verificação de números repetidos na primeira matriz 3x3
    x = 0;
    for (i=0;i<3;i++){
        for(j=0;j<3;j++){
        V[x] = M[i][j];
        x++;
        }
    }
    for (x=0;x<9;x++){
        for(i=0;i<x;i++){
        if (V[x] == V[i] && V[x] != 0){
            printf("\nHá mais de um '%d' entre a linha 1-3 e coluna 1-3\n", V[i]);
            erro++;}
        }
    }
     //Verificação de números repetidos na segunda matriz 3x3
    x = 0;
    for (i=3;i<6;i++){
        for(j=0;j<3;j++){
        V[x] = M[i][j];
        x++;
        }
    }
    for (x=0;x<9;x++){
        for(i=0;i<x;i++){
        if (V[x] == V[i] && V[x] != 0){
            printf("\nHá mais de um '%d' entre a linha 4-6 e coluna 1-3\n", V[i]);
            erro++;}
        }
    }
     //Verificação de números repetidos na terceira matriz 3x3
    x = 0;
    for (i=6;i<9;i++){
        for(j=0;j<3;j++){
        V[x] = M[i][j];
        x++;
        }
    }
    for (x=0;x<9;x++){
        for(i=0;i<x;i++){
        if (V[x] == V[i] && V[x] != 0){
            printf("\nHá mais de um '%d' entre a linha 7-9 e coluna 1-3\n", V[i]);
            erro++;}
        }
    }
      //Verificação de números repetidos na quarta matriz 3x3
    x = 0;
    for (i=0;i<3;i++){
        for(j=3;j<6;j++){
        V[x] = M[i][j];
        x++;
        }
    }
    for (x=0;x<9;x++){
        for(i=0;i<x;i++){
        if (V[x] == V[i] && V[x] != 0){
            printf("\nHá mais de um '%d' entre a linha 1-3 e coluna 4-6\n", V[i]);
            erro++;}
        }
    }
     //Verificação de números repetidos na quinta matriz 3x3
    x = 0;
    for (i=3;i<6;i++){
        for(j=3;j<6;j++){
        V[x] = M[i][j];
        x++;
        }
    }
    for (x=0;x<9;x++){
        for(i=0;i<x;i++){
        if (V[x] == V[i] && V[x] != 0){
            printf("\nHá mais de um '%d' entre a linha 4-6 e coluna 4-6\n", V[i]);
            erro++;}
        }
    }
      //Verificação de números repetidos na sexta matriz 3x3
    x = 0;
    for (i=6;i<9;i++){
        for(j=3;j<6;j++){
        V[x] = M[i][j];
        x++;
        }
    }
    for (x=0;x<9;x++){
        for(i=0;i<x;i++){
        if (V[x] == V[i] && V[x] != 0){
            printf("\nHá mais de um '%d' entre a linha 7-9 e coluna 4-6\n", V[i]);
            erro++;}
        }
    }
      //Verificação de números repetidos na sétima matriz 3x3
    x = 0;
    for (i=0;i<3;i++){
        for(j=6;j<9;j++){
        V[x] = M[i][j];
        x++;
        }
    }
    for (x=0;x<9;x++){
        for(i=0;i<x;i++){
        if (V[x] == V[i] && V[x] != 0){
            printf("\nHá mais de um '%d' entre a linha 1-3 e coluna 7-9\n", V[i]);
            erro++;}
        }
    }
      //Verificação de números repetidos na oitava matriz 3x3
    x = 0;
    for (i=3;i<6;i++){
        for(j=6;j<9;j++){
        V[x] = M[i][j];
        x++;
        }
    }
    for (x=0;x<9;x++){
        for(i=0;i<x;i++){
        if (V[x] == V[i] && V[x] != 0){
            printf("\nHá mais de um '%d' entre a linha 4-6 e coluna 7-9\n", V[i]);
            erro++;}
        }
    }
     //Verificação de números repetidos na nona matriz 3x3
    x = 0;
    for (i=6;i<9;i++){
        for(j=6;j<9;j++){
        V[x] = M[i][j];
        x++;
        }
    }
    for (x=0;x<9;x++){
        for(i=0;i<x;i++){
        if (V[x] == V[i] && V[x] != 0){
            printf("\nHá mais de um '%d' entre a linha 7-9 e coluna 7-9\n", V[i]);
            erro++;}
        }
    }
    printf("\nNúmeros que precisam ser alterados: %d", erro/3);
    }while(erro!=0);

    //Mostra a matriz finalizada

    printf("\nJogo Finalizado:\n\n\tC1\tC2\tC3\tC4\tC5\tC6\tC7\tC8\tC9\n\n\n");
    for (i=0;i<9;i++){
    printf("L%d", i+1);
        for (j=0;j<9;j++){
        printf("\t%d", M[i][j]);
        }
    printf("\n\n\n");
    }
    printf("\n\t\t\t\tParabéns, você concluiu o Sudoku!!!\n\nDesenvolvido por: Douglas Geller e Carlos Eduardo Oliveira da Silva\n\nObrigado por jogar!\n\n");
    break;
    system("pause");

    //-------------------------------------------------------------------------------//
    //FÁCIL

    case 'F': printf("A dificuldade escolhida foi: Fácil.\t\tO jogo vai começar!!!");{
    do{ //começa o jogo
    erro = 0; //Zera os erros a cada loop
    //Mostra a matriz
    textcolor(1); //Cor azul
    printf("\n\n\tC1\tC2\tC3\tC4\tC5\tC6\tC7\tC8\tC9\n\n\n"); //Imprime as colunas
    fflush(stdin);
    for (i=0;i<9;i++){
    textcolor(1); //Cor azul
    printf("L%d", i+1); // Imprime as linhas
    fflush(stdin);
        for (j=0;j<9;j++){
            textcolor(7); //Cor padrão para elementos fixos
            if(eixoX==0 && eixoY==0){ //significa que é o primeiro desenho
                printf("\t%d", MM[i][j]);
            }else{
                if (i == eixoX && j== eixoY){
                   textcolor(4);
                }
                printf("\t%d", MM[i][j]);
            }
            textcolor(4);
        }
    printf("\n\n\n");
    }

    textcolor(7); // Cor padrão
    //Alterar algum número na matriz
    printf("Digite a linha que deseja alterar: ");
    scanf("%d",&i);
    printf("Digite a coluna que deseja alterar: ");
    scanf("%d",&j);
        if (MM[i-1][j-1] == MM[0][0]){
        printf("\nO Número na L%d/C%d não é alterável\n", i, j);
        textcolor(4);}
            else{
            printf("Digite o número que deseja inserir neste local: ");
            textcolor(4);
            scanf("%d",&MM[i-1][j-1]);}
            eixoX = i-1;
            eixoY = j-1;
            //M[eixoX][eixoy]


    //Verificação de '0'
    for (j=0;j<9;j++){
        for(i=0;i<9;i++){
            if((MM[i][j]) == 0){
            erro+=3;}
        }
    }

    //Verificação de números repetidos em colunas
    for (j=0;j<9;j++){
        for(i=0;i<9;i++){
            for(ii=0; ii<i; ii++){
            if((MM[i][j]) == (MM[ii][j]) && (MM[i][j]) != 0){
                printf("\nNúmero repetido na L%d/L%d C%d\n", i+1, ii+1, j+1);
                erro++;}
            }
        }
    }
    //Verificação de números repetidos em linhas
    for (i=0;i<9;i++){
        for(j=0;j<9;j++){
            for(jj=0; jj<j; jj++){
            if((MM[i][j]) == (MM[i][jj]) && (MM[i][j]) != 0){
                printf("\nNúmero repetido na C%d/C%d L%d\n", j+1, jj+1, i+1);
                erro++;}
            }
        }
    }
    //Verificação de números repetidos na primeira matriz 3x3
    x = 0;
    for (i=0;i<3;i++){
        for(j=0;j<3;j++){
        V[x] = MM[i][j];
        x++;
        }
    }
    for (x=0;x<9;x++){
        for(i=0;i<x;i++){
        if (V[x] == V[i] && V[x] != 0){
            printf("\nHá mais de um '%d' entre a linha 1-3 e coluna 1-3\n", V[i]);
            erro++;}
        }
    }
     //Verificação de números repetidos na segunda matriz 3x3
    x = 0;
    for (i=3;i<6;i++){
        for(j=0;j<3;j++){
        V[x] = MM[i][j];
        x++;
        }
    }
    for (x=0;x<9;x++){
        for(i=0;i<x;i++){
        if (V[x] == V[i] && V[x] != 0){
            printf("\nHá mais de um '%d' entre a linha 4-6 e coluna 1-3\n", V[i]);
            erro++;}
        }
    }
     //Verificação de números repetidos na terceira matriz 3x3
    x = 0;
    for (i=6;i<9;i++){
        for(j=0;j<3;j++){
        V[x] = MM[i][j];
        x++;
        }
    }
    for (x=0;x<9;x++){
        for(i=0;i<x;i++){
        if (V[x] == V[i] && V[x] != 0){
            printf("\nHá mais de um '%d' entre a linha 7-9 e coluna 1-3\n", V[i]);
            erro++;}
        }
    }
      //Verificação de números repetidos na quarta matriz 3x3
    x = 0;
    for (i=0;i<3;i++){
        for(j=3;j<6;j++){
        V[x] = MM[i][j];
        x++;
        }
    }
    for (x=0;x<9;x++){
        for(i=0;i<x;i++){
        if (V[x] == V[i] && V[x] != 0){
            printf("\nHá mais de um '%d' entre a linha 1-3 e coluna 4-6\n", V[i]);
            erro++;}
        }
    }
     //Verificação de números repetidos na quinta matriz 3x3
    x = 0;
    for (i=3;i<6;i++){
        for(j=3;j<6;j++){
        V[x] = MM[i][j];
        x++;
        }
    }
    for (x=0;x<9;x++){
        for(i=0;i<x;i++){
        if (V[x] == V[i] && V[x] != 0){
            printf("\nHá mais de um '%d' entre a linha 4-6 e coluna 4-6\n", V[i]);
            erro++;}
        }
    }
      //Verificação de números repetidos na sexta matriz 3x3
    x = 0;
    for (i=6;i<9;i++){
        for(j=3;j<6;j++){
        V[x] = MM[i][j];
        x++;
        }
    }
    for (x=0;x<9;x++){
        for(i=0;i<x;i++){
        if (V[x] == V[i] && V[x] != 0){
            printf("\nHá mais de um '%d' entre a linha 7-9 e coluna 4-6\n", V[i]);
            erro++;}
        }
    }
      //Verificação de números repetidos na sétima matriz 3x3
    x = 0;
    for (i=0;i<3;i++){
        for(j=6;j<9;j++){
        V[x] = MM[i][j];
        x++;
        }
    }
    for (x=0;x<9;x++){
        for(i=0;i<x;i++){
        if (V[x] == V[i] && V[x] != 0){
            printf("\nHá mais de um '%d' entre a linha 1-3 e coluna 7-9\n", V[i]);
            erro++;}
        }
    }
      //Verificação de números repetidos na oitava matriz 3x3
    x = 0;
    for (i=3;i<6;i++){
        for(j=6;j<9;j++){
        V[x] = MM[i][j];
        x++;
        }
    }
    for (x=0;x<9;x++){
        for(i=0;i<x;i++){
        if (V[x] == V[i] && V[x] != 0){
            printf("\nHá mais de um '%d' entre a linha 4-6 e coluna 7-9\n", V[i]);
            erro++;}
        }
    }
     //Verificação de números repetidos na nona matriz 3x3
    x = 0;
    for (i=6;i<9;i++){
        for(j=6;j<9;j++){
        V[x] = MM[i][j];
        x++;
        }
    }
    for (x=0;x<9;x++){
        for(i=0;i<x;i++){
        if (V[x] == V[i] && V[x] != 0){
            printf("\nHá mais de um '%d' entre a linha 7-9 e coluna 7-9\n", V[i]);
            erro++;}
        }
    }
    printf("\nNúmeros que precisam ser alterados: %d", erro/3);
    }while(erro!=0);

    //Mostra a matriz finalizada

    printf("\nJogo Finalizado:\n\n\tC1\tC2\tC3\tC4\tC5\tC6\tC7\tC8\tC9\n\n\n");
    for (i=0;i<9;i++){
    printf("L%d", i+1);
        for (j=0;j<9;j++){
        printf("\t%d", MM[i][j]);
        }
    printf("\n\n\n");
    }
    printf("\n\t\t\t\tParabéns, você concluiu o Sudoku!!!\n\nDesenvolvido por: Douglas Geller e Carlos Eduardo Oliveira da Silva\n\nObrigado por jogar!\n\n");
    break;
    system("pause");

    }
    }
}


