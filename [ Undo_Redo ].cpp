#include <iostream>
#include "clsMyStringUndoRedo.h"

using namespace std;

int main() {
    
    clsMyString S1;

    cout << "\nS1 = " << S1.Value << "\n";

    S1.Value = "Gwiada";

    cout << "S1 = " << S1.Value << "\n";

    S1.Value = "Gwiada2";

    cout << "S1 = " << S1.Value << "\n";

    S1.Value = "Gwiada3";

    cout << "S1 = " << S1.Value << "\n";

    cout << "\n\nUndo :";
    cout << "\n________\n";

    S1.Undo();

    cout << "\nS1 after Undo = " << S1.Value << "\n";

    S1.Undo();

    cout << "S1 after Undo = " << S1.Value << "\n";

    S1.Undo();

    cout << "S1 after Undo = " << S1.Value << "\n";

    cout << "\n\nRedo :";
    cout << "\n________\n";

    S1.Redo();

    cout << "\nS1 after Redo = " << S1.Value << "\n";

    S1.Redo();

    cout << "S1 after Redo = " << S1.Value << "\n";

    S1.Redo();

    cout << "S1 after Redo = " << S1.Value << "\n";

    return 0;
}
