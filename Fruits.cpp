#include<iostream>
#include<string>

using namespace std;

class Fruit{
	private:
		int qty;
		int total;
		string name;
	public:
		string getName();
		int getQuantity();
		void setQuantity(int);

};

string Fruit::getName(){
	return name;
}

int Fruit::getQuantity(){
	return qty;
}

void Fruit::setQuantity(int qty){
	this->qty = qty;
}

class Apples: public Fruit{
	public:
		string getName(){
			return "Apples";
			
		}

};

class Mangoes: public Fruit{
	public:
		string getName(){
			return "Mangoes";
			
		}

};

int main(){
	
	int total,qty;
	
	Apples a;
	Mangoes m;
	
	cout<<"Enter number of mangoes:"<<endl;
	cin>>qty;
	m.setQuantity(qty);
	cout<<"Enter number of apples:"<<endl;
	cin>>qty;
	a.setQuantity(qty);
	cout<<m.getName()<<":"<<m.getQuantity()<<endl;
	cout<<a.getName()<<":"<<a.getQuantity()<<endl;
	cout<<"Total Fruits:"<<a.getQuantity() + m.getQuantity()<<endl;

	
}
