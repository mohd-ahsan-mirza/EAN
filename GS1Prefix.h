#define nullptr NULL

class Prefix{


 public:

  	Prefix(const char* f);

  	bool isRegistered(int a) const;

  	int minNoDigits(int a) const;

  	bool isRegistered(int a,const char* p) const;
       
         int total() const;

 private:

  //const int MAX=700;

  	int no;
  
  	int area[700];

  	char pubLow[700][8];
  
 	char pubHgh[700][8];
  
  	int pubLen[700];

};

 



