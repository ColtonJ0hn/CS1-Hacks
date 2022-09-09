/**
 * a function to replace a character with a different character
 */
void replaceChar(char *s, char oldChar, char newChar);

/**
 * a function to make a copy and return a string with a character replaced
 */
char * replaceCharCopy(const char *s, char oldChar, char newChar);
/**
 * a function to make a copy of a string
 */
char * stringCopy(const char *s);
/**
 * a function to remove a character and make the new string of equal space.
 */
void removeChar(char *s, char c);
/**
 *a function to remove a character and make a copy of the removed character string
 */
char * removeCharCopy(const char *s, char c);

/**
 * a function to seperate a string into multiple strings by an nth number
 */
 
char **lengthSplit(const char *s, int n);