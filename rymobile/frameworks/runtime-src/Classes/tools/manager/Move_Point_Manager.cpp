//
//  Move_Point_Manager.cpp
//  qipaicocos
//
//  Created by keven on 16/8/12.
//
//

#include "Move_Point_Manager.h"

Move_Point::Move_Point() :angle_(0)
{
    
}

Move_Point::Move_Point(const xPoint &position, float angle)
: position_(position), angle_(angle)
{
    
}

Move_Point::~Move_Point()
{
    
}

xRect::xRect()
:top_(0),
bottom_(0),
left_(0),
right_(0)
{
}

xRect::xRect(const xPoint &point, const xSize &size)
:top_(point.y_),
bottom_(point.y_ + size.height_),
left_(point.x_),
right_(point.x_ + size.width_)
{
}

xRect::xRect(float left, float top, float right, float bottom)
:top_(top),
bottom_(bottom),
left_(left),
right_(right)
{
}

xRect::xRect(const xRect& rect)
:top_(rect.top_),
bottom_(rect.bottom_),
left_(rect.left_),
right_(rect.right_)
{
}

void xRect::set_position(const xPoint& pt)
{
    xSize sz(get_size());
    
    left_ = pt.x_;
    top_ = pt.y_;
    
    set_size(sz);
}

void xRect::set_rect(float left, float top, float right, float bottom)
{
    top_ = top;
    bottom_ = bottom;
    left_ = left;
    right_ = right;
}

void xRect::set_rect(const xPoint &point, const xSize &size)
{
    top_ = point.y_;
    bottom_ = point.y_ + size.height_;
    left_ = point.x_;
    right_ = point.x_ + size.width_;
}

void xRect::offset_rect(float x, float y)
{
    top_ += y;
    bottom_ += y;
    left_ += x;
    right_ += x;
}

void xRect::offset_rect(const xSize &size)
{
    top_ += size.height_;
    bottom_ += size.height_;
    left_ += size.width_;
    right_ += size.width_;
}

bool xRect::pt_in_rect(const xPoint& point) const
{
    if ((left_ > point.x_) ||
        (right_ <= point.x_) ||
        (top_ > point.y_) ||
        (bottom_ <= point.y_))
    {
        return false;
    }
    
    return true;
}

xRect xRect::intersection_rect(const xRect& rect) const
{
    if ((right_ > rect.left_) &&
        (left_ < rect.right_) &&
        (bottom_ > rect.top_) &&
        (top_ < rect.bottom_))
    {
        xRect temp;
        
        temp.left_ = (left_ > rect.left_) ? left_ : rect.left_;
        temp.right_ = (right_ < rect.right_) ? right_ : rect.right_;
        temp.top_ = (top_ > rect.top_) ? top_ : rect.top_;
        temp.bottom_ = (bottom_ < rect.bottom_) ? bottom_ : rect.bottom_;
        
        return temp;
    }
    else
    {
        return xRect(0.0f, 0.0f, 0.0f, 0.0f);
    }
    
}