char* reverseWords(char* s) {
 int len = strlen(s);
    char** words = (char**)malloc(len * sizeof(char*));
    int count = 0;

    int i = 0;
    while (i < len) {
        // Skip spaces
        while (i < len && s[i] == ' ') i++;
        if (i >= len) break;

        int start = i;
        while (i < len && s[i] != ' ') i++;
        int wordLen = i - start;

        char* word = (char*)malloc((wordLen + 1) * sizeof(char));
        strncpy(word, s + start, wordLen);
        word[wordLen] = '\0';
        words[count++] = word;
    }

    // Calculate total length for result
    int totalLen = 0;
    for (i = 0; i < count; i++)
        totalLen += strlen(words[i]);
    totalLen += (count - 1); // spaces

    char* result = (char*)malloc((totalLen + 1) * sizeof(char));
    result[0] = '\0';

    for (i = count - 1; i >= 0; i--) {
        strcat(result, words[i]);
        if (i > 0)
            strcat(result, " ");
        free(words[i]);  // free each word
    }
    free(words);

    return result;   
}