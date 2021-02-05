/******************PROJECT ON UNUSED FOOD MANAGEMENT************
*********BY- ANSH ANURAG(2K20/B2/71) AND ANKIT NAIN(2K20/B2/64)**********
**************************************************************/



//****************** HEADER FILES**********************
#include<stdlib.h>
#include<fstream.h>
#include<iostream.h>
#include<process.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdio.h>
#include<dos.h>
//****************** GLOBAL VARIABLES *****************
int total=0,quantity[6]={0,0,0,0,0,0};

//******************FUNCTION PROTOTYPES****************
void loading_scr();
void readfrom();
void readrestau();
void screen();
void employee_info();
void createNGO();
void NGOMenu();

//******************STRUCTURES USED********************


	//-------- STRUCTURE OF NGO MENU ------------------

struct Nmenu
{
	char code[3];
	char name[20],Adress[50];
	int Amountkg;
}Nout,Nin;


//**********************************************************************




/****************************************************
*********************CLASSES USED********************
*****************************************************/


	//------- CLASS OF DISPLAY MENU ----------

class dp_menu
{
	public:

	void modSmenu();
	void NGOMenu();
	void modNmenu();
};




	//------- CLASS OF EMPLOYEE ------------------

class employee
{
	int e_id;
	char e_name[25],e_address[35];
	unsigned long int e_ph_no;
	int e_jyear;

	public:

	employee()
	{
		e_id=0;
		strcpy(e_name,"NULL");
		strcpy(e_address,"NULL");
		e_ph_no=0;
		e_jyear=0;
	}

	void password();
	void e_menu();
	void e_search();
	void e_modify();
	void e_delete();
	void e_append();
	void e_show();
	int e_get_id();
	int e_getinfo();

}e,etemp;




	//-------- CLASS OF restau ---------------

class restau
{
	char c_address[35],c_name1[20],c_name2[20],c_id[20];
	unsigned long int c_ph_no;


	public:
	char c_name[25], c_pass1[5];
	void c_login();
	void c_append();
	void c_show();



}c,ctemp;
//*********************************************************************

void marquee_effect(char s[], int speed)
{
	int x,y,i,l, left;
	l = strlen(s);
	left = (80-(l+(l/2)));
	y = wherey();
	do
	{
		for(x=0;x<left;x++)
		{
			gotoxy(x-1,y);
			clreol();
			gotoxy(x,y);
			cout<<s;
			delay(170-speed);
		}
	}
	while(!kbhit);

}



/*******************************************************************
***************** FUNCTIONS RELATED TO FOODITEMS ********************
*******************************************************************/



	//----------- FUNCTION TO CREATE NGO MENU ---------------

void createNGO()
{
	ofstream fout("NGO.dat",ios::binary);

	strcpy(Nout.code,"P1");
	strcpy(Nout.name,"CRY");
	Nout.Amountkg=15;
	strcpy(Nout.Adress,"Connaught Place, Delhi");
	fout.write((char*)&Nout,sizeof(Nout));

	strcpy(Nout.code,"P2");
	strcpy(Nout.name,"RHA");
	Nout.Amountkg=25;
	strcpy(Nout.Adress,"Sector 12 Noida");
	fout.write((char*)&Nout,sizeof(Nout));

	strcpy(Nout.code,"P3");
	strcpy(Nout.name,"Bhojan");
	Nout.Amountkg=20;
	strcpy(Nout.Adress,"Mundka Industrial Area, Delhi");
	fout.write((char*)&Nout,sizeof(Nout));

	strcpy(Nout.code,"P4");
	strcpy(Nout.name,"Lifebring");
	Nout.Amountkg=10;
	strcpy(Nout.Adress,"Patparganj Indus. area, Delhi");
	fout.write((char*)&Nout,sizeof(Nout));

	strcpy(Nout.code,"P5");
	strcpy(Nout.name,"EatDel");
	Nout.Amountkg=20;
	strcpy(Nout.Adress,"Chanakyapuri, Delhi");
	fout.write((char*)&Nout,sizeof(Nout));

	strcpy(Nout.code,"P6");
	strcpy(Nout.name,"YouWeCan");
	Nout.Amountkg=300;
	strcpy(Nout.Adress,"M Block,GK 1,Delhi");
	fout.write((char*)&Nout,sizeof(Nout));

	fout.close();
 }


