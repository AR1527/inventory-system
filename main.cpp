// Book Shope Project With File Handling in C++.
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>

using namespace std;



class book
{
	public:
		void add_book();
		void show_books();
		void check_book();
		void update_book();
		void del_book();
};
	
	void book::add_book()
	{
		system("cls");
		fstream file;
		int no_copy;
		string b_name,a_name,b_id;
		cout<<"\n\n\t\t\t\t Add New Book";
		cout<<"\n\n\t\t\t\t Use - Instead of Spaces";
		cout<<"\n\n Book ID : ";
		cin>>b_id;
		cout<<"\n\n Book Name : ";
		cin>>b_name;
		cout<<"\n\n Author Name : ";
		cin>>a_name;
		cout<<"\n\n No. of Copies : ";
		cin>>no_copy;
		file.open("book.txt",ios::out|ios::app);
		file<<" "<<b_id<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n";
		file.close();
	}	
	void book::show_books()
	{
		system("cls");
		fstream file;
		int no_copy;
		string b_name,b_id,a_name;
		cout<<"\n\n Show All Books";
		file.open("book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Opening Error...";
		else
		{
			cout<<"\n\n Book_ID    Book_Name    Author    No. of Copies\n\n";
			file>>b_id>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				cout<<"   "<<b_id<<"     "<<b_name<<"     "<<a_name<<"\t\t"<<no_copy<<"\n\n";
				file>>b_id>>b_name>>a_name>>no_copy;
			}
			file.close();
		}
	}	
	void book::check_book()
	{
		system("cls");
		fstream file;
		int no_copy,count=0;
		string b_id,b_name,a_name,b_idd;
		cout<<"\n\n\t\t\t\tCheck Specific Book";
		file.open("book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Opening Error...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>b_idd;
			file>>b_id>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				if(b_idd == b_id)
				{
					system("cls");
					cout<<"\n\n\t\t\t\tCheck Specific Book";
					cout<<"\n\n\t\t\t\t Use - Instead of Spaces";
					cout<<"\n\n Book ID : "<<b_id;
					cout<<"\n\n\t\t\tName : "<<b_name;
					cout<<"\n\n Author : "<<a_name;
					cout<<"\n\n\t\t\tNo. of Copies : "<<no_copy;
					count++;
					break;	
				}
				file>>b_id>>b_name>>a_name>>no_copy;
			}
			file.close();
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
	}	
	void book::update_book()
	{
		system("cls");
		fstream file,file1;
		int no_copy,no_co,count=0;
		string b_name,b_na,a_name,a_na,b_idd,b_id;
		cout<<"\n\nUpdate Book Record";
		file1.open("book1.txt",ios::app|ios::out);
		file.open("book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Opening Error...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>b_id;
			file>>b_idd>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				if(b_id == b_idd)
				{
					system("cls");
					cout<<"\n\n Update Book Record";
					cout<<"\n\n\t\t\t\t Use - Instead of Spaces";
					cout<<"\n\n New Book Name : ";
					cin>>b_na;
					cout<<"\n\n uthor Name : ";
					cin>>a_na;
					cout<<"\n\n No. of Copies : ";
					cin>>no_co;
					file1<<" "<<b_id<<" "<<b_na<<" "<<a_na<<" "<<no_co<<"\n";
					count++;
				}
				else
				file1<<" "<<b_idd<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n";
				file>>b_idd>>b_name>>a_name>>no_copy;
			}
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
		file.close();
		file1.close();
		remove("book.txt");
		rename("book1.txt","book.txt");
	}	
	void book::del_book()
	{
		system("cls");
		fstream file,file1;
		int no_copy,count=0;
		string b_id,b_idd,b_name,a_name;
		cout<<"\n\n Delete Book Record";
		file1.open("book1.txt",ios::app|ios::out);
		file.open("book.txt",ios::in);
		if(!file)
		cout<<"\n\n Error File Opening...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>b_id;
			file>>b_idd>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				if(b_id == b_idd)
				{
					system("cls");
					cout<<"\n\n\t\t\t\tDelete Book Record";
					cout<<"\n\n One Book is Deleted Successfully...";
					count++;
				}
				else
				file1<<" "<<b_idd<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n";
				file>>b_idd>>b_name>>a_name>>no_copy;
			}
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
		file.close();
		file1.close();
		remove("book.txt");
		rename("book1.txt","book.txt");
	}




