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
        show_menu();
        cout << "Your choice: " << endl;
        int choice = 0;

        while(true)
        {
            cin >> choice;
            switch (choice)
            {
                case ADD_NOTE:
                    system("cls");
                    cout << " Add Notes... " << endl;
                    break;
                
                case SEE_ALL_NOTES:
                    system("cls");
                    cout << " Show All Notes... " << endl;
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