//-----------------------INVOICE FUNCTION------------------


 void bill()
 {
	 clrscr();

	ifstream fin("NGO.dat",ios::binary);

	gotoxy(38,1);
	cout<<"INVOICE";
	gotoxy(36,3);
	cout<<"NGOS";
	gotoxy(3,5);
	cout<<"CODE";
	gotoxy(10,5);
	cout<<"NAME";
	gotoxy(35,5);
	cout<<"MIN AMT";
	gotoxy(71,5);
	cout<<"AMOUNT(kg)";



	fin.read((char*)&Nin,sizeof(Nin));
	if(quantity[0]!=0)
	{
		gotoxy(3,7);
		cout<<Nin.code;
		gotoxy(10,7);
		cout<<Nin.name;
		gotoxy(30,7);
		cout<<Nin.Amountkg;
		gotoxy(73,7);
		cout<<quantity[0];

		total+=quantity[0];
	}

	fin.read((char*)&Nin,sizeof(Nin));
	if(quantity[1]!=0)
	{
		gotoxy(3,9);
		cout<<Nin.code;
		gotoxy(10,9);
		cout<<Nin.name;
		gotoxy(30,9);
		cout<<Nin.Amountkg;
		gotoxy(73,9);
		cout<<quantity[1];

		total+=quantity[1];
	}

	fin.read((char*)&Nin,sizeof(Nin));
	if(quantity[2]!=0)
	{
		gotoxy(3,11);
		cout<<Nin.code;
		gotoxy(10,11);
		cout<<Nin.name;
		gotoxy(30,11);
		cout<<Nin.Amountkg;
		gotoxy(73,11);
		cout<<quantity[2];

		total+=quantity[2];
	}


	fin.read((char*)&Nin,sizeof(Nin));
	if(quantity[3]!=0)
	{
		gotoxy(3,13);
		cout<<Nin.code;
		gotoxy(10,13);
		cout<<Nin.name;
		gotoxy(30,13);
		cout<<quantity[3];
		gotoxy(73,13);
		cout<<quantity[3];

		total+=quantity[3];
	}


	fin.read((char*)&Nin,sizeof(Nin));
	if(quantity[4]!=0)
	{
		gotoxy(3,15);
		cout<<Nin.code;
		gotoxy(10,15);
		cout<<Nin.name;
		gotoxy(30,15);
		cout<<Nin.Amountkg;
		gotoxy(73,15);
		cout<<quantity[4];

		total+=quantity[4];
	}


	fin.read((char*)&Nin,sizeof(Nin));
	if(quantity[5]!=0)
	{
		gotoxy(3,17);
		cout<<Nin.code;
		gotoxy(10,17);
		cout<<Nin.name;
		gotoxy(30,17);
		cout<<Nin.Amountkg;
		gotoxy(73,17);
		cout<<Nin.Amountkg*quantity[5];

		total+=Nin.Amountkg*quantity[5];
	}

	fin.close();
	getch();

	gotoxy(3,19);
	cout<<"TOTAL FOOD CONTRIBUTED(kg) :"<<total;
	getch();
	clrscr();
	cout<<"\n\n\n\t\t\tTHANK YOU FOR ORDERING!";
	cout<<"\n\n\n\n\t\t\tVISIT AGAIN!";
	getch();
	screen();

 }


