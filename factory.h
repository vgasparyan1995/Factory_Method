#pragma once

#include <iostream>

enum class instrument
{
    PIANO,
    ORGAN
};

class musician
{
public:
    static musician* create_musician(const instrument i);

    virtual ~musician() {}
    virtual void play() const = 0;
};

class pianist : public musician
{
public:
    void play() const override
    {
        std::cout << "piano" << std::endl;
    }

    pianist() {}
};

class organist : public musician
{
public:
    void play() const override
    {
        std::cout << "organ" << std::endl;
    }

    organist() {}
};

musician* musician::create_musician(const instrument i)
{
    switch (i) {
        case instrument::PIANO:
            return new pianist();
        case instrument::ORGAN:
            return new organist();
        default:
            throw "WTF?";
    }
    return nullptr;
}
