#include <iostream>
#include "Printer.h"

int main()
{
    Printer printer;

    std::cout << "========================================"
              << std::endl;

    std::cout << "       SHARED PRINTER SIMULATION"
              << std::endl;

    std::cout << "========================================"
              << std::endl;

    std::cout << std::endl;

    // Adding Jobs
    std::cout << "ADDING PRINT JOBS..."
              << std::endl;

    std::cout << std::endl;

    printer.addJob(101, "Joshua", 5);
    printer.addJob(102, "Carlos", 10);
    printer.addJob(103, "Maria", 3);
    printer.addJob(104, "Daniel", 8);

    // Display Current Queue
    std::cout << "CURRENT QUEUE:"
              << std::endl;

    printer.displayJobs();

    // Process Two Jobs
    std::cout << "STARTING PRINTER..."
              << std::endl;

    std::cout << std::endl;

    printer.processJob();
    printer.processJob();

    // Display Remaining Jobs
    std::cout << "REMAINING QUEUE:"
              << std::endl;

    printer.displayJobs();

    // Process Remaining Jobs
    printer.processAllJobs();

    return 0;
}