#include <string>
#include <functional>
#include <vector>

class EventEmitter
{
public:
std::function<void ( void* )> handler[36];
std::vector<std::string> event;
public:
    void on(std::string event, std::function<void ( void* )> callback);
private:
    void addListener(std::string event, std::function<void (void* )> callback);
protected:
    void emit(std::string event, void* pointer);
};