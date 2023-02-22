#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;
//............................................PROTOTYPES......................................//

void maze();
void role();
void admin();
void admin_menu();
void admin_feature();
void header();
void footer();

//-------Admins Function-------//
void addflight();
void viewflight();
void planes();
void addpilot();
void viewpilot();
void ticket_price();
void view_passenger();
void add_passenger();
void remove_flight();
void remove_pilot();
void remove_passenger();
void update_flight();
void update_pilot();
void update_passenger();
void passenger_feature();
void passenger_opt();
//----Admins functions----//

//----Passengers functions---//
void check_balance();
void deletebalance();
void updatebalance();
void checkFlight();
// void buyTicket();
void seeTicketprice();
//----Passengers functions---//

void presskey();
void signup();
void signin();
int validateInput(string); // general function to validate any input!
void login_option();
//.............................................PROTOTYPES................................................//

//.........GLOBAL VARIABLES......................//
string choice; //..used to ask choices..//
// string choice1; //.....passenger
// string choice2; //..inner passenger
const int size = 50000;
int flightCount = 10;
int pilotcount = 5;
int passengercount = 8;
int userCount = 0;
int balance_count = 1;
string adminName = "ahmar";
string adminPassword = "123";
string p_Name = "ahmar";
string p_password = "123";
//.........GLOBAL VARIABLES......................//

//..............GLOBAL ARRAYS.............................//
string flight[size] = {"pia", "emirates", "airworld", "qantas", "airindia", "shaheenair", "serenee", "lufthansa", "saudiair", "arabair"};
int price[size] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
string pilot[size] = {"James", "Harry", "Alex", "Robert", "Henry"};
string passenger[size] = {"Mickel", "Trump", "Putin", "Jimmy", "Roy", "Williamson", "Watson", "Mark"};
string balance[size] = {"50"};
string user[size];     //.....username for a new users
string password[size]; //.......password for new users
//.....................GLOBAL ARRAYS......................//

main()
{
    while (choice != "3") // Press 3 for exit
    {
        system("cls");
        maze();
        presskey();
        system("cls");
        role();

        cout << "Enter your choice:";
        cin >> choice;
        while (choice == "1") //......admin choice
        {
            system("cls");
            admin();
            admin_menu();
            while (choice != "0")
            {
                system("cls");
                admin_feature();
                cout << "Enter the choice :"; //..choice section for admin
                cin >> choice;
                if (choice == "1")
                {
                    system("cls"); //....add flight
                    addflight();
                }
                else if (choice == "2")
                {
                    system("cls"); //...view flight
                    viewflight();
                }
                else if (choice == "3")
                {
                    system("cls"); //.....remove flight
                    viewflight();
                    remove_flight();
                    system("cls");
                    viewflight();
                }
                else if (choice == "4")
                {
                    system("cls"); //.....update flight
                    viewflight();
                    update_flight();
                    system("cls");
                    viewflight();
                }
                else if (choice == "5")
                {
                    system("cls");
                    addpilot();
                }
                else if (choice == "6")
                {
                    system("cls");
                    viewpilot();
                }
                else if (choice == "7")
                {
                    system("cls");
                    viewpilot();
                    remove_pilot();
                    system("cls");
                    viewpilot();
                }
                else if (choice == "8")
                {
                    system("cls");
                    viewpilot();
                    update_pilot();
                    system("cls");
                    viewpilot();
                }
                else if (choice == "9")
                {
                    system("cls");
                    add_passenger();
                    system("cls");
                    view_passenger();
                }
                else if (choice == "10")
                {
                    system("cls");
                    view_passenger();
                }
                else if (choice == "11")
                {
                    system("cls");
                    view_passenger();
                    remove_passenger();
                    system("cls");
                    view_passenger();
                }
                else if (choice == "12")
                {
                    system("cls");
                    view_passenger();
                    update_passenger();
                    system("cls");
                    view_passenger();
                }
                else if (choice == "13")
                {
                    system("cls");
                    ticket_price();
                }
            }
        }
        while (choice == "2") // choice section for passenger
        {
            while (choice != "0")
            {
                system("cls");
                login_option();
                cout << "Enter your choice :";
                cin >> choice;
                if (choice == "1")
                {
                    signup();
                }
                else if (choice == "2")
                {

                    signin();
                    system("cls");
                    while (choice != "0")
                    {
                        passenger_feature();
                        cout << "Enter choice :";
                        cin >> choice;
                        if (choice == "1")
                        {
                            system("cls");
                            check_balance();
                            presskey();
                            system("cls");
                        }
                        else if (choice == "2")
                        {
                            system("cls");
                            deletebalance();
                            presskey();
                            system("cls");
                            check_balance();
                        }
                        else if (choice == "3")
                        {
                            system("cls");
                            updatebalance();
                            presskey();
                            system("cls");
                            check_balance();
                        }
                        else if (choice == "4")
                        {
                            system("cls");
                            checkFlight();
                            presskey();
                            system("cls");
                        }
                        else if (choice == "5")
                        {
                            cout << "Coming soon!";
                        }
                        else if (choice == "6")
                        {
                            cout << "coming soon !";
                        }
                        else if (choice == "7")
                        {
                            cout << "Coming soon!";
                        }
                        else if (choice == "8")
                        {
                            system("cls");
                            seeTicketprice();
                            presskey();
                            system("cls");
                        }
                    }
                }
            }
        }
    }
}

