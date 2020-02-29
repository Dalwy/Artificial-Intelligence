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




void display(map<int, string>);
int main() {
    int rules = 0;
    int userinput;
    vector<string> Majors = {"Engineering", "Science", "Business", "Medical", "English", "Geography", "Psychology",
                             "Agriculture", "Health Care", "Education"};


    map<int, string> owo;
    for(int x = 1;x <= Majors.size(); x++)
    {
        owo.insert(pair<int, string>(x, Majors[x-1]));
    }
    display(owo);
    cout << "Enter Shit: " << endl;
    cin >> userinput;

    auto it = owo.find(userinput);
    if(it != owo.end())
    {
        cout << "You have chosen " << it->second << " as your Profession yes?" << endl;
        string userchoice;
        cin >> userchoice;
        if(userchoice == "yes")
        {
            cout << "Do you like this shit? (yes/no): " << endl;
            cin >> userchoice;
        }
    }
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