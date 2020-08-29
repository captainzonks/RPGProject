#include "job_component.h"

#include <iostream>
#include <algorithm>

job_component::job_component(const job_labels &job_choice) {
  build_job(job_choice);
}

job_component::~job_component() {
  std::cout << "job_component destructor called" << std::endl;
}

void job_component::build_job(const job_labels &job_choice) {
  if (std::find(my_jobs_.begin(), my_jobs_.end(), job_choice) == my_jobs_.end()) {
	my_jobs_.push_back(job_choice);
  }
}

void job_component::display_jobs() const {
  if (my_jobs_.capacity() == 1)
	std::cout << job_strings.at(static_cast<int>(my_jobs_.at(0)));
  else {
	for (auto &c : my_jobs_) {
	  std::cout << job_strings.at(static_cast<int>(c));
	}
  }
}