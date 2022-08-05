#include <iostream>
#include <string>

template <typename T>
class Pair1 {
private:
    T m_1{ };
    T m_2{ };
public:
    Pair1(T one, T two) : m_1{ one }, m_2{ two } {};

    T first() const { return m_1; }
    T second() const { return m_2; }
};

template <typename T1, typename T2>
class Pair2 {
private:
    T1 m_1{ };
    T2 m_2{ };
public:
    Pair2(T1 one, T2 two) : m_1{ one }, m_2{ two } {};
    T1 first() const { return m_1; }
    T2 second() const { return m_2; }
};


template <typename T1, typename T2>
class Pair3 {
private:
    T1 m_1{ };
    T2 m_2{ };
public:
    Pair3(const T1& one, const T2& two) : m_1{ one }, m_2{ two } {};
    const T1& first() const { return m_1; }
    const T2& second() const { return m_2; }
};

template<typename T>
class StringValuePair: public Pair3<std::string, T> {
public:
    StringValuePair(const std::string& k, const T& v) : Pair3<std::string, T>(k, v) {};
};


int main()
{
	///////////////////////////////////////////////////////////////////////////////
    Pair1<int> p1 { 5, 8 };
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
	const Pair1<double> p2 { 2.3, 4.5 };
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
	///////////////////////////////////////////////////////////////////////////////
    Pair2<int, double> pair2a { 5, 6.7 };
	std::cout << "Pair: " << pair2a.first() << ' ' << pair2a.second() << '\n';
	const Pair2<double, int> pair2b { 2.3, 4 };
	std::cout << "Pair: " << pair2b.first() << ' ' << pair2b.second() << '\n';
	///////////////////////////////////////////////////////////////////////////////
    StringValuePair<int> svp { "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}

