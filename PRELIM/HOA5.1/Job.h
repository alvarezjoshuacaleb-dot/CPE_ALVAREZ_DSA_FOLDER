#ifndef JOB_H
#define JOB_H

#include <string>

class Job {
public:
    int jobID;
    std::string userName;
    int pages;

    Job(int id, std::string name, int pageCount);
};

#endif