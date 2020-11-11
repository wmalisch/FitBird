#include <iostream>
#include <string>
#include <Python.h>

using namespace std;

int main(){

    // Start Interpreter
    cout << "Initializing python interpreter" << endl;
    Py_Initialize();

    cout << "Import sys" << endl;
    PyRun_SimpleString("import sys");

    cout << "run sense.py" << endl;
    PyRun_SimpleString("sys.path.append('./sense.py')");
    
    cout << "Program over" << endl;
    return 0;

}