//-------------------------NGO MENU-------------------------



 void NGOMenu()
{

	ifstream fin("NGO.dat",ios::binary);

	gotoxy(38,1);
	cout<<"MENU";
	gotoxy(36,3);
	cout<<"NGOS";
	gotoxy(3,5);
	cout<<"CODE";
	gotoxy(10,5);
	cout<<"NAME";
	gotoxy(35,5);
	cout<<"Adress";
	gotoxy(71,5);
	cout<<"Amountkg(Rs)";

	fin.read((char*)&Nin,sizeof(Nin));
	gotoxy(3,7);
	cout<<Nin.code;
	gotoxy(10,7);
	cout<<Nin.name;
	gotoxy(27,7);
	cout<<Nin.Adress;
	gotoxy(73,7);
	cout<<Nin.Amountkg;

	fin.read((char*)&Nin,sizeof(Nin));
	gotoxy(3,9);
	cout<<Nin.code;
	gotoxy(10,9);
	cout<<Nin.name;
	gotoxy(27,9);
	cout<<Nin.Adress;
	gotoxy(73,9);
	cout<<Nin.Amountkg;
	gotoxy(3,11);

	fin.read((char*)&Nin,sizeof(Nin));
	cout<<Nin.code;
	gotoxy(10,11);
	cout<<Nin.name;
	gotoxy(27,11);
	cout<<Nin.Adress;
	gotoxy(73,11);
	cout<<Nin.Amountkg;

	fin.read((char*)&Nin,sizeof(Nin));
	gotoxy(3,13);
	cout<<Nin.code;
	gotoxy(10,13);
	cout<<Nin.name;
	gotoxy(27,13);
	cout<<Nin.Adress;
	gotoxy(73,13);
	cout<<Nin.Amountkg;

	fin.read((char*)&Nin,sizeof(Nin));
	gotoxy(3,15);
	cout<<Nin.code;
	gotoxy(10,15);
	cout<<Nin.name;
	gotoxy(27,15);
	cout<<Nin.Adress;
	gotoxy(73,15);
	cout<<Nin.Amountkg;

	fin.read((char*)&Nin,sizeof(Nin));
	gotoxy(3,17);
	cout<<Nin.code;
	gotoxy(10,17);
	cout<<Nin.name;
	gotoxy(27,17);
	cout<<Nin.Adress;
	gotoxy(73,17);
	cout<<Nin.Amountkg;


	char ch,order[5];

	do{
		cout<<"\n\n\t\t**********CALL YOUR NGO*******************\n";

		cout<<"\nWant to Call NGO<Y/N>";
		cin>>ch;
		cout<<"\n\nEnter the NGO code: ";
		cin>>order;
		int temp;
		if(!strcmpi(order,"P1"))
		{
			cout<<"\nEnter the quantity: ";
			cin>>temp;
			quantity[0]+=temp;

		}

		else if(!strcmpi(order,"P2"))
		{
			cout<<"\nEnter the quantity: ";
			cin>>quantity[1];
			cin>>temp;
			quantity[1]+=temp;

		}

		else if(!strcmpi(order,"P3") )
		 {
			cout<<"\nEnter the quantity: ";
			cin>>temp;
			quantity[2]+=temp;

		 }

		else if(!strcmpi(order,"P4"))
		 {
			cout<<"\nEnter the quantity: ";
			cin>>temp;
			quantity[3]+=temp;

		 }

		else if(!strcmpi(order,"P5"))
		 {
			cout<<"\nEnter the quantity: ";
			cin>>temp;
			quantity[4]+=temp;
		 }

		 else if(!strcmpi(order,"P6"))
		  {
			cout<<"\nEnter the quantity: ";
			cin>>temp;
			quantity[5]+=temp;

		  }

		  else
			cout<<"\nWRONG INPUT!!";

		  cout<<"DO YOU WANT TO CONTRIBUTE MORE?(y/n)"<<endl;
		  cin>>ch;

	}while(ch=='Y'||ch=='y');

	bill();
	fin.close();
	getch();
	clrscr();

}



	//-----------FUNCTION TO MODIFY NGO MENU -------------

void dp_menu::modNmenu()
{
	int flag;
	long pos;
	char ch,code[3];
	Nmenu pio;

	fstream fio("NGO.dat",ios::in|ios::out|ios::binary);

	do
	{
		flag=0;
		fio.seekg(0);
		cout<<"Enter the product code: ";
		cin>>code;

		while(!fio.eof())
		{

			pos=fio.tellg();
			fio.read((char*)&pio,sizeof(pio));
			if(strcmpi(code,pio.code)==0)
			{
				flag=1;

				break;
			}
		}
		if(flag)
		{
			cout<<"\n\nEnter the new Amount(kg): ";
			cin>>pio.Amountkg;
			fio.seekg(pos);
			fio.write((char*)&pio,sizeof(pio));
		}

		cout<<"Do you want modify more(y/n): ";
		cin>>ch;
	}while(ch=='Y'||ch=='y');

	fio.close();

}



