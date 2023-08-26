#include "BhopalMetro.cpp"
#include<conio.h>
int main()
{
    Metro Bhopal;
    Bhopal.SetStation();

    string yourName;
    cout << "Enter Your Name :";
    cin >> yourName;
    cout << "\tHello " << yourName << " :) " << endl;
    cout << "WELCOME TO BHOPAL METRO";
    cout << endl
         << "---------------------" << endl;

    cout << endl
         << "\tLIST OF ALL BHOPAL METRO STATION" << endl;
    cout << "\t---------------------------------" << endl;

    Bhopal.showStation();

    int sourceStation;
    cout << "Enter Your Metro Station :";
    cin >> sourceStation;
    cout << endl
         << "Your Choosen Station :"
         << Bhopal.NameOfStation(sourceStation) << endl;

    int x;
    cout << endl
         << yourName
         << " What you want to do ?" << endl;
    while (1)
    {

        cout << endl
             << "\nPlease Select the appropirate Option :" << endl;
        cout << "-------------------------------------" << endl
             << endl;
        cout << "1. See Minimun Station From Your Station To Your Destination Station " << endl;
        cout << "2. See Minimum Station From Your Station To All Station " << endl;
        cout << "3. Want to know the route upto your destination :" << endl;
        cout << "4. Want To Edit your Source Station: " << endl;
        cout << "5. Exit" << endl;
        // cin.ignore();
        x=_getch();
        switch (x)
        {

        case '1':
        {
            cin.ignore();
            cout << "Enter you Destination : ";
            int destinationStation;
            cin >> destinationStation;
            cout << endl
                 << "Minimum Station Between Your station To Your Destination Station : ";
            int minStation = Bhopal.ToDestination(sourceStation, destinationStation);
            cout << minStation << endl;
            cout << "-------------------------------------------------------------" << endl;
            getch();
            break;
        }

        case '2':
        {
            cout << "Minimum Station Between Your Station to All Station : ";
            cout << endl
                 << "------------------------------------------------" << endl;
            Bhopal.ToAll(sourceStation);
            getch();
            break;
        }

        case '3':
        {
            cin.ignore();
            cout << "Enter you Destination : ";
            int destinationStation;
            cin >> destinationStation;
            Bhopal.TellMeRoute(sourceStation, destinationStation);
            break;
        }

        case '4':
        {
            int newStation;
            cout << "Enter Your New Station :";
            cin >> newStation;
            sourceStation = newStation;
            break;
        }

        case '5':
        {
            cout << "THANKYOU FOR VISIT IN BHOPAL METRO " << endl;
            cout << "-----------------------------------" << endl;
            cout << "Have a HAPPY AND SAFE JOURNEY " << endl;
            cout << "------------------------------" << endl;
            return 0;
        }

        default:
            cout << "You Choosed a Default option" << endl;
            cout << "Please Enter a correct and appropirate option" << endl;
        }
    }
    return 0;
}