class dvd
{
	public:
		void add_dvd();
		void show_dvd();
		void check_dvd();
		void update_dvd();
		void del_dvd();
};

	void dvd::add_dvd()
	{
		system("cls");
		fstream file;
		int no_copy,relyr;
		string dvd_name,direc_name,d_id;
		cout<<"\n\n\t\t\t\t Add New DVD";
		cout<<"\n\n\t\t\t\t Use - Instead of Spaces";
		cout<<"\n\n DVD ID : ";
		cin>>d_id;
		cout<<"\n\n DVD Name : ";
		cin>>dvd_name;
		cout<<"\n\n Director Name : ";
		cin>>direc_name;
		cout<<"\n\n Release Year : ";
		cin>>relyr;
		cout<<"\n\n No. of Copies : ";
		cin>>no_copy;

		file.open("dvd.txt",ios::out|ios::app);
		file<<" "<<d_id<<" "<<dvd_name<<" "<<direc_name<<" "<<relyr<<" "<<no_copy<<"\n";
		file.close();
	}
	void dvd::show_dvd()
	{
		system("cls");
		fstream file;
		int no_copy,relyr;
		string dvd_name,direc_name,d_id;
		cout<<"\n\n\t\t\t\tShow All DVDs";
		file.open("dvd.txt",ios::in);
		if(!file)
		cout<<"\n\n File Opening Error...";
		else
		{
			cout<<"\n\n DVD ID    DVD    Director	Release Year    No. of Copies\n\n";
			file>>d_id>>dvd_name>>direc_name>>relyr>>no_copy;
			while(!file.eof())
			{
				cout<<"   "<<d_id<<"     "<<dvd_name<<"     "<<direc_name<<"	"<<relyr<<"		"<<no_copy<<"\n\n";
				file>>d_id>>dvd_name>>direc_name>>relyr>>no_copy;
			}
			file.close();
		}
	}
	void dvd::check_dvd()
	{
		system("cls");
		fstream file;
		int no_copy,relyr,count=0;
		string dvd_name,direc_name,d_id,d_idd;
		cout<<"\n\n\t\t\t\tCheck Specific DVD";
		file.open("dvd.txt",ios::in);
		if(!file)
		cout<<"\n\n File Opening Error...";
		else
		{
			cout<<"\n\n DVD ID : ";
			cin>>d_idd;
			file>>d_id>>dvd_name>>direc_name>>relyr>>no_copy;
			while(!file.eof())
			{
				if(d_idd == d_id)
				{
					system("cls");
					cout<<"\n\nCheck Specific DVD";
					cout<<"\n\n\t\t\t\t Use - Instead of Spaces";
					cout<<"\n\n DVD ID : "<<d_id;
					cout<<"\n\nName : "<<dvd_name;
					cout<<"\n\n Director : "<<direc_name;
					cout<<"\n\nNo. of Copies : "<<no_copy;
					count++;
					break;	
				}
				file>>d_id>>dvd_name>>direc_name>>relyr>>no_copy;
			}
			file.close();
			if(count == 0)
			cout<<"\n\n DVD ID Not Found...";
		}
	}
	void dvd::update_dvd()
	{
		system("cls");
		fstream file,filecopy;
		int no_copy,no_cop,count=0,relyr,relyr_cop;
		string dvd_name,dvd_na,direc_name,direc_na,d_idd,d_id;
		cout<<"\n\nUpdate DVD Record";
		filecopy.open("dvd1.txt",ios::app|ios::out);
		file.open("dvd.txt",ios::in);
		if(!file)
		cout<<"\n\n File Opening Error...";
		else
		{
			cout<<"\n\n DVD ID : ";
			cin>>d_idd;
			file>>d_id>>dvd_name>>direc_name>>relyr>>no_copy;
			while(!file.eof())
			{
				if(d_id == d_idd)
				{
					system("cls");
					cout<<"\n\n Update DVD Record";
					cout<<"\n\n\t\t\t\t Use - Instead of Spaces";
					cout<<"\n\n New DVD Name : ";
					cin>>dvd_na;
					cout<<"\n\n Director Name : ";
					cin>>direc_na;
					cout<<"\n\n Release Year : ";
					cin>>relyr_cop;
					cout<<"\n\n No. of Copies : ";
					cin>>no_cop;
					filecopy<<" "<<d_id<<" "<<dvd_na<<" "<<direc_na<<" "<<relyr_cop<<" "<<no_cop<<"\n";
					count++;
				}
				else
				filecopy<<" "<<d_idd<<" "<<dvd_name<<" "<<direc_name<<" "<<relyr<<" " <<no_copy<<"\n";
				file>>d_idd>>dvd_name>>direc_name>>relyr>>no_copy;
			}
			if(count == 0)
			cout<<"\n\n DVD ID Not Found...";
		}
		file.close();
		filecopy.close();
		remove("dvd.txt");
		rename("dvd1.txt","dvd.txt");
	}
	void dvd::del_dvd()
		{
			system("cls");
			fstream file,file1;
			int no_copy,count=0,relyr;
			string d_id,d_idd,dvd_name,direc_name;
			cout<<"\n\n\t\t\t\tDelete DVD Record";
			file1.open("dvd1.txt",ios::app|ios::out);
			file.open("dvd.txt",ios::in);
			if(!file)
			cout<<"\n\n Error File Opening...";
			else
				{
				cout<<"\n\n DVD ID : ";
				cin>>d_id;
				file>>d_idd>>dvd_name>>direc_name>>relyr>>no_copy;
				while(!file.eof())
				{
					if(d_id == d_idd)
					{
						system("cls");
						cout<<"\n\n Delete DVD Record";
						cout<<"\n\n DVD Deleted Successfully...";
						count++;
					}
					else
					file1<<" "<<d_idd<<" "<<dvd_name<<" "<<direc_name<<" "<<relyr<<"  "<<no_copy<<"\n";
					file>>d_idd>>dvd_name>>direc_name>>relyr>>no_copy;
				}
				if(count == 0)
				cout<<"\n\n Book ID Not Found...";
			}
			file.close();
			file1.close();
			remove("dvd.txt");
			rename("dvd1.txt","dvd.txt");
		}



