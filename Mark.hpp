#ifndef MARK_HPP
#define MARK_HPP
#include <cstring>
#include <iostream>

class Student
{
	int m_marks[10];

public:

	Student(int marks) : m_marks{ marks }
	{

	}

	int getAge()
	{
		return m_marks;
	}
	void setAge(int marks)
	{
		m_marks = marks;
	}
};

#endif // !MARK_HPP

