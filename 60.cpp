#include <iostream>
#include <math.h>
using namespace std;

int g_max = 6;

void Probability(int number, int rest_num, int sum, int *proba);

void PrintProbability(int number) {
    if (number < 1)
        return;
    int *proba = new int[number * g_max - number + 1]();
    for (int i = 1; i <= g_max; ++i)
        Probability(number, number - 1, i, proba);
    int numSum = pow((double)g_max, number);
    for (int i = 0; i < number * g_max - number + 1; ++i) {
        cout << "i: " << i + number << " probability: " << double(proba[i]) / numSum << endl;
    }
}

void Probability(int number, int rest_num, int sum, int *proba) {
    if (rest_num == 0) {
        proba[sum - number] ++;
        return;
    }
    for (int i = 1; i <= g_max; ++i) {
        Probability(number, rest_num - 1, sum + i, proba);
    }
}

int main() {
    PrintProbability(7);
    return 0;
}
