#include <iostream>
#include <vector>
#include <string>

class Parent {
protected:
	std::string name;
	std::vector<Parent> list_;

public:
	Parent::Parent() {

	};
	
	Parent::Parent(std::string name) {
		this->name = name;
		list_.clear();
	};

	void add_child(Parent child) {
		list_.push_back(child);
	};

	std::string get_name() {
		return name;
	};

	void print() {
		std::cout << "I currently have " << list_.size() << " children.\n";
		std::vector<Parent>::iterator it;
		for (it = list_.begin(); it != list_.end(); it++) {
			Parent temp = *it;
			std::cout << temp.get_name() << std::endl;
		}
	};
};

class Child :public Parent {
public:
	Child::Child(std::string name) {
		this->name = name;
		list_.clear();
	}
};

int main() {
	Parent parent = Parent("Parent");
	Child son = Child("Son");
	Child daughter = Child("Daughter");
	Child grandSon = Child("Grand Son");

	return 0;

};

