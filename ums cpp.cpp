#include<iostream>
using namespace std;
class user                        //abstract class
{
	protected:                   // access specifier
		string name;            //instance variables
		string id;
	public:
	    virtual void getdetails()=0;     //pure virtual function
	    virtual ~user(){}
};

class student : public user
{
	private:
		string degree;
	public:
		student(){}
	    student(string n , string i , string m){
	    	name=n;
	    	id=i;
	    	degree=m;
		}	
		void getdetails(){
			cout<<"Student name is "<<name<<" and ID is "<<id<<" with degree: "<<degree<<endl;
		}
	
};

class teacher : public user
{
	private:
		string subject;
	public:	
	    teacher(){}
	    teacher(string n , string i , string m){
	    	name=n;
	    	id=i;
	    	subject=m;
		}	
		void getdetails(){
			cout<<"Teacher name is "<<name<<" and ID is "<<id<<" and he teaches "<<subject<<endl;
		}
};

class course 
{
	private:
		string name;
		string code;
		string credithours;
	public:
		course(){}
	    course(string n,string c, string ch){
	    	name=n;
	    	code=c;
	    	credithours=ch;
		}	
		void getdetails(){
			cout<<"course name is "<<name<<" code is "<<code<<" & CH is "<<credithours<<endl;
		}
};
class enrollment
{
	private:
		string studentname;
		string coursecode;
	public:
		enrollment(){}
		enrollment(string n,string c){
	    	studentname=n;
	    	coursecode=c;
		}	
		void getdetails()
		{
			cout<<"student :"<<studentname<<" is enrolled in course: "<<coursecode<<endl;
		}
};

class university_system
{
	private:
		course obj[100]; int l=0;
		user* obj1[100]; int j=0;
		enrollment obj3[100]; int k=0;
		
	public:
		void adduser(student *s){                //function overloading
		    obj1[j++]=s;
			cout<<"Student Added successfully !!"<<endl;
		}
		void adduser(teacher *t){                  //function overloading
		    obj1[j++]=t;
			cout<<"Teacher Added successfully !!"<<endl;
		}
		void addcourse(course c){
			obj[l++]=c;
			cout<<"Course Added successfully !!"<<endl;
		}
		void enrollstudent(enrollment o){
			obj3[k++]=o;
			cout<<"Student Successfull !!"<<endl;
		}
		void showallusers(){
			for(int i=0 ; i<j ;i++){
				obj1[i]->getdetails();
			}
		}
		void showallcourses(){
			for(int i=0 ; i<l ;i++){
				obj[i].getdetails();
			}
		}
		void showallenrollments(){
			for(int i=0 ; i<k ;i++){
				obj3[i].getdetails();
			}
		}
		void cleanup() {
        for (int i = 0; i < j; i++) {
            delete obj1[i]; // prevent memory leak
        }}
};

int main()
{
	university_system obj;
    
//	user* array[3];
	int i=0;
	int choice;
	while(true){
	
	    cout << "\n--- University System Menu ---\n";
        cout << "1. Add Student\n2. Add Teacher\n3. Add Course\n4. Enroll Student\n5. Show All Users\n6. Show All Courses\n7. Show All Enrollments\n8. Exit\nEnter choice: ";
        cin >> choice;
	if(choice==1){
		string n,id,d;
		cout<<"Enter Student's Name , ID , Degree : ";
		cin>>n>>id>>d;
	//	array[i++]=new student(n,id,d);  		         //polymorphism
		obj.adduser(new student(n,id,d));
		
	}
	else if(choice==2){
		string n,id,d;
		cout<<"Enter Teacher's Name , ID , Subject : ";
		cin>>n>>id>>d;
	//	array[i++]=new teacher(n,id,d);           //memory leakage
		obj.adduser(new teacher(n,id,d));
	}
	else if(choice==3){
		string n,c,ch;
		cout<<"Enter Course Name , Code , CreditHour :";
		cin>>n>>c>>ch;
		obj.addcourse(course(n,c,ch));            //dont use NEW polymorphism is not used 
	}                                             // use new only when void addcourse(course *c)
	else if(choice==4){
		string n,c;
		cout<<"Enter Student Name , CourseCode :";
		cin>>n>>c;
		obj.enrollstudent( enrollment(n,c));
    }
    else if(choice==5){
    	obj.showallusers();
	}
	else if(choice==6){
		obj.showallcourses();
	}
	else if(choice==7){
		obj.showallenrollments();
	}
	else if(choice==8){
		cout<<"\n\tExiting the Program.";
		obj.cleanup();
		break;   //added this to exit the loop
	}
	else{
		cout<<"Invalid choice. Please enter again"<<endl;
		
	}
}
    return 0;
   }

	















