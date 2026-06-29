#include <bits/stdc++.h>
using namespace std;
class Train_details
{
private:
    int n;
    string name;
    string route;
    double fare;

public:
    Train_details(int n, string name, string route, double fare)
    {
        this->n = n;
        this->name = name;
        this->route = route;
        this->fare = fare;
    }
    Train_details()
    {
    }
    void print_details(vector<Train_details> &details)
    {
        for (auto &val : details)
        {
            cout << val.n << " "
                 << "TRAIN NAME :: " << val.name << endl
                 << "TRAIN ROUTE ::" << val.route << endl
                 << "TRAIN FARE :: " << val.fare << endl;
            cout << "-----------------------------------" << endl
                 << endl;
        }
    }
    void Ticket_collector(vector<Train_details> &details, int choice, vector<pair<string, double>> &Records, int no_tickets)
    {
        for (auto &val : details)
        {
            if (choice == val.n)
            {
                cout << "TRAIN NAME :: " << val.name << endl
                     << "FARE :: " << val.fare << endl;
                cout << "ROUTE IS " << val.route << endl
                     << "-----------------" << endl;
                cout << "YOUR TICKET FOR " << val.name << " IS CONFORMED " << endl;
                cout << endl
                     << "YOUR TOTAL FARE IS :: " << (no_tickets * val.fare) << endl;
                cout << "-----------------------" << endl;
                auto record = make_pair(val.name, no_tickets * val.fare);
                Records.push_back(record);
            }
        }
    }
};
class Ticket_Booking : public Train_details
{
private:
    vector<Train_details> details;

public:
    vector<pair<string, double>> Records;
    Ticket_Booking()
    {
        details.push_back(Train_details(1, " Vande Bharat", "Delhi to varanasi", 1800));
        details.push_back(Train_details(2, " Rajdhani Express", "Delhi to Mumbai", 2990));
        details.push_back(Train_details(3, " Shatabdi Express", "Delhi to Chandigarh", 1500));
    }
    void Display_Train_detail()
    {
        print_details(details);
    }
    void Book_train(int chose_train, int no_tickets)
    {
        Ticket_collector(details, chose_train, Records, no_tickets);
    }
    void Display_all_bookings()
    {
        for (auto &val : Records)
        {
            if (Records.empty())
            {
                cout << "::NO REOCRDS FOUND :: ";
            }
            else
            {
                cout << endl
                     << val.first << " TRAIN BOOK AT A FARE OF " << val.second << endl;
            }
        }
    }
};
int main()
{
    Ticket_Booking Book_ticket;
    int choice;

    do
    {
        cout << "\n===================================\n";
        cout << "     TICKET BOOKING SYSTEM\n";
        cout << "===================================\n";
        cout << "1. VIEW AVAILABLE TRAINS \n";
        cout << "2. BOOK TICKET\n";
        cout << "3. VIEW ALL BOOKINGS\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Book_ticket.Display_Train_detail();
            break;
        case 2:
            int chose_train, no_tickets;
            cout << endl
                 << "WHICH TRAIN TO BOOK :: ";
            cin >> chose_train;
            cout << endl
                 << "HOW MANY TICKETS YOU WANT TO BOOK :: ";
            cin >> no_tickets;
            Book_ticket.Book_train(chose_train, no_tickets);
            break;
        case 3:
            Book_ticket.Display_all_bookings();
            break;
        case 4:
            cout << "--EXITING PROGRAM--";
            break;
        default:
            cout << "\nInvalid choice! Please select between 1 and 4.\n";
        }
    } while (choice != 4);
}