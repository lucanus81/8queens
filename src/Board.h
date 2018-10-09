#pragma once

#include <algorithm>
#include <set>

namespace queens
{

class board
{
public:
    enum class status { added, already_exists, invalid_argument };

    board(unsigned short width,
          unsigned short height,
          unsigned short queens)
      : width_{width}
      , height_{height}
      , queens_{queens}
    {
    }
    
    unsigned short width() const { return width_; }
    unsigned short height() const { return height_; }
    unsigned short queens() const { return queens_; }
    status add_queen(unsigned short x, unsigned short y)
    {
        if (already_placed_all_queens() || invalid_width(x) || invalid_height(y))
            return status::invalid_argument;

        if (data_.insert({x,y}).second)
            return status::added;
        else
            return status::already_exists;
    }

    void print() const
    {
        std::cout <<"  "; for (unsigned short w=0; w<width(); ++w) std::cout <<w; std::cout <<'\n';
        std::cout <<" +"; for (unsigned short w=0; w<width(); ++w) std::cout <<'-'; std::cout <<"+\n";
        for (unsigned short h=0; h<height(); ++h)
        {
            std::cout <<h <<'|'; 
            for (unsigned short w=0; w<width(); ++w)
            {
                if (data_.find({h,w}) != data_.cend())
                    std::cout <<'X';
                else
                    std::cout <<' ';
            }
            std::cout <<'|' <<h <<'\n'; 
        }
        std::cout <<" +"; for (unsigned short w=0; w<width(); ++w) std::cout <<'-'; std::cout <<"+\n";
        std::cout <<"  "; for (unsigned short w=0; w<width(); ++w) std::cout <<w; std::cout <<'\n';
    }

private:
    bool already_placed_all_queens() const { return data_.size() == queens(); }
    bool invalid_width(unsigned short x) const { return x > width() - 1; }
    bool invalid_height(unsigned short y) const { return y > height() - 1; }

    struct queen_2d_position 
    { 
        unsigned short x{0}, y{0}; 
        bool operator<(queen_2d_position const& p) const 
        { 
            if (x < p.x)
                return true;
            if (x > p.x)
                return false;
            return y < p.y;    
        }
    };
    unsigned short width_{0};
    unsigned short height_{0};
    unsigned short queens_{0};
    std::set<queen_2d_position> data_;
};

} // namespace 8queens
