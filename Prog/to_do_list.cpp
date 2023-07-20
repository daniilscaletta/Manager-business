#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

enum CHOICE
{
    ADD_NOTE = 1,
    SEE_ALL_NOTES,
    FIND_NOTE,
    REMOVE_NOTE,
    REMOVE_ALL_NOTES
};


int main(void)
{   
        int choice = 0;
        string new_node;

        while(true)
        {
            show_menu();   
            cout << "Your choice: " << endl;
            cin >> choice;
            switch (choice)
            {
                case ADD_NOTE:
                    system("cls");
                    cout << " Add Notes... " << endl;

                    getline(cin, new_node); //перенос строки от cin
                    getline(cin, new_node);
                    cout << "Add Note : ";
                    add_note(new_node);

                    break;
                
                case SEE_ALL_NOTES:
                    system("cls");
                    cout << " Show All Notes... " << endl;
                    see_all_notes();
                    break;
                
                case FIND_NOTE:
                    system("cls");
                    cout << " Find Note... " << endl;
                    break;

                case REMOVE_NOTE:
                    system("cls");
                    cout << " Remove Note... " << endl;                    
                    break;

                case REMOVE_ALL_NOTES:
                    system("cls");
                    cout << " Remove All Notes... " << endl;
                    break;
                default:
                    system("cls");
                    cout << " Exit... " << endl;
                    return 0;
            }
        }
        
    
    return 0;
}