// #include <iostream>
// using namespace std;

// class Stack
// {
// private:
//     int arr[8];
//     int top;

// public:
//     Stack()
//     {
//         top = -1;
//     }

//     void push(int value)
//     {
//         if (top == 7)
//         {
//             cout << "Stack is full" << endl;
//             return;
//         }

//         arr[++top] = value;
//         cout << "Current top: " << arr[top] << endl;
//     }

//     void undo()
//     {
//         if (top == -1)
//         {
//             cout << "Undo requested, but stack is empty" << endl;
//             return;
//         }

//         top--;

//         if (top == -1)
//             cout << "Current top: Stack is empty" << endl;
//         else
//             cout << "Current top: " << arr[top] << endl;
//     }

//     void display()
//     {
//         cout << "Operations from top to bottom: ";

//         for (int i = top; i >= 0; i--)
//         {
//             cout << arr[i] << " ";
//         }

//         cout << endl;
//     }
// };

// int main()
// {
//     Stack s;

//     s.push(12);
//     s.push(25);
//     s.push(17);
//     s.push(31);
//     s.push(44);
//     s.push(19);

//     s.undo();
//     s.undo();
//     s.undo();

//     s.push(52);

//     s.undo();
//     s.undo();

//     s.display();

//     return 0;
// }



// #include <iostream>
// #include <string>
// using namespace std;

// class Stack
// {
// private:
//     string arr[100];
//     int top;

// public:
//     Stack()
//     {
//         top = -1;
//     }

//     void push(string value)
//     {
//         arr[++top] = value;
//     }

//     string pop()
//     {
//         if (top == -1)
//             return "";

//         return arr[top--];
//     }

//     bool empty()
//     {
//         return top == -1;
//     }

//     void clear()
//     {
//         top = -1;
//     }
// };

// class TextEditor
// {
// private:
//     string document;
//     Stack undoStack;
//     Stack redoStack;

// public:
//     void type(string word)
//     {
//         document += word;

//         undoStack.push(word);
//         redoStack.clear();

//         print();
//     }

//     void undo()
//     {
//         if (undoStack.empty())
//         {
//             cout << "Nothing to undo" << endl;
//             print();
//             return;
//         }

//         string word = undoStack.pop();

//         document.erase(document.length() - word.length());

//         redoStack.push(word);

//         print();
//     }

//     void redo()
//     {
//         if (redoStack.empty())
//         {
//             cout << "Nothing to redo" << endl;
//             print();
//             return;
//         }

//         string word = redoStack.pop();

//         document += word;

//         undoStack.push(word);

//         print();
//     }

//     void print()
//     {
//         cout << "Document: " << document << endl;
//     }
// };

// int main()
// {
//     TextEditor editor;

//     editor.type("Hello ");
//     editor.type("World");

//     editor.undo();

//     editor.redo();

//     editor.undo();

//     editor.type("There");

//     editor.redo();

//     return 0;
// }



// #include <iostream>
// #include <string>
// #include <cmath>
// using namespace std;

// class Stack
// {
// private:
//     string arr[100];
//     int top;

// public:
//     Stack()
//     {
//         top = -1;
//     }

//     void push(string value)
//     {
//         arr[++top] = value;
//     }

//     string pop()
//     {
//         if (top == -1)
//             return "";

//         return arr[top--];
//     }

//     string peek()
//     {
//         if (top == -1)
//             return "";

//         return arr[top];
//     }

//     bool empty()
//     {
//         return top == -1;
//     }
// };

// bool isOperator(char c)
// {
//     return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
// }

// int precedence(char c)
// {
//     if (c == '+' || c == '-')
//         return 1;

//     if (c == '*' || c == '/')
//         return 2;

//     if (c == '^')
//         return 3;

//     return 0;
// }

// bool isRightAssociative(char c)
// {
//     return c == '^';
// }

// bool isNumber(string s)
// {
//     if (s.length() == 0)
//         return false;

//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i] < '0' || s[i] > '9')
//             return false;
//     }

//     return true;
// }

// bool infixToPostfix(string expression, string postfix[], int &count)
// {
//     Stack operators;
//     count = 0;

//     bool expectingOperand = true;

//     for (int i = 0; i < expression.length();)
//     {
//         if (expression[i] == ' ')
//         {
//             i++;
//             continue;
//         }

//         if (expression[i] >= '0' && expression[i] <= '9')
//         {
//             if (!expectingOperand)
//             {
//                 cout << "Error: Two operands without an operator" << endl;
//                 return false;
//             }

//             string number = "";

//             while (i < expression.length() &&
//                    expression[i] >= '0' &&
//                    expression[i] <= '9')
//             {
//                 number += expression[i];
//                 i++;
//             }

//             postfix[count++] = number;
//             expectingOperand = false;
//         }
//         else if (expression[i] == '(')
//         {
//             if (!expectingOperand)
//             {
//                 cout << "Error: Missing operator before '('" << endl;
//                 return false;
//             }

//             operators.push("(");
//             i++;
//         }
//         else if (expression[i] == ')')
//         {
//             if (expectingOperand)
//             {
//                 cout << "Error: Unexpected ')'" << endl;
//                 return false;
//             }

//             bool foundOpening = false;

//             while (!operators.empty())
//             {
//                 string op = operators.pop();

//                 if (op == "(")
//                 {
//                     foundOpening = true;
//                     break;
//                 }

//                 postfix[count++] = op;
//             }

//             if (!foundOpening)
//             {
//                 cout << "Error: Mismatched parentheses" << endl;
//                 return false;
//             }

//             i++;
//         }
//         else if (isOperator(expression[i]))
//         {
//             char current = expression[i];

