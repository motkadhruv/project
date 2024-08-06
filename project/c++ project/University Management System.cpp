#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;


class university{
	
	private:
//		mamber strig ntype function 
		string RollNo,Name,Subject,Address;
	
	public:
	   university():RollNo(""),Name(""),Subject(""),Address(""){}
//	   set function
	   setRollNo(string rollno){
	   	RollNo = rollno;
	   }
	   
	   	setName(string name){
	   	Name = name;
	   }
	   
	   	setSubject(string subject){
	   	Subject = subject;
	   }
	   
	   setAddress(string address){
	   	Address = address;
	   }
	   
//	   get function

       string getRollNo(){
	        return RollNo;
       }
 
       string getName(){
	        return Name;
       }
	   
       string getSubject(){
	        return Subject;
       }
	   
       string getAddress(){
	        return Address;
       }	   	          
	   	
};

add(university student)
{
	string rollNo,name,subject,address;
	
	cout<<"\tEnter Rollno Of Student:";
	cin>>rollNo;
	student.setRollNo(rollNo);
	
    cout<<"\tEnter name Of Student:";
	cin>>name;
	student.setName(name);
	
	cout<<"\tEnter subject Of Student:";
	cin>>subject;
	student.setSubject(subject);
	
	cout<<"\tEnter Address Of Student:";
	cin>>address;
	student.setAddress(address);
	
	ofstream out("D:/university.txt",ios::app); 
	
	if(!out)
	{
		cout<<"\tError: File can't Opan"<<endl;
	}
	
	else
	{
		out<<"\t"<<student.getRollNo()<<":"<<student.getName()<<":"<<student.getSubject()<<":"<<student.getAddress()<<":"<<endl<<endl;
	}
	
	out.close();
	cout<<"\tStudent Added Successfuly!"<<endl;
}

search()
{
	string rollNo;
	cout<<"\tEnter RollNo of Student: ";
	cin>>rollNo;
	
	ifstream in("D:/university.txt");
	if(!in)
	{
		cout<<"\tError: File Can't Opan"<<endl;
		
	}
	string line;
	bool found = false;
	while(getline(in,line))
	{
		int data= line.find(rollNo);
		if(data != string::npos)
		{
			cout<<"\t"<<line<<endl;
			found = true;
		}
		if(!found)
		{
			cout<<"\tStudent Not Found!"<<endl;
		}
	}
	in.close();
};

update(university student)
{
	string rollNo;
	cout<<"\tEnter RollNO of Student:";
	cin>>rollNo;
	
	ifstream infile("D:/university.txt");
	ofstream outfile("D:/university temp.txt");
	if(!infile || !outfile)
	{
		cout<<"\t Error : Flie Can't Opan";
		
	}
	
	string line;
	bool found = false;
	while(getline(infile,line))
	{
		int pos=line.find(rollNo);
		if(pos!= string::npos)
		{
				string address;
				cout<<"\tEnter New Address";
				cin>>address;
				student.setAddress(address);
				
				int newpos = line.find_last_of(':');
				line.replace(newpos + 2, string::npos, student.getAddress());	
		}
		outfile<<line<<endl;
		found = true;
	 } 
	 if(!found)
	 {
	 	cout<<"\tStudent Not Found";
	 	
	 }
	 outfile.close();
	 infile.close();
	 remove("D:/university.txt");
	 rename("D:/university temp.txt", "D:/university.txt");
	 cout<<"\tData Updated"<<endl;
}



int main()
{
	
	university student;
	
	bool exit = false;
	while(!exit){
		system("cls");
		
		int val;
		
		cout<<"\tWelcome To University Management System"<<endl;
		cout<<"\t*********************************************"<<endl;
		cout<<"\t1.Add Student."<<endl;
		cout<<"\t2.search student."<<endl;
		cout<<"\t3.Update Data Of Student."<<endl;
		cout<<"\t4..Exit"<<endl;
		cout<<"\tEnter Your Choice"<<endl;
		cin>>val;
		
		if(val==1)
		{
			system("cls");
			add(student);
			Sleep(6000);
		}
		
		else if(val==2)
		{
			system("cls");
			search();
			Sleep(6000);
		}
		
		if(val==3)
		{
			system("cls");
			update(student);
			Sleep(6000);
		}
		
		if(val==4)
		{
			system("cls");
			exit =true;
			cout<<"\t Good Luck"<<endl;
			Sleep(6000);
		}
	
		
	}
}
