#include <iostream>
#include <string>

int main() {
	setlocale(LC_ALL, "russian");
	
	int n;

	class Student {
		std::string name;
		int* marks;
		size_t marks_number;
		int age;
	public:
		Student() {
			std::cout << "Конструктор по умолчанию.\n";
			name = "Ayanami Rei";
			marks = nullptr;
			marks_number = 0;
			age = 0;
		}
		Student(std::string other_name, int other_age = 0) {
			std::cout << "Параметрический конструктор.\n";
			name = other_name;
			marks = nullptr;
			marks_number = 0;
			setAge(other_age);
		}
		~Student() {
			std::cout << "Деструктор.\n";
			delete[] marks;
		}

		void sayName() {
			std::cout << "My name is " << name << ".\n";
		}
		void setMark(int mark) {
			if (marks == nullptr) {
				marks = new int[1] { mark };
				marks_number = 1;
				return;
			}
			int* tmp = new int[marks_number + 1];
			for (size_t i = 0; i < marks_number; ++i)
				tmp[i] = marks[i];
			tmp[marks_number] = mark;
			delete[] marks;
			marks = tmp;
			++marks_number;
		}

		int getMark(size_t index) {
			return marks[index];
		}

		void setAge(int other_age) {
			if (other_age >= 5 && other_age <= 55){
				age = other_age;
			return;
		}
		age = 0;
	}
		int getAge() {
			return age;
		}



	};

	//Блок проверки деструктора
	if (true) {
		Student tmp;
	}

	Student s1("Kuroko Tetsuya", 15);
	//s1.name = "Tom Smith"; //Ошибка! ()инкапсуляция
	s1.sayName();
	s1.setMark(6);
	s1.setMark(12);
	std::cout << s1.getMark(0) << std::endl;
	std::cout << s1.getMark(1) << std::endl;
	std::cout << "Возраст: " << s1.getAge() << std::endl;





	return 0;
}