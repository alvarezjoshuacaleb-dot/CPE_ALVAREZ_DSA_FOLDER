//ALVAREZ,JOSHUA CALEB P.
#include <iostream>
#include <string>
#include "Printer.h"

Job::Job(int id, std::string name, int pageCount)
{
    jobID = id;
    userName = name;
    pages = pageCount;
}

JobNode::JobNode(Job newJob)
    : job(newJob), next(nullptr)
{
}

Printer::Printer()
{
    front = nullptr;
    rear = nullptr;
}

void Printer::addJob(int id, std::string name, int pages)
{
    Job newJob(id, name, pages);

    JobNode* newNode = new JobNode(newJob);

    if (rear == nullptr)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    std::cout << "Job " << id << " added successfully." << std::endl;
    std::cout << "User: " << name << " | Pages: " << pages << std::endl;
    std::cout << std::endl;
}

void Printer::processJob()
{
    if (front == nullptr)
    {
        std::cout << "No pending jobs in the printer." << std::endl;
        return;
    }

    JobNode* temp = front;

    std::cout << "Processing Job "
              << temp->job.jobID
              << "..." << std::endl;

    std::cout << "User: "
              << temp->job.userName
              << std::endl;

    std::cout << "Pages: "
              << temp->job.pages
              << std::endl;

    std::cout << "Job "
              << temp->job.jobID
              << " completed."
              << std::endl;

    std::cout << std::endl;
    front = front->next;
    if (front == nullptr)
    {
        rear = nullptr;
    }

    delete temp;
}

void Printer::displayJobs()
{
    if (front == nullptr)
    {
        std::cout << "No pending print jobs." << std::endl;
        return;
    }
    JobNode* current = front;
    std::cout << "----------------------------------------"
              << std::endl;
    std::cout << "          PENDING PRINT JOBS"
              << std::endl;
    std::cout << "----------------------------------------"
              << std::endl;
    while (current != nullptr)
    {
        std::cout << "Job ID: "
                  << current->job.jobID
                  << std::endl;

        std::cout << "User: "
                  << current->job.userName
                  << std::endl;
        std::cout << "Pages: "
                  << current->job.pages
                  << std::endl;
        std::cout << "----------------------------------------"
                  << std::endl;

        current = current->next;
    }

    std::cout << std::endl;
}

void Printer::processAllJobs()
{
    std::cout << "========================================"
              << std::endl;
    std::cout << "       PROCESSING ALL PRINT JOBS"
              << std::endl;

    std::cout << "========================================"
              << std::endl;
    while (front != nullptr)
    {
        processJob();
    }
    std::cout << "All print jobs have been completed."
              << std::endl;
}