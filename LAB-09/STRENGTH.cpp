//TO IMPLEMENT A GAME IN WHICH THE EACH PARTICIPANT GETS TO SEE HOW MUCH ADVANTAGE THEY HAVE OVER THE BEST OF OTHER PARTICIPANTS IN TERMS OF STRENGTH
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    int t, n;
    scanf("%d", &t);

    if (t < 1 || t > 1000) {
        printf("INVALID INPUT PLEASE ENTER AGAIN\n");
        return 0;
    }

    while (t--) {
        scanf("%d", &n);

        if (n < 2 || n > 200000) {
            printf("INVALID NUMBER OF INPUTS PLEASE ENTER AGAIN\n");
            t++;  // Repeat the test case
            continue;
        }

        int *strength = (int *)malloc(n * sizeof(int));
        bool valid_input;

        // Keep taking input until all values are valid
        do {
            valid_input = true;  // Assume input is valid

            for (int i = 0; i < n; i++) {
                scanf("%d", &strength[i]);
            }

            // Check if all values are valid
            for (int i = 0; i < n; i++) {
                if (strength[i] < 1 || strength[i] > 1000000000) {
                    printf("INVALID STRENGTH FOUND! PLEASE RE-ENTER ALL VALUES.\n");
                    valid_input = false;
                    break;
                }
            }

            if (!valid_input) {
                printf("RE-ENTER ALL %d VALUES:\n", n);
            }

        } while (!valid_input);  // Repeat input until it's valid

        int max_value = *max_element(strength, strength + n);

        for (int i = 0; i < n; i++) {
            int max_excluding_current = 0;

            // Find max excluding current element
            for (int j = 0; j < n; j++) {
                if (j != i && strength[j] > max_excluding_current) {
                    max_excluding_current = strength[j];
                }
            }

            printf("%d ", strength[i] - max_excluding_current);
        }

        printf("\n");
        free(strength);
    }

    return 0;
}
