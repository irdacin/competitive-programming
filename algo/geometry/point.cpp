struct point {
  int x, y;
  point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
  point operator+(const point& p) const { return point(x + p.x, y + p.y); }
  point operator-(const point& p) const { return point(x - p.x, y - p.y); }

  int dot(const point& p) const { return x * p.x + y * p.y; }
  int cross(const point& p) const { return x * p.y - y * p.x; }
  int dot(const point& p, const point& q) const { return (p - *this).dot(q - *this); }
  int cross(const point& p, const point& q) const { return (p - *this).cross(q - *this); }
  int dist2(const point& p) const { return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y); }
  double dist(const point& p) const { return sqrt(dist2(p)); }

  friend bool intersect(point p, point q, point r, point s) {
    auto sign = [](int x) { return x >= 0 ? x > 0 : -1; };
    auto overlap = [](int a, int b, int c, int d) {
      return max(min(a, b), min(c, d)) <= min(max(a, b), max(c, d));
    };

    if(sign(p.cross(r, s)) == 0 && sign(r.cross(p, q)) == 0)
      return overlap(p.x, q.x, r.x, s.x) && overlap(p.y, q.y, r.y, s.y);

    return sign(p.cross(r, s)) != sign(q.cross(r, s)) && sign(r.cross(p, q)) != sign(s.cross(p, q));
  }

  bool operator==(const point& p) const { return x == p.x && y == p.y; }
  bool operator!=(const point& p) const { return x != p.x || y != p.y; }
  bool operator<(const point& p) const { return x < p.x || x == p.x && y < p.y; }
  bool operator>(const point& p) const { return x > p.x || x == p.x && y > p.y; }
  friend istream& operator>>(istream& is, point& p) { return is >> p.x >> p.y; }
  friend ostream& operator<<(ostream& os, const point& p) { return os << "(" << p.x << ", " << p.y << ")"; }
};