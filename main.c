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
#include <string.h>

#define COMANDOTXPWR "iw dev wlp2s0 station dump | grep signal:"
//#define PRD "        signal:         -61 [-61, -64] dBm"

char * txtsplit[];

char* splitTxPower(char texto[], char delimiter[]);
char * readOutput(char comando[]);

int main(int argc, char** argv) {
    
    //printf(COMANDOTXPWR);
    printf("\n");
    //char str[] = system(COMANDOTXPWR);
    
    //printf(str);
    char * txt = readOutput(COMANDOTXPWR);
    printf(txt);
    splitTxPower(txt," signal:[]dBm\t,");
    printf("\n--------------\n");
    printf(txtsplit[0]);
    printf(txtsplit[1]);
    printf(txtsplit[2]);
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
    
    return str;
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




