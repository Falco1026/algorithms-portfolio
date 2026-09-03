#include <iostream>
using namespace std;

int main() {
    int rows, cols, maxH, maxW, threshold;

    // reading the inputs
    cout << "Ingrese los valores de F, C, H, W y U en ese respectivo orden: ";
    cin >> rows >> cols >> maxH >> maxW >> threshold;

    int traffic[rows][cols];

    cout << "Ingrese los valores de la matriz: ";
    // proper matrix reading: r for rows, c for cols
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cin >> traffic[r][c];
        }
    }

    // printing the initial state
    cout << "\nMatriz evaluada:\n";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << traffic[r][c] << "\t"; // using tab for clean spacing
        }
        cout << endl;
    }

    cout << "\nAltura máxima del bloque: " << maxH << endl;
    cout << "Ancho máximo del bloque: " << maxW << endl;
    cout << "Umbral sospechoso: " << threshold << "\n\n";

    int blockCounter = 0;

    // Brute Force: Check every possible top-left corner
    for (int startR = 0; startR < rows; startR++) {
        for (int startC = 0; startC < cols; startC++) {

            // From this corner, try every valid height (1 to maxH) and width (1 to maxW)
            for (int h = 1; h <= maxH; h++) {
                for (int w = 1; w <= maxW; w++) {

                    int endR = startR + h - 1;
                    int endC = startC + w - 1;

                    // only proceed if the block actually fits inside the matrix limits
                    if (endR < rows && endC < cols) {
                        int currentSum = 0;

                        // sum all elements inside this specific block
                        for (int r = startR; r <= endR; r++) {
                            for (int c = startC; c <= endC; c++) {
                                currentSum += traffic[r][c];
                            }
                        }

                        // if we caught them leaking data, print it!
                        if (currentSum > threshold) {
                            blockCounter++;
                            cout << "Bloque sospechoso " << blockCounter << ":\n";
                            cout << "Fila inicial: " << startR << endl;
                            cout << "Columna inicial: " << startC << endl;
                            cout << "Fila final: " << endR << endl;
                            cout << "Columna final: " << endC << endl;
                            cout << "Suma: " << currentSum << "\n\n";
                        }
                    }
                }
            }
        }
    }

    // if no blocks were found, print the required exam message
    if (blockCounter == 0) {
        cout << "No se encontraron patrones sospechosos\n";
    }

    return 0;
}