struct Line {
	int m = 0, c = 0;
	Line(int _m, int _c) : m(_m), c(_c) { }
	int get(int x) { return m * x + c; }
	double intersection(Line o) { return (double) (o.c - c) / (double) (m - o.m); }
	bool good(Line l2, Line l3) { return __int128(l2.c - c) * (l2.m - l3.m) < __int128(l3.c - l2.c) * (m - l2.m); }
};
struct CHT {
	deque<Line> hull;
	void insert(Line l) {
		while (hull.size() > 1) {
			auto last = hull.end()[-1];
			auto p_last = hull.end()[-2];
			if (p_last.good(last, l)) break;
			hull.pop_back();
		}
		hull.push_back(l);
	}
	int query(int x) {
		while (hull.size() > 1 && hull[0].get(x) > hull[1].get(x)) {
			hull.pop_front();
		}
		return hull[0].get(x);
	}
	int query1(int x) {
		int lo = 1, hi = hull.size() - 1;
		while (lo < hi) {
			int mid = (lo + hi + 1) >> 1;
			if (hull[mid - 1].get(x) > hull[mid].get(x)) lo = mid;
			else hi = mid - 1;
		}
		return min(hull[lo - 1].get(x), hull[lo].get(x));
	}
};

// CHT for min query, decreasing slopes and increaing queries
// for max query just add Line(-m, -c) that is flip the signs of the slope and intercept
