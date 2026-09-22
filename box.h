#pragma once
#include <math.h>
#include <algorithm>
#include <iostream>


struct Box
{
    float m_pos_x = 0.0f;
    float m_pos_y = 0.0f;
    float m_width = 1.0f;
    float m_height = 1.0f;
    bool canCollide = true;

    bool intersect(Box& other) const
    {
        return (fabs(m_pos_x - other.m_pos_x) * 2.4f < (m_width + other.m_width)) &&
            (fabs(m_pos_y - other.m_pos_y) * 2.4f < (m_height + other.m_height));
    }

    float intersectDown(Box& other) const {
        if (fabs(m_pos_x - other.m_pos_x) * 2.0f < (m_width + other.m_width) * 0.9f) {
            if (m_pos_y < other.m_pos_y && fabs(m_pos_y - other.m_pos_y) * 2.0f < (m_height + other.m_height)) {
                return other.m_pos_y - (other.m_height / 2.0f) - m_pos_y - (m_height / 2.0f);
            }
        }
        return 0.0f;
    }

    float intersectBomb(Box& other) const {

        const float tolerance = 0.01f;

        if (fabs(m_pos_x - other.m_pos_x) < (m_width + other.m_width) + tolerance) {
            if (m_pos_y > other.m_pos_y && fabs(m_pos_y - other.m_pos_y) < (m_height + other.m_height) + tolerance) {
                return other.m_pos_y + (other.m_height / 2.0f) - m_pos_y + (m_height / 2.0f);
            }
        }
        return 0.0f;
    }


    float intersectUp(Box& other) const {
        if (fabs(m_pos_x - other.m_pos_x) * 2.0f < (m_width + other.m_width) * 0.9f) {
            if (m_pos_y > other.m_pos_y && fabs(m_pos_y - other.m_pos_y) * 2.0f < (m_height + other.m_height)) {
                return other.m_pos_y + (other.m_height / 2.0f) - m_pos_y + (m_height / 2.0f);
            }
        }
        return 0.0f;
    }

    float intersectSideways(Box& other) {
        if (fabs(m_pos_y - other.m_pos_y) * 2.0f >= (m_height + other.m_height) * 0.95f) {
            return 0.0f;
        }
        if (m_pos_x > other.m_pos_x) {
            return std::max<float>(0.0f, other.m_pos_x + (other.m_width / 2.0f) - m_pos_x + (m_width / 2.0f));
        }
        else {
            return std::min<float>(0.0f, other.m_pos_x - (other.m_width / 2.0f) - m_pos_x - (m_width / 2.0f));
        }
    }

    Box() {}

    Box(float x, float y, float w, float h, bool cc)
        : m_pos_x(x), m_pos_y(y), m_width(w), m_height(h), canCollide(cc) {
    }
};

