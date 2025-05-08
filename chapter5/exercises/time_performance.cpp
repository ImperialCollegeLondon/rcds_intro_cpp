#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

// Example of an expensive task
void expensiveTask1() {

    // Simulate an expensive task with a sleep
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Task 1 completed\n";

}

void expensiveTask2() {

    // Simulate an expensive task with a sleep
    std::this_thread::sleep_for(std::chrono::seconds(4));
    std::cout << "Task 2 completed\n";

}

// Main function
int main() {

    // Declare variables
    double time_sequential;
    double time_parallel;
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;

    // Measure time for sequential execution
    start = std::chrono::high_resolution_clock::now();
    expensiveTask1();
    expensiveTask2();
    end = std::chrono::high_resolution_clock::now();

    // Print sequential time
    time_sequential = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    cout << "Sequential execution time: " << time_sequential << " ms\n";

    // Measure time for parallel execution
    start = std::chrono::high_resolution_clock::now();
    std::thread worker1(expensiveTask1);
    std::thread worker2(expensiveTask2);
    worker1.join();
    worker2.join();
    end = std::chrono::high_resolution_clock::now();

    // Compute time parallel
    time_parallel = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    cout << "Parallel execution time: " << time_parallel << " ms\n";
    
    return 0;

}