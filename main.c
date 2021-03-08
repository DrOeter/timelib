#include <stdio.h>

int leap_year(int jahr){
    if(jahr <= 0) return -1;

    if(jahr % 4 == 0){
        if(jahr % 100 == 0){
            if(jahr % 400 == 0) return 1;
            else return 0;
        }
        else return 1;
    }
    else return 0;

    return -1;
}

int day_of_year(int tag, int monat, int jahr){
    int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int acum = 0;

    if(leap_year(jahr)) arr[1] = 29;
       
    for(int i=0;i < monat - 1;i++){
        acum += arr[i];
    }
    acum += tag;
    printf("Tage:  %d\n",acum);

    return acum;
}

void input_date(int tag, int monat, int jahr){
    int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(leap_year(jahr)) arr[1] = 29;

    while(1){
        if(tag <= arr[monat - 1] && tag >= 1 && monat >= 1 && monat <= 12 && jahr >= 1){
            printf("Datum Korrekt");
            break;
        }

        printf("Gebe Tag ein: ");
        scanf("%d",&tag);
        printf("Gebe Monat ein: ");
        scanf("%d",&monat);
        printf("Gebe Jahr ein: ");
        scanf("%d",&jahr);
    }    
}

int get_days_month(int monat, int jahr){
    int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(leap_year(jahr)) arr[1] = 29;
    return arr[monat - 1];
}

int exists_date(int tag, int monat, int jahr){
    int i = 0;

    if( tag >= 1 && tag <= 31 
        && monat >= 1 && monat <= 12 
        && jahr >= 1582 && jahr <= 2400
    ) i = 1;

    return i;
}

int main(){
    int tag, monat, jahr;

    printf("Gebe Tag ein: ");
    scanf("%d",&tag);
    printf("Gebe Monat ein: ");
    scanf("%d",&monat);
    printf("Gebe Jahr ein: ");
    scanf("%d",&jahr);

    day_of_year(tag, monat, jahr);

    input_date(tag, monat, jahr);

    printf("Schaltjahr bei 1: %d \n", leap_year(jahr));

    get_days_month(monat, jahr);
    
    printf("Datum Existiert bei 1: %d\n", exists_date(tag, monat, jahr));
}
