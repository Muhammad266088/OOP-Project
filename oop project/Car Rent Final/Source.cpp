#include <iostream>
#include <string>
#include<fstream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class Cars {
    friend class person;
public:

    string brand[100] = { "Hyundai","BMW","Mercedes","Audi","Suzuki","Shnajan","Honda","Toyota","Ford" };

    string model[100] = { "Sonata","5 series","C class","A7","Alto","Alsvin","Civic","Grande","Victoria" };

    string color[100] = { "Red","black","yellow","Blue","Red","Brown","Silver","Black","grey" };

    string maxs_peed[100] = { "100 Km/h ","150 Km/h","150 Km/h","170 Km/h","130 Km/h","140 Km/h","130 Km/h","120 Km/h","150 Km/h" };

    int price[100] = { 200,900,950,800,100,180,400,350,600 };

    int date[100] = { 2010,2012,2013,2017,2018,2005,2008,2010,2014 };

    string parking[100] = { "A1","B9","H16","C2","D10","F12","A6","A12","E99","K2" };

};

class person {
public:
    string Name[10];
    string Natio_ID[10];
    int payment_acc[10];
};

int Carscount = 9;
Cars car;
person personobj;


void Minu()
{


    int num = 1;
    for (int i = 0; i < 9; ++i)
    {
        cout << "\t\t\t";
        cout << "Enter " << num << "\t- To Select  " << car.brand[i] << endl;
        num++;
    }

}
string pass = "";

void Details(int theChoice)
{
    system("CLS");
    cout << "\n\n\n\t\t\t-----------------------------\n";
    cout << "\t\t\tYou Have Selected - " << car.brand[theChoice - 1] << endl;
    cout << "\t\t\t-----------------------------\n\n\n";
    cout << "\t\t\tModel : " << car.model[theChoice - 1] << endl;
    cout << "\t\t\tColor : " << car.color[theChoice - 1] << endl;
    cout << "\t\t\tMaximum Speed : " << car.maxs_peed[theChoice - 1] << endl;
    cout << "\t\t\tPrice : " << car.price[theChoice - 1] << "K" << endl;


}
//check lessee credit

void check(int j)
{
    if (personobj.payment_acc[j] >= car.price[j]) {
        cout << "\n\n\n\t\t\tProcess has been done successfully!! " << endl;
        cout << "\n\n\n\t\t\tThe car has been rented for:  " << personobj.payment_acc[j] / car.price[j] <<"  Days"<< endl;
        cout << "\n\n\n\t\t\t Your car is in " << car.parking[j] << endl;
        ofstream UserFile("UserData.txt");
        string fname = personobj.Name[j];
        string fid = personobj.Natio_ID[j];
        int fpay = personobj.payment_acc[j];
        
        UserFile << fname<<endl;
        UserFile << fid<<endl;
        UserFile << fpay<<endl;
        UserFile.close();
        car.brand[j] = "Sorry this car has already been rented!";

    }


    else {
        cout << "\n\n\n\t\t\tNot Available " << endl;
    }
}

