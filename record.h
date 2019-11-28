

#ifndef RECORD_H
#define RECORD_H
#include <string>

class Student
{
private:
        int studentID;
        string studentName;
        string studentLevel;
        string studentMajor;
        double gpa;
        int advisor;
        
public:
        Student(int id, string name, string level, string major, 
        double gpa, int adv):
        studentID(id),
        studentName(name),
        studentLevel(level),
        studentMajor(major),
        gpa(gpa),
        advisor(adv)
        {}
        ~Student() {}
        int getID()  {return studentID; }
        string getName() { return studentName; }
        string getLevel() { return studentLevel; }
        string getMajor() { return studentMajor; }
        double getGPA() { return gpa; }
        int getAdvisor(){ return advisor;}
        
        
};

/*
and a list of integers
corresponding to all of the faculty member’s advisees’ ids
*/
class Faculty
{
private:
    int facultyID;
    string facultyName;
    string facultyLevel;
    string department;
    
public:
    Faculty(int id, string name, string level, string dpt):
    facultyID(id),
    facultyName(name),
    facultyLevel(level),
    department(dpt)
    {}
    ~Faculty() {}
        
    int getID() { return facultyID; }
    string getName() { return facultyName; }
    string getLevel() { return facultyLevel;}
    string getDepartment() { return department;}

};

#endif