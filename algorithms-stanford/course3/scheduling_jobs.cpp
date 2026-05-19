#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

struct Job
{
    long long weight;
    long long length;
};

bool compareJobs_diff(const Job &a, const Job &b)
{
    long long diffA = a.weight - a.length;
    long long diffB = b.weight - b.length;

    if (diffA == diffB)
        return a.weight > b.weight;
    return diffA > diffB;
}

bool compareJobs_ratio(const Job &a, const Job &b)
{
    return a.weight * b.length > b.weight * a.length;
}

int main()
{
    std::ifstream file("jobs.txt");
    long long n;
    file >> n; // first line contains n

    std::vector<Job> jobs(n);

    for (long long i = 0; i < n; i++)
        file >> jobs[i].weight >> jobs[i].length;

    sort(jobs.begin(), jobs.end(), compareJobs_ratio);

    long long completionTime = 0;
    long long totalWeightedCompetionTime = 0;

    for (const Job &job : jobs)
    {
        completionTime += job.length;
        totalWeightedCompetionTime += job.weight * completionTime;
    }

    std::cout << totalWeightedCompetionTime << std::endl;

    return 0;
}
