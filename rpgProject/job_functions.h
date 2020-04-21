#ifndef JOB_FUNCTIONS_H
#define JOB_FUNCTIONS_H
#include "character_job.h"

class job_functions
{
public:

	void access_functions(job_labels job);

	static job_functions* instance()
	{
		return &job_functions_instance_;
	}
	
protected:
	job_functions() = default;
	static job_functions job_functions_instance_;
};

#endif
