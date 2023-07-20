#include <iostream>
#include <string>
#include <vector>
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
                {
                    system("cls");
                    cout << " Add Notes... " << endl;

                    getline(cin, new_node); //перенос строки от cin
                    getline(cin, new_node);
                    cout << "Add Note : ";
                    add_note(new_node);

                    break;
                
                }
                    
                case SEE_ALL_NOTES:
                {
                    system("cls");
                    cout << " Show All Notes... " << endl;
                    see_all_notes();
                    break;
                
                }
                    
                case FIND_NOTE:
                {
                    system("cls");
                    cout << " Find Note... " << endl;

                    string note_to_find;
                    getline(cin, note_to_find);
                    cout << "Note to fine : ";
                    getline(cin, note_to_find);

                    vector<string> found_notes = find_one_note(note_to_find);
                    if(found_notes.size() != 0)
                    {
                        for(auto& a : found_notes) cout << a << endl;
                    }
                    else
                    {
                        cout << "Not such note!" << endl;
                    }
                    break;
                }
                    
                case REMOVE_NOTE:
                {
                    system("cls");
                    cout << " Remove Note..." << endl << "Enter the number of note: ";   
                    int number_of_note;
                    cin >> number_of_note;
                    remove_note(number_of_note);
                    break;
                }
                    
                case REMOVE_ALL_NOTES:
                {
                    system("cls");
                    cout << " Remove All Notes... " << endl;
                    remove_all_notes();
                    break;
                }
                    
                default:
                {
                    system("cls");
                    cout << " Exit... " << endl;
                    return 0;
                }
                    
            }
        }
}