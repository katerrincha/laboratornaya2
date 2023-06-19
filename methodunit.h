#ifndef METHODUNIT_H
#define METHODUNIT_H
#include <string>
#include <vector>
#include <Unit.h>
#include <ClassUnit.h>

class MethodUnit : public Unit
{
private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector <std::shared_ptr<Unit>> m_body;

public:
    enum Modifier
    {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };

public:
    MethodUnit(const std::string& name, const std::string& returnType, Flags flags) :
    m_name (name), m_returnType (returnType), m_flags (flags) { } // name - имя метода,
    // returnType - тип возвр. значения, flags - флаги для опр. модификаторов метода

    void add (const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0) override // добавление влож. элементов
    // unit - ук-ль на подэлемент
    {
        m_body.push_back (unit); // добавляем ук-ль unit в конец вектора m_body
    }

    std::string compile (unsigned int level = 0) const // формир-е строкового представления метода
    //с его подэлем-ми с учетом модификатора доступа и вложенности
    {
        std::string result = generateShift (level); // содержит сгенер. результат,
        // добавляем отступ, зависящий от влож-ти
        if (m_flags & STATIC)
        {
            result += "static ";
        }
        else if (m_flags & VIRTUAL)
        {
            result += "virtual ";
        }

        result += m_returnType + " "; // + тип возвр. значения
        result += m_name + "()";

        if (m_flags & CONST)
        {
            result += " const";
        }
        result += " {\n"; // начало тела метода

        for (const auto& b : m_body)
        {
            result += b->compile (level + 1); // уровень влож-ти level+1
        }

        result += generateShift (level) + "}\n";
        return result;
    }
};

#endif // METHODUNIT_H