//-------------- FUNCTION TO DISPLAY NGO MENU -----------------

void dp_menu::NGOMenu()
{
	char ch;
	ifstream fin("NGO.dat",ios::binary);

	gotoxy(38,1);
	cout<<"MENU";
	gotoxy(36,3);
	cout<<"NGO";
	gotoxy(3,5);
	cout<<"CODE";
	gotoxy(10,5);
	cout<<"NAME";
	gotoxy(35,5);
	cout<<"Adress";
	gotoxy(71,5);
	cout<<"Min Amount(kg)";

	fin.read((char*)&Nin,sizeof(Nin));
	gotoxy(3,7);
	cout<<Nin.code;
	gotoxy(10,7);
	cout<<Nin.name;
	gotoxy(27,7);
	cout<<Nin.Adress;
	gotoxy(73,7);
	cout<<Nin.Amountkg;

	fin.read((char*)&Nin,sizeof(Nin));
	gotoxy(3,9);
	cout<<Nin.code;
	gotoxy(10,9);
	cout<<Nin.name;
	gotoxy(27,9);
	cout<<Nin.Adress;
	gotoxy(73,9);
	cout<<Nin.Amountkg;
	gotoxy(3,11);

	fin.read((char*)&Nin,sizeof(Nin));
	cout<<Nin.code;
	gotoxy(10,11);
	cout<<Nin.name;
	gotoxy(27,11);
	cout<<Nin.Adress;
	gotoxy(73,11);
	cout<<Nin.Amountkg;

	fin.read((char*)&Nin,sizeof(Nin));
	gotoxy(3,13);
	cout<<Nin.code;
	gotoxy(10,13);
	cout<<Nin.name;
	gotoxy(27,13);
	cout<<Nin.Adress;
	gotoxy(73,13);
	cout<<Nin.Amountkg;

	fin.read((char*)&Nin,sizeof(Nin));
	gotoxy(3,15);
	cout<<Nin.code;
	gotoxy(10,15);
	cout<<Nin.name;
	gotoxy(27,15);
	cout<<Nin.Adress;
	gotoxy(73,15);
	cout<<Nin.Amountkg;

	fin.read((char*)&Nin,sizeof(Nin));
	gotoxy(3,17);
	cout<<Nin.code;
	gotoxy(10,17);
	cout<<Nin.name;
	gotoxy(27,17);
	cout<<Nin.Adress;
	gotoxy(73,17);
	cout<<Nin.Amountkg;

	cout<<"\n\n DO YOU WANT TO MODIFY THE MENU: ";
	cin>>ch;
	if(ch=='Y'||ch=='y')
		{
			modNmenu();
			clrscr();
			NGOMenu();
		}

	getch();


	fin.close();

	clrscr();
}



	

	
		//FUNCTION2


//*************************************************************
/***************************************************************
********************** FUNCTIONS RELATED TO EMPLOYEE******************
*********************************************************************/



	//----------- FUNCTION FOR EMPLOYEE LOGIN --------------------

void employee::password()
{
	char ch,c,pw[40];
	clrscr();


	int i=0;

	cout<<"\n\t\t\tENTER PASSWORD: ";

	for(i=0;i!='\r';i++)
	{
		c=getch();

		if(c==13)
		{
			pw[i]='\0';
			break;

		}

		else if(c!='\b')
		{
			cout<<"*";
			pw[i]=c;
		}

		else
		{
			i=i-2;
			cout<<"\b \b";

		}
	}//end of forloop
	pw[i]='\0';

	if(strcmp("shiv",pw)==0)    	 //**condition to check password**
	{
	       e.e_menu();
	}

	else
	{

		clrscr();
		cout<<"\n\t\t\t\tWRONG PASSWORD! ACCESS DENIED!!!";
		getch();
		screen();

	}
}



	//----------FUNCTION TO DISPLAY EMPLOYEE MENU ----------------

