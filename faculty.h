#ifndef FACULTY_H

using namespace std;


 class Faculty{

private:

      int ID;
      string name;
      string level;
      string departmeant;
      int advisor;
      vector<int> advisees;// vector of ints

public:

    Faculty();
    Faculty(int ID, string name, string level, string departmeant, int advisor);

    const vector<int>& getAdvisees(){
      return advisees;
    }

    void setName(String val){
      name = val;
    }
    String getName(){
      return name;
    }

    void setLevel(String val){
      level = val;
    }
    String getLevel(){
      return name;
    }
    string getDep(){
      return departmeant;
    }
    void set Dep(value){
      departmeant = value;
    }



    ostream & operator << (ostream& out) {
      out << "ID: " << ID << ", Name: " << ", Level: " << level << "" endl;
    }


 }




#endif
