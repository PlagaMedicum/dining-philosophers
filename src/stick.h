#include <mutex>

class Stick
{
public:
    Stick();
    ~Stick();
    void release();
    void wait();
private:
    std::mutex mux;
};


