#include <iostream>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class Exam{
	private:
		
		string *name;
		string *date;
		float *marks;
	public:
		Exam(string name,string date,float marks){
			
			name = new string(name);
			date = new string(date);
			marks = new float(marks); 
			
		}
		//DEEP COPY
		//Exam(const Exam &other){
		//	
		//	name = new string(*other.name);
		//	date = new string(*other.date);
		//	marks = new float(*other.marks); 
		//	
		//}
		//SHALLOW COPY
		
		Exam(Exam &other){
			
			name = other.name;
			date = other.date;
			marks = other.marks; 
			
		}
		void displayInfo(){
					
			cout<<"STUDENT NAME: "<<*name<<endl<<"EXAM DATE: "<<*date<<"TOTAL MARKS: "<<*marks<<endl;
		}
		
		~Exam(){
			delete name;
			delete marks;
			delete marks;
		}
};

int main(int argc, char** argv) {
	
	
	Exam exam1("Mishal Fahim","12-oct-25",86);
	
	exam1.displayInfo();
	
	Exam exam2(exam1);
	
	exam1.displayInfo();
	return 0;
}
