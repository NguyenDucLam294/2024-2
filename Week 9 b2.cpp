#include <iostream>
#include <string>

using namespace std;

// Cấu trúc node để lưu trữ từng từ và số lượng của nó
struct WordNode {
    string word;
    int count;
    WordNode* next;

    WordNode(const string& w) : word(w), count(1), next(nullptr) {}
};

// Danh sách để quản lý từ
class WordList {
private:
    WordNode* head;

public:
    WordList() : head(nullptr) {}

    // Thêm chữ vào danh sách hoặc cập nhật số lượng
    void addWord(const string& word) {
        WordNode* current = head;
        WordNode* previous = nullptr;
        
        while (current) {
            if (current->word == word) {
                current->count++;
                return;
            }
            previous = current;
            current = current->next;
        }
        
        WordNode* newNode = new WordNode(word);
        if (previous) {
            previous->next = newNode;
        } else {
            head = newNode;
        }
    }

    // Trình bày danh sách từ và số lượng mỗi từ
    void showList() const {
        WordNode* current = head;
        while (current) {
            cout << "Word: " << current->word << ", Count: " << current->count << endl;
            current = current->next;
        }
    }

    // Tìm từ lặp lại nhiều nhất
    string mostCommonWord() const {
        WordNode* current = head;
        string frequentWord;
        int highestCount = 0;
        
        while (current) {
            if (current->count > highestCount) {
                highestCount = current->count;
                frequentWord = current->word;
            }
            current = current->next;
        }
        return frequentWord;
    }

    // Loại bỏ từ lặp
    void removeRepeats() {
        WordNode* current = head;
        WordNode* previous = nullptr;
        
        while (current) {
            if (current->word.length() >= 4 && 
                current->word.substr(0, current->word.length() / 2) == current->word.substr(current->word.length() / 2)) {
                
                cout << "Removing reduplicative word: " << current->word << endl;
                
                if (previous) {
                    previous->next = current->next;
                } else {
                    head = current->next;
                }
                
                delete current;
                current = previous ? previous->next : head;
            } else {
                previous = current;
                current = current->next;
            }
        }
    }

    // Đếm số từ trong danh sách
    int totalWords() const {
        int wordCount = 0;
        WordNode* current = head;
        while (current) {
            wordCount++;
            current = current->next;
        }
        return wordCount;
    }
};

int main() {
    WordList words;

    cout << "Enter a Vietnamese sentence: ";
    string sentence;
    getline(cin, sentence);

    // Chia câu thành các từ và thêm vào danh sách
    size_t pos = 0;
    string delimiter = " ";

    while ((pos = sentence.find(delimiter)) != string::npos) {
        string word = sentence.substr(0, pos);
        words.addWord(word);
        sentence.erase(0, pos + delimiter.length());
    }
    words.addWord(sentence); // Thêm từ cuối cùng

    cout << "\nInitial word list:\n";
    words.showList();

    string commonWord = words.mostCommonWord();
    cout << "Most frequent word: " << commonWord << endl;

    words.removeRepeats();
    cout << "\nWord list after removing repeats:\n";
    words.showList();

    int wordCount = words.totalWords();
    cout << "Total words: " << wordCount << endl;

    return 0;
}