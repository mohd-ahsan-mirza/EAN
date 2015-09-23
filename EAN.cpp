

#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>

using namespace std;
#include"GS1Prefix.h"
#include"EAN.h"

EAN::EAN()
{
	ostring="";
	registered=false;
	formatted[0]='\0';

};

EAN::EAN(const char* str,const Prefix& list)
{
	if(str==nullptr || list.total()==0)
	{
		registered=false;
		ostring="";
		formatted[0]='\0';
	}


 	else{
		if(isValid(str))
      		{
		
			ostring=str;
	       		
		       	l=(Prefix*) malloc (sizeof(*l)+1);

			*l=list;
               		if(isRegistered(*l))
			{		
				registered=true;
				style('-');
			
                	}
		
			else
			{
				registered=false;
						
				for(int run=0;run<13;run++)
					formatted[run]=ostring[run];
			
					
				formatted[13]='\0';
				

			}		
		}
		else
		{
	        	registered=false;
			
			//if(strlen(str)==13)
			ostring="";
			//else
				//ostring="";
			

			formatted[0]='\0';


		}

	}
};

bool isValid(const char* str)
{


	if(str==nullptr)
		return false;

	if(strlen(str)==0)
		return false;

	if(strlen(str)!=13)
		return false;

	for(int x=0;x<13;x++)
	{

		if(!(isdigit(str[x])))
			return false;

	}

	int first=0;

	int check=1;

	for(int x=0;x<13;x++)
	{

		int digit=str[x]-'0';

		if(check%2==0)
		{

			int sec=digit*3;
			first=first+sec;
 
		}
	else
		first=first+digit;

	check++;
	}

	if((first)%10!=0)
		return false;



	return true;


}

bool EAN::isRegistered(const Prefix& p)
{



	if(!(isValid(ostring)))
		return false;

	char firstelement[5];

	for(int run=0;run<3;run++)
		firstelement[run]=ostring[run];

	const char* firstthree=firstelement;

	const char* firstcase="978";
	const char* secondcase="979";

	//if(!(strcmp(firstthree,secondcase)==0 || strcmp(firstthree,firstcase)==0))
		//return false;

	char aelement[6]={};
	char pubelement[8]={};
	char telement[11]={};

	int firstchecker=0;

	char a1[1000]={};

	int alength;

	int a;

	for(int run=0;run<5;run++)
	{

		if(run==0)
			a1[0]=ostring[3];

		if(run==1)
			a1[1]=ostring[4];

		if(run==2)
			a1[2]=ostring[5];


		if(run==3)
			a1[3]=ostring[6];



		if(run==4)
			a1[4]=ostring[7];



		const char* c=a1;
		int i=atoi(c);

      		if(p.isRegistered(i))
		{
			firstchecker=1;
			a=i;

			alength=strlen(c);

			for(int z=0;z<strlen(c);z++)
				aelement[z]=a1[z];

			aelement[alength]='\0';


		}


			

		if(firstchecker==1)
			break;


	}
	if(firstchecker==0)
		return false;



	int secondchecker=0;



	char a2[1000]={};

	int publength;
        
	for(int run=0;run<7;run++)
	{

		if(run==0)
			a2[0]=ostring[3+alength];

		if(run==1)
			a2[1]=ostring[3+alength+1];

		if(run==2)
			a2[2]=ostring[3+alength+2];


		if(run==3)
			a2[3]=ostring[3+alength+3];

		if(run==4)
			a2[4]=ostring[3+alength+4];

		if(run==5)
			a2[5]=ostring[3+alength+5];

		if(run==6)
			a2[6]=ostring[3+alength+6];

		

		const char* c=a2;
		int i=atoi(c);


		if(p.isRegistered(a,c))
		{
			secondchecker=1;
				
			publength=strlen(c);

			for(int z=0;z<strlen(c);z++)
				pubelement[z]=a2[z];



			pubelement[strlen(c)]='\0';


		}



		if(secondchecker==1)
			break;


	}
	if(secondchecker==0)
		return false;


	int titlelength=0;

	int pubstart=3+alength+publength;

	for(int run=0;run<(12-pubstart);run++)
	{
		telement[run]=ostring[pubstart+run];
			titlelength++;
	}

	telement[titlelength]='\0';

	for(int run=0;run<alength;run++)
		areae[run]=aelement[run];

	for(int run=0;run<publength;run++)
		publisher[run]=pubelement[run];

	for(int run=0;run<titlelength;run++)
		title[run]=telement[run];

	areae[alength]='\0';
	publisher[publength]='\0';
	title[titlelength]='\0';
	

	return true;


}


