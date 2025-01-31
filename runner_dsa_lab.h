// runer code for linklist
#ifndef RUN_P
#define RUN_P
#include "class_event_dsa_lab.h"
class runnner_list
{
public:
    EventManagementSystem ems;
    int choice;
    int id;
    string name, dt, loc;

public:
    runnner_list() {}
    void runlist()
    {

  
    do {
        cout << "\n==================== Event Management Menu ====================\n"
             << "1. Add Event\n"
             << "2. Delete Event\n"
             << "3. Display Events (Forward)\n"
             << "4. Display Events (Reverse)\n"
             << "5. Add Attendee to Event\n"
             << "6. Display Attendees of an Event\n"
             << "7. update the event\n"
             << "8. Delete the attendee\n"
             << "9. Exit\n"
             << "==============================================================\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout<<"Please Enter the ID"<<endl;
            cin>>id;
            cout<<"Please Enter the Name"<<endl;
                        cin>>name;
            cout<<"Please Enter the DateTime (YYYY-MM-DD HH:MM)"<<endl;
                        cin>>dt;

            cout<<"Please Enter the location"<<endl;   
			            cin>>loc;
        
            ems.addEvent(id, name, dt, loc);
            break;
        }
        case 2: {
            int id;
            cout << "Enter Event ID to delete: ";
            cin >> id;
            ems.deleteEvent(id);
            break;
        }
        case 3:
            ems.displayEvents();
            break;
        case 4:
            ems.displayEvents(true);
            break;
        case 5: {
            int eventID, attendeeID;
            string name, email;
            cout << "Enter Event ID, Attendee ID, Name, Email: ";
            cin >> eventID >> attendeeID >> ws;
            getline(cin, name);
            cin >> email;
            ems.addAttendee(eventID, attendeeID, name, email);
            break;
        }
        case 6: {
            int id;
            cout << "Enter Event ID to display attendees: ";
            cin >> id;
            ems.displayAttendees(id);
            break;
        }
        case 7:
        	cout<<"Please Enter the ID"<<endl;
            cin>>id;
            cout<<"Please Enter the new Name"<<endl;
                        cin>>name;
            cout<<"Please Enter the DateTime (YYYY-MM-DD HH:MM)"<<endl;
                        cin>>dt;

            cout<<"Please Enter the location"<<endl;   
			            cin>>loc;
        
        	ems.update_event(id,name,dt,loc);
            break;
        case 8:
        	int a;
        	cout<<"Enter the attendee or event id"<<endl;
        	cin>>a;
        	ems.delete_attendee(a,a);
        	break;
        case 9:
        	if(choice!=0)
        	processingAnimation("Exiting Program");
            cout << "\n[!] Goodbye!\n";
            break;
        default:
            cout << "\n[!] Invalid choice. Try again.\n";
        }
    } while (true);

}
};
#endif
