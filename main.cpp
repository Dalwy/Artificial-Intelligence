#include <iostream>
#include <map>
#include <iterator>
#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;


/**
 * Create an intelligent computer expert system for career advising to a freshman student who wishes to choose a major to pursue his/her studies.
 * First use Backward Chaining methodology to determine the profession in which the student is interested.
 * Use at least ten professions like Engineering, Science, Business, Medical, English, Geography, Psychology, Agriculture, Health Care, and Education.
 * Then use Forward Chaining methodology to recommend a specific area in which a student should pursue.
 * For example, if the profession is engineering the area could be chosen from Electrical, Mechanical, Civil, petroleum, chemical etc.;
 * if the profession is medical, the area could be chosen from mental health, oncologist, orthopedic, cardiologist, and General practitioner etc.;
 * if the profession is health care, the area could be chosen from nursing, Health Services Management, Healthcare Administration, Physician Assistant, and Public Health, etc.
 * Use a minimum of five areas for each profession.
 * You can use Web or any other source to collect knowledge to develop knowledge bases.
 *
 * A student who wishes to avail advising service will enter data in response to prompts from the Expert system.
 * Your expert system will first advise the profession and then a specific area in that profession.
 *
 * After collecting knowledge, develop two decision trees;
 * one for Backward Chaining to advise the profession and second for Forward Chaining to advise the specific area in the chosen profession.
 * Then transform the decision trees into rules.
 * The rules should contain variables.
 * At least 50 rules should be used in total for backward chaining and forward chaining.
 * Also, develop a user-friendly interface in restricted English format, which receives input data from a student, uses keyword matching, and responds in a restricted English format.
 * @return
 */



string bwChain();
string fwChain(string);
void display(map<int, string>);
int main() {

    string Profession = bwChain();
    cout << "A good profession for you is: " << Profession << endl;
//    string x = fwChain(Profession);
//    cout << x;


//    map<int, string> owo;
//    owo.insert(pair<int, string>(10, "Engineering"));
//    owo.insert(pair<int, string>(20, "Science"));
//    owo.insert(pair<int, string>(30, "Business"));
//    owo.insert(pair<int, string>(40, "Medical"));
//    owo.insert(pair<int, string>(50, "English"));
//    owo.insert(pair<int, string>(60, "Geography"));
//    owo.insert(pair<int, string>(70, "Psychology"));
//    owo.insert(pair<int, string>(80, "Agriculture"));
//    owo.insert(pair<int, string>(90, "Health Care"));
//    owo.insert(pair<int, string>(100, "Education"));
//
//    display(owo);
//    char userinput;
//
//    cout << "Choose Major: " << endl;
//    cout << "A: Business" << endl;
//    cout << "B: Medical" << endl;
//    cin >> userinput;
//    if(rules = 20)
//    {
//        cout << it->second;
//    }
//    for(rules = 10; rules <= 10; rules++)
//    {
//        if(userinput == 'A')
//            cout << it->first << it->second;
//    }
//    for(rules = 20; rules; rules++)
//    {
//        if(userinput == 'A')
//            cout << it->first << it->second;
//    }

    return 0;
}

void display(map<int, string> owo)
{

    for(auto & it : owo)
    {
        cout << it.first << ": " << it.second << endl;
    }
}