void maze()
{
    cout << '\t' << "***********************************************************************************************************" << endl;
    cout << '\t' << "**************************                                                                                *" << endl;
    cout << '\t' << "****************                                                                                          *" << endl;
    cout << '\t' << "************                                 WELCOME                                                      *" << endl;
    cout << '\t' << "*******                                                                                                   *" << endl;
    cout << '\t' << "*                                              TO                                                         *" << endl;
    cout << '\t' << "*                                                                                                         *" << endl;
    cout << '\t' << "*                                         FLY EMIRATES                                                    *" << endl;
    cout << '\t' << "*                                                                                                   *******" << endl;
    cout << '\t' << "*                                           AIRLINES                                           ************" << endl;
    cout << '\t' << "*                                                                                      ********************" << endl;
    cout << '\t' << "*                                                                             *****************************" << endl;
    cout << '\t' << "***********************************************************************************************************" << endl;
}
void role()
{
    cout << '\t' << "***********************************************************************************************************" << endl;
    cout << '\t' << "**************************                                                                                *" << endl;
    cout << '\t' << "****************                        Enter your choice                                                 *" << endl;
    cout << '\t' << "************                                 1-Admin                                                      *" << endl;
    cout << '\t' << "*******                                      2-Customer                                                   *" << endl;
    cout << '\t' << "*                                            3-Exit                                                       *" << endl;
    cout << '\t' << "*                                                                                                         *" << endl;
    cout << '\t' << "*                                                                                                         *" << endl;
    cout << '\t' << "*                                                                                              ************" << endl;
    cout << '\t' << "*                                                                                      ********************" << endl;
    cout << '\t' << "*                                                                              ****************************" << endl;
    cout << '\t' << "***********************************************************************************************************" << endl;
}

void admin()
{
    cout << '\t' << "***********************************************************************************************************" << endl;
    cout << '\t' << "**************************                                                                                *" << endl;
    cout << '\t' << "****************                        Admin(menu)                                                       *" << endl;
    cout << '\t' << "************                                                                                              *" << endl;
    cout << '\t' << "*******                                                                                                   *" << endl;
    cout << '\t' << "*                                       1-Enter your username:____________                                *" << endl;
    cout << '\t' << "*                                       2-Enter your password:____________                                *" << endl;
    cout << '\t' << "*                                                                                                         *" << endl;
    cout << '\t' << "*                                                                                              ************" << endl;
    cout << '\t' << "*                                                                                      ********************" << endl;
    cout << '\t' << "*                                                                              ****************************" << endl;
    cout << '\t' << "***********************************************************************************************************" << endl;
}

