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


#define COMANDOTXPWR "iw dev wlp2s0 station get 8e:10:f0:45:9d:a4 | grep signal:"
#define CAMBIOTXPWR "sudo iwconfig wlp2s0 txpower "
#define DOWNINTERFACE "sudo ifconfig wlp2s0 down"
#define UPINTERFACE "sudo ifconfig wlp2s0 up"
#define MINTXPWR 1
#define MAXTXPWR 22

char* txtsplit[100];
int* datosTx[3];

void splitTxPower(char texto[], char delimiter[]);
char * readOutput(char comando[]);
void controlarPotencia();

int main(int argc, char** argv) {

    char* txttx = readOutput("sudo iwconfig wlp2s0 txpower 6");
    printf(txttx);

    char* txtiw = readOutput("sudo iwconfig wlp2s0");
    printf(txtiw);

    int txtmp = 6;

    

    char * txt = readOutput(COMANDOTXPWR);
    printf(txt);
    splitTxPower(txt," signal:[]dBm\t,");
    printf("\n--------------\n");
    int dato1 = atoi(txtsplit[0]);
    int dato2 = atoi(txtsplit[1]);
    int dato3 = atoi(txtsplit[2]);
    
    //datosTx[3];
    //datosTx[0] = dato1;
    //datosTx[1] = dato2;
    //datosTx[2] = dato3;
    
    printf("Tx=%d   ,Rx =%d",txtmp,dato2);
    //printf("%d",datosTx[1]);
    //printf("%d",*datosTx[2]);
    
    printf("\n--------------\n");
    
    bool cierto = true;
    while (cierto) {

	char * txts = readOutput(COMANDOTXPWR);
    	printf(txts);
    	splitTxPower(txts," signal:[]dBm\t,");
    	printf("\n--------------\n");
    	int dato11 = atoi(txtsplit[0]);
    	int dato12 = atoi(txtsplit[1]);
    	int dato13 = atoi(txtsplit[2]);	
	if(dato12<(-51)){
	    if(txtmp>2 && txtmp<20){
	       txtmp = txtmp -3;
	    }else{
	       //txtmp = txtmp-1;
	    }
	}else{
	    if(txtmp<20){
	       txtmp = txtmp +3;
	    }else{
	       //txtmp = txtmp +1;
	    }
	}

	txt = readOutput(COMANDOTXPWR);
	splitTxPower(txts," signal:[]dBm\t,");
    	dato12 = atoi(txtsplit[1]);
	char* comtx = malloc(500) ;
	char ll[20];
	sprintf(ll,"%d",txtmp);	
	
	strcat(comtx,"sudo iwconfig wlp2s0 txpower ");
	strcat(comtx,ll);
	//comtx ="sudo iwconfig wlp2s0 txpower ";
	//printf("%s",comtx);
	//strcat(comtx," 3 333");

	txttx= readOutput(comtx);
    	//printf(txttxd);
	
	txtiw = readOutput("sudo iwconfig wlp2s0 | grep Tx-Power");
    	//printf(txtiw2);        
        printf("\n--------------\n");
        printf("Tx=%d   ,Rx =%d ",txtmp,dato12);
        printf("\n--------------\n");
        usleep(5 * 1000000);
    }


    return (EXIT_SUCCESS);
}

void splitTxPower(char texto[], char delimiter[]){
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
    
   // return str;
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


