#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>


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
		bwd[(length-k-1)] = fwd[k];
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
	int input_a; 
	int product_d;
	int greatest_palindrome = 0;
	double time;
	clock_t start = clock();
 	std::cin >> input_a;
	int lower_bound = pow(10, (input_a - 1));
	int upper_bound = pow(10, input_a);
	for (int i = lower_bound; i < upper_bound; i++){
		for (int j = lower_bound; j < i; j++){
			product_d = check_if_palindrome(i*j);   
			if(product_d != 0){
 				std::cout << i << " " << j << ": ";
				std::cout << product_d << std::endl;
				if(greatest_palindrome < product_d){
					greatest_palindrome = product_d;
				}	  
			}		
		}
	}
	std::cout << "The largest palindrome number produced by multiplyling two " << input_a << " digit numbers is " << greatest_palindrome << std::endl;
	clock_t end = clock();
	time = (end - start)/1000;
	std::cout << "time: " << time << std::endl;
}	