void employee :: e_menu()
{
	clrscr();

	dp_menu dp_m ;
	int em_choice;
	char ch;

	cout<<"\n\n\t\t\t\t\t\tMENU";
	cout<<"\n\n\t\t\tPRESS 1:  CHANGE MENU";
	cout<<"\n\n\t\t\tPRESS 2:  EMPLOYEE INFORMATION";
	cout<<"\n\t\t\tPRESS 3: RETURN TO MAIN MENU";
	do
	{

		cout<<"\n\n\n\n\t\t\tENTER YOUR CHOICE: ";
		cin>>em_choice;

		if(em_choice==1)
		{
			clrscr();
			dp_m.NGOMenu();
		}

		else if(em_choice==2)
		{
			employee_info();
		}
		else if(em_choice==3)
		{
			screen();
		}
		else
		{
			cout<<"\n\t\tWRONG CHOICE!!CHOOSE AGAIN!";
			cout<<"\n\t\tCHOOSE AGAIN: ";
			cin>>ch;
		}
       }while(ch=='y' || ch=='Y'); //end of do-while loop
}


	//--------- FUNCTION TO ACCESS & CHANGE EMPLOYEE INFO -------

void employee_info()
{
	clrscr();
	int ei_choice;
	char ch;

	cout<<"\n\n\t\tPRESS 1: SEARCH EMPLOYEE'S INFORMATION";
	cout<<"\n\t\tPRESS 2: DELETE EMPLOYEE'S INFORMATION";
	cout<<"\n\t\tPRESS 3: MODIFY EMPLOYEE'S INFORMATION";
	cout<<"\n\t\tPRESS 4: ADD EMPLOYEE'S INFORMATION";
	cout<<"\n\t\tPRESS 5: DISPLAY EMPLOYEE'S LIST";
	cout<<"\n\t\tPRESS 6: DISPLAY restau'S LIST";
	cout<<"\n\t\tPRESS 7: RETURN TO EMPLOYEE'S MENU";
	cout<<"\n\t\tPRESS 8: RETURN TO MAIN MENU";
	do
	{
		cout<<"\n\n\n\n\t\tENTER YOUR CHOICE: ";
		cin>>ei_choice;

		switch(ei_choice)
		{
			case 1:		e.e_search();
					break;

			case 2:		e.e_delete();
					break;

			case 3:         e.e_modify();
					break;

			case 4:         e.e_append();
					break;

			case 5:		readfrom();
					break;

			case 6:         readrestau();
					break;

			case 7:         e.e_menu();
					break;

			case 8:		screen();
					break;

			default:	cout<<"\n\t\tWRONG CHOICE!!CHOOSE AGAIN!";
					cout<<"\n\t\tENTER YOUR CHOICE: ";
					cin>>ch;
					break;
		}//end of switch
	}while(ch=='y'|| ch=='Y');//end of do-while loop

}

	//------------ FUNCTION TO GET EMPLOYEE ID -------------------


int employee :: e_get_id()
{
	return e_id;
}



	//------------ FUNCTION TO INPUT EMPLOYEE INFO ----------------

int employee::e_getinfo()
{

	char c;
	employee e1;
	randomize();
	ifstream fin;
	fin.open("employee.dat",ios::binary);
	do
	{
		e_id=random(49)+1;
		fin.read((char*)&e1,sizeof(e1));
	}while(e_id==e1.e_get_id());

	cout<<"\t\t\tEMPLOYEE'S ID NUMBER: "<<e_id;


	getch();

	cout<<"\n\t\t\tEMPLOYEE'S RECORD INPUT";
	cout<<"\n\t\t\tENTER EMPLOYEE'S NAME: ";
	gets(e_name);

	cout<<"\t\t\tENTER EMPLOYEE'S ADDRESS: ";
	gets(e_address);
	cout<<"\t\t\tENTER EMPLOYEE'S PHONE NUMBER: ";
	cin>>e_ph_no;
	cout<<"\t\t\tENTER EMPLOYEE'S JOINING YEAR: ";
	cin>>e_jyear;


	fin.close();
	return 0  ;

}



	//---------- FUNCTION TO READ BINARY FILE NAMED EMPLOYEE ----------

void readfrom()
{
	clrscr();

	ifstream rf;
	rf.open("employee.dat",ios::binary);
	if (!rf)
	{
		exit(1);
	}
	employee e;

	while(!rf.eof())
	{
	      rf.read((char*)&e,sizeof(e));
	      if(!rf.good())
	      {
			break;
	      }

	      e.e_show();


	}
	rf.close();


	employee_info();
	getch();

}


	//------------- FUNCTION TO SEARCH EMPLOYEE INFO --------------

