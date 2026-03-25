#include "calculator.h" 
#include <iostream> 
#include <string> 
#include <cmath> 


bool ReadNumber(Number& result) { 
    if (std::cin >> result) { 
        return true; 
    } 
    return false; 
} 

bool RunCalculatorCycle() { 
    // Число калькулятора 
    Number number = 0.0;
    
    // Локальные переменные для памяти
    Number memory = 0.0;
    bool memory_initialized = false;
     
    // Пытаемся прочитать начальное число 
    if (!ReadNumber(number)) { 
        std::cerr << "Error: Numeric operand expected" << std::endl; 
        return false; 
    } 
     
    std::string token;      
    while (std::cin >> token) { 
        if (token == "q") { 
            return true;  // Завершаем программу штатно 
        }  
        else if (token == "+") { 
            Number operand; 
            if (!ReadNumber(operand)) { 
                std::cerr << "Error: Numeric operand expected" << std::endl; 
                return false; 
            } 
            number += operand; 
        }  
        else if (token == "-") { 
            Number operand; 
            if (!ReadNumber(operand)) { 
                std::cerr << "Error: Numeric operand expected" << std::endl; 
                return false; 
            } 
            number -= operand; 
        }  
        else if (token == "*") { 
            Number operand; 
            if (!ReadNumber(operand)) { 
                std::cerr << "Error: Numeric operand expected" << std::endl; 
                return false; 
            } 
            number *= operand; 
        }  
        else if (token == "/") { 
            Number operand; 
            if (!ReadNumber(operand)) { 
                std::cerr << "Error: Numeric operand expected" << std::endl; 
                return false; 
            } 
            number /= operand; 
        }

        else if (token == "**") { 
            Number operand; 
            if (!ReadNumber(operand)) { 
                std::cerr << "Error: Numeric operand expected" << std::endl; 
                return false; 
            } 
            number = std::pow(number, operand); 
        }  
        else if (token == "=") { 
            std::cout << number << std::endl; 
        }  
        else if (token == ":") { 
            Number operand; 
            if (!ReadNumber(operand)) { 
                std::cerr << "Error: Numeric operand expected" << std::endl; 
                return false; 
            } 
            number = operand; 
        }  
        else if (token == "c") { 
            number = 0.0; 
        }  
        else if (token == "s") { 
            memory = number; 
            memory_initialized = true; 
        }

        else if (token == "l") { 
            if (!memory_initialized) { 
                std::cerr << "Error: Memory is empty" << std::endl;
                 
                return false; 
            } 
            number = memory; 
        }  
        else { 
            // Неизвестная команда 
            std::cerr << "Error: Unknown token " << token << std::endl; 
            return false; 
        } 
    } 
 
    return true; 
}  