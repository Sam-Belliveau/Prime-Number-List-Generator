#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

typedef unsigned long long NUM; // 64 Bit Number Support

const NUM limit = 34359738368; // Generate Up to
const NUM sLimit = sqrt(limit); // Generate Up to
std::vector<bool> list(limit); // Vectors Are Formated In Optimal Way

int main()
{
    std::ofstream primes; // Output
    primes.open("Primes Up To 34,359,738,368.txt"); // Just A Name

    // Support For Making Vector In Stack
    // Helpful when it takes a lot of time
    std::cout << "Finished Allocating List Of " << limit << " Bools."<< std::endl;

    NUM i = 2; // Number Used For Eliminating Multiples
    // You can see progress in an app like cheat engine
    // Faster that std::cout or printf
    std::cout << "Follow Progress At " << &i << std::endl;
    for(i = 2; i < sLimit; i++)
    {
        if(list[i] == false) // Prime Number
        {
            // Output Prime
            primes << i << std::endl;

            // Eliminate Prime From List
            for(NUM j = i*i; j < limit; j += i)
            {
                list[j] = true; // Mark that as not prime
            }
        }
    }
    for(i = sLimit; i < limit; i++)
    {
        if(list[i] == false) // Prime Number
        {
            // Output Prime
            primes << i << std::endl;
        }
    }

    primes.close();
    return 0;
}