//             if (expectingOperand)
//             {
//                 cout << "Error: Operator appears where an operand is expected" << endl;
//                 return false;
//             }

//             while (!operators.empty() &&
//                    operators.peek() != "(" &&
//                    (
//                        precedence(operators.peek()[0]) > precedence(current) ||
//                        (precedence(operators.peek()[0]) == precedence(current) &&
//                         !isRightAssociative(current))
//                    ))
//             {
//                 postfix[count++] = operators.pop();
//             }

//             string op = "";
//             op += current;
//             operators.push(op);

//             expectingOperand = true;
//             i++;
//         }
//         else
//         {
//             cout << "Error: Invalid character in expression" << endl;
//             return false;
//         }
//     }

//     if (expectingOperand)
//     {
//         cout << "Error: Expression ends with an operator" << endl;
//         return false;
//     }

//     while (!operators.empty())
//     {
//         string op = operators.pop();

//         if (op == "(")
//         {
//             cout << "Error: Mismatched parentheses" << endl;
//             return false;
//         }

//         postfix[count++] = op;
//     }

//     return true;
// }

// bool evaluatePostfix(string postfix[], int count, double &answer)
// {
//     double values[100];
//     int top = -1;

//     for (int i = 0; i < count; i++)
//     {
//         if (isNumber(postfix[i]))
//         {
//             double number = 0;

//             for (int j = 0; j < postfix[i].length(); j++)
//             {
//                 number = number * 10 + (postfix[i][j] - '0');
//             }

//             values[++top] = number;
//         }
//         else
//         {
//             if (top < 1)
//             {
//                 cout << "Error: Invalid expression" << endl;
//                 return false;
//             }

//             double right = values[top--];
//             double left = values[top--];
//             double result;

//             char op = postfix[i][0];

//             if (op == '+')
//                 result = left + right;
//             else if (op == '-')
//                 result = left - right;
//             else if (op == '*')
//                 result = left * right;
//             else if (op == '/')
//             {
//                 if (right == 0)
//                 {
//                     cout << "Error: Division by zero" << endl;
//                     return false;
//                 }

//                 result = left / right;
//             }
//             else if (op == '^')
//                 result = pow(left, right);
//             else
//             {
//                 cout << "Error: Invalid operator" << endl;
//                 return false;
//             }

//             values[++top] = result;
//         }
//     }

//     if (top != 0)
//     {
//         cout << "Error: Invalid expression" << endl;
//         return false;
//     }

//     answer = values[top];

//     return true;
// }

// void calculate(string expression)
// {
//     string postfix[100];
//     int count;
//     double answer;

//     cout << "Expression: " << expression << endl;

//     if (infixToPostfix(expression, postfix, count))
//     {
//         cout << "Postfix: ";

//         for (int i = 0; i < count; i++)
//             cout << postfix[i] << " ";

//         cout << endl;

//         if (evaluatePostfix(postfix, count, answer))
//             cout << "Answer: " << answer << endl;
//     }

//     cout << endl;
// }

// int main()
// {
//     calculate("12 + 3 * (4 - 1)");
//     calculate("(2 + 3) ^ 2");
//     calculate("100 / 5 / 2");
//     calculate("5 + )");

//     return 0;
// }




// #include <iostream>
// #include <queue>
// #include <stack>
// using namespace std;

// void reverseFirstK(queue<int> &q, int k)
// {
//     if (k <= 0 || k > q.size())
//         return;

//     stack<int> s;

//     for (int i = 0; i < k; i++)
//     {
//         s.push(q.front());
//         q.pop();
//     }

//     while (!s.empty())
//     {
//         q.push(s.top());
//         s.pop();
//     }

//     int remaining = q.size() - k;

//     for (int i = 0; i < remaining; i++)
//     {
//         q.push(q.front());
//         q.pop();
//     }
// }

// void display(queue<int> q)
// {
//     while (!q.empty())
//     {
//         cout << q.front() << " ";
//         q.pop();
//     }

//     cout << endl;
// }

// int main()
// {
//     queue<int> q;

//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);
//     q.push(5);
//     q.push(6);
//     q.push(7);

//     cout << "Before: ";
//     display(q);

//     reverseFirstK(q, 3);

//     cout << "After: ";
//     display(q);

//     return 0;
// }



#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int arr[6];
    int front;
    int rear;
    int count;

public:
    CircularQueue()
    {
        front = 0;
        rear = 0;
        count = 0;
    }

    bool isFull()
    {
        return count == 6;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }

        arr[rear] = value;
        rear = (rear + 1) % 6;
        count++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int value = arr[front];

        front = (front + 1) % 6;
        count--;

        return value;
    }

    void display()
    {
        for (int i = 0; i < count; i++)
        {
            cout << arr[(front + i) % 6] << " ";
        }

        cout << endl;
    }

    int getFront()
    {
        return front;
    }
};

int main()
{
    CircularQueue q;

    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);
    q.enqueue(104);
    q.enqueue(105);
    q.enqueue(106);

    cout << "Boarded: " << q.dequeue() << endl;
    cout << "Boarded: " << q.dequeue() << endl;
    cout << "Boarded: " << q.dequeue() << endl;

    q.enqueue(107);
    q.enqueue(108);
    q.enqueue(109);

    cout << "Boarded: " << q.dequeue() << endl;
    cout << "Boarded: " << q.dequeue() << endl;

    q.enqueue(110);

    cout << "Boarded: " << q.dequeue() << endl;

    q.enqueue(111);
    q.enqueue(112);

    cout << "Final passengers in boarding order: ";
    q.display();

    cout << "Final front index: " << q.getFront() << endl;

    return 0;
}