bool EAN::isRegistered() const 
{
	return registered;



}

void EAN::toStr(char* str) const

{
	if(str !=nullptr)
	{
		for(int run=0;run<strlen(ostring);run++)
			str[run]=ostring[run];
		str[strlen(ostring)]='\0';

	}


}

void EAN::toStrWithStyle(char* str) const
{

	//cout<<"1)formatted in toStrWithStyle"<<formatted<<endl;	

 	if(str !=nullptr)
	{
		for(int run=0;run<17;run++)
			str[run]=formatted[run];
		str[strlen(formatted)]='\0';
	}

	//cout<<"2)formatted in toStrWIthStyle:"<<formatted<<endl;

}


void EAN::style(char option)
{
	if((option=='-' || option==' ') && registered)
	{		
		if(option=='-')

	

		{
			
			formatted[0]='\0';
			char temp[18]={};
			strcat(temp,"9");
			strcat(temp,"7");
			temp[2]=ostring[2];			
			strcat(temp,"-");
			strcat(temp,areae);
			strcat(temp,"-");
			strcat(temp,publisher);
			strcat(temp,"-");
			strcat(temp,title);
			strcat(temp,"-");
			temp[16]=ostring[(strlen(ostring))-1];
			temp[17]='\0';	
			for(int run=0;run<17;run++)
				formatted[run]=temp[run];
			formatted[17]='\0';
			//cout<<endl;
			
			/*
			formatted[0]='\0';
			//char temp[18]={};
			strcat((char*)formatted,"9");
			strcat((char*)formatted,"7");
			formatted[2]=ostring[2];			
			strcat((char*)formatted,"-");
			strcat((char*)formatted,areae);
			strcat((char*)formatted,"-");
			strcat((char*)formatted,publisher);
			strcat((char*)formatted,"-");
			strcat((char*)formatted,title);
			strcat((char*)formatted,"-");
			formatted[16]=ostring[(strlen(ostring))-1];
			//temp[17]='\0';	
			//for(int run=0;run<17;run++)
				//formatted[run]=temp[run];
			formatted[17]='\0';
			*/
		}			
		else
		{
				
		
			formatted[0]='\0';
			char temp[18]={};
			strcat(temp,"9");
			strcat(temp,"7");
			temp[2]=ostring[2];			
			strcat(temp," ");
			strcat(temp,areae);
			strcat(temp," ");
			strcat(temp,publisher);
			strcat(temp," ");
			strcat(temp,title);
			strcat(temp," ");
			temp[16]=ostring[(strlen(ostring))-1];
			temp[17]='\0';	
			for(int run=0;run<17;run++)
				formatted[run]=temp[run];
			formatted[17]='\0';					
			//cout<<endl;	
		

			
			/*
			formatted[0]='\0';
			//char temp[18]={};
			strcat((char*)formatted,"9");
			strcat((char*)formatted,"7");
			formatted[2]=ostring[2];			
			strcat((char*)formatted," ");
			strcat((char*)formatted,areae);
			strcat((char*)formatted," ");
			strcat((char*)formatted,publisher);
			strcat((char*)formatted," ");
			strcat((char*)formatted,title);
			strcat((char*)formatted," ");
			formatted[16]=ostring[(strlen(ostring))-1];
			//temp[17]='\0';	
			//for(int run=0;run<17;run++)
				//formatted[run]=temp[run];
			formatted[17]='\0';
			cout<<"formatted in funtion blank:"<<formatted<<endl;	
			*/
		}			

	
	}	

	else
		if(!(registered))
			{
				for(int run=0;run<13;run++)
					formatted[run]=ostring[run];
				formatted[13]='\0';
			}

	if(option=='\0')
	{
	
		for(int run=0;run<strlen(ostring);run++)
			formatted[run]=ostring[run];
		formatted[strlen(ostring)]='\0';		
					
	}

}

