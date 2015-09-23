#include<iostream>
#include<string.h>
using namespace std;

#include"EAN.h"

class iOrder{

	public :

		virtual EAN& getEAN()=0;
		virtual bool add(int)=0;
		virtual bool add(std::istream&)=0;
		virtual bool receive(std::istream&)=0;
		virtual int outstanding() const=0;
		virtual void display(std::ostream&) const=0;




};



class Order : public iOrder {


	public :

		Order();

		Order(const EAN& ean);

		EAN& getEAN();

		int outstanding() const;

		bool add(std::istream& is);

		bool add(int n);

		bool receive(std::istream& is);

		void display(std::ostream& os) const;

		//friend std::ostream& operator<<(std::ostream& os, const Order& order);

		virtual ~Order();

	protected:

		EAN* ean;

		int copies;

		int delivered;


};

std::ostream& operator<<(std::ostream& os,const iOrder& order);


class SpecialOrder : public Order {

	public :
		SpecialOrder();
		SpecialOrder(const EAN&,const char* instr);
		bool add(std::istream& is);
		void display(std::ostream& os);

		


	private :

		const char* instructions;






};
