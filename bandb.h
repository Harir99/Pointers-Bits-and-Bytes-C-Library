void getbytes(unsigned char dest[], int bytes, void *src, int reverse);
void getbits(char dest[], int bytes, void *src, int start, int end);
unsigned long long bits2ull(char *bits);
long long bits2ll(char *bits);
void spff(char *sign, char *exponent, char *significand, float *src);
void dpff(char *sign, char *exponent, char *significand, double *src);

/** helper functions ***/
unsigned long long power(unsigned long long power, unsigned long long base);
long long signedPow(long long power, long long base);

