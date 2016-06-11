#include "factory.h"

#include <vector>

int main()
{
    std::vector<musician*> orchestra;
    orchestra.push_back(musician::create_musician(instrument::PIANO));
    orchestra.push_back(musician::create_musician(instrument::PIANO));
    orchestra.push_back(musician::create_musician(instrument::ORGAN));

    for (const auto m : orchestra) {
        m->play();
    }

    for (auto m : orchestra) {
        delete m;
        m = nullptr;
    }
}
