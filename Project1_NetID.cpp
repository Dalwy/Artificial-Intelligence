/**
 * @authors: Dalton Melville, Sam Swanson, Charlie Orch
 */
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
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



string Profession_BW();
string Area_FW(const string&);
void display(const map<int, string>&);
int askAgain();
int main()
{


    vector<string> Professions = {"Engineering", "Science", "Medical", "English",
                                  "Geography", "Psychology", "Agriculture", "Health Care", "Education","Business"};

    bool y = false;
    int choice = 0;
    string Profession;
    string SpecificArea;
    while(!y)
    {
        cout << "Please pick an option based on number." << endl;
        cout << "1. Start Expert System" << endl;
        cout << "2. End Program" << endl;
        cin >> choice;
        switch(choice) {
            case 1:
                Profession = Profession_BW();
                if(find(Professions.begin(), Professions.end(), Profession) != Professions.end()) {
                    cout << "A good profession for you is: " << Profession << "\n" << endl;
                    SpecificArea = Area_FW(Profession);
                    cout << "A good area in that field for you is: " << SpecificArea;
                    askAgain();
                }
                else
                    return 3;
            case 2:
                y = true;
            default: ;
        }
    }
    return 0;
}

/**
 *
 * @return: Expert system will return the Profession it thinks is best for the student based on their answers.
 */
