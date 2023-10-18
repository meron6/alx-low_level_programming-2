#include <stdio.h>
#include <string.h>

char *infinite_add(char *n1, char *n2, char *r, int size_r) {
    int len1 = strlen(n1);
    int len2 = strlen(n2);

    // Find the maximum length among the two input numbers
    int max_len = (len1 > len2) ? len1 : len2;

    // Check if the result can fit in the given buffer
    if (max_len + 1 > size_r) {
        return 0; // Cannot fit the result
    }

    int carry = 0;
    int idx1 = len1 - 1;
    int idx2 = len2 - 1;
    int result_idx = 0;

    // Perform addition digit by digit
    while (idx1 >= 0 || idx2 >= 0 || carry) {
        int digit1 = (idx1 >= 0) ? (n1[idx1] - '0') : 0;
        int digit2 = (idx2 >= 0) ? (n2[idx2] - '0') : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        int digit_sum = sum % 10;

        r[result_idx] = digit_sum + '0';
        result_idx++;
        
        idx1--;
        idx2--;
    }

    // Reverse the result string
    for (int i = 0; i < result_idx / 2; i++) {
        char temp = r[i];
        r[i] = r[result_idx - i - 1];
        r[result_idx - i - 1] = temp;
    }

    r[result_idx] = '\0'; // Null-terminate the result string
    return r;
}

int main() {
    char num1[] = "12345";
    char num2[] = "6789";
    int result_size = 10;
    char result[result_size];

    char *sum = infinite_add(num1, num2, result, result_size);
    if (sum) {
        printf("Sum: %s\n", sum);
    } else {
        printf("Result cannot fit in the buffer.\n");
    }

    return 0;
}
