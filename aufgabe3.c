#define NUMBER_OF_NAMES 10  //Konstante für die Anzahl der Adressanten
#define NUMBER_OF_SIZE 100 //Größe der Adressanten
#include <stdio.h>
#include <string.h>

int main() {
    
    FILE* fp;  // pointer
   
    char einladung[100] = {0}; //ganze Einladung
    char* firstP;        //Teil 1 der Einladung
    char* secondP;       //Teil 2 der Einladung
    char namen[NUMBER_OF_SIZE] = {0};     //String mit Namen der Adressanten
    char* split;         //String für die einzelnen Namen in der Schleife
    int counter = 0;     //Zähler für die Schleife zum Finden der verschiedenen Namen
    char Adressanten[NUMBER_OF_NAMES][NUMBER_OF_SIZE] = {{0}};  //Anzahl Adressanten und wie groß diese sein dürfen
    char filename[20] = {0};   //Variable für Dateinamen der Briefe
    
    fp = fopen("Die Adressanten.txt", "w"); //Erstellen der Adressanten Datei falls nicht vorhanden
    // nicht erfolgreich keine Speicheradresse
    if (NULL == fp) {
        printf("sch... passiert\n");
        return -1; //fehler passiert
    }
    fprintf(fp, "Sara, Anton, Maximilian, Erwin, Erna"); //schreibt die Adressanten in die Datei
    fclose(fp); //Datei Schließen
    
    fp = fopen("Der Text.txt", "w"); //Erstellen der Text.txt Datei falls nicht vorhanden
    // nicht erfolgreich keine Speicheradresse
    if (NULL == fp) {
        printf("sch... passiert\n");
        return -1; //fehler passiert
    }
    fprintf(fp, "Liebe(r) ###, du bist herzlich zu meiner Semesterende Party eingeladen. Dein Wilhelm"); //Schreibt unbefüllte Einladung
    fclose(fp);

    fp = fopen("Der Text.txt", "r"); //Lesen der Text.txt Datei mit "r"
    // nicht erfolgreich keine Speicheradresse
    if (NULL == fp) {
        printf("sch... passiert\n");
        return -1; //fehler passiert
    }
    fgets(einladung, NUMBER_OF_SIZE, fp); //Die Einladung von der Datei wo der Pointer fp hin zeigt in firstP speichern

    firstP = strtok(einladung, "#"); //den String an der Stelle find(###) aufteilen und den erster Teil in firstP
    //puts(firstP);

    secondP = strtok(NULL, "#"); // zweiter Teil schaut mit Null auf den letzten Teil des Strings, wird in secondP initialisiert
    //puts(secondP);
    fclose(fp);  //Datei Schließen
   
    fp = fopen("Die Adressanten.txt", "r"); //Lesen der  Adressanten.txt Datei mit "r"
    // nicht erfolgreich keine Speicheradresse
    if (NULL == fp) {
        printf("sch... passiert\n");
        return -1; //fehler passiert
    }
    fgets(namen, NUMBER_OF_SIZE, fp);
    split = strtok(namen, ","); //ersten Namen in split speichern
    while (split != NULL) {     //Schleife solange durchführen, bis kein Name mehr gefunden wird
        strcpy(Adressanten[counter], split); //Namen in Array eintragen
        //printf("%s\n", split);
        split = strtok(NULL, ", "); //weitere Namen für jeden Durchlauf der Schleife in split speichern
        counter++;
    }

    for (int i = 0; i < counter; i++) { //for-Schleife 0 bis Anzahl Adressanten

        sprintf(filename, "%sBrf.txt", Adressanten[i]); //namen der Datei in filename initialisieren z.B SaraBrf.txt
        fp = fopen(filename, "w");  //Datei erstellen mit dem Namen in filename Bsp. SaraBrf.txt
        // nicht erfolgreich keine Speicheradresse
        if (NULL == fp) {
            printf("sch... passiert\n");
            return -1; //fehler passiert
        }

        char newEinladung[strlen(firstP) + strlen(Adressanten[i]) + strlen(secondP) + 1];
        strcpy(newEinladung, firstP);  //neuen Einladungstext mit Namen zusammenfügen (53-55)
        strcat(newEinladung, Adressanten[i]);
        strcat(newEinladung, secondP);
        fprintf(fp, "%s", newEinladung); //neuen Einladungstext in die entsprechende Datei eintragen

            fclose(fp); //schließt die Date auf welche der Pointer fp zeigt
    }



    return 0;
}