string Profession_BW()
{
    string userchoice;
    unsigned int Rn = 0;
    //These could be put into one vector but having seperate strings makes for easier readability.
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
    string undefined = "Undefined";
    vector<string> MajorsQuesiton = {"Do you like Math?", "Do you like Chem?", "Do you like Nature?",
                                     "Are you interesting in farming?",
                                     "Are you interested in helping people?", "Are you interested in Finances?",
                                     "Are you interested in Writing?", "Are you interested in teaching?"};
    map<int, string> Rules;
    for(unsigned int x = 1;x <= MajorsQuesiton.size(); x++)
    {
        Rn = x * 10;
        Rules.insert(pair<int, string>(Rn, MajorsQuesiton[x-1]));
    }

//    display(Rules);
    cout << "Do you like STEM? (Yes/No):  " << endl;
    cin >> userchoice;
    if(userchoice == "Yes" || userchoice == "yes")
    {
        auto it = Rules.find(10);
        cout << it->second << endl;
        cin >> userchoice;
        if(userchoice == "Yes" || userchoice == "yes")
        {
            return Engin;
        }
        else if(userchoice == "No" || userchoice == "no")
        {
            auto itr = Rules.find(20);
            cout << itr->second << endl;
            cin >> userchoice;
            if(userchoice == "Yes"|| userchoice == "yes")
            {
                return Med;
            }
            else if(userchoice == "No" || userchoice == "no")
            {
                it = Rules.find(30);
                cout << it->second << endl;
                cin >> userchoice;
                if(userchoice == "Yes" || userchoice == "yes")
                {
                    it = Rules.find(40);
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
        auto it = Rules.find(50);
        cout << it->second << endl;
        cin >> userchoice;
        if(userchoice == "Yes" || userchoice == "yes")
        {
            it = Rules.find(70);
            cout << it->second << endl;
            cin >> userchoice;
            if(userchoice == "yes" || userchoice == "Yes")
            {
                it = Rules.find(80);
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
        else if(userchoice == "No" || userchoice == "no")
        {
            it = Rules.find(60);
            cout << it->second << endl;
            cin >> userchoice;
            if(userchoice == "Yes" || userchoice == "yes")
                return BUS;
            else if(userchoice == "No" || userchoice == "no")
                return HC;
        }
    }

    /**
     * Was initialy going to use switch statements to handle the condiditons
     */
//        cout << "Please pick a Major you are interesting in by typing the number!" << endl;
//        display(Rules);
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
//    auto it = Rules.find(userinput);
    return undefined;
}
/**
 * Forward chaining will ask the user what they like in order to find a specific area in which they should go to.
 *
 * @param Major: Major is the parameter from which the user got from bwChain()
 * @return: Returns with the specific area (Profession) in which the user should look into going for.
 */
string Area_FW(const string& Profession)
{
    unsigned int rn;
    string userchoice;


/**
 * These comments were our initial thought as to how to split up each Area but ultimately decided to have them all in
 * on vector.
 */
//    vector <string> SpecificArea= {"Civil Engineering", "Mechanical Engineering", "Chemical Engineer", "Electrical Engineer",
//                            "Industrial Engineer"};
//    vector <string> SAS= {"Computer Scientist", "Physicist", "Chemist", "Biologist",
//                            "Astronomer"};
//    vector <string> SAB= {"Financial Adviser", "Marketer", "Accountant", "Stock Broker",
//                            "Adviser"};
//    vector <string> SAM= {"Nursing", "Dentistry", "Physical Therapy", "Surgeon",
//                            "Pharmacist"};
//    vector <string> SAE= {"Author", "Journalist","Editor","Poet", "Historian"};
//    vector <string> SAED= {"High School Teacher", "Professor", "Elementary School Teacher","Special Education Teacher","Tutor"};
//    vector <string> SAHC= {"Nutritionist", "Dietician","Veterinary","Music Therapy","Athletic Trainer"};
//    vector <string> SAA= {"Crop Farmer", "Rancher", "Food Scientist", "Dairy Farmer", "Aquaculture"};
//    vector <string> SAP= {"Counselor", "Forensic Psychologist", "Health Psychologist", "School Psychologist", "Psychiatrist"};
//    vector <string> SAG= {"Cartographer", "Climatologist" , "Environmental Manager", "Demographer", "Park Ranger"};


    vector <string> SpecificArea = {"Civil Engineering", "Mechanical Engineering", "Chemical Engineer", "Electrical Engineer",
                                    "Industrial Engineer",
                                    "Computer Scientist", "Physicist", "Chemist", "Biologist","Astronomer",
                                    "Financial Adviser", "Marketer", "Accountant", "Stock Broker","Adviser",
                                    "Nursing", "Dentistry", "Physical Therapy", "Surgeon","Pharmacist",
                                    "Author", "Journalist","Editor","Poet", "Historian",
                                    "High School Teacher", "Professor", "Elementary School Teacher","Special Education Teacher",
                                    "Tutor", "Nutritionist", "Dietician","Veterinary","Music Therapy","Athletic Trainer",
                                    "Crop Farmer", "Rancher", "Food Scientist", "Dairy Farmer", "Aquaculture","Counselor",
                                    "Forensic Psychologist", "Health Psychologist", "School Psychologist", "Psychiatrist",
                                    "Cartographer", "Climatologist" , "Environmental Manager", "Demographer", "Park Ranger",
                                    "Undefined"};

    vector<string> RuleQuestion = {"Do you like construction?",
                                   "Do you like physics and math?",
                                   "Do you like using chemicals?",
                                   "Do you like using technology?",
                                   "Do you like machines?",
                                   "Are you interested in computers?",
                                   "Do you like physics?",
                                   "Do you like chemistry?",
                                   "Do you like biology?",
                                   "Do you like space?", //100
                                   "Do you like giving advice about money?",
                                   "Do you like making products likable?",
                                   "Do you like dealing with others money?",
                                   "Do you like investing money?",
                                   "Do you like showing off products?",
                                   "Do you like helping people?",
                                   "Do you like teeth?",
                                   "Are you interested in how muscles work?",
                                   "Do you like cutting people open?",
                                   "Do you like making chemicals to make drugs?", //200
                                   "Do you like writing books?",
                                   "Do you like articles?",
                                   "Do you like editing writing?",
                                   "Do you like writing poems?",
                                   "Do you like the history of english?",
                                   "Do you like teaching teenagers?",
                                   "Do you like teaching college students?",
                                   "Do you like young kids?",
                                   "Do you like teaching kids who need more help?",
                                   "Do you like helping people with homework?",//300
                                   "Do you like the benefits of food?",
                                   "Do you like helping people with weight loss?",
                                   "Do you like helping animals?",
                                   "Do you like helping people with music?",
                                   "Do you like helping people become fit?",
                                   "Do you like crops?",
                                   "Do you like taking care of your own land?",
                                   "Do you like analyzing food?",
                                   "Do you like dealing with cows?",
                                   "Are you interested in lakes and oceans?", //400
                                   "Do you like talking with troubled people?",
                                   "Do you like working with crime scenes?",
                                   "Do you like helping people with mental health?",
                                   "Do you like dealing with troubled students?",
                                   "Do you like dealing with mental disorders?",
                                   "Do you like making maps?",
                                   "Do you like studying climate?",
                                   "Do you like training people about nature?",
                                   "Do you like studying about population?",
                                   "Do you like taking care of national parks?"};//500

//    map<int, string> MAP;
//    for(unsigned int x = 1; x <= SpecificArea.size(); x++)
//    {
//        MAP.insert(pair<int, string>(x, SpecificArea[x-1]));
//    }
    map<int, string> var;
    for(unsigned int x = 1; x <= RuleQuestion.size(); x++)
    {
        rn = x * 10;
        var.insert(pair<int, string>(rn, RuleQuestion[x-1]));
    }
//    display(var);
    if(Profession == "Engineering")
    {

        auto it = var.find(10);
        cout << it->second << endl;
        cin >> userchoice;
        if(userchoice == "Yes" || userchoice == "yes")
        {
            return SpecificArea[0];
        }
        if(userchoice == "No" || userchoice == "no")
        {
            it = var.find(20);
            cout << it->second << endl;
            cin >> userchoice;
            if(userchoice == "Yes" || userchoice == "yes")
                return SpecificArea[1];
            else if (userchoice == "No" || userchoice == "no")
            {
                it = var.find(30);
                cout << it->second << endl;
                cin >> userchoice;
                if(userchoice == "Yes" || userchoice == "yes")
                    return SpecificArea[2];
                else if(userchoice == "No" || userchoice == "no")
                {
                    it = var.find(40);
                    cout << it->second << endl;
                    cin >> userchoice;
                    if(userchoice == "Yes" || userchoice == "yes")
                        return SpecificArea[3];
                    else if (userchoice == "No" || userchoice == "no")
                    {
                        it = var.find(50);
                        cout << it->second << endl;
                        cin >> userchoice;
                        if(userchoice == "Yes" || userchoice == "yes")
                            return SpecificArea[4];
                        else if(userchoice == "No" || userchoice == "no")
                        {
                            return SpecificArea[50];
                        }
                    }
                }
            }
        }
    }
    else if(Profession == "Science")
    {
        auto it = var.find(60);
        cout << it->second << endl;
        cin >> userchoice;
        if(userchoice == "Yes" || userchoice == "yes")
        {
            return SpecificArea[5];
        }
        if(userchoice == "No" || userchoice == "no")
        {
            it = var.find(70);
            cout << it->second << endl;
            cin >> userchoice;
            if(userchoice == "Yes" || userchoice == "yes")
                return SpecificArea[6];
            else if (userchoice == "No" || userchoice == "no")
            {
                it = var.find(80);
                cout << it->second << endl;
                cin >> userchoice;
                if(userchoice == "Yes" || userchoice == "yes")
                    return SpecificArea[7];
                else if(userchoice == "No" || userchoice == "no")
                {
                    it = var.find(90);
                    cout << it->second << endl;
                    cin >> userchoice;
                    if(userchoice == "Yes" || userchoice == "yes")
                        return SpecificArea[8];
                    else if (userchoice == "No" || userchoice == "no")
                    {
                        it = var.find(100);
                        cout << it->second << endl;
                        cin >> userchoice;
                        if(userchoice == "Yes" || userchoice == "yes")
                            return SpecificArea[9];
                        else if(userchoice == "No" || userchoice == "no")
                        {
                            return SpecificArea[50];
                        }
                    }
                }
            }
        }
    }
    else if(Profession == "Business")
    {
        auto it = var.find(110);
        cout << it->second << endl;
        cin >> userchoice;
        if(userchoice == "Yes" || userchoice == "yes")
        {
            return SpecificArea[10];
        }
        if(userchoice == "No" || userchoice == "no")
        {
            it = var.find(120);
            cout << it->second << endl;
            cin >> userchoice;
            if(userchoice == "Yes" || userchoice == "yes")
                return SpecificArea[11];
            else if (userchoice == "No" || userchoice == "no")
            {
                it = var.find(130);
                cout << it->second << endl;
                cin >> userchoice;
                if(userchoice == "Yes" || userchoice == "yes")
                    return SpecificArea[12];
                else if(userchoice == "No" || userchoice == "no")
                {
                    it = var.find(140);
                    cout << it->second << endl;
                    cin >> userchoice;
                    if(userchoice == "Yes" || userchoice == "yes")
                        return SpecificArea[13];
                    else if (userchoice == "No" || userchoice == "no")
                    {
                        it = var.find(150);
                        cout << it->second << endl;
                        cin >> userchoice;
                        if(userchoice == "Yes" || userchoice == "yes")
                            return SpecificArea[14];
                        else if(userchoice == "No" || userchoice == "no")
                        {
                            return SpecificArea[50];
                        }
                    }
                }
            }
        }
    }
    else if(Profession == "Medical")
    {
        auto it = var.find(160);
        cout << it->second << endl;
        cin >> userchoice;
        if(userchoice == "Yes" || userchoice == "yes")
        {
            return SpecificArea[15];
        }
        if(userchoice == "No" || userchoice == "no")
        {
            it = var.find(170);
            cout << it->second << endl;
            cin >> userchoice;
            if(userchoice == "Yes" || userchoice == "yes")
                return SpecificArea[16];
            else if (userchoice == "No" || userchoice == "no")
            {
                it = var.find(180);
                cout << it->second << endl;
                cin >> userchoice;
                if(userchoice == "Yes" || userchoice == "yes")
                    return SpecificArea[17];
                else if(userchoice == "No" || userchoice == "no")
                {
                    it = var.find(190);
                    cout << it->second << endl;
                    cin >> userchoice;
                    if(userchoice == "Yes" || userchoice == "yes")
                        return SpecificArea[18];
                    else if (userchoice == "No" || userchoice == "no")
                    {
                        it = var.find(200);
                        cout << it->second << endl;
                        cin >> userchoice;
                        if(userchoice == "Yes" || userchoice == "yes")
                            return SpecificArea[19];
                        else if(userchoice == "No" || userchoice == "no")
                        {
                            return SpecificArea[50];
                        }
                    }
                }
            }
        }
    }
    else if(Profession == "English")
    {
        auto it = var.find(210);
        cout << it->second << endl;
        cin >> userchoice;
        if(userchoice == "Yes" || userchoice == "yes")
        {
            return SpecificArea[20];
        }
        if(userchoice == "No" || userchoice == "no")
        {
            it = var.find(220);
            cout << it->second << endl;
            cin >> userchoice;
            if(userchoice == "Yes" || userchoice == "yes")
                return SpecificArea[21];
            else if (userchoice == "No" || userchoice == "no")
            {
                it = var.find(230);
                cout << it->second << endl;
                cin >> userchoice;
                if(userchoice == "Yes" || userchoice == "yes")
                    return SpecificArea[22];
                else if(userchoice == "No" || userchoice == "no")
                {
                    it = var.find(240);
                    cout << it->second << endl;
                    cin >> userchoice;
                    if(userchoice == "Yes" || userchoice == "yes")
                        return SpecificArea[23];
                    else if (userchoice == "No" || userchoice == "no")
                    {
                        it = var.find(250);
                        cout << it->second << endl;
                        cin >> userchoice;
                        if(userchoice == "Yes" || userchoice == "yes")
                            return SpecificArea[24];
                        else if(userchoice == "No" || userchoice == "no")
                        {
                            return SpecificArea[50];
                        }
                    }
                }
            }
        }
    }
    else if(Profession == "Education")
    {
        auto it = var.find(260);
        cout << it->second << endl;
        cin >> userchoice;
        if(userchoice == "Yes" || userchoice == "yes")
        {
            return SpecificArea[25];
        }
        if(userchoice == "No" || userchoice == "no")
        {
            it = var.find(270);
            cout << it->second << endl;
            cin >> userchoice;
            if(userchoice == "Yes" || userchoice == "yes")
                return SpecificArea[26];
            else if (userchoice == "No" || userchoice == "no")
            {
                it = var.find(280);
                cout << it->second << endl;
                cin >> userchoice;
                if(userchoice == "Yes" || userchoice == "yes")
                    return SpecificArea[27];
                else if(userchoice == "No" || userchoice == "no")
                {
                    it = var.find(290);
                    cout << it->second << endl;
                    cin >> userchoice;
                    if(userchoice == "Yes" || userchoice == "yes")
                        return SpecificArea[28];
                    else if (userchoice == "No" || userchoice == "no")
                    {
                        it = var.find(300);
                        cout << it->second << endl;
                        cin >> userchoice;
                        if(userchoice == "Yes" || userchoice == "yes")
                            return SpecificArea[29];
                        else if(userchoice == "No" || userchoice == "no")
                        {
                            return SpecificArea[50];
                        }
                    }
                }
            }
        }
    }
    else if(Profession == "Health Care")
    {
        auto it = var.find(310);
        cout << it->second << endl;
        cin >> userchoice;
        if(userchoice == "Yes" || userchoice == "yes")
        {
            return SpecificArea[30];
        }
        if(userchoice == "No" || userchoice == "no")
        {
            it = var.find(320);
            cout << it->second << endl;
            cin >> userchoice;
            if(userchoice == "Yes" || userchoice == "yes")
                return SpecificArea[31];
            else if (userchoice == "No" || userchoice == "no")
            {
                it = var.find(330);
                cout << it->second << endl;
                cin >> userchoice;
                if(userchoice == "Yes" || userchoice == "yes")
                    return SpecificArea[32];
                else if(userchoice == "No" || userchoice == "no")
                {
                    it = var.find(340);
                    cout << it->second << endl;
                    cin >> userchoice;
                    if(userchoice == "Yes" || userchoice == "yes")
                        return SpecificArea[33];
                    else if (userchoice == "No" || userchoice == "no")
                    {
                        it = var.find(350);
                        cout << it->second << endl;
                        cin >> userchoice;
                        if(userchoice == "Yes" || userchoice == "yes")
                            return SpecificArea[34];
                        else if(userchoice == "No" || userchoice == "no")
                        {
                            return SpecificArea[50];
                        }
                    }
                }
            }
        }
    }else if(Profession == "Agriculture")
    {
        auto it = var.find(360);
        cout << it->second << endl;
        cin >> userchoice;
        if(userchoice == "Yes" || userchoice == "yes")
        {
            return SpecificArea[35];
        }
        if(userchoice == "No" || userchoice == "no")
        {
            it = var.find(370);
            cout << it->second << endl;
            cin >> userchoice;
            if(userchoice == "Yes" || userchoice == "yes")
                return SpecificArea[36];
            else if (userchoice == "No" || userchoice == "no")
            {
                it = var.find(380);
                cout << it->second << endl;
                cin >> userchoice;
                if(userchoice == "Yes" || userchoice == "yes")
                    return SpecificArea[37];
                else if(userchoice == "No" || userchoice == "no")
                {
                    it = var.find(390);
                    cout << it->second << endl;
                    cin >> userchoice;
                    if(userchoice == "Yes" || userchoice == "yes")
                        return SpecificArea[38];
                    else if (userchoice == "No" || userchoice == "no")
                    {
                        it = var.find(400);
                        cout << it->second << endl;
                        cin >> userchoice;
                        if(userchoice == "Yes" || userchoice == "yes")
                            return SpecificArea[39];
                        else if(userchoice == "No" || userchoice == "no")
                        {
                            return SpecificArea[50];
                        }
                    }
                }
            }
        }
    }
    else if(Profession == "Psychology")
    {
        auto it = var.find(410);
        cout << it->second << endl;
        cin >> userchoice;
        if(userchoice == "Yes" || userchoice == "yes")
        {
            return SpecificArea[40];
        }
        if(userchoice == "No" || userchoice == "no")
        {
            it = var.find(420);
            cout << it->second << endl;
            cin >> userchoice;
            if(userchoice == "Yes" || userchoice == "yes")
                return SpecificArea[41];
            else if (userchoice == "No" || userchoice == "no")
            {
                it = var.find(430);
                cout << it->second << endl;
                cin >> userchoice;
                if(userchoice == "Yes" || userchoice == "yes")
                    return SpecificArea[42];
                else if(userchoice == "No" || userchoice == "no")
                {
                    it = var.find(440);
                    cout << it->second << endl;
                    cin >> userchoice;
                    if(userchoice == "Yes" || userchoice == "yes")
                        return SpecificArea[43];
                    else if (userchoice == "No" || userchoice == "no")
                    {
                        it = var.find(450);
                        cout << it->second << endl;
                        cin >> userchoice;
                        if(userchoice == "Yes" || userchoice == "yes")
                            return SpecificArea[44];
                        else if(userchoice == "No" || userchoice == "no")
                        {
                            return SpecificArea[50];
                        }
                    }
                }
            }
        }
    }
    else if(Profession == "Geography")
    {
        auto it = var.find(460);
        cout << it->second << endl;
        cin >> userchoice;
        if(userchoice == "Yes" || userchoice == "yes")
        {
            return SpecificArea[45];
        }
        if(userchoice == "No" || userchoice == "no")
        {
            it = var.find(470);
            cout << it->second << endl;
            cin >> userchoice;
            if(userchoice == "Yes" || userchoice == "yes")
                return SpecificArea[46];
            else if (userchoice == "No" || userchoice == "no")
            {
                it = var.find(480);
                cout << it->second << endl;
                cin >> userchoice;
                if(userchoice == "Yes" || userchoice == "yes")
                    return SpecificArea[47];
                else if(userchoice == "No" || userchoice == "no")
                {
                    it = var.find(490);
                    cout << it->second << endl;
                    cin >> userchoice;
                    if(userchoice == "Yes" || userchoice == "yes")
                        return SpecificArea[48];
                    else if (userchoice == "No" || userchoice == "no")
                    {
                        it = var.find(500);
                        cout << it->second << endl;
                        cin >> userchoice;
                        if(userchoice == "Yes" || userchoice == "yes")
                            return SpecificArea[49];
                        else if(userchoice == "No" || userchoice == "no")
                        {
                            return SpecificArea[50];
                        }
                    }
                }
            }
        }
    }
    return SpecificArea[50];
}
/**
 *  Function is meant to ask the user whether they want to run through the program again
 *  This is for another user.
 * @return
 */
int askAgain() {
    string user;
    cout << "\n\nWould you like to go again?(yes/no)" << endl;
    cin >> user;
    if (user == "yes")
        main();
    else if (user == "no")
        return 3;
    else
        return 4;
    return 2;
}
/**
 * Display will display the rules with their questions
 * This function is not used in the program since there is no requirement for it, however if the user so pleases
 * they may call this anytime by simply putting
 *
 * display(<map name>);
 * where they would like to see it at.
 * @param Rules
 */
void display(const map<int, string>& Rules)
{

    for(auto & it : Rules)
    {
        cout << it.first << ": " << it.second << endl;
    }
}