class CDs
{
	public: 
		void add_cd();
		void show_cds();
		void check_cd();
		void update_cd();
		void del_cd();
};

	void CDs::add_cd()
	{
		system("cls");
		fstream file;
		int no_copy,relyr;
		string cd_name,art_name,cd_id;
		cout<<"\n\n\t\t\t\t Add New CD";
		cout<<"\n\n\t\t\t\t Use - Instead of Spaces";
		cout<<"\n\n CD ID : ";
		cin>>cd_id;
		cout<<"\n\n CD Name : ";
		cin>>cd_name;
		cout<<"\n\n Artist Name : ";
		cin>>art_name;
		cout<<"\n\n Release Year : ";
		cin>>relyr;
        cout<<"\n\n No. of Copies : ";
		cin>>no_copy;

		file.open("cd.txt",ios::out|ios::app);
		file<<" "<<cd_id<<" "<<cd_name<<" "<<art_name<<" "<<relyr<<" "<<no_copy<<"\n";
		file.close();
	}
	void CDs::show_cds()
	{
		system("cls");
		fstream file;
		int no_copy,relyr;
		string cd_name,art_name,cd_id;
		cout<<"\n\n Show All CDs";
		file.open("cd.txt",ios::in);
		if(!file)
		cout<<"\n\n File Opening Error...";
		else
		{
			cout<<"\n\n CD_ID    CD    Artist 	Release_Year    No. of Copies\n\n";
			file>>cd_id>>cd_name>>art_name>>relyr>>no_copy;
			while(!file.eof())
			{
				cout<<"   "<<cd_id<<"     "<<cd_name<<"     "<<art_name<<"	"<<relyr<<"		"<<no_copy<<"\n\n";
				file>>cd_id>>cd_name>>art_name>>relyr>>no_copy;
			}
			file.close();
		}
	}
	void CDs::check_cd()
	{
		system("cls");
		fstream file;
		int no_copy,relyr,count=0;
		string cd_name,art_name,cd_id,cd_idd;
		cout<<"\n\n Check Specific CD";
		file.open("cd.txt",ios::in);
		if(!file)
		cout<<"\n\n File Opening Error...";
		else
		{
			cout<<"\n\n CD ID : ";
			cin>>cd_idd;
			file>>cd_id>>cd_name>>art_name>>relyr>>no_copy;
			while(!file.eof())
			{
				if(cd_idd == cd_id)
				{
					system("cls");
					cout<<"\n\nCheck Specific CD";
					cout<<"\n\n\t\t\t\t Use - Instead of Spaces";
					cout<<"\n\n CD ID : "<<cd_id;
					cout<<"\n\n CD Name : "<<cd_name;
					cout<<"\n\n Artist : "<<art_name;
					cout<<"\n\n Release Year: "<<relyr;
					cout<<"\n\nNo. of Copies : "<<no_copy;
					count++;
					break;	
				}
				file>>cd_id>>cd_name>>art_name>>relyr>>no_copy;
			}
			file.close();
			if(count == 0)
			cout<<"\n\n CD ID Not Found..."; 
		}
	}
	void CDs::update_cd()
	{
		system("cls");
		fstream file,filecopy;
		int no_copy,no_cop,count=0,relyr,relyr_cop;
		string cd_name,cd_na,art_name,art_na,cd_idd,cd_id;
		cout<<"\n\nUpdate CD Record";
		filecopy.open("cd1.txt",ios::app|ios::out);
		file.open("cd.txt",ios::in);
		if(!file)
		cout<<"\n\n File Opening Error...";
		else
		{
			cout<<"\n\n CD ID : ";
			cin>>cd_idd;
			file>>cd_id>>cd_name>>art_name>>relyr>>no_copy;
			while(!file.eof())
			{
				if(cd_id == cd_idd)
				{
					system("cls");
					cout<<"\n\n Update CD Record";
					cout<<"\n\n Use - Instead of Spaces";
					cout<<"\n\n New CD Name : ";
					cin>>cd_na;
					cout<<"\n\n New Artist Name : ";
					cin>>art_na;
					cout<<"\n\n New Release Year : ";
					cin>>relyr_cop;
					cout<<"\n\n New No. of Copies : ";
					cin>>no_cop;
					filecopy<<" "<<cd_id<<" "<<cd_na<<" "<<art_na<<" "<<relyr_cop<<" "<<no_cop<<"\n";
					count++;
				}
				else
				filecopy<<" "<<cd_idd<<" "<<cd_name<<" "<<art_name<<" "<<relyr<<" " <<no_copy<<"\n";
				file>>cd_idd>>cd_name>>art_name>>relyr>>no_copy;
			}
			if(count == 0)
			cout<<"\n\n CD ID Not Found...";
		}
		file.close();
		filecopy.close();
		remove("cd.txt");
		rename("cd1.txt","cd.txt");
	}
	void CDs::del_cd()
		{
			system("cls");
			fstream file,file1;
			int no_copy,count=0,relyr;
			string cd_id,cd_idd,cd_name,art_name;
			cout<<"\n\n\t\t\t\tDelete CD Record";
			file1.open("cd1.txt",ios::app|ios::out);
			file.open("cd.txt",ios::in);
			if(!file)
			cout<<"\n\n Error File Opening...";
			else
				{
				cout<<"\n\n CD ID : ";
				cin>>cd_id;
				file>>cd_idd>>cd_name>>art_name>>relyr>>no_copy;
				while(!file.eof())
				{
					if(cd_id == cd_idd)
					{
						system("cls");
						cout<<"\n\n Delete CD Record";
						cout<<"\n\n CD Deleted Successfully...";
						count++;
					}
					else
					file1<<" "<<cd_idd<<" "<<cd_name<<" "<<art_name<<" "<<relyr<<"  "<<no_copy<<"\n";
					file>>cd_idd>>cd_name>>art_name>>relyr>>no_copy;
				}
				if(count == 0)
				cout<<"\n\n CD ID Not Found...";
			}
			file.close();
			file1.close();
			remove("cd.txt");
			rename("cd1.txt","cd.txt");
		}


