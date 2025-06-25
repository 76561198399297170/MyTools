/// @file box.cpp
/// @brief 矩形框类实现
/// @date 2025-06-23

#include "rectangle.h"

// @details 有参构造方法通过左上坐标和宽高构造
Rectangle::Rectangle(const Vector2& position, const Vector2& size)
	: m_position(position), m_size(size)
{

}

// @details 有参构造方法通过坐标和宽高创建矩形
Rectangle::Rectangle(float x, float y, float width, float height)
    : m_position(x, y), m_size(width, height)
{

}

Rectangle::Rectangle(const Vector2& pos, float width, float height)
    : m_position(pos), m_size(width, height)
{

}

// @details 拷贝构造函数
Rectangle::Rectangle(const Rectangle& other)
    : m_position(other.m_position), m_size(other.m_size)
{

}

// @details 移动构造函数
Rectangle::Rectangle(Rectangle&& other) noexcept
    : m_position(std::move(other.m_position)), m_size(std::move(other.m_size))
{

}

// @details 赋值重载
Rectangle& Rectangle::operator=(const Rectangle& other)
{
    if (this != &other)
    {
        this->m_position = other.m_position, this->m_size = other.m_size;
    }
    return *this;
}

// @details 移动赋值重载
Rectangle& Rectangle::operator=(Rectangle&& other) noexcept
{
    if (this != &other)
    {
        this->m_position = std::move(other.m_position), this->m_size = std::move(other.m_size);
    }
    return *this;
}

// @details 等于重载，比较坐标与大小是否一致
bool Rectangle::operator==(const Rectangle& other) const
{
    return this->m_position == other.m_position && this->m_size == other.m_size;
}

/// @details 不等于重载
bool Rectangle::operator!=(const Rectangle& other) const
{
    return !(*this == other);
}

/// @details 设置矩形正中心坐标，矩形大小不变
void Rectangle::SetCenter(const Vector2& center)
{
    this->m_position.m_x = center.m_x - this->m_size.m_x * 0.5f;
    this->m_position.m_y = center.m_y - this->m_size.m_y * 0.5f;
}

/// @details 获取矩形正中心坐标
Vector2 Rectangle::GetCenter() const
{
    return Vector2(this->m_position.m_x + this->m_size.m_x * 0.5f, this->m_position.m_y + this->m_size.m_y * 0.5f);
}

/// @details 获取矩形右下角坐标
Vector2 Rectangle::GetBottomRight() const
{
    return Vector2(this->m_position.m_x + this->m_size.m_x, this->m_position.m_y + this->m_size.m_y);
}

/// @details 获取矩形面积
float Rectangle::GetArea() const
{
    return this->m_size.m_x * this->m_size.m_y;
}

/// @details 获取矩形周长
float Rectangle::GetPerimeter() const
{
    return 2.0f * (this->m_size.m_x + this->m_size.m_y);
}

/// @details 判断点是否与矩形发生接触或碰撞
bool Rectangle::Collision(const Vector2& point) const
{
    return this->m_position.m_x <= point.m_x && this->m_position.m_x + this->m_size.m_x >= point.m_x
        && this->m_position.m_y <= point.m_y && this->m_position.m_y + this->m_size.m_y >= point.m_x;
}

/// @details 判断矩形是否与矩形发生接触或碰撞
bool Rectangle::Collision(const Rectangle& other) const
{
    return this->m_position.m_x <= other.m_position.m_x + other.m_size.m_x
        && this->m_position.m_x + this->m_size.m_x >= other.m_position.m_x
        && this->m_position.m_y <= other.m_position.m_y + other.m_size.m_y
        && this->m_position.m_y + this->m_size.m_y >= other.m_position.m_y;
}

/// @details 判断是否包含该矩形
bool Rectangle::Contains(const Rectangle& other) const
{
    return this->Collision(other.m_position) && this->Collision(other.GetBottomRight());
}

/// @details 合并矩形为同时包含两矩形的最小矩形
Rectangle Union(const Rectangle& rect1, const Rectangle& rect2)
{
    float x1 = std::min(rect1.m_position.m_x, rect2.m_position.m_x);
    float x2 = std::max(rect1.m_position.m_x + rect1.m_size.m_x, rect2.m_position.m_x + rect2.m_size.m_x);
    float y1 = std::min(rect1.m_position.m_y, rect2.m_position.m_y);
    float y2 = std::max(rect1.m_position.m_y + rect1.m_size.m_y, rect2.m_position.m_y + rect2.m_size.m_y);

    return Rectangle(x1, y1, x2 - x1, y2 - y1);
}

/// @details 获取两矩形交集部分矩形，不相交则返回原点长宽为0矩形
Rectangle Intersection(const Rectangle& rect1, const Rectangle& rect2)
{
    if (rect1.Collision(rect2)) return Rectangle();
    float x1 = std::max(rect1.m_position.m_x, rect2.m_position.m_x);
    float x2 = std::min(rect1.m_position.m_x + rect1.m_size.m_x, rect2.m_position.m_x + rect2.m_size.m_x);
    float y1 = std::max(rect1.m_position.m_y, rect2.m_position.m_y);
    float y2 = std::min(rect1.m_position.m_y + rect1.m_size.m_y, rect2.m_position.m_y + rect2.m_size.m_y);

    return Rectangle(x1, y1, x2 - x1, y2 - y1);
}