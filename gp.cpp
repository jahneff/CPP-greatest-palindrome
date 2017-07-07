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

int check_if_palindrome(int original){
	int modified = original;		//preserve s, which will be modified
	int length = get_length(original);		
	int fwd[length];
	int bwd[length];
	for(int k = 0; k < length; k++){ 
		fwd[k] = modified % 10;
		bwd[(length-k-1)] = modified % 10;
		modified /= 10;
	}
	for(int l = 0; l < length; l++){ 
		if (fwd[l] != bwd[l]){
			return 0;		
		}
	}
	return original;
} 

int main(int argc, char* argv[]){
	int input_a, input_b, length_of_a, product_d;
	std::cin >> input_a >> input_b;
	length_of_a = get_length(input_a); 
	for (int i = pow(10, (length_of_a - 1)); i <= pow(10, length_of_a)-1; i++){
		for (int j = 0; j <= i; j++){
			product_d = check_if_palindrome(i*j);   
			if(product_d != 0){
 				std::cout << i << " " << j << ": ";
				std::cout << product_d << std::endl; 
			}		
		}
	}
}
