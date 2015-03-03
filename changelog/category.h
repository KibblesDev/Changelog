#ifndef CATEGORY_H_
#define CATEGORY_H_

#include <iostream>
#include <vector>
#include <ctime>
#include <map>
#include <string>

/*
	New category for the change log
*/
class Category {
private:
	void print_helper(int tab_count);

protected:
	std::vector<std::string> description_;
	std::vector<Category> list_;
	std::string name_;
	time_t created_;
	std::vector<time_t> last_changed_;
	int change_count_;

public:
	Category();
	Category(std::string name);
	Category(std::string name, Category sub);

	int get_change_count();
	void set_time();
	void add_subcategory(Category sub);
	void increase_change_count();
	void print();
	std::vector<Category> get_list();
	time_t get_created_time();
	time_t get_last_changed_time();
	std::string get_name();
	std::string to_string();
	Category get_subcategory(std::string name);
	std::string get_latest_description();

};

/*
	Content
*/
class Content :public Category {
public:
	Content();
	Content(std::string name);
	Content(std::string name, std::string description);


};
#endif