void login_option()
{
    cout << '\t' << "***********************************************************************************************************" << endl;
    cout << '\t' << "**************************                                                                                *" << endl;
    cout << '\t' << "****************                        Login Option                                                      *" << endl;
    cout << '\t' << "************                                                                                              *" << endl;
    cout << '\t' << "*******                                                                                                   *" << endl;
    cout << '\t' << "*                                       1- Sign up                                                        *" << endl;
    cout << '\t' << "*                                       2- Sign in                                                        *" << endl;
    cout << '\t' << "*                                       0- exit                                                           *" << endl;
    cout << '\t' << "*                                                                                              ************" << endl;
    cout << '\t' << "*                                                                                      ********************" << endl;
    cout << '\t' << "*                                                                              ****************************" << endl;
    cout << '\t' << "***********************************************************************************************************" << endl;
}

void passenger_opt()
{
    cout << '\t' << "***********************************************************************************************************" << endl;
    cout << '\t' << "**************************                                                                                *" << endl;
    cout << '\t' << "****************                        Passenger(menu)                                                   *" << endl;
    cout << '\t' << "************                                                                                              *" << endl;
    cout << '\t' << "*******                                                                                                   *" << endl;
    cout << '\t' << "*                                       1-Enter your username:____________                                *" << endl;
    cout << '\t' << "*                                       2-Enter your password:____________                                *" << endl;
    cout << '\t' << "*                                                                                                         *" << endl;
    cout << '\t' << "*                                                                                              ************" << endl;
    cout << '\t' << "*                                                                                      ********************" << endl;
    cout << '\t' << "*                                                                              ****************************" << endl;
    cout << '\t' << "***********************************************************************************************************" << endl;
}
void signin()
{
    bool flag = false;
    string username, pass;
    cout << "Enter your username :";
    cin >> username;
    cout << "Enter your password :";
    cin >> pass;
    for (int idx = 0; idx < userCount; idx++)
    {
        if (username == user[idx] && pass == password[idx])
        {
            flag = true;
            break;
        }
    }
    if (flag == true)
    {
        cout << "Successfully Signin !";
        presskey();
    }
    else
    {
        cout << "Invalid Credentials" << endl;
        presskey();
        system("cls");
        signin();
    }
}

void signup() // function for sign up!
{
    string name;
    string code;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter password: ";
    cin >> code;

    user[userCount] = name;
    password[userCount] = code;

    userCount++;
    cout << "Successfully Signup !";
    presskey();
}

void admin_menu()
{
    string username, password;
    cout << "Enter your username:";
    cin >> username;
    cout << "Enter your password:";
    cin >> password;
    if (username == adminName && password == adminPassword)
    {
    }
    else
    {
        cout << " Invalid Credentials" << endl;
        presskey();
        system("cls");
        admin();
        admin_menu();
    }
}

void admin_feature()
{
    cout << '\t' << "***********************************************************************************************************" << endl;
    cout << '\t' << "*                            1- Add Flight                                                                *" << endl;
    cout << '\t' << "*                            2- View Flight                                                               *" << endl;
    cout << '\t' << "*                            3- Remove Flight                                                             *" << endl;
    cout << '\t' << "*                            4- Update Flight                                                             *" << endl;
    cout << '\t' << "*                            5- Add Pilot                                                                 *" << endl;
    cout << '\t' << "*                            6- View Pilot                                                                *" << endl;
    cout << '\t' << "*                            7- Remove Pilot                                                              *" << endl;
    cout << '\t' << "*                            8- Update pilot                                                              *" << endl;
    cout << '\t' << "*                            9- Add Passenger                                                             *" << endl;
    cout << '\t' << "*                           10- View Passenger                                                            *" << endl;
    cout << '\t' << "*                           11- Remove passenger                                                          *" << endl;
    cout << '\t' << "*                           12- Update Passenger                                                          *" << endl;
    cout << '\t' << "*                           13- View Ticket Price                                                         *" << endl;
    cout << '\t' << "*                            0- Logout                                                                    *" << endl;
    cout << '\t' << "***********************************************************************************************************" << endl;
}

