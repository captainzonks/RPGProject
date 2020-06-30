#ifndef COMBAT_CLASS_H
#define COMBAT_CLASS_H

#include <ostream>
#include <vector>

#include "component.h"
#include "constants.h"

class job_component final
	: public component
{
public:
	job_component(const job_component& other) = default;

	job_component(job_component&& other) noexcept
		: component(other),
		  my_jobs_(std::move(other.my_jobs_))
	{
	}

	job_component& operator=(const job_component& other)
	{
		if (this == &other)
			return *this;
		component::operator =(other);
		my_jobs_ = other.my_jobs_;
		return *this;
	}

	job_component& operator=(job_component&& other) noexcept
	{
		if (this == &other)
			return *this;
		component::operator =(other);
		my_jobs_ = std::move(other.my_jobs_);
		return *this;
	}

	explicit job_component(job_labels class_choice);
	~job_component();

	void initialize() override {}
	void update(float delta_time) override {}
	void render() override {}
	
	void build_job(job_labels class_choice);
	void display_jobs() const;
	std::vector<job_labels>& get_my_jobs() { return my_jobs_; }
	
private:
	// class storage
	std::vector<job_labels> my_jobs_ {};
};

#endif