void employee :: e_search()
{
	clrscr();
	employee e;
	int input;
	cout<<"\nENTER THE EMPLOYEE ID: ";
	cin>>input;

	ifstream es;
	es.open("employee.dat",ios::binary);
	if(!es)
	{
		cout<<"\nCAN'T OPEN FILE";
		exit(1);
	}

	while(!es.eof())
	{
		es.read((char*)&e,sizeof(e));
		if(input==e.e_get_id())
		{
			e.e_show();
			break;
		}
	}


	if(es.eof())
	{
		cout<<"\nRECORD OF EMPLOYEE WITH SUCH ID NUMBER DOESN'T EXISTS";
	}
	es.close();
	getch();

	employee_info();


}



	//------------- FUNCTION TO DELETE EMPLOYEE INFO -------------

void employee :: e_delete()
{
	employee e;
	ifstream edi;
	ofstream edo;

	clrscr();
	int input;
	int flag=0;

	edi.open("employee.dat", ios::binary);
	edo.open("temp.dat",ios::binary);

	cout<<"\n\t\t\tENTER THE EMPLOYEE'S ID NUMBER: ";
	cin>>input;

	while(!edi.eof())
	{
		edi.read((char*)&e,sizeof(e));
		if(!edi.good())
		{
			break;
		}

		if(input!=e.e_get_id())
		{

			edo.write((char*)&e,sizeof(e));
		}

		else
		{
			flag=1;
		}
	}
	edo.close();
	edi.close();

	if(flag==0)
	{
		cout<<"\nRECORD OF EMPLOYEE WITH SUCH ID NUMBER DOESN'T EXISTS";
	}

		remove("employee.dat");
		rename("temp.dat","employee.dat");


	getch();
	employee_info();
}



	//------------ FUNCTION TO MODIFY EMPLOYEE INFO -----------------

void employee :: e_modify()
{
	fstream em;
	clrscr();
	em.open("employee.dat",ios::binary|ios::in|ios::out);

	int id,pos,flag=0;
	cout<<"\n\t\t\tENTER THE EMPLOYEE'S ID NUMBER: ";
	cin>>id;

	while(!em.eof())
	{
		pos=em.tellg();

		em.read((char*)&e,sizeof(e));

		if(!em.good())
		break;

		if(id==e.e_get_id())
		{
			e.e_show();

			cout<<"\n\n\t\t\tEMPLOYEE'S RECORD INPUT";
			cout<<"\n\t\t\tENTER EMPLOYEE'S NAME: ";
			gets(e_name);

			cout<<"\t\t\tENTER EMPLOYEE'S ADDRESS: ";
			gets(e_address);
			cout<<"\t\t\tENTER EMPLOYEE'S PHONE NUMBER: ";
			cin>>e_ph_no;
			cout<<"\t\t\tENTER EMPLOYEE'S JOINING YEAR: "<<e_jyear;

			em.seekg(pos);
			em.write((char*)&e,sizeof(e));
			break;

		}
		else
		{
			cout<<"\nNO SUCH USER EXISTS!";
			flag=1;
		}
	}
	if(flag==1)
	{
		cout<<"\nRECORD OF EMPLOYEE WITH SUCH ID NUMBER DOESN'T EXISTS!"<<endl;
	}

	em.close();
	employee_info();

}



	//---------- FUNCTION TO ADD EMPLOYEE INFO ------------------

void employee :: e_append()
{
	clrscr();
	int flag=0;
	ofstream ea;
	ea.open("employee.dat",ios::binary|ios::app);

	char ch='y';
	while(ch=='y')
	{
		flag=e.e_getinfo();
		clrscr();
		if(!flag)
		{
			ea.write((char*)&e,sizeof(e));
		}

		cout<<"\n\t\tDO YOU WANT TO ENTER MORE(Y/N)??";
		cin>>ch;
	}
	ea.close();
	employee_info();

}



	//------------ FUNCTION TO DISPLAY EMPLOYEE INFO ---------------

