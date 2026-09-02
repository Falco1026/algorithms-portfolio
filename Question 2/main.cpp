#include <iostream>
using namespace std;

// recursive binary search to find the missing guy - O(log n)
int findMissingPatient(int * triage, int * specialist, int start, int end) {
    // base case: narrowed down to one dude
    if (start == end) {
        return triage[start];
    }

    int mid = (start + end) / 2;

    // if they match, the missing guy is further to the right
    if (triage[mid] == specialist[mid]) {
        return findMissingPatient(triage, specialist, mid + 1, end);
    }
    // mismatch! the missing guy is here or to the left
    else {
        return findMissingPatient(triage, specialist, start, mid);
    }
}

int main() {
    // exam test case 2
    int triage[] = {101, 102, 103, 104, 105, 106};
    int general[] = {101, 102, 103, 104, 105, 106};
    int specialist[] = {101, 102, 103, 105, 106};

    int nTriage = 6;
    int nGeneral = 6;
    int nSpecialist = 5;

    // find who got lost just by checking the first and last arrays
    int missingGuy = findMissingPatient(triage, specialist, 0, nTriage - 1);

    cout << "Paciente: " << missingGuy << endl;

    // logic to figure out exactly when he bailed
    if (nTriage > nGeneral) {
        // if general has fewer people than triage, he left early
        cout << "Abandonó después de Triaje" << endl;
    } else {
        // if general has the same as triage, he survived general but skipped specialist
        cout << "Abandonó después de Consulta General" << endl;
    }

    return 0;
}