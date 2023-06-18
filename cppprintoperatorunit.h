#ifndef CPPPRINTOPERATORUNIT_H
#define CPPPRINTOPERATORUNIT_H
#include "PrintOperatorUnit.h"
#include "Unit.h"

class cppPrintOperatorUnit : public PrintOperatorUnit
{
public:
    cppPrintOperatorUnit(const std::string& text) : PrintOperatorUnit(text)
    {}

    std::string compile(unsigned int level = 0) const override
    {
        return generateShift( level ) + "printf( \"" + _text + "\" );\n";
    }

};

#endif // CPPPRINTOPERATORUNIT_H
