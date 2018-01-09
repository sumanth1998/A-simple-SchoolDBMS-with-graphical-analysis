#include<iostream>
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include<time.h>
using namespace std;

// GLOBAL VARIABLES 

	int school_id=100;
	int m_max=0,sci_max=0,soc_max=0,kan_max=0,eng_max=0;
	

//Global functions
void max_finder()
{
	int id;
	char fname[20],lname[20];
	int m,sci,soc,kan,eng;
	ifstream file;
	file.open("marks.txt");
	while(file>>id>>m>>sci>>soc>>kan>>eng)
	{
		if(m>=m_max)
		{
			m_max=m;
		}
	
		if(sci>=sci_max)
		{
			sci_max=sci;
		}
		
		if(soc>=soc_max)
		{
			soc_max=soc;
		}
		
		if(kan>=kan_max)
		{
			kan_max=kan;
		}
		
		if(eng>=eng_max)
		{
			eng_max=eng;
		}	
	} 
}

//Defines gotoxy() for ANSI C compilers.
void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void loading()
{
	int i;
	char ch=178,ce=177;
	for(i=0;i<25;i++)
	{
		cout<<ch;
		Sleep(20);
	}
}

void head()
{
	cout<<"\t\t\t\t----------------------------------------------------------\n";
	cout<<"\t\t\t\t|             STUDENT DATABASE MANAGEMENT SYSTEM         |\n";
	cout<<"\t\t\t\t----------------------------------------------------------\n";
}

 
void create_files()
{
	ofstream file;
	if(!"student.txt"||(!"teacher.txt")|| (!"admin.txt")||(!"notifications.txt")||(!"complaint.txt")||(!"marks.txt")||(!"attendance.txt"))
	{
		cout<<" Creating database !!   "<<endl;
		loading();
		file.open("student.txt");
		file.close();
		file.open("teacher.txt");
		file.close();
		file.open("admin.txt");
		file.close();
		file.open("notifications.txt");
		file.close();
		file.open("complaint.txt");
		file.close();
		file.open("marks.txt");
		file.close();
		file.open("attendance.txt");
		file.close();
	}
}

//Classes

