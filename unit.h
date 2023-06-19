#ifndef UNIT_H
#define UNIT_H
#include <iostream>
#include <memory>

class Unit
{
public:
    using Flags = unsigned int; // объявление псевдонима Flags для типа unsigned int
    virtual ~Unit() = default;
    virtual void add (const std::shared_ptr< Unit >& , Flags)  // добавление вложенных элементов
    {
        throw std::runtime_error("Not supported");
    }
    virtual std::string compile (unsigned int level = 0) const = 0;  // вирт. метод для формирования юнита в виде текста и возврата строки,
    // level - уровень вложенности элемента

protected:
    virtual std::string generateShift (unsigned int level) const // вспомог. метод для генерации пробелов в зав-ти от уровня вложенности
    // вернет строку с отступом
    {
        static const auto DEFAULT_SHIFT = " ";
        std::string result;
        for( unsigned int i = 0; i < level; ++i)
        {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
};

#endif // UNIT_H
