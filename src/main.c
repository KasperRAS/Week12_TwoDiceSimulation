/* ¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤ | Two Dice Simulation | ¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤ ¤
¤           Simulerer 50.000 kast med to d6-terninger              ¤
¤        ud fra et tilfældigt genereret tidsbaseret seed           ¤
¤         og udskriver resultatfordelingen i terminalen.           ¤
¤       Under antagelse af, at fordeling af terningkast følger     ¤
¤      en Bell-kurve, må værdien 7 forventes at optræde oftest,    ¤   
¤              da den ligger i midten af værdierne 2-12.           ¤
¤  ¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤¤ */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KAST_TOTAL  50000
#define SUM_MAX     12

/* ¤¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤¤ | kast_2d6 | ¤¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤¤ ¤
¤          Genererer to tilfældige tal med rand(),          ¤
¤              og returnerer summen af de to.               ¤
¤  ¤¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤¤ */

int kast_2d6(void) {
    int d6_num_1 = 1 + rand() % 6;
    int d6_num_2 = 1 + rand() % 6;
    return d6_num_1 + d6_num_2;
}

/* ¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤ | udskriv_fordeling | ¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤ ¤
¤    Sammenholder alle værdier på plads 2 og over i <sum> med    ¤
¤   <SUM_MAX> og sætter dem overfor værdien på den tilsvarende   ¤
¤   plads i <taellinger>, hvorefter der udskrives til terminal.  ¤
¤  ¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤¤ */

void udskriv_fordeling(const int taellinger[]) {
    for (int sum = 2; sum <= SUM_MAX; ++sum) {
        printf("%2d: %6d\n", sum, taellinger[sum]);
    }
}

/* ¤¤¤¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤¤ | main | ¤¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤¤¤¤ ¤
¤   Seeder rand(), kører kast_2d6() og lægger returværdien  ¤
¤     i <sum>, så længe <i> er mindre end <KAST_TOTAL>.     ¤
¤        Baseret på <sum> øges tælleren, <taellinger>,      ¤
¤         for den returnerede sum. Når for-løkken er        ¤
¤        færdig (i = ANTAL_KAST) udskrives resulatet.       ¤
¤ ¤¤¤¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤¤ ¤¤¤¤¤¤¤¤¤¤¤¤ */

int main(void) {
    int taellinger[SUM_MAX + 1] = {0};
    
    srand((unsigned)time(NULL));

    for (int i = 0; i < KAST_TOTAL; ++i) {
        int sum = kast_2d6();
        ++taellinger[sum];
    }

    udskriv_fordeling(taellinger);
    
    return 0;
}
