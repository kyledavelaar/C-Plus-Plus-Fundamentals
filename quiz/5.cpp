#include <iostream>
#include <cstdint>


class RGBA {
    using uint = std::uint8_t;
    private:
        uint m_red{ };
        uint m_green{ };
        uint m_blue{ };
        uint m_alpha{ };

    public:
        RGBA(uint r=0, uint g=0, uint b=0, uint a=255) : m_red{r}, m_green{g}, m_blue{b}, m_alpha{a}
        {

        }

        void print() {
            std::cout << "r=" << static_cast<int>(m_red) << " g=" << static_cast<int>(m_green) << " b=" << static_cast<int>(m_blue) << " a=" << static_cast<int>(m_alpha) << '\n';
        }
};

int main() {

    RGBA teal{0, 127, 127};
    teal.print();


    return 0;
}