#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int id;
    float grade;
    static int studentCount;

public:
    Student() {
        name = "";
        id = 0;
        grade = 0.0;
        studentCount++;
    }

    Student(string name, int id, float grade) {
        this->name = name;
        this->id = id;
        this->grade = grade;
        studentCount++;
    }

    ~Student() {
        studentCount--;
    }

    void displayInfo() {
        cout << "name: " << name << endl;
        cout << "id: " << id << endl;
        cout << "grade: " << grade << endl;
    }

    void setName(string name) { 
        this->name = name; 
    }
    string getName() { 
        return name; 
    }
    void setId(int id) { 
        this->id = id; 
    }
    int getId() {
         return id; 
    }
    void setGrade(float grade) {
        if (grade >= 0 && grade <= 100)
            this->grade = grade;
        else
            cout << "Invalid grade" << endl;
    }
    float getGrade() { 
        return grade; 
    }

    static int getCount() { 
        return studentCount; 
    }
};

class Instructor {
private:
    string name;
    int instructorId;

public:
    Instructor() {
        name = "";
        instructorId = 0;
    }

    Instructor(string name, int instructorId) {
        this->name = name;
        this->instructorId = instructorId;
    }

    ~Instructor() { 
        cout << "Instructor is deleted" << endl; 
    }

    void displayInstructorInfo() {
        cout << "Name: " << name << endl;
        cout << "Instructor id: " << instructorId << endl;
    }

    void setName(string name) { 
        this->name = name; 
    }
    void setInstructorId(int id) { 
        this->instructorId = id; 
    }

    friend void updateGrade(Student &s, float newGrade);
};

void updateGrade(Student &s, float newGrade) {
    s.setGrade(newGrade);
    cout << "Grade updated successfully" << endl;
    cout << "New grade: " << s.getGrade() << endl;
}

class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    GraduateStudent(string name, int id, float grade, string researchTopic)
        : Student(name, id, grade) {
        this->researchTopic = researchTopic;
    }

    ~GraduateStudent() { 
        cout << "Graduate student is deleted" << endl; 
    }

    void setResearchTopic(string researchTopic) { 
        this->researchTopic = researchTopic; 
    }

    void displayResearchInfo() {
        cout << "Research topic: " << researchTopic << endl;
        cout << "Name: " << getName() << endl;
        cout << "ID: " << getId() << endl;
        cout << "Grade: " << getGrade() << endl;
    }
};

int Student::studentCount = 0;

int main() {
    Student s1("Ammar", 2401038, 14.5);
    Instructor i1("Eng. Clark", 123456);
    GraduateStudent g1("Ammar", 2401038, 14.5, "cybersecurity");

    s1.setName("Ammar");
    s1.setId(2401038);
    s1.setGrade(14.5);

    i1.setName("Eng. Clark");
    i1.setInstructorId(123456);

    g1.setResearchTopic("cybersecurity");

    updateGrade(s1, 15.0);
    
    g1.displayResearchInfo();

    cout << "Total students: " << Student::getCount() << endl;

    return 0;
}
