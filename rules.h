#ifndef RULES_H
#define RULES_H
#include <vector>

class Rules
{
public:
    Rules();
    ~Rules();

    void breed(int x, int y, int neighbours);
    void kill(int x, int y, int neighbours);
    int test_neighbour(int x, int y);

    std::vector<int> get_alive();
    std::vector<int> get_breed();
    void set_alive(std::vector<int> values);
    void set_breed(std::vector<int> values);

private:
    std::vector<int> alive_values;
    std::vector<int> breed_values;
};

#endif // RULES_H
