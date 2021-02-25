// CPP program to rearrange the given source code 
#include <bits/stdc++.h> 
using namespace std; 

// Function to rearrange the code 
void rearrange(string str) 
{ 
	string replaced; 

	int Open_paren = 0, Open_Braces = 0; 
	int Lessrthan = 0, i = 0, j = 0; 

	do { 

		// Various Conditions For The Code 
		if (str[i] == '#' || str[i] == '<' || str[i] == '>'
			|| str[i] == ';' || str[i] == '}' || str[i] == '{'
			|| str[i] == '(' || str[i] == ')') { 

			// Check for opening braces 
			if (str[i] == '{') 
				Open_Braces++; 

			// Check for closing braces 
			if (str[i] == '}') 
				Open_Braces--; 

			// For less than symbol 
			if (str[i] == '<' && Open_paren == 0) 
				Lessrthan++; 

			// For greater than symbol 
			if (str[i] == '>' && Open_paren == 0) 
				Lessrthan--; 

			// For open parenthesis 
			if (str[i] == '(') { 
				Lessrthan = 0; 
				Open_paren++; 
			} 

			// For closing parenthesis 
			if (str[i] == ')') 
				Open_paren--; 

			if (Open_paren > 0) { 
				replaced += str[i]; 
			} 
			else { 

				// Replace the plain code 
				// for closing parenthesis 
				if (str[i] == ')') 
					replaced += str[i]; 

				// Replace the code for open and close braces 
				else if (str[i] == '{' || str[i] == '}') { 
					replaced += '\n'; 
					replaced += str[i]; 
					replaced += '\n'; 
				} 
				else if (Lessrthan > 0) 
					replaced += str[i]; 

				// Replace the code for # symbol 
				else if (str[i] == '#') { 
					replaced += '\n'; 
					replaced += str[i]; 
				} 
				else { 
					replaced += str[i]; 
					replaced += '\n'; 
				} 
			} 
		} 

		// If all conditions do not 
		// work then print the code as it is 
		else { 
			replaced += str[i]; 
		} 

		i++; 

	} while (i < str.length()); 
	replaced += '\0'; 

	// Print formatted code 
	for (i = 0; i < replaced.length(); i++) 
		cout << replaced[i]; 
	printf("\n"); 
} 

// Driver Code 
int main() 
{ 

	string str = "#include<stdio.h>int main()"
				"{ int a, b, c; c=a+b; printf(\"%d\", c);"
				" return 0; }"; 

	// Function call 
	rearrange(str); 

	return 0; 
} 
