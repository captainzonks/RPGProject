#include "job_component.h"

#include <iostream>

job_component::job_component(job_labels const class_choice)
{
	build_job(class_choice);
}

job_component::~job_component()
{
	std::cout << "combat class destructor called" << std::endl;
}

void job_component::build_job(job_labels const class_choice)
{
	if (std::find(my_jobs_.begin(), my_jobs_.end(), class_choice) == my_jobs_.end())
	{
		my_jobs_.push_back(class_choice);
	}
}

void job_component::display_jobs() const
{
	if (my_jobs_.capacity() == 1)
		std::cout << job_strings.at(static_cast<int>(my_jobs_.at(0)));
	else
	{
		for (auto& c : my_jobs_)
		{
			std::cout << job_strings.at(static_cast<int>(c));
		}
	}
}