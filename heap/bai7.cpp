#include <queue>
#include <string>
#include <iostream>
using namespace std;

class PrinterQueue
{
private:
    struct FileRequest {
        int priority;
        string fileName;

        bool operator<(const FileRequest& other) const {
            if (priority != other.priority) {
                return priority < other.priority;
            } else {
                return false;
            }
        }
    };

    priority_queue<FileRequest> fileQueue;

public:
    void addNewRequest(int priority, string fileName) {
        fileQueue.push({priority, fileName});
    }

    void print() {
        if (!fileQueue.empty()) {
            FileRequest nextFile = fileQueue.top();
            fileQueue.pop();

            cout << nextFile.fileName << endl;
        } else {
            cout << "No file to print" << endl;
        }
    }
};