class student
{
	protected : int school_id;
				int m_att,sci_att,soc_att,kan_att,eng_att;
				char fname[30],lname[30],email[30],dob[30],ph_num[30];
				int m_marks,sci_marks,soc_marks,kan_marks,eng_marks;
	public:	
			void view_profile();
			void view_result();
			void write_complaint();
			void view_notifications();
			void view_attendance();
			void display_graph();
			void display_student_menu();
			int get_school_id()
			{
				system("cls");
				gotoxy(40,7);
				cout<<"Enter School id : ";
				
				cin>>school_id;
				student A;
				ifstream file;
				file.open("student.txt",ios::in);
				while(file>>A.school_id>>A.fname>>A.lname>>A.dob>>A.email>>A.ph_num)
				{
					if(A.school_id==school_id)
						{
							return 1;
						}
						
				}
				return 0;
			}
};

	void student::display_graph()
{
	system("cls");
	student S;
	ifstream file;
	file.open("marks.txt");
	while(file>>S.school_id>>S.m_marks>>S.sci_marks>>S.soc_marks>>S.kan_marks>>S.eng_marks)
	{
		
		cout<<"asdad";
		if(S.school_id==school_id)
		{
			system("cls");
			gotoxy(40,7);
			int i,j=0;
			char ch=178;
			cout<<"------------GRAPHICAL DESCRIPTION---------\n\n";
			cout<<"\t\t\t\t"<<"MATHS:       ";
			for(i=0;i<S.m_marks/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n";
			cout<<"\t\t\t\t"<<"MAX_MATHS:   ";
			for(i=0;i<m_max/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n\n";
			cout<<"\t\t\t\t"<<"SCIENCE:     ";
			for(i=0;i<S.sci_marks/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n";
			cout<<"\t\t\t\t"<<"MAX_SCIENCE: ";
			for(i=0;i<sci_max/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n\n";
			cout<<"\t\t\t\t"<<"SOCIAL:      ";
			for(i=0;i<S.soc_marks/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n";
			cout<<"\t\t\t\t"<<"MAX_SOCIAL:  ";
			for(i=0;i<soc_max/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n\n";
			cout<<"\t\t\t\t"<<"KANNADA:     ";
			for(i=0;i<S.kan_marks/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n";
			cout<<"\t\t\t\t"<<"MAX_KANNADA: ";
			for(i=0;i<kan_max/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n\n";
			cout<<"\t\t\t\t"<<"ENGLISH:     ";
			for(i=0;i<S.eng_marks/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n";
			cout<<"\t\t\t\t"<<"MAX_ENGLISH: ";
			for(i=0;i<eng_max/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n\n";
			cout<<"\t\t\t\t\t     ";
			for(i=0;i<25;i++)
			{
				if(i%6==0)
				{
					cout<<i*4+j;
					j++;
				}
				else
				{
					cout<<" ";
				}
			}
			getch();
			return;
		}
		
		
	}
	gotoxy(40,7);
	cout<<"RESULT YET TO BE UPLOADED \n";
	
	getch();
	file.close();
}

void student::display_student_menu()
{
	int i=1;
	student S;
	
					if(!S.get_school_id())
					{
						cout<<"\n\n\t\t\t\t       INVALID SCHOOL ID \n";
						getch();
						return;	
					}
	do
	{
		system("cls");
		gotoxy(40,7);
		cout<<"--------STUDENT MENU---------\n \n";
		cout<<"\t\t\t\t\t  1.View profile \n";
		cout<<"\t\t\t\t\t  2.View result \n";
		cout<<"\t\t\t\t\t  3.Write complaint \n";
		cout<<"\t\t\t\t\t  4.View notifications \n";
		cout<<"\t\t\t\t\t  5.View attendance \n";
		cout<<"\t\t\t\t\t  6.View graphical result \n";
		cout<<"\t\t\t\t\t  7.Exit \n";
		cin>>i;
		switch(i)
		{
			case 1:S.view_profile();
					break;
			case 2:S.view_result();
					break;
			case 3:S.write_complaint();
					break;
			case 4:S.view_notifications();
					break;
			case 5:S.view_attendance();
					break;
			case 6:S.display_graph();
					break;
			case 7:cout<<"Exiting \n";
					break;
			default: cout<<"invalid choice \n";
		}
	}while(i!=7);
	
}
void student::view_notifications()
{
	system("cls");
	ifstream file;
	char ch;
	file.open("notifications.txt");
	gotoxy(40,7);
	cout<<"-----------NOTIFICATIONS-----------\n\n";
	while(!file.eof())
	{
		file.get(ch);
		cout<<ch;
	}
	getch();
	file.close();
}
void student::view_profile()
{
	student S;
	system("cls");
	
	ifstream file;
	file.open("student.txt");
	while(file>>S.school_id>>S.fname>>S.lname>>S.dob>>S.email>>S.ph_num)
	{
		if(S.school_id==school_id)
		{
			system("cls");
			gotoxy(40,7);
			cout<<"---------------Student Details --------------"<<endl;
			cout<<"\t\t\t\t\t NAME : "<<S.fname<<" "<<S.lname<<endl;
			cout<<"\t\t\t\t\t Date of birth : "<<S.dob<<endl;
			cout<<"\t\t\t\t\t Email : "<<S.email<<endl;
			cout<<"\t\t\t\t\t Phone number :"<<S.ph_num<<endl;
			getch();
			return;
		}
	}
	file.close();
}
void student::write_complaint()
{
	system("cls");
	string comp;
	gotoxy(40,7);
	cout<<"      ADD COMPLAINT \n\n";
	cout<<"\t\t\t\t\t----------------------------\n\n\t\t\t\t\t";
	cin.ignore();
	getline(cin,comp);
	
	ofstream file;
	file.open("complaints.txt",ios::app);
	file<<"------------------------------------------------------\n";
	file<<"\t\t\t\t "<<comp<<"\n";
	file<<"------------------------------------------------------\n\n\n";
	cout<<"\n\n\n\t\t\t\t COMPLAINT SUCCESSFULLY REGISTERED \n ";
	getch();
	file.close();
}
void student::view_result()
{
	system("cls");
	student S;
	ifstream file;
	file.open("marks.txt");
	while(file>>S.school_id>>S.m_marks>>S.sci_marks>>S.soc_marks>>S.kan_marks>>S.eng_marks)
	{
		if(S.school_id==school_id)
		{
			gotoxy(40,7);
			cout<<"---------------MARKS SHEET--------------\n\n";
			cout<<"\t\t\t\t\t\t   MATHS : "<<S.m_marks<<endl;
			cout<<"\t\t\t\t\t\t   SCIENCE : "<<S.sci_marks<<endl;
			cout<<"\t\t\t\t\t\t   SOCIAL : "<<S.soc_marks<<endl;
			cout<<"\t\t\t\t\t\t   KANNADA : "<<S.kan_marks<<endl;
			cout<<"\t\t\t\t\t\t   ENGLISH : "<<S.eng_marks<<endl;
			getch();
			return;
		}
	}
	gotoxy(40,7);
	cout<<"RESULT YET TO BE UPLOADED \n";
	
	getch();
	file.close();
}

void student::view_attendance()
{
	system("cls");
	student S;
	ifstream file;
	file.open("attendance.txt");
	while(file>>S.school_id>>S.m_att>>S.sci_att>>S.soc_att>>S.kan_att>>S.eng_att)
	{
		if(S.school_id==school_id)
		{
			gotoxy(40,7);
			cout<<"---------------ATTENDANCE SHEET--------------\n\n";
			cout<<"\t\t\t\t\t\t   MATHS : "<<S.m_att<<endl;
			cout<<"\t\t\t\t\t\t   SCIENCE : "<<S.sci_att<<endl;
			cout<<"\t\t\t\t\t\t   SOCIAL : "<<S.soc_att<<endl;
			cout<<"\t\t\t\t\t\t   KANNADA : "<<S.kan_att<<endl;
			cout<<"\t\t\t\t\t\t   ENGLISH : "<<S.eng_att<<endl;
			getch();
			return;
		}
	}
	gotoxy(40,7);
	cout<<"ATTENDANCE YET TO BE UPLOADED \n";
	
	getch();
	file.close();
}
class admin:public student
{
	public: void add_student();
			void add_teacher();
			void add_notification();
			void view_complaint();
			void view_all_result();
			void view_all_att();
			void display_admin_menu();
			int check_admin();
			void graph_admin();
};
void admin::graph_admin()
{
	system("cls");
	admin S,A;
	system("cls");
	cout<<"\n\n\n\t\t\t\t\t\t Enter School id: ";
	if(!A.get_school_id())
	{
		cout<<"\n\n\t\t\t\t INVALID SCHOOL ID \n";
		return;
	}
	ifstream file;
	file.open("marks.txt");
	while(file>>S.school_id>>S.m_marks>>S.sci_marks>>S.soc_marks>>S.kan_marks>>S.eng_marks)
	{
		
		if(S.school_id==A.school_id)
		{
			system("cls");
			gotoxy(40,7);
			int i,j=0;
			char ch=178;
			cout<<"------------GRAPHICAL DESCRIPTION---------\n\n";
			cout<<"\t\t\t\t"<<"MATHS:       ";
			for(i=0;i<S.m_marks/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n";
			cout<<"\t\t\t\t"<<"MAX_MATHS:   ";
			for(i=0;i<m_max/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n\n";
			cout<<"\t\t\t\t"<<"SCIENCE:     ";
			for(i=0;i<S.sci_marks/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n";
			cout<<"\t\t\t\t"<<"MAX_SCIENCE: ";
			for(i=0;i<sci_max/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n\n";
			cout<<"\t\t\t\t"<<"SOCIAL:      ";
			for(i=0;i<S.soc_marks/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n";
			cout<<"\t\t\t\t"<<"MAX_SOCIAL:  ";
			for(i=0;i<soc_max/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n\n";
			cout<<"\t\t\t\t"<<"KANNADA:     ";
			for(i=0;i<S.kan_marks/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n";
			cout<<"\t\t\t\t"<<"MAX_KANNADA: ";
			for(i=0;i<kan_max/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n\n";
			cout<<"\t\t\t\t"<<"ENGLISH:     ";
			for(i=0;i<S.eng_marks/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n";
			cout<<"\t\t\t\t"<<"MAX_ENGLISH: ";
			for(i=0;i<eng_max/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n\n";
			cout<<"\t\t\t\t\t     ";
			for(i=0;i<25;i++)
			{
				if(i%6==0)
				{
					cout<<i*4+j;
					j++;
				}
				else
				{
					cout<<" ";
				}
			}
			getch();
			return;
		}
		
		
	}
	gotoxy(40,7);
	cout<<"RESULT YET TO BE UPLOADED \n";
	
	getch();
	file.close();
	
}
int admin::check_admin()
{
	char username[20],pass[20],c;
	system("cls");
	gotoxy(50,10);
	cout<<"--------------------\n";
	cout<<"\t\t\t\t\t\t      ADMINISTRATOR ";
	gotoxy(50,12);
	cout<<"--------------------\n";
	cout<<"\t\t\t\t\t\t Username :";
	cin>>username;
	cout<<"\n\t\t\t\t\t\t ";
	cout<<"Password: ";
	short i=0;
    while((c=getch())!=13){ pass[i]=c; i++; cout<<'*';
	  }
	pass[i]='\0';
	if(strcmp(pass,"a"))
		return 1;
	else
		return 0;
}
void admin::display_admin_menu()
{
	int i=1;
	
	do
	{
		system("cls");
		gotoxy(40,7);
		cout<<"--------ADMIN MENU------- \n\n";
		cout<<"\t\t\t\t\t  1.Add Student \n";
		cout<<"\t\t\t\t\t  2.Add Teacher \n";
		cout<<"\t\t\t\t\t  3.View Complaint \n";
		cout<<"\t\t\t\t\t  4.View All Result \n";
		cout<<"\t\t\t\t\t  5.View All Attendance \n";
		cout<<"\t\t\t\t\t  6.Add Notifications \n";
		cout<<"\t\t\t\t\t  7.View Grpahical result \n";
		cout<<"\t\t\t\t\t  8.Exit \n";
		cin>>i;
		switch(i)
		{
			case 1:add_student();
					break;
			case 2:add_teacher();
					break;
			case 3:view_complaint();
					break;
			case 4:view_all_result();
				break;
			case 5:view_all_att();
				break;
			case 6:add_notification();
					break;
			case 7:graph_admin();
					break;
			case 8:cout<<"Exiting \n";
				break;
			default: cout<<"invalid choice \n";
			
		}
		
	}while(i!=8);
}
void admin::add_student()
{
	admin a;
	system("cls");
	gotoxy(40,7);
	cout<<"ENTER STUDENT DETAILS : \n\n"<<endl;
	cout<<"\t\t\t\t\t  Enter first name : ";
	cin>>a.fname;
	cout<<"\t\t\t\t\t  Enter first name : ";
	cin>>a.lname;
	cout<<"\t\t\t\t\t  Enter date of birth : ";
	cin>>a.dob;
	cout<<"\t\t\t\t\t  Enter email address : ";
	cin>>a.email;
	cout<<"\t\t\t\t\t  Enter the phone number ";
	cin>>a.ph_num;
 int id;
	fstream id_up;
	id_up.open("id.txt",ios::in);
	id_up>>id;
	cout<<"\t\t\t\t\t  The school id assigned is : "<<id++<<endl;
	
	getch();
	ofstream file;
	file.open("id.txt",ios::out);
	
	file<<id;
	file.close();
	file.open("student.txt",ios::app);
	file<<id<<" "<<a.fname<<" "<<a.lname<<" "<<a.dob<<" "<<a.email<<" "<<a.ph_num<<"\n";
	file.close();
	cout<<"\n\n\t\t\t\t\t  Successfully added the details";
	getch();
}
void admin::add_teacher()
{
	admin a;
	system("cls");
	gotoxy(40,7);
	cout<<"ENTER TEACHER DETAILS : \n\n"<<endl;
	cout<<"\t\t\t\t\t  Enter first name : ";
	cin>>a.fname;
	cout<<"\t\t\t\t\t  Enter first name : ";
	cin>>a.lname;
	cout<<"\t\t\t\t\t  Enter date of birth : ";
	cin>>a.dob;
	cout<<"\t\t\t\t\t  Enter email address : ";
	cin>>a.email;
	cout<<"\t\t\t\t\t  Enter the phone number ";
	cin>>a.ph_num;
	int id;
	fstream id_up;
	id_up.open("id.txt",ios::in);
	id_up>>id;
	cout<<"\t\t\t\t\t  The school id assigned is : "<<id++<<endl;
	
	getch();
	ofstream file;
	file.open("id.txt",ios::out);
	
	file<<id;
	file.close();
	file.open("teacher.txt",ios::app);
	file<<school_id++<<" "<<a.fname<<" "<<a.lname<<" "<<a.dob<<" "<<a.email<<" "<<a.ph_num<<"\n";
	file.close();
	cout<<"\n\n\t\t\t\t\t  Successfully added the details";
	getch();
}
void admin::add_notification() 
{
	system("cls");
	string notf;
	gotoxy(40,7);
	cout<<"      ADD NOTIFICATION \n\n";
	cout<<"\t\t\t\t\t----------------------------\n\n\t\t\t\t\t";
	cin.ignore();
	getline(cin,notf);
	
	ofstream file;
	file.open("notifications.txt",ios::app);
	file<<"------------------------------------------------------\n";
	file<<"\t\t\t\t "<<notf<<"\n";
	file<<"------------------------------------------------------\n\n\n";
	cout<<"\n\n\n\t\t\t\t SUCCESFULLY ADDED NOTIFICATION ";
	getch();
	file.close();
}
void admin::view_complaint()
{
	system("cls");
	ifstream file;
	char ch;
	file.open("complaints.txt");
	gotoxy(40,7);
	cout<<"-----------COMPLAINTS-----------\n\n";
	while(!file.eof())
	{
		file.get(ch);
		cout<<ch;
	}
	getch();
	file.close();
}
void admin::view_all_result()
{
	system("cls");
	ifstream file1,file2;
	admin S,A;
	file1.open("student.txt");
	file2.open("marks.txt");
	gotoxy(30,7);
	cout<<"---------------------COMPLETE RESULT SHEET --------------------\n\n";
	cout<<"   School id \t Name \t\t mat_marks \t sci_marks \t soc_marks \t kan_marks \t eng_marks \n";
	cout<<"----------------------------------------------------------------------------------------------------------\n";
	while((file1>>A.school_id>>A.fname>>A.lname>>A.dob>>A.email>>A.ph_num)&&(file2>>A.school_id>>A.m_marks>>A.sci_marks>>A.soc_marks>>A.kan_marks>>A.eng_marks))
	{
		cout<<"   "<<A.school_id<<"\t\t  "<<A.fname<<" "<<A.lname<<"\t\t  "<<A.m_marks<<"\t\t  "<<A.sci_marks<<"\t\t  "<<A.soc_marks<<"\t\t  "<<A.kan_marks<<"\t\t  "<<A.eng_marks<<endl;
	}
getch();
}

void admin::view_all_att()
{
	system("cls");
	ifstream file1,file2;
	admin S,A;
	file1.open("student.txt");
	file2.open("marks.txt");
	gotoxy(35,7);
	cout<<"---------------------COMPLETE ATTENDANCE SHEET --------------------\n\n";
	cout<<"   School id \t Name \t\t maths \t\t  science  \t social  \t kannada  \t english \n";
	cout<<"----------------------------------------------------------------------------------------------------------\n";
	while((file1>>A.school_id>>A.fname>>A.lname>>A.dob>>A.email>>A.ph_num)&&(file2>>A.school_id>>A.m_att>>A.sci_att>>A.soc_att>>A.kan_att>>A.eng_att))
	{
		cout<<"   "<<A.school_id<<"\t\t  "<<A.fname<<" "<<A.lname<<"\t\t  "<<A.m_att<<"\t\t  "<<A.sci_att<<"\t\t  "<<A.soc_att<<"\t\t  "<<A.kan_att<<"\t\t  "<<A.eng_att<<endl;
	}
getch();
}

class teacher:public student
{
	public: void update_marks();
			void update_attendance();
			void add_notification();
			void view_student();
			void view_performance();
			void view_all_result();
			void display_teacher_menu();
			void graph_teacher();
};

void teacher::display_teacher_menu()
{
	int i=1;
	do
	{
		system("cls");
		gotoxy(40,7);
		cout<<"---------Teacher menu--------\n \n";
		cout<<"\t\t\t\t\t  1. Update marks \n";
		cout<<"\t\t\t\t\t  2. Update attendance \n";
		cout<<"\t\t\t\t\t  3. Add notifications \n";
		cout<<"\t\t\t\t\t  4. View Student \n";
		cout<<"\t\t\t\t\t  5. View Performance \n";
		cout<<"\t\t\t\t\t  6. View All Result \n";
		cout<<"\t\t\t\t\t  7. View Graphical result \n";
		cout<<"\t\t\t\t\t  8. Exit \n";
		cin>>i;
		switch(i)
		{
			case 1:update_marks();
					break;
			case 2:update_attendance();
					break;
			case 3:add_notification();
					break;
			case 4:view_student();
					break;
			case 5:view_performance();
					break;
			case 6:view_all_result();
					break;
			case 7:graph_teacher();
					break;
			case 8:cout<<"Exiting \n";
					break;
			default: cout<<"Invalid choice \n";
		}
		
	}while(i!=8);
}
void teacher::update_marks()
{
	teacher A;
	ifstream file1;
	file1.open("student.txt",ios::in);
	ofstream file;
	file.open("marks.txt",ios::app);
	while((file1>>A.school_id>>A.fname>>A.lname>>A.dob>>A.email>>A.ph_num))
	{
		system("cls");
		gotoxy(40,7);
		cout<<"Enter the marks of "<<A.fname<<" "<<A.lname<<endl<<"\n\n";
		cout<<"\t\t\t\t\t  Enter maths marks : ";
		cin>>A.m_marks;
		if(A.m_marks>m_max)
		{
			m_max=A.m_marks;
		}
		cout<<"\t\t\t\t\t  Enter science marks : ";
		cin>>A.sci_marks;
		if(A.sci_marks>sci_max)
		{
			sci_max=A.sci_marks;
		}
		cout<<"\t\t\t\t\t  Enter social marks : ";	
		cin>>A.soc_marks;
		if(A.soc_marks>soc_max)
		{
			soc_max=A.soc_marks;
		}
		cout<<"\t\t\t\t\t  Enter kannada marks : ";
		cin>>A.kan_marks;		
		if(A.kan_marks>kan_max)
		{
			kan_max=A.kan_marks;
		}
		cout<<"\t\t\t\t\t  Enter english marks : ";
		cin>>A.eng_marks;
		if(A.eng_marks>eng_max)
		{
			eng_max=A.eng_marks;
		}
		file<<A.school_id<<" "<<A.m_marks%100<<" "<<A.sci_marks%100<<" "<<A.soc_marks%100<<" "<<A.kan_marks%100<<" "<<A.eng_marks%100<<" \n";
	
	}
		file.close();
}
void teacher::update_attendance()
{
	teacher A;
	ifstream file1;
	file1.open("student.txt",ios::in);
	ofstream file;
	file.open("attendance.txt",ios::app);
	while((file1>>A.school_id>>A.fname>>A.lname>>A.dob>>A.email>>A.ph_num))
	{
		system("cls");
		gotoxy(40,7);
		cout<<"Enter the attendance of "<<A.fname<<" "<<A.lname<<endl<<"\n\n";
		cout<<"\t\t\t\t\t  Enter maths attendance : ";
		cin>>A.m_att;
		cout<<"\t\t\t\t\t  Enter science attendance : ";
		cin>>A.sci_att;
		cout<<"\t\t\t\t\t  Enter social attendance : ";	
		cin>>A.soc_att;
		cout<<"\t\t\t\t\t  Enter kannada attendance : ";
		cin>>A.kan_att;		
		cout<<"\t\t\t\t\t  Enter english attendance : ";
		cin>>A.eng_att;
		
		file<<A.school_id<<" "<<A.m_att%21<<" "<<A.sci_att%21<<" "<<A.soc_att%21<<" "<<A.kan_att%21<<" "<<A.eng_att%21<<" \n";
	
	}
		file.close();
}
void teacher::add_notification()
{
	system("cls");
	char notf[100];
	gotoxy(40,7);
	cout<<"      ADD NOTIFICATION \n\n";
	cout<<"\t\t\t\t\t----------------------------\n\n\t\t\t\t\t";
	cin>>notf;
	
	ofstream file;
	file.open("notifications.txt",ios::app);
	file<<"------------------------------------------------------\n";
	file<<"\t\t\t\t "<<notf<<"\n";
	file<<"------------------------------------------------------\n\n\n";
	cout<<"\n\n\n\t\t\t\t SUCCESFULLY ADDED NOTIFICATION ";
	getch();
	file.close();
	
}
void teacher::view_student()
{
	teacher S,A;
	system("cls");
	cout<<"\n\n\n\t\t\t\t\t\t Enter School id: ";
	if(!A.get_school_id())
	{
		cout<<"\n\n\t\t\t\t INVALID SCHOOL ID \n";
		return;
	}
	
	system("cls");
	
	ifstream file;
	file.open("student.txt");
	while(file>>S.school_id>>S.fname>>S.lname>>S.dob>>S.email>>S.ph_num)
	{
		if(S.school_id==A.school_id)
		{
			system("cls");
			gotoxy(40,7);
			cout<<"---------------Student Details --------------"<<endl;
			cout<<"\t\t\t\t\t NAME : "<<S.fname<<" "<<S.lname<<endl;
			cout<<"\t\t\t\t\t Date of birth : "<<S.dob<<endl;
			cout<<"\t\t\t\t\t Email : "<<S.email<<endl;
			cout<<"\t\t\t\t\t Phone number :"<<S.ph_num<<endl;
			getch();
			return;
		}
	}
	file.close();
}
void teacher::graph_teacher()
{
	
	system("cls");
	teacher S,A;
	system("cls");
	cout<<"\n\n\n\t\t\t\t\t\t Enter School id: ";
	if(!A.get_school_id())
	{
		cout<<"\n\n\t\t\t\t INVALID SCHOOL ID \n";
		return;
	}
	ifstream file;
	file.open("marks.txt");
	while(file>>S.school_id>>S.m_marks>>S.sci_marks>>S.soc_marks>>S.kan_marks>>S.eng_marks)
	{
		
		if(S.school_id==A.school_id)
		{
			system("cls");
			gotoxy(40,7);
			int i,j=0;
			char ch=178;
			cout<<"------------GRAPHICAL DESCRIPTION---------\n\n";
			cout<<"\t\t\t\t"<<"MATHS:       ";
			for(i=0;i<S.m_marks/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n";
			cout<<"\t\t\t\t"<<"MAX_MATHS:   ";
			for(i=0;i<m_max/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n\n";
			cout<<"\t\t\t\t"<<"SCIENCE:     ";
			for(i=0;i<S.sci_marks/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n";
			cout<<"\t\t\t\t"<<"MAX_SCIENCE: ";
			for(i=0;i<sci_max/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n\n";
			cout<<"\t\t\t\t"<<"SOCIAL:      ";
			for(i=0;i<S.soc_marks/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n";
			cout<<"\t\t\t\t"<<"MAX_SOCIAL:  ";
			for(i=0;i<soc_max/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n\n";
			cout<<"\t\t\t\t"<<"KANNADA:     ";
			for(i=0;i<S.kan_marks/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n";
			cout<<"\t\t\t\t"<<"MAX_KANNADA: ";
			for(i=0;i<kan_max/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n\n";
			cout<<"\t\t\t\t"<<"ENGLISH:     ";
			for(i=0;i<S.eng_marks/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n";
			cout<<"\t\t\t\t"<<"MAX_ENGLISH: ";
			for(i=0;i<eng_max/4;i++)
			{
					cout<<ch;
					Sleep(20);
			}
			cout<<"\n\n";
			cout<<"\t\t\t\t\t     ";
			for(i=0;i<25;i++)
			{
				if(i%6==0)
				{
					cout<<i*4+j;
					j++;
				}
				else
				{
					cout<<" ";
				}
			}
			getch();
			return;
		}
		
		
	}
	gotoxy(40,7);
	cout<<"RESULT YET TO BE UPLOADED \n";
	
	getch();
	file.close();
}
void teacher::view_performance()
{
	teacher S,A;
	system("cls");
	cout<<"\n\n\n\t\t\t\t\t\t Enter School id: ";
	if(!A.get_school_id())
	{
		cout<<"\n\n\t\t\t\t INVALID SCHOOL ID \n";
		return;
	}
	system("cls");
	ifstream file;
	file.open("marks.txt");
	while(file>>S.school_id>>S.m_marks>>S.sci_marks>>S.soc_marks>>S.kan_marks>>S.eng_marks)
	{
		if(S.school_id==A.school_id)
		{
			gotoxy(40,7);
			cout<<"---------------MARKS SHEET--------------\n\n";
			cout<<"\t\t\t\t\t\t   MATHS : "<<S.m_marks<<endl;
			cout<<"\t\t\t\t\t\t   SCIENCE : "<<S.sci_marks<<endl;
			cout<<"\t\t\t\t\t\t   SOCIAL : "<<S.soc_marks<<endl;
			cout<<"\t\t\t\t\t\t   KANNADA : "<<S.kan_marks<<endl;
			cout<<"\t\t\t\t\t\t   ENGLISH : "<<S.eng_marks<<endl;
			getch();
			return;
		}
	}
	gotoxy(40,7);
	cout<<"RESULT YET TO BE UPLOADED \n";
	
	getch();
	file.close();
}
void teacher::view_all_result()
{
	system("cls");
	ifstream file1,file2;
	teacher S,A;
	file1.open("student.txt");
	file2.open("marks.txt");
	gotoxy(30,7);
	cout<<"---------------------COMPLETE RESULT SHEET --------------------\n\n";
	cout<<"   School id \t Name \t\t mat_marks \t sci_marks \t soc_marks \t kan_marks \t eng_marks \n";
	cout<<"----------------------------------------------------------------------------------------------------------\n";
	while((file1>>A.school_id>>A.fname>>A.lname>>A.dob>>A.email>>A.ph_num)&&(file2>>A.school_id>>A.m_marks>>A.sci_marks>>A.soc_marks>>A.kan_marks>>A.eng_marks))
	{
		cout<<"   "<<A.school_id<<"\t\t  "<<A.fname<<" "<<A.lname<<"\t\t  "<<A.m_marks<<"\t\t  "<<A.sci_marks<<"\t\t  "<<A.soc_marks<<"\t\t  "<<A.kan_marks<<"\t\t  "<<A.eng_marks<<endl;
	}
getch();
}
int main()
{
	create_files();
	max_finder();
	system("color 0A");
	gotoxy(0,10);
	head();
	gotoxy(35,14);
	cout<<"Connecting to database: ";
	gotoxy(60,14);
	loading();
	gotoxy(35,17);
	cout<<"\t      <CONNECTION COMPLETED>";
	gotoxy(35,19);
	cout<<"\t  <PRESS ANY KEY TO CONTINUE>";
	getch();
	
	int i=1;
	do
	{
		system("cls");
		cout<<"\n";
		head();
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t  ----------------\n";
		cout<<"\t\t\t\t\t\t  |   MENU       |\n";
		cout<<"\t\t\t\t\t\t  |1. Student    |\n";
		cout<<"\t\t\t\t\t\t  |2. Admin      |\n";
		cout<<"\t\t\t\t\t\t  |3. Teacher    |\n";
		cout<<"\t\t\t\t\t\t  |4. Exit       |\n";
		cout<<"\t\t\t\t\t\t  ----------------\n";
		cout<<"\n\n\t\t\t\t Enter choice : ";
		cin>>i;
		switch(i)
		{
			case 1: student s;
					
					s.display_student_menu();
					break;
			case 2: admin a;
					system("cls");
					if(a.check_admin())
					{
						cout<<"\n\n\t\t\t\t\t\t ACCESS DENIED ";
						getch();
						break;
					}
					a.display_admin_menu();
					break;
			case 3: teacher t;
					t.display_teacher_menu();
					break;
			case 4: 
					cout<<"\n\n\t\t\t\t\t EXITING  :  ";
					loading();
					cout<<"\n\n\n";
					break;
			default:cout<<"Invalid choice \n";
					
		}
		
	}while(i!=4);
	return 0;
}
