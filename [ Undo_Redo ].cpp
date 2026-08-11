#include <iostream>
#include "clsMyString.h"

using namespace std;

int main()
{
    cout << "\n\n\t\t\t\t\t\t Undo/Redo Project\n\n";

    clsMyString S1;

    cout << "\nS1 = " << S1.Value << "\n";

    S1.Value = "Ahmed";

    cout << "S1 = " << S1.Value << "\n";

    S1.Value = "Ahmed2";

    cout << "S1 = " << S1.Value << "\n";

    S1.Value = "Ahmed3";

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

    system("pause>0");
    return 0;
}