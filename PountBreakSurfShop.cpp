// PountBreakSurfShop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>;
#include <fstream>;
#include <iomanip>;
#include <string>;
#include <algorithm>;
#include "windows.h";

using namespace std;

// Constants
const float PRICESMALL = 175.00f;
const float PRICEMEDIUM = 190.00f;
const float PRICELARGE = 200.00f;


void ShowUsage()
{
    cout << "To show program usage 'S' " << endl;
    cout << "To purchase a surfboard press 'P' " << endl;
    cout << "To display current purchases press 'C' " << endl;
    cout << "To display total amount press 'T' " << endl;
    cout << "To quit the program press 'Q' " << endl;
    cout << endl;
}

void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge)
{
    int iNumOf;
    char cSize;

    cout << "Please enter the quanity and type (S = small, M = medium, L = large) of surfboard you would like to purchase:  " << endl;
    cin >> iNumOf >> cSize;

    if (cSize == 'S' || cSize == 's')
    {
        iTotalSmall = iTotalSmall + iNumOf;
    }
    else if (cSize == 'M' || cSize == 'm')
    {
        iTotalMedium = iTotalMedium + iNumOf;
    }
    else if (cSize == 'L' || cSize == 'l')
    {
        iTotalLarge = iTotalLarge + iNumOf;
    }
    else
    {
        cout << "Error: Invaild Input" << endl;
        cout << "Please enter 'P' and then your surfboard selection again." << endl;
        cout << "Please enter 'S' to see how to use the program." << endl; 
    }
        

     cout << endl;
}

void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{
    string s1 = "The total number of ";
    string s2 = " surfboards is ";

    if (iTotalSmall > 0)
        cout << s1 << "small" << s2 << iTotalSmall << endl;
    if (iTotalMedium > 0)
        cout << s1 << "medium" << s2 << iTotalMedium << endl;
    if (iTotalLarge > 0)
        cout << s1 << "large" << s2 << iTotalLarge << endl;
    if (iTotalLarge == 0 && iTotalMedium == 0 && iTotalSmall == 0)
        cout << "No purchases made yet." << endl;
    cout << endl;
}

void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{
    float fSmallCost;
    float fMediumCost;
    float fLargeCost;
    if (iTotalLarge == 0 && iTotalMedium == 0 && iTotalSmall == 0)
        cout << "No purchases made yet." << endl;
    else
    {
        fSmallCost = iTotalSmall * PRICESMALL;
        fMediumCost = iTotalMedium * PRICEMEDIUM;
        fLargeCost = iTotalLarge * PRICELARGE;

        string s3 = "The total number of ";
        string s4 = " surfboards is ";
        string s5 = " at a total of $";

        if (iTotalSmall > 0)
            cout << fixed << setprecision(2) << s3 << "small" << s4 << iTotalSmall << s5 << fSmallCost << endl;
        if (iTotalMedium > 0)
            cout << fixed << setprecision(2) << s3 << "medium" << s4 << iTotalMedium << s5 << fMediumCost << endl;
        if (iTotalLarge > 0)
            cout << fixed << setprecision(2) << s3 << "large" << s4 << iTotalLarge << s5 << fLargeCost << endl;
        cout << fixed << setprecision(2) << "Amount due: $" << fSmallCost + fMediumCost + fLargeCost << endl;
    }
    cout << endl;

}

int main()
{
    // VARIABLES
    char cUserIn = 'S';
    int iTotalSmall = 0;
    int iTotalMedium = 0;
    int iTotalLarge = 0;

    // HEADER
    string sTitle = " Welcome to my Johnny Utah's PointBreak Surf Shop";
    const int iTitleLen = sTitle.length();
    const int TITLEWIDTH = 60;
    cout << setfill('*') << setw(TITLEWIDTH) << '*' << endl;
    cout << setfill('*') << setw((TITLEWIDTH - iTitleLen)/2) << '*' << sTitle << right << setw((TITLEWIDTH - iTitleLen) / 2)<< '*' << endl;
    cout << setfill('*') << setw(TITLEWIDTH) << '*' << endl << endl;

    while (cUserIn != 'Q')
    {
        if (cUserIn == 'S' || cUserIn == 's')
            ShowUsage();
        else if (cUserIn == 'P' || cUserIn == 'p')
            MakePurchase(iTotalSmall, iTotalMedium, iTotalLarge);
        else if (cUserIn == 'C' || cUserIn == 'c')
            DisplayPurchase(iTotalSmall, iTotalMedium, iTotalLarge);
        else if (cUserIn == 'T' || cUserIn == 't')
            DisplayTotal(iTotalSmall, iTotalMedium, iTotalLarge);
        else if (cUserIn == 'Q' || cUserIn == 'q')
        {
            cout << "Thank you" << endl;
            break;
        }
        else
        {
            cout << "Error: Invaild Input" << endl;
            ShowUsage(); 
        }
            
        string sPromote = "Please enter selection: ";
        cout << sPromote << endl;
        cin >> cUserIn;


    }
        
    system("pause");
    return 0;
}


