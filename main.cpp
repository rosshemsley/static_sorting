/*******************************************************************************
* Ross Hemsley, 2013. (GNU V3)
*
* Do some simple tests to compare sorts on short fixed lengh arrays. Admittedly
* our tests aren't very scientific: we don't use the same values. However, with
* a large number of tests we should converge to the correct results anyway.
*******************************************************************************/

#include <iostream>
#include <chrono>
#include <random>
#include <cstddef>
#include "static_sorter.hpp"

using    namespace std;
typedef  chrono::steady_clock my_clock;

/******************************************************************************/

int main()
{
    // Parameters to modify. //
    unsigned long                       repeats = 1e8;
    const unsigned short                N       = 5; 
    //

    uniform_real_distribution<double>   unif(0,1);    
    default_random_engine               rng;   
    chrono::nanoseconds                 std_elapsed(0);
    chrono::nanoseconds                 static_is_elapsed(0);
    
    // Try std::sort on some random data.
    auto start = my_clock::now();
    for (size_t i=0; i<repeats; ++i)
    {
        double array[N];
        for (short i=0; i<N; ++i) array[i] = unif(rng);

        std::sort( array, array + N );
    }
    std_elapsed += my_clock::now() - start;

    // Try a simple static insertion sort on some random data.
    start = my_clock::now();
    for (size_t i=0; i<repeats; ++i)
    {
        double array[N];
        for (short i=0; i<N; ++i) array[i] = unif(rng);

        static_insertion_sort( array );
    }    
    static_is_elapsed += my_clock::now() - start;

    // Output timing.
    cout << "STD sort took: "
         << std_elapsed.count()        / 1e7 << endl
         << "Static insertion sort took: "
         << static_is_elapsed.count()  / 1e7 << endl;
}

/******************************************************************************/