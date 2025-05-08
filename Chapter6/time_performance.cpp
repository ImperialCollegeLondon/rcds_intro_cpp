// Include libraries
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

// Example of expensive task
void expensive_task1() {

    // Simulate something that takes 3s to run
    std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << "Task 1 completed\n";

}

// Example of expensive task
void expensive_task2() {

    // Simulate something that takes 3s to run
    std::this_thread::sleep_for(std::chrono::seconds(4));
    cout << "Task 2 completed\n";

}

// Main function
int main() {

    // Declare variables
    double time_sequential;
    double time_parallel;
    chrono::high_resolution_clock::time_point start;
    chrono::high_resolution_clock::time_point end;

    // Measure time for sequential execution
    start = chrono::high_resolution_clock::now();
    expensive_task1();
    expensive_task2();
    end = chrono::high_resolution_clock::now();

    // Print sequential time
    time_sequential = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "Sequential execution time: " << time_sequential << " ms\n";

    // Measure time for parallel execution
    start = chrono::high_resolution_clock::now();
    thread worker1(expensive_task1);
    thread worker2(expensive_task2);
    worker1.join();
    worker2.join();
    end = chrono::high_resolution_clock::now();
    // Print sequential time
    time_parallel = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "Parallel execution time: " << time_parallel << " ms\n";

    return 0;

}