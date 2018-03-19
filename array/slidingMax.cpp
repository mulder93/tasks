#include "slidingMax.hpp"
#include <deque>
#include <iostream>

namespace tasks::array
{
    void printSlidingMax(const std::vector<int>& data, const size_t windowSize)
    {
        if (windowSize > data.size())
            return;

        // Save indexes of elements which are greater than all the left elements
        std::deque<int> window;

        for (auto i = 0; i < data.size(); ++i) {
            // Remove first element
            if (!window.empty() && window.front() <= i - windowSize) {
                window.pop_front();
            }

            // Add element to the right
            while (!window.empty() && data[window.back()] <= data[i]) {
                window.pop_back();
            }
            window.push_back(i);

            // Print window max element
            if (i >= windowSize - 1) {
                std::cout << data[window.front()] << " ";
            }
        }
        std::cout << std::endl;
    }

    void test()
    {
        printSlidingMax({3, 4, 6, 3, 4}, 2); // Should be "4 6 6 4"
        printSlidingMax({3, 4, 5, 8, 1, 4, 10}, 4); // Should be "8 8 8 10"
    }
}