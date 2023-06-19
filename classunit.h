#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include <string>
#include <vector>
#include <Unit.h>

class ClassUnit : public Unit
{    
private:
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;

public:
     enum AccessModifier
     {
         PUBLIC,
         PROTECTED,
         PRIVATE
     };
    static const std::vector< std::string > ACCESS_MODIFIERS;

public:
    explicit ClassUnit (const std::string& name): m_name(name)
    {
        m_fields.resize(ACCESS_MODIFIERS.size()); // размер вектора, равный кол-ву доступных модификаторов класса
    }

    void add (const std::shared_ptr<Unit>& unit, Flags flags) override
    {
        int accessModifier = PRIVATE;
        if(flags < ACCESS_MODIFIERS.size())
        {
            accessModifier = flags;
        }
        m_fields[accessModifier].push_back(unit);
    }

    std::string compile( unsigned int level = 0 ) const override
    {
        std::string result = generateShift(level) + "class " + m_name + " {\n";

        for(size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
        {
            if(m_fields[i].empty())
            {
                continue;
            }
            result += ACCESS_MODIFIERS[i] + ":\n";

            for(const auto& f : m_fields[i]) // перебор элементов вектора
                // и формир-е строки для каждого подэл-та класса
            {
                result += f->compile(level + 1);
            }
            result += "\n";
        }
        result += generateShift(level) + "};\n";
        return result;
     }
};

#endif // CLASSUNIT_H







