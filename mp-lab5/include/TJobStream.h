#include "TQueue.h"
#include <cstdlib>

class TJobStream
{
private:
	double jobIntense;// интенсивность потока задач
	size_t lastJobId;
public:
	TJobStream(double JobIntens);
	double GetJobIntens(void) const noexcept;
	size_t GetNewJob(void);
	size_t GetLastJobId(void) const noexcept;
};
TJobStream::TJobStream(double jobIntense)
{
	if (jobIntense >= 0.0 && jobIntense <= 1.0)
	{
		this->jobIntense = jobIntense;
		lastJobId = 1;
	}
	else
		throw "Err";
}

double TJobStream::GetJobIntens(void) const noexcept
{
	return jobIntense;
}

size_t TJobStream::GetNewJob(void)
{
	if (static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX) <= jobIntense) //число от [0;1)<=интенсивности
	{
		lastJobId++;
		return lastJobId - 1;
	}
	else
		return 0;
}

size_t TJobStream::GetLastJobId(void) const noexcept
{
	return lastJobId;
}