void passenger_feature()
{
    cout << '\t' << "****************************************************************************************************" << endl;
    cout << '\t' << "*                            1- Check balance                                                      *" << endl;
    cout << '\t' << "*                            2- Delete balance                                                     *" << endl;
    cout << '\t' << "*                            3- Update balance                                                     *" << endl;
    cout << '\t' << "*                            4- Check flight                                                       *" << endl;
    cout << '\t' << "*                            5- Buy ticket                                                         *" << endl;
    cout << '\t' << "*                            6- See arrival times of flight                                        *" << endl;
    cout << '\t' << "*                            7- See departure time of flight                                       *" << endl;
    cout << '\t' << "*                            8- See the ticket price                                               *" << endl;
    cout << '\t' << "*                            0- Logout                                                             *" << endl;
    cout << '\t' << "****************************************************************************************************" << endl;
    presskey();
}

void header()
{
    cout << '\t' << "***********************************************************************************************************" << endl;
    cout << '\t' << "**************************                                                                                 " << endl;
    cout << '\t' << "****************                                                                                           " << endl;
    cout << '\t' << "************                                                                                               " << endl;
    cout << '\t' << "*******                                                                                                    " << endl;
}

void footer()
{
    cout << '\t' << "                                                                                                          " << endl;
    cout << '\t' << "                                                                                                          " << endl;
    cout << '\t' << "                                                                                                    ******" << endl;
    cout << '\t' << "                                                                                               ***********" << endl;
    cout << '\t' << "                                                                                          ****************" << endl;
    cout << '\t' << "                                                                              ****************************" << endl;
    cout << '\t' << "**********************************************************************************************************" << endl;
}

//..........Admins Function...........//
void planes()
{
    for (int idx = 0; idx <= 10; idx++)
    {
        cout << '\t' << '\t' << flight[idx] << '\t' << '\t' << price[idx] << endl;
    }
}

void presskey() // function for a short break ........
{
    cout << "Press any key to continue....";
    getch();
}

int validateInput(string anyName)                    //......This Function is basically the holds the validation of input data.
{                                                    //.......It concept of Ascii to check the validation if the input of any int password is
    int result = 0;                                  //....... string than it compares it with the ASCII code of numbers from 0 to 9.
    bool flag = false;                               //.......It takes the length of the string "anyNAme" and check it .
                                                     //.......For.example if the length of "anyName" is 3 than loop will run 3 times and checks for every
                                                     // single of string and compare it with ASCII of 0 and 1 . If it's true it would be invert and flag turns true
    for (int i = 0; i < anyName.length(); i++)       //....Initially the result is zero but when flag will not true than in else part suppose we have
    {                                                //...3 number "123". ascii of them are 49,50,51 . In start result = 0 but when it
        if (!(anyName[i] >= 48 && anyName[i] <= 57)) //...compare ascii of 1 -->49 -->49-48=1--> 1+0=1 now result = 1 than it will multiple
        {                                            //.... with 10 now result is 10 and continue for furthur, atlast the result is returned.
            flag = true;
        }
    }

    if (anyName.length() > 9)
    {
        flag = true;
    }

    if (flag)
    {
        result = -1;
    }
    else
    {
        for (int i = 0; i < anyName.length(); i++)
        {
            result = result * 10;
            result = result + (anyName[i] - 48);
        }
    }
    return result;
}

void addflight() // function for the adding a new flight....
{
    string input;
    int num;
    cout << "Enter number of planes you want to add:";
    cin >> input;
    num = validateInput(input);
    int idx = 0;
    if (num != -1)
    {
        while (idx < num)
        {
            string priceInput;
            string flightName;
            cout << "Enter new flight name:";
            cin >> flightName;
            cout << "Enter rate of new flight:";
            cin >> priceInput;
            if (validateInput(priceInput) != -1)
            {
                flight[idx + 10] = flightName;
                price[idx + 10] = validateInput(priceInput);
                flightCount++;
                idx++;
            }
            else
            {
                cout << "Invalid Input";
            }
        }

        header();
        for (int idx = 0; idx < num + 10; idx++)
        {
            cout << '\t' << "*" << '\t' << '\t' << flight[idx] << '\t' << '\t' << price[idx] << endl;
        }
        footer();
        presskey();
    }
    else
    {
        cout << "Invalid Input" << endl;
        presskey();
    }
}

void viewflight() // function for view the flights
{
    header();
    for (int idx = 0; idx < flightCount; idx++)
    {
        cout << "\t\t\t" << idx + 1 << '\t' << flight[idx] << endl;
    }
    footer();
    presskey();
}

