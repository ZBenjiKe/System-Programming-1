#ifndef _ADVANACEDCLASSIFICATIONRECURSION_H_
#define _ADVANACEDCLASSIFICATIONRECURSION_H_

	// Check the number of digits in a given integer
	int countDigits(int n);

	// Recursive function to check if a number is an Armstrong Number
	int isArmstorngRecursive(int n, int numDigits);

	// Function to check if a number is an Armstrong Number
	// This function calls isArmstorngRecursive function
	int isArmstorng(int n);

	// Recursive function to check if a number a palindrome
	// The number is represented as an array of digits
	int isPalindromeRecursive(int arr[], int start, int end);

	// Function to check if a number is a palindrome
	// This function creates an array representing the digits of the given number
	// and then calls isPalindromeRecursive function
	int isPalindrome(int n);
	
	#endif