class magazine
{
	public: 
		void add_mag();
		void show_mag();
		void check_mag();
		void update_mag();
		void del_mag();
};

	void magazine::add_mag()
	{
		system("cls");
		fstream file;
		int no_copy,relyr;
		string mag_name,pub_name,mag_id;
		cout<<"\n\n\t\t\t\t Add New Magazine";
		cout<<"\n\n Use - Instead of Spaces";
		cout<<"\n\n Magazine ID : ";
		cin>>mag_id;
		cout<<"\n\n Magazine Name : ";
		cin>>mag_name;
		cout<<"\n\n Publisher : ";
		cin>>pub_name;
		cout<<"\n\n Release Year : ";
		cin>>relyr;
        cout<<"\n\n No. of Copies : ";
		cin>>no_copy;

		file.open("mag.txt",ios::out|ios::app);
		file<<" "<<mag_id<<" "<<mag_name<<" "<<pub_name<<" "<<relyr<<" "<<no_copy<<"\n";
		file.close();
	}
	void magazine::show_mag()
	{
		system("cls");
		fstream file;
		int no_copy,relyr;
		string mag_name,pub_name,mag_id;
		cout<<"\n\n\t\t\t\tShow All Magazines";
		file.open("mag.txt",ios::in);
		if(!file)
		cout<<"\n\n File Opening Error...";
		else
		{
			cout<<"\n\n Magazine_ID    Magazine    Publisher 	Release_Year    No. of Copies\n\n";
			file>>mag_id>>mag_name>>pub_name>>relyr>>no_copy;
			while(!file.eof())
			{
				cout<<"   "<<mag_id<<"     "<<mag_name<<"     "<<pub_name<<"	"<<relyr<<"		"<<no_copy<<"\n\n";
				file>>mag_id>>mag_name>>pub_name>>relyr>>no_copy;
			}
			file.close();
		}
	}
	void magazine::check_mag()
	{
		system("cls");
		fstream file;
		int no_copy,relyr,count=0;
		string mag_name,pub_name,mag_id,mag_idd;
		cout<<"\n\n Check Specific Magazine";
		file.open("mag.txt",ios::in);
		if(!file)
		cout<<"\n\n File Opening Error...";
		else
		{
			cout<<"\n\n Magazine ID : ";
			cin>>mag_idd;
			file>>mag_id>>mag_name>>pub_name>>relyr>>no_copy;
			while(!file.eof())
			{
				if(mag_idd == mag_id)
				{
					system("cls");
					cout<<"\n\nCheck Specific Magazine";
					cout<<"\n\n Use - Instead of Spaces";
					cout<<"\n\n Magazine ID : "<<mag_id;
					cout<<"\n\n Magazine Name : "<<mag_name;
					cout<<"\n\n Publisher : "<<pub_name;
					cout<<"\n\n Release Year: "<<relyr;
					cout<<"\n\nNo. of Copies : "<<no_copy;
					count++;
					break;	
				}
				file>>mag_id>>mag_name>>pub_name>>relyr>>no_copy;
			}
			file.close();
			if(count == 0)
			cout<<"\n\n CD ID Not Found...";
		}
	}
	void magazine::update_mag()
	{
		system("cls");
		fstream file,filecopy;
		int no_copy,no_cop,count=0,relyr,relyr_cop;
		string mag_name,mag_na,pub_name,pub_na,mag_idd,mag_id;
		cout<<"\n\nUpdate Magazine Record";
		filecopy.open("mag1.txt",ios::app|ios::out);
		file.open("mag.txt",ios::in);
		if(!file)
		cout<<"\n\n File Opening Error...";
		else
		{
			cout<<"\n\n Magazine ID : ";
			cin>>mag_idd;
			file>>mag_id>>mag_name>>pub_name>>relyr>>no_copy;
			while(!file.eof())
			{
				if(mag_id == mag_idd)
				{
					system("cls");
					cout<<"\n\n Update Magazine Record";
					cout<<"\n\n Use - Instead of Spaces";
					cout<<"\n\n New Magazine Name : ";
					cin>>mag_na;
					cout<<"\n\n New Publisher Name : ";
					cin>>pub_na;
					cout<<"\n\n New Release Year : ";
					cin>>relyr_cop;
					cout<<"\n\n New No. of Copies : ";
					cin>>no_cop;
					filecopy<<" "<<mag_id<<" "<<mag_na<<" "<<pub_na<<" "<<relyr_cop<<" "<<no_cop<<"\n";
					count++;
				}
				else
				filecopy<<" "<<mag_idd<<" "<<mag_name<<" "<<pub_name<<" "<<relyr<<" " <<no_copy<<"\n";
				file>>mag_idd>>mag_name>>pub_name>>relyr>>no_copy;
			}
			if(count == 0)
			cout<<"\n\n Magazine ID Not Found...";
		}
		file.close();
		filecopy.close();
		remove("mag.txt");
		rename("mag1.txt","mag.txt");
	}
	void magazine::del_mag()
		{
			system("cls");
			fstream file,file1;
			int no_copy,count=0,relyr;
			string mag_id,mag_idd,mag_name,pub_name;
			cout<<"\n\n Delete Magazine Record";
			file1.open("mag1.txt",ios::app|ios::out);
			file.open("mag.txt",ios::in);
			if(!file)
			cout<<"\n\n Error File Opening...";
			else
				{
				cout<<"\n\n Magazine ID : ";
				cin>>mag_id;
				file>>mag_idd>>mag_name>>pub_name>>relyr>>no_copy;
				while(!file.eof())
				{
					if(mag_id == mag_idd)
					{
						system("cls");
						cout<<"\n\n Delete Magazine Record";
						cout<<"\n\n Magazine Deleted Successfully...";
						count++;
					}
					else
					file1<<" "<<mag_idd<<" "<<mag_name<<" "<<pub_name<<" "<<relyr<<"  "<<no_copy<<"\n";
					file>>mag_idd>>mag_name>>pub_name>>relyr>>no_copy;
				}
				if(count == 0)
				cout<<"\n\n Magazine ID Not Found...";
			}
			file.close();
			file1.close();
			remove("mag.txt");
			rename("mag1.txt","mag.txt");
		}




