#ifndef JAVACLASSUNIT_H
#define JAVACLASSUNIT_H
#include "ClassUnit.h"

class javaClassUnit : public ClassUnit
{
public:
    static const std::vector <std::string> ACCESS_MODIFIERS;
    javaClassUnit(const std::string& name): ClassUnit(name)
    {}

    std::string compile(unsigned int level = 0) const override
    {
        std::string result = generateShift(level) + "class " + m_name + " {\n";
        for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
        {
            if (m_fields[i].empty())
                continue;

            for (const auto& it : m_fields[i])
                result += generateShift(level+1) + ACCESS_MODIFIERS[i] + " " + it -> compile(level+1);

            result += '\n';
        }
        result += generateShift(level) + "};\n";
        return result;
    }
};

#endif // JAVACLASSUNIT_H
