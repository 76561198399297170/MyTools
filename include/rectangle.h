/// @file box.h
/// @brief 矩形框类定义，用于表示二维空间中的矩形区域
/// @date 2025-06-23
#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "vector2.h"

/// @class
/// @brief 二维空间矩形箱，描述坐上位置与大小
/// @warning 数据类型为float注意请勿超过数据范围导致溢出
class Rectangle
{
public:
    /// @brief 默认构造函数，位于原点大小为0
    Rectangle() = default;

    /// @brief 有参构造函数，通过位置和大小创建矩形
    /// @param pos 矩形左上角位置
    /// @param size 矩形的大小
    Rectangle(const Vector2& pos, const Vector2& size);

    /// @brief 有参构造函数，通过坐标和宽高创建矩形
    /// @param x 矩形左上角X坐标
    /// @param y 矩形左上角Y坐标
    /// @param width 矩形宽度
    /// @param height 矩形高度
    Rectangle(float x, float y, float width, float height);

    /// @brief 有参构造函数，通过位置和宽高创建矩形
    /// @param pos 矩形左上角位置
    /// @param width 矩形宽度
    /// @param height 矩形高度
    Rectangle(const Vector2& pos, float width, float height);

    /// @brief 拷贝构造函数
    Rectangle(const Rectangle& other);

    /// @brief 移动构造函数
    Rectangle(Rectangle&& other) noexcept;

    /// @brief 默认析构函数
    ~Rectangle() = default;

public:
    /// @brief 拷贝赋值运算符
    Rectangle& operator=(const Rectangle& other);

    /// @brief 移动赋值运算符
    Rectangle& operator=(Rectangle&& other) noexcept;

    /// @brief 等于比较运算符
    bool operator==(const Rectangle& other) const;

    /// @brief 不等于比较运算符
    bool operator!=(const Rectangle& other) const;

public:
    /// @brief 设置矩形中心点
    /// @param center 新的中心点坐标
    void SetCenter(const Vector2& center);

public:
    /// @brief 获取矩形中心点
    /// @return 矩形中心点坐标
    Vector2 GetCenter() const;

    /// @brief 获取矩形右下角坐标
    /// @return 矩形右下角坐标
    Vector2 GetBottomRight() const;

    /// @brief 获取矩形面积
    /// @return 矩形面积
    float GetArea() const;

    /// @brief 获取矩形周长
    /// @return 矩形周长
    float GetPerimeter() const;

public:
    /// @brief 判断点是否与矩形发生碰撞
    /// @param point 待判断点
    /// @return 点与矩形接触与碰撞true，否则false
    bool Collision(const Vector2& point) const;

    /// @brief 判断矩形是否与另一个矩形相交
    /// @param other 待判断的矩形
    /// @return 如果两个矩形相交返回true，否则返回false
    bool Collision(const Rectangle& other) const;

    /// @brief 判断矩形是否包含另一个矩形
    /// @param other 待判断的矩形
    /// @return 如果当前矩形包含另一个矩形返回true，否则返回false
    bool Contains(const Rectangle& other) const;

    /// @brief  以左上坐标为基准扩展矩形
    /// @param x 水平扩展量
    /// @param y 垂直扩展量
    void Expand(float x, float y);

    /// @brief 以左上坐标为基准扩展矩形
    /// @param amount 扩展量向量，x表示水平扩展量，y表示垂直扩展量
    void Expand(const Vector2& amount);

    /// @brief 平移矩形
    /// @param offset 平移向量
    void Translate(const Vector2& offset);

    /// @brief 以中心点为基准缩放矩形
    /// @param scale 缩放因子
    void Scale(float scale);

    /// @brief 以指定点为基准缩放矩形（）
    /// @param scale 缩放因子
    /// @param origin 缩放基准点
    void Scale(float scale, const Vector2& origin);

public:
    Vector2 m_position; ///< 矩形左上位置
    Vector2 m_size;     ///< 矩形宽高

};

/// @brief 合并两个矩形，生成包含两个矩形的最小矩形
/// @param rect1 矩形1
/// @param rect2 矩形2
/// @return 合并后的矩形
Rectangle Union(const Rectangle& rect1, const Rectangle& rect2);

/// @brief 计算两个矩形的交集
/// @param rect1 矩形1
/// @param rect2 矩形2
/// @return 两个矩形的交集矩形，不相交则返回默认构造矩形
Rectangle Intersection(const Rectangle& rect1, const Rectangle& rect2);

#endif // _Rectangle_H_