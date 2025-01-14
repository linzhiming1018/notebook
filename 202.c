#include <stdbool.h>

bool isHappy(int n) {
    bool h[1024] = {false};
    while (true) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        if (sum == 1) return true;
        else if (h[sum]) return false;
        else {
            h[sum] = true;
            n = sum;
        }
    }
}
