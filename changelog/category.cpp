#define _CRT_SECURE_NO_WARNINGS
#include "category.h"
#include <iomanip>

Category::Category() {
	
};

Category::Category(std::string name) {
	time(&created_);
	name_ = name;
	change_count_ = 0;
	list_.clear();
	description_.push_back("No description set");
};

Category::Category(std::string name, Category sub) {
	time(&created_);
	name_ = name;
	list_.push_back(sub);
	change_count_ = 0;
	description_.push_back("No description set");
};

void Category::set_time() {
	last_changed_.push_back(time(0));
};

int Category::get_change_count() {
	return change_count_;
};

void Category::increase_change_count() {
	change_count_++;
};

void Category::add_subcategory(Category sub) {
	list_.push_back(sub);
}

std::vector<Category> Category::get_list() {
	return list_;
}

time_t Category::get_created_time() {
	return created_;
};

time_t Category::get_last_changed_time() {
	return last_changed_[last_changed_.size() - 1];
};

std::string Category::get_name() {
	return name_;
};

Category Category::get_subcategory(std::string name) {
	std::vector<Category>::iterator it;
	for (it = list_.begin(); it != list_.end(); it++) {
		if (it->name_.compare(name) == 0)
			return *it;
	}
	return NULL;
};

void Category::print_helper(int tab_count) {
	std::cout << std::string(tab_count, '\t') << " * " << name_ << "\n";
	std::vector<Category>::iterator it;
	for (it = list_.begin(); it != list_.end(); it++) {
		if (it->list_.size() == 0) {
			time_t c = it->get_created_time();
			std::cout << std::string(tab_count, '\t') << " * " << it->get_name() << "\n";
			tab_count++;
			std::cout << std::string(tab_count, '\t') << "Created: " << ctime(&c);
			std::cout << std::string(tab_count, '\t') << "Change count: " << it->get_change_count() << "\n";
			std::cout << std::string(tab_count, '\t') << "Description : " << it->get_latest_description() << "\n";
			tab_count--;
		} else {
			std::vector<Category>::iterator it2;
			for (it2 = list_.begin(); it2 != list_.end(); it2++) {
				it2->print_helper(++tab_count);
			}
		}
	}
};


void Category::print() {
	print_helper(0);
}

/*
	Content
*/

Content::Content(std::string name) {
	time(&created_);
	last_changed_.push_back(time(0));
	name_ = name;
	description_.push_back("No description set");
	change_count_ = 0;
}

Content::Content(std::string name, std::string description) {
	time(&created_);
	last_changed_.push_back(time(0));
	name_ = name;
	description_.push_back(description);
	change_count_ = 0;
};

std::string Category::get_latest_description() {
	return description_[description_.size() - 1];
}



