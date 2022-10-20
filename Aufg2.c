/**
 * Ein Programm, welches das verzinste Endkapital ausgibt, sofern man das Startkapital, die
 * Zinsrate und den Zeitraum angibt.
 * @author Justin Kahle
 * @date 2022-10-14
*/

#include <stdio.h>

double interestDouble(double, int, double);
float interestFloat(float, int, float);

int main() {
    int timespan = 50;

    // Aufruf der zwei Methoden, die herangezogen werden können.
    printf("Interest using double: %.6f EUR\n", interestDouble(10000.0, timespan, 1.0313));
    // Das angehängte "f" beschreibt explizit ein float-Datentyp; anderenfalls wird es als
    // ein double interpretiert.
    printf("Interest using float: %.6f EUR\n", interestFloat(10000.0f, timespan, 1.0313f));

    // Zusatzaufgabe
    double initialCapital = 0.;
    double interestRate = 0.;
    timespan = 0; // Zeitraum zurücksetzen.

    printf("Geben Sie ihr Startkapital an: ");
    // Der angegebene Wert soll in eine Variable gespeichert werden,
    // dafür wird die Adresse benötigt (s. &).
    scanf("%lf", &initialCapital); // "lf" steht für "long float" (aka. double).
    printf("Geben Sie die Zinsrate an (in %%): ");
    scanf("%lf", &interestRate);
    interestRate = 1 + interestRate / 100; // Wandele % um (bsp. 7 % = 1.07).
    printf("Geben Sie den Zeitraum an: ");
    scanf("%d", &timespan);

    printf("Start: %.2f EUR | Zinsrate: %.2f %% | Zeitraum: %d a\nErgebnis: %.2f EUR",
           initialCapital, (interestRate - 1) * 100, timespan,
           interestDouble(initialCapital, timespan, interestRate));

    return 0;
}

// Methode, um das Endkapital mit einem double zu errechnen.
double interestDouble(double capital, int timespan, double interest) {
    // Schleife, die die Jahre durchgeht.
    for(int i = 0; i < timespan; i++) {
        capital *= interest; // Jedes Jahr soll das Kapital um den Zinssatz erhöht werden.
    }

    return capital;
}

// Methode, um das Endkapital mit einem float zu errechnen.
float interestFloat(float capital, int timespan, float interest) {
    for(int i = 0; i < timespan; i++) {
        capital *= interest;
    }

    return capital;
}
