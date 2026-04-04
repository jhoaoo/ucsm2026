#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Empleado {
protected:
    string nombre;
    string dni;
    double salarioBase;
    bool activo;

public:
    Empleado(const string& nombre, const string& dni, double salarioBase)
        : nombre(nombre), dni(dni), salarioBase(salarioBase), activo(true) {
        if (nombre.empty()) {
            throw invalid_argument("El nombre del empleado no puede estar vacio.");
        }
        if (dni.empty()) {
            throw invalid_argument("El DNI no puede estar vacio.");
        }
        if (salarioBase < 0) {
            throw invalid_argument("El salario base no puede ser negativo.");
        }
    }

    virtual ~Empleado() {
        cout << "Destructor de Empleado ejecutado para: " << nombre << endl;
    }

    string getNombre() const {
        return nombre;
    }

    string getDni() const {
        return dni;
    }

    double getSalarioBase() const {
        return salarioBase;
    }

    bool estaActivo() const {
        return activo;
    }

    void setNombre(const string& nuevoNombre) {
        if (nuevoNombre.empty()) {
            throw invalid_argument("El nuevo nombre no puede estar vacio.");
        }
        nombre = nuevoNombre;
    }

    void setDni(const string& nuevoDni) {
        if (nuevoDni.empty()) {
            throw invalid_argument("El nuevo DNI no puede estar vacio.");
        }
        dni = nuevoDni;
    }

    void setSalarioBase(double nuevoSalario) {
        if (nuevoSalario < 0) {
            throw invalid_argument("El salario no puede ser negativo.");
        }
        salarioBase = nuevoSalario;
    }

    void desactivarEmpleado() {
        activo = false;
    }

    virtual double calcularPago() const {
        return salarioBase;
    }

    virtual void mostrarInfo() const {
        cout << "===== DATOS DEL EMPLEADO =====" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "DNI: " << dni << endl;
        cout << "Salario base: S/ " << salarioBase << endl;
        cout << "Activo: " << (activo ? "Si" : "No") << endl;
    }
};

class Desarrollador : public Empleado {
private:
    string lenguajePrincipal;
    int horasExtra;
    double pagoPorHoraExtra;

public:
    Desarrollador(const string& nombre, const string& dni, double salarioBase,
                  const string& lenguajePrincipal, int horasExtra, double pagoPorHoraExtra)
        : Empleado(nombre, dni, salarioBase),
          lenguajePrincipal(lenguajePrincipal),
          horasExtra(horasExtra),
          pagoPorHoraExtra(pagoPorHoraExtra) {
        if (lenguajePrincipal.empty()) {
            throw invalid_argument("El lenguaje principal no puede estar vacio.");
        }
        if (horasExtra < 0) {
            throw invalid_argument("Las horas extra no pueden ser negativas.");
        }
        if (pagoPorHoraExtra < 0) {
            throw invalid_argument("El pago por hora extra no puede ser negativo.");
        }
    }

    ~Desarrollador() override {
        cout << "Destructor de Desarrollador ejecutado para: " << nombre << endl;
    }

    string getLenguajePrincipal() const {
        return lenguajePrincipal;
    }

    int getHorasExtra() const {
        return horasExtra;
    }

    double getPagoPorHoraExtra() const {
        return pagoPorHoraExtra;
    }

    void setLenguajePrincipal(const string& nuevoLenguaje) {
        if (nuevoLenguaje.empty()) {
            throw invalid_argument("El lenguaje principal no puede estar vacio.");
        }
        lenguajePrincipal = nuevoLenguaje;
    }

    void setHorasExtra(int nuevasHoras) {
        if (nuevasHoras < 0) {
            throw invalid_argument("Las horas extra no pueden ser negativas.");
        }
        horasExtra = nuevasHoras;
    }

    void setPagoPorHoraExtra(double nuevoPago) {
        if (nuevoPago < 0) {
            throw invalid_argument("El pago por hora extra no puede ser negativo.");
        }
        pagoPorHoraExtra = nuevoPago;
    }

    void eliminarDatosPropios() {
        lenguajePrincipal = "";
        horasExtra = 0;
        pagoPorHoraExtra = 0;
    }

    double calcularPago() const override {
        return salarioBase + (horasExtra * pagoPorHoraExtra);
    }

    void programar() const {
        cout << nombre << " esta programando en " << lenguajePrincipal << "." << endl;
    }

    void mostrarInfo() const override {
        Empleado::mostrarInfo();
        cout << "Lenguaje principal: " << (lenguajePrincipal.empty() ? "No asignado" : lenguajePrincipal) << endl;
        cout << "Horas extra: " << horasExtra << endl;
        cout << "Pago por hora extra: S/ " << pagoPorHoraExtra << endl;
        cout << "Pago total: S/ " << calcularPago() << endl;
    }
};

int main() {
    try {
        Desarrollador dev("Bruno Rocchetti", "75896321", 2500.00, "C++", 10, 25.00);

        cout << "1. Accediendo a atributos y metodos heredados de Empleado" << endl;
        cout << "Nombre: " << dev.getNombre() << endl;
        cout << "DNI: " << dev.getDni() << endl;
        cout << "Salario base: S/ " << dev.getSalarioBase() << endl;
        cout << "Estado activo: " << (dev.estaActivo() ? "Si" : "No") << endl;
        cout << endl;

        cout << "2. Accediendo a atributos y metodos propios de Desarrollador" << endl;
        cout << "Lenguaje principal: " << dev.getLenguajePrincipal() << endl;
        cout << "Horas extra: " << dev.getHorasExtra() << endl;
        cout << "Pago por hora extra: S/ " << dev.getPagoPorHoraExtra() << endl;
        dev.programar();
        cout << endl;

        cout << "3. Mostrando informacion completa" << endl;
        dev.mostrarInfo();
        cout << endl;

        cout << "4. Modificando atributos heredados y propios" << endl;
        dev.setNombre("Bruno Valentino");
        dev.setSalarioBase(2800.00);
        dev.setLenguajePrincipal("Python");
        dev.setHorasExtra(12);
        dev.setPagoPorHoraExtra(30.00);
        dev.mostrarInfo();
        cout << endl;

        cout << "5. Eliminando logica y controladamente los atributos propios" << endl;
        dev.eliminarDatosPropios();
        dev.mostrarInfo();
        cout << endl;

        cout << "6. Desactivando el empleado" << endl;
        dev.desactivarEmpleado();
        dev.mostrarInfo();
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}