void user_input(int theChoice)
{
    system("CLS");
    int j = theChoice - 1;
    cout << "\t\t\t----------------------------------------\n";
    cout << "\t\t\tPlease Provide Your Personal Details  : \n";
    cout << "\t\t\t----------------------------------------\n\n";
    cout << "\n\tNOTE: PROVIDE FIRST NAME ONLY, DONOT ENTER SPACE WHILE PROVIDING NAME,\n\tPAYMENT WON'T PROCEED IF THE GIVEN AMOUNT IS LESS THEN THE RATE OF CAR\n\n\n\n";
    cout << "\t\t\tEnter Your Name : ";
    cin >> personobj.Name[j];
    cout << "\t\t\tEnter Your National ID : ";
    cin >> personobj.Natio_ID[j];
    cout << "\t\t\tPayment Amount: ";
    cin >> personobj.payment_acc[j];


    check(j);
}
void Admin() {
    bool cond;
    while (cond = true) {
        string adchoice;
        cout << "\n\n\t\t What do you want to do , ADMIN?:   \n\n\n\t\t\t\ ";
        cout << "----------------------------------------------\n";
        cout << "\n\n\t\t1.remove car\n\n\t\t";
        cout << "\n\n\t\t2.add car\n\n\t\t";
        cout << "\n\n\t\t3.change price\n\n\t\t";
        cout << "\n\n\t\t4.Exit\n\n\t\t";
        cout << "\t----------------------------------------------\n";
        cin >> adchoice;

        if (adchoice == "1") {
            int removech;
            Minu();
            cout << "\n\n\n\t\t\t What car do you want to remove?:  \n\n\n\t\t\t";
            cin >> removech;

            for (int k = 0; k < Carscount; k++) {
                string confirm;
                cout << "\n\n\t\tyour sure you want to remove\t\t" << car.brand[removech - 1] << car.model[removech - 1] << "\n\nfrom the list\t\t\n\n";
                cout << "\n\n\t\t yes / no \t\t\n\n";
                cin >> confirm;
                if (confirm == "yes") {
                    car.model[removech - 1] = "NULL";
                    car.brand[removech - 1] = "NULL";
                    car.maxs_peed[removech - 1] = "NULL";
                    car.color[removech - 1] = "NULL";
                    car.parking[removech - 1] = "NULL";
                    car.price[removech - 1] = 0;
                    Carscount -= 1;
                    cout << "\n\n\t\t The car has been removed successfully\n\n\t\t";
                    break;
                }
                else {
                    break;
                }

            }
        }
        else if (adchoice == "2")

        {
            system("CLS");
            string ncar;
            string nmodel;
            string ncolor;
            string nspeed;
            string nparking;
            int nprice, ndate;
            cout << "\t\t\n\n Enter the brand of the car: \n\n\t\t";
            cin >> ncar;
            cout << "\t\t\n\n Enter the model of the car: \n\n\t\t";
            cin >> nmodel;
            cout << "\t\t\n\n Enter the color of the car: \n\n\t\t";
            cin >> ncolor;
            cout << "\t\t\n\n Enter the max speed of the car: \n\n\t\t";
            cin >> nspeed;
            cout << "\t\t\n\n Enter the price of the car: \n\n\t\t";
            cin >> nprice;
            cout << "\t\t\n\n Enter the Year of the car : \n\n\t\t";
            cin >> ndate;
            cout << "\t\t\n\n Enter the parking of the car:  \n\n\t\t";
            cin >> nparking;
            car.brand[Carscount + 1] = ncar;
            car.model[Carscount + 1] = nmodel;
            car.maxs_peed[Carscount + 1] = nspeed;
            car.color[Carscount + 1] = ncolor;
            car.price[Carscount + 1] = nprice;
            car.date[Carscount + 1] = ndate;
            car.parking[Carscount + 1] = nparking;
            cout << "\t\t\t The car is added successfully \t\t\t";


        }
        else if (adchoice == "3") {
            system("cls");
            int pchange;
            Minu();
            cout << "\t\t\t what car do you want to change price of \t\t\t";
            cin >> pchange;
            int nchhprice;
            cout << "\t\t\t Enter the new price \t\t\t";
            cin >> nchhprice;
            car.price[pchange - 1] = nchhprice;
            cout << "\t\t\t The price has been changed successfully \t\t\t";
            continue;
        }
        else if (adchoice == "4") {
            cond = false;
                
        }
        

        break;
    }

}

int main()
{

    int login();
    login();

    string decide = "yes";
    cout << "\t\t\t----------------------------------------------\n";
    cout << "\t\t\t\tSELF CAR RENTAL SYSTEM \n";
    cout << "\t\t\tWelcome to Our Company ,Choose from the menu : " << endl;
    cout << "\t\t\t----------------------------------------------\n";
    while (decide != "exit")
    {
        if (pass == "user") {
            Minu();
            cout << "\n\n\n\t\t\tYour Choice: ";
            int theChoice;
            cin >> theChoice;
            Details(theChoice);
            cout << "\n\n\n\t\t\tAre You Sure, you want to rent this Car? (yes /no /exit ) : ";
            cin >> decide;
            if (decide == "yes") {
                user_input(theChoice);
                cout << "\n\n\t\t\tDo you want to continue ?(yes/no) ";
                cin >> decide;
                if (decide == "no") break;
                system("CLS");
            }

            else {
                if (decide == "no")
                {
                    system("CLS");
                    continue;
                }
                else if (decide == "exit")
                {
                    system("CLS");
                    cout << "\n\n\n\t\t\t Developed By MUHAMMAD ARSHAD";

                    break;
                }

            }
        }
        else if (pass == "admin") {
            system("cls");
            Admin();
            system("CLS");
            login();
            

        }
        else {
            continue;
        }
    }


    system("pause");
    return 0;
}
//cpo

int login() {
    string type;

    char ch;
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t  Self Car Rental System Login";
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t\n         Eter who you are admin/user: ";
    cin >> pass;
    ch = _getch();
    while (ch != 13) {
        pass.push_back(ch);
        ch = _getch();
    }

    if (pass == "admin") {
        cout << "\n\n\n\n\t\t\t\t\t  Welcome To your System ADMIN ;) \n\n";

    }





    else if (pass == "user") {
        cout << "\n\n\n\n\t\t\t\t\t  Welcome To your System ;) \n\n";
        system("PAUSE");
        system("CLS");

    }
    else {
        cout << "\n\n\n\n\t\t\t\t\tAccess denied...Please Try Again!!\n";
        system("PAUSE");
        system("CLS");
        login();
    }
    return 0;

}