void addpilot() // function used to add pilot
{
    string input;
    int num;
    cout << "Enter number of pilots you want enter:";
    cin >> input;
    num = validateInput(input);
    int idx = 0;
    if (num != -1)
    {
        while (idx < num)
        {
            string newpilot;
            cout << "Enter the name of new pilot :";
            cin >> newpilot;
            if (validateInput(newpilot) != 1)
            {
                pilot[idx + 5] = newpilot;
                pilotcount++;
                idx++;
            }
            else
            {
                cout << "Invalid Input !";
            }
        }
        header();

        for (int idx = 0; idx < num + 5; idx++)
        {
            cout << '\t' << "*" << pilot[idx] << endl;
        }
        footer();
        presskey();
    }
    else
    {
        cout << "Invalid Input !" << endl;
        presskey();
    }
}

void viewpilot() // function used to view pilot
{
    header();
    for (int idx = 0; idx < pilotcount; idx++)
    {
        cout << "\t\t\t" << idx << " " << pilot[idx] << endl;
    }
    footer();
    presskey();
}

void ticket_price() // function used to view ticket price
{
    header();
    for (int idx = 0; idx < flightCount; idx++)
    {
        cout << '\t' << "*" << '\t' << price[idx] << "$"
             << " "
             << "="
             << " " << flight[idx] << endl;
    }
    footer();
    presskey();
}

void view_passenger() // function used to view all passengers
{
    header();
    for (int idx = 0; idx < passengercount; idx++)
    {
        cout << "\t\t" << idx << "-" << passenger[idx] << endl;
    }
    footer();
    presskey();
}

void add_passenger() // function used to add passengers
{
    string input;
    int num;
    cout << "Enter number of passenger you want to add:";
    cin >> input;
    num = validateInput(input);
    int idx = 0;
    if (num != -1)
    {
        while (idx < num)
        {
            string newpassenger;
            cout << "Enter the name of Passenger :";
            cin >> newpassenger;
            if (validateInput(newpassenger) != 1)
            {
                passenger[idx + 8] = newpassenger;
                passengercount++;
                idx++;
            }
            else
            {
                cout << "Invalid Input !";
            }
        }
        header();
        for (int idx = 0; idx < num + 8; idx++)
        {
            cout << '\t' << "*"
                 << "\t\t" << passenger[idx] << endl;
        }
        footer();
        presskey();
    }
    else
    {
        cout << "Invalid Input !" << endl;
        presskey();
    }
}

void remove_flight() //....Function used to delete flight and check with the validateInput Function as explanied above...
{
    int delflight;
    string removeflight;
    cout << "Enter name of flight to remove :";
    cin >> removeflight;
    int idx = -1;
    if (delflight != -1)
    {
        for (int i = 0; i < flightCount; i++)
        {
            if (flight[i] == removeflight)
            {
                idx = i;
            }
        }
        if (idx != -1)
        {
            for (int i = idx; i < flightCount; i++)
            {
                flight[i] = flight[i + 1];
            }
            flightCount--;
        }
        else
        {
            cout << "Invalid Input !" << endl;
            getch();
        }
    }
    else
    {
        cout << "Invalid Input !";
    }
}

void remove_pilot() //....Function used to delete pilots...//
{
    int delpilot;
    string removepilot;
    cout << "Enter the name of pilot to remove:";
    cin >> removepilot;
    int idx = -1;
    if (delpilot != -1)
    {
        for (int i = 0; i < pilotcount; i++)
        {
            if (pilot[i] == removepilot)
            {
                idx = i;
            }
        }
        if (idx != -1)
        {
            for (int i = idx; i < pilotcount; i++)
            {
                pilot[i] = pilot[i + 1];
            }
            pilotcount--;
        }
        else
        {
            cout << "Invalid Input !" << endl;
            presskey();
        }
    }
    else
    {
        cout << "Invalid Input !";
    }
}

