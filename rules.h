#ifndef RULES_H
#define RULES_H


class rules
{
public:
    rules();
    ~rules();

    void breed(int x, int y, int neighbours);
    void kill(int x, int y, int neighbours);
    int test_neighbour(int x, int y);

    void set_alive(int alive_values[]);
    void set_breed(int breed_values[]);
    int get_alive();
    int get_breed();

private:
    int alive_values[]; //finne riktig klasse
    int breed_values[]; //finne riktig klasse
};

#endif // RULES_H