class menu
{
	public:
		void main_panel();
		void book_panel();
		void DVD_panel();
		void CD_panel();
		void mag_panel();
};

void menu::main_panel()
	{
		system("cls");
		cout<<"\n\n Control Panel";
		cout<<"\n\n 1. Books";
		cout<<"\n 2. DVDs";
		cout<<"\n 3. Magazines";
		cout<<"\n 4. CDs";
		cout<<"\n 0. Exit";
	}
void menu::book_panel()
	{
		system("cls");
		cout<<"\n\n Manage Books";
		cout<<"\n\n 1. Add New Book";
		cout<<"\n 2. Display Books";
		cout<<"\n 3. Search For Book";
		cout<<"\n 4. Update Book";
		cout<<"\n 5. Delete Book";
		cout<<"\n 0. Exit";
	}
void menu::DVD_panel()
	{
		system("cls");
		cout<<"\n\n Manage DVDs";
		cout<<"\n\n 1. Add New DVD";
		cout<<"\n 2. Display DVDs";
		cout<<"\n 3. Search For DVD";
		cout<<"\n 4. Update DVD";
		cout<<"\n 5. Delete DVD";
		cout<<"\n 0. Exit";
	}
void menu::CD_panel()
	{
		system("cls");
		cout<<"\n\n Manage CDs";
		cout<<"\n\n 1. Add New CD";
		cout<<"\n 2. Display CDs";
		cout<<"\n 3. Search For CD";
		cout<<"\n 4. Update CDs";
		cout<<"\n 5. Delete CDs";
		cout<<"\n 0. Exit";
	}
