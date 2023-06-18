#ifndef CPPCLASSUNIT_H
#define CPPCLASSUNIT_H
#include "ClassUnit.h"

class cppClassUnit : public ClassUnit
{
public:
    static const std::vector <std::string> ACCESS_MODIFIERS;
    cppClassUnit(const std::string& name): ClassUnit(name)
    {}

    std::string compile(unsigned int level = 0) const override
    {
        std::string result = generateShift(level) + "class " + m_name + " {\n";
        for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
        {
            if (m_fields[i].empty())
                continue;

            result += ACCESS_MODIFIERS[i] + ":\n";

    }
}

#endif // CPPCLASSUNIT_H