bool EAN::empty() const{

	if(strlen(ostring)==0)
		return true;

	else
		return false;

}

void EAN::display(std::ostream& os) const
{
	os<<formatted;

}

bool EAN::read(std::istream& is,const Prefix& list) 
{

	const char* checker;
        
	cout<<"Enter a valid EAN:";	
	is>>initial;
	
	checker=initial;	

	

	
	while(!(isValid(checker)))
	{	
		initial[0]='\0';
		cout<<"Ivnvalid EAN. Try again or enter 0 to quit"<<endl;
		cout<<"EAN:";
		is>>initial;
		checker=initial;
		if(strcmp(checker,"0")==0)
		{
			//ostring="";
			//formatted[0]='\0';
			//registered=false;
			return false;
		}
		
	}
	
			
	
	

				
	ostring=initial;	
	l=(Prefix*) malloc (sizeof(*l)+1);

	*l=list;
         if(isRegistered(*l))
	{
		registered=true;
		style('-');
			
        }
		
	else
	{
		registered=false;
						
		for(int run=0;run<13;run++)
			formatted[run]=ostring[run];
			
					
		formatted[13]='\0';

	}		
	
	return true;
}


bool operator==(const EAN& left, const EAN& right){

	//cout<<"left string:"<<left.ostring<<endl;
	//cout<<"right string:"<<right.ostring<<endl;
	//if(strcmp(left.ostring,right.ostring)==0)
	if(strcmp(right.ostring,left.ostring)==0)	
	{
	//cout<<"left ostring:"<<left.ostring<<endl;
	//cout<<"right ostring:"<<right.ostring<<endl;
	return true;
	}
	else
  		return false;


}

std::ostream& operator<<(std::ostream& os, const EAN& ean){

	ean.display(os);
	
	return os;


}


/*
main(){


	char f3[14]="";


	const char* q="9789070002046";
	
	const char* f="filename";

	Prefix p(f);

	EAN e(q,p);

	e.style(' ');

	e.toStrWithStyle(f3);


	cout<<(cout,e)<<endl;

}
*	
	const char* q1="9789070002046";

	const char* f1="filename";
	
	EAN e1(q1,f1);

	if(e==e1)
		cout<<"true"<<endl;

	else

		cout<<"false"<<endl;

	cout<<(cout,e1)<<endl;
}

	

	

	const char* q="9789070002046";
	
	const char* f="filename";

	Prefix p(f);

	EAN e(q,p);
	
	char f1[14]="";
	char f2[14]="";
	char f3[14]="";


	//e.display(std::cout);
	//cout<<endl;

	e.toStr(f1);
	
	e.toStrWithStyle(f2);
	
	e.style(' ');
	e.toStrWithStyle(f3);
	//cout<<flush;
		cout<<"str: "<<f1<<endl;
	
	cout<<"style dash: "<<f2<<endl;
	
	cout<<"style blank:"<<f3<<endl;

	//e.display(std::cout);
	//cout<<endl;
}	
*


	EAN e(q,p);


//	e.read(std::cin,p);
	
	//cout<<e.isRegistered()<<endl;

	char c[14]={};

	e.toStr(c);

	cout<<"Without style:";

	for(int run=0;run<13;run++)
		cout<<c[run];

	cout<<endl;

	char cs[19]={};

	e.toStrWithStyle(cs);

	cout<<"With default style:"<<cs<<endl;

	e.style(' ');

	char bs[18]={};

	e.toStrWithStyle(bs);

	cout<<"With new style:"<<bs<<endl;

        std::cout<<"Formatted in display:";

        e.display(std::cout);

	cout<<endl;


}	
*/




















