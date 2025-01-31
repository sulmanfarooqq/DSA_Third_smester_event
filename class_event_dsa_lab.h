#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;

void processingAnimation(const string& message) {
    cout << "\n" << message << " Done!\n";
}
// Attendee (Circular Linked List)
struct AttendeeNode {
    int attendeeID;
    string attendeeName;
    string email;
    AttendeeNode* next;

    AttendeeNode(int id, string name, string emailAddress)
        : attendeeID(id), attendeeName(name), email(emailAddress), next(NULL) {}
};
// Event Node (Doubly Linked List)
struct EventNode {
    int eventID;
    string eventName;
    string dateTime;
    string location;
    EventNode* next;
    EventNode* prev;
    AttendeeNode* attendeeHead;

    EventNode(int id, string name, string dt, string loc)
        : eventID(id), eventName(name), dateTime(dt), location(loc), next(NULL), prev(NULL), attendeeHead(NULL) {}
};

// Class to manage events and attendees
class EventManagementSystem {
private:
    EventNode* head;
    EventNode* tail;

public:
    EventManagementSystem() : head(NULL), tail(NULL) {}

    // Add Event in sorted order by date and time
    void addEvent(int id, string name, string dt, string loc) {
        processingAnimation("Adding Event");
        EventNode* newEvent = new EventNode(id, name, dt, loc);
        if (!head) { // If list is empty
            head = tail = newEvent;
        } else {
            EventNode* temp = head;
            while (temp && temp->dateTime < dt) { //finds an event that's later than the new event
                temp = temp->next;
            }
            if (!temp) { // Insert at the end //If the new event is the latest if th event is later than all 
                tail->next = newEvent;
                newEvent->prev = tail;
                tail = newEvent;
            } else if (temp == head) { // Insert at the start at the start when date is too short 
                newEvent->next = head;
                head->prev = newEvent;
                head = newEvent;
            } else { // Insert in between at the center of a list 
                newEvent->next = temp;
                newEvent->prev = temp->prev;
                temp->prev->next = newEvent;
                temp->prev = newEvent;
            }
        }
        cout << "\n[+] Event added successfully.\n";
    }
    void update_event(int id, string name, string dt, string loc) {
        processingAnimation("Updating Event");
        EventNode* temp = head;
        while (temp && temp->eventID != id) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "\n[!] Event not found.\n";
            return;
        }
        temp->eventName = name;
        temp->dateTime = dt;
        temp->location = loc;
        cout << "\n[-] Event updated successfully.\n";
    }
    // Delete Event by ID
    void deleteEvent(int id) {
        processingAnimation("Deleting Event");
        EventNode* temp = head;
        while (temp && temp->eventID != id) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "\n[!] Event not found.\n";
            return;
        }
        if (temp == head) { //if the id is in the first shift the head to the next 
            head = head->next;
            if (head) head->prev = NULL;
        } else if (temp == tail) { // if the id is in the last and then sift the tail to previous 
            tail = tail->prev;
            if (tail) tail->next = NULL;
        } else {          
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev; // sift the value of previous to the next previous 
        }
        delete temp;
        cout << "\n[-] Event deleted successfully.\n";
    }

    // Display Events (Forward and Reverse)
    void displayEvents(bool reverse = false) {
        processingAnimation("Loading Event Schedule");
        if (!head) {
            cout << "\n[!] No events to display.\n";
            return;
        }
        cout << "\n================= Event Schedule =================\n";
        if (reverse) { // display the data that is entered first
            EventNode* temp = tail;
            while (temp) {
                printEvent(temp);
                temp = temp->prev;
            }
        } else {
            EventNode* temp = head;
            while (temp) {
                printEvent(temp);
                temp = temp->next;
            }
        }
        cout << "================================================\n";
    }

    // Add Attendee to a specific event
    void addAttendee(int eventID, int attendeeID, string name, string email) {
        processingAnimation("Adding Attendee");
        EventNode* event = findEvent(eventID);
        if (!event) {
            cout << "\n[!] Event not found.\n";
            return;
        }
        AttendeeNode* newAttendee = new AttendeeNode(attendeeID, name, email);
        if (!event->attendeeHead) { // If no attendees exist
            event->attendeeHead = newAttendee;
            newAttendee->next = newAttendee;
        } else { // Insert at the end of circular list
            AttendeeNode* temp = event->attendeeHead;
            while (temp->next != event->attendeeHead) {  // iterate if the same head is not found 
                temp = temp->next;
            }
            temp->next = newAttendee;
            newAttendee->next = event->attendeeHead;
        }
        cout << "\n[+] Attendee added successfully.\n";
    }

    // Display Attendees of a specific event
    void displayAttendees(int eventID) {
        processingAnimation("Loading Attendee List");
        EventNode* event = findEvent(eventID);
        if (!event) {  // check that the event is list or not 
            cout << "\n[!] Event not found.\n";
            return;
        }
        if (!event->attendeeHead) {    // check that the attendee  of event is exist 
            cout << "\n[!] No attendees for this event.\n";
            return;
        }
        cout << "\n************** Attendees for Event ID: " << eventID << " ***********************\n";
        AttendeeNode* temp = event->attendeeHead;
        do {
            cout << "ID: " << temp->attendeeID << ", Name: " << temp->attendeeName
                 << ", Email: " << temp->email << endl;
            temp = temp->next;
        } while (temp != event->attendeeHead); // it iterates untill the event id is not equal to attendee head 
        cout << "*****************************************************************\n";
    }
void delete_attendee(int eventID, int attendeeID) {
    processingAnimation("Deleting Attendee");

    EventNode* event = findEvent(eventID);
    if (!event) {
        cout << "\n[!] Event not found.\n";
        return;
    }

    if (!event->attendeeHead) {
        cout << "\n[!] No attendees for this event.\n";
        return;
    }

    AttendeeNode* current = event->attendeeHead;
    AttendeeNode* previous = NULL;

    // Circular doubly linked list traversal
    do {
        if (current->attendeeID == attendeeID) {
            if (current == event->attendeeHead) {  // Deleting the head
                if (current->next == current) { //Only one attendee
                    event->attendeeHead = NULL;
                } else {
                    event->attendeeHead = current->next;
                    if (previous) previous->next = current->next; //Important if it was a circular list
                }
            } else { // Deleting from elsewhere in the list
                if (previous) previous->next = current->next; //If previous is not null, connect it to the next
            }
            delete current;
            cout << "\n[-] Attendee deleted successfully.\n";
            return;
        }

        previous = current;
        current = current->next;

    } while (current != event->attendeeHead); //Crucial for circular list

    cout << "\n[!] Attendee not found.\n";
}
private:
    // Helper to find an event by ID
    EventNode* findEvent(int id) {
        EventNode* temp = head;
        while (temp && temp->eventID != id) { // check that the id exist or not 
            temp = temp->next;
        }
        return temp;
    }

    // Helper to print event details
    void printEvent(EventNode* event) {
        cout <<"ID: " << event->eventID <<endl;
		cout<<"Name: " << event->eventName<<endl;
        cout<<"DateTime: " << event->dateTime <<endl;
		cout<<"Location: " << event->location << endl;
    }
};
#endif

