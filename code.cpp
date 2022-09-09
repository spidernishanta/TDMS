  #include<graphics.h>
  #include<fstream.h>
  #include<conio.h>
  #include<stdio.h>
  #include<string.h>
  #include<dos.h>
  #include<iomanip.h>
	 struct node //this structre will be maintain
	       // a dynamic index while sorting object
			 {
			 unsigned long recno;
			long int pin;
			char name[20];
			 node *link;//pointer to next node
			 } ;
	 node *first,*ptr1,*ptr2,*ptr,*temp;//pointers to node
	 class person
			 {
			private:
			 unsigned long record_id; //identification of record number
			 char person_name[20];
			 char res_address[30];
			 char date_of_birth[10];
			 long int res_pincode;
			 long int res_phone_no1;
			 long int res_phone_no2;
			 long int res_fax_no;
			 char occu_pation[10];
			 char company_name[20];
			 char off_address[20];
			 long int off_pincode;
			 long int off_phone_no1;
			 long int off_phone_no2;
			 long int off_fax_no;
			 long int E_mail_no;
			 char internet_address[25];
			 public:
			 person()//constructor to initialise long int variables
			 {
				record_id=0;
				 res_pincode=off_pincode=0;
				 res_phone_no1=res_phone_no2=0;
				 res_fax_no=off_fax_no=0;
				 off_phone_no1=off_phone_no2=0;
				 E_mail_no=0;
				 }
			 unsigned long get_rec_no();//this function generates record identification no
			 void get_data();//function to get the data from operator
			 void show_data();//this function prints data
			 void add_object();//function that creates a master file
			 void make_index();//function that maintains an index to sort various field
			 void sort_name();//function sorts name
			 void sort_recno();//function sorts record no
			 void sort_pin();//function sorts pincode
			 void show_object();//function prints all the object
			 void sort_print();//prints sorted object
			 void del_object();// function delete a object
			 void modify_object();//function to modify aobject
			 void search_object();//function to search object
			 void sort_object();//functiuon to sort a object
			 void reports();//this function generates object
				  }pers;//objectof type person
	  unsigned long person::get_rec_no()
	 {int found=0;
	 unsigned long rec_no;
	unsigned long temp_recno;
	 struct node1
	 {
	 unsigned long recno;
	 node1 *link;
	 };
	 node1 *start,*ptr,*ptr1,*ptr2;//pointer tonode1
		 fstream  infile;
		 infile.open("phoneno.dat",ios::in|ios::binary);
		 infile.seekg(0,ios::end);//set fil epointer to 0 byte
		int n=infile.tellg();
		infile.close();
		if(n==0)//if file is empty this  isthe first record
		rec_no=1;
		else//if file is not empty
			 {
			 infile.open("phoneno.dat",ios::in|ios::binary);
			 start=ptr=new node1;//get new node from operating system
			 infile.seekg(0,ios::beg);
			infile.read((char*)&pers,sizeof (pers));
			 while (!infile.eof())
				 {
				 ptr->recno=pers.record_id;//save record no
				 ptr->link=new node1;//get new code
				 ptr=ptr->link;
				 infile.read((char*)&pers,sizeof(pers));
				 } ptr->link=NULL;
				  infile.close();
				 ptr1=start;
	while(ptr1->link!=NULL)
	{
	ptr2=ptr1->link;
	 while(ptr2!=NULL)
	 {
	 if(ptr2->recno < ptr1->recno)
	 {
	 temp_recno=ptr2->recno;//save smaller value
	 ptr2->recno=ptr1->recno;
	 ptr1->recno=temp_recno;
	 }
	 ptr2=ptr2->link;
	 }
	 ptr2=ptr1->link;
	 ptr1=ptr2;
	 }
	 ptr1=start;
	 while(ptr1!=NULL&&found!=1)
	 {
	 ptr2=ptr1;
	 ptr1=ptr1->link;
	 if((ptr2->recno)+1!=ptr1->recno)
	 {
	 rec_no=(ptr2->recno)+1;//find missing record no
	 found=1;
	 }
	 }
	 if(found!=1)
	 rec_no=(ptr2->recno)+1;
	 while(start!=NULL)
	 {
	 ptr=start;
	start=start->link;//increment pointer
	delete ptr;
	 }
	 }
	 return rec_no;//send record no to the calling program
	 }
	 void person::get_data()
	{
	clrscr();
	record_id=pers.get_rec_no();//get record id no
	gotoxy(5,7);
	 cout<<"\n Enter the name                          >";
 gets(person_name);
 gotoxy(5,8);
 cout<<"\n Enter the date of birth<dd/mm/yyyy>        >";
 gets(date_of_birth);
 gotoxy(5,9);
 cout<<"\nEnter  residential address                  >";
 gets(res_address);
 gotoxy(5,10);
 cout<<"\nEnter the residential pin code              >";
 cin>>res_pincode;
 gotoxy(5,11);
 cout<<"\n Enter residential phone no1                >";
 cin>>res_phone_no1;
 gotoxy(5,12);
 cout<<"\nEnter residentila phone no2                 >";
 cin>>res_phone_no2;
 gotoxy(5,13);
 cout<<"\nEnter the residential fax no                >";
 cin>>res_fax_no;
 clrscr();
 gotoxy(5,7);
 cout<<"\nEnter the occupation                        >";
 gets(occu_pation);
 gotoxy(5,8);
 cout<<"\nEnter company name                          >";
 gets(company_name);
 gotoxy(5,9);
 cout<<"\nEnter company address                       >";
 gets(off_address);
 gotoxy(5,10);
 cout<<"\nEnter office pin code                      >";
 cin>>off_pincode;
 gotoxy(5,11);
 cout<<"\nEnter officephone no1                      >";
 cin>>off_phone_no1;
 gotoxy(5,12);
 cout<<"\nEnter office phone no2                     >";
 cin>>off_phone_no2;
 clrscr();
 gotoxy(5,7);
 cout<<"\nEnter the office fax no                   >";
 cin>>off_fax_no;
 gotoxy(5,8);
 cout<<"\nEnter e-mail ID                             > ";
 cin>>E_mail_no;
 gotoxy(5,9);
 cout<<"\nEnter internet address                       >";
 gets(internet_address);
 }
  void person::show_data()
  {
  clrscr();
  gotoxy(5,2);
  cout<<"\n      Record number                 >"<<record_id;
 gotoxy(5,5);
 cout<<"\n       Name                          >"<<person_name;
 gotoxy(5,8);
 cout<<"\n       Date of birth                 >"<<date_of_birth;
 gotoxy(5,11);
 cout<<"\n       Residential address           >"<<res_address;
 gotoxy(5,14);
 cout<<"\n       Residential pincode           >"<<res_pincode;
 gotoxy(5,17);
 cout<<"\n       Residential phone no1         >"<<res_phone_no1;
 gotoxy(5,20);
 cout<<"\n       Residential phone no2         >"<<res_phone_no2 ;
 gotoxy(5,23);
 cout<<"\n      Residential fax no.            >"<<res_fax_no;
 gotoxy(5,26);
 cout<<"\n      Occupation                     >"<<occu_pation;
 gotoxy(5,29);
 cout<<"\n      Company's name                 >"<<company_name;
 gotoxy(5,32);
 cout<<"\n      Company's adress               >"<<off_address;
 gotoxy(5,35);
 cout<<"\n      Office pin code                >"<<off_pincode;
 gotoxy(5,38);
 cout<<"\n      Office phone no1               >"<<off_phone_no1;
 gotoxy(5,41);
 cout<<"\n      Office phone no2               >"<<off_phone_no2;
 gotoxy(5,44);
 cout<<"\n      Office faxno                   >"<<off_fax_no;
 gotoxy(5,47);
 cout<<"\n      E_mail ID                      >"<<E_mail_no;
 gotoxy(5,50);
 cout<<"\n      Internet address               >"<<internet_address;
 gotoxy(10,52);
 cout<<"\n      Press any key to continue:";
 getch();//wait for a key press.
 }
 //this function creates a master file.
 void person::add_object()
 {
 fstream file;
 char choice='y';
  while(choice=='y'||choice=='Y')
{
file.open("phoneno.dat",ios::app|ios::out|ios::binary);
pers.get_data();//get data to be written to the file
file.write((char*)&pers,sizeof(pers));
file.flush();
 file.close();
clrscr();
cout<<"\nAny more Record to be read<<y/n>>__________>";
cin>> choice;
 }
  }
  //this function deletes an object
  void person::del_object()
  {
  fstream infile,outfile;
  unsigned long rec_no;
  clrscr();
  cout<<"\n Enter record id no to be deleted__>";
  cin>>rec_no;
  infile.open("phoneno.dat",ios::in|ios::binary);//opens master file in i\o mode
  infile.seekg(0);
  outfile.open("tempno.dat",ios::app|ios::binary);//opens temporary file
  infile.read((char*)&pers,sizeof(pers));
  while(!infile.eof())
  {
  if(pers.record_id!=rec_no)
  outfile.write((char*)&pers,sizeof(pers));
  outfile.flush();//if object is required write intemporary
  infile.read((char*)&pers,sizeof(pers));
}
infile.close();
outfile.close();
remove("phoneno.dat");
rename("tempno.dat","phoneno.dat");
}
//this finction searches a record given one of the key feilds
void person::search_object()
{
fstream infile;
int search_choice;
unsigned long rec_no;
long int mail,faxno,phno;
char name[20],internet[25];
do
{   //display search menu
 clrscr();
 int counter=0;
 gotoxy(22,7);
 cout<<"\nSEARCH MENU";
 gotoxy(22,9);
 cout<<"\n------------------";
 gotoxy(22,11);
 cout<<"\nrecord id.No      ..1";
 gotoxy(22,12);
 cout<<"\nName              ..2";
 gotoxy(22,13);
 cout<<"\nPhone No          ..3";
 gotoxy(22,14);
 cout<<"\nFax No            ..4";
 gotoxy(22,15);
 cout<<"\nE_mail            ..5";
 gotoxy(22,16);
 cout<<"\nInternet address  ..6";
 gotoxy(22,17);
 cout<<"\nExit search menu  ..7";
 gotoxy(1,20);
 cout<<"\nEnter the field choice according to which a record";
 cout<<"is to be searched_______>";
 cin>>search_choice;//get search choice from the user
 switch(search_choice)
 {
 case 1:clrscr();
 cout<<"\n Enter the record idno to be searched>";
 cin>>rec_no;
 infile.open("phoneno.dat",ios::in); //pen file in reading mode
 infile.seekg(0,ios::beg);
 infile.read((char*)&pers,sizeof(pers));
 while(!infile.eof())//searc whole file
 {
 if(pers.record_id==rec_no)
 {
 counter++;//increment counter
 pers.show_data();
}
infile.read((char*)&pers,sizeof(pers));
 }
 infile.close();
 gotoxy(20,24);//set cursor position
cout<<"\nrecords found="<<counter;
getch();  //wait for key press
break;
case 2:clrscr();
cout<<"\n Enter the name to be searched>";
gets(name);
infile.open("phone.dat",ios::in);//open file
infile.seekg(0,ios::beg);
infile.read((char*)&pers,sizeof(pers));
while(!infile.eof())
{
if(strcmpi(pers.person_name,name)==0)//read next record
{
counter++;
pers.show_data();
}
infile.read((char*)&pers,sizeof(pers));
}
infile.close();
gotoxy(20,24);
cout<<"\nRecord found="<<counter;
getch();
break;
case 3:clrscr();
cout<<"\n Enter the phone no to be searched>";
cin>>phno;
infile.open("phoneno.dat",ios::in);
infile.seekg(0,ios::beg);
infile.read((char*)&pers,sizeof(pers)); //read first record
while(!infile.eof())
{
if(pers.res_phone_no1==phno||pers.res_phone_no2==phno||pers.off_phone_no1==phno||pers.off_phone_no2==phno)
{ //record found
counter++;
pers.show_data();
}
infile.read((char*)&pers,sizeof(pers));
}
infile.close();
gotoxy(20,24);
cout<<"\nRecords found="<<counter;  //display counter
getch();
break;
case 4:clrscr();
cout<<"\n Enter the fax no to be searched for>";
cin>>faxno;
infile.open("phoneno.dat",ios::in);
infile.seekg(0,ios::beg) ;
infile.read((char*)&pers,sizeof(pers));
while(!infile.eof())
{
if(pers.res_fax_no==faxno||pers.off_fax_no==faxno)
{
counter++;
pers.show_data();
}
infile.read((char*)&pers,sizeof(pers));
}
infile.close();
gotoxy(20,24);
cout<<"\nrecords found="<<counter;
getch();  //wait for key press
break;
case 5:clrscr();
cout<<"\n Enter the email no to be searched>";
cin >>mail;
infile.open("phoneno.dat",ios::in);
infile.seekg(0,ios::beg);  //set file pointer to the beginning
infile.read((char*)&pers,sizeof(pers));
while(!infile.eof())
{
if(pers.E_mail_no==mail)
{
counter++;
pers.show_data();
}
infile.read((char*)&pers,sizeof(pers));
}
infile.close();
gotoxy(20,24);
cout<<"\nrecords found="<<counter;
getch();
break;
case 6:clrscr();
cout<<"\n Enter the internet address to be searched >";
gets(internet);
infile.open("phoneno.dat",ios::in);
infile.seekg(0,ios::beg);
infile.read((char*)&pers,sizeof(pers));
while(!infile.eof())
{
if(strcmpi(pers.internet_address,internet)==0)
{
counter++;
pers.show_data();
}
infile.read((char*)&pers,sizeof(pers));
}
infile.close();
gotoxy(20,24);
cout<<"\nrecords found="<<counter;
getch();
break;
case 7:clrscr();
gotoxy(22,15);
cout<<"\nYou have ended the Search session";
gotoxy(27,18);
cout<<"\nTHANK YOU!";
delay(700);  //wait for sometime
break;
}
}
while(search_choice!=7);
}
//this function modifies information regarding any person
void person::modify_object()
{
fstream file;
unsigned long code;
int modify_choice;
do
{  //display modify menu
clrscr();
gotoxy(22,7);
cout<<"\nMODIFY MENU";
gotoxy(22,8);
cout<<"_____________________";
gotoxy(22,10);
cout<<"\nResidential Information   ..1";
gotoxy(22,11);
cout<<"\nOfficial Information     ..2";
gotoxy(22,12);
cout<<"\nEmail no                 ..3";
gotoxy(22,13);
cout<<"\nInternet address         ..4";
gotoxy(22,14);
cout<<"\nExit                     ..5";
gotoxy(22,16);
cout<<"\nSelect the Information to be changed";
gotoxy(22,18);
cout<<"\nEnter your choice___>";
cin>>modify_choice;//read choice
if(modify_choice!=5)
{
clrscr();
gotoxy(10,15);
cout<<"\nEnter the recod no of the person>";
cin>>code;//get record noto be modified
file.open("phoneno.dat",ios::in|ios::out);
file.seekg(0,ios::beg);
file.read((char*)&pers,sizeof(pers));   //read first record
int n=file.tellg();  //find where we are
while(!file.eof())
{
if(pers.record_id==code)//record found
{
switch(modify_choice)
{
case 1:clrscr();
//get new information
cout<<"\n Enter new residential address  >";
gets(pers.res_address);
cout<<"\nEnter new pin code              >";
cin>>pers.res_pincode;
cout<<"\nEnter new residence phone no1   >";
cin>>pers.res_phone_no1;
cout<<"\n Enter new residence phone no2  >";
cin>>pers.res_phone_no2;
cout<<"\nEnter new residence fax no      >";
cin>>pers.res_fax_no;
file.seekg(n-sizeof(pers)); //position file pointer to the file to be modified
file.write((char*)&pers,sizeof(pers)); //write the modified record
file.flush();
break;
case 2:clrscr();
//get new information
cout<<"\n Enter new occupation           >";
gets(pers.occu_pation);
cout<<"\n Enter new company's name       >";
gets(pers.company_name);
cout<<"\n ENTER NEW OFFICE ADRESS        >";
gets(pers.off_address);
cout<<"\n ENTER NEW OFFICE PIN CODE      >";
cin>>pers.off_pincode;
cout<<"\nENTER NEW OFFICE PHONENO.1      >";
cin>>pers.off_phone_no1;
cout<<"\n ENTER NEW OFFICE PHONE NO.2    >";
cin>>pers.off_phone_no2;
cout<<"\n ENTER NEW OFFICE FAX NO.       >";
cin>>pers.off_fax_no;
file.seekg(n-sizeof(pers));//set file pointer to the record to be modified
file.write((char*)&pers,sizeof(pers));//write the modified record
file.flush();
break;
case 3:clrscr();
//get new information
cout<<"\nENTER NEW E-MAIL ID.          >";
cin>>pers.E_mail_no;
file.seekg(n-sizeof(pers));//set file pointer to the record to be modified
file.write((char*)&pers,sizeof(pers));//write the modiefied record
file.flush();
break;
case 4:clrscr();
//get new information
cout<<"\nENTER NEW INTERNET ADDRESS   >";
gets(pers.internet_address);
file.seekg(n-sizeof(pers));//set file pointer to the record to be modified
file.write((char*)&pers,sizeof(pers));//write the modiefied record
file.flush();
break;
}//end switch
}//end if
file.read((char*)&pers,sizeof(pers));//read next record
n=file.tellg();/*find where we are*/
}//end while
file.close();
}//end if
}//end do while
while(modify_choice!=5);
clrscr();
gotoxy(22,10);//set curser position
cout<<"\nYOU ENDED MODIFY INFORMATION SESSION";
gotoxy(30,13);
cout<<"\nTHANK YOU";
delay(700);//wait for sometime
}
void ex_change()//this function sorts name
{
temp=new node;//get new node from operating system
temp->link=NULL;
temp->recno=ptr2->recno;
temp->pin=ptr2->pin;
strcpy(temp->name,ptr2->name);
ptr2->recno=ptr1->recno;
ptr2->pin=ptr1->pin;
strcpy(ptr1->name,ptr1->name);
ptr1->recno=temp->recno;
ptr1->pin=temp->pin;
strcpy(ptr1->name,temp->name);
delete temp;//return temporary node to operating system
}
//this function makes an index of the master file using a linked list
void person::make_index()
{
fstream infile;

//make a link list to stimulate an index
first=new node;;//get memory from operating system
ptr=first;          //set pointer to the first node
infile.open("phoneno.dat",ios::in);//open masterfile inreading mode
infile.seekg(0,ios::beg);//set file pointer to thebeginning of the file
infile.read((char*)&pers,sizeof(pers));//read first record
while(!infile.eof())
{
ptr->recno=record_id;//save record no. in node
ptr->pin=res_pincode;//save residence pin code no
strcpy(ptr->name,pers.person_name);//save name
ptr->link=new node;
ptr=ptr->link;//increment pointer
infile.read((char*)&pers,sizeof(pers));
}
ptr->link=NULL;//end of linked list;
infile.close(); //close master file
}