void remove_passenger() //...Function used remove passenger....//
{
    int delpassenger;
    string removepassenger;
    cout << "Enter the name of passenger to delete :";
    cin >> removepassenger;
    int idx = -1;
    if (delpassenger != -1)
    {
        for (int i = 0; i < passengercount; i++)
        {
            if (passenger[i] == removepassenger)
            {
                idx = i;
            }
        }
        if (idx != -1)
        {
            for (int i = idx; i < passengercount; i++)
            {
                passenger[i] = passenger[i + 1];
            }
            passengercount--;
        }
        else
        {
            cout << "Invalid Input !";
            presskey();
        }
    }
    else
    {
        cout << "Invalid Input !";
    }
}

void update_flight() //....Function used to update the flight...//
{
    string name;
    int index = -1;
    cout << "Enter the name to replace :";
    cin >> name;
    for (int idx = 0; idx < flightCount; idx++)
    {
        if (name == flight[idx])
        {
            index = idx;
        }
    }
    if (index != -1)
    {
        cout << "Enter new name :";
        cin >> name;
        flight[index] = name;
    }
    else
    {
        cout << "Flight doesn't exist !";
        getch();
    }
}

void update_pilot() //....This function update the pilot exisiting pilot with new pilot.....//
{
    string name;
    int index = -1;
    cout << "Enter the name of pilot to replace :";
    cin >> name;
    for (int idx = 0; idx < pilotcount; idx++)
    {
        if (name == pilot[idx])
        {
            index = idx;
        }
    }
    if (index != -1)
    {
        cout << "Enter the new name :";
        cin >> name;
        pilot[index] = name;
    }
    else
    {
        cout << "Pilot doesn't exist !";
        getch();
    }
}

void update_passenger() //....Function the is used to update passengers....//
{
    string name;
    int index = -1;
    cout << "Enter the name of passenger to replace :";
    cin >> name;
    for (int idx = 0; idx < passengercount; idx++)
    {
        if (name == passenger[idx])
        {
            index = idx;
        }
    }
    if (index != -1)
    {
        cout << "Enter the new name :";
        cin >> name;
        passenger[index] = name;
    }
    else
    {
        cout << "Passenger doesn't exist !";
        getch();
    }
}

//.....Functions of performed by passenger......//
void check_balance()
{

    cout << "Your current balance is :" << balance[0] << '$' << endl;
}

void deletebalance()
{
    string input;
    int del_balance;
    cout << "Enter the amount of balance you want to remove :";
    cin >> input;
    float num = stof(input);
    del_balance = validateInput(input);
    int idx = 0;
    if (del_balance != -1)
    {
        balance[0] = to_string(stof(balance[0]) - num);
    }
    else
    {
        cout << "Invalid Input !" << endl;
        presskey();
    }
    // if (del_balance != -1)
    // {
    //     for (int i = 0; i < balance_count; i++)
    //     {
    //         if (balance[i] == input)
    //         {
    //             idx = i;
    //         }
    //     }
    //     if (idx != -1)
    //     {
    //         for (int i = idx; i < balance_count; i++)
    //         {
    //             balance[i] = balance[i + 1];
    //         }
    //         balance_count--;
    //     }
    //
    // }
}

void updatebalance()
{
    string amount;
    int idx = -1;
    cout << "Enter the amount to replace :";
    cin >> amount;
    for (int i = 0; i < balance_count; i++)
    {
        if (amount == balance[i])
        {
            idx = i;
        }
    }
    if (idx != -1)
    {
        cout << "Enter new amount :";
        cin >> amount;
        balance[idx] = amount;
    }
    else
    {
        cout << "Insufficient Amount !";
        getch();
    }
}

void checkFlight()
{
    header();
    for (int idx = 0; idx < flightCount; idx++)
    {
        cout << "\t\t\t" << idx + 1 << '\t' << flight[idx] << endl;
    }
    footer();
}

void seeTicketprice()
{
    header();
    for (int idx = 0; idx < flightCount; idx++)
    {
        cout << '\t' << "*" << '\t' << "-->  "<< flight[idx] << " for " << price[idx] << "$" << endl;
    }
    footer();
}

/*void buyTicket()
{
    string input;
    int num;
 cout << "Enter your amount :";
cin >> input;
num = validateInput(input);
for(int idx =0 ; idx <  ;idx++)
{

}

}*/