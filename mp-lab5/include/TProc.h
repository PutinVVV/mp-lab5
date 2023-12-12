#include "TQueue.h"
#include <cstdlib>
class TProc
{
private:
	double procRate; 
	TQueue<size_t> jobs;
	size_t jobsDone;
	size_t noJobsTimes;
public:

TProc::TProc(double rate, size_t maxJobs) : jobs(maxJobs)//������������������ � ������ �������
{
	if (rate >= 0.0 && rate <= 1.0)
	{
		procRate = rate;
		jobsDone = 0;
		noJobsTimes = 0;
	}
	else
		throw "Err";
}

double TProc::GetRate(void) const noexcept//�������������
{
	return procRate;
}

size_t TProc::IsProcBusy(void) const noexcept//����� �� ���������
{
	if (jobs.IsEmpty())
		return 0;
	else
		return jobs.Top();
}

bool TProc::IsProcFull(void) const noexcept//������� ���������� ���������
{
	return jobs.IsFull();
}

size_t TProc::RunNewJob(size_t JobId)//������ ����� ������
{

	if (JobId > 0)
	{
		if (!(IsProcFull()))
		{
			jobs.Push(JobId);
			return JobId;
		}
	}
	else
		return ~0;
}

size_t TProc::DoJob(void)
{
	if (!IsProcBusy())
	{
		noJobsTimes++;
		return 0;
	}
	else if (static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX) <= procRate && IsProcBusy())//���������� ��������� ����� �� [0;1)
	{
		size_t lastJob = jobs.TopPop();
		jobsDone++;
		return lastJob;
	}
	else
		return jobs.Top();
}

size_t TProc::GetJobsDone(void) const noexcept
{
	return jobsDone;
}

size_t TProc::GetNoJobsTimes(void) const noexcept
{
	return noJobsTimes;
}
};

