#include<iostream>

//#include"GS1Prefix.h"

using namespace std;


//#include"GS1Prefix.h"

class Prefix;

class EAN{

	public:

 		EAN();

 		EAN(const char* str,const Prefix& list);

  		bool empty() const;

  		bool isRegistered() const;

  		void style(char choice);

  		void toStr(char* str) const;

  		void toStrWithStyle(char* str) const;

 		void display(std::ostream& os) const;

		bool read(std::istream& is,const Prefix& list);

		friend bool operator==(const EAN& left, const EAN& right);

		friend std::ostream& operator<<(std::ostream& os, const EAN& ean);

	private:

 		 char areae[7];

 		 char publisher[9];

 		 char title[12];
		
		const char* ostring;
	
	        Prefix* l;                
          
 		bool isRegistered(const Prefix& list);

				
		 char formatted[18];

		char initial[14];

		bool registered;
};

bool isValid(const char* str);

