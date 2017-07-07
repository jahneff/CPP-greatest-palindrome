#include <iostream>
#include <typeinfo>
#include <cmath>

int get_length(int r) {
	int length = 0;
	while(r) {
		length += 1; 
		r /= 10;
	};
	return length;
}

bool check_if_palindrome(int s){
	std::cout << s << std::endl;
	int t = get_length(s);
	int fwd[t];
	int bwd[t];
	for(int k = 0; k < t; k++){ 
		fwd[k] = s % 10;
		bwd[(t-k-1)] = s % 10;
		s /= 10;
	};
	for(int l = 0; l < t; l++){ 
		if (fwd[l] != bwd[l]){
			return false;		
		}
	}
	std::cout << "PALINDROME: " << std::endl; 
	for(int m = 0; m < t; m++){
		std::cout << fwd[m]; 
	} 
	std::cout << std::endl;
	return true;
} 

int main(int argc, char* argv[]){
	int a, b, c;
	std::cin >> a >> b;
	c = get_length(a); 
	for (int i = pow(10, c-1); i <= pow(10, c)-1; i++){
		for (int j = 0; j <= i; j++){
 			std::cout << i << " " << j << ": " << i*j << std::endl;
			check_if_palindrome(i*j);	 
		}
	}
}
