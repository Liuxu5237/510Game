//
//  Move_Point_Manager.h
//  qipaicocos
//
//  Created by keven on 16/8/12.
//
//

#ifndef Move_Point_Manager_h
#define Move_Point_Manager_h

#include <vector>

#pragma pack(push)
#pragma pack(1)

class xPoint
{
public:
    xPoint() :x_(0), y_(0) {}
    xPoint(float x, float y) :x_(x), y_(y) {}
    xPoint(const xPoint &point) :x_(point.x_), y_(point.y_) {}
    ~xPoint() {}
    
public:
    void offset(float x, float y) { x_ += x; y_ += y; }
    
    void set_point(float x, float y) { x_ = x; y_ = y; }
    
    bool operator == (const xPoint &point) const { return (x_ == point.x_&&y_ == point.y_); }
    bool operator != (const xPoint &point) const { return (x_ != point.x_ || y_ != point.y_); }
    
    xPoint &operator = (const xPoint &point) { x_ = point.x_; y_ = point.y_; return *this; }
    
    void operator += (const xPoint &point) { x_ += point.x_; y_ += point.y_; }
    void operator -= (const xPoint &point) { x_ -= point.x_; y_ -= point.y_; }
    
    xPoint operator + (const xPoint &point) { return xPoint(x_ + point.x_, y_ + point.y_); }
    xPoint operator - (const xPoint &point) { return xPoint(x_ - point.x_, y_ - point.y_); }
    xPoint operator - () { return xPoint(-x_, -y_); }
    
    xPoint operator * (float multip) { return xPoint(x_*multip, y_*multip); }
    
public:
    float x_;
    float y_;
};

inline xPoint operator+ (const xPoint &lhs, const xPoint &rhs)
{
    return xPoint(lhs.x_ + rhs.x_, lhs.y_ + rhs.y_);
}

inline xPoint operator- (const xPoint &lhs, const xPoint &rhs)
{
    return xPoint(lhs.x_ - rhs.x_, lhs.y_ - rhs.y_);
}
/*----------------------------------------move_point-----------------------------------------*/
class Move_Point
{
public:
    Move_Point();
    Move_Point(const xPoint &position, float angle);
    
    ~Move_Point();
    xPoint getPostion() { return position_; }
public:
    float angle_;
    xPoint position_;
};

typedef std::vector<Move_Point> Move_Points;



class xSize
{
public:
	xSize() :width_(0), height_(0)  { }
	xSize(float width, float height) :width_(width), height_(height) {}
	xSize(const xSize &size) : width_(size.width_), height_(size.height_) {}
	~xSize() {}

	bool operator == (const xSize &size) const { return (size.width_ == width_&&size.height_ == height_); }
	bool operator != (const xSize &size) const { return (size.width_ != width_ || size.height_ != height_); }

	xSize &operator = (const xSize &size) { width_ = size.width_; height_ = size.height_; return *this; }

	xSize& operator += (const xSize &size) { width_ += size.width_; height_ += size.height_; return *this; }
	xSize& operator -= (const xSize &size) { width_ -= size.width_; height_ -= size.height_; return *this; }

	void set_size(float width, float height) { width_ = width; height_ = height; }

	xSize operator + (const xSize &size) { return xSize(width_ + size.width_, height_ + size.height_); }
	xSize operator - (const xSize &size) { return xSize(width_ - size.width_, height_ - size.height_); }
	xSize operator - () { return xSize(-width_, -height_); }

public:
	float width_;
	float height_;
};


class  xRect
{
public:
	xRect();
	xRect(const xPoint &point, const xSize &size);
	xRect(float left, float top, float right, float bottom);
	xRect(const xRect& rect);

	xPoint get_position() const { return xPoint(left_, top_); }
	void set_position(const xPoint& pt);

	float get_width() const { return right_ - left_; }
	void set_width(float width) { right_ = left_ + width; }

	float get_height() const { return bottom_ - top_; }
	void set_height(float height) { bottom_ = top_ + height; }

	xSize get_size() const { return xSize(get_width(), get_height()); }
	void set_size(const xSize& size)	{ set_width(size.width_); set_height(size.height_); }

	void set_rect(float left, float top, float right, float bottom);
	void set_rect(const xPoint &point, const xSize &size);

	void offset_rect(float x, float y);
	void offset_rect(const xSize &size);

	bool pt_in_rect(const xPoint& point) const;
	bool is_empty() const { return (get_width() == 0.0f && get_height() == 0.0f); }

	xRect intersection_rect(const xRect& rect) const;
	//xRect union_rect(const xRect& rect) const ;
	//xRect subtract_rect(const xRect& rect) const ;

	xRect& operator = (const xRect& rhs)
	{
		left_ = rhs.left_;
		top_ = rhs.top_;
		right_ = rhs.right_;
		bottom_ = rhs.bottom_;

		return *this;
	}

	bool operator == (const xRect& rhs) const
	{
		return ((left_ == rhs.left_) && (right_ == rhs.right_) && (top_ == rhs.top_) && (bottom_ == rhs.bottom_));
	}
	bool operator != (const xRect& rhs) const { return !operator==(rhs); }

public:
	float left_, top_, right_, bottom_;
};

#pragma pack(pop)




#endif /* Move_Point_Manager_h */
