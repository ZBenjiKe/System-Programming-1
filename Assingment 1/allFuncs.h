#include <stdio.h>
#include <math.h>

// isArmstrong with loops
int isArmstorng(int n){
	int numLength = 0;
	int num = n;
	int result = n;
	while(n>0){
		n = n/10;
		numLength++;
	}
	int digits[numLength];
	for(int x = 0; x < numLength; x++){
		digits[x] = num%10;
		num /= 10;
	}
	int armstrongValue = 0;
	for (int i = 0; i<numLength; i++){
		int x = pow(digits[i], numLength);
		armstrongValue += x;
	}
	int ans = (armstrongValue == result)? 1 : 0;
	return ans;
}

int isPalindrome(int n){
	int numLength = 0;
	int num = n;
	while(n>0){
		n = n/10;
		numLength++;
	}
	int digits[numLength];
	for(int x = 0; x < numLength; x++){
		digits[x] = num%10;
		num /= 10;
	}
	int i = 0;
	int j = numLength-1;
	while (j>i){
		if ((digits[i]==digits[j])==0) {
			return 0;
		}
		i++, j--;
	}
	return 1;
}

int isPrime(int n) {
	if (n <= 0) {
		return 0;
	}
	int limit = (int)sqrt(n);
	for(int i = 2; i <= limit; i++){
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
}

int factorial(int n){
    if (n == 0){
        return 0;
    }
	if (n == 1){
		return 1;
	} else {
		return (n*factorial(n-1));
	}
}

int isStrong(int n) {
	int numLength = 0;
	int num = n;
	int result = n;
	while(n>0){
		n = n/10;
		numLength++;
	}
	int digits[numLength];
	for(int x = 0; x < numLength; x++){
		digits[x] = num%10;
		num /= 10;
	}
	int strongValue = 0;
	for (int i = 0; i < numLength; i++){
		strongValue += factorial(digits[i]);
	}
	int ans = (strongValue == result)? 1 : 0;
	return ans;
}

void main() {
	printf("%d\n", isArmstorng(407));
	printf("%d\n", isPalindrome(1234321));
	printf("%d\n", isPrime(113));
	printf("%d\n", factorial(5));
	printf("%d\n", isStrong(145));
	
}