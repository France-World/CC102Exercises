#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int countPrimesFromFile() {
    ifstream file("NUMS.TXT");
    if (!file) {
        cout << "Error: Cannot open NUMS.TXT" << endl;
        return -1;
    }

    int num, count = 0;
    while (file >> num) {
        if (isPrime(num))
            count++;
    }

    file.close();
    return count;
}

int main() {
    int result = countPrimesFromFile();
    if (result != -1)
        cout << "Prime count: " << result << endl;
    return 0;
}
