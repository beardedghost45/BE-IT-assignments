//============================================================================
// Name        : Assignment9.cpp
// Author      : Devashish
// Version     : 1.0
// Copyright   : GNU Public Lincense
// Description : Hashing
//============================================================================

#include <iostream>
#include <string.h>

using namespace std;

class User
{
	long unsigned int tel;
	char* name;
	int link;
public:
	User()
	{
		tel = 1;
		name = new char[20];
		strcpy(name,"Empty");
		link = -1;
	}
	void getdata()
	{
		cout<<"\n Enter the data for the user - ";
		cout<<"\n Telephone number - ";
		while(tel == 1)
		{
			cin>>tel;
			if(tel >= 999999999 && tel <= 9999999999)
				break;
			else
			{
				cout<<"\n Invalid phone number please try again - ";
				tel=1;
			}
		}
		cout<<"\n Name of the user - ";
		cin>>name;
	}
	void putdata()
	{
		cout<<"\t"<<tel<<"\t"<<name<<"\t"<<link;
	}
	inline int getIndex(int n)
	{
		return tel%n;
	}
	inline long unsigned int getTel()
	{
		return tel;
	}
	inline int getLink()
	{
		return link;
	}
	inline void setLink(int l)
	{
		link = l;
	}
};

int main() {

	long unsigned int no;
	int choice, n, index, flg, check=0, i=0,j=0, k=0;

	User *table1, *table2, *temp;

	do
	{
		cout<<"\n\n\n ____________________________________";
		cout<<"\n|                                    ";
		cout<<"\n|               MAIN MENU             ";
		cout<<"\n|____________________________________";
		cout<<"\n|                                    ";
		cout<<"\n|  1. With Replacement   ";
		cout<<"\n|  2. Without replacement";
		cout<<"\n|  3. Exit                          ";
		cout<<"\n|____________________________________";
		cout<<"\n Enter your choice - ";
		cin>>choice;

		switch(choice)
		{
			case 1:

				do
				{
					cout<<"\n\n\n ____________________________________";
					cout<<"\n|                                    ";
					cout<<"\n|               SUB MENU             ";
					cout<<"\n|____________________________________";
					cout<<"\n|                                    ";
					cout<<"\n|  1. Create Table   ";
					cout<<"\n|  2. Insert ";
					cout<<"\n|  3. Search ";
					cout<<"\n|  4. Display ";
					cout<<"\n|  5. Exit to main menu";
					cout<<"\n|____________________________________";
					cout<<"\n Enter your choice - ";
					cin>>choice;

					switch(choice)
					{
							case 1:
							cout<<"\n Enter the number of records in the hash table - ";
							cin>>n;
							table1 = new User[n];
							cout<<"\n\n INFO : Table was created successfully";
							check = n;
							break;

						case 2:
							i = 0;
							j = 0;
							k = 0;
							if(check == 0)
							{
								cout<<"\n No space in the hash table";
								break;
							}
							temp = new User;
							temp->getdata();
							index = temp->getIndex(n);

							// situation 1
							if(table1[index].getTel() == 1)
							{
								table1[index] = *temp;
							}
							// situation 2
							else if(table1[index].getIndex(n) == index)
							{
								while(table1[index].getTel() != 1)
								{
									table1[index].setLink(index+1);
									index++;
								}
								table1[index] = *temp;	
							}
							// situation 3
							else if(table1[index].getIndex(n) != index)
							{			
								j = index;

								k = 0;
								while(table1[k].getLink() != index && k < n)
									k++;

								while(table1[index].getTel() != 1 && i < n)
								{
									index = (index+1)%n;
									i++;
								}
								if(i == n)
								{
									cout<<"\n No space in the hash table";
									break;
								}

								table1[index] = table1[j];
								table1[k].setLink(index);
								table1[j] = *temp;
							}

							delete temp;
							check --;
							cout<<"\n\n INFO : Record was added successfully";
							break;

						case 3:
							flg = 1;
							cout<<"\n Enter the telephone number of user to be searched - ";
							cin>>no;

							index = no%n;

							if(table1[index].getTel() == no)
							{
								flg = 0;
								table1[index].putdata();
							}
							else
							{
								while(table1[index].getLink() != -1)
								{
									index = table1[index].getLink();

									if(table1[index].getTel() == no)
									{
										flg = 0;
										table1[index].putdata();
										break;
									}
								}
							}

							if(flg == 1)
								cout<<"\n The number you are searching was not found in the table";
							break;

						case 4:
							cout<<"Sr no \t Telephone \t Name \t Link\n";
							for(int i = 0; i<n; i++)
							{
								cout<<"\n";
								cout<<i<<"\t";
								table1[i].putdata();
							}
							break;
						case 5:
							break;
						default:
							break;
					}

				}while(choice != 5);

				break;

			case 2:

				do
				{
					cout<<"\n\n\n ____________________________________";
					cout<<"\n|                                    ";
					cout<<"\n|               SUB MENU             ";
					cout<<"\n|____________________________________";
					cout<<"\n|                                    ";
					cout<<"\n|  1. Create Table   ";
					cout<<"\n|  2. Insert ";
					cout<<"\n|  3. Search ";
					cout<<"\n|  4. Display ";
					cout<<"\n|  5. Exit to main menu";
					cout<<"\n|____________________________________";
					cout<<"\n Enter your choice - ";
					cin>>choice;

					switch(choice)
					{
						case 1:
							cout<<"\n Enter the number of records in the hash table - ";
							cin>>n;
							table2 = new User[n];
							cout<<"\n\n INFO : Table was created successfully";
							check = n;
							break;
						case 2:
							i = 0;
							if(check == 0)
							{
								cout<<"\n No space in the hash table";
								break;
							}
							temp = new User;
							temp->getdata();
							index = temp->getIndex(n);
							while(table2[index].getTel() != 1)
							{
								table2[index].setLink(index+1);
								index++;
							}
							table2[index] = *temp;
							delete temp;
							check --;
							cout<<"\n\n INFO : Record was added successfully";
							break;
						case 3:
							flg = 1;
							cout<<"\n Enter the telephone number of user to be searched - ";
							cin>>no;

							index = no%n;

							if(table2[index].getTel() == no)
							{
								flg = 0;
								table2[index].putdata();
							}
							else
							{
								while(table2[index].getLink() != -1)
								{
									index = table2[index].getLink();

									if(table2[index].getTel() == no)
									{
										flg = 0;
										table2[index].putdata();
										break;
									}
								}
							}

							if(flg == 1)
								cout<<"\n The number you are searching was not found in the table";
							break;
						case 4:
							cout<<"Sr no \t Telephone \t Name \t Link\n";
							for(int i = 0; i<n; i++)
							{
								cout<<"\n";
								cout<<i<<"\t";
								table2[i].putdata();
							}
							break;
						case 5:
							break;
						default:
							break;
					}

				}while(choice != 5);

				break;

			case 3:
				return 0;

			default:
				break;
		}

	}while(1);
return 0;
}
