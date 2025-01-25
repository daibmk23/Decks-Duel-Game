#include "AVL.h"
#include "iostream"
using namespace std;
#include <cstdio>

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "error for %s <input_file> [<output_file>]", argv[0]);
        return 1;
    }

    bool oddTurn = true;
    int n;
    int boboPoints = 0;
    int holoskoPoints = 0;

    AVL boboCards;
    AVL holoskoCards;

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == nullptr) {
        fprintf(stderr, "error in opening input file.\n");
        return 1;
    }

    fscanf(inputFile, "%d", &n);

    int card;
    for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &card);
        boboCards.insert(card);
    }
    for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &card);
        holoskoCards.insert(card);
    }
    fclose(inputFile);

    //effective complexity = N.log N
    while (n != 0) { //n
        TreeNode* boboNode = boboCards.getRoot();
        TreeNode* holoskoNode = holoskoCards.getRoot();
        int largestBobo = boboNode->value;
        int largestHolosko = holoskoNode->value;

        if (oddTurn) {
            while (boboNode->right != nullptr) { //logN
                boboNode = boboNode->right;
            }
            largestBobo = boboNode->value;

            while (holoskoNode != nullptr) { //logN
                if (holoskoNode->value < largestBobo) {
                    largestHolosko = holoskoNode->value;
                    holoskoNode = holoskoNode->right;
                } else {
                    holoskoNode = holoskoNode->left;
                }
            }

            if (largestBobo > largestHolosko) {
                boboPoints++;
            } else {
                holoskoPoints++;
            }
            boboCards.remove(largestBobo);
            holoskoCards.remove(largestHolosko);
        } else {
            while (holoskoNode->right != nullptr) { //log N
                holoskoNode = holoskoNode->right;
            }
            largestHolosko = holoskoNode->value;

            while (boboNode != nullptr) { //log N
                if (boboNode->value < largestHolosko) {
                    largestBobo = boboNode->value;
                    boboNode = boboNode->right;
                } else {
                    boboNode = boboNode->left;
                }
            }

            if (largestBobo < largestHolosko) {
                holoskoPoints++;
            } else {
                boboPoints++;
            }
            boboCards.remove(largestBobo);
            holoskoCards.remove(largestHolosko);
        }
        oddTurn = !oddTurn;
        n--;
    }

    if (argc == 3){
        FILE* outputFile = fopen(argv[2], "w");
        if (outputFile == nullptr) {
            fprintf(stderr, "Error opening output file.\n");
            return 1;
        }
        fprintf(outputFile, "%d %d\n", boboPoints, holoskoPoints);
        fclose(outputFile);
    }
    else{
        cout<<boboPoints<<" "<<holoskoPoints;
    }


    return 0;
}
