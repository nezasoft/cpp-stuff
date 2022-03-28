#include<iostream>
#include<string>

using  namespace std;

class Account{
	public:
		double balance;
	public:
		Account(double _balance){
			if(_balance<0.00){
				_balance = 0.00;
				cout<<"Invalid Balance. Amount should be greater than or equal to 0.00"<<endl;
			}
			balance = _balance;
		}
		~Account(){}
		
		void credit(double _amount);
		void debit(double _amount);
		double getBalance();
		
	
		
};

void Account::credit(double _amount){
	balance += _amount;
}

void Account::debit(double _amount){
	if(balance<_amount){
		cout<<"Debit Amount exceeded account balance"<<endl;
	}else{
	balance -= _amount;	
	}
	
}

double Account::getBalance(){
	return balance;
}

class SavingsAccount: public Account{
	private:
		double interest_rate;
	public:
		SavingsAccount(double balance): Account(balance){
			
		}
		~SavingsAccount(){}
		double calculateInterest(double int_rate);
};

double SavingsAccount::calculateInterest(double int_rate){
	double new_bal = balance;
	interest_rate = int_rate;
	//balance = interest_rate * balance;
	balance += (interest_rate/100) * balance;
	return (interest_rate/100) * new_bal;
	
}

class CheckingAccount: public Account{
	private:
	 double transaction_fee;
	public:
		CheckingAccount(double balance): Account(balance){
			
		}
		~CheckingAccount(){}
		void debit(double _amount);
		void credit(double _amount);
	
};

void CheckingAccount::debit(double _amount){
	double trans_fee = 150;
	transaction_fee = trans_fee;
	bool ok = true;
	if(balance-_amount>=0){
		balance -= _amount;	
		ok = true;
		
	}else{
		ok = false;
	}
	
	if(ok==false){
		cout<<"Debit Amount exceeded account balance"<<endl;
	}else{
	balance -= transaction_fee;	
	}

}

void CheckingAccount::credit(double _amount){
	double trans_fee = 150;
	transaction_fee = trans_fee;
	balance += _amount;
	balance -= transaction_fee;
}

int main(){
	
	Account a=Account(10000);
	SavingsAccount s=SavingsAccount(a.getBalance());
	CheckingAccount c = CheckingAccount(a.getBalance());
	cout<<"Interest Rate: "<<s.calculateInterest(6.00)<<endl;	
	cout<<"Balance: "<<s.getBalance()<<endl;
	cout<<"Credit Amount: KES 2500"<<endl;
	 c.credit(2500.00);
	 cout<<"Account Balance: "<<c.getBalance()<<endl;
	 cout<<"Debit Amount: KES 1200"<<endl;
	 c.debit(1200.00);
	 cout<<"Account Balance:"<<c.getBalance()<<endl;


}


