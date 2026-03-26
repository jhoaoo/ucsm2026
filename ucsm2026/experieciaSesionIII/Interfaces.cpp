#include <string>

#ifndef INTERFACES_CPP
#define INTERFACES_CPP

class ITask {
public:
    virtual ~ITask() = default;
    virtual void execute() = 0;
    virtual std::string getDetails() const = 0;
};

class INotifiable {
public:
    virtual ~INotifiable() = default;
    virtual void sendAlert() = 0;
};

#endif