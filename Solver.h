#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H

using namespace std;

// solver
template<typename P, typename S>
class Solver {
public:
    virtual S solve(P problem) = 0;
};

#endif //EX4_SOLVER_H
