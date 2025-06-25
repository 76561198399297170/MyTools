/// @file box.cpp
/// @brief ���ο���ʵ��
/// @date 2025-06-23

#include "rectangle.h"

// @details �вι��췽��ͨ����������Ϳ�߹���
Rectangle::Rectangle(const Vector2& position, const Vector2& size)
	: m_position(position), m_size(size)
{

}

// @details �вι��췽��ͨ������Ϳ�ߴ�������
Rectangle::Rectangle(float x, float y, float width, float height)
    : m_position(x, y), m_size(width, height)
{

}

Rectangle::Rectangle(const Vector2& pos, float width, float height)
    : m_position(pos), m_size(width, height)
{

}

// @details �������캯��
Rectangle::Rectangle(const Rectangle& other)
    : m_position(other.m_position), m_size(other.m_size)
{

}

// @details �ƶ����캯��
Rectangle::Rectangle(Rectangle&& other) noexcept
    : m_position(std::move(other.m_position)), m_size(std::move(other.m_size))
{

}

// @details ��ֵ����
Rectangle& Rectangle::operator=(const Rectangle& other)
{
    if (this != &other)
    {
        this->m_position = other.m_position, this->m_size = other.m_size;
    }
    return *this;
}

// @details �ƶ���ֵ����
Rectangle& Rectangle::operator=(Rectangle&& other) noexcept
{
    if (this != &other)
    {
        this->m_position = std::move(other.m_position), this->m_size = std::move(other.m_size);
    }
    return *this;
}

// @details �������أ��Ƚ��������С�Ƿ�һ��
bool Rectangle::operator==(const Rectangle& other) const
{
    return this->m_position == other.m_position && this->m_size == other.m_size;
}

/// @details ����������
bool Rectangle::operator!=(const Rectangle& other) const
{
    return !(*this == other);
}

/// @details ���þ������������꣬���δ�С����
void Rectangle::SetCenter(const Vector2& center)
{
    this->m_position.m_x = center.m_x - this->m_size.m_x * 0.5f;
    this->m_position.m_y = center.m_y - this->m_size.m_y * 0.5f;
}

/// @details ��ȡ��������������
Vector2 Rectangle::GetCenter() const
{
    return Vector2(this->m_position.m_x + this->m_size.m_x * 0.5f, this->m_position.m_y + this->m_size.m_y * 0.5f);
}

/// @details ��ȡ�������½�����
Vector2 Rectangle::GetBottomRight() const
{
    return Vector2(this->m_position.m_x + this->m_size.m_x, this->m_position.m_y + this->m_size.m_y);
}

/// @details ��ȡ�������
float Rectangle::GetArea() const
{
    return this->m_size.m_x * this->m_size.m_y;
}

/// @details ��ȡ�����ܳ�
float Rectangle::GetPerimeter() const
{
    return 2.0f * (this->m_size.m_x + this->m_size.m_y);
}

/// @details �жϵ��Ƿ�����η����Ӵ�����ײ
bool Rectangle::Collision(const Vector2& point) const
{
    return this->m_position.m_x <= point.m_x && this->m_position.m_x + this->m_size.m_x >= point.m_x
        && this->m_position.m_y <= point.m_y && this->m_position.m_y + this->m_size.m_y >= point.m_x;
}

/// @details �жϾ����Ƿ�����η����Ӵ�����ײ
bool Rectangle::Collision(const Rectangle& other) const
{
    return this->m_position.m_x <= other.m_position.m_x + other.m_size.m_x
        && this->m_position.m_x + this->m_size.m_x >= other.m_position.m_x
        && this->m_position.m_y <= other.m_position.m_y + other.m_size.m_y
        && this->m_position.m_y + this->m_size.m_y >= other.m_position.m_y;
}

/// @details �ж��Ƿ�����þ���
bool Rectangle::Contains(const Rectangle& other) const
{
    return this->Collision(other.m_position) && this->Collision(other.GetBottomRight());
}

/// @details �ϲ�����Ϊͬʱ���������ε���С����
Rectangle Union(const Rectangle& rect1, const Rectangle& rect2)
{
    float x1 = std::min(rect1.m_position.m_x, rect2.m_position.m_x);
    float x2 = std::max(rect1.m_position.m_x + rect1.m_size.m_x, rect2.m_position.m_x + rect2.m_size.m_x);
    float y1 = std::min(rect1.m_position.m_y, rect2.m_position.m_y);
    float y2 = std::max(rect1.m_position.m_y + rect1.m_size.m_y, rect2.m_position.m_y + rect2.m_size.m_y);

    return Rectangle(x1, y1, x2 - x1, y2 - y1);
}

/// @details ��ȡ�����ν������־��Σ����ཻ�򷵻�ԭ�㳤��Ϊ0����
Rectangle Intersection(const Rectangle& rect1, const Rectangle& rect2)
{
    if (rect1.Collision(rect2)) return Rectangle();
    float x1 = std::max(rect1.m_position.m_x, rect2.m_position.m_x);
    float x2 = std::min(rect1.m_position.m_x + rect1.m_size.m_x, rect2.m_position.m_x + rect2.m_size.m_x);
    float y1 = std::max(rect1.m_position.m_y, rect2.m_position.m_y);
    float y2 = std::min(rect1.m_position.m_y + rect1.m_size.m_y, rect2.m_position.m_y + rect2.m_size.m_y);

    return Rectangle(x1, y1, x2 - x1, y2 - y1);
}