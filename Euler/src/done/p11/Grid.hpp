#ifndef GRID_HPP
#define GRID_HPP

#include <memory>
#include <vector>
#include <iostream>
#include <iomanip>

template <typename T>
class Grid 
{
    public:
        Grid(int width, int height);

        int linearIndexOf(int x, int y);

        T get(int x, int y);
        void set(int x, int y, T value);
        void add(T value);
        bool hasRoom();

        void print(char fillchar='0', int width=2);

        bool pointInBounds(int x, int y);

        void forEach(std::function<void(int x, int y) > action);

        int width();
        int height();
    private:
        int m_width;
        int m_height;
        std::vector<T> m_content;
};

    template <typename T>
int Grid<T>::width()
{
    return m_width;
}
    template <typename T>
int Grid<T>::height()
{
    return m_height;
}
    template <typename T>
Grid<T>::Grid(int width, int height)
    : m_width(width), m_height(height)
{
    m_content.reserve(width * height);
}

template <typename T>
int Grid<T>::linearIndexOf(int x, int y){
    return x + (m_width * y);
}

template <typename T>
T Grid<T>::get(int x, int y){
    return m_content[linearIndexOf(x,y) ];
}

template <typename T>
void Grid<T>::set(int x, int y, T value){
    m_content[linearIndexOf(x,y)] = value;
}

template <typename T>
void Grid<T>::add(T value){
    m_content.push_back(value);
}

template <typename T>
bool Grid<T>::hasRoom(){
    return m_content.size() < m_content.capacity();
}
template <typename T>
void Grid<T>::print(char fillchar, int width){
    for (int i = 0; i < m_content.size(); ++i){
        std::cout << std::setfill(fillchar) << std::setw(width) << m_content[i] << " ";
        if ((i+1) % m_width == 0)
            std::cout << std::endl;
    } 
}

template <typename T>
bool Grid<T>::pointInBounds(int x, int y){
    return ((-1 < x && x < m_width) && (-1 < y && y < m_height));
}

    template <typename T>
void Grid<T>::forEach(std::function<void(int x, int y) > action)
{
    for (int y = 0; y < m_height; ++y){
        for (int x = 0; x < m_width; ++x){
            action(x, y);
        }
    }
}
#endif /* GRID_HPP */
