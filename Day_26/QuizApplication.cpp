#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

// Class to represent a single question
class Question {
private:
    string questionText;
    vector<string> options;
    char correctAnswer;

public:
    Question(string text, vector<string> opts, char answer) {
        questionText = text;
        options = opts;
        correctAnswer = toupper(answer);
    }

    void displayQuestion() {
        cout << "\n" << questionText << "\n";
        for (int i = 0; i < options.size(); i++) {
            cout << options[i] << "\n";
        }
    }

    bool isCorrect(char guess) {
        return toupper(guess) == correctAnswer;
    }

    char getCorrectAnswer() {
        return correctAnswer;
    }
};

// Class to manage the quiz logic
class Quiz {
private:
    vector<Question> questions;
    int score;

public:
    Quiz() {
        score = 0;
    }

    void addQuestion(const Question& q) {
        questions.push_back(q);
    }

    void start() {
        score = 0;
        int totalQuestions = questions.size();
        
        if (totalQuestions == 0) {
            cout << "No questions in the quiz.\n";
            return;
        }

        cout << "==== WELCOME TO THE C++ QUIZ ====\n";

        for (int i = 0; i < totalQuestions; i++) {
            cout << "\nQuestion " << (i + 1) << "/" << totalQuestions << ":";
            questions[i].displayQuestion();

            char userGuess;
            cout << "\nEnter your answer (A, B, C, or D): ";
            cin >> userGuess;

            if (questions[i].isCorrect(userGuess)) {
                cout << "Correct! 🎉(●'◡'●)\n";
                score++;
            } else {
                cout << "Incorrect. ❌ The correct answer was " << questions[i].getCorrectAnswer() << "\n";
            }
        }

        displayResults();
    }

    void displayResults() {
        cout << "\n================================\n";
        cout << "           QUIZ OVER!           \n";
        cout << "================================\n";
        cout << "Your Final Score: " << score << " / " << questions.size() << "\n";
        
        double percentage = ((double)score / questions.size()) * 100.0;
        cout << "Percentage: " << percentage << "%\n";
    }
};

int main() {
    // Create quiz instance
    Quiz myQuiz;

    // Add questions
    myQuiz.addQuestion(Question(
        "What is the correct syntax to output a string to the screen in C++?",
        {"A. Console.WriteLine()", "B. print()", "C. std::cout", "D. System.out.print()"},
        'C'
    ));

    myQuiz.addQuestion(Question(
        "Which of the following is a valid C++ data type?",
        {"A. real", "B. integer", "C. string", "D. character"},
        'C'
    ));

    myQuiz.addQuestion(Question(
        "Which symbol is used to terminate a statement in C++?",
        {"A. ;", "B. :", "C. .", "D. ,"},
        'A'
    ));

    // Start the quiz
    myQuiz.start();

    return 0;
}
