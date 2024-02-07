#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

struct Node {
    long long int value;
    long long int min;
    long long int max;
};

int main() {
    ofstream file2("bst.out");
    ifstream file("bst.in");

    int n;
    file >> n;
    vector<Node> nodes(n);
    nodes[0].min = numeric_limits<long long int>::min();
    nodes[0].max = numeric_limits<long long int>::max();
    file >> nodes[0].value;

    for (int i = 1; i < n; i++) {
        long long int value, position;
        char letter;
        file >> value >> position >> letter;

        nodes[i].value = value;
        if (letter == 'L') {
            nodes[i].min = nodes[position - 1].min;
            nodes[i].max = nodes[position - 1].value;
        }
        else {
            nodes[i].min = nodes[position - 1].value;
            nodes[i].max = nodes[position - 1].max;
        }

        if (nodes[i].value < nodes[i].min || nodes[i].value >= nodes[i].max) {
            file2 << "NO";
            return 0;
        }
    }

    file2 << "YES";
    return 0;
}
