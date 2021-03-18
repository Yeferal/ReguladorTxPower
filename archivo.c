/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   archivo.c
 * Author: alvarados
 *
 * Created on 17 de marzo de 2021, 09:53 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    FILE *fichero;
    fichero = fopen("my_wlan.conf", "");
    fclose(fichero);
    return (EXIT_SUCCESS);
}

