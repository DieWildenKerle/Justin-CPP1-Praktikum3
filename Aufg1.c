/**
 * Ein Programm, das die ersten 128 ASCII-Zeichen mit ihren jeweiligen Oktal-, Dezimal-
 * und Hexadezimalwert tabellarisch anzeigt. Dabei sind Control Codes mit einem "..." versehen.
 * @author Justin Kahle
 * @date 2022-10-14
*/

#include <stdio.h>

int main() {
    int width = 0; // Breite der Tabelle insgesamt.

    for(int i = 0; i < 4; i++) { // Generiere vier Spalten mit je vier "Unterspalten".
        width += printf("%3s %3s %3s %3s", "Okt", "Dez", "Hex", "Zch");

        if(i < 3) width += printf(" | "); // Trenne Spalten voneinander.
    }

    printf("\n");

    // Drucke der Tabellenbreite entsprechend viele "-"-Zeichen.
    for(int i = 0; i < width; i++) printf("-");

    printf("\n");

    // Drucke 32 Zeilen (128 durch 4 Spalten = 32 Zeilen).
    for(int i = 0; i < 32; i++) {
        // Fülle die vier Spalten. Der Zellenwert unterscheidet sich vom Vorigen um +32 (um eine top-down Liste zu drucken).
        // Also: 1. Spalte = 0; 2. = 32; 3. = 64 und 4. = 96 (5. Spalte wäre 128, ist aber aus der Bedingung).
        for(int j = 0; j < 128; j += 32) {
            // Der Wert pro Zelle: Reihe + Spalte, wobei Spalten jeweils ihren Wert +32 zum Vorigen haben.
            int charNum = i + j;

            printf("%03o %03d %03x", charNum, charNum, charNum); // Drucke den Wert der ersten drei Unterspalten pro Zelle

            // Sofern das Zeichen den Zahlenwert 0-31 oder 127 hat (→ Control Code), drucke einfach "...";
            if(charNum < 32 || charNum >= 127) {
                printf(" %-3s", "...");
            }
            // Sofern das Zeichen gemäß der ASCII-Zeichenkodierung ein druckbares Zeichen ist, drucke dies.
            else {
                printf(" %-3c", charNum);
            }

            if(j < 96) printf(" | "); // Trenne Zellen voneinander.
        }

        printf("\n"); // Zeilenumbruch; beginne neue Zeile.
    }

    return 0;
}
