#include <bits/stdc++.h>         // Usado en muchos entornos de programación competitiva (no es estándar)
#include <cxxabi.h>             // Para la función __cxa_demangle (GNU)
#include <stdint.h>             // Para tipos fijos como int64_t, uint32_t, etc.

using namespace std;

// Función genérica que recibe una variable de cualquier tipo y retorna su nombre desmanglado.
template <typename T>
string getTypeName(const T& var) {
    int status;
    // typeid(var).name() devuelve el nombre "manglado"
    const char* mangledName = typeid(var).name();

    // Demangling del nombre para hacerlo legible
    char* demangledName = abi::__cxa_demangle(mangledName, nullptr, nullptr, &status);
    string typeName = (status == 0) ? demangledName : mangledName;

    // Liberar la memoria reservada por __cxa_demangle
    free(demangledName);

    return typeName;
}

signed main() {
    

    // Ejemplo de variables con diferentes tipos
    // ------------------------------------------------------
    bool         varBool      = true;
    char         varChar      = 'A';
    short        varShort     = 10;
    unsigned int varUnsigned  = 40000;
    int          varInt       = 123;
    long         varLong      = 123456;
    long long    varLongLong  = 123456789123LL;
    int64_t      varInt64_t   = -999999999999;
    float        varFloat     = 3.14f;
    double       varDouble    = 3.1415926535;
    long double  varLongDouble= 3.14159265358979323846L; // aprox pi

    // Imprimir valor y tipo de cada variable
    // ------------------------------------------------------
    cout << "varBool       = " << varBool       << " | tipo: " << getTypeName(varBool)       << endl;
    cout << "varChar       = " << varChar       << " | tipo: " << getTypeName(varChar)       << endl;
    cout << "varShort      = " << varShort      << " | tipo: " << getTypeName(varShort)      << endl;
    cout << "varUnsigned   = " << varUnsigned   << " | tipo: " << getTypeName(varUnsigned)   << endl;
    cout << "varInt        = " << varInt        << " | tipo: " << getTypeName(varInt)        << endl;
    cout << "varLong       = " << varLong       << " | tipo: " << getTypeName(varLong)       << endl;
    cout << "varLongLong   = " << varLongLong   << " | tipo: " << getTypeName(varLongLong)   << endl;
    cout << "varInt64_t    = " << varInt64_t    << " | tipo: " << getTypeName(varInt64_t)    << endl;
    cout << "varFloat      = " << varFloat      << " | tipo: " << getTypeName(varFloat)      << endl;
    cout << "varDouble     = " << varDouble     << " | tipo: " << getTypeName(varDouble)     << endl;
    cout << "varLongDouble = " << varLongDouble << " | tipo: " << getTypeName(varLongDouble) << endl;

    return 0;
}
