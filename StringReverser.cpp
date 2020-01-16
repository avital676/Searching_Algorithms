#include <algorithm>
#include "StringReverser.h"

// reverse a given string
string StringReverser::solve(string problem) {
    int numCharacters = problem.length();
    for (int i = 0; i < numCharacters / 2; i++) {
        swap(problem[i], problem[numCharacters - i - 1]);
    }
    return problem;
}
