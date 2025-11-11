#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

class Resume {
protected:
    string name, email, contact;
public:
    virtual void inputBasicDetails() {
        cout << "\n=== Create Your Resume ===\n";
        cout << "👉 Enter full name: "; getline(cin, name);
        if (name.empty()) throw invalid_argument("Name cannot be empty!");
        cout << "👉 Enter email: "; getline(cin, email);
        if (email.empty()) throw invalid_argument("Email cannot be empty!");
        cout << "👉 Enter contact number: "; getline(cin, contact);
        if (contact.empty()) throw invalid_argument("Contact cannot be empty!");
    }
};

class DetailedResume : public Resume {
    string education, skills, experience;
public:
    void inputAdditionalDetails() {
        cout << "\n👉 Enter education (e.g. B.E. in Computer Engineering - MITAOE): ";
        getline(cin, education);
        if (education.empty()) throw invalid_argument("Education cannot be empty!");
        cout << "👉 Enter skills (e.g. C++, Java, Android, Firebase): ";
        getline(cin, skills);
        if (skills.empty()) throw invalid_argument("Skills cannot be empty!");
        cout << "👉 Enter experience (press Enter if none): ";
        getline(cin, experience);
        if (experience.empty()) experience = "Fresher";
    }

    void createResumeFile() {
        string filename = name + "_Resume.txt";
        ofstream f(filename.c_str());
        if (!f) throw runtime_error("Error creating file!");
        f << "-------------------------------\n           RESUME\n-------------------------------\n";
        f << "Name: " << name << "\nEmail: " << email << "\nContact: " << contact
          << "\n\nEDUCATION:\n" << education << "\n\nSKILLS:\n" << skills
          << "\n\nEXPERIENCE:\n" << experience << "\n-------------------------------\n";
        f.close();
        cout << "\n✅ Resume saved as '" << filename << "'!\n";
    }

    void viewResume() {
        string filename; cout << "\nEnter filename (e.g. Namita_Resume.txt): "; getline(cin, filename);
        ifstream f(filename.c_str()); if (!f) throw runtime_error("File not found!");
        cout << "\n----- Your Resume -----\n"; string line; while (getline(f, line)) cout << line << "\n"; f.close();
    }

    void updateResume() {
        string filename; cout << "\nEnter filename to update: "; getline(cin, filename);
        fstream f(filename.c_str(), ios::in); if (!f) throw runtime_error("File not found!"); f.close();
        int ch; cout << "\n1. Update Skills\n2. Update Experience\nEnter choice: "; cin >> ch; cin.ignore();
        string info; 
        if (ch == 1) { cout << "Enter updated skills: "; getline(cin, info); if (info.empty()) throw invalid_argument("Skills cannot be empty!"); skills = info; }
        else if (ch == 2) { cout << "Enter updated experience: "; getline(cin, info); if (info.empty()) info = "Fresher"; experience = info; }
        else throw invalid_argument("Invalid choice!");
        ofstream nf(filename.c_str(), ios::app); if (!nf) throw runtime_error("Error updating file!");
        nf << "\n[UPDATED INFORMATION]\n" << (ch == 1 ? "SKILLS: " : "EXPERIENCE: ") << info << "\n"; nf.close();
        cout << "\n✅ Resume updated successfully!\n";
    }
};

void showMenu() {
    cout << "\n========== RESUME BUILDER ==========\n"
         << "1. Create New Resume\n2. View Resume\n3. Update Resume\n4. Exit\n"
         << "===================================\nEnter choice: ";
}

int main() {
    int ch; DetailedResume r;
    do {
        showMenu(); cin >> ch; cin.ignore();
        try {
            if (ch == 1) { r.inputBasicDetails(); r.inputAdditionalDetails(); r.createResumeFile(); }
            else if (ch == 2) r.viewResume();
            else if (ch == 3) r.updateResume();
            else if (ch == 4) cout << "\n👋 Goodbye, Namita!\n";
            else cout << "⚠️ Invalid choice.\n";
        } 
        catch (const invalid_argument &e) { cout << "\nInput Error ❌: " << e.what() << "\n"; }
        catch (const runtime_error &e) { cout << "\nFile Error ⚠️: " << e.what() << "\n"; }
        catch (...) { cout << "\nUnknown Error ❗\n"; }
    } while (ch != 4);
    return 0;
}