void menu::mag_panel()
	{
		system("cls");
		cout<<"\n\n Manage Magazines";
		cout<<"\n\n 1. Add New Magazine";
		cout<<"\n 2. Display Magazines";
		cout<<"\n 3. Search For Magazine";
		cout<<"\n 4. Update Magazines";
		cout<<"\n 5. Delete Magazines";
		cout<<"\n 0. Exit";
	}


main()
{
	
	int choice,choice2,choice3,choice4,choice5;
	char x;
	
	CDs cds;
	dvd d;
	menu m;
	book b;
	magazine mag;
	
	p:
	m.main_panel();
	cout<<"\n\n Your Choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			b:
			m.book_panel();
			cout<<"\n\n Your Choice : ";
			cin>>choice2;
			if(choice2 == 1){
				b.add_book();
				break;

			}else if (choice2 == 2){
				b.show_books();
				break;

			}else if (choice2 == 3){
				b.check_book();
				break;

			}else if (choice2 == 4){
				b.update_book();
				break;

			}else if (choice2 == 5){
				b.del_book();
				break;

			} else if (choice2 == 0){
				break;
				goto p;
			} else
			{
				cout<<"\n\n Invalid Input";
				break;
			}
			goto b;
			break;
		case 2:
			m.DVD_panel();
			d:
			cout<<"\\n\\n Your Choice : ";
			cin>>choice3;
			if(choice3 == 1){
				d.add_dvd();
				break;

			}else if (choice3 == 2){
				d.show_dvd();
				break;

			}else if (choice3 == 3){
				d.check_dvd();
				break;

			}else if (choice3 == 4){
				d.update_dvd();
				break;

			}else if (choice3 == 5){
				d.del_dvd();
				break;

			} else if (choice3 == 0){
				break;
				goto p;
			} else
			{
				cout<<"\n\n Invalid Input";
				break;
			}
			break;
			goto d;
		case 3:
			m.mag_panel();
			m:
			cout<<"\n\n Your Choice: ";
			cin>>choice4;
			if(choice4 == 1){
				mag.add_mag();
				break;

			}else if (choice4 == 2){
				mag.show_mag();
				break;

			}else if (choice4 == 3){
				mag.check_mag();
				break;

			}else if (choice4 == 4){
				mag.update_mag();
				break;

			}else if (choice4 == 5){
				mag.del_mag();
				break;

			} else if (choice4 == 0){
				break;
				goto p;
			} else
			{
				cout<<"\n\n Invalid Input";
				break;
			}
			break;
			goto m;
		case 4:
			m.CD_panel();
			c:
			cout<<"\n\n Your Choice: ";
			cin>>choice5;
			if(choice5 == 1){
				cds.add_cd();
				break;

			}else if (choice5 == 2){
				cds.show_cds();
				break;

			}else if (choice5 == 3){
				cds.check_cd();
				break;

			}else if (choice5 == 4){
				cds.update_cd();
				break;

			}else if (choice5 == 5){
				cds.del_cd();
				break;

			} else if (choice5 == 0){
				break;
				goto p;
			} else
			{
				cout<<"\n\n Invalid Input";
				break;
			}
			break;
			goto c;


		case 5:
			exit(0);
		default:
			cout<<"\n\n Invalid Value...Please Try Again...";
	}
	getch();
	goto p;
}