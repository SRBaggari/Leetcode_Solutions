char* getHint(char* secret, char* guess) {
 int bulls = 0, cows = 0;
    int count[10] = {0};

    for (int i = 0; secret[i] != '\0'; i++) {
        int s = secret[i] - '0';
        int g = guess[i] - '0';

        if (s == g) {
            bulls++;
        } else {
            // if guess digit was seen in secret before
            if (count[g] > 0)
                cows++;

            // if secret digit was seen in guess before
            if (count[s] < 0)
                cows++;

            count[s]++;
            count[g]--;
        }
    }

    // Allocate result string
    char* result = (char*)malloc(10 * sizeof(char));
    sprintf(result, "%dA%dB", bulls, cows);

    return result;   
}