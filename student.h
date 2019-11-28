#ifndef STUDENT_H

using namespace std;


 class Student{

private:

      int ID;
      string name;
      double GPA;
      string level;
      string major;
      int advisor;

public:

      Student();
      Student(int ID, string name, double GPA, string level, int advisor);
      void setStudent(){

      }

      int getID();
      void setID(int value);
      {
        value = ui;
      }
      string getName();

      void setName(string val);
      {
        name = val;
      }

      double getGPA(){

      };
      void setGPA(int val){
        gpa = val
      }

      void getAdvisor(){return advisor}
      void setAdvisor(int value){
        advisor = value
      }

      void toString();


 }




#endif
