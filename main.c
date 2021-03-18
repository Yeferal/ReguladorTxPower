/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: alvarados
 *
 * Created on 17 de marzo de 2021, 01:30 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>


#define COMANDOTXPWR "iw dev wlp2s0 station dump | grep signal:"
#define CAMBIOTXPWR "sudo iwconfig wlp2s0 txpower "
#define DOWNINTERFACE "sudo ifconfig wlp2s0 down"
#define UPINTERFACE "sudo ifconfig wlp2s0 up"
#define MINTXPWR 1
#define MAXTXPWR 22

char* txtsplit[100];
char* datosTx[3];

char* splitTxPower(char texto[], char delimiter[]);
char * readOutput(char comando[]);
void controlarPotencia();

int main(int argc, char** argv) {
    
    char * txt = readOutput(COMANDOTXPWR);
    printf(txt);
    splitTxPower(txt," signal:[]dBm\t,");
    printf("\n--------------\n");
    int dato1 = atoi(txtsplit[0]);
    int dato2 = atoi(txtsplit[1]);
    int dato3 = atoi(txtsplit[2]);
    
    //datosTx[3];
    datosTx[0] = dato1;
    datosTx[1] = dato2;
    datosTx[2] = dato3;
    
    printf("%i",datosTx[0]);
    //printf("%i",datosTx[1]);
    //printf("%i",datosTx[2]);
    
    printf("\n--------------\n");
    return (EXIT_SUCCESS);
}

char* splitTxPower(char texto[], char delimiter[]){
    int tamanio = strlen(texto);
    int tamaniod = strlen(delimiter);
    char str[tamanio];
    char strg[tamanio];
    char delim[tamaniod];
    
    
    for(int i = 0; i<tamanio; i++){
        str[i] = texto[i];
        strg[i] = texto[i];
    }
    for(int i = 0; i<tamaniod; i++){
        delim[i] = delimiter[i];
    }
    int init_size = strlen(str);

    char *ptr = strtok(str, delim);
    int index = 0;
    //char *nuevoStr [init_size];

    while(ptr != NULL){
        index++;
        //printf("'%s'\n", ptr);
        ptr = strtok(NULL, delim);
    }
    ptr = strtok(strg, delim);
    char* str2[index];
    txtsplit[index];
    for (int i = 0; i < index; i++){
        //printf("'%s'\n", ptr);
        str2[i] = ptr;
        txtsplit[i] = str2[i];
//        printf(str2[i]);
//        printf("\n");
        ptr = strtok(NULL, delim);
    }
    
    return *str;
}

char * readOutput(char comando[]){
    char * texto = malloc(2000);
    FILE *fp;
    char path[1035];
    fp = popen(comando, "r");
    if(fp==NULL){
        printf("Fallo al correr Comando");
        exit(1);
    }
    while(fgets(path, sizeof(path),fp) != NULL){
        strcat(texto,path);
    }
    pclose(fp);
    return texto;
}

void controlarPotencia(char interfaz[]){
    bool cierto = true;
    while (cierto) {
        
        
        
        usleep(3 * 1000000);
    }

}


