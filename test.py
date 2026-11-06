class Data:
    def __init__(self, number, subject, value, gpa):
        self.number = number
        self.subject = subject
        self.value = value
        self.gpa = gpa

def GradeToPoint(grade):

    grade_points = {
        "A": 4.00,
        "B+": 3.50,
        "B": 3.00,
        "C+": 2.50,
        "C": 2.00,
        "D+": 1.50,
        "D": 1.00,
        "F": 0.00
    }

    return grade_points.get(grade, -1.00)

def EnterName():

    subjects = []

    while True:
        try: 
            n = int(input("Please Enter number of subject: "))

            if n > 0 :
                break
            print("Number of subject must be more than 0")

        except ValueError :
            print("Please enter valid number")

    for i in range(n):
        print(f"\nSubject{i + 1}")

        subject = input("Enter subject name: ")

        while True :
            try:
                value = int(input("Enter value of subject: "))

                if value > 0 :
                    break

                print("Value must be more than 0")

            except ValueError:
                print("Please enter a valid number")
        while True :
            gpa = input("Please Enter GPA of subject: ").upper()

            if GradeToPoint(gpa) >= 0:
                break
            print("You entered a wrong grade. Please try again")

        data = Data(i + 1, subject, value, gpa)

        subjects.append(data)

    return subjects

def CalculateGPA(subjects):
    total = 0
    credits = 0

    for subject in subjects:

        x = GradeToPoint(subject.gpa) * subject.value

        total += x
        credits += subject.value

    return total / credits

def DisplayResult(subjects, GPA):

    print("\n")
    print(f"{'n':<5}{'subject':<20}{'credit':<8}{'gpa':<6}")

    print("-" * 39)

    for subject in subjects:

        print(
            f"{subject.number:<5}"
            f"{subject.subject:<20}"
            f"{subject.value:<8}"
            f"{subject.gpa:<6}"
        )

    print("-" * 39)

    print(f"Your GPA = {GPA:.2f}")

def main():

    result = EnterName()

    GPA = CalculateGPA(result)

    DisplayResult(result, GPA)


if __name__ == "__main__":
    main()