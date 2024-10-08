// Copyright (c) 2024 Rich Spencer. All rights reserved.

#pragma once

/**
 * @struct Vector2i
 *
 * @brief A Vector class for 2 dimension, integer pairs
 */
struct Vector2i
{
public:
    Vector2i() = default;
    Vector2i(int InX, int InY)
    {
        X = InX;
        Y = InY;
    }

    int X;
    int Y;

    bool operator!=(const Vector2i& Other) const
    {
        return (X != Other.X) || (Y != Other.Y);
    }
    bool operator==(const Vector2i& Other) const
    {
        return (X == Other.X) && (Y == Other.Y);
    }
    Vector2i operator+(const Vector2i &Other) const
    {
        return Vector2i(X + Other.X, Y + Other.Y);
    }
    Vector2i operator-(const Vector2i &Other) const
    {
        return Vector2i(X - Other.X, Y - Other.Y);
    }
};