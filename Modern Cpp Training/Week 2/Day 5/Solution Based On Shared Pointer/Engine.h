#ifndef ENGINE_H
#define ENGINE_H
#include <ostream>

class Engine
{
private:
    int m_engine_horse_power;
    float m_engine_torque;
public:
    Engine() = delete;
    ~Engine() = default;
    Engine(const Engine&) = delete;
    Engine(Engine&&) = default;
    Engine& operator=(const Engine&) = delete;
    Engine& operator=(Engine&&) = delete;

    int engineHorsePower() const { return m_engine_horse_power; }

    float engineTorque() const { return m_engine_torque; }

    Engine(int engine_horse_power , float engine_torque);

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);

};

#endif // ENGINE_H
