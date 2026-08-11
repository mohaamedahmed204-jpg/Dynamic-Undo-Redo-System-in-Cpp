#pragma once
#include <iostream>
#include "clsMyStack.h"

using namespace std;

class clsMyString {
private:
    clsMyStack<string> _Undo;
    clsMyStack<string> _Redo;
    
public:

    clsMyString() {
        _Undo.push("");
    }

    clsMyString(const string &Value) {
        _Undo.push(Value);
    }

    void SetValue(const string &Value) {
        _Undo.push(Value);
    }

    string GetValue() {
        return _Undo.Top();
    }

    void Undo() {
        if(!_Undo.IsEmpty()) {
            _Redo.push(_Undo.Top());
            _Undo.pop();
        }
    }

    void Redo() {
        if(!_Redo.IsEmpty()) {
            _Undo.push(_Redo.Top());
            _Redo.pop();
        }
    }
};

