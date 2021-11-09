#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<cstdio>
#include<stdlib.h>
using namespace std;
struct r{
    char dish[50];
    int key;
    float price;
}r;
class Resturant
{
public:
    void create();
    void query();
    void display();
    void update();
    void delet();
    void admin();
};
void signup();
void account_check();
int validate();
void login();


void signup();
{
	printf("Enter Your name\t");
	scanf("%s", temp_name);

	printf("Enter Your Age\t");
	scanf("%d", &temp_age);

	printf("Enter Your Email\t");
	scanf("%s", temp_email);

	printf("Enter Password\t");
	scanf("%s", temp_password1);

	printf("Confirm Password\t");
	scanf("%s", temp_password2);

	printf("Enter Your Mobile Number\t");
	scanf("%s", temp_mobile);

	// Function Call to validate
	// the user creation
	x = validate();
	if (x == 1)
		account_check();
}

// Function to validate the user
// for signup process
int validate()
{
	// Validate the name
	for (i = 0; temp_name[i] != '\0'; i++) {
		if (!((temp_name[i] >= 'a' && temp_name[i] <= 'z')
			|| (temp_name[i] >= 'A'
				&& temp_name[i] <= 'Z'))) {
			printf("\nPlease Enter the");
			printf("valid Name\n");
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		count = 0;

		// Validate the Email ID
		for (i = 0;
			temp_email[i] != '\0'; i++) {
			if (temp_email[i] == '@'
				|| temp_email[i] == '.')
				count++;
		}
		if (count >= 2
			&& strlen(temp_email) >= 5) {
			// Validating the Password and
			// Check whether it matches
			// with Conform Password
			if (!strcmp(temp_password1,
						temp_password2)) {
				if (strlen(temp_password1) >= 8
					&& strlen(temp_password1) <= 12) {
					caps = 0;
					small = 0;
					numbers = 0;
					special = 0;
					for (i = 0; temp_password1[i] != '\0';
						i++) {
						if (temp_password1[i] >= 'A'
							&& temp_password1[i] <= 'Z')
							caps++;
						else if (temp_password1[i] >= 'a'
								&& temp_password1[i]
										<= 'z')
							small++;
						else if (temp_password1[i] >= '0'
								&& temp_password1[i]
										<= '9')
							numbers++;
						else if (temp_password1[i] == '@'
								|| temp_password1[i] == '&'
								|| temp_password1[i] == '#'
								|| temp_password1[i]
										== '*')
							special++;
					}
					if (caps >= 1 && small >= 1
						&& numbers >= 1 && special >= 1) {
						// Validating the Input age
						if (temp_age != 0 && temp_age > 0) {
							// Validating the Input mobile
							// number
							if (strlen(temp_mobile) == 10) {
								for (i = 0; i < 10; i++) {
									if (temp_mobile[i]
											>= '0'
										&& temp_mobile[i]
											<= '9') {
										success = 1;
									}
									else {
										printf("\n\nPlease");
										printf("Enter Valid ");
										printf("Mobile "
											"Number\n\n");
										return 0;
										break;
									}
								}

								// Success is assigned with
								// value 1, Once every
								// inputs are correct.
								if (success == 1)
									return 1;
							}
							else {
								printf("\n\nPlease Enter the");
								printf("10 digit mobile");
								printf("number\n\n");
								return 0;
							}
						}
						else {
							printf("\n\nPlease Enter ");
							printf("the valid age\n\n");
							return 0;
						}
					}
					else {
						printf("\n\nPlease Enter the");
						printf("strong password, Your ");
						printf("password must contain ");
						printf("atleast one uppercase, ");
						printf("Lowercase, Number and ");
						printf("special character\n\n");
						return 0;
					}
				}
				else {
					printf("\nYour Password is very");
					printf("short\nLength must ");
					printf("between 8 to 12\n\n");
					return 0;
				}
			}
			else {
				printf("\nPassword Mismatch\n\n");
				return 0;
			}
		}
		else {
			printf("\nPlease Enter"
				" Valid E-Mail\n\n");
			return 0;
		}
	}
}
void account_check();
{
	for (i = 0; i < 100; i++) {
		// Check whether the email
		// and password are already
		// matched with existed account
		if (!(strcmp(temp_email, s[i].email)
			&& strcmp(temp_password1,
						s[i].password))) {
			printf("\n\nAccount Already");
			printf("Existed. Please Login !!\n\n");
			main();
			break;
		}
	}
	// if account does not already
	// existed, it creates a new
	// one with new inputs
	if (i == 100) {
		strcpy(s[j].uname, temp_name);
		s[j].age = temp_age;
		strcpy(s[j].password, temp_password1);
		strcpy(s[j].email, temp_email);
		strcpy(s[j].mobile, temp_mobile);
		j++;
		printf("\n\n\nAccount Successfully");
		printf("Created!!\n\n");
	}
}

// Function to Login the users
void login()
{
	printf("\n\nLOGIN\n\n");
	printf("\nEnter Your Email\t");
	scanf("%s", temp_email);
	printf("Enter Your Password\t");
	scanf("%s", temp_password1);
	for (i = 0; i < 100; i++) {
		// Check whether the input
		// email is already existed or not
		if (!strcmp(s[i].email, temp_email)) {
			// Check whether the password
			// is matched with the email or not
			if (!strcmp(s[i].password, temp_password1)) {
				printf("\n\nWelcome %s, ", s[i].uname);
				printf("Your are successfully ");
				printf("logged in\n\nWe Provide ");
				printf("two ways of search\n1) ");
				printf("Search By Hotels\n2) ");
				printf("Search by Food\n3) ");
				printf("Exit\n\nPlease Enter");
				printf("your choice\t");
				scanf("%d", &search_choice);

				// Getting the input whether
				// the user are going to search
				// /Order by hotels or search/
				// order by food.
				switch (search_choice) {
				case 1: {
					search_by_hotels();
					break;
				}
				case 2: {
					search_by_food();
					break;
				}
				case 3: {
					// exit(1);
					return;
				}
				default: {
					printf("Please Enter ");
					printf("the valid choice\n\n");
					break;
				}
				}
				break;
			}
			else {
				printf("\n\nInvalid Password! ");
				printf("Please Enter the ");
				printf("correct password\n\n");
				main();
				break;
			}
		}
		else {
			printf("\n\nAccount doesn't ");
			printf("exist, Please signup!!\n\n");
			main();
			break;
		}
	}
}

void Resturant::create()
{
    char a;
    int k;
    fstream obj;
    top:
    do {
        obj.open("resturant.txt",ios::in|ios::binary);
        cout<<"enter the dish key : ";
        cin>>k;
         while(obj.read((char*)&r,sizeof(r)))
            {
                if(r.key==k)
                {
                    cout<<"key is already exist"<<endl;
                    obj.close();
                goto top;
                }
            }
        obj.close();
        obj.open("resturant.txt",ios::app|ios::binary);
        r.key=k;
        cin.ignore();
        cout<<"ENTER THE DISH NAME : ";
        gets(r.dish);
        cout<<"ENTER THE DISH PRICE : ";
        cin>>r.price;
        obj.write((char*)&r,sizeof(r));
        cout<<"do you want to add an other [y/n] : ";
        cin>>a;
        obj.close();
    }
    while(a!='n');
}
void Resturant::display()
{
      int c=0;
     fstream obj;
     obj.open("resturant.txt",ios::in|ios::binary);
    cout<<"\tKey\t\tDISH NAME\t\tPRICE"<<endl;
    while(obj.read((char*)&r,sizeof(r)))
    {
            cout<<"\t"<<r.key<<"\t\t"<<r.dish<<"\t\t\t"<<r.price<<endl;
            c++;
    }
    if(c==0)
    {
        cout<<"list is empty"<<endl;
    }
    obj.close();
}
void Resturant::query()
{
     int a,c=0;
     fstream obj;
     obj.open("resturant.txt",ios::in);
    cout<<"enter the dish key : ";
    cin>>a;
    while(obj.read((char*)&r,sizeof(r)))
    {
           if(r.key==a)
           {
            cout<<"\t"<<r.key<<"\t\t"<<r.dish<<"\t\t\t"<<r.price<<endl;
            c++;
           }
    }
    if(c==0)
    {
        cout<<"not found"<<endl;
    }
    obj.close();
}
void Resturant::update()
{
     int a,p,c=0;
     fstream obj;
     obj.open("resturant.txt",ios::in|ios::out|ios::binary);
    cout<<"enter the dish key : ";
    cin>>a;
    obj.seekg(0);
    while(obj.read((char*)&r,sizeof(r)))
    {
        if(r.key==a)
        {
            cout<<"destinatio record:"<<endl;
            cout<<"\t"<<r.key<<"\t\t"<<r.dish<<"\t\t\t"<<r.price<<endl;
            p=obj.tellg()-(sizeof(r));
            obj.seekp(p);
            cout<<"enter the dish key : ";
            cin>>r.key;
            cin.ignore();
            cout<<"ENTER THE DISH NAME:";
             gets(r.dish);
            cout<<"ENTER THE DISH PRICE:";
            cin>>r.price;
            obj.write((char*)&r,sizeof(r));
            c++;
           }

        }
        if(c==0)
        {
            cout<<"not found"<<endl;
        }

    obj.close();
}
void Resturant::delet()
{
     int a,c;
     fstream obj,obj1;
     obj.open("resturant.txt",ios::in|ios::binary);
     obj1.open("temp.txt",ios::app|ios::binary);
    cout<<"enter the dish key : ";
    cin>>a;
    while(obj.read((char*)&r,sizeof(r)))
    {
        if(r.key==a)
        {
            c++;
            cout<<"\t"<<r.key<<"\t\t"<<r.dish<<"\t\t\t"<<r.price<<endl;
            cout<<"destination record is deleted"<<endl;
        }
        if(r.key!=a)
        {
            obj1.write((char*)&r,sizeof(r));
           }
    }
    obj.close();
    obj1.close();
    if(c==0)
       {
         cout<<"not found"<<endl;
       }
    remove("resturant.txt");
    rename("temp.txt","resturant.txt");
}
 void Resturant::admin()
{
char a;
    do{

            cout<<"\t\t\t\t\t\t _______________________"<<endl;
            cout<<"\t\t\t\t\t\t|                       |"<<endl;
            cout<<"\t\t\t\t\t\t|  1) ADD DISH          |"<<endl;
            cout<<"\t\t\t\t\t\t|  2) Display           |"<<endl;
            cout<<"\t\t\t\t\t\t|  3) QUERY             |"<<endl;
            cout<<"\t\t\t\t\t\t|  4) UPDATE            |"<<endl;
            cout<<"\t\t\t\t\t\t|  5) DELETE            |"<<endl;
            cout<<"\t\t\t\t\t\t|  0) EXIT TO MAIN MANU |"<<endl;
            cout<<"\t\t\t\t\t\t|                       |"<<endl;
            cout<<"\t\t\t\t\t\t|_______________________|"<<endl;
            cout<<"\t\t\t\t\t\tselect the key ";
            cin>>a;
            switch(a)
            {
            case '0':
                break;
            case '1':
                system("CLS");
               create();
                break;
            case '2':
                system("CLS");
               display();
                break;
            case '3':
                system("CLS");
               query();
                break;
            case '4':
                system("CLS");
               update();
                break;
            case '5':
                system("CLS");
             delet();
                break;
            }
    }
    while(a!='0');
}
struct {
char d[50];
float p,amount;
int qty;
}rd;
class custmer:public Resturant
{
public:
    void bill();
    void showbill();
    void dish_menu();
};
void custmer::bill()
{
     int a,c=0;
     char ch;
     float total=0;
    fstream obj,obj1;
    dish_menu();
    obj1.open("bill.txt",ios::out|ios::binary);
     do{
    obj.open("resturant.txt",ios::in|ios::binary);
    cout<<"enter the dish key : ";
    cin>>a;
    while(obj.read((char*)&r,sizeof(r)))
    {
           if(r.key==a)
           {
            c++;
            cout<<"enter the quantity : ";
            cin>>rd.qty;
            rd.amount=rd.qty*r.price;
            cout<<"\t"<<r.dish<<"\t\t"<<r.price<<"*"<<rd.qty<<"\t\t"<<rd.amount<<endl;
            strcpy(rd.d,r.dish);
            rd.p=r.price;
            obj1.write((char*)&rd,sizeof(rd));
            total=total+rd.amount;
           }
        }
        if(c==0)
     {
        cout<<"not found"<<endl;
     }

    cout<<"do you want to order more [y/n] : ";
    cin>>ch;
    obj.close();
     }
     while(ch!='n');
    obj1.close();
    cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"|||||||||||||||||||||||||||||||||||||||||||||||| BILL  |||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
     cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    showbill();
    cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"|||\t\t\t\t\t\t\t   TOTAL = "<<total<<"\t\t\t\t\t   |||"<<endl;
    cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
}
 void custmer::showbill(){
    fstream obj;
    obj.open("bill.txt",ios::in|ios::binary);
    cout<<"\tDISH NAME\t\tPRICE\t\tQTY\t\tAMOUNT"<<endl;
    while(obj.read((char*)&rd,sizeof(rd)))
    {

            cout<<"\t"<<rd.d<<"\t\t\t"<<rd.p<<"\t\t"<<rd.qty<<"\t\t"<<rd.amount<<endl;


    }
    obj.close();
 }
 void custmer::dish_menu()
 {
      fstream obj;
     obj.open("resturant.txt",ios::in|ios::binary);
    while(obj.read((char*)&r,sizeof(r)))
    {


            cout<<"\t\t"<<r.key<<") "<<r.dish<<"-------RS  "<<r.price<<endl;
    }
    obj.close();
 }
int main()
{
    printf(""
			"\n\nWelcome to Food ");
		printf("Ordering System\n\n1)SIGNUP\n");
		printf("2)LOGIN\n3)EXIT\n\n");
		printf("Enter your choice\t");
		scanf("%d", &choice);
		switch (choice) {
		case 1: {
			signup();
			break;
		}
		case 2: {
			login();
			break;
		}
		case 3: {
			// exit(1);
			return 0;
		}
		default: {
			printf("\nPlease Enter the ");
			printf("valid choice\n");
			break;
		}
		}
	}
}

    // char a;
    // custmer obj;
    // do
    // {
    //     cout<<"\t\t\t\t\t\t __________________"<<endl;
    //     cout<<"\t\t\t\t\t\t|                  |"<<endl;
    //     cout<<"\t\t\t\t\t\t|    1)Admin       |"<<endl;
    //     cout<<"\t\t\t\t\t\t|    2)custmer     |"<<endl;
    //     cout<<"\t\t\t\t\t\t|    0)Exit        |"<<endl;
    //     cout<<"\t\t\t\t\t\t|                  |"<<endl;
    //     cout<<"\t\t\t\t\t\t|__________________|"<<endl;
    //     cout<<"\t\t\t\t\t\tselect the menu ";
    //     cin>>a;
    //     switch(a)
    //     {
    //     case '0':
    //         break;
    //     case '1':
    //          system("CLS");
    //         obj.admin();
    //         break;
    //     case '2':
    //          system("CLS");
    //         obj.bill();
    //         break;
    //     }
    // }
    // while(a!='0');

}