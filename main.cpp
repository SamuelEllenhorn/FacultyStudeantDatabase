
#include "binarysearchtree.h"
#include "record.h"
#include <vector>
using std::vector;


void printMenu() {
  system("cls");
  printf("1: Print all studeant");
  printf("2: Print all faculty\n");
  printf("3: View specific studeant information\n");
  printf("4: View specific faculty information\n");
  printf("5: Print studeant advisor record\n");
  printf("6: Display all members of specific Faculty advisors group\n");
  printf("7: Add new studeant\n");
  printf("8: Remove specific Studeant from DataBase\n");
  printf("9: add a new faculty member\n");
  printf("10: Remove a faculty member\n");
  printf("11: Change a student’s advisor\n");
  printf("12: Remove advisee from Faculty advisor Group\n");
  printf("13: Rollback last action\n");
  printf("14: Exit Program\n");
}

int getIntInput(String prompt){
  cout << prompt;
  int n;
  cin >> n;
  // Error trap
  while (!cin){
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Please enter an integer: " << endl;
    cin >> n;
  }
  return n;

}

void printAll(type BST){

  inorder transversal and call the toString() method on each memeber


}


void queryAdvisor() {
  int ID = getIntInput("Enter the studeants ID number:\n")
  Faculty f;
  bool success = queryAdviserByStudentID(ID, f);
  if(success)
    cout << f;
  else
    cout << "Unable to find advisor for student.\n"
}

void queryAdvisees(){
  int fID = getIntInput("Enter the faculty ID number:\n")

  bool success = queryAdviseeByFacultyID(fID);
  if(success)
    cout << f;
  else
    cout << "Unable to find specifc faculties advisees.\n"

}




BinarySearchTree<int, Student* >* studentTree = new  BinarySearchTree<int, Student*>();
Student *s1 = new Student(1, "Samuel", "Senior", "CS", 4.0, 51);
Student *s2 = new Student(2, "Harry", "Junior", "English", 3.5, 52);
Student *s3 = new Student(3, "Elliot", "Sophomore", "Mathematics", 3.8, 53);

vector<Student*> studentVector;
vector<Faculty*> facultyVector;

BinarySearchTree<int, Faculty*>* facultyTree = new  BinarySearchTree<int, Faculty*>();
Faculty *f1 = new Faculty(51, "John", "Assoc.Prof", "CS");
Faculty *f2 = new Faculty(52, "David", "Prof", "Mathematics");
Faculty *f3 = new Faculty(53, "Carl", "Prof", "English");



void enter_records()
{
    studentVector.push_back(s1);
    studentVector.push_back(s2);
    studentVector.push_back(s3);

    facultyVector.push_back(f1);
    facultyVector.push_back(f2);
    facultyVector.push_back(f3);



    for(int i=0; i < studentVector.size(); i++)
    {
        studentTree->insert(i+1, studentVector[i]);
    }

    for(int i=0; i < facultyVector.size(); i++)
    {
        facultyTree->insert(i+51, facultyVector[i]);
    }

}

void print_student_data()
{
    cout << "Students:\n";
    for(int i=0; i < studentVector.size(); i++ )
        cout << studentTree->search(i+1)->getValue()->getName() << endl;

}

void print_faculty_data()
{
    cout << "Faculty:\n";
    for(int i=0; i < facultyVector.size(); i++ )
        cout << facultyTree->search(51+i)->getValue()->getName() << endl;
}


Student* find_student(int id)
{
    TNode<int, Student*> *ts = studentTree->search(id);
    Student *s;
    if ( ts == NULL )
    {
        s = NULL;
        cout << "Student not found.\n";
    }
    else
    {
        s = ts->getValue();
        cout << "STUDENT_INFO:\n";
        cout <<"Name: " <<  s->getName() << "\n";
        cout <<"Level: " << s->getLevel() << "\n";
        cout <<"Major: " << s->getMajor() << "\n";
        cout <<"GPA: " << s->getGPA() << "\n";
    }
    return s;
}


Faculty* find_faculty(int id)
{
    TNode<int, Faculty*> *tf = facultyTree->search(id);
    Faculty *f;
    if ( tf == NULL )
    {
        f = NULL;
        cout << "Faculty not found.\n";
    }
    else
    {
        f = tf->getValue();
        cout << "FACULTY_INFO:\n";
        cout <<"Name: " <<  f->getName() << "\n";
        cout <<"Level: " << f->getLevel() << "\n";
        cout <<"Department: " << f->getDepartment() << "\n";

    }
    return f;
}




void find_faculty_by_student_id(int sid)
{
    Student* s = find_student(sid);
    if( s != NULL)
    {
        int fid = s->getAdvisor();
        find_faculty(fid);
    }

}


void add_new_student()
{
    int id, adv;
    string name, level, major;
    double gpa;

    cout << "Enter Student data:\n";
    cout << "Student ID, Name, Level, Major, GPA, AdvisorID:";
    cin >> id >> name >> level >> major >> gpa >> adv;
    studentVector.push_back( new Student(id, name, level, major, gpa, adv) );
    studentTree->insert(id, studentVector[studentVector.size()-1]);

}





void print_menu()
{
    int choice = 0;

    string menu = "1. Print all students and their information (sorted by ascending id #)\n"
     "2. Print all faculty and their information (sorted by ascending id #)\n"
     "3. Find and display student information given the students id\n"
     "4. Find and display faculty information given the faculty id\n"
     "5. Given a student\'s id, print the name and info of their faculty advisor\n"
     "6. Given a faculty id, print ALL the names and info of his/her advisees.\n"
     "7. Add a new student\n"
     "8. Delete a student given the id\n"
     "9. Add a new faculty member\n"
     "10. Delete a faculty member given the id.\n"
     "11. Change a student\'s advisor given the student id and the new faculty id.\n"
     "12. Remove an advisee from a faculty member given the ids\n"
     "13. Rollback\n"
     "14. Exit\n";
     cout << menu;

    do
    {
        cout << "Enter your selection: "; cin >> choice;
        switch(choice)
        {
            case 1: print_student_data(); break;
            case 2: print_faculty_data(); break;
            case 3:
            {
                int sid;
                cout << "Please enter student\'s ID:"; cin>> sid;
                find_student(sid);
                break;
            }
            case 4:
            {
                int fid;
                cout << "Please enter faculty\'s ID:"; cin>> fid;
                find_faculty(fid);
                break;
            }

            case 5:
            {
                int sid;
                cout << "Please enter student\'s ID to print advisor:"; cin>> sid;
                find_faculty_by_student_id(sid);
            }
            case 7:
            {
                add_new_student();
            }

            case 14: break;
            default: cout << "selection out of range, try again.\n"; break;

        }

    } while( choice != 14);
}




int main()
{

    enter_records();
    print_menu();
    return 0;


}