void employee::e_show()
{

	cout<<"\n\n\t\t\t\tEMPLOYEE'S RECORD";
	cout<<"\n\t\tNAME : "<<e_name;
	cout<<"\n\t\tID : "<<e_id;
	cout<<"\n\t\tADDRESS : "<<e_address;
	cout<<"\n\t\tPHONE NUMBER :"<<e_ph_no;
	cout<<"\n\t\tJOINING YEAR :"<<e_jyear;
	getch();

}


//***********************************************************************




/*********************************************************************
**********************  FUNCTIONS RELATED TO restau******************
*********************************************************************/


	//------------ FUNCTION TO DISPLAY restau INFO ---------------

void restau::c_show()
{

	cout<<"\n\n\t\t\t\tRESTAURANT/ORGANISER'S RECORD";
	cout<<"\n\t\tNAME OF THE ENTERPRISE: "<<c_name1;
	cout<<"\n\t\tMANAGER NAME : "<<c_name2;
	cout<<"\n\t\tADDRESS : "<<c_address;
	cout<<"\n\t\tPHONE NUMBER :"<<c_ph_no;
	cout<<"\n\t\tEMAIL ID :"<<c_id;
	cout<<"\n\t\tUSERNAME :"<<c_name;
	getch();

}



	//---------- FUNCTION TO READ BINARY FILE NAMED EMPLOYEE ----------

void readrestau()
{
	clrscr();

	ifstream rc;
	rc.open("restau.dat",ios::binary);
	if (!rc)
	{
		exit(1);
	}
	restau c;

	while(!rc.eof())
	{
	      rc.read((char*)&c,sizeof(c));
	      if(!rc.good())
	      {
			break;
	      }

	      c.c_show();


	}
	rc.close();


	employee_info();
	getch();

}

	  //----------FUNCTION OF restau LOGIN--------
void restau::c_login()
{
clrscr();
int ch,ch1,flag=0;
char pass[5],uname[30];

while(1)
{
	cout<<"\n\n\t\t\t1>NEW USER";
	cout<<"\n\n\t\t\t2>OLD USER";
	cout<<"\n\n\t\t\t3>RETURN TO MAIN MENU";
	cout<<"\n\n\n\t\tENTER YOUR CHOICE: ";
	cin>>ch;

	clrscr();

	switch(ch)
	{
		case 1:
			c_append();
			break;

		case 2:
			cout<<"\n\n\t\t\t USERNAME: ";
			cin>>uname;

			ifstream fin;
			fin.open("restau.dat",ios::binary);
			if(!fin)
			{
				cout<<"\n\t\tNO SUCH USER EXISTS";


			}
			while(!fin.eof())
			{
				fin.read((char*)&ctemp,sizeof(ctemp));
				if(!strcmp(uname,ctemp.c_name))
				{

					flag=1;
					break;
				}
			}//end of whileloop
			cout<<"\nNAME ->"<<ctemp.c_name;

			fin.close();


			if(flag)
			{

				cout<<"\n\t\t\t PASSWORD: ";

				char ch,c1,pw[10];

				for(int i=0;i<5;i++)
				{
					c1=getch();

					if(c1==13)
					{
						pw[i]='\0';
						break;

					}

					else if(c1!='\b')
					{
						cout<<"*";
						pw[i]=c1;
					}

					else
					{
						i=i-2;
						cout<<"\b \b";

					}
				}//end of forloop
				pw[i]='\0';
				strcpy(pw,pass);

				if(!strcmp(pass,ctemp.c_pass1))
				{
					while(1)
					{
						clrscr();
						cout<<"\n\n\t\t\tWELCOME , "<<c_name1;
						cout<<"\n\n\t\t\t1> LIST OF NGOs";
						cout<<"\n\t\t\t2>RETURN TO MAIN MENU ";
						cout<<"\nENTER YOUR CHOICE: ";
						cin>>ch1;


						switch(ch1)
						{
							case 1 :
								clrscr();
								NGOMenu();
								break;

							case 2:
								screen();
								break;

							default :
								clrscr();
								cout<<"\n\t\tWRONG INPUT PLEASE ENTER VALID NUMBER " ;
						}

					}//end of whileloop

				}
				else
				{
					cout<<"\n\t\t\tWRONG PASSWORD";
					getch();
				}
			}

			else
			{
				cout<<"\n\t\tNO SUCH USER EXISTS";

			}
			break;
		case 3:
			screen();
			break;

		default:
			cout<<"WRONG INPUT PLEASE ENTER VALID INPUT";
			break;
	}
}//end of while loop
}


	   //-------------FUNCTION TO ADD NEW restau---------

