class RoundPeg;

class RoundHole{
private:
    double radius;
public:
    RoundHole(double rad): radius(rad) {}
    double getRadius() const {return radius;}
    bool fits(RoundPeg&) const;
};

class RoundPeg{
private:
    double radius;
public:
    RoundPeg(double rad): radius(rad) {}
    virtual double getRadius() const {return radius;}
};

class SquarePeg{
private:
    double width;
public:
    SquarePeg(double wid): width(wid) {}
    double getWidth() const {return width;}
};

class SquarePegAdapter: public RoundPeg{
private:
    SquarePeg sqPeg;
public:
    SquarePegAdapter(const SquarePeg& peg): RoundPeg(0), sqPeg(peg) {};
    double getRadius() const override;
};