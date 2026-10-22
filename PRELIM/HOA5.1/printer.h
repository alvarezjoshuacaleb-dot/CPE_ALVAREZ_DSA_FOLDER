#ifndef PRINTER_H
#define PRINTER_H

#include "Job.h"

class JobNode {
public:
    Job job;
    JobNode* next;

    JobNode(Job newJob);
};

class Printer {
private:
    JobNode* front;
    JobNode* rear;

public:
    Printer();

    void addJob(int id, std::string name, int pages);
    void processJob();
    void displayJobs();
    void processAllJobs();
};

#endif