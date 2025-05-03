//TO IMPLEMENT A GAME DEVELOPED BY NENE BY FOLLOWING GIVEN RULES IN QUESTION A
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    if (t < 1 || t > 250) {
        printf("INVALID VALUE OF t TRY AGAIN\n");
        return 0;
    }

    vector<vector<int>> results;

    while (t--) {
        int k, q;
        scanf("%d %d", &k, &q);
        
        if (k < 1 || k > 100 || q < 1 || q > 100) {
            printf("INVALID VALUES ENTER AGAIN\n");
            t++;  
            continue;
        }

        vector<int> arr1(k), arr2(q);

        for (int i = 0; i < k; i++) {
            int j;
            scanf("%d", &j);
            if (j < 1 || j > 100) {
                printf("INVALID VALUE OF SERIES ENTER AGAIN\n");
                i--;
                continue;
            }
            arr1[i] = j;
        }

        sort(arr1.begin(), arr1.end());

        for (int i = 0; i < q; i++) {
            int j;
            scanf("%d", &j);
            if (j < 1 || j > 100) {
                printf("INVALID VALUE OF NUMBERS ENTER AGAIN\n");
                i--;
                continue;
            }
            arr2[i] = j;
        }

        vector<int> test_case_result;

        for (int i = 0; i < q; i++) {
            int n = arr2[i];
            vector<int> a(n);
            for (int j = 0; j < n; j++) {
                a[j] = j + 1;
            }

            while ((int)a.size() >= arr1[0]) {
                for (int m = 0; m < k; m++) {
                    if ((int)a.size() >= arr1[m] && arr1[m] > 0) {
                        a.erase(a.begin() + (arr1[m] - 1));
                        break;
                    }
                }
            }

            test_case_result.push_back((int)a.size());
        }

        results.push_back(test_case_result);
    }

    for (int i = 0; i < results.size(); i++) {
        for (int j = 0; j < results[i].size(); j++) {
            printf("%d ", results[i][j]);
        }
        printf("\n");
    }

    return 0;
}
