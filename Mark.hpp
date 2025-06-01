#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <cstring>
#include <iostream>

class Student
{
	char* m_lastName;
	char* m_firstName;
	int m_age;
	int m_marks[10];

	// const int m_group = 101; // possible
	const int m_group;

	void copyStrField(char*& field, const char* value)
	{
		delete[] field;
		size_t valueSize = strlen(value) + 1;
		field = new char[valueSize] {};
		strcpy_s(field, valueSize, value);
	}
public:

	static unsigned studentsCount;

	Student() : Student("Smith", "John", 19, 0)
	{
	}

	Student(const char* lastName, const char* firstName, int age) : Student(lastName, firstName, age, 0)
	{
	}

	Student(const char* lastName, const char* firstName, int age, int group)
		: m_lastName{ new char[strlen(lastName) + 1] {} }
		, m_firstName{ new char[strlen(firstName) + 1] {} }
		, m_age{ age }
		, m_marks{}
		, m_group{ group }
	{
		std::cout << "Student::Student(): with address " << this << std::endl;

		strcpy_s(this->m_lastName, strlen(lastName) + 1, lastName);
		strcpy_s(m_firstName, strlen(firstName) + 1, firstName);
		// m_group = 101; // error
	}

	~Student()
	{
		std::cout << "Student::~Student(): with address " << this << std::endl;
		delete[] m_lastName;
		delete[] m_firstName;
	}

	const char* getLastName() // getLastName(Student* const this)
	{
		return m_lastName;
	}

	Student& setLastName(const char* lastName)
	{
		copyStrField(m_lastName, lastName);
		return *this;
	}

	const char* getFirstName() // getFirstName(Student* const this)
	{
		return m_firstName;
	}

	Student& setFirstName(const char* firstName)
	{
		copyStrField(m_firstName, firstName);
		return *this;
	}

	static unsigned getStudentsCount(); // getStudentsCount() because it is static

	int getAge() // getAge(Student* const this)
	{
		return m_age;
	}

	void setAge(int age) // setAge(Student* const this, int age)
	{
		m_age = age;
	}
};

#endif // !STUDENT_HPP
