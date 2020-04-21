#ifndef COMBAT_CLASS_H
#define COMBAT_CLASS_H

#include <ostream>
#include <vector>

#include "constants.h"

class class_features;
class fighter_features;
class wizard_features;
class rogue_features;

class character_job final
{
public:
	character_job(const character_job& other) = default;

	character_job(character_job&& other) noexcept
		: my_jobs_(std::move(other.my_jobs_))
	{
	}

	character_job& operator=(const character_job& other)
	{
		if (this == &other)
			return *this;
		my_jobs_ = other.my_jobs_;
		return *this;
	}

	character_job& operator=(character_job&& other) noexcept
	{
		if (this == &other)
			return *this;
		my_jobs_ = std::move(other.my_jobs_);
		return *this;
	}

	character_job() = default;
	explicit character_job(job_labels class_choice);
	~character_job();
	
	void build_job(job_labels class_choice);
	void display_jobs() const;
	std::vector<job_labels>& get_my_jobs() { return my_jobs_; }
	
private:
	// class storage
	std::vector<job_labels> my_jobs_ {};
};

#endif