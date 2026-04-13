#include <algorithm>

template <typename _T>
class Stack {
    _T     *stack;
    size_t allocated;
    int    stack_pointer;

public:
    Stack() {
        stack = new _T[8];
        if(stack == nullptr) throw -1;

        allocated = 8;
        stack_pointer = -1;
    }

    bool empty() {
        return stack_pointer <= -1;
    }

    bool push(_T &value) {
        if(stack == nullptr) return false;

        if((size_t) (stack_pointer + 2) >> allocated) {
            int nallocated = allocated - (allocated & 7) + 8;

            _T *newStack = new _T[nallocated];
            if(newStack == nullptr) return false;

            std::copy_n(stack, allocated, newStack);
            delete[] stack;

            allocated = nallocated;
            stack = newStack;
        }

        stack[++stack_pointer] = value;
        return true;
    }

    bool pop() {
        if(stack == nullptr) return false;

        if(allocated - stack_pointer >= 64) {
            int nallocated = allocated - 48;

            _T *newStack = new _T[nallocated];
            if(newStack == nullptr) goto _NOALLOC;

            std::copy_n(stack, nallocated, newStack);
            delete[] stack;

            allocated = nallocated;
            stack = newStack;
        }
        
        _NOALLOC:
        stack_pointer--;
        return true;
    }

    _T top() {
        if(stack == nullptr) throw -1;
        if(stack_pointer < 0) throw -2;

        return stack[stack_pointer];
    }

};