/*this function sorts name*/
void person::sort_name()
{
pers.make_index();//call a function
//sort linked list to simulate an sorted index
ptr1=first;
while(ptr1->link!=NULL)
{
ptr2=ptr1->link;
while(ptr2->link!=NULL)
{
if(strcmpi(ptr2->name,ptr1->name)<0)
ex_change();
ptr2=ptr2->link;
}
ptr2=ptr1->link;
ptr1=ptr2;
}
}
//this function sorts record no and print them
void  person::sort_recno()
{
pers.make_index();
//sort index
ptr1=first;
while(ptr1->link!=NULL)
{//..........addd
 ptr2=ptr1->link;
 while(ptr2!=NULL)
 {
  if(ptr2->recno<ptr1->recno)
  ex_change();
  ptr2=ptr2->link;
  }
  ptr2=ptr1->link;
  ptr1=ptr2;
  }
  }
  //this function sorts records according to pincode nos
  void person::sort_pin()
  {
  pers.make_index();//call a function to call index
  //sort the index
  ptr1=first;
  while(ptr1->link!=NULL)
  {
  ptr2=ptr1->link;
  while(ptr2!=NULL)
  {
  if(ptr2->pin<ptr1->pin)
  ex_change();

  ptr2=ptr2->link;
  }
  ptr2=ptr1->link;
  ptr1=ptr2;
  }
  }
  //this function prints sorted records
  void person::sort_print()
  {
  fstream infile;
  ptr=first;
  while(ptr!=NULL)
  {
  infile.open("phone.dat",ios::in);
  infile.seekg(0,ios::beg);
  infile.read((char*)&pers,sizeof(pers));//read first record
  while(!infile.eof())
  {
  if(ptr->recno==pers.record_id)//compare record nos with sorted index
  { //record found
  pers.show_data();
  infile.seekg(0,ios::end); //set file pointer to the end of file
  }
  infile.read((char*)&pers,sizeof(pers)); //if not found read next record
  }
   infile.close();//close master file
   ptr=ptr->link;//increment pointer to index
   }
   }
   //this function destroys index in order to save memory
   void del_index()
   {
   while(first!=NULL)
   {
   ptr=first;  //set pointer to first node of index
   first=first->link;
   delete ptr;  //return memory to the operating system
   }
   }
   //this function performs the overall sorting operation indicated in menu
   void person::sort_object()
   {
   int sort_choice;
do
{//display sorrt menu
clrscr();
gotoxy(22,7);
cout<<"\nSORT MENU";
gotoxy(22,8);
cout<<"_____________";
gotoxy(25,10);
cout<<"\nSORTED record nos...1";
gotoxy(25,11);
cout<<"\nSORTED NAMES.... 2";
gotoxy(25,12);
cout<<"\nSORTED PIN CODE NOS...3";
gotoxy(25,13);
cout<<"\nEXIT SORT MENU...4";
gotoxy(25,20);
cout<<"\nENTER YOUR CHOICE NOS->";
cin>>sort_choice;//get choice
switch(sort_choice)
{
case 1:
clrscr();
pers.sort_recno();//sort recno
pers.sort_print();//display records in sorted maner
del_index();//return memory to operating system
delay(200);//wait for some time
break;
case 2:
clrscr();
pers.sort_name();//sort names
pers.sort_print();//display sorted records
del_index();//return memory to operating system
delay(200);//waitfor some  time
break;
case 3:
clrscr();
pers.sort_pin();//sort pin code nos
pers.sort_print();//print sorted records
del_index();//return memory to operating system
delay(200);//wait for some  time
break;
case 4:
clrscr();
gotoxy(22,10);//set cursor to position
cout<<"\nYOU ENDED THE SORTED PORTION";
gotoxy(27,13);
cout<<"\nthank you";
delay(700);
break;
}
}
while(sort_choice!=4);
}
//this function generates reportb on the given guide lines in report  menu
void person::reports()
{
fstream infile;
int report_choice;
do //display report menu
{
clrscr();
gotoxy(22,7);
cout<<"\nREPORT MENU";
gotoxy(22,8);
cout<<"________________________";
gotoxy(5,10);
cout<<"\nSORTED LIST OF NAMES WITH RESIDENCE AND OFFICE PHONE NOS...1";
gotoxy(5,11);
cout<<"\nLIST OF NAMES WITH THEIR OFFICE ADDRESS AND PHONE NOS....2";
gotoxy(5,12);
cout<<"\nlist of names with their e-mail nosand internet address";
gotoxy(5,13);
cout<<"\nLIST OF NAMES WITH RECORD NOS AND RESIDENTIAL ADDRESS";
gotoxy(5,14);
cout<<"\nEXIT REPORT SESSION........5";
gotoxy(5,16);
cout<<"\nENTER YOUR CHOICE NOS";
cin>>report_choice;
switch(report_choice)
{
case 1:
clrscr();
pers.sort_name();//call  function to sort names
cout<<"\n NAME      RESIDENCE PHONE NOS     OFFICE PHONE NO";
cout<<"\n____________________________________________________";
sort_name();
ptr=first;
while(ptr!=NULL) //desired result not achived
{
infile.open("phoneno.dat",ios::in);//open master file in reading mode
infile.seekg(0,ios::beg);
infile.read((char*)&pers, sizeof(pers));//read first ercord
while(!infile.eof())
{
if(ptr->recno==pers.record_id)//compare record no with index
{
cout<<"\n";
cout<<setiosflags(ios::left)<<setw(28)<<pers.person_name<<setw(30)<<pers.res_phone_no1
      <<setw(30)<<pers.off_phone_no1;
//set left justified output
cout<<setw(20)<<" ";
cout<<setiosflags(ios::left)<<setw(30)<<pers.res_phone_no2<<setw(30)<<pers.off_phone_no2;
infile.seekg(0,ios::end);
}
infile.read((char*)&pers,sizeof(pers) );
}
infile.close();//close master file
ptr=ptr->link;//increament pointer to sorted index
}
del_index();//delete index
gotoxy(20,24);
cout<<"\nPRESS ANY KEY TO CONTINUE";
getch();//WAIT FOR A KEY PRES
break;
case 2:
clrscr();
infile.open("phoneno.dat",ios::in);//open master file in reading mode
infile.seekg(0);//set file pointer to the begining of the file
infile.read((char*)&pers, sizeof(pers));//read first record
while(!infile.eof())
{
gotoxy(10,5);
cout<<"\nNAME______________>"<<pers.person_name;
gotoxy(10,6);
cout<<"\nCOMPANY'S NAME___________>"<<pers.company_name;
gotoxy(10,7);
cout<<"\nCOMPANY'S ADDRESS__________>"<<pers.off_address;
gotoxy(10,8);
cout<<"\nOFFICE FAX  NO________<"<<pers.off_fax_no;
gotoxy(10,9);
cout<<"\noffice phone no1_>"<<pers.off_phone_no1;
gotoxy(10,10);
cout<<"\nOFFICE PHONE NO2->"<<pers.off_phone_no2;
gotoxy(20,24);
cout<<"\nPRESS ANY KEY TO CONTINUE";
getch();//wait for some time
clrscr();
infile.read((char*)&pers,sizeof(pers));//read next record
}
infile.close();//close master file
break;
case 3:
clrscr();
gotoxy(4,1);
cout<<"\nNAME    E-MAIL NO.       INTERNET ADDRESS ";
gotoxy(2,2);
cout<<"_______________________________________________";
infile.open("phoneno.dat",ios::in);//open master file in reading mode
infile.seekg(0);//set file pointer to th e begining of the file
infile.read((char*)&pers,sizeof(pers));
while(!infile.eof())
{
cout<<"\n";
cout<<setiosflags(ios::left)<<setw(27)
<<pers.person_name<<setw(25)<<pers.E_mail_no
<<setw(30)<<pers.internet_address;
infile.read((char*)&pers,sizeof(pers));
}
infile.close();//close master file
gotoxy(20,24);//set cursor position
cout<<"\nENTER ANY KEY TO CONTINUE";
getch();
break;
case 4:
clrscr();
cout<<"\n   RECORDNO.   NAME    RES.ADDRESS  ";
cout<<"\res.fax no.  res phonne no ";
cout<<"\n___________________________________________";
infile.open("phone.dat",ios::in);
infile.seekg(0,ios::beg);

infile.read((char*)&pers,sizeof(pers));
while(!infile.eof())
{
cout<<"\n";
cout<<setiosflags(ios::left)<<setw(15)<<pers.record_id<<setw(15)
<<pers.person_name<<setw(18)<<pers.res_address<<setw(15)<<pers.res_fax_no<<setw(25)
<<pers.res_phone_no1;
cout<<setw(55)<<" ";
cout<<setiosflags(ios::left)<<setw(25)<<pers.res_phone_no2;
infile.read((char*)&pers,sizeof(pers));
}
infile.close();
gotoxy(20,24);
cout<<"\nPRESS ANY KEY TO CONTINUE";
getch();
break;
case 5:
clrscr();
gotoxy(22,10);
cout<<"\nYOU HAVE ENDED REPORT SESSION";
gotoxy(27,13);
cout<<"\nTHANK YOU!";
delay(700);
break;
}
}
while(report_choice!=5);
}
//THIS IS A GRAPICS PROCEDURE THAT CAN BE CALLED IN MAIN FUNCTION
/* void graphic_screen()
{
int driver,mode;
driver=DETECT;
initgraph(&driver,&mode," ");//initialise graph mode
setbkcolor(10);//set background color to light green
setcolor(5);//set text color to magenta
settextstyle(0,0,7);//set default font,horizontal direction,sise of text
outtextxy(50,100,"TELEPHONE");
outtextxy(50,300,"DIRECTORY");
delay(2500);
closegraph();
initgraph(&driver,&mode,"");
setbkcolor(10);
setcolor(1);
settextstyle(0,0,7);
outtextxy(50,100,"DEVELOPED");
outtextxy(250,250,"BY");
delay(2000);
closegraph();
initgraph(&driver,&mode,"");
setbkcolor(10);//set background color to light green
setcolor(4);
//settextcolor to red
settextstyle(0,0,5);//set default font.horizontal direction,size of text
outtextxy(60,10,"B.B PATRA");
outtextxy(250,200,"AND");
outtextxy(95,300,"prashant,bipin");
delay(2500);
closegraph();
}*/
//THIS IS THE MAIN PROGRAM
void main()
{
int main_choice;
/*here the graphic_screen()function can be called to make the screen more colourfull*/
do
{//display main menu
clrscr();
gotoxy(22,7);
cout<<"\n                        MAIN MENU";
gotoxy(12,9);
cout<<"             ---------";
cout<<"\n                  PRESS 0 TO VIEW CONTENT";
gotoxy(25,11);
cout<<"\n                 ADD A NEW RECORD     ..1";
gotoxy(25,14);
cout<<"\n                 DELETE A RECORD      ..2";
gotoxy(25,17);
cout<<"\n                 MODIFY A RECORD      ..3";
gotoxy(25,20);
cout<<"\n                 SEAARCH A RECORD     ..4";
gotoxy(25,23);
cout<<"\n                 SORTED INFORMATION   ..5";
gotoxy(25,26);
cout<<"\n                 REPORTS              ..6";
gotoxy(25,29);
cout<<"\n                 EXIT                 ..7";
gotoxy(25,32);
cout<<"\n                 ENTER YOUR CHOICE NO____>";
cin>>main_choice;;//get choice
switch(main_choice)
{
case 1:pers.add_object();//register a new person
break;
case 2:pers.del_object();//delete a record
break;
case 3:pers.modify_object();//modify a record
break;
case 4:pers.search_object();//search for an information
break;
case 5:pers.sort_object();//sort records
break;
case 6:pers.reports();//make reports
break;
case 7:clrscr();
gotoxy(22,10);
cout<<"\n                         YOU HAVE ENDED THE SESSION";
gotoxy(27,13);
cout<<"\n                         THANK YOU !";
delay(1000);
break;
case 0:clrscr();
pers.show_data();
}
}while(main_choice!=7);
}
