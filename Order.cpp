#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

//#include"EAN.h"

#include"GS1Prefix.h"

#include"Order.h"


Order::Order(){

	EAN e;
	//cout<<"5"<<endl;
	this->ean=(EAN*) malloc (sizeof(e)+1);
	*this->ean=e;
	this->copies=0;
	
	this->delivered=0;

}

SpecialOrder::SpecialOrder(){

	EAN e;
	this->instructions=nullptr;
	this->ean=(EAN*) malloc (sizeof(e)+1);
	*this->ean=e;
	this->copies=0;
	this->delivered=0;


}


Order::Order(const EAN& ean)
{

	this->ean=(EAN*) malloc (sizeof(ean)+1);
	
	*this->ean=ean;
	
	//cout<<"isRegister in order"<<this->ean

	this->copies=0;

	this->delivered=0;	

}


SpecialOrder::SpecialOrder(const EAN& isbn,const char* instr)
{


	if(instr != nullptr)
	{

		this->ean=(EAN*) malloc (sizeof(isbn)+1);

		*this->ean=isbn;

		this->copies=0;
	
		this->delivered=0;

		this->instructions=new char[61];

		strcpy((char*)this->instructions,instr);

	
	}

	else{


	

	EAN e;
	this->instructions=nullptr;
	this->ean=(EAN*) malloc (sizeof(e)+1);
	*this->ean=e;
	this->copies=0;
	this->delivered=0;

	}


}


EAN& Order::getEAN(){

	return *this->ean;


}


int Order::outstanding() const{

	return (this->copies-this->delivered);


}

bool Order::add(std::istream& is){

	int input;

	cout<<"Enter number of copies to order:";
	
	is>>input;

	if(is.fail())
	{
		
		is.clear();
		return false;

	}

	else
	{

		/*
		if((input>0) && (this->ean !=nullptr))
		{
		
			if(this->ean->isRegistered())
			{
				this->copies=this->copies+input;
				return true;
			}

			else
				return false;
			
		}


		else
			return false;

		*/
		return Order::add(input);

	}
	

}

bool SpecialOrder::add(std::istream& is){

	bool quantity=Order::add(is);

	is.clear();

	is.ignore();

	bool instructions=true;

	char input[61];

	cout<<"Enter special instructions:";

	is.getline (input,61);

	if(is.fail())
	{

		is.clear();
		instructions=false;

	}


	else{
		
		delete [] this->instructions;

		this->instructions=new char[61];

		strcpy((char*)this->instructions,input);

	}


	if(quantity==false || instructions==false)
		return false;

	else

		return true;


}



bool Order::add(int n){

	if((n>0)&&(this->ean !=nullptr))
	{
		if(this->ean->isRegistered())
		{
			this->copies=this->copies+n;
			return true;
		}

		else{
			return false;
		}

	}
	else
		return false;

}


bool Order::receive(std::istream& is)
{



	int input;

	cout<<"Enter number of copies delivered:";
	
	is>>input;

	if(is.fail())
	{
		
		is.clear();
		return false;

	}

	else
	{

		if((input>0) && (input<=this->outstanding()))
		{
			if(this->getEAN().isRegistered())
			{	
				this->delivered=this->delivered+input;
				return true;
			}
			else{
				
				return false;			

			}
	
		}


		else
			return false;

	}
}

void Order::display(std::ostream& os) const
{

 	//cout<<(cout,*this->ean)<<endl;

	os.width(17);	

	os<<(os,*this->ean);
	
	//cout<<"copies:"<<this->copies<<endl;
	//cout<<"delivered:"<<this->delivered<<endl;

	os.width(9);

	os<<this->copies;

	os.width(11);

	os<<this->delivered;

}


void SpecialOrder::display(std::ostream& os){

	Order::display(os);

	os.width(15);

	os<<this->instructions<<endl;


}

std::ostream& operator<<(std::ostream& os, const iOrder& order){

	order.display(os);

	return os;

}


 Order::~Order(){

}



/*
main(){



	//const char* q="9789070002046";
	
	const char* f="prefixRanges.txt";

	Prefix p(f);

	//EAN e(q,p);

        
	EAN ean("9789070002046",p);
        

	SpecialOrder order(ean,"10\% discount");

	order.add(cin);

	order.display(cout);



}	//cout<<(cout,order);

*
	

 	EAN ean1("9780003194876",p);


	 (ean,ean1);

	//cout<<check<<endl;

}
*	Order order1(ean1);

	order.add(cin);

	order.receive(cin);

	order1.add(cin);
	
	order1.receive(cin);

	order.display(cout);

	order1.display(cout);


	
    	
}
*	
	
	

	//order= Order(EAN("9789070002046",f));
    	
		

	//order.add(5);
	
	//cout<<"Register:"<<order.getEAN().isRegistered()<<endl;

}
*

	order.add(cin);

	//cout<<"outstanding:"<<order.outstanding()<<endl;


	order.receive(cin);

	//cout<<"outstanding:"<<order.outstanding()<<endl;		


	cout<<(cout,order);

	

	//e1.display(cout);
}
*/
