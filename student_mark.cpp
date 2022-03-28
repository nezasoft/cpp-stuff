#include<iostream>
#include<string>
using namespace std;
class Mark{
	private:
		string reg_no,name,subject;
		int mark;		
	public:
		string getSubject();
		void setStudentData(string,string,int);
		int getStudentMark();
		void displayStudentData();		
};

void Mark::setStudentData(string _name, string _reg_no, int _mark){
	reg_no = _reg_no;
	name = _name;
	mark = _mark;
}
void Mark::displayStudentData(){
	cout<<" Student Name: "<< name<<endl;
	cout<<" Student Reg No: "<< reg_no<<endl;
}
string Mark::getSubject(){
	return subject;
}
int Mark::getStudentMark(){
	return mark;
}
class Physics: public Mark{
	public:
		string getSubject(){
			return "Physics";
		}
};
class Chemistry: public Mark{
	public:
		string getSubject(){
			return "Chemistry";
		}
};
class Math: public Mark{
	public:
		string getSubject(){
			return "Math";
		}
};
int main(){
	int students,mark;
	string name,reg_no;
	int total;
	int count =1;
	float average;	
	cout<<"Enter No of students:"<<endl;
	cin>>students;	
	Physics p;
	Chemistry c;
	Math m;
	while(count<=students){
		count++;
		cout<<" Enter Student Name:"<<endl;
		cin>>name;
		cout<<"Enter Registration No:"<<endl;
		cin>>reg_no;
		cout<<"Enter Marks for Physics:"<<endl;
		cin>>mark;
		p.setStudentData(name,reg_no,mark);
		cout<<"Enter Marks for Chemistry:"<<endl;
		cin>>mark;
		c.setStudentData(name,reg_no,mark);
		cout<<"Enter Marks for Math:"<<endl;
		cin>>mark;
		m.setStudentData(name,reg_no,mark);
		total = m.getStudentMark() + p.getStudentMark() + c.getStudentMark();
		average = total / 3;
		p.displayStudentData();
		cout<<" Physics: "<<p.getStudentMark()<<endl;
		cout<<" Chemistry : "<<c.getStudentMark()<<endl;
		cout<<" Math : "<<m.getStudentMark()<<endl;
		cout<<" Average Mark:"<<average<<endl;					
	}
		
}
