/// @file vector2.cpp
/// @brief ��ά������ʵ��
/// @date 2025-06-22
#include "vector2.h"

/// @details ���췽����������
Vector2::Vector2(float x, float y)
{
	this->m_x = x, this->m_y = y;
}

/// @details ���췽����ȫ����other��������
Vector2::Vector2(const Vector2& other)
{
	this->m_x = other.m_x, this->m_y = other.m_y;
}

/// @details ���췽����ȫ����other��������
Vector2::Vector2(Vector2&& other) noexcept : m_x(other.m_x), m_y(other.m_y)
{

}

/// @details ��ֵ����
Vector2& Vector2::operator=(const Vector2& other)
{
	if (this != &other)
	{
		this->m_x = other.m_x, this->m_y = other.m_y;
	}
	return *this;
}

/// @details �ӷ�����
Vector2 Vector2::operator+(const Vector2& other) const
{
	return Vector2(this->m_x + other.m_x, this->m_y + other.m_y);
}

/// @details ��������
Vector2 Vector2::operator-(const Vector2& other) const
{
	return Vector2(this->m_x - other.m_x, this->m_y - other.m_y);
}

/// @details ȡ������
Vector2 Vector2::operator-() const
{
	return Vector2(-this->m_x, -this->m_y);
}

/// @details �˷�����
Vector2 Vector2::operator*(float scalar) const
{
	return Vector2(this->m_x * scalar, this->m_y * scalar);
}

/// @details ��������
Vector2 Vector2::operator/(float scalar) const
{
	if (!scalar) return Vector2(this->m_x, this->m_y);
	return Vector2(this->m_x / scalar, this->m_y / scalar);
}

/// @details ���ϼӷ�����
Vector2& Vector2::operator+=(const Vector2& other)
{
	this->m_x += other.m_x, this->m_y += other.m_y;
	return *this;
}

/// @details ���ϼ�������
Vector2& Vector2::operator-=(const Vector2& other)
{
	this->m_x -= other.m_x, this->m_y -= other.m_y;
	return *this;
}

/// @details ���ϳ˷�����
Vector2& Vector2::operator*=(float scalar)
{
	this->m_x *= scalar, this->m_y *= scalar;
	return *this;
}

/// @details ���ϳ�������
Vector2& Vector2::operator/=(float scalar)
{
	if (!scalar) return *this;
	this->m_x /= scalar, this->m_y /= scalar;
	return *this;
}

/// @details ��������
bool Vector2::operator==(const Vector2& other) const
{
	return this->m_x == other.m_x && this->m_y == other.m_y;
}

/// @details ����������
bool Vector2::operator!=(const Vector2& other) const
{
	return !(*this == other);
}

/// @details �������ȼ���
float Vector2::Length() const
{
	return sqrt(this->LengthSquared());
}

/// @details ��������ƽ�����㣬һ�㲻��Ҫ�����ٶȸ���ʹ�ø÷���
float Vector2::LengthSquared() const
{
	return this->m_x * this->m_x + this->m_y * this->m_y;
}

/// @details ������һ������������Ϊ0�򷵻�0����
Vector2 Vector2::Normalized() const
{
	float len = this->Length();
	if (!len) return Vector2(0.0f, 0.0f);
	return Vector2(this->m_x / len, this->m_y / len);
}

/// @details ԭ��������һ������������Ϊ0�򲻱�Ϊ0����
Vector2& Vector2::Normalize()
{
	float len = this->Length();
	if (!len) return *this;
	this->m_x /= len;
	this->m_y /= len;
	return *this;
}

/// @details ������ǰ�������������������
Vector2 operator*(float scalar, const Vector2& vec)
{
	return vec * scalar;
}

/// @details ��ά�������������ڻ�
float Dot(const Vector2& v1, const Vector2& v2)
{
	return v1.m_x * v2.m_x + v1.m_y * v2.m_y;
}

/// @details ��ά����������������
float Cross(const Vector2& v1, const Vector2& v2)
{
	return v1.m_x * v2.m_y - v1.m_y * v2.m_x;
}

/// @details ����ά�����нǻ���
/// @ note ����v1�˴������ֵ�н���Ǹ�ֵ�۽ǣ������ֵ��ʱ����ת��ֵ˳ʱ��
float Angle(const Vector2& v1, const Vector2& v2)
{
	return std::atan2(Dot(v1, v2), Cross(v1, v2));
}

/// @details ����v1��v2�ϵ�ͶӰ
Vector2 Project(const Vector2& v1, const Vector2& v2)
{
	float len = v2.LengthSquared();
	if (!len) return Vector2(0.0f, 0.0f);
	return v2 * Dot(v1, v2) / len;
}

/// @details ����v1ϵ��t��ֵƽ������v2
/// @note ��ֵϵ����Χ[0.0f, 1.0f]�������Զ����з�Χ����
Vector2 Lerp(const Vector2& v1, const Vector2& v2, float t)
{
	t = (t < 0.0f ? 0.0f : (t > 1.0f ? 1.0f : t));
	return v1 + (v2 - v1) * t;
}

/// @details ������������max_len�ڵ�����
Vector2 ClampMagnitude(const Vector2& vec, float max_len)
{
	if (vec.LengthSquared() > max_len * max_len) return vec.Normalized() * max_len;
	return vec;
}
