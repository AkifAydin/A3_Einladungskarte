#include <stdio.h>

int main() {
    FILE* fp;
    int errno = 0;
    int mz = 7;
    char in1[10], in2[10], in3[10];

    // fopen mit "w" erzeugt leere Datei, wenn sie schon existiert
    // wird sie geloescht und neu erzeugt
    fp = fopen("27-5-1.txt", "w");
    if (fp == 0) {
        printf("sch... passiert\n");
        errno = 1;
        return errno; //errno 1
    }
    for (mz = 0;mz < 10;mz++) {
        // fprintf schreibt in eine Datei,
        // sie muss vorher zum Schreiben geoeffnet sein
        // der Formatstring beschreibt wie geschrieben wird
        fprintf(fp, "Meine Zahl ist %d\n\r", mz);
    }
    fclose(fp);
    // fopen mit "r" oeffnet Datei zum Lesen,
    // sie muss schon existieren
    fp = fopen("27-5-1.txt", "r");
    if (fp == 0) {
        printf("sch... passiert\n");
        errno = 1; //errno 2
    }
    else
    {
        printf("Erfolg\n");
        // fscanf sliest aus einer Datei, sie muss vorher
        // zum Lesen geoeffnet sein
        // der Formatstring beschreibt wie geschrieben wird

        fscanf(fp, "%s %s %s %d", in1, in2, in3, &mz);
        fscanf(fp, "%s %s %s %d", in1, in2, in3, &mz);
        fscanf(fp, "%s %s %s %d", in1, in2, in3, &mz);
        fscanf(fp, "%s %s %s %d", in1, in2, in3, &mz);
    }
    fclose(fp);
    //printf("Hello, World!\n");
    return errno;
}