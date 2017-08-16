/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
*/

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. O(n)*/
    void push(int x) {
        queue<int> tmp;
        tmp.push(x);

        while (!que_.empty()) {
            tmp.push(que_.front());
            que_.pop();
        }

        swap(que_, tmp);
    }

    /** Removes the element on top of the stack and returns that element. O(1)*/
    int pop() {
        auto val = que_.front();
        que_.pop();
        return val;
    }

    /** Get the top element. O(1)*/
    int top() {
        return que_.front();
    }

    /** Returns whether the stack is empty. O(1)*/
    bool empty() {
        return que_.empty();
    }
private:
    queue<int> que_;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
