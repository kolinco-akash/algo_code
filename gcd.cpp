#include <iostream>

int gcd(int a, int b) {
    if (b == 0) {
        return a; // GCD is found when 'b' becomes 0
    } else {
        return gcd(b, a % b); // Recursive call with updated values
    }
}

int main() {
    int num1, num2;
    
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    int result = gcd(num1, num2);
    
    std::cout << "GCD of " << num1 << " and " << num2 << " is " << result << std::endl;
    
    return 0;
}
