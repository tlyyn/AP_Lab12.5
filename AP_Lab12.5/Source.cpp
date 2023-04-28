#include <iostream>
#include <fstream>
#include <stack>
#include <string>


using namespace std;

struct Elem {
    Elem* link;
    char info;
};

void push(Elem*& top, char value) {
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = top;
    top = tmp;
}

char pop(Elem*& top) {
    Elem* tmp = top->link;
    char value = top->info;
    delete top;
    top = tmp;
    return value;
}

bool is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    else {
        return 0;
    }
}

string infix_to_postfix(string infix) {
    string postfix = "";
    stack<char> op_stack;
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (is_operator(c)) {
            while (!op_stack.empty() && precedence(op_stack.top()) >= precedence(c)) {
                postfix += op_stack.top();
                op_stack.pop();
            }
            op_stack.push(c);
        }
        else if (c == '(') {
            op_stack.push(c);
        }
        else if (c == ')') {
            while (!op_stack.empty() && op_stack.top() != '(') {
                postfix += op_stack.top();
                op_stack.pop();
            }
            op_stack.pop();
        }
        else {
            postfix += c;
        }
    }
    while (!op_stack.empty()) {
        postfix += op_stack.top();
        op_stack.pop();
    }
    return postfix;
}

void convert_to_postfix(string input_file, string output_file) {
    ifstream infile(input_file);
    ofstream outfile(output_file);
    if (!infile) {
        cerr << "Error: cannot open input file " << input_file << endl;
        return;
    }
    if (!outfile) {
        cerr << "Error: cannot open output file " << output_file << endl;
        return;
    }
    string infix;
    getline(infile, infix);
    string postfix = infix_to_postfix(infix);
    outfile << postfix << endl;
    infile.close();
    outfile.close();
}

int main() {
    string input_file = "input.txt";
    string output_file = "output.txt";
    convert_to_postfix(input_file, output_file);
    return 0;
}
