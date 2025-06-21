/// @file vector2.cpp
/// @brief 二维向量类实现
/// @date 2025-06-22
#include "vector2.h"

/// @details 构造方法设置坐标
Vector2::Vector2(float x, float y)
{
	this->m_x = x, this->m_y = y;
}

/// @details 构造方法完全复制other所有数据
Vector2::Vector2(const Vector2& other)
{
	this->m_x = other.m_x, this->m_y = other.m_y;
}

/// @details 构造方法完全复制other所有数据
Vector2::Vector2(Vector2&& other) noexcept : m_x(other.m_x), m_y(other.m_y)
{

}

/// @details 赋值重载
Vector2& Vector2::operator=(const Vector2& other)
{
	if (this != &other)
	{
		this->m_x = other.m_x, this->m_y = other.m_y;
	}
	return *this;
}

/// @details 加法重载
Vector2 Vector2::operator+(const Vector2& other) const
{
	return Vector2(this->m_x + other.m_x, this->m_y + other.m_y);
}

/// @details 减法重载
Vector2 Vector2::operator-(const Vector2& other) const
{
	return Vector2(this->m_x - other.m_x, this->m_y - other.m_y);
}

/// @details 取反重载
Vector2 Vector2::operator-() const
{
	return Vector2(-this->m_x, -this->m_y);
}

/// @details 乘法重载
Vector2 Vector2::operator*(float scalar) const
{
	return Vector2(this->m_x * scalar, this->m_y * scalar);
}

/// @details 除法重载
Vector2 Vector2::operator/(float scalar) const
{
	if (!scalar) return Vector2(this->m_x, this->m_y);
	return Vector2(this->m_x / scalar, this->m_y / scalar);
}

/// @details 复合加法重载
Vector2& Vector2::operator+=(const Vector2& other)
{
	this->m_x += other.m_x, this->m_y += other.m_y;
	return *this;
}

/// @details 复合减法重载
Vector2& Vector2::operator-=(const Vector2& other)
{
	this->m_x -= other.m_x, this->m_y -= other.m_y;
	return *this;
}

/// @details 复合乘法重载
Vector2& Vector2::operator*=(float scalar)
{
	this->m_x *= scalar, this->m_y *= scalar;
	return *this;
}

/// @details 复合除法重载
Vector2& Vector2::operator/=(float scalar)
{
	if (!scalar) return *this;
	this->m_x /= scalar, this->m_y /= scalar;
	return *this;
}

/// @details 等于重载
bool Vector2::operator==(const Vector2& other) const
{
	return this->m_x == other.m_x && this->m_y == other.m_y;
}

/// @details 不等于重载
bool Vector2::operator!=(const Vector2& other) const
{
	return !(*this == other);
}

/// @details 向量长度计算
float Vector2::Length() const
{
	return sqrt(this->LengthSquared());
}

/// @details 向量长度平方计算，一般不需要开方速度更快使用该方法
float Vector2::LengthSquared() const
{
	return this->m_x * this->m_x + this->m_y * this->m_y;
}

/// @details 向量归一化处理，若长度为0则返回0向量
Vector2 Vector2::Normalized() const
{
	float len = this->Length();
	if (!len) return Vector2(0.0f, 0.0f);
	return Vector2(this->m_x / len, this->m_y / len);
}

/// @details 原地向量归一化处理，若长度为0则不变为0向量
Vector2& Vector2::Normalize()
{
	float len = this->Length();
	if (!len) return *this;
	this->m_x /= len;
	this->m_y /= len;
	return *this;
}

/// @details 标量在前的向量数乘运算符重载
Vector2 operator*(float scalar, const Vector2& vec)
{
	return vec * scalar;
}

/// @details 二维向量点积，结果内积
float Dot(const Vector2& v1, const Vector2& v2)
{
	return v1.m_x * v2.m_x + v1.m_y * v2.m_y;
}

/// @details 二维向量叉积，结果标量
float Cross(const Vector2& v1, const Vector2& v2)
{
	return v1.m_x * v2.m_y - v1.m_y * v2.m_x;
}

/// @details 两二维向量夹角弧度
/// @ note 对于v1此处点积正值夹角锐角负值钝角，叉积正值逆时针旋转负值顺时针
float Angle(const Vector2& v1, const Vector2& v2)
{
	return std::atan2(Dot(v1, v2), Cross(v1, v2));
}

/// @details 计算v1在v2上的投影
Vector2 Project(const Vector2& v1, const Vector2& v2)
{
	float len = v2.LengthSquared();
	if (!len) return Vector2(0.0f, 0.0f);
	return v2 * Dot(v1, v2) / len;
}

/// @details 计算v1系数t插值平滑移向v2
/// @note 插值系数范围[0.0f, 1.0f]，函数自动进行范围修正
Vector2 Lerp(const Vector2& v1, const Vector2& v2, float t)
{
	t = (t < 0.0f ? 0.0f : (t > 1.0f ? 1.0f : t));
	return v1 + (v2 - v1) * t;
}

/// @details 计算向量限制max_len内的向量
Vector2 ClampMagnitude(const Vector2& vec, float max_len)
{
	if (vec.LengthSquared() > max_len * max_len) return vec.Normalized() * max_len;
	return vec;
}