void restau::c_append()
{
	clrscr();
	int ch2;
	cout<<"\n\n\t\t\tRESTAURANT/ORGANISATION NAME:";
	cin>>c_name1;
	cout<<"\n\t\t\tMANAGER NAME:";
	cin>> c_name2;
	cout<<"\n\t\t\tADDRESS:";
	gets(c_address);
	cout<<"\n\t\t\tPHONE NUMBER:";
	cin>>c_ph_no;
	cout<<"\n\t\t\tEMAIL ID:";
	cin>>c_id;
	cout<<"\n\t\t\tUSERNAME: ";
	cin>>c_name;

	cout<<"\n\t\t\tPASSWORD( ATMOST 4 LETTERS ): ";

		char ch,c1,pw[10];

	for(int i=0;i<5;i++)
	{
		c1=getch();

		if(c1==13)
		{
			pw[i]='\0';
			break;

		}

		else if(c1!='\b')
		{
			cout<<"*";
			pw[i]=c1;
		}

		else
		{
			i=i-2;
			cout<<"\b \b";

		}
	}
	pw[i]='\0';
	strcpy(pw,c_pass1);

	ctemp=c;

	ofstream fout;
	fout.open("restau.dat",ios::binary|ios::app);

	fout.write((char*)&(ctemp),sizeof(ctemp));
	fout.close();

	clrscr();



	c_login();


}


void screen()
{
	clrscr();
	int s_choice;
	gotoxy(17,7);
	cout<<"WELCOME TO THE FEED ME APP";
	gotoxy(10,9);
	cout<<"1> NGO/FOUNDATIONS";
	gotoxy(10,11);
	cout<<"2> RESTAURANT/EVENT ORGANISER";
	gotoxy(10,13);
	cout<<"3> EXIT";
	gotoxy(9,17);
	cout<<"ENTER YOUR CHOICE: ";

	cin>>s_choice;
	while(1)
	{
		if(s_choice==1)
		{
		       e.password();
		}
		else if(s_choice==2)
		{
			c.c_login();
		}
		else if(s_choice==3)
		{
			exit(1);
		}
		else
		{
			cout<<"\nWRONG INPUT!!CHOOSE AGAIN";
		}
	}
}

//************************MAIN FUNCTION********************************
void main()
{
	clrscr();
	textcolor(GREEN);
	textbackground(0);
	loading_scr();
	clrscr();
	textbackground(12);
	textcolor(14);
	gotoxy(20,10);
	marquee_effect("FEED ME\n\n",60);
	marquee_effect("THE STEP TO CURE HUNGER AND FOOD WASTAGE",60);
			//LOGO PRINTING and use of delay to make sequential
	employee e;
	restau c;
	ifstream fin;
	fin.open("NGO.dat",ios::binary|ios::noreplace);
	if(!fin)
	{
		createNGO();
	}

	fin.close();																									screen();

	getch();
}

void loading_scr()                                 //LOADING SCREEN FUNCTION
{
	clrscr();
	textcolor(GREEN);
	int x=0;
//	cout<<endl<<"                            FEED ME"<<endl;
  //	  delay(150);
    //	cout<<"                     THE STEP TO CURE HUNGER AND FOOD WASTAGE";
      //	  delay(2500);
 //	clrscr();
			    //loader function using delay and gotoxy
	gotoxy(30,13);
	cout<<"LOADING...";

	for(int i=1; i<=10; i++)
	{
		gotoxy(30+x,14);
		delay(500);

		cout<<"__";
		x+=2;

		gotoxy(52,14);
		cout<<i*10<<"%";
	}

	gotoxy(35,17);
	cout<<"COMPLETE!";

	gotoxy(50,21);
	cout<<"PRESS ANY KEY TO CONTINUE";
	getch();
	clrscr();
}

//***************************** END *****************************
