/// @file box.h
/// @brief ���ο��ඨ�壬���ڱ�ʾ��ά�ռ��еľ�������
/// @date 2025-06-23
#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "vector2.h"

/// @class
/// @brief ��ά�ռ�����䣬��������λ�����С
/// @warning ��������Ϊfloatע�����𳬹����ݷ�Χ�������
class Rectangle
{
public:
    /// @brief Ĭ�Ϲ��캯����λ��ԭ���СΪ0
    Rectangle() = default;

    /// @brief �вι��캯����ͨ��λ�úʹ�С��������
    /// @param pos �������Ͻ�λ��
    /// @param size ���εĴ�С
    Rectangle(const Vector2& pos, const Vector2& size);

    /// @brief �вι��캯����ͨ������Ϳ�ߴ�������
    /// @param x �������Ͻ�X����
    /// @param y �������Ͻ�Y����
    /// @param width ���ο��
    /// @param height ���θ߶�
    Rectangle(float x, float y, float width, float height);

    /// @brief �вι��캯����ͨ��λ�úͿ�ߴ�������
    /// @param pos �������Ͻ�λ��
    /// @param width ���ο��
    /// @param height ���θ߶�
    Rectangle(const Vector2& pos, float width, float height);

    /// @brief �������캯��
    Rectangle(const Rectangle& other);

    /// @brief �ƶ����캯��
    Rectangle(Rectangle&& other) noexcept;

    /// @brief Ĭ����������
    ~Rectangle() = default;

public:
    /// @brief ������ֵ�����
    Rectangle& operator=(const Rectangle& other);

    /// @brief �ƶ���ֵ�����
    Rectangle& operator=(Rectangle&& other) noexcept;

    /// @brief ���ڱȽ������
    bool operator==(const Rectangle& other) const;

    /// @brief �����ڱȽ������
    bool operator!=(const Rectangle& other) const;

public:
    /// @brief ���þ������ĵ�
    /// @param center �µ����ĵ�����
    void SetCenter(const Vector2& center);

public:
    /// @brief ��ȡ�������ĵ�
    /// @return �������ĵ�����
    Vector2 GetCenter() const;

    /// @brief ��ȡ�������½�����
    /// @return �������½�����
    Vector2 GetBottomRight() const;

    /// @brief ��ȡ�������
    /// @return �������
    float GetArea() const;

    /// @brief ��ȡ�����ܳ�
    /// @return �����ܳ�
    float GetPerimeter() const;

public:
    /// @brief �жϵ��Ƿ�����η�����ײ
    /// @param point ���жϵ�
    /// @return ������νӴ�����ײtrue������false
    bool Collision(const Vector2& point) const;

    /// @brief �жϾ����Ƿ�����һ�������ཻ
    /// @param other ���жϵľ���
    /// @return ������������ཻ����true�����򷵻�false
    bool Collision(const Rectangle& other) const;

    /// @brief �жϾ����Ƿ������һ������
    /// @param other ���жϵľ���
    /// @return �����ǰ���ΰ�����һ�����η���true�����򷵻�false
    bool Contains(const Rectangle& other) const;

    /// @brief  ����������Ϊ��׼��չ����
    /// @param x ˮƽ��չ��
    /// @param y ��ֱ��չ��
    void Expand(float x, float y);

    /// @brief ����������Ϊ��׼��չ����
    /// @param amount ��չ��������x��ʾˮƽ��չ����y��ʾ��ֱ��չ��
    void Expand(const Vector2& amount);

    /// @brief ƽ�ƾ���
    /// @param offset ƽ������
    void Translate(const Vector2& offset);

    /// @brief �����ĵ�Ϊ��׼���ž���
    /// @param scale ��������
    void Scale(float scale);

    /// @brief ��ָ����Ϊ��׼���ž��Σ���
    /// @param scale ��������
    /// @param origin ���Ż�׼��
    void Scale(float scale, const Vector2& origin);

public:
    Vector2 m_position; ///< ��������λ��
    Vector2 m_size;     ///< ���ο��

};

/// @brief �ϲ��������Σ����ɰ����������ε���С����
/// @param rect1 ����1
/// @param rect2 ����2
/// @return �ϲ���ľ���
Rectangle Union(const Rectangle& rect1, const Rectangle& rect2);

/// @brief �����������εĽ���
/// @param rect1 ����1
/// @param rect2 ����2
/// @return �������εĽ������Σ����ཻ�򷵻�Ĭ�Ϲ������
Rectangle Intersection(const Rectangle& rect1, const Rectangle& rect2);

#endif // _Rectangle_H_