string bwChain()
{
    int userinput;
    string userchoice;
    int Rn = 0;
    string Engin = "Engineering";
    string Sci = "Science";
    string Med = "Medical";
    string Eng = "English";
    string Geo = "Geography";
    string Psy = "Psychology";
    string Agr = "Agriculture";
    string HC = "Health Care";
    string EDU = "Education";
    string BUS = "Business";


    /**
     * WHY THE FUCK DOES THIS CRASH IT.
     */
//    string professions = {"Engineering", "Science"};
//    string professions2 = {"Medical", "English"};
//    string professions3 = {"Geography", "Psychology"};
//    string professions4 ={"Agriculture", "Health Care"};


    vector<string> MajorsQuesiton = {"Do you like Math?", "Do you like Chem?", "Do you like Nature?", "Are you interesting in farming?",
                             "Are you interested in helping people?", "Are you interested in Finances?",
                             "Are you interested in Writing?", "Are you interested in teaching?"};

//    for(int z = 1; z <= Professions.size(); z++)
//    {
//        Rn = z *10;
//        cout << Rn << endl;
//    }

    map<int, string> owo;
    for(int x = 1;x <= MajorsQuesiton.size(); x++)
    {
        Rn = x * 10;
        owo.insert(pair<int, string>(Rn, MajorsQuesiton[x-1]));
    }

    display(owo);
    cout << "Do you like STEM? (Yes/No):  " << endl;
    cin >> userchoice;
    if(userchoice == "Yes" || userchoice == "yes")
    {
        auto it = owo.find(10);
        cout << it->second << endl;
        cin >> userchoice;
        if(userchoice == "Yes" || userchoice == "yes")
        {
            return Engin;
        }
        else if(userchoice == "No" || userchoice == "no")
        {
            auto itr = owo.find(20);
            cout << itr->second << endl;
            cin >> userchoice;
            if(userchoice == "Yes"|| userchoice == "yes")
            {
                return Med;
            }
            else if(userchoice == "No" || userchoice == "no")
            {
                auto it = owo.find(30);
                cout << it->second << endl;
                cin >> userchoice;
                if(userchoice == "Yes" || userchoice == "yes")
                {
                    auto it = owo.find(40);
                    cout << it->second << endl;
                    cin >> userchoice;
                    if(userchoice == "Yes" || userchoice == "yes")
                    {
                        return Agr;
                    }
                    else if (userchoice == "No" || "no")
                        return Geo;
                }
                else if(userchoice =="No" || userchoice == "no")
                    return Sci;
            }
        }
    }
    else if(userchoice == "No" || userchoice == "no")
    {
        auto it = owo.find(50);
        cout << it->second << endl;
        cin >> userchoice;
        if(userchoice == "Yes" || userchoice == "yes")
        {
            auto it = owo.find(70);
            cout << it->second << endl;
            cin >> userchoice;
            if(userchoice == "yes" || userchoice == "Yes")
            {
                auto it = owo.find(80);
                cout << it->second << endl;
                cin >> userchoice;
                if(userchoice == "Yes" || userchoice == "yes")
                {
                    return EDU;
                }
                else if(userchoice == "No" || userchoice == "no")
                    return Eng;
            }
            else if(userchoice == "No" || userchoice == "no")
                return Psy;
        }
        else if(userchoice == " Yes" || userchoice == "yes")
        {
            auto it = owo.find(60);
            cout << it->second << endl;
            cin >> userchoice;
            if(userchoice == "Yes" || userchoice == "yes")
                return BUS;
            else if(userchoice == "No" || userchoice == "no")
                return HC;
        }
    }
//        cout << "Please pick a Major you are interesting in by typing the number!" << endl;
//        display(owo);
//        cin >> userinput;


//        switch(userinput)
//        {
//            case 10:
//                cout << "Engineering" << endl;
//                break;
//            case 20:
//                cout << "Medical" << endl;
//                break;
//            case 30:
//                cout << "Science" << endl;
//                break;
//            default:
//
//                break;
//        }
//    }



//    auto it = owo.find(userinput);

//    if(it != owo.end())
//    {
//        cout << "You have chosen " << it->second << " as your Profession yes?" << endl;
//        string userchoice;
//        cin >> userchoice;
//        if(userchoice == "yes")
//        {
//            cout << "Do you like this shit? (yes/no): " << endl;
//            cin >> userchoice;
//        }
//    }
}

string fwChain(string Profession)
{
    int rn;
    string userchoice;
    string CE = "Civil Engineering";
    string ME = "Mechanical Engineering";
    vector<string> Enginerring = {"Do you like circuits?", "do you like machines?", "do you like buidlings?"};
    vector<string> Business = {"Do you like circuits?", "do you like machines?", "do you like buidlings?"};
    map<int, string> var;
    for(int x = 1;x <= Enginerring.size(); x++)
    {
        rn = x * 10;
        var.insert(pair<int, string>(rn, Enginerring[x-1]));
    }
    if(Profession == "Engineering")
    {
        auto it = var.find(10);
        cout << it->second << endl;
        cin >> userchoice;
        if(userchoice == "Yes" || userchoice == "yes")
        {
            return CE;
        }
        if(userchoice == "No" || userchoice == "no")
        {
            auto it = var.find(20);
            cout << it->second << endl;
            cin >> userchoice;
            if(userchoice == "Yes" || userchoice == "yes")
                return ME;
        }

    }

}