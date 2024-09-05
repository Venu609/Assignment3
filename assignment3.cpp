#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int row;
    int col;
    int value;
    Node* next;
};

// Class to manage Sparse Matrix using linked list
class SparseMatrix {
private:
    Node* head;
    int rows, cols;

public:
    // Constructor to initialize matrix
    SparseMatrix(int r, int c) {
        rows = r;
        cols = c;
        head = nullptr;
    }

    // Insert a non-zero element
    void insertElement(int r, int c, int val) {
        Node* newNode = new Node;
        newNode->row = r;
        newNode->col = c;
        newNode->value = val;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Display sparse matrix in full form (with zeros)
    void displayMatrix() {
        Node* temp = head;
        cout << "Sparse Matrix Representation:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                bool found = false;
                temp = head;
                while (temp) {
                    if (temp->row == i && temp->col == j) {
                        cout << temp->value << " ";
                        found = true;
                        break;
                    }
                    temp = temp->next;
                }
                if (!found) {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }

    // Destructor to free memory
    ~SparseMatrix() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    int rows, cols, numNonZero, r, c, val;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter number of non-zero elements: ";
    cin >> numNonZero;

    SparseMatrix sparse(rows, cols);

    for (int i = 0; i < numNonZero; i++) {
        cout << "Enter row, column and value for element " << i + 1 << ": ";
        cin >> r >> c >> val;
        sparse.insertElement(r, c, val);
    }

    sparse.displayMatrix();

    return 0;
}