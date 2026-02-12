//------------------------------------------------------------------------------
// CS 281-0593 Spring 2026
// PA01-Random-Vector.cpp : solution code
// 
// std::vector reference page at cplusplus.com:
// https://cplusplus.com/reference/vector/vector/
// 
// Input validation code is from:
// code from https://www.geeksforgeeks.org/cpp/how-to-validate-user-input-in-cpp/
//
// Notes on std::ignore() used in input validation:
// https://www.geeksforgeeks.org/cpp/cin-ignore-function-in-cpp/
//
// StackOverflow on vector at() vs. square bracket indexing:
// https://stackoverflow.com/questions/9376049/when-should-i-use-vectorat-instead-of-vectoroperator
// 
// StackOverflow on OS portability of "\n" vs. std::endl:
// https://stackoverflow.com/questions/8689344/portable-end-of-line-newline
//------------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <limits>       // for input validation
#include <vector>

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int ITEMCOUNT = 10;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
bool getUserMax(int&);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    std::vector<int> vi;
    vi.reserve(ITEMCOUNT);

    // app banner
    std::cout << "\nThis app generates " << ITEMCOUNT
        << " random numbers\n"
        << "from 1 to the integer you enter, inclusive\n"
        << "Random numbers are displayed in forward and backwards order.\n\n";

    // seed random number generator rand()
    // #TODO what happens if you don't seed with the srand() call?

    // C type cast
    //srand((unsigned int)time(0));

    // C++ type cast is better
    // #TODO why?
    srand(static_cast<unsigned int>(time(0)));

    // exit loop on 0 input
    int maxRand;
    while (getUserMax(maxRand))
    {
        // generate random numbers from 1 to user's max
        // and add them after the last element in vector vi

        for (int i = 0; i < ITEMCOUNT; ++i)
        {
            vi.push_back(rand() % maxRand + 1);
        }

        std::cout << "forward order:\n";

        // display in forward order: normal for loop
        for (int i = 0; i < vi.size(); ++i)
        {
            std::cout << vi.at(i) << ' ';
            // #TODO _safer than_ cout << vi[i] << ' ';

        }
        std::cout << "\n";

        // #TODO display in forward order: range-based for loop
        for (int i : vi)
        {
            std::cout << i << ' ';
        }

        std::cout << "\n\nbackwards order:\n";

        // display in backwards order, remove each element displayed
        while (!vi.empty())
        {
            std::cout << vi.back() << ' ';
            vi.pop_back();
        }
        std::cout << "\n\n";
    }
    std::cout << "Goodbye!\n";

    // #TODO optional, but can be important:
    // returns app termination status to OS
    return 0;
}

//------------------------------------------------------------------------------
// Get largest random integer to generate from user
// - validate user input
// - store entered integer in reference parameter userMax
// - use the absolute value of the integer entered
// - return true if entered integer is nonzero, false otherwise
// #TODO why use a reference parameter?
//------------------------------------------------------------------------------
bool getUserMax(int& userMax)
{
    std::cout << "Enter an integer (0 quits): ";

    // input validation
    // #TODO what is the value of this expression?
    while (!(std::cin >> userMax))
    {
        // prompt for valid input
        std::cout << "\nInvalid input. Please enter an integer: ";

        // clear the input stream buffer
        std::cin.clear();

        // ignore all characters up to newline character
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "You entered: " << userMax << "\n\n";

    // return false when user quits
    if (!userMax) {
        return false;
    }

    // store absolute value of user's integer in reference parameter
    userMax = abs(userMax);

    return true;
}
