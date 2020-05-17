#include <iostream>

class Accumulator
{
    private:
        int m_value;
    public:
        Accumulator() { m_value = 0; }
        void add(int value) { m_value += value; }

        // Make the reset() function a _friend_ of this class
        friend void reset(Accumulator &acuumulator);
        int getValue() { return m_value; }
};

/* reset() is now a friend of the Accumulator class */
void reset(Accumulator &accumulator)
{
    /* And can access the private data of Accumulator objects */
    accumulator.m_value = 0;
}

/* Another Example */
class Value
{
    private:
        int m_value;
    public:
        Value(int value) { m_value = value; }
        friend bool isEqual(const Value &value1, const Value &value2);
};

bool isEqual(const Value &value1, const Value &value2)
{
    return (value1.m_value == value2.m_value);
}

// Note you can use multiple friends
class Humidity;
class Temperature
{
    private:
        int m_temp;
    public:
        Temperature(int temp=0) { m_temp = temp; }
        friend void printWeather(const Temperature &temperature, const Humidity &humidity);
};

class Humidity
{
    private:
        int m_humidity;
    public:
        Humidity(int humidity=0) { m_humidity = humidity; }
        friend void printWeather(const Temperature &temperature, const Humidity &humidity);
};

void printWeather(const Temperature &temperature, const Humidity &humidity)
{
    std::cout << "The temperature is " << temperature.m_temp << " and the humidity is " << humidity.m_humidity << '\n';
}

// Friend Classes
class Storage
{
    private:
        int m_nValue;
        double m_dValue;
    public:
        Storage(int nValue, double dValue)
        {
            m_nValue = nValue;
            m_dValue = dValue;
        }
        // Make the Display class a friend of Storage
        friend class Display;
};

class Display
{
    private:
        bool m_displayIntFirst;
    public:
        Display (bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }
        void displayItem(const Storage &storage)
        {
            if (m_displayIntFirst)
                std::cout << storage.m_nValue << " " << storage.m_dValue << '\n';
            else
                std::cout << storage.m_dValue << " " << storage.m_nValue << '\n';
        }
};

int main()
{
    Accumulator acc;
    acc.add(5); // add 5 to the accumulator
    std::cout << acc.getValue() << '\n';
    reset(acc); // reset the accumulator to 0
    std::cout << acc.getValue() << '\n';

    Humidity hum(10);
    Temperature temp(12);
    printWeather(temp, hum);

    Storage storage(5, 6.7);
    Display display(false);

    display.displayItem(storage);
    return 0;
}
