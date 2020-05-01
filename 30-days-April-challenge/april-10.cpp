class MinStack {
public:
    void push(int x) {
        int min = 0;
        if (m_stack.empty()) {
            min = x;
        } else {
            min = std::min(m_stack.top().second, x);
        }
        m_stack.push({x, min});
    }
    
    void pop() {
        m_stack.pop(); 
    }
    
    int top() {
        return m_stack.top().first;
    }
    
    int getMin() {
        return m_stack.top().second;
    }
    
private:
    std::stack<std::pair<int, int>> m_stack;
};

int main() {
    MinStack stack;
    stack.push(x);
    stack.pop();
    int param_3 = stack.top();
    int param_4 = stack.getMin();
}
