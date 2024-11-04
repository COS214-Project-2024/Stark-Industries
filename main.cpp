#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <ctime>
#include <algorithm>

#include "CityFacade.h"
using namespace std;

// ANSI color codes for styling the output
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define MAGENTA "\033[35m"
#define BLUE "\033[34m"
#define ORANGE "\033[38;5;208m" 
#define PURPLE "\033[38;5;93m"

int main(){
    CityFacade facade;
    facade.bigTestingMain();
    return 0;
}
