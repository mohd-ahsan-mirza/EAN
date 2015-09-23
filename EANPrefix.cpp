
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>

using namespace std;

#include"GS1Prefix.h"


Prefix::Prefix(const char* filename)
{

	//area[]={};
	//pubLen[][]={};
	//pubLow[][]={};
	//pubHgh[][]={};	
	//pubLen[][]={};

     
     if (filename != nullptr) {
         std::ifstream file(filename);
         if (file.is_open()) {
	    int num = 0;
             while (file.good()) {  // version 1.2
                 file >> area[num] >> pubLow[num] >> pubHgh[num]; 
                 if (file.good()) {
                     pubLen[num] = strlen(pubLow[num]);
                     num++;
                 }
             }
             if (num > 0) {
                 no = num;
             }
         }
     }
     

}     

bool Prefix::isRegistered(int a) const{


	for(int x=0;x<no;x++)
		
	{
	
	
		if(area[x]==a)
		{
			return true;
		}
	}

	return false;

}




int Prefix::minNoDigits( int a) const
{
	for(int run=0;run<no;run++)
	{
		if(area[run]==a)
			return strlen(pubLow[run]);
	}
	return 0;

}


bool Prefix::isRegistered(int a,const char* publisher) const{



	if(!(isRegistered(a)))
		return false;

	if(minNoDigits(a)==1)
	{
			int index=0;

			while(!(area[index]==a)) {

				index++;
			}


		char ints[11][3]={"00","01","02","03","04","05","06","07","08","09"};


		do{
			int min=atoi(pubLow[index]);
			int max=atoi(pubHgh[index])+1;

			int quarry=atoi(publisher);

			for(int run=min;run<max;run++)
			{




				if(run==quarry)
					return true;


			}	



			index++;
	
		}while(area[index]==a);

		return false;

	}


	if(minNoDigits(a)==2)
	{

		int index=0;

		while(!(area[index]==a)) {

		index++;
		}

		char ints[11][3]={"00","01","02","03","04","05","06","07","08","09"};



		do{

			int min=atoi(pubLow[index]);
			int max=atoi(pubHgh[index])+1;

			int no = atoi(publisher);


			for(int run=min;run<max;run++)
			{

				if(run>=0 && run<10)
				{

					for(int x=0;x<10;x++)
					{

						if(strcmp(ints[x],publisher)==0)
						return true;

					}

				}	

				if(no==run && run>=10)
					return true;




			}		

			index++;
		
		}while(area[index]==a);


		return false;

	}



	if(minNoDigits(a)==3)
	{


		int index=0;

		while(!(area[index]==a)) {

			index++;
		}

		char ints[101][4]={};



		for(int run=0;run<101;run++)
		{

			ints[run][0]='0';

			int rem=run%10;
			int div=run/10;

			char sec=div+'0';

			char third=rem+'0';

			ints[run][1]=sec;
			ints[run][2]=third;



		}	


		do{


			int min=atoi(pubLow[index]);
			int max=atoi(pubHgh[index])+1;

			int no = atoi(publisher);


			for(int run=min;run<max;run++)
			{

				if(run>=0 && run<100)
				{

					for(int x=0;x<100;x++)
					{

						if(strcmp(ints[x],publisher)==0)
							return true;

					}

				}

				if(no==run && run>=100)
					return true;


			}

			index++;
		}while(area[index]==a);

		return false;



	}



}

int Prefix::total() const
{
	return no;

}



/*


main()
{

	const char *f="filename";

	Prefix p(f);

        const char* pub="70002";

	bool check=p.isRegistered(0);
        
        int t=p.total();

	cout<<check<<endl;

}

*/
