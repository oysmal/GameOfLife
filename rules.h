#ifndef RULES_H
#define RULES_H
#include <vector>

class rules
{
public:
    rules();
    ~rules();

    void breed(int x, int y, int neighbours);
    void kill(int x, int y, int neighbours);
    int test_neighbour(int x, int y);

    std::vector<int> get_alive();
    std::vector<int> get_breed();

private:
    std::vector<int> alive_values;
    std::vector<int> breed_values;
};

#endif // RULES_H
