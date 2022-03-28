#include<iostream>
#include<string>

using namespace std;
class Invoice{
	private:
		string partNo;
		string partDesc;
		int Quantity,Price,Total;
	public:
		int getInvoiceAmount(int,int);
		void displayData();
		void getAllData(string,string,int,int);
		void setPrice(int);
		void setQuantity(int);
		void setPartNo(string);
		void setPartDesc(string);
		void displayMenu();
		int getPrice();
		int getQuantity();
		
		Invoice(){}
		~Invoice(){}
			
};

		
		int Invoice::getInvoiceAmount(int cal_qty, int cal_price){	
		    cal_qty = this->getQuantity();	
			cal_price = this->getPrice();	
			return cal_qty * cal_price;		
			
		}
		
		void Invoice::setPrice(int price){
			if(price<0){
				price = 0;
			}
			Price = price;
		}
		void Invoice::setQuantity(int qty){
			if(qty<0){
			 	qty = 0;	
			}
			Quantity = qty;
		}
		void Invoice::setPartNo(string part_no){
			partNo = part_no;
		}
		void Invoice::setPartDesc(string part_desc){
			partDesc = part_desc;
			
		}
		int Invoice::getPrice(){
			return Price;
		}
		
		int Invoice::getQuantity(){
			return Quantity;
		}
		
		void  Invoice::getAllData(string part_no, string part_desc, int qty, int price){
			this->setPartNo(part_no);
			this->setPartDesc(part_desc);
			this->setQuantity(qty);
			this->setPrice(price);
			qty = this->getQuantity();
			price = this->getPrice();
			Total = this->getInvoiceAmount(qty,price);

		}
		
	void Invoice::displayData(){
	 	cout<<"******** Item Details ****"<<endl;
		cout<<"Item Description:"<<partDesc<<" Part No:"<<partNo<<" Price:"<<Price<<" Quantity:"<<Quantity<<" Total Amount: "<<Total<<endl;	
		cout<<"******** Item End*******"<<endl;		
		}		
	void Invoice::displayMenu(){
		cout<<"***Choose Option***"<<endl;
		cout<<"1. Generate Invoice"<<endl;
		cout<<"0. Quit! "<<endl;				
	}	
	
	int main(){	
	int menu_item,price,qty;
	string part_no,part_desc;
	Invoice inv;	
    cout<<"--***---Welcome to Dynamics Store--***--"<<endl;
    inv.displayMenu();
    cin>>menu_item;
	menu_item = (int) menu_item;
    while(menu_item==1){

    	cout<<"Enter Part No: "<<endl;
    	cin>>part_no;
    	cout<<"Enter Item Desc"<<endl;
    	cin>>part_desc;
    	//getline(cin,part_desc);
    	cout<<"Enter Quantity"<<endl;
    	cin>>qty;
    	cout<<"Enter Price"<<endl;
    	cin>>price;
    	inv.getAllData(part_no,part_desc,qty,price);
    	inv.displayData();  
		inv.displayMenu();
	    cin>>menu_item;
		menu_item = (int) menu_item;	
	}
	
	}

