#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define C 3

int fill();
int check(int i);
int viz();

int m[C][C], checker[C], x;

int main(){
    fill();
    for (int i=0; i<C; i++) {
        checker[i]=0;
    }
    checker[0]=1;
    check(0);
    for (int i=0; i<C; i++) {
        if (checker[i]>0) {
            x++;
        }
    }
    if (x==C) {
        printf("Граф связный");
    } else {
        printf("Граф несвязный");
    }
    viz();
    return 0;
}

int check(int i) {
    for (int j=0; j<C; j++) {
        if (checker[j]==0) {
            if (i != j) {
                if (m[i][j]>0) {
                    checker[j]++;
                    check(j);
                }
            }
        }
    }
    return 0;
}

int fill() {
    /*
    for (int i=0; i<C; i++) {
        for (int j=0; j<C; j++) {
            m[i][j]=0;
        }
    }
    m[0][1]=1;
    m[1][0]=1;
    m[0][2]=1;
    m[2][0]=1;
    m[0][1]=1;
    m[2][3]=1;
    m[0][1]=1;
    m[3][2]=1;
    m[0][1]=1;
    m[1][0]=1;
    m[4][3]=1;
    m[3][4]=1;
    */

    for (int i=0; i<C; i++) {
        for (int j=0; j<C; j++) {
            scanf("%d", &(m[i][j]));
        }
        printf("\n");
    }
    return 0;
}

int viz() {
    char s[1000];
    strcpy(s, "echo 'graph {");
    for (int i=0; i<C; i++) {
        for (int j=i+1; j<C; j++) {
            if (m[i][j]>0) {
                char p[7];
                sprintf(p, "%d--%d; ", i, j);
                strcat(s, p);
            }
        }
    }
    strcat(s, "}' | neato -Tsvg > output.svg");
    printf("%s", s);
    system(s);
    return 0;
}
