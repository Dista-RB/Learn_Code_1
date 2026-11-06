#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>
#include <type_traits>

struct Data {
    int number ;
    std:: string Subject ;
    int Value ;
    std:: string gpa ;
};
int n;

double GradeToPoint(std::string grade);

std::vector<Data> EnterName() {
    std::cout << "Pleases Enter Number of Subject : " << std:: endl;
    std::cin >> n ;
    while (std::cin.fail()||n <= 0 ) {
        std::cout << "Number of subject must be more than 0, or its not number please try again : " ;
        
        std::cin.clear() ;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> n ;
    }
    std::vector<Data>subjects(n) ;

    for (int i = 0 ; i < n ; i++) {
        std:: cout << "enter subject name : " ;
        std:: cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n'
        );
        std::getline(std::cin, subjects[i].Subject);

        std:: cout << "enter value of subject : " ;
        std:: cin >> subjects[i].Value ;
        while (std::cin.fail()||subjects[i].Value <= 0 ) {
            std::cout << "Value must be number or more than 0 please try again : " ;
            std::cin.clear() ;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> subjects[i].Value ;
        }

        std:: cout << "please Enter GPA of subject : " << std::endl;
        std:: cin >> subjects[i].gpa ;
        while (GradeToPoint(subjects[i].gpa) < 0)
        {
            std::cout << "You enter wrong character please try again : " ;
            std::cin>> subjects[i].gpa ;
        }
         
    }

    return subjects ;
}

double GradeToPoint(std::string grade) {

    if (grade == "A")  return 4.00;
    if (grade == "B+") return 3.50;
    if (grade == "B")  return 3.00;
    if (grade == "C+") return 2.50;
    if (grade == "C")  return 2.00;
    if (grade == "D+") return 1.50;
    if (grade == "D")  return 1.00;
    if (grade == "F")  return 0.00;

    return -1.00;
}

double CalculateGPA(std::vector<Data> subjects) {
    double total = 0 ;
    double credits = 0 ;
    double x ;

    for (size_t i = 0 ; i < subjects.size(); i++) {
        x = GradeToPoint(subjects[i].gpa)*subjects[i].Value ;
        total += x ;
        credits += subjects[i].Value ;
    }
    return total / credits ;
}

int main() {

    std::vector<Data> result = EnterName();

    double GPA = CalculateGPA(result);

    std::cout << "\n" << std::left
              << std::setw(5)  << "n"
              << std::setw(20) << "subject"
              << std::setw(8)  << "credit"
              << std::setw(6)  << "gpa" << std::endl;
    std::cout << std::string(39, '-') << std::endl;

    for (size_t i = 0 ; i < result.size() ; i++) {
        std::cout << std::setw(5)  << i + 1
                  << std::setw(20) << result[i].Subject
                  << std::setw(8)  << result[i].Value
                  << std::setw(6)  << result[i].gpa << std::endl;
    }

    std::cout << std::string(39, '-') << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Your GPA = " << GPA << std::endl;

    return 0;
}
