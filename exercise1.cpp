#include <iostream> 
#include <string> 
using namespace std; 
 
class Sensor { 
protected: 
    double value; 
 
public: 
    // Default constructor: 
    // - Print: "Sensor default constructor" 
    // - Set value = 0 
    Sensor(); 
 
    // Parameter constructor: 
    // - Print: "Sensor parameter constructor" 
    // - Set value = v (if v < 0, set value = 0) 
    Sensor(double v); 
 
    // Sets value (if v < 0, set to 0) 
    void setValue(double v); 
 
    // Returns value 
    double getValue() const; 
}; 
 
 
 
 
class Logger { 
protected: 
    string name; 
 
public: 
    // Default constructor: 
    // - Print: "Logger default constructor" 
    // - Set name = "Unnamed" 
    Logger(); 
 
    // Parameter constructor: 
    // - Print: "Logger parameter constructor" 
    // - Set name = n 
    Logger(const string &n); 
 
    // Print: "Logging from [name]" 
    void log() const; 
}; 
 
// SmartSensor inherits from BOTH Sensor and Logger 
class SmartSensor : public Sensor, public Logger { 
public: 
    // Default constructor: 
    // - Call Sensor default constructor 
    // - Call Logger default constructor 
    // - Print: "SmartSensor default constructor" 
    SmartSensor(); 
 
    // Parameter constructor: 
    // - Call Sensor(v) 
    // - Call Logger(n) 
    // - Print: "SmartSensor parameter constructor" 
    SmartSensor(double v, const string &n); 
 
    // Print a status line: 
    // "SmartSensor [name] has value = [value]" 
    void printStatus(); 
 
    // Destructor: 
    // - Print: "SmartSensor destructor" 
    ~SmartSensor(); 
}; 
 
 
// === DEFINE ALL MEMBER FUNCTIONS BELOW (outside class) === 
// TODO: Implement all Sensor member functions 
Sensor::Sensor(){
    cout << "Sensor default constructor" << endl;
    value = 0;
}

Sensor::Sensor(double v){
    cout << "Sensor parameter constructor" << endl;
    if(v < 0){
        value = 0;
    } else {
        value = v;
    }
}
 
void Sensor::setValue(double v){
    if(v < 0){
        value = 0;
    } else {
        value = v;
    }
}
  
double Sensor::getValue() const{
    return value;
}


// TODO: Implement all Logger member functions 
Logger::Logger(){
    cout << "Logger default constructor" << endl;
    name = "Unnamed";
}

Logger::Logger(const string &n){
    cout << "Logger parameter constructor" << endl;
    name = n;
}

void Logger::log() const{
    cout << "Logging from " << name << endl;
}


// TODO: Implement all SmartSensor member functions 
SmartSensor::SmartSensor(): Sensor(), Logger(){
    cout << "SmartSensor default constructor" << endl;
}

SmartSensor::SmartSensor(double v, const string &n): Sensor(v), Logger(n){
    cout << "SmartSensor parameter constructor" << endl;
}

void SmartSensor::printStatus() {
    cout << "SmartSensor " << name << " has value = " << value << endl;
}

SmartSensor::~SmartSensor() {
    cout << "SmartSensor destructor" << endl;
}
 
int main() { 
    cout << "Creating s1" << endl; 
    SmartSensor s1;      
 
    cout << "Creating s2" << endl; 
    SmartSensor s2(42.5, "RoomSensor"); 
 
    cout << "Status of s2:" << endl; 
    s2.printStatus(); 
 
    cout << "Changing value of s2:" << endl; 
    s2.setValue(100.0); 
    s2.printStatus(); 
 
    cout << "End of main" << endl; 
    return 0; 
} 
 